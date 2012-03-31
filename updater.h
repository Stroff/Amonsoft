/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: updater.h,v 1.1 2006/08/27 15:42:00 pascal Exp $
* $Log: updater.h,v $
* Revision 1.1  2006/08/27 15:42:00  pascal
* - Système de mise à jour automatique
*
*/

#ifndef _UPDATER_H_
# define _UPDATER_H_

#include <qobject.h>
#include <qstring.h>
#include <qhttp.h>
#include <qfile.h>
#include <qnetworkprotocol.h>

# define URL_UPDATE "otsbn.dnsalias.net"

/*
 * CUpdater
 * Check for available update on the Internet
 * Install update
 */

class CUpdater : public QObject
{
    Q_OBJECT

    public:
        // Constructor
        CUpdater( QWidget& );
        // Destructor
        ~CUpdater();

    public:
        // Check version
        void updateAvailable();

    private:
        // Download Update
        void downloadUpdate( QString sVersion );
        // Diff version
        int diffVersion( QString sCurrent, QString sNet );

    private slots:
        void done( bool done );

    private:
        QHttp        url_;
        QWidget      &main_;
        ushort       state_;
        QFile        *file_;
};

#endif /* _UPDATER_H_ */