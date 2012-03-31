/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: CPersonnes.cpp,v 1.26 2006/10/09 10:06:08 pascal Exp $
 * $Log: CPersonnes.cpp,v $
 * Revision 1.26  2006/10/09 10:06:08  pascal
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
 * Revision 1.25  2006/08/04 11:21:48  pascal
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
 * Revision 1.24  2006/06/21 11:23:23  pascal
 * - systeme de recherche avancé
 * - correction de bug dans le chargement des Revenus et des Charges
 * - correction de bug dans le chargement des XML des familles
 *
 * Revision 1.23  2006/06/02 19:11:17  pascal
 * Version 0.2.0
 * - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
 * - Suppression des masques sur les pourcentages dans QT
 *
 * Revision 1.22  2006/05/23 16:06:40  pascal
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
 * Revision 1.21  2006/05/12 16:22:43  pascal
 * Version 0.1 build 14
 * - Le fond de la form principale passe au bleu
 * - [BUG] : Problème avec le chargement des dates depuis l'XML : Les dates sont désormais au format ISO
 *
 * Revision 1.20  2006/04/29 16:29:28  pascal
 * Version 0.1 build 13
 * - Correction d'un bug avec les listes 'static' qui étaient partagées
 * - Suppression des boutons "Valider" & "Rester"
 * - Modification des images des boutons
 * - Personnes et Entreprises ne sont plus manipulé que par Id
 * - Correction de bug : suppression de la liste des retraites
 * - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
 *
 * Revision 1.19  2006/04/28 22:48:02  pascal
 * *** empty log message ***
 *
 * Revision 1.18  2006/04/21 00:08:16  pascal
 * Version 0.1.12
 *
 * - correction du problème liée au reset des listes dynamique.
 * - CPersonne ne crée par forcémment un CFamille (à surveiller !)
 * - nouvelle image pour les prospects
 * - correction bugs mineurs
 *
 * Revision 1.17  2006/04/16 22:12:25  pascal
 * - liens entre employés & entreprises
 * - correction de bug sur le chargement d'une personne depuis une autre
 * - chargement des gérants & employés depuis leur entreprise OK
 * - les tabulations sont dans le bon ordre
 * - version 0.1.10
 *
 * Revision 1.16  2006/03/21 10:42:16  pascal
 * *** empty log message ***
 *
 * Revision 1.15  2005/12/27 10:28:04  pascal
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
 * Revision 1.14  2005/12/20 19:14:47  pascal
 * - liste des prospects màj
 * - modification du conjoint prises en compte
 *
 * Revision 1.13  2005/12/18 19:30:59  pascal
 * - CFamille est désormais enregistré dans un fichier
 * - Ajout dans main.cpp/h de ParserFamille
 * - CPersonne.savetoXML appel désormais l'enregistrement du CFamille correspondant
 * - Ajout dans main.cpp de la fonction de chargement des Familles
 * - amonsoft.ui.h: Ajout dans ChargerPersonne du code permettant de remplir la comboBox du conjoint
 * - Toutes les fonctions de chargements et d'enregistrement des Familles sont faites
 * - TODO: Màj de bugs
 *
 * Revision 1.12  2005/11/30 18:16:48  pascal
 * - améliorations des chargements / enregistrements XML
 * - CFamille peut désormais être sauvegarder dans un fichier
 * - Correction de bugs pour l'XML des entses
 *
 * Revision 1.11  2005/10/14 08:41:11  pascal
 * - correction d'un bogue lors de la lecture du fichier XML : Un élément vide était ajouté
 *
 * Revision 1.10  2005/10/12 22:57:07  pascal
 * *** empty log message ***
 *
 * Revision 1.9  2005/10/12 16:11:21  pascal
 * - implementation des fonctions loadFromXerces des classes CPersonnes *
 * - bug: ajout de CPrevoyance dans CPersonnes
 *
 * Revision 1.8  2005/10/11 22:53:58  pascal
 * - CPersonnes peut lire depuis le XML ses données
 * - CConseillers aussi
 * - CEpargnes en cours !
 *
 * Revision 1.7  2005/10/11 08:12:17  pascal
 * - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
 * - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
 * - les fonctions liées à QT sont toutes implémentées
 * - les fonctions saveToXML sont implémentées pour les particuliers
 *
 * Revision 1.6  2005/10/05 17:14:23  pascal
 * - nouvelle structure de données pour stocker les informations sur l'épargne
 * - résolution du problème lié à l'épouse : méthodes surchargées avec un bool supplémentaire permettant de savoir à qui l'on a à faire dans CPersonne et dans CRevenus.
 * - loadInQT implémenté pour toutes les classes
 *
 * Revision 1.5  2005/09/29 15:51:27  pascal
 * - Les boutons des onglets de la section ajouter possèdent désormais une image
 * - copyFromQT est bientôt implémentée pour toutes les classes
 *
 * Revision 1.4  2005/09/27 15:28:11  pascal
 * - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
 *
 * Revision 1.3  2005/09/21 17:21:03  pascal
 * - Amélioration pour la gestion des données
 * - Fichier TODO
 * - Nouvelle classe de données CPrevoyance
 *
 * Revision 1.2  2005/09/09 15:49:38  pascal
 * - Ajout de la classes virtuel pure CDatas
 * - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
 *
 */

#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qtextedit.h>

#include <list>

#include "CPersonnes.h"

#include "main.h"

using namespace Datas;

//-----------------------------------------------------------------------------
// CPersonnes constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CPersonnes::CPersonnes( bool bEmpty )
{
    if( bEmpty )
    {
        usId_ = (ushort) -1;
        pFamille_ = new CFamille( this );
    }
    else
    {
        usId_ = ++usLastId;
        pFamille_ = 0;
    }
    bBeneficiaire_ = false;
    pEntreprise_ = 0;
    consNotaire_ = new CConseiller( Preferences::eNotaire );
    consAvocat_  = new CConseiller( Preferences::eAvocat );
    consComptable_= new CConseiller( Preferences::eComptable );
    bGerant_ = false;
}

CPersonnes::CPersonnes( QString sNom, QString sPrenom, QDate dNaissance ) :
    sNom_( sNom ),
    sPrenom_( sPrenom ),
    dNaissance_( dNaissance )
{
    bBeneficiaire_ = false;
    pEntreprise_ = 0;
    consNotaire_ = new CConseiller( Preferences::eNotaire );
    consAvocat_  = new CConseiller( Preferences::eAvocat );
    consComptable_= new CConseiller( Preferences::eComptable );
    usId_ = ++usLastId;
    pFamille_ = 0;
    bGerant_= false;
}

CPersonnes::CPersonnes( CFamille *famille ):
    pFamille_( famille )
{ 
    consNotaire_ = new CConseiller( Preferences::eNotaire );
    consAvocat_  = new CConseiller( Preferences::eAvocat );
    consComptable_= new CConseiller( Preferences::eComptable );
    pEntreprise_ = 0;
    bGerant_= false;
    bBeneficiaire_ = false;
    usId_ = ++usLastId;
    pFamille_ = 0;
}
//-----------------------------------------------------------------------------
// CPersonnes destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CPersonnes::~CPersonnes()
{
    delete consAvocat_;
    delete consComptable_;
    delete consNotaire_;

    if( pFamille_ != 0 )
    {
        if( pFamille_->getBeneficiaire() != this )
            // If conjoint
            pFamille_->setConjoint( 0 );
        else
        {
            // If benef
            CPersonnes *pp = const_cast< CPersonnes* >( pFamille_->getConjoint() );
            if( pp != 0 )
                pp->setFamille( 0 );
            delete pFamille_;
            pFamille_ = 0;
        }
    }
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CPersonnes::loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    if( XMLString::equals( XMLString::transcode( xmlNode->getTagName() ), "Personne" ) )
    {
        sNom_ = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "Nom" ) ) );
        sPrenom_ = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "Prenom" ) ) );
        usId_ = XMLString::parseInt( xmlNode->getAttribute( XMLString::transcode( "ID" ) ) );
        const char *sTmp = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "Beneficiaire" ) ) );
        
        if( strcmp( sTmp, "oui" ) == 0 )
            bBeneficiaire_ = true;
        else bBeneficiaire_ = false;

        if( usId_ > usLastId )
            usLastId = usId_;

        const char *sCivilite = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "Civilite" ) ) );
        if( strcmp( sCivilite, "Mr" ) == 0 )
            eCiv_ = Mr;
        if( strcmp( sCivilite, "Melle" ) == 0 )
            eCiv_ = Melle;
        if( strcmp( sCivilite, "Mde" ) == 0 )
            eCiv_ = Mde;
    } else return 1;

    DOMNodeList *listNodes = xmlNode->getChildNodes();

    XMLSize_t size = listNodes->getLength();

    // Viewing list of nodes
    for( XMLSize_t i = 0; i < size; i++ )
    {
        DOMNode *ptNode = listNodes->item( i );
        const char *pt;

        pt = CParser::getTextNode( ptNode, "DateNaissance" );
        if( pt != 0 )
        {
            dNaissance_ = QDate::fromString( pt, Qt::ISODate );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "NomJeuneFille" );
        if( pt != 0 )
        {
            sNomJeuneFille_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "LieuNaissance" );
        if( pt != 0 )
        {
            sLieuNaissance_ = pt;
            continue ;
        }

        if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Adresse" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
        {
            DOMNodeList *plistAddress = ptNode->getChildNodes();

            XMLSize_t asize = plistAddress->getLength();

            for( XMLSize_t iAdresse = 0; iAdresse < asize; iAdresse++ )
            {
                DOMNode *ptNodeAdd = plistAddress->item( iAdresse );
                const char *ptAdd;

                ptAdd = CParser::getTextNode( ptNodeAdd, "Rue" );
                if( ptAdd != 0 )
                {
                    Adresse_.sRue_ = ptAdd;
                    continue ;
                }
                
                ptAdd = CParser::getTextNode( ptNodeAdd, "Complement" );
                if( ptAdd != 0 )
                {
                    Adresse_.sComplement_ = ptAdd;
                    continue ;
                }

                ptAdd = CParser::getTextNode( ptNodeAdd, "CodePostal" );
                if( ptAdd != 0 )
                {
                    Adresse_.sCodePostal_ = ptAdd;
                    continue ;
                }

                ptAdd = CParser::getTextNode( ptNodeAdd, "Ville" );
                if( ptAdd != 0 )
                {
                    Adresse_.sVille_ = ptAdd;
                    continue ;
                }
            }
            continue ;
        }

        if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "AdresseGestion" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
        {
            DOMNodeList *plistAddress = ptNode->getChildNodes();

            XMLSize_t asize = plistAddress->getLength();

            for( XMLSize_t iAdresse = 0; iAdresse < asize; iAdresse++ )
            {
                DOMNode *ptNodeAdd = plistAddress->item( iAdresse );
                const char *ptAdd;

                ptAdd = CParser::getTextNode( ptNodeAdd, "Rue" );
                if( ptAdd != 0 )
                {
                    AdresseGestion_.sRue_ = ptAdd;
                    continue ;
                }
                
                ptAdd = CParser::getTextNode( ptNodeAdd, "Complement" );
                if( ptAdd != 0 )
                {
                    AdresseGestion_.sComplement_ = ptAdd;
                    continue ;
                }

                ptAdd = CParser::getTextNode( ptNodeAdd, "CodePostal" );
                if( ptAdd != 0 )
                {
                    AdresseGestion_.sCodePostal_ = ptAdd;
                    continue ;
                }

                ptAdd = CParser::getTextNode( ptNodeAdd, "Ville" );
                if( ptAdd != 0 )
                {
                    AdresseGestion_.sVille_ = ptAdd;
                    continue ;
                }
            }
            continue ;
        }

        if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Besoins" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
        {
            DOMNodeList *plistAddress = ptNode->getChildNodes();

            XMLSize_t asize = plistAddress->getLength();

            for( XMLSize_t iAdresse = 0; iAdresse < asize; iAdresse++ )
            {
                DOMNode *ptNodeAdd = plistAddress->item( iAdresse );
                const char *ptAdd;

                ptAdd = CParser::getTextNode( ptNodeAdd, "Prevoyance" );
                if( ptAdd != 0 )
                {
                    sBesoinsPrevoyance_ = ptAdd;
                    continue ;
                }
                
                ptAdd = CParser::getTextNode( ptNodeAdd, "Retraite" );
                if( ptAdd != 0 )
                {
                    sBesoinsRetraite_ = ptAdd;
                    continue ;
                }

                ptAdd = CParser::getTextNode( ptNodeAdd, "Epargne" );
                if( ptAdd != 0 )
                {
                    sBesoinsEpargne_ = ptAdd;
                    continue ;
                }

                ptAdd = CParser::getTextNode( ptNodeAdd, "Patrimoine" );
                if( ptAdd != 0 )
                {
                    sBesoinsPatrimoine_ = ptAdd;
                    continue ;
                }

                ptAdd = CParser::getTextNode( ptNodeAdd, "Sante" );
                if( ptAdd != 0 )
                {
                    sBesoinsSante_ = ptAdd;
                    continue ;
                }
            }
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Notes" );
        if( pt != 0 )
        {
            sNotes_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Telephone" );
        if( pt != 0 )
        {
            sTelephone_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "TelephonePortable" );
        if( pt != 0 )
        {
            sTelephonePortable_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "TelephonePro" );
        if( pt != 0 )
        {
            sTelephonePro_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Fax" );
        if( pt != 0 )
        {
            sTelephoneFax_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Mail" );
        if( pt != 0 )
        {
            sEmail_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "LienEntreprise" );
        if( pt != 0 )
        {
            pEntreprise_ =  getEntses( XMLString::parseInt( XMLString::transcode( pt ) ) );
            continue ;
        }
  
        pt = CParser::getTextNode( ptNode, "Gerant" );
        if( pt != 0 )
        {
            bGerant_ = strcmp( pt, "1" ) == 0 ? true : false;
            continue ;
        }

        if( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Conseillers" )
            && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
        {      
            DOMNodeList *plistAddress = ptNode->getChildNodes();

            XMLSize_t asize = plistAddress->getLength();

            for( XMLSize_t iAdresse = 0; iAdresse < asize; iAdresse++ )
            {
                DOMNode *ptNodeAdd = plistAddress->item( iAdresse );

                if( XMLString::equals( XMLString::transcode( ptNodeAdd->getNodeName() ), "Conseiller" )
                    && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
                {
                    DOMElement *pNodeT = static_cast< DOMElement* > ( ptNodeAdd );
                    enum Preferences::eTypeCabinet eType;

                    eType = (enum Preferences::eTypeCabinet) XMLString::parseInt( pNodeT->getAttribute( XMLString::transcode( "Type" ) ) );
                    switch( eType )
                    {
                        case Preferences::eAvocat:
                            { consAvocat_->loadFromXML( ptNodeAdd ); break ; }
                        case Preferences::eComptable:
                            { consComptable_->loadFromXML( ptNodeAdd ); break ; }
                        case Preferences::eNotaire:
                            { consNotaire_->loadFromXML( ptNodeAdd ); break ; }
                    }
                }
            }
            continue ;
        }

        //  about incoming
        Revenus_.loadFromXML( ptNode );
        Fiscalite_.loadFromXML( ptNode );
        Epargne_.loadFromXML( ptNode );
        Prevoyance_.loadFromXML( ptNode );
        Carriere_.loadFromXML( ptNode );

        //  about ...
    }

    return 0;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CPersonnes::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, 
                           XERCES_CPP_NAMESPACE::DOMDocument *xmlNodeFamille ) const
{
    if( usId_ == (ushort) -1 )
        return 0;

    XERCES_CPP_NAMESPACE_USE

	try {
        QString string;
		DOMElement    *pElem = xmlNode->createElement( XMLString::transcode( "Personne" ) );
        pElem->setAttribute( XMLString::transcode( "ID" ), XMLString::transcode( string.setNum( usId_ ) ) );
        pElem->setAttribute( XMLString::transcode( "Beneficiaire" ), XMLString::transcode( bBeneficiaire_ ? "oui" : "non" ) );
        
        QString sCivilite;
        switch( eCiv_ )
        {
            case Mr: { sCivilite = "Mr"; break ; }
            case Melle: { sCivilite = "Melle"; break ; }
            case Mde: { sCivilite = "Mde"; break ; }
        }

        pElem->setAttribute( XMLString::transcode( "Civilite" ), XMLString::transcode( sCivilite ) );
        pElem->setAttribute( XMLString::transcode( "Nom" ), XMLString::transcode( sNom_.simplifyWhiteSpace() ) );
		pElem->setAttribute( XMLString::transcode( "Prenom" ), XMLString::transcode( sPrenom_.simplifyWhiteSpace() ) );

        CParser::createTextNode( xmlNode, "NomJeuneFille", sNomJeuneFille_, pElem );
		CParser::createTextNode( xmlNode, "DateNaissance", dNaissance_.toString( Qt::ISODate ), pElem );
        CParser::createTextNode( xmlNode, "LieuNaissance", sLieuNaissance_, pElem );
	    
		DOMElement    *pElemAdresse = xmlNode->createElement( XMLString::transcode( "Adresse" ) );
	    
		CParser::createTextNode( xmlNode, "Rue", Adresse_.sRue_, pElemAdresse );
		CParser::createTextNode( xmlNode, "Complement", Adresse_.sComplement_, pElemAdresse );
		CParser::createTextNode( xmlNode, "CodePostal", Adresse_.sCodePostal_, pElemAdresse );
		CParser::createTextNode( xmlNode, "Ville", Adresse_.sVille_, pElemAdresse );

		pElem->appendChild( pElemAdresse );

        CParser::createTextNode( xmlNode, "Telephone", sTelephone_, pElem );
        CParser::createTextNode( xmlNode, "TelephonePortable", sTelephonePortable_, pElem );
        CParser::createTextNode( xmlNode, "TelephonePro", sTelephonePro_, pElem );
        CParser::createTextNode( xmlNode, "Fax", sTelephoneFax_, pElem );
		CParser::createTextNode( xmlNode, "Mail", sEmail_, pElem );

		DOMElement    *pElemAdresseG = xmlNode->createElement( XMLString::transcode( "AdresseGestion" ) );
	    
		CParser::createTextNode( xmlNode, "Rue", AdresseGestion_.sRue_, pElemAdresseG );
		CParser::createTextNode( xmlNode, "Complement", AdresseGestion_.sComplement_, pElemAdresseG );
		CParser::createTextNode( xmlNode, "CodePostal", AdresseGestion_.sCodePostal_, pElemAdresseG );
		CParser::createTextNode( xmlNode, "Ville", AdresseGestion_.sVille_, pElemAdresseG );
		pElem->appendChild( pElemAdresseG );

        DOMElement    *pElemBesoins = xmlNode->createElement( XMLString::transcode( "Besoins" ) );
        pElem->appendChild( pElemBesoins );

		CParser::createTextNode( xmlNode, "Prevoyance", sBesoinsPrevoyance_, pElemBesoins );
        CParser::createTextNode( xmlNode, "Retraite", sBesoinsRetraite_, pElemBesoins );
        CParser::createTextNode( xmlNode, "Epargne", sBesoinsEpargne_, pElemBesoins );
        CParser::createTextNode( xmlNode, "Patrimoine", sBesoinsPatrimoine_, pElemBesoins );
        CParser::createTextNode( xmlNode, "Sante", sBesoinsSante_, pElemBesoins );

        CParser::createTextNode( xmlNode, "Notes", sNotes_, pElem );

        if( pEntreprise_ != 0 )
        {
            CParser::createTextNode( xmlNode, "LienEntreprise", string.setNum( pEntreprise_->getID() ), pElem );
            CParser::createTextNode( xmlNode, "Gerant", bGerant_ ? "1" : "0", pElem );
        }

		DOMElement *node = xmlNode->getDocumentElement();
		node->appendChild( pElem );

		DOMElement *pElemCons = xmlNode->createElement( XMLString::transcode( "Conseillers" ) );
		pElem->appendChild( pElemCons );

		// Call depending class method
		//  about advisers
        if( consAvocat_ )
            consAvocat_->saveToXML( xmlNode, pElemCons );
        if( consNotaire_ )
            consNotaire_->saveToXML( xmlNode, pElemCons );
        if( consComptable_ )
            consComptable_->saveToXML( xmlNode, pElemCons );

		//  about incoming
		Revenus_.saveToXML( xmlNode, pElem );

		//  about taxes
		Fiscalite_.saveToXML( xmlNode, pElem );

		Epargne_.saveToXML( xmlNode, pElem );

        Prevoyance_.saveToXML( xmlNode, pElem );

        Carriere_.saveToXML( xmlNode, pElem );

		//  about ...
        if( pFamille_ && pFamille_->getBeneficiaire() == this )
        {
            // We save the family only if we are the right consumer of the family
            pFamille_->saveToXML( xmlNodeFamille );
        }
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
void CPersonnes::copyFromQT( const dlgAmonSoft &amon )
{
    // Civil State
    eCiv_                   = (enum civilite) amon.comboBoxEtatCivilCivilite->currentItem();
    sNom_                   = amon.lineEditEtatCivilNom->text();
    sNomJeuneFille_         = amon.lineEditEtatCivilNomJeuneFille->text();
    sPrenom_                = amon.lineEditEtatCivilPrenom->text();
    dNaissance_             = amon.dateEditEtatCivilDateNaissance->date();
    sLieuNaissance_         = amon.lineEditEtatCivilLieuNaissance->text();
    
    Adresse_.sRue_          = amon.lineEditEtatCivilRue->text();
    Adresse_.sComplement_   = amon.lineEditEtatCivilAdresseComplement->text();
    Adresse_.sCodePostal_   = amon.lineEditEtatCivilCodePostal->text();
    Adresse_.sVille_        = amon.lineEditEtatCivilVille->text();
    
    AdresseGestion_.sRue_   = amon.lineEditEtatCivilRueGestion->text();
    AdresseGestion_.sComplement_   = amon.lineEditEtatCivilAdresseComplementGestion->text();
    AdresseGestion_.sCodePostal_   = amon.lineEditEtatCivilCodePostalGestion->text();
    AdresseGestion_.sVille_        = amon.lineEditEtatCivilVilleGestion->text();
    
    sTelephone_             = amon.lineEditEtatCivilTelephone->text();
    sTelephonePortable_     = amon.lineEditEtatCivilTelephonePortable->text();
    sTelephonePro_          = amon.lineEditEtatCivilTelephonePro->text();
    sTelephoneFax_          = amon.lineEditEtatCivilTelephoneFax->text();

    sEmail_                 = amon.lineEditEtatCivilEmail->text();
    pEntreprise_            = getEntses( amon.comboBoxEtatCivilRaisonSociale->currentItem() );

    // Call depending class method
    //  about advisers
    consAvocat_->copyFromQT( amon );
    consNotaire_->copyFromQT( amon );
    consComptable_->copyFromQT( amon );

    sBesoinsRetraite_       = amon.lineEditBesoinsRetraite->text();
    sBesoinsPrevoyance_     = amon.lineEditBesoinPrevoyance->text();
    sBesoinsSante_          = amon.lineEditBesoinSante->text();
    sBesoinsEpargne_        = amon.lineEditBesoinEpargne->text();
    sBesoinsPatrimoine_     = amon.lineEditBesoinPatrimoine->text();
    sNotes_                 = amon.textEditBesoinNotes->text();

    //  about incoming
    Revenus_.copyFromQT( amon );

    //  about taxes
    Fiscalite_.copyFromQT( amon );

    // Familial situation
    if( pFamille_ )
        pFamille_->copyFromQT( amon );

    // Saving
    Epargne_.copyFromQT( amon );

    Prevoyance_.copyFromQT( amon );

    Carriere_.copyFromQT( amon );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CPersonnes::loadInQT( dlgAmonSoft &amon ) const
{
    mAssert( usId_ != -1, "usId_ != -1" );
    amon.comboBoxEtatCivilCivilite->setCurrentItem( eCiv_ );
    amon.lineEditEtatCivilNom->setText( sNom_ );
    amon.lineEditEtatCivilNomJeuneFille->setText( sNomJeuneFille_ );
    amon.lineEditEtatCivilPrenom->setText( sPrenom_ );
    amon.dateEditEtatCivilDateNaissance->setDate( dNaissance_ );
    amon.lineEditEtatCivilLieuNaissance->setText( sLieuNaissance_ );

    amon.lineEditEtatCivilRue->setText( Adresse_.sRue_ );
    amon.lineEditEtatCivilAdresseComplement->setText( Adresse_.sComplement_ );
    amon.lineEditEtatCivilCodePostal->setText( Adresse_.sCodePostal_ );
    amon.lineEditEtatCivilVille->setText( Adresse_.sVille_ );

    amon.lineEditEtatCivilRueGestion->setText( AdresseGestion_.sRue_ );
    amon.lineEditEtatCivilAdresseComplementGestion->setText( AdresseGestion_.sComplement_ );
    amon.lineEditEtatCivilCodePostalGestion->setText( AdresseGestion_.sCodePostal_ );
    amon.lineEditEtatCivilVilleGestion->setText( AdresseGestion_.sVille_ );

    amon.lineEditEtatCivilTelephone->setText( sTelephone_ );
    amon.lineEditEtatCivilTelephonePortable->setText( sTelephonePortable_ );
    amon.lineEditEtatCivilTelephonePro->setText( sTelephonePro_ );
    amon.lineEditEtatCivilTelephoneFax->setText( sTelephoneFax_ );
    amon.lineEditEtatCivilEmail->setText( sEmail_ );

    amon.lineEditBesoinsRetraite->setText( sBesoinsRetraite_ );
    amon.lineEditBesoinPrevoyance->setText( sBesoinsPrevoyance_ );
    amon.lineEditBesoinSante->setText( sBesoinsSante_ );
    amon.lineEditBesoinEpargne->setText( sBesoinsEpargne_ );
    amon.lineEditBesoinPatrimoine->setText( sBesoinsPatrimoine_ );
    amon.textEditBesoinNotes->setText( sNotes_ );

    if( ! bBeneficiaire_ )
        amon.comboBoxBenefProspect->setCurrentItem( 0 );
    else
        amon.comboBoxBenefProspect->setCurrentItem( 1 );

    loadEntsesInComboBox( amon.comboBoxEtatCivilRaisonSociale );
    amon.comboBoxEtatCivilRaisonSociale->setEnabled( true );
    if( pEntreprise_ != 0 )
    {
        amon.comboBoxEtatCivilRaisonSociale->setCurrentItem( pEntreprise_->getID() );
        if( bGerant_ ) amon.comboBoxEtatCivilRaisonSociale->setEnabled( false );
    }

    // Call depending class method
    //  about advisers
    consNotaire_->loadInQT( amon );
    consAvocat_->loadInQT( amon );
    consComptable_->loadInQT( amon );

    //  about incoming
    Revenus_.loadInQT( amon );

    //  about taxes
    Fiscalite_.loadInQT( amon );

    // Familial situation
    if( pFamille_ != 0 )
        pFamille_->loadInQT( amon );

    // Saving
    Epargne_.loadInQT( amon );

    Prevoyance_.loadInQT( amon );

    Carriere_.loadInQT( amon );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CPersonnes::loadInQT( dlgAmonSoft &amon, bool bFriend ) const
{
    if( bFriend == false )
    {
        loadInQT( amon );
        return ;
    }

    QString string;

    amon.dateEditFamilleDateNaissance->setDate( dNaissance_ );
    amon.lineEditFamilleLieuNaissance->setText( sLieuNaissance_ );
    amon.lineEditFamilleNomRue->setText( Adresse_.sRue_ );
    amon.lineEditFamilleAdresseComplement->setText( Adresse_.sComplement_ );
    amon.lineEditFamilleCodePostal->setText( Adresse_.sCodePostal_ );
    amon.lineEditFamilleVille->setText( Adresse_.sVille_ );
    amon.lineEditFamilleTelephone->setText( sTelephone_ );
    amon.lineEditFamilleTelephonePro->setText( sTelephonePro_ );
    amon.lineEditFamilleTelephonePortable->setText( sTelephonePortable_ );
    amon.lineEditFamilleTelephoneFax->setText( sTelephoneFax_ );
    amon.lineEditFamilleEmail->setText( sEmail_ );
    amon.lineEditCarriereMontantImpotMadame->setText( string.setNum( Fiscalite_.getMontantImpot() ) );
    amon.lineEditCarriereDeductionsMadame->setText( string.setNum( Fiscalite_.getDeduction() ) );

    //  about incoming
    Revenus_.loadInQT( amon, bFriend );
}
//-----------------------------------------------------------------------------
// Search a personne
// By $Author: pascal $
//-----------------------------------------------------------------------------
CPersonnes *CPersonnes::getItemFromID( ushort usId )
{
    // TODO: Use hashmap
    std::list< Datas::CPersonnes * >::const_iterator ite;

    for( ite = g_listPersonnes.begin(); ite != g_listPersonnes.end(); ite++ )
    {
        if( (*ite)->getID() == usId )
            return *ite;
    }
    return 0;
}