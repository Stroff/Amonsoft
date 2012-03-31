/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: CPersonnes.h,v 1.22 2006/08/04 11:21:48 pascal Exp $
 * $Log: CPersonnes.h,v $
 * Revision 1.22  2006/08/04 11:21:48  pascal
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
 * Revision 1.21  2006/06/21 11:23:24  pascal
 * - systeme de recherche avancé
 * - correction de bug dans le chargement des Revenus et des Charges
 * - correction de bug dans le chargement des XML des familles
 *
 * Revision 1.20  2006/06/02 19:11:17  pascal
 * Version 0.2.0
 * - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
 * - Suppression des masques sur les pourcentages dans QT
 *
 * Revision 1.19  2006/05/23 16:06:40  pascal
 * - Correction du bugs sur les clients phantômes
 * - Début des fonctionnalités de recherche
 * - Correction du bugs sur les listes de status pro
 * - Charger / Valider: Enregistre également les XML désormais
 * - Correction du bugs avec le chargement des enfants dans famille
 * - Correction du bug qui empéchait le chargement d'un client depuis une entrses
 * - Amélioration interface : champs plus larges et corrections divers
 * - Correction du bug avec l'enregistrement des dates de naissance
 * - L'ajout d'un dirigeant ou d'un employé permet de crée des clients prospect directement
 * - Suppression de l'onglet liste des prospects dans les fiches personnelles
 *
 * Revision 1.18  2006/04/29 16:29:28  pascal
 * Version 0.1 build 13
 * - Correction d'un bug avec les listes 'static' qui étaient partagées
 * - Suppression des boutons "Valider" & "Rester"
 * - Modification des images des boutons
 * - Personnes et Entreprises ne sont plus manipulé que par Id
 * - Correction de bug : suppression de la liste des retraites
 * - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
 *
 * Revision 1.17  2006/04/16 22:12:25  pascal
 * - liens entre employés & entreprises
 * - correction de bug sur le chargement d'une personne depuis une autre
 * - chargement des gérants & employés depuis leur entreprise OK
 * - les tabulations sont dans le bon ordre
 * - version 0.1.10
 *
 * Revision 1.16  2006/03/21 10:42:16  pascal
 * *** empty log message ***
 *
 * Revision 1.15  2006/01/20 13:18:44  pascal
 * Version 1.0.8b
 * - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
 * - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
 * - Grosses modifications des fichiers de données
 *
 * Revision 1.14  2005/12/27 10:28:04  pascal
 * - Release 1.0.6 (build 1 & 2)
 * - Nouveaux champs pour les particuliers
 * - Corrections de bugs chargement XML / sauvegarde XML
 * - Corrections de bugs chargement QT / sauvegardes QT
 * - Modification de l'installeur pour ne pas écraser les fichiers de données
 * - Modification de la manière dont sont gérés les QDate
 * - Correction du bug avec le slot DelAssuranceVie
 * - TODO : màj
 * - Liens bénéficiaire / prospect corrigés
 *
 * Revision 1.13  2005/12/20 19:14:47  pascal
 * - liste des prospects màj
 * - modification du conjoint prises en compte
 *
 * Revision 1.12  2005/12/18 19:30:59  pascal
 * - CFamille est désormais enregistré dans un fichier
 * - Ajout dans main.cpp/h de ParserFamille
 * - CPersonne.savetoXML appel désormais l'enregistrement du CFamille correspondant
 * - Ajout dans main.cpp de la fonction de chargement des Familles
 * - amonsoft.ui.h: Ajout dans ChargerPersonne du code permettant de remplir la comboBox du conjoint
 * - Toutes les fonctions de chargements et d'enregistrement des Familles sont faites
 * - TODO: Màj de bugs
 *
 * Revision 1.11  2005/11/30 18:16:48  pascal
 * - améliorations des chargements / enregistrements XML
 * - CFamille peut désormais être sauvegarder dans un fichier
 * - Correction de bugs pour l'XML des entses
 *
 * Revision 1.10  2005/10/12 16:11:21  pascal
 * - implementation des fonctions loadFromXerces des classes CPersonnes *
 * - bug: ajout de CPrevoyance dans CPersonnes
 *
 * Revision 1.9  2005/10/11 22:53:58  pascal
 * - CPersonnes peut lire depuis le XML ses données
 * - CConseillers aussi
 * - CEpargnes en cours !
 *
 * Revision 1.8  2005/10/11 08:12:17  pascal
 * - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
 * - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
 * - les fonctions liées à QT sont toutes implémentées
 * - les fonctions saveToXML sont implémentées pour les particuliers
 *
 * Revision 1.7  2005/10/05 17:14:23  pascal
 * - nouvelle structure de données pour stocker les informations sur l'épargne
 * - résolution du problème lié à l'épouse : méthodes surchargées avec un bool supplémentaire permettant de savoir à qui l'on a à faire dans CPersonne et dans CRevenus.
 * - loadInQT implémenté pour toutes les classes
 *
 * Revision 1.6  2005/09/29 15:51:28  pascal
 * - Les boutons des onglets de la section ajouter possèdent désormais une image
 * - copyFromQT est bientôt implémentée pour toutes les classes
 *
 * Revision 1.5  2005/09/27 15:28:11  pascal
 * - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
 *
 * Revision 1.4  2005/09/21 17:21:03  pascal
 * - Amélioration pour la gestion des données
 * - Fichier TODO
 * - Nouvelle classe de données CPrevoyance
 *
 * Revision 1.3  2005/09/09 15:49:38  pascal
 * - Ajout de la classes virtuel pure CDatas
 * - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
 *
 */

#ifndef _CPERSONNES_H_
# define _CPERSONNES_H_

// QT basic types
#include <qdatetime.h>
#include <qstring.h>
#include <qlistview.h>

// STL
#include <list>

#include "defines.h"

// Externals definitions
#include "CDatas.h"
#include "CConseiller.h"
#include "CRevenus.h"
#include "CFiscalite.h"
#include "CFamille.h"
#include "CEpargne.h"
#include "CPrevoyance.h"
#include "CCarriere.h"
#include "CEntreprise.h"

#include "Forms/amonsoft.h"
#include "Preferences/CPreferences.h"

namespace Datas
{
  static ushort         usLastId;

  /* CPersonnes
   * This class contain informations about physical person
   */

  class CPersonnes
  {

    public:
      // Constructor
      CPersonnes( bool bEmpty = false );
      CPersonnes( QString sNom, QString sPrenom, QDate dNaissance );
      CPersonnes( CFamille *famille );
      // Destructor
      ~CPersonnes();

    public:
     QString            getNom() const { return sNom_; }
     QString            getPrenom() const { return sPrenom_; }
     QString            getTelephone() const { return sTelephone_; }
     QString            getEmail() const { return sEmail_; }
     ushort             getID() const { return usId_; }

     const CFamille     *getFamille() const { return pFamille_; }
     const CEpargnes    *getEpargne() const { return &Epargne_; }
     QDate              getDateNaissance() const { return dNaissance_; }
     const CPrevoyance  *getPrevoyance() const { return &Prevoyance_; }
     const CCarriere    *getCarriere() const { return &Carriere_; }
     const CRevenus     &getRevenus() const { return Revenus_; }
     t_Adresse          getAdresse() const { return Adresse_; }

     CFamille           *getFamille() { return pFamille_; }
     CEpargnes          *getEpargne() { return &Epargne_; }
     CPrevoyance        *getPrevoyance() { return &Prevoyance_; }
     CCarriere          *getCarriere() { return &Carriere_; }
     CRevenus           &getRevenus() { return Revenus_; }

     bool    isBeneficiaire() const {return bBeneficiaire_; }
     void    setBeneficiaire( bool bFoo ) { bBeneficiaire_ = bFoo; }

     // TODO: Find better method to set family without delete an unused pointer
     void    setFamille( CFamille *pFamille )
     { /* TODO if( pFamille_ != 0 ) delete pFamille_;*/ pFamille_ = pFamille; }
     void    setAdresse( t_Adresse add ) { Adresse_ = add; }
     void    setTelephone( QString sPhone ) { sTelephone_ = sPhone; }

     CEntreprise *getEntreprise() { return pEntreprise_; }
     void    setEntreprise( CEntreprise *pEntreprise, bool bGerant = false )
     { pEntreprise_ = pEntreprise; bGerant_ = bGerant; }
     void    removeEntreprise()
     { pEntreprise_ = 0; bGerant_ = false; }

     // Get CPersonne from ID
     // return 0 if Id not present
     static CPersonnes *getItemFromID( ushort usId );

    public:
      // CDatas virtual functions
      int loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode );
      int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMDocument *xmlNodeFamille ) const;

      // Graphical functions
      virtual void loadInQT( dlgAmonSoft & ) const;
      virtual void copyFromQT( const dlgAmonSoft & );

      // Overloaded method for friend
      virtual void loadInQT( dlgAmonSoft &, bool bFriend ) const;

    protected:
      ushort                  usId_;
      // Personal informations about consumer
      enum civilite {
          Mr,
          Melle,
          Mde }               eCiv_;
      QString                 sNom_;
      QString                 sNomJeuneFille_;
      QString                 sPrenom_;
      QDate                   dNaissance_;
      QString                 sLieuNaissance_;
      t_Adresse               Adresse_;
      t_Adresse               AdresseGestion_;
      QString                 sTelephone_;
      QString                 sTelephonePortable_;
      QString                 sTelephonePro_;
      QString                 sTelephoneFax_;
      QString                 sEmail_;
      CEntreprise             *pEntreprise_;
      bool                    bGerant_;
      // If not "beneficiaire" is "prospect"
      bool                    bBeneficiaire_;

      // Advisers
      CConseiller             *consNotaire_;
      CConseiller             *consAvocat_;
      CConseiller             *consComptable_;

      // Needs
      QString                 sBesoinsRetraite_;
      QString                 sBesoinsPrevoyance_;
      QString                 sBesoinsSante_;
      QString                 sBesoinsEpargne_;
      QString                 sBesoinsPatrimoine_;
      QString                 sNotes_;

      // Incomes informations
      CRevenus                Revenus_;

      // Taxes informations
      CFiscalite              Fiscalite_;

      // Familial
      CFamille                *pFamille_;

      // Saving
      CEpargnes               Epargne_;

      CPrevoyance             Prevoyance_;

      CCarriere               Carriere_;
  };

}

#endif /* _CPERSONNES_H_ */