/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CCarriere.h,v 1.12 2006/05/23 16:06:39 pascal Exp $
* $Log: CCarriere.h,v $
* Revision 1.12  2006/05/23 16:06:39  pascal
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
* Revision 1.11  2006/04/29 16:29:28  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.10  2006/01/20 13:18:44  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.9  2005/12/27 10:28:04  pascal
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
* Revision 1.8  2005/10/11 08:12:16  pascal
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
* Revision 1.6  2005/10/04 10:16:33  pascal
* - ajout des dialogues dlgArretMaladie, dlgEmploi, dlgEnfant, dlgGarantieDeces et dlgRenteEducation
* - les listes sont desormais static et public pour que l'interface puisse y ajouter des valeurs
* - CJobs devient SJobs
* - modification de la structure de CEnfant : plus de lien vers CFamille, nouvelle champ prénom et nouvelle méthode pour accéder aux variables
* - les std::list sont encapsulées dans des types pour une manipulation plus souple
*
* Revision 1.5  2005/09/29 15:51:27  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.4  2005/09/27 15:28:10  pascal
* - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
*
* Revision 1.3  2005/09/21 17:21:03  pascal
* - Amélioration pour la gestion des données
* - Fichier TODO
* - Nouvelle classe de données CPrevoyance
*
* Revision 1.2  2005/09/09 15:49:38  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
*
*/

#ifndef _CCARRIERE_H_
# define _CCARRIERE_H_

// QT basic types
#include <qdatetime.h>
#include <qstring.h>
// STL
#include <list>

#include "CDatas.h"
#include "defines.h"

namespace Datas
{
/* For information *only*
  enum eStatutPro
  {
      eSalarie,
      eSalarieCadre,
      eETAM,
      eFonctionnaire,
      eArtisant,
      eCommercant,
      eLiberal,
      eExploitantAgricole
  };
*/

  struct SJobs
  {
      QDate                       dEntree_;
      QDate                       dFin_;
      enum eStatutPro             eStatut_;
      uint                        uRevenus_;
      uint                        uPointsRCO_;
      QString                     sNotes_;
  };

  typedef std::list< struct SJobs* >  t_listJobs;

  /*
   * CCarriere
   * Carrier of consumer
   */

  class CCarriere
  {
    public:
      // Constructor
      CCarriere();
      // Destructor
      ~CCarriere();

    public:
      // CDatas virtual functions
      int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
	  int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *) const;

      // Graphical functions
      virtual void loadInQT( dlgAmonSoft & ) const;
      virtual void copyFromQT( const dlgAmonSoft & );

      // Get string of status
      static QString statutToString( enum eStatutPro );

    public:
      // list of jobs
      t_listJobs             listEmplois_;

    private:
      uint                          uDepartRetraite_;
  };

}

#endif /* _CCARRIERE_H_ */