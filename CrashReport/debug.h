/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: debug.h,v 1.1 2006/10/12 21:20:04 pascal Exp $
* $Log: debug.h,v $
* Revision 1.1  2006/10/12 21:20:04  pascal
* - Generation de minidump OK
*
* Revision 1.1  2006/10/09 10:06:07  pascal
* Version 0.2.4
*
* Nouvelles fonctionnalit�s
*
* - D�sormais lorsqu'une erreur "attendue" se d�clenche, un email nous est envoy� pour nous le signaler.
*
* - A chaque lancement du programme les fichiers de donn�es sont copi�s dans des fichiers ".bak", lesquels seront utilisables en cas de crash. Ce syst�me ne remplacement toutefois pas une sauvegarde quotidienne que l'on pourrait faire avec, e.g. http://www.clubic.com/telecharger-fiche11081-cobian-backup.html.
*
* - Lorsqu'une erreur est d�tect�e durant l'ex�cution du programme, le syst�me tant de faire une sauvegarde avant de se fermer.
*
* - G�n�ration de coredump, lors que le programme plante afin d'�tablir la raison du plantage. Ce module n'est pas tout � fait fonctionnel, il sera compl�ter dans la prochaine version.
*
* Correction de bugs
*
* - Correction d'un bug avec avec le bouton besoin / notes qui ne fonctionnait pas.
*
* Revision 1.1  2006/08/27 15:42:00  pascal
* - Syst�me de mise � jour automatique
*
*/

#ifndef _DEBUG_H_
# define _DEBUG_H_

#include "smtp.h"

#define MAIL_FROM       "amonsoft@sesam-micro.fr"
#define MAIL_TO         "pascal.bart@sesam-micro.fr"
#define SUBJECT         "Rapport automatique d erreur AmonSoft"

void mAssert( bool, const char * );

#endif /* _DEBUG_H_ */