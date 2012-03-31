/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CEntreprise.h,v 1.13 2007/02/06 19:04:45 pascal Exp $
* $Log: CEntreprise.h,v $
* Revision 1.13  2007/02/06 19:04:45  pascal
* - Début nouvelles Forms dans l'interface entreprise
* - Modification date validité
* - Ajout nouveaux fichiers pour les nouvelles Forms, il reste les liens Dynamique a créer
*
* Revision 1.12  2006/11/09 13:39:48  pascal
* Version 0.2.6
* Nouvelles fonctionnalités
*
* - Les resets ainsi que les sauvegardes des fichiers ont été vérifiés et aucune donnée n'est perdue.
*
* - Les exportations des personnes a été revue et est désormais plus jolie et plus compréhensible. Dans la prochaine version nous ajouterons la même méthode pour l'exportation des familles et des entreprises.
*
* Correction de bugs
*
* - Désormais, il est possible de mettre des nombres réels dans les pourcentages. Plus généralement, cette version n'utilise plus les masques de saisies. C'est à cause d'eux, que l'on pouvait avoir le curseur au milieu d'une saisie, ce qui était gênant.
*
* Il est important de faire attention à mettre des nombres dans les champs où l'on attend des nombres. Ces vérifications sont en cours d'être mise en place sous une autre forme et seront ré-activées dans la prochaine version.
*
* - Les problèmes liés à la suppression d'une personne ont été corrigés
* - Les informations concernant l'ISF n'étaient pas sauvegardées, c'est corrigé.
*
* Roadmap
*
* - Fin novembre
*  + Validation de la cohérence des données lors de la validation
*  + Correction de bugs divers restants
*  + Connexion pour les fiches entses.
*  + Cryptage des fichiers de données XML
*
* - Fin décembre
*   + Amélioration du système de mise à jour
*   + Modification dans la gestion des listes d'épargne, d'enfants, de revenus, des charges, etc.
*
* Pour information version active jusqu'au 30 décembre 2006.
*
* Revision 1.11  2006/06/21 11:23:23  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.10  2006/05/23 16:06:39  pascal
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
* Revision 1.9  2006/04/29 16:29:28  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.8  2006/04/16 22:11:30  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.7  2006/03/21 10:42:16  pascal
* *** empty log message ***
*
* Revision 1.6  2005/12/20 19:14:46  pascal
* - liste des prospects màj
* - modification du conjoint prises en compte
*
* Revision 1.5  2005/11/30 18:16:48  pascal
* - améliorations des chargements / enregistrements XML
* - CFamille peut désormais être sauvegarder dans un fichier
* - Correction de bugs pour l'XML des entses
*
* Revision 1.4  2005/11/12 15:04:55  pascal
* Mise à niveau ...
*
* Revision 1.3  2005/10/26 10:11:07  pascal
* - CEntreprise : saveToXML réalisé
* - retouches divers
*
* Revision 1.2  2005/10/11 22:53:57  pascal
* - CPersonnes peut lire depuis le XML ses données
* - CConseillers aussi
* - CEpargnes en cours !
*
* Revision 1.1  2005/10/11 08:12:17  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
*
*/

#ifndef _CENTREPRISE_H_
# define _CENTREPRISE_H_

#include <qlistview.h>
#include <qdatetime.h>
#include <list>

#include "defines.h"
#include "Datas/CRevenus.h"
#include "CDatas.h"
#include "Preferences/CPreferences.h"

namespace Datas
{
    typedef enum
    {
        eSARL,
        eSA,
        eSAS,
        eEURL,
        eSCP,
        eAutreStatus
    }                   t_eStatusEntreprise;

    typedef enum
    {
        eGerantMajoritaire,
        eGerantMinoritaire,
        eGerantAssocie,
        eGerantInconnu
    }                   t_ePartsGerant;

    typedef struct      s_PersonneGerant
    {
        const CPersonnes *pPersonne_;
        t_ePartsGerant  ePart_;
    }                   t_PersonneGerant;

    struct SRetraite
    {
        QString     sContrat_;
        QDate       dEffet_;
        struct Preferences::SCompagnie *pCompagnie_;
        QString     sCollegue_;
        ushort      usTA_;
        ushort      usTB_;
        ushort      usTC_;
        ushort      usFisc82_;
        ushort      usFisc82AD_;
        ushort      usFisc82SD_;
        ushort      usFisc39_;
    };

    typedef std::list< SRetraite* >         t_listRetraites;

    struct SCapitalDeces
    {
        enum eStatutPro eTypeSalarie_;
        QString         sContrat_;
        struct Preferences::SCompagnie *pCompagnie_;
        ushort          usCDV_;
        ushort          usTA_;
        ushort          usTB_;
        ushort          usTC_;
        ushort          usM_;
        ushort          usMaj_;
        uint            uRenteConjoint_;
        uint            uRenteEdu_;
    };

    typedef std::list< SCapitalDeces* >         t_listCapitalDeces;

    struct SIJournaliere
    {
        enum eStatutPro  eTypeSalarie_;
        QString         sContrat_;
        struct Preferences::SCompagnie *pCompagnie_;
        ushort          usTA_;
        ushort          usTB_;
        ushort          usTC_;
        ushort          usIJMontant_;
        uint            uIJReduite_;
        uint            uIJFranchise_;
        ushort          usInvMontant_;
        uint            uInvPartielle_;
    };

    typedef std::list< SIJournaliere* >         t_listIJournaliere;

    /*
     * CSalarie
     * Employees
     */
    class CSalarie
    {
    public:
        // Constructor
        CSalarie();
        // Destructor
        ~CSalarie();

    public:
        // CDatas virtual functions
        int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
        int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

        // Graphical functions
        virtual void loadInQT( dlgAmonSoft & ) const;
        virtual void copyFromQT( const dlgAmonSoft & );

    private:
        ushort                  usNbCadres_;
        ushort                  usNbETAM_;
        ushort                  usNbNonCadres_;
        ushort                  usNbAutre_;
        bool                    bDeleguePersonnel_;
        bool                    bComiteEntreprise_;
        bool                    bInteressement_;
        QString                 sInteressement_;
        ushort                  usARRCOPS_;
        ushort                  usARRCOPP_;
        ushort                  usAGIRCPS_;
        ushort                  usAGIRCPP_;
        ushort                  usAutresPS_;
        ushort                  usAutresPP_;
        ushort                  usCongesPayes_;
        ushort                  usTauxAccident_;
        uint                    uTaxeTransports_;

    };

    static ushort usLastIdEntses;

    /*
     * CEntreprise
     * Describe entreprise
     */
    class CEntreprise : public CDatas
    {
        public:
            // Constructor
            CEntreprise( bool bEmpty = false );
            // Destructor
            ~CEntreprise();

        public:
            // CDatas virtual functions
            int loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode );
            int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const;

            // Graphical functions
            virtual void loadInQT( dlgAmonSoft & ) const;
            virtual void copyFromQT( const dlgAmonSoft & );

            // Access var
            QString     getRaisonSociale() const
            { return sRaisonSociale_; }
            QString     getNumeroSiret() const
            { return sNumSiret_; }
            ushort      getID() const
            { return usId_; }

        private:
            ushort                  usId_;
            QString                 sRaisonSociale_;
            t_eStatusEntreprise     eSatus_;
            QString                 sAutre_;
            t_Adresse               Adresse_;
            QString                 sCodeNAF_;
            QString                 sNumSiret_;
            QString                 sActivite_;
            QString                 sConvention_;
            bool                    bAGA_;
            bool                    bCGA_;
            ushort                  usCollegueGerance_;
            ushort                  usProche_;
            ushort                  usAutre_;
            uint                    uBeneficesN1_;
            uint                    uBeneficesN2_;
            enum
            {
                eImpotSociete,
                eImpotRevenus
            }                       eRegimeFiscale_;
            QString                 sDateCreation_;
            bool                    bSuiteEconomique_;
            QString                 sTelephone_;
            QString                 sFax_;
            QString                 sSiteInternet_;
            QString                 sPEEOrganisme_;
            QDate                   dPEEDate_;
            bool                    bInteressement_;
            uint                    uVersementN1_;
            uint                    uVersementN2_;

        private:
            CSalarie                Salarie_;

        public:
            t_listRetraites     listRetraites_;
            t_listCapitalDeces  listCapitalDeces_;
            t_listIJournaliere  listIJournaliere_;

        //
        // Manage boss and emploiement
        //
        private:
            std::list< const CPersonnes * >         listEmployes_;
            std::list< t_PersonneGerant * >         listGerants_;

            void saveEmployesToXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode ) const;
            void loadEmployesFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode );
            void saveGerantsToXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode ) const;
            void loadGerantsFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode );

        public:
            int addEmploye( const CPersonnes & );
            int addGerant( const CPersonnes &, t_ePartsGerant );
            void removeEmploye( ushort );
            void removeGerant( ushort );
            void removeEmploye( CPersonnes * );
            void removeGerant( CPersonnes * );

        private:
            void loadEmployesInListView( QListView * ) const;
            void loadGerantsInListView( QListView * ) const;
    };
}

#endif /* _CENTREPRISE_H_ */