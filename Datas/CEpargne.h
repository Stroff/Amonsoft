/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CEpargne.h,v 1.10 2006/04/29 16:29:28 pascal Exp $
* $Log: CEpargne.h,v $
* Revision 1.10  2006/04/29 16:29:28  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.9  2006/04/21 00:08:16  pascal
* Version 0.1.12
*
* - correction du problème liée au reset des listes dynamique.
* - CPersonne ne crée par forcémment un CFamille (à surveiller !)
* - nouvelle image pour les prospects
* - correction bugs mineurs
*
* Revision 1.8  2006/03/21 10:42:16  pascal
* *** empty log message ***
*
* Revision 1.7  2006/01/20 13:18:44  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.6  2005/11/12 15:04:55  pascal
* Mise à niveau ...
*
* Revision 1.5  2005/10/14 08:41:11  pascal
* - correction d'un bogue lors de la lecture du fichier XML : Un élément vide était ajouté
*
* Revision 1.4  2005/10/12 16:11:21  pascal
* - implementation des fonctions loadFromXerces des classes CPersonnes *
* - bug: ajout de CPrevoyance dans CPersonnes
*
* Revision 1.3  2005/10/11 22:53:57  pascal
* - CPersonnes peut lire depuis le XML ses données
* - CConseillers aussi
* - CEpargnes en cours !
*
* Revision 1.2  2005/10/11 08:12:16  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
* Revision 1.1  2005/10/05 17:14:23  pascal
* - nouvelle structure de données pour stocker les informations sur l'épargne
* - résolution du problème lié à l'épouse : méthodes surchargées avec un bool supplémentaire permettant de savoir à qui l'on a à faire dans CPersonne et dans CRevenus.
* - loadInQT implémenté pour toutes les classes
*
*
*/

#ifndef _CEPARGNE_H_
# define _CEPARGNE_H_

// QT
#include <qdatetime.h>

// STL
#include <list>

#include "defines.h"
#include "CDatas.h"
#include "Preferences/CPreferences.h"

namespace Datas
{
    typedef enum 
    {
        eLoiMadelin,
        eArt83,
        eArt82,
        ePerp,
        ePerco,
        eArt39,
        eIFC,
        eAutreRetraite
    }                                               t_eTypeEpargne;

    struct SEpargne {
        t_eTypeEpargne          eType_;
        QDate                   dEffet_;
        uint                    uInvAnnuel_;
        uint                    uEpargne_;
        QDate                   dEpargne_;
        QString                 sContrat_;
        struct Preferences::SCompagnie *pCompagnie_;
    };

    typedef std::list< struct Datas::SEpargne* >    t_listEpargnes;

    struct SAssuranceVie
    {
        QString                 sContrat_;
        struct Preferences::SCompagnie *pCompagnie_;
        QDate                   dEffet_;
        uint                    uInvAnnuel_;
        QString                 sTerme_;
        uint                    uCapital_;
        QDate                   dCapital_;
        uint                    uDSK_;
        uint                    uPEP_;
        uint                    uMS_;
        uint                    uFD_;
    };

    typedef std::list< struct Datas::SAssuranceVie* >   t_listAssurancesVie;

    typedef enum
    {
        eCodevi,
        ePEL,
        eCEL,
        eSICAV,
        eObligations,
        eActions,
        ePEA,
        ePEP,
        eOPCVM
    }                                                   t_eTypeCompte;

    struct SComptes
    {
        t_eTypeCompte           eType_;
        struct Preferences::SCompagnie *pCompagnie_;
        QDate                   dEffet_;
        uint                    uInvAnnuel_;
        QString                 sTerme_;
        uint                    uCapital_;
        QDate                   dCapital_;
        ushort                  usRendement_;
        QString                 sNotes_;
    };

    typedef std::list< struct Datas::SComptes* >       t_listComptes;

    struct SRevenus
    {
        QString                 sDesignation_;
        uint                    uMontant_;
    };

    typedef std::list< struct Datas::SRevenus* >       t_listRevenus;
    typedef std::list< struct Datas::SRevenus* >       t_listCharges;

    class CEpargnes
    {
        enum eTypeMotivations
        {
            eFiscalite,
            eDisponibilite,
            eSecurite,
            eRentabilite
        };

        public:
            // Constructor
            CEpargnes() 
            { 
                uSensibilite_ = 0;
                listEpargnes_.empty();
                listAssurancesVie_.empty();
                listComptes_.empty();
                listRevenus_.empty();
                listCharges_.empty();
            
            }
            // Destructor
            ~CEpargnes() {}

        public:
            // CDatas virtual functions
            int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
            int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

            // Graphical functions
            virtual void loadInQT( dlgAmonSoft & ) const;
            virtual void copyFromQT( const dlgAmonSoft & );

            void setSensibilite( uint val ) { uSensibilite_ = val; }

        public:
            static QString typeEpargneToString( t_eTypeEpargne type );
            static QString typeCompteToString( t_eTypeCompte type );

        public:
            t_listEpargnes                  listEpargnes_;
            t_listAssurancesVie             listAssurancesVie_;
            t_listComptes                   listComptes_;
            t_listRevenus                   listRevenus_;
            t_listCharges                   listCharges_;

        private:
            uint                            uSensibilite_;
            enum eTypeMotivations           eMotivation1_;
            enum eTypeMotivations           eMotivation2_;
            enum eTypeMotivations           eMotivation3_;
            enum eTypeMotivations           eMotivation4_;

        private:
            // XML sub functions
            void getXMLListRetraites( XERCES_CPP_NAMESPACE::DOMNode *ptNode );
            void getXMLListMotivations( XERCES_CPP_NAMESPACE::DOMNode *ptNode );
            void getXMLListAssuranceVies( XERCES_CPP_NAMESPACE::DOMNode *ptNode );
            void getXMLListComptes( XERCES_CPP_NAMESPACE::DOMNode *ptNode );
            void getXMLListRevenus( XERCES_CPP_NAMESPACE::DOMNode *ptNode );
            void getXMLListCharges( XERCES_CPP_NAMESPACE::DOMNode *ptNode );
    };
}

#endif /* _CEPARGNE_H_ */