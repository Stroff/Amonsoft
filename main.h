/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: main.h,v 1.16 2006/10/12 21:19:33 pascal Exp $
* $Log: main.h,v $
* Revision 1.16  2006/10/12 21:19:33  pascal
* - Generation de minidump OK
*
* Revision 1.15  2006/10/09 10:06:07  pascal
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
* Revision 1.14  2006/09/04 11:44:22  pascal
* Version 0.2.3
* Nouvelles fonctionnalit�s
*
* - Recherche complexe deuxi�me version
*     Les recherches sont d�finies dans le fichier search.ini qui se trouve par d�faut dans "c:\program files\Amonsoft\".
*     La syntaxe de ce fichier est d�sormais de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE AND|OR [!] MOTCLE
*
*     Il est donc d�sormais possible de combiner deux crit�res de recherche.
*
* - Modification des mots clefs :
*         ANNIVERSAIRE renvoit d�sormais la liste des personnes dont c'est l'anniversaire (m�me jour et m�me mois que le syst�me).
*         DATEANNIVERSAIRE n�cessitera dans l'interface la saisie d'une date (m�me fonctionnement l'ancien ANNIVERSAIRE).
*
* - Les recherches par nom, pr�nom et type de clients sont combin�s aux recherches complexes. Il est ainsi possible de chercher un client, par exemple, qui n'a pas de mutuelle et dont le pr�nom contient "dou".
*
* - "Exporter personnes" dans le menu Fichier, devient "Exporter". Il est d�sormais possible d'exporter une fiche entreprise en XML pour l'ouvrir avec Word.
*
* - Un syst�me de mise � jour automatique est en place. La v�rification s'effectue au lancement du programme, si une nouvelle version est disponible vous pouvez la t�l�charger. Lors du t�l�chargement de la nouvelle version, le programme est bloqu� afin de ne pas y saisir d'information qui ne pourront �tre sauvegard�e. La nouvelle version est t�l�charg�e dans le r�pertoire courant du programme, une fois le t�l�chargement fini, l'installation est automatiquement lanc�e.
*
* Correction de bugs
*
* - Pas de corrections dans cette version
*
* Revision 1.13  2006/08/04 11:21:48  pascal
* Version 0.2.2
* Nouvelles fonctionnalit�s
*
* - Recherche complexe premi�re version
*     Les recherches sont d�finies dans le fichier search.ini qui se trouve par d�faut dans "c:\program files\Amonsoft\" (un fichier d'exemple est fourni lors de l'installation).
*     La syntaxe de ce fichier est de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE
*
*     Toutes les lignes commen�ant par '#' ne seront pas interpr�t�es par le programme.
*     Nom: repr�sente le terme sous lequel vous retrouverez la recherche dans le programme.
*     0 signifie qu'il s'ag�t d'une recherche pour les particuliers.
*     ! facultatif, le point d'exclamation permet de renvoyer l'inverse des valeurs retourn�es par le MOTCLE
*     MOTCLE est une valeur dans la liste tel que
*         ANNIVERSAIRE n�cessitera dans l'interface la saisie d'une date
*         AGE n�cessitera dans l'interface la saisie d'une valeur num�rique
*         REVENUS n�cessitera dans l'interface la saisie d'une valeur num�rique
*         BILAN n�cessitera dans l'interface la saisie d'une valeur texte
*         MUTUELLE, RETRAITE, FISCALITERETRAITEMADELIN et ASSURANCEVIE ne requi�re aucune saisie dans l'interface
*
*     Attention pour le moment, les recherches par Nom, Pr�nom ou prospect ne tiennent pas comptent de la recherche complexe s�lectionn�e.
*     Par exemple, il n'est pas possible encore, d'avoir la liste des prospect, qui n'ont pas d'assurance vie.
*
* - Les espaces superflus ne sont plus sauvegard�s dans les fichiers XML
* - Dans la liste des dossiers personnes Fichier/Exporter Personnes permet d'exporter la liste des personnes concern�es par une recherche complexe dans un fichier CSV compatible avec Excel.
* - Lorsqu'une fiche client ou prospect est ouverte Fichier/Exporter Personnes permet d'exporter la personne courante dans deux fichiers XML compatible Word.
*
* Correction de bugs
*
* - La liste des revenus n'�taient pas sauvegard�e dans les fichiers XML
* - Lors de l'ouverture des formulaires annexes d'une fiche les compagnies d'assurance n'�taient pas toujours correctement s�lectionn�es
* - Une personne ne peut plus �tre mari�e qu'� une autre personne (plus de polygamie)
* - Les filtres simples par Nom, Pr�nom et Type de client souffraient de bugs lorsqu'on voulait utiliser les 3 crit�res de recherche
*
* Revision 1.12  2006/06/02 19:11:16  pascal
* Version 0.2.0
* - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
* - Suppression des masques sur les pourcentages dans QT
*
* Revision 1.11  2006/05/12 16:22:43  pascal
* Version 0.1 build 14
* - Le fond de la form principale passe au bleu
* - [BUG] : Probl�me avec le chargement des dates depuis l'XML : Les dates sont d�sormais au format ISO
*
* Revision 1.10  2006/04/29 16:27:48  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui �taient partag�es
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipul� que par Id
* - Correction de bug : suppression de la liste des retraites
* - R�activation de la sauvegarde manuel et correction des bugs qui ont conduit � sa d�sactivation
*
* Revision 1.9  2006/04/21 00:07:22  pascal
* Version 0.1.12
*
* - correction du probl�me li�e au reset des listes dynamique.
* - CPersonne ne cr�e par forc�mment un CFamille (� surveiller !)
* - nouvelle image pour les prospects
* - correction bugs mineurs
*
* Revision 1.8  2006/04/16 22:34:32  pascal
* - liens entre employ�s & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des g�rants & employ�s depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.7  2006/03/21 10:42:11  pascal
* *** empty log message ***
*
* Revision 1.6  2006/01/20 13:18:39  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs � tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet d�sormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de donn�es
*
* Revision 1.5  2005/12/18 19:30:58  pascal
* - CFamille est d�sormais enregistr� dans un fichier
* - Ajout dans main.cpp/h de ParserFamille
* - CPersonne.savetoXML appel d�sormais l'enregistrement du CFamille correspondant
* - Ajout dans main.cpp de la fonction de chargement des Familles
* - amonsoft.ui.h: Ajout dans ChargerPersonne du code permettant de remplir la comboBox du conjoint
* - Toutes les fonctions de chargements et d'enregistrement des Familles sont faites
* - TODO: M�j de bugs
*
* Revision 1.4  2005/11/12 15:04:44  pascal
* Mise � niveau ...
*
* Revision 1.3  2005/10/26 10:15:03  pascal
* - ajout des entreprises
*
* Revision 1.2  2005/10/12 16:19:25  pascal
* - am�liorations de la class pour le parsing
* - chargement du fichier de donn�e au d�marrage
*
* Revision 1.1  2005/10/11 07:57:25  pascal
* - ajout de la class CParser, qui permet de faire abstraction de Xerces un minimum
* - les variables globales sont d�finies dans main.h
* - les images ne sont plus int�gr�es dans les fichiers
*
*
*/

#ifndef _MAIN_H_
# define _MAIN_H_

#include "CApp.h"

#endif /* _MAIN_H_ */