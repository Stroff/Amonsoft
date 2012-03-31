/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 * 
 * $Id: CApp.cpp,v 1.5 2007/04/06 15:34:43 pascal Exp $
 */

#include "CApp.h"

// QT
#include <qapplication.h>
#include <qsplashscreen.h>
#include <qimage.h>
#include <qtabwidget.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qurloperator.h>
#include <qdir.h>

// Xerces
#include <xercesc/util/PlatformUtils.hpp>

// XML Parser
#include "XMLParser.h"
#include "updater.h"
// Main interface
#include "Forms/Dynamique.h"
// Mains Datas
#include "Datas/CDatas.h"
#include "Datas/CPersonnes.h"
#include "Datas/CEntreprise.h"
#include "Datas/CSearch.h"

//----------------------------------------------------------------------------
// Global var
//----------------------------------------------------------------------------
CParser                                 *g_Parser;
CParser                                 *g_ParserEntses;
CParser                                 *g_ParserFamille;

Preferences::CPreferences               *g_Preferences;
dlgAmonSoft                             *g_gui;
CApp                                    *g_App;

static const char sPersonnesFile[]      = "./xml/personnes.xml";
static const char sEntreprisesFile[]    = "./xml/entreprises.xml";
static const char sFamilleFile[]        = "./xml/familles.xml";
static const char sSearchFile[]         = "./search.ini";

XERCES_CPP_NAMESPACE_USE

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
CApp::CApp( int argc, char **argv ) : argc_( argc ), argv_( argv )
{
    g_App = this;
}

//----------------------------------------------------------------------------
// Run app
//----------------------------------------------------------------------------
void CApp::runApp()
{

    // We must always have an application
    QApplication application( argc_, argv_ );
    AmonSoft *main = new AmonSoft; // We create our dialog

    dlgAmonSoft *gui = const_cast< dlgAmonSoft* >( g_gui );
    gui = main;

    // Shareware version !
    QDate currentDate = QDate::currentDate();
    QDate expireDate;
    expireDate.setYMD( 2007, 12, 30 );

    if( currentDate > expireDate )
    {
        QMessageBox::critical( main,
            "Votre version a expiré",
            "Veuillez contacter votre revendeur pour continuer à utiliser ce programme",
            QMessageBox::Ok,
            QMessageBox::NoButton );
        exit( 0 );
    }

    // Splash screen
    QImage imgSplash( "Forms/Img/Splash.PNG" );
    QSplashScreen *splash =
	    new QSplashScreen( imgSplash );

    splash->show();  

    Datas::usLastId = 0;
    Datas::usLastIdEntses = 0;

    splash->message(QObject::tr("Initialisation de Xerces..."),
	    Qt::AlignLeft | Qt::AlignTop, Qt::blue);

    XMLPlatformUtils::Initialize();

    //<-- Insert here modules to load during splash screen
    splash->message(QObject::tr("Chargement de l'interface..."),
        Qt::AlignLeft | Qt::AlignTop, Qt::blue);
    //-->

    application.setMainWidget( main );        // It is our main widget

    CUpdater  up( *main );
    up.updateAvailable();

    // Interface init
    splash->message(QObject::tr("Chargement des données..."),
        Qt::AlignLeft | Qt::AlignTop, Qt::blue);

    makeBackup();

    // Load searchs
    Datas::g_Search = new Datas::CSearch();
    Datas::g_Search->loadFileSearch( sSearchFile );
    Datas::g_Search->loadInComboBox( main->comboBoxSearchFunction, true );

    // Add empty enterprise and person to reset form
    Datas::CPersonnes    *pEmptyPerson = new Datas::CPersonnes( true );
    Datas::CEntreprise   *pEmptyEnterprise = new Datas::CEntreprise( true );

    Datas::g_listPersonnes.push_back( pEmptyPerson );
    Datas::g_listEntreprises.push_back( pEmptyEnterprise );
        
    // Initialize & load preference system
    g_Preferences = new Preferences::CPreferences();

    // Initialize parser
    g_Parser              = new CParser( sPersonnesFile );
    g_ParserEntses        = new CParser( sEntreprisesFile );
    g_ParserFamille       = new CParser( sFamilleFile );

    // Be carrefull, order is really important !
    loadXercesData( *main );
    loadXercesDataEntses( *main );
    loadXercesDataFamille( *main ); // Always after Personnes load !!

    // TODO: Put progress bar

    // Show version information
    QString   strVersion = "Amonsoft (c) Sesam micro 2005-2006 Version ";
    qDebug( strVersion + STR_APP_VERSION );

    main->lister();
    main->show(); // Show it...
        
    delete splash;

    application.exec();              // And run!

    saveXercesData();
    delete g_Preferences;

    XMLPlatformUtils::Terminate();    
}

//----------------------------------------------------------------------------
// Be sure about files compability
//----------------------------------------------------------------------------
static void CheckDataFileVersion( const DOMElement *pElem, dlgAmonSoft &amon )
{
    std::string sVersion = XMLString::transcode( pElem->getAttribute( XMLString::transcode( "version" ) ) );
    if( sVersion != CONF_COMPTABILITY && sVersion != CONF_VERSION )
    {
        std::string sMsg = "Vous utilisez une version des données incompatibles avec la version du programme : ";
        sMsg += CONF_COMPTABILITY;
        QMessageBox::critical( &amon,
            "Version de fichiers de données",
                sMsg.c_str(),
            QMessageBox::Ok,
            QMessageBox::NoButton );
        exit( -1 );
    }
}

/*
 * Load datas
 */
int CApp::loadXercesData( dlgAmonSoft &amon )
{    
    try {
        XERCES_CPP_NAMESPACE::DOMDocument *pDoc = g_Parser->getDocument();
        XERCES_CPP_NAMESPACE::DOMElement  *pElem = pDoc->getDocumentElement();

        CheckDataFileVersion( pElem, amon );

        DOMNodeList *pNodeList = pElem->getChildNodes ();

        uint size = pNodeList->getLength();

        for( uint i = 0; i < size; i++ )
        {            
            DOMNode *pNode = pNodeList->item( i );

            if( XMLString::equals( XMLString::transcode( pNode->getNodeName() ), "Personne" ) )
            {
                QString string;
                Datas::CPersonnes *pPersonne = new Datas::CPersonnes;
                DOMElement *elmt = static_cast< DOMElement* >( pNode );
                mAssert( elmt != 0, "elmt != 0" );
                pPersonne->loadFromXML( elmt );
                QListView *listView = amon.getListViewPersonnes();
                QListViewItem *item = new QListViewItem( listView,
                    pPersonne->getNom(),
                    pPersonne->getPrenom(),
                    pPersonne->getTelephone(),
                    pPersonne->getEmail(),
                    string.setNum( pPersonne->getID() ) );

                Datas::g_listPersonnes.push_back( pPersonne );
            }                        
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 0;
}

int CApp::loadXercesDataFamille( dlgAmonSoft &amon )
{    
    try {
        XERCES_CPP_NAMESPACE::DOMDocument *pDoc = g_ParserFamille->getDocument();
        XERCES_CPP_NAMESPACE::DOMElement  *pElem = pDoc->getDocumentElement();

        CheckDataFileVersion( pElem, amon );

        DOMNodeList *pNodeList = pElem->getChildNodes ();

        uint size = pNodeList->getLength();

        for( uint i = 0; i < size; i++ )
        {            
            DOMNode *pNode = pNodeList->item( i );

            if( XMLString::equals( XMLString::transcode( pNode->getNodeName() ), "Famille" ) )
            {
                Datas::CFamille *pFamille = new Datas::CFamille( 0 );
                DOMElement *elmt = static_cast< DOMElement* >( pNode );
                mAssert( elmt != 0, "elmt != 0" );
                // loadFromXML has to link with correct CPersonne, this means
                // that all CPersonne *must* be loaded before !
                int iRet = pFamille->loadFromXML( elmt );
                if( iRet == -1 )
                    delete pFamille;
            }                        
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 0;
}

int CApp::loadXercesDataEntses( dlgAmonSoft &amon )
{    
    try {
        XERCES_CPP_NAMESPACE::DOMDocument *pDoc = g_ParserEntses->getDocument();
        XERCES_CPP_NAMESPACE::DOMElement  *pElem = pDoc->getDocumentElement();

        CheckDataFileVersion( pElem, amon );

        DOMNodeList *pNodeList = pElem->getChildNodes ();

        uint size = pNodeList->getLength();

        for( uint i = 0; i < size; i++ )
        {            
            DOMNode *pNode = pNodeList->item( i );

            if( XMLString::equals( XMLString::transcode( pNode->getNodeName() ), "Entreprise" ) )
            {
                QString string;
				Datas::CEntreprise *pEntreprise = new Datas::CEntreprise;
                DOMElement *elmt = static_cast< DOMElement* >( pNode );
                mAssert( elmt != 0, "elmt != 0" );
                pEntreprise->loadFromXML( elmt );
                QListView *listView = amon.getListViewEntses();
                QListViewItem *item = new QListViewItem( listView,
                    pEntreprise->getRaisonSociale(),
					pEntreprise->getNumeroSiret(),
                    string.setNum( pEntreprise->getID() ) );

				Datas::g_listEntreprises.push_back( pEntreprise );
            }                        
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 0;
}

/*
 * Save datas to XML
 */
void CApp::saveXercesData()
{
	using namespace Datas;

    g_Parser->initWrite( "ListPersonnes", CONF_VERSION );
    g_ParserFamille->initWrite( "ListFamilles", CONF_VERSION );

    // Search item in the global list
    // TODO: Try to find more efficient method
    std::list< CPersonnes* >::const_iterator    ite;
    for( ite = g_listPersonnes.begin(); 
        ite != g_listPersonnes.end(); ite++ )
    {
        // Write CPersonne and call function to save CFamille too
        (*ite)->saveToXML( g_Parser->getDocument(), g_ParserFamille->getDocument() );
    }
    g_ParserFamille->writeFile();
    g_Parser->writeFile();

    // List of societies
    g_ParserEntses->initWrite( "ListeEntreprises", CONF_VERSION );

    // Search item in the global list
    // TODO: Try to find more efficient method
    std::list< CEntreprise* >::const_iterator    ites;
    for( ites = g_listEntreprises.begin(); 
        ites != g_listEntreprises.end(); ites++ )
    {
        // Write
        (*ites)->saveToXML( g_ParserEntses->getDocument() );
    }        
    g_ParserEntses->writeFile( );

    g_Preferences->saveToXerces();
}

//----------------------------------------------------------------------------
// Make copy of daya file
// TODO:Memory leak probably
//----------------------------------------------------------------------------
void CApp::makeBackup()
{
    try
    {
        QStringList listStr;

        listStr << sPersonnesFile
                << sEntreprisesFile
                << sFamilleFile
                << sSearchFile
                << "./xml/preferences.xml"; //TODO: Share prefernce filename

        QStringList::Iterator  ite = listStr.begin();

        for( ; ite != listStr.end(); ite++ )
        {
            QUrlOperator *op = new QUrlOperator();
        
            QString src = QDir::currentDirPath() + *ite;
            QString target = QDir::currentDirPath() + *ite + ".bak"; 
            op->copy( src, target, false, false );
        }

    }
    catch(...)
    {
        qDebug( "Impossible de sauvegarder les fichiers" );
    }
}