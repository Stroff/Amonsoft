/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: Dynamique.ui.h,v 1.4 2006/04/29 16:29:29 pascal Exp $
* $Log: Dynamique.ui.h,v $
* Revision 1.4  2006/04/29 16:29:29  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.3  2005/10/11 08:08:43  pascal
* - Main.* ont été renommé amonsoft.*
* - la classe générée par QT Designer pour l'interface globale s'appelle maintenant dlgMain
* - AmonSoft est désormais définie dans les fichiers Dynamique.* est hérite de dlgMain
* - AmonSoft définie les actions liées aux formulaires annexes qui permettent de saisir les données
* - liens avec le parser pour les ouvertures et les sauvegardes
* - ouvrir un fichier devient ouvrir une autre base de donnée, par défaut on ouvre un fichier dans xml/
* - début de l'interface de préférence
* - les informations entreprises sont différenciées de celle des particuliers
* - ajout des listes permettant de retrouver les participants et les prospects
* - modifications de prévoyance suite à la demande du client
* - ajout de dlgRetraite
*
* Revision 1.2  2005/10/04 10:12:35  pascal
* - ajout des dialogues dlgArretMaladie, dlgEmploi, dlgEnfant, dlgGarantieDeces et dlgRenteEducation
* - renommage des dialogues avec le prefixe dlg
* - modification de l'interface principale pour qu'elle support les nouvelles fenêtre de dialogue et pour qu'elle affiche les informations ajoutées par ces dialogues dans des listView
* - nouvelles images pour les nouvelles fenêtre de dialogue
*
* Revision 1.1  2005/10/01 17:10:13  pascal
* - Ajout d'une nouvelle dialogue pour les emprunts
* - Ajout d'une nouvelle image pour le dialogue sur les emprunts
* - Dynamique.ui.h permet de séparer les fonctions dynamiques (données) de l'interface
* - LoadFromQT pour la prévoyance est terminée
*
*/

#ifndef _DYNAMIQUE_UI_H_
# define _DYNAMIQUE_UI_H_

// Includes QT
#include <qvariant.h>
#include <qmainwindow.h>
#include <qdialog.h>
#include <qwidgetstack.h>
#include <qaction.h>
#include <qlistview.h>

#include "Forms/amonsoft.h"
#include "Forms/Dynamique.h"

#include "Datas/CPersonnes.h"
#include "Datas/CEntreprise.h"

extern Datas::CPersonnes    *pCurrentPersonne;
extern Datas::CEntreprise   *pCurrentEntreprise;

//****************************************************************************
//  Definitions of type
//****************************************************************************

//****************************************************************************
//  Global variables
//****************************************************************************

//****************************************************************************
//  Functions
//****************************************************************************


#endif /* _DYNAMIQUE_UI_H_ */
