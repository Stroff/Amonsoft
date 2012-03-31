/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: CPreferences.cpp,v 1.5 2006/10/13 14:39:50 pascal Exp $
 * $Log: CPreferences.cpp,v $
 * Revision 1.5  2006/10/13 14:39:50  pascal
 * Version 0.2.5
 *
 * Nouvelles fonctionnalit�s
 *
 * - Syst�me de CrashReport complet: G�n�ration d'un fichier de dump (.dmp) lorsque le programme plante. Tentative de sauvegarde des fichiers lors d'un plantage.
 *
 * - MoisBilan est d�sormais une liste d�roulante.
 *
 * - Plus de masque de saisie, ce qui implique plus de v�rification au niveau des types de donn�es saisies. Cela corrige les probl�mes li�s au curseur au milieu de la case ou encore l'impossibilit� d'avoir des pourcentages utilisant des nombres r�els.
 *
 * - Le terme b�n�ficiaire a �t� remplac� par client.
 *
 * Correction de bugs
 *
 * - Il n'y a plus de bugs lorsqu'on supprime une personne employ�e dans une entreprise.
 *
 * Roadmap
 *
 * - Fin octobre
 *  + Tests de coh�rences
 *  + Mise en forme des exportations.
 *  + Connexion pour les fiches entses.
 *
 * - Fin novembre
 *  + Cryptage des fichiers de donn�es XML
 *  + Am�lioration du syst�me de mise � jour
 *  + Modification dans la gestion des listes d'�pargne, d'enfants, de revenus, des charges, etc.
 *
 * La version expire le 30/11/2006
 *
 * Revision 1.4  2006/10/09 10:06:09  pascal
 * Version 0.2.4
 *
 * Nouvelles fonctionnalit�s
 *
 * - D�sormais lorsqu'une erreur "attendue" se d�clenche, un email nous est envoy� pour nous le signaler.
 *
 * - A chaque lancement du programme les fichiers de donn�es sont copi�s dans des fichiers ".bak", lesquels seront utilisables en cas de crash. Ce syst�me ne remplacement toutefois pas une sauvegarde quotidienne que l'on pourrait faire avec, e.g. http://www.clubic.com/telecharger-fiche11081-cobian-backup.html.
 *
 * - Lorsqu'une erreur est d�tect�e durant l'ex�cution du programme, le syst�me tant de faire une sauvegarde avant de se fermer.
 *
 * - G�n�ration de coredump, lors que le programme plante afin d'�tablir la raison du plantage. Ce module n'est pas tout � fait fonctionnel, il sera compl�ter dans la prochaine version.
 *
 * Correction de bugs
 *
 * - Correction d'un bug avec avec le bouton besoin / notes qui ne fonctionnait pas.
 *
 * Revision 1.3  2006/04/29 16:29:57  pascal
 * Version 0.1 build 13
 * - Correction d'un bug avec les listes 'static' qui �taient partag�es
 * - Suppression des boutons "Valider" & "Rester"
 * - Modification des images des boutons
 * - Personnes et Entreprises ne sont plus manipul� que par Id
 * - Correction de bug : suppression de la liste des retraites
 * - R�activation de la sauvegarde manuel et correction des bugs qui ont conduit � sa d�sactivation
 *
 * Revision 1.2  2006/04/16 22:20:52  pascal
 * - liens entre employ�s & entreprises
 * - correction de bug sur le chargement d'une personne depuis une autre
 * - chargement des g�rants & employ�s depuis leur entreprise OK
 * - les tabulations sont dans le bon ordre
 * - version 0.1.10
 *
 * Revision 1.1  2006/03/21 10:42:25  pascal
 * *** empty log message ***
 *
 *
 */

/*
 * Be carrefull CONF_COMPTABILITY *must* be define before !
 */

#include "main.h"
#include "CPreferences.h"

using namespace Preferences;

static const char sPreferencesFile[] = "./xml/preferences.xml";

XERCES_CPP_NAMESPACE_USE

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
CPreferences::CPreferences()
{
    try
    {
        qDebug( "CPreferences()" );
        Parser_ = new CParser( sPreferencesFile );

        DOMDocument *pDoc = Parser_->getDocument();
        DOMElement  *pElem = pDoc->getDocumentElement();

        // TODO CheckDataFileVersion( pElem, amon );

        DOMNodeList *pNodeList = pElem->getChildNodes ();

        uint size = pNodeList->getLength();

        for( uint i = 0; i < size; i++ )
        {            
            DOMNode *pNode = pNodeList->item( i );

            if( XMLString::equals( XMLString::transcode( pNode->getNodeName() ), "Compagnies" ) )
            {
                compagnies_.loadFromXML( pNode );
                continue ;
            } 

            if( XMLString::equals( XMLString::transcode( pNode->getNodeName() ), "Epargnes" ) )
            {
                loadListFromXML( listEpargnes_, "Epargnes", pNode );
                continue ;
            } 

            if( XMLString::equals( XMLString::transcode( pNode->getNodeName() ), "Comptes" ) )
            {
                loadListFromXML( listComptes_, "Comptes", pNode );
                continue ;
            } 

            if( XMLString::equals( XMLString::transcode( pNode->getNodeName() ), "Cabinets" ) )
            {
                DOMNodeList *pNodeCab = pNode->getChildNodes ();

                uint sizec = pNodeCab->getLength();

                for( uint i = 0; i < sizec; i++ )
                {            
                    DOMNode *pNodeC = pNodeCab->item( i );
                    if( XMLString::equals( XMLString::transcode( pNodeC->getNodeName() ), "Cabinet" ) )
                    {
                        DOMElement *pEl = static_cast< DOMElement* >( pNodeC );
                        mAssert( pEl != 0, "pEl != 0" );

                        CCabinet *cabinet = new CCabinet();
                        cabinets_.push_back( cabinet );
                        cabinet->loadFromXML( pEl );
                    }
                }
                continue ;
            } 
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------
CPreferences::~CPreferences()
{
    delete Parser_;
}

void CPreferences::saveToXerces()
{
    XERCES_CPP_NAMESPACE_USE

    Parser_->initWrite( "Preferences", CONF_VERSION );
    
    compagnies_.saveToXML( Parser_->getDocument() );
    saveListToXML( listEpargnes_, "Epargnes", Parser_->getDocument() );
    saveListToXML( listComptes_, "Comptes", Parser_->getDocument() );
    
    /*
     * Write list of cabinets and advisors
     */
    DOMDocument *domdoc = Parser_->getDocument();
    mAssert( domdoc != 0, "domdoc != 0" );
    DOMElement *pElem = domdoc->createElement( XMLString::transcode( "Cabinets" ) );
    
    t_listCabinet::iterator ite = cabinets_.begin();
    for( ; ite != cabinets_.end(); ite++ )
        (*ite)->saveToXML( Parser_->getDocument(), pElem );

    DOMElement *node = domdoc->getDocumentElement();
    node->appendChild( pElem );

    Parser_->writeFile();
}
//----------------------------------------------------------------------------
// saveListToXML
// Generic save list of QString*
//----------------------------------------------------------------------------
void CPreferences::saveListToXML( t_listQString &lTmp, 
                                  const char *sName,
                                  XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const
{
	XERCES_CPP_NAMESPACE_USE

	try {
		QString string;

		DOMElement *pElem = xmlNode->createElement( XMLString::transcode( sName ) );

        t_listQString::const_iterator ite;
        for( ite = lTmp.begin(); ite != lTmp.end(); ite++ )
            CParser::createTextNode( xmlNode, "Nom", (*(*ite)), pElem );

        DOMElement *node = xmlNode->getDocumentElement();
		node->appendChild( pElem );
	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}
}

//----------------------------------------------------------------------------
// loadListFromXML
// Generic save list of QString*
//----------------------------------------------------------------------------
void CPreferences::loadListFromXML( t_listQString &lTmp,
                                    const char *sName,
                                    XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE
    try{
        QString string;

        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), sName ) )
            return ;

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            pt = CParser::getTextNode( ptNode, "Nom" );
            if( pt != 0 )
                lTmp.push_back( new QString( pt ) );
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
}

//----------------------------------------------------------------------------
// getCabinet
//
//----------------------------------------------------------------------------
CCabinet *CPreferences::getCabinet( QString name )
{
    t_listCabinet::iterator ite;

    for( ite = cabinets_.begin(); ite != cabinets_.end(); ite++ )
        if( (*ite)->getName() == name )
            return *ite;
    return 0;
}

//----------------------------------------------------------------------------
// newCabinet
//
//----------------------------------------------------------------------------
CCabinet *CPreferences::newCabinet( QString name, enum eTypeCabinet type )
{
    CCabinet    *cabinet = new CCabinet( name, type );
    cabinets_.push_back( cabinet );
    return cabinet;
}

//----------------------------------------------------------------------------
// delCabinet
//
//----------------------------------------------------------------------------
void CPreferences::delCabinet( QString name )
{
    t_listCabinet::iterator ite;

    if( cabinets_.size() > 0 )
        for( ite = cabinets_.begin(); ite != cabinets_.end(); ite++ )
            if( (*ite)->getName() == name )
            {
                (*ite)->deleteIt();
                cabinets_.remove( *ite );
                return ;
            }
}

//----------------------------------------------------------------------------
// loadCabinet in QT
//
//----------------------------------------------------------------------------
void CPreferences::loadInQTCabinet( QListView *list ) const
{
    t_listCabinet::const_iterator ite;

    list->clear();
    for( ite = cabinets_.begin(); ite != cabinets_.end(); ite++ )
    {
        QListViewItem *l = new QListViewItem( list,
            (*ite)->getName(),
            (*ite)->getTypeText() );
    }
}

//----------------------------------------------------------------------------
// loadCabinet in QT
//
//----------------------------------------------------------------------------
void CPreferences::loadInQTCabinet( QComboBox *combo, enum eTypeCabinet eType ) const
{
    t_listCabinet::const_iterator ite;

    combo->clear();
    combo->insertItem( "" );

    for( ite = cabinets_.begin(); ite != cabinets_.end(); ite++ )
        if( (*ite)->getType() == eType )
            combo->insertItem( (*ite)->getName() );
}