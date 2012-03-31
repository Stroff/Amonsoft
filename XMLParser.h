/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: XMLParser.h,v 1.6 2006/04/16 22:34:32 pascal Exp $
* $Log: XMLParser.h,v $
* Revision 1.6  2006/04/16 22:34:32  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.5  2006/03/21 10:42:11  pascal
* *** empty log message ***
*
* Revision 1.4  2006/01/20 13:18:39  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.3  2005/10/26 10:12:49  pascal
* - modification d'initWrite
*
* Revision 1.2  2005/10/12 16:19:25  pascal
* - améliorations de la class pour le parsing
* - chargement du fichier de donnée au démarrage
*
* Revision 1.1  2005/10/11 07:57:25  pascal
* - ajout de la class CParser, qui permet de faire abstraction de Xerces un minimum
* - les variables globales sont définies dans main.h
* - les images ne sont plus intégrées dans les fichiers
*
*/

#ifndef _XMLPARSER_H_
# define _XMLPARSER_H_

// STD
#include <string>
#include <iostream>

// Xerces
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>

/*
 * CParser
 * This class provide an interface to use Xerces library
 */

class CParser
{
	public:
		// Constructor
		CParser( const char * /* FileName */ );
		// Destructor
		~CParser();

	public:
        // Get DOM document
        XERCES_CPP_NAMESPACE::DOMDocument *getDocument() const
        { return pDOMNode_; }
        // Initialize writing
        void initWrite( const char *, const char *sVersion = 0 );
		// Write file
		void writeFile();
        void writeFile( const char * );

	public:

		// Static functions

		//--------------------------------------------------------------------
		// Create DOMElement
		//--------------------------------------------------------------------
		static XERCES_CPP_NAMESPACE::DOMElement *createElementNode( XERCES_CPP_NAMESPACE::DOMDocument *doc,
									const char *name,
									XERCES_CPP_NAMESPACE::DOMNode *node,
									const char *attributName = 0,
									const char *attributVal = 0 );

        XERCES_CPP_NAMESPACE::DOMElement *createElementNode( const char *name,
									                         XERCES_CPP_NAMESPACE::DOMNode *node,
									                         const char *attributName = 0,
									                         const char *attributVal = 0 ) const
        { return createElementNode( pDOMNode_, name, node, attributName, attributVal );  }

		//--------------------------------------------------------------------
		// Create text node
		//--------------------------------------------------------------------
		static void createTextNode( XERCES_CPP_NAMESPACE::DOMDocument *doc,
									const char *name, // Node name
									const char *val, // Node value
									XERCES_CPP_NAMESPACE::DOMNode *node
								  );
        void createTextNode( const char *name, // Node name
									const char *val, // Node value
									XERCES_CPP_NAMESPACE::DOMNode *node
								  )
        { createTextNode( pDOMNode_, name, val, node ); }

        //--------------------------------------------------------------------
        // Get text node
        // Return 0 if node is not the good
        //--------------------------------------------------------------------
        static const char *getTextNode( XERCES_CPP_NAMESPACE::DOMNode *node,
                                        const char *name );

        //--------------------------------------------------------------------
        // Get attribute node
        //--------------------------------------------------------------------
        static const char *getElementAttribute( XERCES_CPP_NAMESPACE::DOMNode *node,
                                                const char *name );
        static int getIntElementAttribute( XERCES_CPP_NAMESPACE::DOMNode *node,
                                           const char *name );        

	private:
		std::string										sFilename_;

	private:
		XERCES_CPP_NAMESPACE::DOMDocument				*pDOMNode_;
		XERCES_CPP_NAMESPACE::XercesDOMParser			*pParser_;
		XERCES_CPP_NAMESPACE::DOMBuilder				*pBuilder_;
		XERCES_CPP_NAMESPACE::DOMWriter					*pWriter_;
};

#endif /* _XMLPARSER_H_ */