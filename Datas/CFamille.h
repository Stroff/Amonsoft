/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: CFamille.h,v 1.15 2006/06/02 19:11:17 pascal Exp $
 * $Log: CFamille.h,v $
 * Revision 1.15  2006/06/02 19:11:17  pascal
 * Version 0.2.0
 * - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
 * - Suppression des masques sur les pourcentages dans QT
 *
 * Revision 1.14  2006/05/23 16:06:40  pascal
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
 * Revision 1.13  2006/04/29 16:29:28  pascal
 * Version 0.1 build 13
 * - Correction d'un bug avec les listes 'static' qui �taient partag�es
 * - Suppression des boutons "Valider" & "Rester"
 * - Modification des images des boutons
 * - Personnes et Entreprises ne sont plus manipul� que par Id
 * - Correction de bug : suppression de la liste des retraites
 * - R�activation de la sauvegarde manuel et correction des bugs qui ont conduit � sa d�sactivation
 *
 * Revision 1.12  2005/12/27 10:28:04  pascal
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
 * Revision 1.11  2005/12/20 19:14:46  pascal
 * - liste des prospects m�j
 * - modification du conjoint prises en compte
 *
 * Revision 1.10  2005/12/18 19:30:59  pascal
 * - CFamille est d�sormais enregistr� dans un fichier
 * - Ajout dans main.cpp/h de ParserFamille
 * - CPersonne.savetoXML appel d�sormais l'enregistrement du CFamille correspondant
 * - Ajout dans main.cpp de la fonction de chargement des Familles
 * - amonsoft.ui.h: Ajout dans ChargerPersonne du code permettant de remplir la comboBox du conjoint
 * - Toutes les fonctions de chargements et d'enregistrement des Familles sont faites
 * - TODO: M�j de bugs
 *
 * Revision 1.9  2005/11/30 18:16:48  pascal
 * - am�liorations des chargements / enregistrements XML
 * - CFamille peut d�sormais �tre sauvegarder dans un fichier
 * - Correction de bugs pour l'XML des entses
 *
 * Revision 1.8  2005/10/11 08:12:17  pascal
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
 * Revision 1.4  2005/09/27 15:28:11  pascal
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

#ifndef _FAMILLE_H_
# define _FAMILLE_H_

// QT basic types
#include <qdatetime.h>
#include <qstring.h>
#include <list>

#include "CDatas.h"
#include "defines.h"

namespace Datas
{

  // Type declaration
  class CPersonnes;
  class CEnfants;
  typedef std::list< Datas::CEnfants* >        t_listEnfants;

  /* CFamille
   * This class contain information about person family links
   */  

  class CFamille
  {
    public:
      // Constructor
      CFamille( const CPersonnes* /* Beneficiaire */ );
      // Destructor
      ~CFamille();

    public:
      // CDatas virtual functions
      int loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode );
      int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const;

      // Graphical functions
      virtual void loadInQT( dlgAmonSoft & ) const;
//TODO      virtual void loadInQT( dlgAmonSoft &, bool ) const;
      virtual void copyFromQT( const dlgAmonSoft & );

      const CPersonnes    *getBeneficiaire() const { return pBeneficiaire_; }
      void                 setConjoint( CPersonnes *pConjoint ) { pConjoint_ = pConjoint; }
      const CPersonnes    *getConjoint() const { return pConjoint_; }

    private:
      // Personal informations about relation link
      const CPersonnes                   *pBeneficiaire_;
      uint                               uDureePrecMariageBeneficiaire_;
      CPersonnes                         *pConjoint_;
      ushort                             usConjointId_;
      uint                               uDureePrecMariageConjoint_;
      enum Relation {
        eNone,
        eMarie,
        eCelibataire,
        eDivorce,
        eVeuf,
        eUnionLibre,
        ePACS,
        eConcubinage }                   TypeRelation_;
      QDate                              dMariage_;
      enum {
        eCommunauteAcquets,
        eParticipationAcquets,
        eCommunauteUniverselle,
        eSeparationBiens }              RegimeMatrimonial_;      
      QString                           sTestament_;
      QString                           sDonationEntreEpoux_;
      ushort                            usNbEnfantsCommuns_;
      ushort                            usNbEnfantsBeneficiaire_;
      ushort                            usNbEnfantsProspect_;
      ushort                            usRangMariage_;
      bool                              bDernierVivant_;
      QString                           sAutresDispositions_;


    public:
      t_listEnfants              listEnfants_;
  };

  /*
   * CEnfants
   * This class contain information about family child
   * -- TODO: Add link if child is also consumer of the society --
   */
  class CEnfants
  {
    public:
      // Constructor
      CEnfants() {}
      CEnfants( QString sNom, QString sPrenom, QDate dNaissance, bool bACharge, bool bEnEtudes, QString sNote ) :
        sNom_( sNom ),
        sPrenom_( sPrenom ),
        dNaissance_( dNaissance ),
        bACharge_( bACharge ),
        bEnEtudes_( bEnEtudes ),
        sNote_( sNote )
        {}
      // Destructor
      ~CEnfants();

    public:
      // CDatas virtual functions
      void loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *Node );
      void saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

      // Graphical functions
      virtual void loadInQT( dlgAmonSoft & ) const;
      virtual void copyFromQT( const dlgAmonSoft & );

    public:
      QString GetNom() const { return sNom_; }
      QString GetPrenom() const { return sPrenom_; }
      QDate   GetDate() const { return dNaissance_; }
      bool    ACharge() const { return bACharge_; }
      bool    EnEtudes() const { return bEnEtudes_; }
      QString GetNote() const { return sNote_; }

    private:
      QString                  sNom_;
      QString                  sPrenom_;
      QDate                    dNaissance_;
      bool                     bACharge_;
      bool                     bEnEtudes_;
      QString                  sNote_;   // Note from operator
  };
}

#endif /* _FAMILLE_H_ */