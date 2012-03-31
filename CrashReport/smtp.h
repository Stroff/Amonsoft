/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: smtp.h,v 1.1 2006/10/12 21:20:04 pascal Exp $
* $Log: smtp.h,v $
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

#ifndef _SMTP_H_
# define _SMTP_H_

//----------------------------------------------------------------------------
// SMTP Procedure
//----------------------------------------------------------------------------
#include <qobject.h>
#include <qstring.h>

class QSocket;
class QTextStream;
class QDns;

class Smtp : public QObject
{
    Q_OBJECT

public:
    Smtp( const QString &from, const QString &to,
	  const QString &subject, const QString &body );
    ~Smtp();

signals:
    void status( const QString & );

private slots:
    void dnsLookupHelper();
    void readyRead();
    void connected();

private:
    enum State {
	Init,
	Mail,
	Rcpt,
	Data,
	Body,
	Quit,
	Close
    };

    QString message;
    QString from;
    QString rcpt;
    QSocket *socket;
    QTextStream * t;
    int state;
    QString response;
    QDns * mxLookup;
};

#endif /* _SMTP_H_ */