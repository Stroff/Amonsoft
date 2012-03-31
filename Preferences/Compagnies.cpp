/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: Compagnies.cpp,v 1.2 2006/04/16 22:20:52 pascal Exp $
 * $Log: Compagnies.cpp,v $
 * Revision 1.2  2006/04/16 22:20:52  pascal
 * - liens entre employés & entreprises
 * - correction de bug sur le chargement d'une personne depuis une autre
 * - chargement des gérants & employés depuis leur entreprise OK
 * - les tabulations sont dans le bon ordre
 * - version 0.1.10
 *
 * Revision 1.1  2006/03/21 10:42:25  pascal
 * *** empty log message ***
 *
 *
 */

#include <list>

#include "Compagnies.h"

using namespace Preferences;

//----------------------------------------------------------------------------
// Add compagnie
//
//----------------------------------------------------------------------------
struct SCompagnie   *CCompagnies::addCompagnie( QString name, enum eTypeCompagnie type, QString contact )
{
    struct SCompagnie *pCompagnie = new struct SCompagnie;

    pCompagnie->sCompagnie_ = name;
    pCompagnie->sContact_   = contact;
    pCompagnie->eType_      = type;
    pCompagnie->bDelete_    = false;

    listCompagnies_.push_back( pCompagnie );
    qDebug( "Ajout compagnie depuis preferences" );
    return( pCompagnie );
}

//----------------------------------------------------------------------------
// Del compagnie
//
//----------------------------------------------------------------------------
void CCompagnies::delCompagnie( QString name )
{
    std::list< struct SCompagnie* >::iterator    ite;
    struct SCompagnie *pCompagnie = 0;

    for( ite = listCompagnies_.begin(); ite != listCompagnies_.end() && pCompagnie == 0; ite++ )
        if( (*ite)->sCompagnie_ == name )
            pCompagnie = *ite;

    if( pCompagnie != 0 )
    {
        listCompagnies_.remove( pCompagnie );
        pCompagnie->bDelete_ = true;
    }
}

//----------------------------------------------------------------------------
// Get compagnie
//
//----------------------------------------------------------------------------
struct SCompagnie *CCompagnies::getCompagnie( QString name )
{
    std::list< struct SCompagnie* >::iterator    ite;

    for( ite = listCompagnies_.begin(); ite != listCompagnies_.end(); ite++ )
        if( (*ite)->sCompagnie_ == name )
            return *ite;
    return 0;
}

//----------------------------------------------------------------------------
// Save compagnies
//
//----------------------------------------------------------------------------
void CCompagnies::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const
{
	XERCES_CPP_NAMESPACE_USE

	try {
		QString string;

		DOMElement *pElem = xmlNode->createElement( XMLString::transcode( "Compagnies" ) );

        t_listCompagnies::const_iterator ite;
        for( ite = listCompagnies_.begin(); ite != listCompagnies_.end(); ite++ )
        {
            DOMElement *pCom = xmlNode->createElement( XMLString::transcode( "Compagnie" ) );

            CParser::createTextNode( xmlNode, "Compagnie", (*ite)->sCompagnie_, pCom );
            CParser::createTextNode( xmlNode, "Contact", (*ite)->sContact_, pCom );
            CParser::createTextNode( xmlNode, "Type", string.setNum( (*ite)->eType_ ), pCom );

            pElem->appendChild( pCom );
        }
        DOMElement *node = xmlNode->getDocumentElement();
		node->appendChild( pElem );
	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}
}

//----------------------------------------------------------------------------
// Load compagnie
//
//----------------------------------------------------------------------------
void CCompagnies::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try{
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Compagnies" ) )
            return ;
    
        listCompagnies_.clear();

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );

            if( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Compagnie" ) )
            {    
                struct SCompagnie *ep = new struct SCompagnie;
                ep->bDelete_ = false;

                DOMNodeList *plistElt = ptNode->getChildNodes();

                XMLSize_t asize = plistElt->getLength();

                for( XMLSize_t idx = 0; idx < asize; idx++ )
                {
                    DOMNode *ptNodeRetElt = plistElt->item( idx );
                    const char *ptRetElt;

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Compagnie" );
                    if( ptRetElt != 0 )
                    {
                        ep->sCompagnie_ = ptRetElt;
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Contact" );
                    if( ptRetElt != 0 )
                    {
                        ep->sContact_ = ptRetElt;
                        continue ;
                    }

                    ptRetElt = CParser::getTextNode( ptNodeRetElt, "Type" );
                    if( ptRetElt != 0 )
                    {                           
                        ep->eType_ =  (enum eTypeCompagnie) XMLString::parseInt( XMLString::transcode( ptRetElt ) );
                        continue ;
                    }
                }
                listCompagnies_.push_back( ep );
            }
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
}

//----------------------------------------------------------------------------
// Load compagnie
//
//----------------------------------------------------------------------------
QString CCompagnies::typeCompagnieToString( enum eTypeCompagnie type )
{
    switch( type )
    {
        case eTCAssurance: return "Assurance";
        case eTCBanque: return "Banque";
        case eTCBanqueAssurance: return "Banque/Assurance";
        default: return "Unknown";
    }
}

//----------------------------------------------------------------------------
// Load compagnie
//
//----------------------------------------------------------------------------
void CCompagnies::loadInQT( QListView *list ) const
{
    list->clear();

    QListViewItem *l = new QListViewItem( list,
        "<Nouveau>");

    t_listCompagnies::const_iterator ite;
    for( ite = listCompagnies_.begin(); ite != listCompagnies_.end(); ite++ )
    {
        QListViewItem *l = new QListViewItem( list,
            (*ite)->sCompagnie_,
            typeCompagnieToString( (*ite)->eType_ ),
            (*ite)->sContact_ );
    }
}

//----------------------------------------------------------------------------
// Load compagnie
//
//----------------------------------------------------------------------------
void CCompagnies::loadInQT( QComboBox *list ) const
{
    list->clear();

    list->insertItem ( "" );

    t_listCompagnies::const_iterator ite;
    for( ite = listCompagnies_.begin(); ite != listCompagnies_.end(); ite++ )
        list->insertItem ( (*ite)->sCompagnie_ );
}