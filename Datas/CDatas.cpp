/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CDatas.cpp,v 1.10 2006/11/10 10:48:06 pascal Exp $
* $Log: CDatas.cpp,v $
* Revision 1.10  2006/11/10 10:48:06  pascal
* - V�rification de la coh�rence des donn�es lors de la validation. Pour le moment, on l�ve simplement une exception si l'on ne passe pas des entiers l� o� ils sont attendus.
*
* Revision 1.9  2006/11/09 13:39:48  pascal
* Version 0.2.6
* Nouvelles fonctionnalit�s
*
* - Les resets ainsi que les sauvegardes des fichiers ont �t� v�rifi�s et aucune donn�e n'est perdue.
*
* - Les exportations des personnes a �t� revue et est d�sormais plus jolie et plus compr�hensible. Dans la prochaine version nous ajouterons la m�me m�thode pour l'exportation des familles et des entreprises.
*
* Correction de bugs
*
* - D�sormais, il est possible de mettre des nombres r�els dans les pourcentages. Plus g�n�ralement, cette version n'utilise plus les masques de saisies. C'est � cause d'eux, que l'on pouvait avoir le curseur au milieu d'une saisie, ce qui �tait g�nant.
*
* Il est important de faire attention � mettre des nombres dans les champs o� l'on attend des nombres. Ces v�rifications sont en cours d'�tre mise en place sous une autre forme et seront r�-activ�es dans la prochaine version.
*
* - Les probl�mes li�s � la suppression d'une personne ont �t� corrig�s
* - Les informations concernant l'ISF n'�taient pas sauvegard�es, c'est corrig�.
*
* Roadmap
*
* - Fin novembre
*  + Validation de la coh�rence des donn�es lors de la validation
*  + Correction de bugs divers restants
*  + Connexion pour les fiches entses.
*  + Cryptage des fichiers de donn�es XML
*
* - Fin d�cembre
*   + Am�lioration du syst�me de mise � jour
*   + Modification dans la gestion des listes d'�pargne, d'enfants, de revenus, des charges, etc.
*
* Pour information version active jusqu'au 30 d�cembre 2006.
*
* Revision 1.8  2006/10/09 10:06:07  pascal
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
* Revision 1.7  2006/09/04 11:44:22  pascal
* Version 0.2.3
* Nouvelles fonctionnalit�s
*
* - Recherche complexe deuxi�me version
*     Les recherches sont d�finies dans le fichier search.ini qui se trouve par d�faut dans "c:\program files\Amonsoft\".
*     La syntaxe de ce fichier est d�sormais de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE AND|OR [!] MOTCLE
*
*     Il est donc d�sormais possible de combiner deux crit�res de recherche.
*
* - Modification des mots clefs :
*         ANNIVERSAIRE renvoit d�sormais la liste des personnes dont c'est l'anniversaire (m�me jour et m�me mois que le syst�me).
*         DATEANNIVERSAIRE n�cessitera dans l'interface la saisie d'une date (m�me fonctionnement l'ancien ANNIVERSAIRE).
*
* - Les recherches par nom, pr�nom et type de clients sont combin�s aux recherches complexes. Il est ainsi possible de chercher un client, par exemple, qui n'a pas de mutuelle et dont le pr�nom contient "dou".
*
* - "Exporter personnes" dans le menu Fichier, devient "Exporter". Il est d�sormais possible d'exporter une fiche entreprise en XML pour l'ouvrir avec Word.
*
* - Un syst�me de mise � jour automatique est en place. La v�rification s'effectue au lancement du programme, si une nouvelle version est disponible vous pouvez la t�l�charger. Lors du t�l�chargement de la nouvelle version, le programme est bloqu� afin de ne pas y saisir d'information qui ne pourront �tre sauvegard�e. La nouvelle version est t�l�charg�e dans le r�pertoire courant du programme, une fois le t�l�chargement fini, l'installation est automatiquement lanc�e.
*
* Correction de bugs
*
* - Pas de corrections dans cette version
*
* Revision 1.6  2006/08/04 11:21:48  pascal
* Version 0.2.2
* Nouvelles fonctionnalit�s
*
* - Recherche complexe premi�re version
*     Les recherches sont d�finies dans le fichier search.ini qui se trouve par d�faut dans "c:\program files\Amonsoft\" (un fichier d'exemple est fourni lors de l'installation).
*     La syntaxe de ce fichier est de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE
*
*     Toutes les lignes commen�ant par '#' ne seront pas interpr�t�es par le programme.
*     Nom: repr�sente le terme sous lequel vous retrouverez la recherche dans le programme.
*     0 signifie qu'il s'ag�t d'une recherche pour les particuliers.
*     ! facultatif, le point d'exclamation permet de renvoyer l'inverse des valeurs retourn�es par le MOTCLE
*     MOTCLE est une valeur dans la liste tel que
*         ANNIVERSAIRE n�cessitera dans l'interface la saisie d'une date
*         AGE n�cessitera dans l'interface la saisie d'une valeur num�rique
*         REVENUS n�cessitera dans l'interface la saisie d'une valeur num�rique
*         BILAN n�cessitera dans l'interface la saisie d'une valeur texte
*         MUTUELLE, RETRAITE, FISCALITERETRAITEMADELIN et ASSURANCEVIE ne requi�re aucune saisie dans l'interface
*
*     Attention pour le moment, les recherches par Nom, Pr�nom ou prospect ne tiennent pas comptent de la recherche complexe s�lectionn�e.
*     Par exemple, il n'est pas possible encore, d'avoir la liste des prospect, qui n'ont pas d'assurance vie.
*
* - Les espaces superflus ne sont plus sauvegard�s dans les fichiers XML
* - Dans la liste des dossiers personnes Fichier/Exporter Personnes permet d'exporter la liste des personnes concern�es par une recherche complexe dans un fichier CSV compatible avec Excel.
* - Lorsqu'une fiche client ou prospect est ouverte Fichier/Exporter Personnes permet d'exporter la personne courante dans deux fichiers XML compatible Word.
*
* Correction de bugs
*
* - La liste des revenus n'�taient pas sauvegard�e dans les fichiers XML
* - Lors de l'ouverture des formulaires annexes d'une fiche les compagnies d'assurance n'�taient pas toujours correctement s�lectionn�es
* - Une personne ne peut plus �tre mari�e qu'� une autre personne (plus de polygamie)
* - Les filtres simples par Nom, Pr�nom et Type de client souffraient de bugs lorsqu'on voulait utiliser les 3 crit�res de recherche
*
* Revision 1.5  2006/06/21 11:23:23  pascal
* - systeme de recherche avanc�
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.4  2006/06/02 19:11:17  pascal
* Version 0.2.0
* - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
* - Suppression des masques sur les pourcentages dans QT
*
* Revision 1.3  2006/05/23 16:06:39  pascal
* - Correction du bugs sur les clients phant�mes
* - D�but des fonctionnalit�s de recherche
* - Correction du bugs sur les listes de status pro
* - Charger / Valider: Enregistre �galement les XML d�sormais
* - Correction du bugs avec le chargement des enfants dans famille
* - Correction du bug qui emp�chait le chargement d'un client depuis une entrses
* - Am�lioration interface : champs plus larges et corrections divers
* - Correction du bug avec l'enregistrement des dates de naissance
* - L'ajout d'un dirigeant ou d'un employ� permet de cr�e des clients prospect directement
* - Suppression de l'onglet liste des prospects dans les fiches personnelles
*
* Revision 1.2  2006/04/16 22:12:24  pascal
* - liens entre employ�s & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des g�rants & employ�s depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.1  2005/09/09 15:49:39  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ d�rive d�sormais de CDatas et d�finisse les classes virtuelles pures
*
*/

#include <list>
#include <qstringlist.h>
#include <qregexp.h>
#include <qmessagebox.h>
#include <qdir.h>
#include <qlineedit.h>

#include <xercesc/util/XMLString.hpp>

// basic file operations
#include <iostream>
#include <fstream>

#include "main.h"
#include "CPersonnes.h"
#include "CEntreprise.h"
#include "CDatas.h"
#include "CSearch.h"
#include "exception.h"

using namespace Datas;

std::list< Datas::CPersonnes * >        Datas::g_listPersonnes;
std::list< Datas::CEntreprise * >       Datas::g_listEntreprises;

CSearch                                 *Datas::g_Search;

//----------------------------------------------------------------------------
// Load the list of entreprises into the combo box
//----------------------------------------------------------------------------
void Datas::loadEntsesInComboBox( QComboBox *combo )
{
    std::list< Datas::CEntreprise * >::const_iterator ite;
    mAssert( combo != 0, "combo != 0" );

    combo->clear();
    combo->insertItem( "", -1 );

    for( ite = g_listEntreprises.begin(); ite != g_listEntreprises.end(); ite++ )
        if( (*ite)->getID() != -1 )
            combo->insertItem( (*ite)->getRaisonSociale(), (*ite)->getID() );
}

//----------------------------------------------------------------------------
// Get an entreprise by its ID
//----------------------------------------------------------------------------
CEntreprise *Datas::getEntses( ushort uId )
{
    std::list< Datas::CEntreprise * >::const_iterator ite;

    for( ite = g_listEntreprises.begin(); ite != g_listEntreprises.end(); ite++ )
    {
        if( (*ite)->getID() == uId )
            return *ite;
    }
    return 0;
}

//----------------------------------------------------------------------------
// Load Personnes list according cmp fonction
//----------------------------------------------------------------------------
void Datas::loadPersonneInListView( QListView *l, CSearch &search, dlgAmonSoft &amon )
{
    std::list< Datas::CPersonnes * >::const_iterator ite;
    QString string;

    qDebug( "loadPersonneInListView" );

    mAssert( l != 0, "l != 0" );
    l->clear();

    for( ite = g_listPersonnes.begin(); ite != g_listPersonnes.end(); ite++ )
    {
        if( search.isPrintable( *ite, amon ) && (*ite)->getID() < (ushort) -1 )
        {
            QListViewItem *item = new QListViewItem( l,
                (*ite)->getNom(),
                (*ite)->getPrenom(),
                (*ite)->getTelephone(),
                (*ite)->getEmail(),
                string.setNum( (*ite)->getID() ) );
        }
    }
    l->sort();
}

//----------------------------------------------------------------------------
// Load Entses list according cmp fonction
//----------------------------------------------------------------------------
void Datas::loadEntsesInListView( QListView *l, const QString patRaison, const QString patSiret,
    bool (*cmp)(const Datas::CEntreprise*, QString strRaison, QString strSiret ) )
{
    std::list< Datas::CEntreprise * >::const_iterator ite;
    QString string;

    qDebug( "loadEntsesInListView" );

    mAssert( l != 0, "l != 0" );
    l->clear();

    for( ite = g_listEntreprises.begin(); ite != g_listEntreprises.end(); ite++ )
    {
        if( ( cmp == 0 || cmp( *ite, patRaison, patSiret ) ) && (*ite)->getID() < (ushort) -1 )
        {
            QListViewItem *item = new QListViewItem( l,
                (*ite)->getRaisonSociale(),
                (*ite)->getNumeroSiret(),
                string.setNum( (*ite)->getID() ) );
        }
    }
}

//----------------------------------------------------------------------------
// Get a person by his ID
//----------------------------------------------------------------------------
CPersonnes   *Datas::getPersonne( ushort usId )
{
    std::list< CPersonnes * >::const_iterator ite;

    for( ite = g_listPersonnes.begin(); ite != g_listPersonnes.end(); ite++ )
    {
        if( (*ite)->getID() == usId )
            return *ite;
    }
    return 0;
}

//----------------------------------------------------------------------------
// Get a person by his civil state
//----------------------------------------------------------------------------
CPersonnes   *Datas::getPersonne( QString sNom, QString sPrenom, QDate dNaissance )
{
    std::list< CPersonnes * >::const_iterator ite;

    for( ite = g_listPersonnes.begin(); ite != g_listPersonnes.end(); ite++ )
    {
        if( (*ite)->getNom() == sNom
            && (*ite)->getPrenom() == sPrenom
            && (*ite)->getDateNaissance() == dNaissance )
            return *ite;
    }
    return 0;
}

//----------------------------------------------------------------------------
// Compare CEntreses'RaisonSocial with str
//----------------------------------------------------------------------------
bool Datas::searchEntsesSimple( const CEntreprise *entses, const QString strRaison, const QString strSiret )
{
    mAssert( entses != 0, "entses != 0" );
    return entses->getRaisonSociale().find( strRaison, 0, false ) > -1
        && entses->getNumeroSiret().find( strSiret, 0, false ) > -1;
}

//----------------------------------------------------------------------------
// Import from CSV file
//
// CSV Format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
//----------------------------------------------------------------------------
QStringList get_substr_csv( std::string str )
{
    QRegExp     sSeparator( "[;\t]" );
    QStringList listStr;

    return listStr.split( sSeparator, str.c_str(), true );
}

void Datas::importerCSV( QString fn, dlgAmonSoft *amon )
{
    // TODO
    // Maybe should we return error list with errors
    std::string     temp;
    int iRep = QMessageBox::No;
    
    std::ifstream csvFile;
    csvFile.open( fn );

    if( ! csvFile.is_open() )
    { qDebug( "Unable to open file importerCSV" ); return ; }
    
    while( std::getline( csvFile,temp ) && iRep == QMessageBox::No )
    {
        QStringList listStr = get_substr_csv( temp );

        if( getPersonne( listStr[0], listStr[1], QDate::fromString( listStr[2], Qt::ISODate ) ) )
        {
            iRep = QMessageBox::warning ( amon,
                            "Erreur durant l'importation",
                            "Doublon avec :" + listStr[0] + listStr[1] + listStr[2] + "\nVoulez-vous interrompre ?",
                            QMessageBox::Yes,
                            QMessageBox::No );
            continue ;
        }

        CPersonnes  *pPer = new CPersonnes( listStr[0], listStr[1], QDate::fromString( listStr[2], Qt::ISODate ) );
        t_Adresse   add;
        QString     string;

        add.sRue_           = listStr[3];
        add.sComplement_    = listStr[4];
        add.sCodePostal_    = listStr[5];
        add.sVille_         = listStr[6];
        pPer->setAdresse( add );

        pPer->setTelephone( listStr[7] );
        g_listPersonnes.push_back( pPer );

        QListViewItem *item = new QListViewItem( amon->listView,
            pPer->getNom(),
            pPer->getPrenom(),
            pPer->getTelephone(),
            pPer->getEmail(),
            string.setNum( pPer->getID() ) );
        amon->listView->setSelected( item, true );

    }

    csvFile.close();
}

//----------------------------------------------------------------------------
// Export One Personne to XML file
//----------------------------------------------------------------------------
void Datas::exportPersonne( QString filename, QString filenameF, const CPersonnes &p )
{
    qDebug( "CDatas::exportPersonne" );

    CParser *Parser = new CParser( filename );
    CParser *ParserFamille = new CParser( filenameF );    

    Parser->initWrite( "Exportation" );
    ParserFamille->initWrite( "Exportation" );

    XERCES_CPP_NAMESPACE::DOMDocument *pDoc = Parser->getDocument();

    QString strdir = QDir::currentDirPath();
    QString path = "href=\"";
    path += strdir + "\\xml\\personnes.xsl\" type=\"text/xsl\"";

    // Add directive xsl
    XERCES_CPP_NAMESPACE::DOMProcessingInstruction *pi
        = pDoc->createProcessingInstruction( XERCES_CPP_NAMESPACE::XMLString::transcode( "xml-stylesheet" ),
            XERCES_CPP_NAMESPACE::XMLString::transcode( path ) );

    XERCES_CPP_NAMESPACE::DOMNode* docRootNode = pDoc->getDocumentElement();
	pDoc->replaceChild( pi, docRootNode );
    pDoc->appendChild( docRootNode );

    p.saveToXML( pDoc, ParserFamille->getDocument() );

    ParserFamille->writeFile();
    Parser->writeFile();

    delete Parser;
    delete ParserFamille;
}

//----------------------------------------------------------------------------
// Export Entreprise to XML file
//----------------------------------------------------------------------------
void Datas::exportEntreprise( QString filename, const CEntreprise &p )
{
    qDebug( "CDatas::exportPersonne" );

    // Fake to keep information about global which is used by gerant and employe save function
    CParser *parserEntses = g_ParserEntses;

    CParser *Parser = new CParser( filename );
    g_ParserEntses = Parser;
    Parser->initWrite( "Exportation" );
    p.saveToXML( Parser->getDocument() );
    Parser->writeFile();
    delete Parser;

    g_ParserEntses = parserEntses;
}

//----------------------------------------------------------------------------
// Get informations from GUI and check type
//----------------------------------------------------------------------------
unsigned int Datas::get_uint_from_qlineedit( QLineEdit *a )
{
    uint i = 0;
    bool t = true;
    i = a->text().toUInt( &t );
    if( ! t )
    {
        QString str = "Le champs suivant attend un entier : ";
        str = str + a->name();
        CException exce( str );
        throw( exce );
    }
    return i;
}

unsigned short Datas::get_ushort_from_qlineedit( QLineEdit *a )
{
    ushort i = 0;
    bool t = true;
    i = a->text().toUInt( &t );
    if( ! t )
    {
        QString str = "Le champs suivant attend un entier : ";
        str = str + a->name();
        CException exce( str );
        throw( exce );
    }
    return i;
}