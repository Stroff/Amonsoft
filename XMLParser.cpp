/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: XMLParser.cpp,v 1.11 2006/10/13 14:39:46 pascal Exp $
* $Log: XMLParser.cpp,v $
* Revision 1.11  2006/10/13 14:39:46  pascal
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
* Revision 1.10  2006/10/09 10:06:07  pascal
* Version 0.2.4
*
* Nouvelles fonctionnalités
*
* - Désormais lorsqu'une erreur "attendue" se déclenche, un email nous est envoyé pour nous le signaler.
*
* - A chaque lancement du programme les fichiers de données sont copiés dans des fichiers ".bak", lesquels seront utilisables en cas de crash. Ce système ne remplacement toutefois pas une sauvegarde quotidienne que l'on pourrait faire avec, e.g. http://www.clubic.com/telecharger-fiche11081-cobian-backup.html.
*
* - Lorsqu'une erreur est détectée durant l'exécution du programme, le système tant de faire une sauvegarde avant de se fermer.
*
* - Génération de coredump, lors que le programme plante afin d'établir la raison du plantage. Ce module n'est pas tout à fait fonctionnel, il sera compléter dans la prochaine version.
*
* Correction de bugs
*
* - Correction d'un bug avec avec le bouton besoin / notes qui ne fonctionnait pas.
*
* Revision 1.9  2006/08/04 11:21:48  pascal
* Version 0.2.2
* Nouvelles fonctionnalités
*
* - Recherche complexe première version
*     Les recherches sont définies dans le fichier search.ini qui se trouve par défaut dans "c:\program files\Amonsoft\" (un fichier d'exemple est fourni lors de l'installation).
*     La syntaxe de ce fichier est de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE
*
*     Toutes les lignes commençant par '#' ne seront pas interprétées par le programme.
*     Nom: représente le terme sous lequel vous retrouverez la recherche dans le programme.
*     0 signifie qu'il s'agît d'une recherche pour les particuliers.
*     ! facultatif, le point d'exclamation permet de renvoyer l'inverse des valeurs retournées par le MOTCLE
*     MOTCLE est une valeur dans la liste tel que
*         ANNIVERSAIRE nécessitera dans l'interface la saisie d'une date
*         AGE nécessitera dans l'interface la saisie d'une valeur numérique
*         REVENUS nécessitera dans l'interface la saisie d'une valeur numérique
*         BILAN nécessitera dans l'interface la saisie d'une valeur texte
*         MUTUELLE, RETRAITE, FISCALITERETRAITEMADELIN et ASSURANCEVIE ne requière aucune saisie dans l'interface
*
*     Attention pour le moment, les recherches par Nom, Prénom ou prospect ne tiennent pas comptent de la recherche complexe sélectionnée.
*     Par exemple, il n'est pas possible encore, d'avoir la liste des prospect, qui n'ont pas d'assurance vie.
*
* - Les espaces superflus ne sont plus sauvegardés dans les fichiers XML
* - Dans la liste des dossiers personnes Fichier/Exporter Personnes permet d'exporter la liste des personnes concernées par une recherche complexe dans un fichier CSV compatible avec Excel.
* - Lorsqu'une fiche client ou prospect est ouverte Fichier/Exporter Personnes permet d'exporter la personne courante dans deux fichiers XML compatible Word.
*
* Correction de bugs
*
* - La liste des revenus n'étaient pas sauvegardée dans les fichiers XML
* - Lors de l'ouverture des formulaires annexes d'une fiche les compagnies d'assurance n'étaient pas toujours correctement sélectionnées
* - Une personne ne peut plus être mariée qu'à une autre personne (plus de polygamie)
* - Les filtres simples par Nom, Prénom et Type de client souffraient de bugs lorsqu'on voulait utiliser les 3 critères de recherche
*
* Revision 1.8  2006/04/29 16:27:48  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.7  2006/04/16 22:34:32  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.6  2006/01/20 13:18:39  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.5  2005/12/27 10:27:59  pascal
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
* Revision 1.4  2005/10/26 10:12:49  pascal
* - modification d'initWrite
*
* Revision 1.3  2005/10/14 08:41:00  pascal
* - correction d'un bogue lors de la lecture du fichier XML : Un élément vide était ajouté
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

#include <fstream>
#include <stdlib.h> 
#include "XMLParser.h"
#include "CrashReport/debug.h"
#include <qapplication.h>

#include <xercesc/framework/LocalFileFormatTarget.hpp>

#if defined(XERCES_NEW_IOSTREAMS)
#include <iostream>
#else
#include <iostream.h>
#endif

XERCES_CPP_NAMESPACE_USE

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
CParser::CParser( const char *sfileName )
{
    try
    {
	    sFilename_ = sfileName;

        // DOMImplementationLS contains factory methods for creating objects
        // that implement the DOMBuilder and the DOMWriter interfaces
        XMLCh tempStr[100];
        XMLString::transcode("LS", tempStr, 99);
        DOMImplementation *pimpl = 
            DOMImplementationRegistry::getDOMImplementation(tempStr);

        // construct the DOMBuilder
        pBuilder_ = ((DOMImplementationLS*)pimpl)->
            createDOMBuilder( DOMImplementationLS::MODE_SYNCHRONOUS, 0 );

        // Check file exist and create it else
        std::ifstream file;
        file.open( sfileName, std::ios::in );
        if( ! file.is_open() )
        {
            std::ofstream ofile;
            ofile.open( sfileName );
            ofile << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>\n";
            ofile << "<Init/>\n";
        }

        // parse the XML data, assume it is saved in a local file 
        // the DOMBuilder will parse the data and return it as a DOM tree
        const char *str = sfileName;
        pDOMNode_ = pBuilder_->parseURI( XMLString::transcode( str ) );
        mAssert( pDOMNode_ != 0, "pDOMNode_ != 0" );

        // construct the DOMWriter
        pWriter_ = ((DOMImplementationLS*)pimpl)->createDOMWriter();
        mAssert( pWriter_ != 0, "pWriter_ != 0" );

        // optionally, set some DOMWriter features
        // set the format-pretty-print feature
        if (pWriter_->canSetFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true))
            pWriter_->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true);

        // set the byte-order-mark feature      
        if (pWriter_->canSetFeature(XMLUni::fgDOMWRTBOM, true))
            pWriter_->setFeature(XMLUni::fgDOMWRTBOM, true);
    }
    catch( DOMException  &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
        exit( -1 );
    }
    catch( XMLException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
        exit( -1 );
    }
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------
CParser::~CParser()
{
    // release the memory
    pWriter_->release();
    pBuilder_->release();
}

//----------------------------------------------------------------------------
// Initialize write file
//----------------------------------------------------------------------------
void CParser::initWrite( const char *topnode, const char *sVersion )
{
	DOMElement *pTopNode = pDOMNode_->createElement( XMLString::transcode( topnode ) );
    if( sVersion )
        pTopNode->setAttribute( XMLString::transcode( "version" ), XMLString::transcode( sVersion ) );
	DOMNode* docRootNode = pDOMNode_->getDocumentElement();
	// We initialize a new write, so we don't keep previous tree
	pDOMNode_->replaceChild( pTopNode, docRootNode );
}

//----------------------------------------------------------------------------
// Write file
//----------------------------------------------------------------------------
void CParser::writeFile()
{
    writeFile( sFilename_.c_str() );
}

void CParser::writeFile( const char * filename )
{
    try
    {
        XMLFormatTarget *myFormTarget = new LocalFileFormatTarget( XMLString::transcode( filename ), XMLPlatformUtils::fgMemoryManager );

        // write node
        pWriter_->writeNode( myFormTarget, *pDOMNode_ );
        delete myFormTarget;
    }
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}
}

//--------------------------------------------------------------------
// Create DOMElement
//--------------------------------------------------------------------
DOMElement *CParser::createElementNode( DOMDocument *doc,
                                        const char *name,
                                        DOMNode *node,
                                        const char *attributName,
                                        const char *attributVal )
{
    try
    {
        DOMElement *pElem = doc->createElement( XMLString::transcode( name ) );
        if( attributVal != 0 && attributName != 0 )
        {
            XMLCh *foo = XMLString::transcode( attributVal );
            XMLString::trim( foo );
            pElem->setAttribute( XMLString::transcode( attributName ), foo );
        }
        node->appendChild( pElem );
        return pElem;
    }
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}

	return 0;
}

//--------------------------------------------------------------------
// Create text node
//--------------------------------------------------------------------
void CParser::createTextNode( DOMDocument *doc,
                              const char *name, // Node name
                              const char *val, // Node value
                              DOMNode *node )
{
    XMLCh *foo = XMLString::transcode( val );
    XMLString::trim( foo );

    DOMElement    *pElem = doc->createElement( XMLString::transcode( name ) );
    DOMText       *pText = doc->createTextNode( foo );
    pElem->appendChild( pText );
    node->appendChild( pElem );
}

//--------------------------------------------------------------------
// Get text node
// Return 0 if node is not the good
//--------------------------------------------------------------------
const char *CParser::getTextNode( DOMNode *tnode, const char *name )
{
    if( XMLString::equals( XMLString::transcode( tnode->getNodeName() ), name ) )
    {
        DOMNode *node = tnode->getFirstChild();
        if( node == 0 )
            return 0;
        const XMLCh *bar = node->getNodeValue();
        const char *foo = XMLString::transcode( bar );
        return foo;
    }
    else return 0;
}

//----------------------------------------------------------------------------
// Get attribute of element
//----------------------------------------------------------------------------
const char *CParser::getElementAttribute( DOMNode *node,
                                          const char *name )
{
    DOMNamedNodeMap *attrNode =	node->getAttributes();

    if( attrNode != 0 )
    {        
        DOMNode *pnode = attrNode->getNamedItem( XMLString::transcode( name ) );
        if( pnode == 0 )
            return 0;
        return XMLString::transcode( pnode->getNodeValue() );
    }
    else return 0;
}

int CParser::getIntElementAttribute( DOMNode *node,
                                     const char *name )
{
    const char *pC = CParser::getElementAttribute( node, name );

    if( pC == 0 ) return -1;
    return XMLString::parseInt( XMLString::transcode( pC ) );
}