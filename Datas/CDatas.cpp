/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CDatas.cpp,v 1.10 2006/11/10 10:48:06 pascal Exp $
* $Log: CDatas.cpp,v $
* Revision 1.10  2006/11/10 10:48:06  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
* Revision 1.9  2006/11/09 13:39:48  pascal
* Version 0.2.6
* Nouvelles fonctionnalités
*
* - Les resets ainsi que les sauvegardes des fichiers ont été vérifiés et aucune donnée n'est perdue.
*
* - Les exportations des personnes a été revue et est désormais plus jolie et plus compréhensible. Dans la prochaine version nous ajouterons la même méthode pour l'exportation des familles et des entreprises.
*
* Correction de bugs
*
* - Désormais, il est possible de mettre des nombres réels dans les pourcentages. Plus généralement, cette version n'utilise plus les masques de saisies. C'est à cause d'eux, que l'on pouvait avoir le curseur au milieu d'une saisie, ce qui était gênant.
*
* Il est important de faire attention à mettre des nombres dans les champs où l'on attend des nombres. Ces vérifications sont en cours d'être mise en place sous une autre forme et seront ré-activées dans la prochaine version.
*
* - Les problèmes liés à la suppression d'une personne ont été corrigés
* - Les informations concernant l'ISF n'étaient pas sauvegardées, c'est corrigé.
*
* Roadmap
*
* - Fin novembre
*  + Validation de la cohérence des données lors de la validation
*  + Correction de bugs divers restants
*  + Connexion pour les fiches entses.
*  + Cryptage des fichiers de données XML
*
* - Fin décembre
*   + Amélioration du système de mise à jour
*   + Modification dans la gestion des listes d'épargne, d'enfants, de revenus, des charges, etc.
*
* Pour information version active jusqu'au 30 décembre 2006.
*
* Revision 1.8  2006/10/09 10:06:07  pascal
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
* Revision 1.7  2006/09/04 11:44:22  pascal
* Version 0.2.3
* Nouvelles fonctionnalités
*
* - Recherche complexe deuxième version
*     Les recherches sont définies dans le fichier search.ini qui se trouve par défaut dans "c:\program files\Amonsoft\".
*     La syntaxe de ce fichier est désormais de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE AND|OR [!] MOTCLE
*
*     Il est donc désormais possible de combiner deux critères de recherche.
*
* - Modification des mots clefs :
*         ANNIVERSAIRE renvoit désormais la liste des personnes dont c'est l'anniversaire (même jour et même mois que le système).
*         DATEANNIVERSAIRE nécessitera dans l'interface la saisie d'une date (même fonctionnement l'ancien ANNIVERSAIRE).
*
* - Les recherches par nom, prénom et type de clients sont combinés aux recherches complexes. Il est ainsi possible de chercher un client, par exemple, qui n'a pas de mutuelle et dont le prénom contient "dou".
*
* - "Exporter personnes" dans le menu Fichier, devient "Exporter". Il est désormais possible d'exporter une fiche entreprise en XML pour l'ouvrir avec Word.
*
* - Un système de mise à jour automatique est en place. La vérification s'effectue au lancement du programme, si une nouvelle version est disponible vous pouvez la télécharger. Lors du téléchargement de la nouvelle version, le programme est bloqué afin de ne pas y saisir d'information qui ne pourront être sauvegardée. La nouvelle version est téléchargée dans le répertoire courant du programme, une fois le téléchargement fini, l'installation est automatiquement lancée.
*
* Correction de bugs
*
* - Pas de corrections dans cette version
*
* Revision 1.6  2006/08/04 11:21:48  pascal
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
* Revision 1.5  2006/06/21 11:23:23  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.4  2006/06/02 19:11:17  pascal
* Version 0.2.0
* - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
* - Suppression des masques sur les pourcentages dans QT
*
* Revision 1.3  2006/05/23 16:06:39  pascal
* - Correction du bugs sur les clients phantômes
* - Début des fonctionnalités de recherche
* - Correction du bugs sur les listes de status pro
* - Charger / Valider: Enregistre également les XML désormais
* - Correction du bugs avec le chargement des enfants dans famille
* - Correction du bug qui empéchait le chargement d'un client depuis une entrses
* - Amélioration interface : champs plus larges et corrections divers
* - Correction du bug avec l'enregistrement des dates de naissance
* - L'ajout d'un dirigeant ou d'un employé permet de crée des clients prospect directement
* - Suppression de l'onglet liste des prospects dans les fiches personnelles
*
* Revision 1.2  2006/04/16 22:12:24  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.1  2005/09/09 15:49:39  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
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