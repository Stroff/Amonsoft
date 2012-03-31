/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: Conseillers.cpp,v 1.1 2006/03/21 10:42:25 pascal Exp $
 * $Log: Conseillers.cpp,v $
 * Revision 1.1  2006/03/21 10:42:25  pascal
 * *** empty log message ***
 *
 *
 */

#include "Preferences/Conseillers.h"

using namespace Preferences;

//----------------------------------------------------------------------------
// Save to XML
//----------------------------------------------------------------------------
void CCabinet::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode,
                          XERCES_CPP_NAMESPACE::DOMElement *xmlElement ) const
{
    XERCES_CPP_NAMESPACE_USE

	try {
		QString string;

        DOMElement *pElem = CParser::createElementNode( xmlNode, "Cabinet", xmlElement, "Nom", sNom_ );
        pElem->setAttribute( XMLString::transcode( "Type" ), XMLString::transcode( string.setNum( eCabinet_ ) ) );

        std::list< QString* >::const_iterator ite;
        for( ite = listConseillers_.begin(); ite != listConseillers_.end(); ite++ )
            CParser::createTextNode( xmlNode, "Nom", **ite, pElem );
	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}
}

//----------------------------------------------------------------------------
// Load from XML
//----------------------------------------------------------------------------
void CCabinet::loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try{
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getTagName() ), "Cabinet" ) )
            return ;
    
        sNom_ = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "Nom" ) ) );
        eCabinet_ = (enum eTypeCabinet) XMLString::parseInt( xmlNode->getAttribute( XMLString::transcode( "Type" ) ) );

        listConseillers_.clear();

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            const char *pt = 0;
            DOMNode *ptNode = listNodes->item( i );

            pt = CParser::getTextNode( ptNode, "Nom" );
            if( pt != 0 )
            {
                QString *pNom = new QString( pt );
                listConseillers_.push_back( pNom );
            }                
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
}

//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------
void CCabinet::loadInQT( QListView *list ) const
{
    list->clear();

    QListViewItem *l = new QListViewItem( list,
        "<Nouveau>");

    std::list< QString* >::const_iterator ite;
    for( ite = listConseillers_.begin(); ite != listConseillers_.end(); ite++ )
        QListViewItem *l = new QListViewItem( list, **ite );
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
void CCabinet::loadInQT( QComboBox *list ) const
{
    list->clear();

    list->insertItem ( "" );

    std::list< QString* >::const_iterator ite;
    for( ite = listConseillers_.begin(); ite != listConseillers_.end(); ite++ )
        list->insertItem ( **ite );
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
QString *CCabinet::getConseiller( QString name )
{
    std::list< QString* >::iterator ite;

    for( ite = listConseillers_.begin(); ite != listConseillers_.end(); ite++ )
        if( **ite == name )
            return *ite;
    return 0;
}