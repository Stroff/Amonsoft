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
* Revision 1.14  2006/09/04 11:44:22  pascal
* Version 0.2.3
* Nouvelles fonctionnalités
*
* - Recherche complexe deuxième version
*     Les recherches sont définies dans le fichier search.ini qui se trouve par défaut dans "c:\program files\Amonsoft\".
*     La syntaxe de ce fichier est désormais de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE AND|OR [!] MOTCLE
*
*     Il est donc désormais possible de combiner deux critères de recherche.
*
* - Modification des mots clefs :
*         ANNIVERSAIRE renvoit désormais la liste des personnes dont c'est l'anniversaire (même jour et même mois que le système).
*         DATEANNIVERSAIRE nécessitera dans l'interface la saisie d'une date (même fonctionnement l'ancien ANNIVERSAIRE).
*
* - Les recherches par nom, prénom et type de clients sont combinés aux recherches complexes. Il est ainsi possible de chercher un client, par exemple, qui n'a pas de mutuelle et dont le prénom contient "dou".
*
* - "Exporter personnes" dans le menu Fichier, devient "Exporter". Il est désormais possible d'exporter une fiche entreprise en XML pour l'ouvrir avec Word.
*
* - Un système de mise à jour automatique est en place. La vérification s'effectue au lancement du programme, si une nouvelle version est disponible vous pouvez la télécharger. Lors du téléchargement de la nouvelle version, le programme est bloqué afin de ne pas y saisir d'information qui ne pourront être sauvegardée. La nouvelle version est téléchargée dans le répertoire courant du programme, une fois le téléchargement fini, l'installation est automatiquement lancée.
*
* Correction de bugs
*
* - Pas de corrections dans cette version
*
* Revision 1.13  2006/08/04 11:21:48  pascal
* Version 0.2.2
* Nouvelles fonctionnalités
*
* - Recherche complexe première version
*     Les recherches sont définies dans le fichier search.ini qui se trouve par défaut dans "c:\program files\Amonsoft\" (un fichier d'exemple est fourni lors de l'installation).
*     La syntaxe de ce fichier est de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE
*
*     Toutes les lignes commençant par '#' ne seront pas interprétées par le programme.
*     Nom: représente le terme sous lequel vous retrouverez la recherche dans le programme.
*     0 signifie qu'il s'agît d'une recherche pour les particuliers.
*     ! facultatif, le point d'exclamation permet de renvoyer l'inverse des valeurs retournées par le MOTCLE
*     MOTCLE est une valeur dans la liste tel que
*         ANNIVERSAIRE nécessitera dans l'interface la saisie d'une date
*         AGE nécessitera dans l'interface la saisie d'une valeur numérique
*         REVENUS nécessitera dans l'interface la saisie d'une valeur numérique
*         BILAN nécessitera dans l'interface la saisie d'une valeur texte
*         MUTUELLE, RETRAITE, FISCALITERETRAITEMADELIN et ASSURANCEVIE ne requière aucune saisie dans l'interface
*
*     Attention pour le moment, les recherches par Nom, Prénom ou prospect ne tiennent pas comptent de la recherche complexe sélectionnée.
*     Par exemple, il n'est pas possible encore, d'avoir la liste des prospect, qui n'ont pas d'assurance vie.
*
* - Les espaces superflus ne sont plus sauvegardés dans les fichiers XML
* - Dans la liste des dossiers personnes Fichier/Exporter Personnes permet d'exporter la liste des personnes concernées par une recherche complexe dans un fichier CSV compatible avec Excel.
* - Lorsqu'une fiche client ou prospect est ouverte Fichier/Exporter Personnes permet d'exporter la personne courante dans deux fichiers XML compatible Word.
*
* Correction de bugs
*
* - La liste des revenus n'étaient pas sauvegardée dans les fichiers XML
* - Lors de l'ouverture des formulaires annexes d'une fiche les compagnies d'assurance n'étaient pas toujours correctement sélectionnées
* - Une personne ne peut plus être mariée qu'à une autre personne (plus de polygamie)
* - Les filtres simples par Nom, Prénom et Type de client souffraient de bugs lorsqu'on voulait utiliser les 3 critères de recherche
*
* Revision 1.12  2006/06/02 19:11:16  pascal
* Version 0.2.0
* - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
* - Suppression des masques sur les pourcentages dans QT
*
* Revision 1.11  2006/05/12 16:22:43  pascal
* Version 0.1 build 14
* - Le fond de la form principale passe au bleu
* - [BUG] : Problème avec le chargement des dates depuis l'XML : Les dates sont désormais au format ISO
*
* Revision 1.10  2006/04/29 16:27:48  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.9  2006/04/21 00:07:22  pascal
* Version 0.1.12
*
* - correction du problème liée au reset des listes dynamique.
* - CPersonne ne crée par forcémment un CFamille (à surveiller !)
* - nouvelle image pour les prospects
* - correction bugs mineurs
*
* Revision 1.8  2006/04/16 22:34:32  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.7  2006/03/21 10:42:11  pascal
* *** empty log message ***
*
* Revision 1.6  2006/01/20 13:18:39  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.5  2005/12/18 19:30:58  pascal
* - CFamille est désormais enregistré dans un fichier
* - Ajout dans main.cpp/h de ParserFamille
* - CPersonne.savetoXML appel désormais l'enregistrement du CFamille correspondant
* - Ajout dans main.cpp de la fonction de chargement des Familles
* - amonsoft.ui.h: Ajout dans ChargerPersonne du code permettant de remplir la comboBox du conjoint
* - Toutes les fonctions de chargements et d'enregistrement des Familles sont faites
* - TODO: Màj de bugs
*
* Revision 1.4  2005/11/12 15:04:44  pascal
* Mise à niveau ...
*
* Revision 1.3  2005/10/26 10:15:03  pascal
* - ajout des entreprises
*
* Revision 1.2  2005/10/12 16:19:25  pascal
* - améliorations de la class pour le parsing
* - chargement du fichier de donnée au démarrage
*
* Revision 1.1  2005/10/11 07:57:25  pascal
* - ajout de la class CParser, qui permet de faire abstraction de Xerces un minimum
* - les variables globales sont définies dans main.h
* - les images ne sont plus intégrées dans les fichiers
*
*
*/

#ifndef _MAIN_H_
# define _MAIN_H_

#include "CApp.h"

#endif /* _MAIN_H_ */