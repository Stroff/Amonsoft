/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CRevenus.cpp,v 1.15 2006/11/10 10:48:07 pascal Exp $
* $Log: CRevenus.cpp,v $
* Revision 1.15  2006/11/10 10:48:07  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
* Revision 1.14  2006/10/13 14:39:46  pascal
* Version 0.2.5
*
* Nouvelles fonctionnalités
*
* - Système de CrashReport complet: Génération d'un fichier de dump (.dmp) lorsque le programme plante. Tentative de sauvegarde des fichiers lors d'un plantage.
*
* - MoisBilan est désormais une liste déroulante.
*
* - Plus de masque de saisie, ce qui implique plus de vérification au niveau des types de données saisies. Cela corrige les problèmes liés au curseur au milieu de la case ou encore l'impossibilité d'avoir des pourcentages utilisant des nombres réels.
*
* - Le terme bénéficiaire a été remplacé par client.
*
* Correction de bugs
*
* - Il n'y a plus de bugs lorsqu'on supprime une personne employée dans une entreprise.
*
* Roadmap
*
* - Fin octobre
*  + Tests de cohérences
*  + Mise en forme des exportations.
*  + Connexion pour les fiches entses.
*
* - Fin novembre
*  + Cryptage des fichiers de données XML
*  + Amélioration du système de mise à jour
*  + Modification dans la gestion des listes d'épargne, d'enfants, de revenus, des charges, etc.
*
* La version expire le 30/11/2006
*
* Revision 1.13  2006/10/12 11:29:46  pascal
* - Suppression des inpputs Masks
* - Bénéficiaire s'appel désormais client
* - Mois bilan utilise une comboBox
*
* Revision 1.12  2006/01/20 13:18:45  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.11  2005/12/27 10:28:05  pascal
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
* Revision 1.10  2005/11/12 15:04:56  pascal
* Mise à niveau ...
*
* Revision 1.9  2005/10/14 08:41:11  pascal
* - correction d'un bogue lors de la lecture du fichier XML : Un élément vide était ajouté
*
* Revision 1.8  2005/10/13 15:53:34  pascal
* - petites modifications
*
* Revision 1.7  2005/10/12 16:11:21  pascal
* - implementation des fonctions loadFromXerces des classes CPersonnes *
* - bug: ajout de CPrevoyance dans CPersonnes
*
* Revision 1.6  2005/10/11 08:12:17  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
* Revision 1.5  2005/10/05 17:14:23  pascal
* - nouvelle structure de données pour stocker les informations sur l'épargne
* - résolution du problème lié à l'épouse : méthodes surchargées avec un bool supplémentaire permettant de savoir à qui l'on a à faire dans CPersonne et dans CRevenus.
* - loadInQT implémenté pour toutes les classes
*
* Revision 1.4  2005/09/29 15:51:28  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.3  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
*
* Revision 1.2  2005/09/09 15:49:38  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
*
*/

#include <qlineedit.h>
#include <qcombobox.h>

#include <string.h>

#include "CRevenus.h"

using namespace Datas;

//-----------------------------------------------------------------------------
// CRevenus constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CRevenus::CRevenus()
{
    uBNC_ = 0;
    uBIC_ = 0;
    uRevenusFonciers_ = 0;
    uDividendes_ = 0;
    uAutres_ = 0;
    SalaireAnnuel_.uSalaire = 0;
}

//-----------------------------------------------------------------------------
// CRevenus destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CRevenus::~CRevenus()
{
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CRevenus::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try
    {
        qDebug( XMLString::transcode( xmlNode->getNodeName() ) );
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Revenus" ) )
            return 0;

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            pt = CParser::getTextNode( ptNode, "SalaireAnnuel" );
            if( pt != 0 )
            {
                SalaireAnnuel_.uSalaire = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "TypeSalaire" );
            if( pt != 0 )
            {
                if( strcmp( pt, "net" ) == 0 )
                    SalaireAnnuel_.tTypeRevenus = eRevenusNet;
                else
                    SalaireAnnuel_.tTypeRevenus = eRevenusBrut;
                continue ;
            }
            
            pt = CParser::getTextNode( ptNode, "AutresRevenus" );
            if( pt != 0 )
            {
                uAutres_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "BIC" );
            if( pt != 0 )
            {
                uBIC_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "BNC" );
            if( pt != 0 )
            {
                uBNC_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Dividendes" );
            if( pt != 0 )
            {
                uDividendes_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "RevenusFonciers" );
            if( pt != 0 )
            {
                uRevenusFonciers_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "StatusPro" );
            if( pt != 0 )
            {
                sStatutPro_ = (enum eStatutPro) XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "MoisBilan" );
            if( pt != 0 )
            {
                try {
                    eMoisBilan_ = (enum eMoisBilan) XMLString::parseInt( XMLString::transcode( pt ) );
                }
                catch(...)
                { eMoisBilan_ = eJanvier; }
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Employeur" );
            if( pt != 0 )
            {
                sEmployeur_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Fonction" );
            if( pt != 0 )
            {
                sFonction_ = pt;
                continue ;
            }
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 1;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CRevenus::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

		try{
			QString string;

			DOMElement *pElem = CParser::createElementNode( xmlNode, "Revenus", node );

			CParser::createTextNode( xmlNode, "SalaireAnnuel", string.setNum( SalaireAnnuel_.uSalaire ), pElem );
			CParser::createTextNode( xmlNode, "TypeSalaire", SalaireAnnuel_.tTypeRevenus == eRevenusNet ? "net" :  "brut", pElem );
			CParser::createTextNode( xmlNode, "AutresRevenus", string.setNum( uAutres_ ), pElem );
			CParser::createTextNode( xmlNode, "BIC", string.setNum( uBIC_ ), pElem );
			CParser::createTextNode( xmlNode, "BNC", string.setNum( uBNC_ ), pElem );
			CParser::createTextNode( xmlNode, "Dividendes", string.setNum( uDividendes_ ), pElem );
			CParser::createTextNode( xmlNode, "RevenusFonciers", string.setNum( uRevenusFonciers_ ), pElem );
            CParser::createTextNode( xmlNode, "StatusPro", string.setNum( sStatutPro_ ), pElem );
            CParser::createTextNode( xmlNode, "MoisBilan", string.setNum( eMoisBilan_ ), pElem );
            CParser::createTextNode( xmlNode, "Employeur", sEmployeur_, pElem );
            CParser::createTextNode( xmlNode, "Fonction", sFonction_, pElem );
		}
		catch( DOMException &e )
		{
			qDebug( XMLString::transcode( e.getMessage() ) );
		}
		return 0;
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CRevenus::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.lineEditCarriereSalaireAnnuel->setText( string.setNum( SalaireAnnuel_.uSalaire ) );
    amon.comboBoxCarriereNetBrut->setCurrentItem( SalaireAnnuel_.tTypeRevenus == eRevenusNet ? 0 : 1 );
    amon.lineEditCarriereAutresRevenus->setText( string.setNum( uAutres_ ) );
    amon.lineEditCarriereBIC->setText( string.setNum( uBIC_ ) );
    amon.lineEditCarriereBNC->setText( string.setNum( uBNC_ ) );
    amon.lineEditCarriereDividendes->setText( string.setNum( uDividendes_ ) );
    amon.lineEditCarriereRevenusFonciers->setText( string.setNum( uRevenusFonciers_ ) );
    amon.comboBoxStatutPro->setCurrentItem( sStatutPro_ );
    amon.comboBoxRevenusMoisBilan->setCurrentItem( eMoisBilan_ );
    amon.lineEditRevenusEmployeur->setText( sEmployeur_ );
    amon.lineEditRevenusFonction->setText( sFonction_ );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CRevenus::copyFromQT( const dlgAmonSoft &amon )
{
    SalaireAnnuel_.uSalaire         = get_uint_from_qlineedit( amon.lineEditCarriereSalaireAnnuel );
    SalaireAnnuel_.tTypeRevenus     = ( amon.comboBoxCarriereNetBrut->currentItem () == 0 ?
                                             eRevenusNet : eRevenusBrut );
    uAutres_                        = get_uint_from_qlineedit( amon.lineEditCarriereAutresRevenus );
    uBIC_                           = get_uint_from_qlineedit( amon.lineEditCarriereBIC );
    uBNC_                           = get_uint_from_qlineedit( amon.lineEditCarriereBNC );
    uDividendes_                    = get_uint_from_qlineedit( amon.lineEditCarriereDividendes );
    uRevenusFonciers_               = get_uint_from_qlineedit( amon.lineEditCarriereRevenusFonciers );
    sStatutPro_                     = (enum eStatutPro) amon.comboBoxStatutPro->currentItem();
    eMoisBilan_                     = (enum eMoisBilan) amon.comboBoxRevenusMoisBilan->currentItem();
    sEmployeur_                     = amon.lineEditRevenusEmployeur->text();
    sFonction_                      = amon.lineEditRevenusFonction->text();
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CRevenus::loadInQT( dlgAmonSoft &amon, bool bFriend ) const
{
    if( !bFriend )
    {
        loadInQT( amon );
        return ;
    }

    QString string;

    amon.lineEditFamilleSalaireAnnuel->setText( string.setNum( SalaireAnnuel_.uSalaire ) );
    amon.comboBoxFamilleNetBrut->setCurrentItem( SalaireAnnuel_.tTypeRevenus == eRevenusNet ? 0 : 1 );
    amon.lineEditFamilleAutresRevenus->setText( string.setNum( uAutres_ ) );
    amon.lineEditFamilleBIC->setText( string.setNum( uBIC_ ) );
    amon.lineEditFamilleBNC->setText( string.setNum( uBNC_ ) );
    amon.lineEditFamilleDividendes->setText( string.setNum( uDividendes_ ) );
    amon.lineEditFamilleRevenusFonciers->setText( string.setNum( uRevenusFonciers_ ) );    
}
/* TODO: Delete
//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CRevenus::copyFromQT( const dlgAmonSoft &amon, bool bFriend )
{
    if( !bFriend )
    {
        copyFromQT( amon );
        return ;
    }

    SalaireAnnuel_.uSalaire         = get_uint_from_qlineedit( amon.lineEditFamilleSalaireAnnuel );
    SalaireAnnuel_.tTypeRevenus     = ( amon.comboBoxFamilleNetBrut->currentItem () == 0 ?
                                            eRevenusNet : eRevenusBrut );
    uAutres_                        = get_uint_from_qlineedit( amon.lineEditFamilleAutresRevenus );
    uBIC_                           = get_uint_from_qlineedit( amon.lineEditFamilleBIC );
    uBNC_                           = get_uint_from_qlineedit( amon.lineEditFamilleBNC );
    uDividendes_                    = get_uint_from_qlineedit( amon.lineEditFamilleDividendes );
    uRevenusFonciers_               = get_uint_from_qlineedit( amon.lineEditFamilleRevenusFonciers );
}*/