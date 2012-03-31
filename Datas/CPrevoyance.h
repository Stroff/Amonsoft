/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CPrevoyance.h,v 1.15 2006/06/21 11:23:24 pascal Exp $
* $Log: CPrevoyance.h,v $
* Revision 1.15  2006/06/21 11:23:24  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.14  2006/04/29 16:29:29  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.13  2006/04/21 00:08:16  pascal
* Version 0.1.12
*
* - correction du problème liée au reset des listes dynamique.
* - CPersonne ne crée par forcémment un CFamille (à surveiller !)
* - nouvelle image pour les prospects
* - correction bugs mineurs
*
* Revision 1.12  2006/03/21 10:42:17  pascal
* *** empty log message ***
*
* Revision 1.11  2006/01/20 13:18:45  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.10  2005/12/27 10:28:05  pascal
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
* Revision 1.9  2005/11/12 15:04:56  pascal
* Mise à niveau ...
*
* Revision 1.8  2005/10/12 16:11:21  pascal
* - implementation des fonctions loadFromXerces des classes CPersonnes *
* - bug: ajout de CPrevoyance dans CPersonnes
*
* Revision 1.7  2005/10/11 08:12:17  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
* Revision 1.6  2005/10/04 10:16:33  pascal
* - ajout des dialogues dlgArretMaladie, dlgEmploi, dlgEnfant, dlgGarantieDeces et dlgRenteEducation
* - les listes sont desormais static et public pour que l'interface puisse y ajouter des valeurs
* - CJobs devient SJobs
* - modification de la structure de CEnfant : plus de lien vers CFamille, nouvelle champ prénom et nouvelle méthode pour accéder aux variables
* - les std::list sont encapsulées dans des types pour une manipulation plus souple
*
* Revision 1.5  2005/10/01 17:10:11  pascal
* - Ajout d'une nouvelle dialogue pour les emprunts
* - Ajout d'une nouvelle image pour le dialogue sur les emprunts
* - Dynamique.ui.h permet de séparer les fonctions dynamiques (données) de l'interface
* - LoadFromQT pour la prévoyance est terminée
*
* Revision 1.4  2005/09/29 15:51:28  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.3  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
*
* Revision 1.2  2005/09/27 12:22:06  pascal
* - Toutes les containeurs pour l'interface réalisée sont en place
* - Retouche de l'interface avec une barre verticale pour l'ajout
*
* Revision 1.1  2005/09/21 17:21:03  pascal
* - Amélioration pour la gestion des données
* - Fichier TODO
* - Nouvelle classe de données CPrevoyance
*
*
*/

#ifndef _CPREVOYANCE_H_
# define _CPREVOYANCE_H_

// QT basic types
#include <qdatetime.h>
#include <qstring.h>

// STD
#include <list>

#include "CDatas.h"
#include "defines.h"
#include "Preferences/CPreferences.h"

namespace Datas
{
    enum eTypeFiscalite
    {
        eAssuranceVie,
        eMadelin
    };

    // Medical job stop
    struct SArretTravail
    {
        uint         uMontantIJ_;
        uint         uFranchise_;
        uint         uDuree_;
    };

    typedef std::list< struct Datas::SArretTravail* const >     t_listArretTravail;

    // Couverture emprunt (TODO: Translate)
    struct SCouvertureEmprunt
    {
        uint        uMontantRemboursement_;
        uint        uFranchise_;
        QString     sBanque_;
        QString     dDebut_;
        ushort      usTerme_;
        ushort      usTxMoyen_;
        QString     sTypeEmprunt_;
    };

    typedef std::list< struct Datas::SCouvertureEmprunt* const  >  t_listEmprunts;

    enum e_Beneficiaire
    {
        eFamille,
        eAssocie,
        eBanque,
        eEntreprise,
        eAutre
    };

    // Death Warranty
    struct SGarantieDeces
    {
        uint        uCapitaux_;
        uint        uMaladie_;
        uint        uAccident_;
        enum e_Beneficiaire  eBeneficiaire_;
        QString     sOther_;
        enum eTypeFiscalite eFiscalite_;
        struct Preferences::SCompagnie *pCompagnie_;
        QDate       dDateEffet_;
        uint        uDuree_;
    };

    typedef std::list< struct Datas::SGarantieDeces* const >    t_listGarantieDeces;

    // Education incoming
    struct SRenteEducation
    {
        uint        uAgeDebut_;
        uint        uAgeFin_;
        uint        uMontant_;
        ushort      usPourcentageSalaire_;
    };

    typedef std::list< struct Datas::SRenteEducation* const >  t_listRenteEducation;

  /*
   * CArretMaladie
   * Medical job stop
   */
  class CArretMaladie
  {
    public:
        // Constructor
        CArretMaladie() 
        {
            uFranchiseMaladie_ = 0;
            uFranchiseHopital_ = 0;
            uFranchiseAccident_ = 0;
            listArretTravail_.empty();
            bAccordEntreAssocies_ = true;
            uDureeAccord_ = 0;
            pCompagnie_ = 0;
        };
        // Destructor
        ~CArretMaladie() {};

    public:
        // CDatas virtual functions
        virtual int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
        virtual int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

        // Graphical functions
        virtual void loadInQT( dlgAmonSoft & ) const;
        virtual void copyFromQT( const dlgAmonSoft & );

    public:
        t_listArretTravail      listArretTravail_;

    private:
        uint                    uFranchiseMaladie_;
        uint                    uFranchiseHopital_;
        uint                    uFranchiseAccident_;
        struct Preferences::SCompagnie *pCompagnie_;
        QString			    	sContrat_;
        enum eTypeFiscalite		eFiscalite_;
        QDate					dDateEffet_;
        QDate					dDateMiseAJour_;
        bool					bAccordEntreAssocies_;
        uint					uDureeAccord_;
  };

  /*
   * CFraisGeneraux
   * General outgoing
   */
  class CFraisGeneraux
  {
    public:
        // Constructor
        CFraisGeneraux()
        {
            uCouvertureMensuelle_ = 0;
            uFranchiseFraisGeneraux_ = 0;
            pCompagnie_ = 0;
        };
        // Destructor
        ~CFraisGeneraux() {};

    public:
        // CDatas virtual functions
        virtual int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
        virtual int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

        // Graphical functions
        virtual void loadInQT( dlgAmonSoft & ) const;
        virtual void copyFromQT( const dlgAmonSoft & );

    private:
        uint                    uCouvertureMensuelle_;
        uint                    uFranchiseFraisGeneraux_;
        QDate                   dDuree_;
        struct Preferences::SCompagnie *pCompagnie_;
        QString                 sContrat_;
        QString                 sNotes_;
  };

  /*
   * CInvalidite
   * 
   */

  class CInvalidite
  {
    public:
        // Constructor
        CInvalidite()
        {
            uMontantRenteInvalidite100_ = 0;
            uMontantRenteInvalidite66_ = 0;
            uMontantRenteInvalidite33_ = 0;
            bProfessionnelle_ = true;
            uCapitauxInvalidite60_ = 0;
            pCompagnie_ = 0;
        };
        // Destructor
        ~CInvalidite() {};

    public:
        // CDatas virtual functions
        virtual int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
        virtual int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

        // Graphical functions
        virtual void loadInQT( dlgAmonSoft & ) const;
        virtual void copyFromQT( const dlgAmonSoft & );

    private:
        uint                    uMontantRenteInvalidite100_;
        uint                    uMontantRenteInvalidite66_;
        uint                    uMontantRenteInvalidite33_;
        bool                    bProfessionnelle_;
        enum eTypeFiscalite     eFiscalite_;
        struct Preferences::SCompagnie *pCompagnie_;
        QDate                   dDateEffet_;
        QDate                   dDateMiseAJour_;
        uint                    uCapitauxInvalidite60_;
        QString                 sNotes_;
  };

  /*
   * CDeces
   * Death
   */
  class CDeces
  {
    public:
        // Constructor
        CDeces()
        {
            uRenteConjoint_ = 0;
            uDureeRenteConjoint_ = 0;
            pCompagnieConjoint_ = 0;
            pCompagnieEducation_ = 0;
            listRentesEducation_.empty();
            listGarantiesDeces_.empty();

        };
        // Destructor
        ~CDeces() {};

    public:
        // CDatas virtual functions
        virtual int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
        virtual int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

        // Graphical functions
        virtual void loadInQT( dlgAmonSoft & ) const;
        virtual void copyFromQT( const dlgAmonSoft & );

    public:
        t_listGarantieDeces     listGarantiesDeces_;
        
    private:
        // Conjoint (TODO: Translate)
        uint                    uRenteConjoint_;
        enum eTypeFiscalite     eFiscaliteConjoint_;
        uint                    uDureeRenteConjoint_;
        struct Preferences::SCompagnie *pCompagnieConjoint_;
        QDate                   dDateEffetConjoint_;
        QString                 sNotes_;

    public:
        t_listRenteEducation   listRentesEducation_;

    private:
        // Education        
        struct Preferences::SCompagnie *pCompagnieEducation_;
        enum eTypeFiscalite     eFiscaliteEducation_;
        QDate                   dDateEffetEducation_;
  };

  /*
   * CPrevoyance
   * Social warranty
   */
  class CPrevoyance
  {
    enum eTypeBeneficaires
    {
        eIsole,
        eIsoleParents,
        eFamille
    };

    public:
        // Constructor
        CPrevoyance();
        // Destructor
        ~CPrevoyance();

    public:
        // CDatas virtual functions
        virtual int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
        virtual int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

        // Graphical functions
        virtual void loadInQT( dlgAmonSoft & ) const;
        virtual void copyFromQT( const dlgAmonSoft & );

        CArretMaladie   *getArretMaladie() { return &ArretMaladie_; }
        CDeces          *getDeces() { return &Deces_; }

        bool          hasGaranties() const { return !sNiveauGaranties_.isEmpty() && sNiveauGaranties_.toUInt() != 0 ; }

    private:
        QString                 sNiveauGaranties_;
        QDate                   dDateEffet_;
        uint                    uCotisationAnnuelle_;
        uint                    uIndiceSatisfaction_;
        enum eTypeBeneficaires  eBeneficiaires_;
        bool                    bViager_;
        enum t_TypeViager {
            ePersonnel,
            eProfessionnel,
            ePasEnViager
        }                       eTypeViager_;
        QString                 sFiscalite_;
        struct Preferences::SCompagnie *pCompagnie_;
        QString                 sContrat_;
        enum SanteSource {
            Amon,
            Concurrence }       eSanteSource_;
        QString                 sNotes_;
      
    public:
        t_listEmprunts   listCouvertureEmprunts_;

    private:
        CArretMaladie           ArretMaladie_;
        CFraisGeneraux          FraisGeneraux_;
        CInvalidite             Invalidite_;        
        CDeces                  Deces_;
  };
}

#endif /* _CPREVOYANCE_H_ */