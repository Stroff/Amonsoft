/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CEpargne.cpp,v 1.13 2006/06/21 11:23:23 pascal Exp $
* $Log: CEpargne.cpp,v $
* Revision 1.13  2006/06/21 11:23:23  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.12  2006/05/12 16:22:43  pascal
* Version 0.1 build 14
* - Le fond de la form principale passe au bleu
* - [BUG] : Problème avec le chargement des dates depuis l'XML : Les dates sont désormais au format ISO
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
* Revision 1.10  2006/03/21 10:42:16  pascal
* *** empty log message ***
*
* Revision 1.9  2006/01/20 13:18:44  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.8  2005/12/27 10:28:04  pascal
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
* Revision 1.7  2005/11/30 18:16:48  pascal
* - améliorations des chargements / enregistrements XML
* - CFamille peut désormais être sauvegarder dans un fichier
* - Correction de bugs pour l'XML des entses
*
* Revision 1.6  2005/10/14 08:41:11  pascal
* - correction d'un bogue lors de la lecture du fichier XML : Un élément vide était ajouté
*
* Revision 1.5  2005/10/12 22:57:07  pascal
* *** empty log message ***
*
* Revision 1.4  2005/10/12 16:11:20  pascal
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

// QT
#include <qslider.h> 
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qlistview.h>
#include <qlabel.h>
#include <qcombobox.h>

#include <iostream>
#include <string.h>

#include "CEpargne.h"
#include "main.h"

using namespace Datas;

//----------------------------------------------------------------------------
// Static members
//----------------------------------------------------------------------------


//=============================================================================
// CEpargne
//=============================================================================
//----------------------------------------------------------------------------
// static function to get list of SRetraites
//----------------------------------------------------------------------------
void CEpargnes::getXMLListRetraites( XERCES_CPP_NAMESPACE::DOMNode *ptNode )
{
    XERCES_CPP_NAMESPACE_USE

    if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Retraites" ) 
        && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
    {
        DOMNodeList *plistRetraite = ptNode->getChildNodes();

        XMLSize_t asize = plistRetraite->getLength();

        for( XMLSize_t i = 0; i < asize; i++ )
        {
            DOMNode *ptNodeRet = plistRetraite->item( i );

            if( XMLString::equals( XMLString::transcode( ptNodeRet->getNodeName() ), "Retraite" ) )
            {    
                struct SEpargne *ep = new struct SEpargne;
                listEpargnes_.push_back( ep );
                ep->pCompagnie_ = 0;

                ep->eType_ = (t_eTypeEpargne) CParser::getIntElementAttribute( ptNodeRet, "type" );
                DOMNodeList *plistEltRetraite = ptNodeRet->getChildNodes();

                XMLSize_t asize = plistEltRetraite->getLength();

                for( XMLSize_t idx = 0; idx < asize; idx++ )
                {
                    DOMNode *ptNodeRetElt = plistEltRetraite->item( idx );
                    const char *ptRetElt;

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "DateEffet" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->dEffet_ = QDate::fromString( ptRetElt, Qt::ISODate );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "InvAnnuel" );
                    if( ptRetElt != 0 )
                    {
                         XMLCh *ptt = XMLString::transcode( ptRetElt );
                        int itt = XMLString::parseInt( ptt );
                        ep->uInvAnnuel_ = itt;
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "MontantEpargne" );
                    if( ptRetElt != 0 )
                    {
                        ep->uEpargne_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "DateEpargne" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->dEpargne_ = QDate::fromString( ptRetElt, Qt::ISODate );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Contrat" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->sContrat_ = ptRetElt;
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Compagnie" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->pCompagnie_ = GET_COMP_FROM_TEXT( ptRetElt );
                        continue ;
                    }
                }
            }
        }
    }
}

//----------------------------------------------------------------------------
// Get list of Motivations from XML
//----------------------------------------------------------------------------
void CEpargnes::getXMLListMotivations( XERCES_CPP_NAMESPACE::DOMNode *ptNode )
{
    XERCES_CPP_NAMESPACE_USE

    if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Motivation" ) 
        && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
    {
        DOMNodeList *plistMotivation = ptNode->getChildNodes();

        XMLSize_t asize = plistMotivation->getLength();

        for( XMLSize_t i = 0; i < asize; i++ )
        {
            DOMNode *ptNodeMot = plistMotivation->item( i );
            const char *ptMot;

            ptMot = CParser::getTextNode( ptNodeMot, "Motivation1" );
            if( ptMot != 0 )
            {
                eMotivation1_ = (enum eTypeMotivations) XMLString::parseInt( XMLString::transcode( ptMot ) );
                continue ;
            }

            ptMot = CParser::getTextNode( ptNodeMot, "Motivation2" );
            if( ptMot != 0 )
            {
                eMotivation2_ = (enum eTypeMotivations) XMLString::parseInt( XMLString::transcode( ptMot ) );;
                continue ;
            }

            ptMot = CParser::getTextNode( ptNodeMot, "Motivation3" );
            if( ptMot != 0 )
            {
                eMotivation3_ = (enum eTypeMotivations) XMLString::parseInt( XMLString::transcode( ptMot ) );;
                continue ;
            }

            ptMot = CParser::getTextNode( ptNodeMot, "Motivation4" );
            if( ptMot != 0 )
            {
                eMotivation4_ = (enum eTypeMotivations)XMLString::parseInt( XMLString::transcode( ptMot ) );;
                continue ;
            }
        }
    }
}

//----------------------------------------------------------------------------
// Get list of Motivations from XML
//----------------------------------------------------------------------------
void CEpargnes::getXMLListAssuranceVies( XERCES_CPP_NAMESPACE::DOMNode *ptNode )
{
    XERCES_CPP_NAMESPACE_USE

    if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "AssuranceVies" ) 
        && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
    {
        DOMNodeList *plist = ptNode->getChildNodes();

        XMLSize_t asize = plist->getLength();

        for( XMLSize_t i = 0; i < asize; i++ )
        {
            DOMNode *ptNodeRet = plist->item( i );
            const char *ptRet;

            if( XMLString::equals( XMLString::transcode( ptNodeRet->getNodeName() ), "AssuranceVie" ) )
            {    
                struct SAssuranceVie *ep = new struct SAssuranceVie;
                ep->pCompagnie_ = 0;

                DOMNodeList *plistElt = ptNodeRet->getChildNodes();

                XMLSize_t asize = plistElt->getLength();

                for( XMLSize_t idx = 0; idx < asize; idx++ )
                {
                    DOMNode *ptNodeRetElt = plistElt->item( idx );
                    const char *ptRetElt;

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "DateEffet" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->dEffet_ = QDate::fromString( ptRetElt, Qt::ISODate );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Contrat" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->sContrat_ = ptRetElt;
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Compagnie" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->pCompagnie_ = GET_COMP_FROM_TEXT( ptRetElt );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "InvAnnuel" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uInvAnnuel_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Terme" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->sTerme_ = ptRetElt;
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Capital" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uCapital_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "DateCapital" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->dCapital_ = QDate::fromString( ptRetElt, Qt::ISODate );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "DSK" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uDSK_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "PEP" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uPEP_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "MS" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uMS_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "FD" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uFD_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }
                }
                listAssurancesVie_.push_back( ep );
            }
        }
    }
}

//----------------------------------------------------------------------------
// Get list of Motivations from XML
//----------------------------------------------------------------------------
void CEpargnes::getXMLListComptes( XERCES_CPP_NAMESPACE::DOMNode *ptNode )
{
    XERCES_CPP_NAMESPACE_USE    

    if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Comptes" ) 
        && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
    {
        DOMNodeList *plist = ptNode->getChildNodes();

        XMLSize_t asize = plist->getLength();

        for( XMLSize_t i = 0; i < asize; i++ )
        {
            DOMNode *ptNodeRet = plist->item( i );
            const char *ptRet;

            if( XMLString::equals( XMLString::transcode( ptNodeRet->getNodeName() ), "Compte" ) )
            {    
                struct SComptes *ep = new struct SComptes;

                ep->eType_ = (t_eTypeCompte) CParser::getIntElementAttribute( ptNodeRet, "type" );
                ep->pCompagnie_ = 0;
                DOMNodeList *plistElt = ptNodeRet->getChildNodes();

                XMLSize_t asize = plistElt->getLength();

                for( XMLSize_t idx = 0; idx < asize; idx++ )
                {
                    DOMNode *ptNodeRetElt = plistElt->item( idx );
                    const char *ptRetElt;

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "DateEffet" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->dEffet_ = QDate::fromString( ptRetElt, Qt::ISODate );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Compagnie" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->pCompagnie_ = GET_COMP_FROM_TEXT( ptRetElt );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "InvAnnuel" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uInvAnnuel_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Terme" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->sTerme_ = ptRetElt;
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Capital" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->uCapital_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "DateCapital" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->dCapital_ = QDate::fromString( ptRetElt, Qt::ISODate );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Rendement" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->usRendement_ = XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Notes" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->sNotes_ = ptRetElt;
                        continue ;
                    }
                }
                listComptes_.push_back( ep );
            }
        }
    }
}

//----------------------------------------------------------------------------
// Get list of Motivations from XML
//----------------------------------------------------------------------------
void CEpargnes::getXMLListRevenus( XERCES_CPP_NAMESPACE::DOMNode *ptNode )
{
    XERCES_CPP_NAMESPACE_USE    

    if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Revenus" ) 
        && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
    {
        DOMNodeList *plist = ptNode->getChildNodes();

        XMLSize_t asize = plist->getLength();

        for( XMLSize_t i = 0; i < asize; i++ )
        {
            DOMNode *ptNodeRet = plist->item( i );
            const char *ptRet;

            if( XMLString::equals( XMLString::transcode( ptNodeRet->getNodeName() ), "Revenu" ) )
            {    
                struct SRevenus *ep = new struct SRevenus;

                DOMElement *pNode = static_cast< DOMElement* > ( ptNodeRet );

                ep->sDesignation_ = XMLString::transcode( pNode->getAttribute( XMLString::transcode( "Designation" ) ) );
                ep->uMontant_ = XMLString::parseInt( pNode->getAttribute( XMLString::transcode( "Montant" ) ) );

                listRevenus_.push_back( ep );
            }
        }
    }
}

//----------------------------------------------------------------------------
// Get list of Charges from XML
//----------------------------------------------------------------------------
void CEpargnes::getXMLListCharges( XERCES_CPP_NAMESPACE::DOMNode *ptNode )
{
    XERCES_CPP_NAMESPACE_USE

    if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Charges" ) 
        && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
    {
        DOMNodeList *plist = ptNode->getChildNodes();

        XMLSize_t asize = plist->getLength();

        for( XMLSize_t i = 0; i < asize; i++ )
        {
            DOMNode *ptNodeRet = plist->item( i );
            const char *ptRet;

            if( XMLString::equals( XMLString::transcode( ptNodeRet->getNodeName() ), "Charge" ) )
            {    
                struct SRevenus *ep = new struct SRevenus;

                DOMElement *pNode = static_cast< DOMElement* > ( ptNodeRet );

                ep->sDesignation_ = XMLString::transcode( pNode->getAttribute( XMLString::transcode( "Designation" ) ) );
                ep->uMontant_ = XMLString::parseInt( pNode->getAttribute( XMLString::transcode( "Montant" ) ) );

                listCharges_.push_back( ep );
            }
        }
    }
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CEpargnes::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try{
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Epargne" ) )
            return 0;
    
        listEpargnes_.clear();
        listAssurancesVie_.clear();
        listCharges_.clear();
        listComptes_.clear();
        listRevenus_.clear();

        uSensibilite_ = CParser::getIntElementAttribute( xmlNode, "Sensibilite" );

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );

            getXMLListMotivations( ptNode );
            getXMLListRetraites( ptNode );
            getXMLListAssuranceVies( ptNode );
            getXMLListComptes( ptNode );
            getXMLListRevenus( ptNode );
            getXMLListCharges( ptNode );
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
int CEpargnes::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try {
		QString string;

		DOMElement *pElem = CParser::createElementNode( xmlNode, "Epargne", node, "Sensibilite", string.setNum( uSensibilite_ ) );

		DOMElement *pElemMotivation = CParser::createElementNode( xmlNode, "Motivation", pElem );
        CParser::createTextNode( xmlNode, "Motivation1", string.setNum( eMotivation1_ ), pElemMotivation );
		CParser::createTextNode( xmlNode, "Motivation2", string.setNum( eMotivation2_ ), pElemMotivation );
		CParser::createTextNode( xmlNode, "Motivation3", string.setNum( eMotivation3_ ), pElemMotivation );
		CParser::createTextNode( xmlNode, "Motivation4", string.setNum( eMotivation4_ ), pElemMotivation );

		DOMElement *pElemSav = CParser::createElementNode( xmlNode, "Retraites", pElem );

		// Load list of saving
		{  
			t_listEpargnes::const_iterator ite;
			for( ite = listEpargnes_.begin(); ite != listEpargnes_.end(); ite++ )
			{
				QString string;

				DOMElement *pRet = CParser::createElementNode( xmlNode, "Retraite", pElemSav, "type", string.setNum( (*ite)->eType_ )  );
				CParser::createTextNode( xmlNode, "DateEffet", (*ite)->dEffet_.toString( Qt::ISODate ), pRet );
				CParser::createTextNode( xmlNode, "InvAnnuel", string.setNum( (*ite)->uInvAnnuel_ ), pRet );
				CParser::createTextNode( xmlNode, "MontantEpargne", string.setNum( (*ite)->uEpargne_ ), pRet );
				CParser::createTextNode( xmlNode, "DateEpargne", (*ite)->dEpargne_.toString( Qt::ISODate ), pRet );
				CParser::createTextNode( xmlNode, "Contrat", (*ite)->sContrat_, pRet );
				CParser::createTextNode( xmlNode, "Compagnie", (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "", pRet );
			}
		}

		DOMElement *pElemAssV = CParser::createElementNode( xmlNode, "AssuranceVies", pElem );

		// Load list of life assurance
		{      
			t_listAssurancesVie::const_iterator ite;
			for( ite = listAssurancesVie_.begin(); ite != listAssurancesVie_.end(); ite++ )
			{
				QString string;

				DOMElement *pAssV = CParser::createElementNode( xmlNode, "AssuranceVie", pElemAssV );

				CParser::createTextNode( xmlNode, "Contrat", (*ite)->sContrat_, pAssV );
				CParser::createTextNode( xmlNode, "Compagnie", (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "", pAssV );
				CParser::createTextNode( xmlNode, "DateEffet", (*ite)->dEffet_.toString( Qt::ISODate ), pAssV );
				CParser::createTextNode( xmlNode, "InvAnnuel", string.setNum( (*ite)->uInvAnnuel_ ), pAssV );
				CParser::createTextNode( xmlNode, "Terme", (*ite)->sTerme_, pAssV );
				CParser::createTextNode( xmlNode, "Capital", string.setNum( (*ite)->uCapital_ ), pAssV );
				CParser::createTextNode( xmlNode, "DateCapital", (*ite)->dCapital_.toString( Qt::ISODate ), pAssV );
				CParser::createTextNode( xmlNode, "DSK", string.setNum( (*ite)->uDSK_ ), pAssV );
				CParser::createTextNode( xmlNode, "PEP", string.setNum( (*ite)->uPEP_ ), pAssV );
				CParser::createTextNode( xmlNode, "MS", string.setNum( (*ite)->uMS_ ), pAssV );
				CParser::createTextNode( xmlNode, "FD", string.setNum( (*ite)->uFD_ ), pAssV );
			}
		}

		DOMElement *pElemCompte = CParser::createElementNode( xmlNode, "Comptes", pElem );

		// Load list of compte
		{
			t_listComptes::const_iterator ite;
			for( ite = listComptes_.begin(); ite != listComptes_.end(); ite++ )
			{
				QString string;

				DOMElement *pElemCom = CParser::createElementNode( xmlNode,
					"Compte", pElemCompte, "type", string.setNum( (*ite)->eType_ ) );
				
				CParser::createTextNode( xmlNode, "Compagnie", (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "", pElemCom );
				CParser::createTextNode( xmlNode, "DateEffet", (*ite)->dEffet_.toString( Qt::ISODate ), pElemCom );
				CParser::createTextNode( xmlNode, "InvAnnuel", string.setNum( (*ite)->uInvAnnuel_ ), pElemCom );
				CParser::createTextNode( xmlNode, "Terme", (*ite)->sTerme_, pElemCom );
				CParser::createTextNode( xmlNode, "Capital", string.setNum( (*ite)->uCapital_ ), pElemCom );
				CParser::createTextNode( xmlNode, "DateCapital", (*ite)->dCapital_.toString( Qt::ISODate ), pElemCom );
				CParser::createTextNode( xmlNode, "Rendement", string.setNum( (*ite)->usRendement_ ), pElemCom );
				CParser::createTextNode( xmlNode, "Notes", (*ite)->sNotes_, pElemCom );
			}
		}

		DOMElement *pElemRev = CParser::createElementNode( xmlNode, "Revenus", pElem );

		// Load list of incoming
		{
			t_listRevenus::const_iterator ite;
			for( ite = listRevenus_.begin(); ite != listRevenus_.end(); ite++ )
			{
				QString string;
				DOMElement *pRev = xmlNode->createElement( XMLString::transcode( "Revenu" ) );
				pRev->setAttribute( XMLString::transcode( "Designation" ), XMLString::transcode( (*ite)->sDesignation_ ) );
				pRev->setAttribute( XMLString::transcode( "Montant" ), XMLString::transcode( string.setNum( (*ite)->uMontant_ ) ) );
				pElemRev->appendChild( pRev );
			}
		}

		DOMElement *pElemCharge = CParser::createElementNode( xmlNode, "Charges", pElem );

		// Load list of outgoing
		{
			t_listCharges::const_iterator ite;
			for( ite = listCharges_.begin(); ite != listCharges_.end(); ite++ )
			{
				QString string;

				DOMElement *pChar = xmlNode->createElement( XMLString::transcode( "Charge" ) );
				pChar->setAttribute( XMLString::transcode( "Designation" ), XMLString::transcode( (*ite)->sDesignation_ ) );
				pChar->setAttribute( XMLString::transcode( "Montant" ), XMLString::transcode( string.setNum( (*ite)->uMontant_ ) ) );
				pElemCharge->appendChild( pChar );
			}
		}

	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}
    return 0;
}

//-----------------------------------------------------------------------------
// Convert function
// By $Author: pascal $
//-----------------------------------------------------------------------------
QString CEpargnes::typeEpargneToString( t_eTypeEpargne etype )
{
    QString type;

    switch( etype )
    {
    case eLoiMadelin: { type = "Loi Madelin"; break ; }
    case eArt83: { type = "Art 83"; break ; }
    case eArt82: { type = "Art 82"; break ; }
    case ePerp: { type = "PERP"; break ; }
    case ePerco: { type = "PERCO"; break ; }
    case eIFC: { type = "IFC"; break ; }
    case eArt39: { type = "Art 39"; break ; }
    case eAutreRetraite: { type = "Autre"; break ; }
    default: qDebug( "CEpargnes::typeEpargneToString(): Not supported case" );
    }

    return type;
}

//-----------------------------------------------------------------------------
// Convert function
// By $Author: pascal $
//-----------------------------------------------------------------------------
QString CEpargnes::typeCompteToString( t_eTypeCompte etype )
{
    QString type;

    switch( etype )
    {
        case eCodevi: { type = "Codevi/Livret A"; break ; }
        case ePEL: { type = "PEL"; break ; }
        case eCEL: { type = "CEL"; break ; }
        case eSICAV: { type = "Sicav"; break ; }
        case eObligations: { type = "Obligations"; break ; }
        case eActions: { type = "Actions"; break ; }
        case ePEA: { type = "PEA"; break ; }
        case ePEP: { type = "PEP Bancaire"; break ; }
        case eOPCVM: { type = "OPCVM"; break ; }
        default: qDebug( "CEpargnes::typeCompteToString() : Unsupported case" );
    }
    return type;
}

//-----------------------------------------------------------------------------
// Convert function
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEpargnes::copyFromQT( const dlgAmonSoft &amon )
{
    uSensibilite_       = amon.sliderEpargneSensibilite->value();
    eMotivation1_       = (enum eTypeMotivations) amon.comboBoxMotivation->currentItem();
    eMotivation2_       = (enum eTypeMotivations) amon.comboBoxMotivation_2->currentItem();
    eMotivation3_       = (enum eTypeMotivations) amon.comboBoxMotivation_3->currentItem();
    eMotivation4_       = (enum eTypeMotivations) amon.comboBoxMotivation_4->currentItem();
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEpargnes::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.sliderEpargneSensibilite->setValue( uSensibilite_ );
    amon.textLabelSensibilie->setText( string.setNum( uSensibilite_ ) );

    amon.comboBoxMotivation->setCurrentItem( eMotivation1_ );
    amon.comboBoxMotivation_2->setCurrentItem( eMotivation2_ );
    amon.comboBoxMotivation_3->setCurrentItem( eMotivation3_ );
    amon.comboBoxMotivation_4->setCurrentItem( eMotivation4_ );

    // Load list of saving
    {  
        amon.listViewEpargne->clear();

        t_listEpargnes::const_iterator ite;
        for( ite = listEpargnes_.begin(); ite != listEpargnes_.end(); ite++ )
        {
            QListViewItem *item = new QListViewItem( amon.listViewEpargne,
                typeEpargneToString( (*ite)->eType_ ),
                (*ite)->dEffet_.toString( Qt::ISODate ),
                string.setNum( (*ite)->uInvAnnuel_ ),
                string.setNum( (*ite)->uEpargne_ ),
                (*ite)->dEpargne_.toString( Qt::ISODate ),
                (*ite)->sContrat_,
                (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "" );
        }
    }

    // Load list of life assurance
    {   
        amon.listViewAssuranceVie->clear();

        t_listAssurancesVie::const_iterator ite;
        for( ite = listAssurancesVie_.begin(); ite != listAssurancesVie_.end(); ite++ )
        {
            QString string;

            QListViewItem *item = new QListViewItem( amon.listViewAssuranceVie,
                (*ite)->sContrat_,
                (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "",
                (*ite)->dEffet_.toString( Qt::ISODate ),
                string.setNum( (*ite)->uInvAnnuel_ ),
                (*ite)->sTerme_,
                string.setNum( (*ite)->uCapital_ ),
                (*ite)->dCapital_.toString( Qt::ISODate ) );

            item->setText( 8, string.setNum( (*ite)->uDSK_ ) );
            item->setText( 9, string.setNum( (*ite)->uPEP_ ) );
            item->setText( 10, string.setNum( (*ite)->uMS_) );
            item->setText( 11, string.setNum( (*ite)->uFD_ ) );
        }
    }

    // Load list of compte
    {
        amon.listViewComptes->clear();
        t_listComptes::const_iterator ite;
        for( ite = listComptes_.begin(); ite != listComptes_.end(); ite++ )
        {
            QString string;

            QListViewItem *item = new QListViewItem( amon.listViewComptes,
                typeCompteToString( (*ite)->eType_ ),
                (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "",
                (*ite)->dEffet_.toString( Qt::ISODate ),
                string.setNum( (*ite)->uInvAnnuel_ ),
                (*ite)->sTerme_,
                string.setNum( (*ite)->uCapital_ ),
                (*ite)->dCapital_.toString( Qt::ISODate ),
                string.setNum( (*ite)->usRendement_ ) );
            item->setText( 8, (*ite)->sNotes_ );
        }
    }

    // Load list of incoming
    {
        amon.listViewRevenus->clear();
        t_listRevenus::const_iterator ite;
        for( ite = listRevenus_.begin(); ite != listRevenus_.end(); ite++ )
        {
            QString string;

            QListViewItem *item = new QListViewItem( amon.listViewRevenus,
                (*ite)->sDesignation_,
                string.setNum( (*ite)->uMontant_ ) );
        }
    }

    // Load list of outgoing
    {
        amon.listViewCharges->clear();
        t_listCharges::const_iterator ite;
        for( ite = listCharges_.begin(); ite != listCharges_.end(); ite++ )
        {
            QString string;

            QListViewItem *item = new QListViewItem( amon.listViewCharges,
                (*ite)->sDesignation_,
                string.setNum( (*ite)->uMontant_ ) );
        }
    }
}