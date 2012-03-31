/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: updater.cpp,v 1.1 2006/08/27 15:42:00 pascal Exp $
* $Log: updater.cpp,v $
* Revision 1.1  2006/08/27 15:42:00  pascal
* - Système de mise à jour automatique
*
*/
#include <process.h>
#include <qdir.h>
#include <qmessagebox.h>
#include <qstringlist.h>

#include "main.h"
#include "updater.h"

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
CUpdater::CUpdater( QWidget &main ) : QObject(), url_( URL_UPDATE, 80 ), main_( main )
{
    file_ = 0;
    state_ = 0;
    connect(&url_, SIGNAL(done(bool)), this, SLOT(done(bool)));
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------
CUpdater::~CUpdater()
{
    if( file_ != 0 )
        delete file_;
}

//----------------------------------------------------------------------------
// Check for update available
//----------------------------------------------------------------------------
void CUpdater::updateAvailable()
{
    url_.get( "/savane/amonsoft/last.txt" );
}

//----------------------------------------------------------------------------
// Download update
//----------------------------------------------------------------------------
void CUpdater::downloadUpdate( QString sVersion )
{
    QString sUrl = "/savane/amonsoft/amonsoft-" + sVersion + ".exe";
    QString sFile = "amonsoft-" + sVersion + ".exe";
    
    unlink( sFile );
    file_ = new QFile( sFile );    
    bool bErr = file_->open( IO_WriteOnly );

    if( !bErr )
    {
        qDebug( QString( "Impossible de creer" ) + sFile );
        return ;
    }

    state_ = 1;
    url_.get( sUrl, file_ );
    main_.setDisabled( true );
//    system( QString("explore.exe http://URL_UPDATE") + sUrl );
}

//----------------------------------------------------------------------------
// Check diff version
// Version form : Major.Minor.Build
//----------------------------------------------------------------------------
int CUpdater::diffVersion( QString sCurrent, QString sNet )
{
    QStringList listStr, listStr2;

    listStr  = QStringList::split( ".", sCurrent );
    listStr2 = QStringList::split( ".", sNet );

    if( listStr[0].toUInt() > listStr2[0].toUInt() )
        return -1;
    if( listStr[0].toUInt() < listStr2[0].toUInt() )
        return 1;
    if( listStr[1].toUInt() > listStr2[1].toUInt() )
        return -1;
    if( listStr[1].toUInt() < listStr2[1].toUInt() )
        return 1;
    if( listStr[2].toUInt() > listStr2[2].toUInt() )
        return -1;
    if( listStr[2].toUInt() < listStr2[2].toUInt() )
        return 1;
    return 0;
}

//----------------------------------------------------------------------------
// Signal
//----------------------------------------------------------------------------
void CUpdater::done( bool bError )
{
    if( bError )
    {
        qDebug( "Error HTTP" );
        return ;
    }

    switch( state_ )
    {
        case 0:
        { // Check Update available
            int iRep = 0;

            QString sVersion = QString(url_.readAll());
            qDebug( "Last online version available " + sVersion ); 

            if( diffVersion( APP_VERSION, sVersion ) >= 1 )
            {
                QString     str = "Une nouvelle version est disponible : " + sVersion;
                iRep = QMessageBox::information( &main_,
                        "Mise à jour", 
                        str + "\n Souhaitez-vous la télécharger ?",
                        QMessageBox::Yes, 
                        QMessageBox::No );    

                if( iRep == QMessageBox::Yes )
                    downloadUpdate( sVersion );
            }
            break ;
        }
        case 1:
        {
            file_->close();
            qDebug( "Fichier telecharger" );      
            qDebug( QDir::currentDirPath() + "\\" + file_->name() );
            execl( QDir::currentDirPath() + "\\" + file_->name(), file_->name(), 0 );
            break ;
        }
    }
}
