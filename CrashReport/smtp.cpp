/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: smtp.cpp,v 1.1 2006/10/12 21:20:04 pascal Exp $
* $Log: smtp.cpp,v $
* Revision 1.1  2006/10/12 21:20:04  pascal
* - Generation de minidump OK
*
* Revision 1.1  2006/10/09 10:06:07  pascal
* Version 0.2.4
*
* Nouvelles fonctionnalités
*
* - Désormais lorsqu'une erreur "attendue" se déclenche, un email nous est envoyé pour nous le signaler.
*
* - A chaque lancement du programme les fichiers de données sont copiés dans des fichiers ".bak", lesquels seront utilisables en cas de crash. Ce système ne remplacement toutefois pas une sauvegarde quotidienne que l'on pourrait faire avec, e.g. http://www.clubic.com/telecharger-fiche11081-cobian-backup.html.
*
* - Lorsqu'une erreur est détectée durant l'exécution du programme, le système tant de faire une sauvegarde avant de se fermer.
*
* - Génération de coredump, lors que le programme plante afin d'établir la raison du plantage. Ce module n'est pas tout à fait fonctionnel, il sera compléter dans la prochaine version.
*
* Correction de bugs
*
* - Correction d'un bug avec avec le bouton besoin / notes qui ne fonctionnait pas.
*
* Revision 1.1  2006/08/27 15:42:00  pascal
* - Système de mise à jour automatique
*
*/

#include "smtp.h"

//----------------------------------------------------------------------------
// SMTP Procedure
//----------------------------------------------------------------------------
#include <qtextstream.h>
#include <qsocket.h>
#include <qdns.h>
#include <qtimer.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qregexp.h>


Smtp::Smtp( const QString &from, const QString &to,
	    const QString &subject,
	    const QString &body )
{
    socket = new QSocket( this );
    connect ( socket, SIGNAL( readyRead() ),
	      this, SLOT( readyRead() ) );
    connect ( socket, SIGNAL( connected() ),
	      this, SLOT( connected() ) );

    mxLookup = new QDns( to.mid( to.find( '@' )+1 ), QDns::Mx );
    connect( mxLookup, SIGNAL(resultsReady()),
	     this, SLOT(dnsLookupHelper()) );

    message = QString::fromLatin1( "From: " ) + from +
	      QString::fromLatin1( "\nTo: " ) + to +
	      QString::fromLatin1( "\nSubject: " ) + subject +
	      QString::fromLatin1( "\n\n" ) + body + "\n";
    message.replace( QString::fromLatin1( "\n" ),
		     QString::fromLatin1( "\r\n" ) );
    message.replace( QString::fromLatin1( "\r\n.\r\n" ),
		     QString::fromLatin1( "\r\n..\r\n" ) );

    this->from = from;
    rcpt = to;

    state = Init;
}


Smtp::~Smtp()
{
    delete t;
    delete socket;
}


void Smtp::dnsLookupHelper()
{
    QValueList<QDns::MailServer> s = mxLookup->mailServers();
    if ( s.isEmpty() ) {
	if ( !mxLookup->isWorking() )
	    qDebug( "Error in MX record lookup" );
	return;
    }

    qDebug( tr( "Connecting to %1" ).arg( s.first().name ) );

    socket->connectToHost( s.first().name, 25 );
    t = new QTextStream( socket );
}


void Smtp::connected()
{
    qDebug( tr( "Connected to %1" ).arg( socket->peerName() ) );
}

void Smtp::readyRead()
{
    // SMTP is line-oriented
    if ( !socket->canReadLine() )
	return;

    QString responseLine;
    do {
	responseLine = socket->readLine();
	response += responseLine;
    } while( socket->canReadLine() && responseLine[3] != ' ' );
    responseLine.truncate( 3 );

    if ( state == Init && responseLine[0] == '2' ) {
	// banner was okay, let's go on
	*t << "HELO there\r\n";
	state = Mail;
    } else if ( state == Mail && responseLine[0] == '2' ) {
	// HELO response was okay (well, it has to be)
	*t << "MAIL FROM: <" << from << ">\r\n";
	state = Rcpt;
    } else if ( state == Rcpt && responseLine[0] == '2' ) {
	*t << "RCPT TO: <" << rcpt << ">\r\n";
	state = Data;
    } else if ( state == Data && responseLine[0] == '2' ) {
	*t << "DATA\r\n";
	state = Body;
    } else if ( state == Body && responseLine[0] == '3' ) {
	*t << message << ".\r\n";
	state = Quit;
    } else if ( state == Quit && responseLine[0] == '2' ) {
	*t << "QUIT\r\n";
	// here, we just close.
	state = Close;
	qDebug( "Message sent" );
    } else if ( state == Close ) {
	deleteLater();
	return;
    } else {
	// something broke.
	QMessageBox::warning( qApp->activeWindow(),
			      tr( "Qt Mail" ),
			      tr( "Unexpected reply from SMTP server:\n\n" ) +
			      response );
	state = Close;
    }

    response = "";
}
