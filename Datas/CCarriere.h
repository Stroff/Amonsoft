/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CCarriere.h,v 1.12 2006/05/23 16:06:39 pascal Exp $
* $Log: CCarriere.h,v $
* Revision 1.12  2006/05/23 16:06:39  pascal
* - Correction du bugs sur les clients phant�mes
* - D�but des fonctionnalit�s de recherche
* - Correction du bugs sur les listes de status pro
* - Charger / Valider: Enregistre �galement les XML d�sormais
* - Correction du bugs avec le chargement des enfants dans famille
* - Correction du bug qui emp�chait le chargement d'un client depuis une entrses
* - Am�lioration interface : champs plus larges et corrections divers
* - Correction du bug avec l'enregistrement des dates de naissance
* - L'ajout d'un dirigeant ou d'un employ� permet de cr�e des clients prospect directement
* - Suppression de l'onglet liste des prospects dans les fiches personnelles
*
* Revision 1.11  2006/04/29 16:29:28  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui �taient partag�es
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipul� que par Id
* - Correction de bug : suppression de la liste des retraites
* - R�activation de la sauvegarde manuel et correction des bugs qui ont conduit � sa d�sactivation
*
* Revision 1.10  2006/01/20 13:18:44  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs � tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet d�sormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de donn�es
*
* Revision 1.9  2005/12/27 10:28:04  pascal
* - Release 1.0.6 (build 1 & 2)
* - Nouveaux champs pour les particuliers
* - Corrections de bugs chargement XML / sauvegarde XML
* - Corrections de bugs chargement QT / sauvegardes QT
* - Modification de l'installeur pour ne pas �craser les fichiers de donn�es
* - Modification de la mani�re dont sont g�r�s les QDate
* - Correction du bug avec le slot DelAssuranceVie
* - TODO : m�j
* - Liens b�n�ficiaire / prospect corrig�s
*
* Revision 1.8  2005/10/11 08:12:16  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de donn�es n'h�ritent plus de CDatas � part CPersonne et CEntreprise
* - les fonctions li�es � QT sont toutes impl�ment�es
* - les fonctions saveToXML sont impl�ment�es pour les particuliers
*
* Revision 1.7  2005/10/05 17:14:23  pascal
* - nouvelle structure de donn�es pour stocker les informations sur l'�pargne
* - r�solution du probl�me li� � l'�pouse : m�thodes surcharg�es avec un bool suppl�mentaire permettant de savoir � qui l'on a � faire dans CPersonne et dans CRevenus.
* - loadInQT impl�ment� pour toutes les classes
*
* Revision 1.6  2005/10/04 10:16:33  pascal
* - ajout des dialogues dlgArretMaladie, dlgEmploi, dlgEnfant, dlgGarantieDeces et dlgRenteEducation
* - les listes sont desormais static et public pour que l'interface puisse y ajouter des valeurs
* - CJobs devient SJobs
* - modification de la structure de CEnfant : plus de lien vers CFamille, nouvelle champ pr�nom et nouvelle m�thode pour acc�der aux variables
* - les std::list sont encapsul�es dans des types pour une manipulation plus souple
*
* Revision 1.5  2005/09/29 15:51:27  pascal
* - Les boutons des onglets de la section ajouter poss�dent d�sormais une image
* - copyFromQT est bient�t impl�ment�e pour toutes les classes
*
* Revision 1.4  2005/09/27 15:28:10  pascal
* - Mise en place dans CData des m�thodes relatives � l'interface : r�alisation du squelette
*
* Revision 1.3  2005/09/21 17:21:03  pascal
* - Am�lioration pour la gestion des donn�es
* - Fichier TODO
* - Nouvelle classe de donn�es CPrevoyance
*
* Revision 1.2  2005/09/09 15:49:38  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ d�rive d�sormais de CDatas et d�finisse les classes virtuelles pures
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