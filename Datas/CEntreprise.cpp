/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CEntreprise.cpp,v 1.17 2006/11/10 10:48:06 pascal Exp $
* $Log: CEntreprise.cpp,v $
* Revision 1.17  2006/11/10 10:48:06  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
* Revision 1.16  2006/11/09 13:39:48  pascal
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
* Revision 1.15  2006/10/09 10:06:07  pascal
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
* Revision 1.14  2006/06/21 11:23:23  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.13  2006/05/23 16:06:39  pascal
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
* Revision 1.10  2006/04/16 22:12:24  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.9  2006/03/21 10:42:16  pascal
* *** empty log message ***
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
* Revision 1.7  2005/12/20 19:14:46  pascal
* - liste des prospects màj
* - modification du conjoint prises en compte
*
* Revision 1.6  2005/12/18 19:30:58  pascal
* - CFamille est désormais enregistré dans un fichier
* - Ajout dans main.cpp/h de ParserFamille
* - CPersonne.savetoXML appel désormais l'enregistrement du CFamille correspondant
* - Ajout dans main.cpp de la fonction de chargement des Familles
* - amonsoft.ui.h: Ajout dans ChargerPersonne du code permettant de remplir la comboBox du conjoint
* - Toutes les fonctions de chargements et d'enregistrement des Familles sont faites
* - TODO: Màj de bugs
*
* Revision 1.5  2005/11/30 18:16:48  pascal
* - améliorations des chargements / enregistrements XML
* - CFamille peut désormais être sauvegarder dans un fichier
* - Correction de bugs pour l'XML des entses
*
* Revision 1.4  2005/11/12 15:04:55  pascal
* Mise à niveau ...
*
* Revision 1.3  2005/10/26 10:11:07  pascal
* - CEntreprise : saveToXML réalisé
* - retouches divers
*
* Revision 1.2  2005/10/11 22:53:57  pascal
* - CPersonnes peut lire depuis le XML ses données
* - CConseillers aussi
* - CEpargnes en cours !
*
* Revision 1.1  2005/10/11 08:12:17  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
*
*/

// QT
#include <qlineedit.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qdatetimeedit.h>

#include "main.h"
#include "CPersonnes.h"
#include "CEntreprise.h"

using namespace Datas;

//-----------------------------------------------------------------------------
// CEntreprise constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CEntreprise::CEntreprise( bool bEmpty )
{
    /*
     * Init
     */

    if( bEmpty )
        usId_ = (ushort) -1;
    else
        usId_ = ++usLastIdEntses;

    eSatus_ = eSARL;
    bAGA_ = false;
    bCGA_ = false;
    usCollegueGerance_ = 0;
    usProche_ = 0;
    usAutre_ = 0;
    uBeneficesN1_ = 0;
    uBeneficesN2_ = 0;
    eRegimeFiscale_ = eImpotSociete;
    listGerants_.clear();
    listEmployes_.clear();      
    bInteressement_ = false;
    uVersementN1_ = 0;
    uVersementN2_ = 0;

}

//-----------------------------------------------------------------------------
// CEntreprise destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CEntreprise::~CEntreprise()
{
    std::list< const CPersonnes * >::iterator itep;

    for( itep = listEmployes_.begin(); itep != listEmployes_.end(); itep++ )
    {
        CPersonnes *pPer = const_cast< CPersonnes* >( *itep );
        pPer->removeEntreprise();
    }

    std::list< t_PersonneGerant * >::iterator ite;

    for( ite = listGerants_.begin(); ite != listGerants_.end(); ite++ )
    {
        CPersonnes *pPer = const_cast< CPersonnes* >( (*ite)->pPersonne_ );
        pPer->removeEntreprise();
        delete *ite;
    }
}

//----------------------------------------------------------------------------
// static function to load SRetraite to XML
//----------------------------------------------------------------------------
static struct SRetraite *loadFromXMLRetraites( XERCES_CPP_NAMESPACE::DOMElement *xmlNode )
{    
    XERCES_CPP_NAMESPACE_USE

    try {
        struct SRetraite *retraite = new struct SRetraite;
        retraite->sContrat_ = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "Contrat" ) ) );

        retraite->pCompagnie_ = 0;
        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            pt = CParser::getTextNode( ptNode, "DateEffet" );
            if( pt != 0 )
                retraite->dEffet_ = QDate::fromString( pt, Qt::ISODate );

            pt = CParser::getTextNode( ptNode, "Compagnie" );
            if( pt != 0 )
                retraite->pCompagnie_ = GET_COMP_FROM_TEXT( pt );

            pt = CParser::getTextNode( ptNode, "Collegue" );
            if( pt != 0 )
                retraite->sCollegue_ = pt;

            pt = CParser::getTextNode( ptNode, "TA" );
            if( pt != 0 )
                retraite->usTA_ = XMLString::parseInt( XMLString::transcode( pt ) );

            pt = CParser::getTextNode( ptNode, "TB" );
            if( pt != 0 )
                retraite->usTB_ = XMLString::parseInt( XMLString::transcode( pt ) );

            pt = CParser::getTextNode( ptNode, "TC" );
            if( pt != 0 )
                retraite->usTC_ = XMLString::parseInt( XMLString::transcode( pt ) );

            pt = CParser::getTextNode( ptNode, "Fisc82" );
            if( pt != 0 )
                retraite->usFisc82_ = XMLString::parseInt( XMLString::transcode( pt ) );

            pt = CParser::getTextNode( ptNode, "Fisc82AD" );
            if( pt != 0 )
                retraite->usFisc82AD_ = XMLString::parseInt( XMLString::transcode( pt ) );

            pt = CParser::getTextNode( ptNode, "Fisc82SD" );
            if( pt != 0 )
                retraite->usFisc82SD_ = XMLString::parseInt( XMLString::transcode( pt ) );

            pt = CParser::getTextNode( ptNode, "Fisc39" );
            if( pt != 0 )
                retraite->usFisc39_ = XMLString::parseInt( XMLString::transcode( pt ) );            
        }
        return retraite;
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }

    return 0;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CEntreprise::loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    if( XMLString::equals( XMLString::transcode( xmlNode->getTagName() ), "Entreprise" ) )
    {
        std::string sStatus;

        usId_ = XMLString::parseInt( xmlNode->getAttribute( XMLString::transcode( "ID" ) ) );
        if( usId_ > usLastIdEntses )
            usLastIdEntses = usId_;
        sRaisonSociale_ = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "RaisonSociale" ) ) );
        sStatus = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "Status" ) ) );

        if( XMLString::equals( "SARL", sStatus.c_str() ) )
        {    eSatus_ = eSARL; }
        else if( XMLString::equals( "SA", sStatus.c_str() ) )
        {    eSatus_ = eSA; }
        else if( XMLString::equals( "SAS", sStatus.c_str() ) )
        {    eSatus_ = eSAS; }
        else if( XMLString::equals( "EURL", sStatus.c_str() ) )
        {    eSatus_ = eEURL; }
        else if( XMLString::equals( "SCP", sStatus.c_str() ) )
        {    eSatus_ = eSCP; }
        else
        {
            eSatus_ = eAutreStatus;
			sAutre_ = sStatus.c_str();
        }

    } else return 1;

    DOMNodeList *listNodes = xmlNode->getChildNodes();

    XMLSize_t size = listNodes->getLength();

    // Viewing list of nodes
    for( XMLSize_t i = 0; i < size; i++ )
    {
        DOMNode *ptNode = listNodes->item( i );
        const char *pt;

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

        pt = CParser::getTextNode( ptNode, "CodeNAF" );
        if( pt != 0 )
        {
            sCodeNAF_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "NumeroSiret" );
        if( pt != 0 )
        {
            sNumSiret_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Activite" );
        if( pt != 0 )
        {
            sActivite_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "ConventionCollective" );
        if( pt != 0 )
        {
            sConvention_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "AGA" );
        if( pt != 0 )
        {
            if( XMLString::equals( "oui", pt ) )
                bAGA_ = true;
            else bAGA_ = false;
            continue ;
        }
        
        pt = CParser::getTextNode( ptNode, "CGA" );
        if( pt != 0 )
        {
            if( XMLString::equals( "oui", pt ) )
                bCGA_ = true;
            else bCGA_ = false;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "CollegueGerance" );
        if( pt != 0 )
        {
            usCollegueGerance_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Proche" );
        if( pt != 0 )
        {
            usProche_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Autre" );
        if( pt != 0 )
        {
            usAutre_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "BeneficesN1" );
        if( pt != 0 )
        {
            uBeneficesN1_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "BeneficesN2" );
        if( pt != 0 )
        {
            uBeneficesN2_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "RegimeFiscale" );
        if( pt != 0 )
        {
            if( strcmp( pt, "IR" ) )
                eRegimeFiscale_ = eImpotRevenus;
            else
                eRegimeFiscale_ = eImpotSociete;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "DateCreation" );
        if( pt != 0 )
        {
            sDateCreation_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "SuiteEconomique" );
        if( pt != 0 )
        {
            if( strcmp( pt, "0" ) == 0 )
                bSuiteEconomique_ = true;
            else bSuiteEconomique_ = false;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Telephone" );
        if( pt != 0 )
        {
            sTelephone_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Fax" );
        if( pt != 0 )
        {
            sFax_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "SiteInternet" );
        if( pt != 0 )
        {
            sSiteInternet_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Gerants" );
        if( pt != 0 )
        {
            DOMElement *elmt = static_cast< DOMElement* >( ptNode );
            loadGerantsFromXML( elmt );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Employes" );
        if( pt != 0 )
        {
            DOMElement *elmt = static_cast< DOMElement* >( ptNode );
            loadEmployesFromXML( elmt );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "PEEOrganisme" );
        if( pt != 0 )
        {
            sPEEOrganisme_ = pt;
            continue ;
        }
        
        pt = CParser::getTextNode( ptNode, "PEEDate" );
        if( pt != 0 )
        {
            dPEEDate_ = QDate::fromString( pt, Qt::ISODate );
            continue ;
        }
        
        pt = CParser::getTextNode( ptNode, "Interessement" );
        if( pt != 0 )
        {
            if( strcmp( pt, "oui" ) == 0 )
                bInteressement_ = true;
            else bInteressement_ = false;
            continue ;
        }
        
        pt = CParser::getTextNode( ptNode, "VersementN1" );
        if( pt != 0 )
        {
            uVersementN1_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }
        
        pt = CParser::getTextNode( ptNode, "VersementN2" );
        if( pt != 0 )
        {
            uVersementN2_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Retraites" );
        if( pt != 0 )
        {
			DOMNodeList *listNodes = ptNode->getChildNodes();
			XMLSize_t size = listNodes->getLength();

			// Viewing list of nodes
			for( XMLSize_t i = 0; i < size; i++ )
			{
				DOMNode *ptNodeB = listNodes->item( i );
				struct SRetraite *sRet;
                
                if( XMLString::equals( XMLString::transcode( ptNodeB->getNodeName() ), "Retraite" ) )
                {
                    sRet = loadFromXMLRetraites( static_cast< DOMElement* >( ptNodeB ) );

				    if( sRet == 0 ) break ;

				    listRetraites_.push_back( sRet ); 
                }
            }
            continue ;
        }

        Salarie_.loadFromXML( ptNode );
    }

    return 0;
}


//----------------------------------------------------------------------------
// static function to save SRetraite to XML
//----------------------------------------------------------------------------
static void saveToXMLRetraites( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode,
                                XERCES_CPP_NAMESPACE::DOMElement *node,
                                const struct SRetraite *retraite )
{
    XERCES_CPP_NAMESPACE_USE

    try {
        QString string;

        DOMElement    *pElem =  CParser::createElementNode( xmlNode, "Retraite", node );
        pElem->setAttribute( XMLString::transcode( "Contrat" ), XMLString::transcode( retraite->sContrat_ ) );

        CParser::createTextNode( xmlNode, "DateEffet", retraite->dEffet_.toString( Qt::ISODate ), pElem );
        CParser::createTextNode( xmlNode, "Compagnie", retraite->pCompagnie_ ? retraite->pCompagnie_->sCompagnie_ : "", pElem );
        CParser::createTextNode( xmlNode, "Collegue", retraite->sCollegue_, pElem );
        CParser::createTextNode( xmlNode, "TA", string.setNum( retraite->usTA_ ), pElem );
        CParser::createTextNode( xmlNode, "TB", string.setNum( retraite->usTB_ ), pElem );
        CParser::createTextNode( xmlNode, "TC", string.setNum( retraite->usTC_ ), pElem );
        CParser::createTextNode( xmlNode, "Fisc82", string.setNum( retraite->usFisc82_ ), pElem );
        CParser::createTextNode( xmlNode, "Fisc82AD", string.setNum( retraite->usFisc82AD_ ), pElem );
        CParser::createTextNode( xmlNode, "Fisc82SD", string.setNum( retraite->usFisc82SD_ ), pElem );
        CParser::createTextNode( xmlNode, "Fisc39", string.setNum( retraite->usFisc39_ ), pElem );
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
}


//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CEntreprise::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const
{
    if( usId_ == (ushort) -1 )
        return 0;

    XERCES_CPP_NAMESPACE_USE

    try {
        QString string;

        DOMElement    *pElem = xmlNode->createElement( XMLString::transcode( "Entreprise" ) );
        pElem->setAttribute( XMLString::transcode( "ID" ), XMLString::transcode( string.setNum( usId_ ) ) );
        pElem->setAttribute( XMLString::transcode( "RaisonSociale" ), XMLString::transcode( sRaisonSociale_ ) );
        
        const char *sStatus;
        switch( eSatus_ )
        {
            case eSARL: { sStatus = "SARL"; break ; }
            case eSA: { sStatus = "SA"; break ; }
            case eSAS: { sStatus = "SAS"; break ; }
            case eEURL: { sStatus = "EURL"; break ; }
            case eSCP: { sStatus = "SCP"; break ; }
            // NOTE: Be carefull when reading status, other directly write the status.
            case eAutreStatus: { sStatus = sAutre_; break ; }
            default: qDebug( "CEntreprise::saveToXML(): Unsupported case status" );
        }
        pElem->setAttribute( XMLString::transcode( "Status" ), XMLString::transcode( sStatus ) );

        DOMElement    *pElemAdresse = xmlNode->createElement( XMLString::transcode( "Adresse" ) );

        CParser::createTextNode( xmlNode, "Rue", Adresse_.sRue_, pElemAdresse );
        CParser::createTextNode( xmlNode, "Complement", Adresse_.sComplement_, pElemAdresse );
        CParser::createTextNode( xmlNode, "CodePostal", Adresse_.sCodePostal_, pElemAdresse );
        CParser::createTextNode( xmlNode, "Ville", Adresse_.sVille_, pElemAdresse );

        pElem->appendChild( pElemAdresse );

        CParser::createTextNode( xmlNode, "CodeNAF", sCodeNAF_, pElem );
        CParser::createTextNode( xmlNode, "NumeroSiret", sNumSiret_, pElem );
        CParser::createTextNode( xmlNode, "Activite", sActivite_, pElem );
        CParser::createTextNode( xmlNode, "ConventionCollective", sConvention_, pElem );
        CParser::createTextNode( xmlNode, "AGA", bAGA_ ? "oui" : "non", pElem );
        CParser::createTextNode( xmlNode, "CGA", bCGA_ ? "oui" : "non", pElem );

        CParser::createTextNode( xmlNode, "CollegueGerance", string.setNum( usCollegueGerance_ ) , pElem );
        CParser::createTextNode( xmlNode, "Proche", string.setNum( usProche_ ) , pElem );
        CParser::createTextNode( xmlNode, "Autre", string.setNum( usAutre_ ) , pElem );
        CParser::createTextNode( xmlNode, "BeneficesN1", string.setNum( uBeneficesN1_ ) , pElem );
        CParser::createTextNode( xmlNode, "BeneficesN2", string.setNum( uBeneficesN2_ ) , pElem );

        CParser::createTextNode( xmlNode, "RegimeFiscale", eRegimeFiscale_ == eImpotSociete ? "IS" : "IR" , pElem );
        DOMComment    *pElemCom = xmlNode->createComment( XMLString::transcode( "Mettre un lien numerique vers le gérant" ) );
        pElem->appendChild( pElemCom );

        CParser::createTextNode( xmlNode, "DateCreation", sDateCreation_, pElem );
        CParser::createTextNode( xmlNode, "SuiteEconomique", bSuiteEconomique_ ? "0" : "1", pElem );
        CParser::createTextNode( xmlNode, "Telephone", sTelephone_, pElem );
        CParser::createTextNode( xmlNode, "Fax", sFax_, pElem );
        CParser::createTextNode( xmlNode, "SiteInternet", sSiteInternet_, pElem );

        DOMElement *node = xmlNode->getDocumentElement();
        node->appendChild( pElem );

        // Gerants
        DOMElement *pElemGer = xmlNode->createElement( XMLString::transcode( "Gerants" ) );
        pElem->appendChild( pElemGer );

        saveGerantsToXML( pElemGer );

        // Employes
        DOMElement *pElemEmp = xmlNode->createElement( XMLString::transcode( "Employes" ) );
        pElem->appendChild( pElemEmp );

        saveEmployesToXML( pElemEmp );

        DOMElement *pElemRet = xmlNode->createElement( XMLString::transcode( "Retraites" ) );
        pElem->appendChild( pElemRet );

        // Call depending class method
        //  about advisers
        std::list< Datas::SRetraite * >::const_iterator       iteRetraite;

        for( iteRetraite = listRetraites_.begin(); iteRetraite != listRetraites_.end(); iteRetraite++ )
            saveToXMLRetraites( xmlNode, pElemRet, *iteRetraite );

        CParser::createTextNode( xmlNode, "PEEOrganisme", sPEEOrganisme_, pElem );
        CParser::createTextNode( xmlNode, "PEEDate", dPEEDate_.toString( Qt::ISODate ), pElem );
        CParser::createTextNode( xmlNode, "Interessement", bInteressement_ ? "oui" : "non", pElem );
        CParser::createTextNode( xmlNode, "VersementN1", string.setNum( uVersementN1_ ) , pElem );
        CParser::createTextNode( xmlNode, "VersementN2", string.setNum( uVersementN2_ ) , pElem );

        //  about incoming
        Salarie_.saveToXML( xmlNode, pElem );
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }

    return 0;
}

//-----------------------------------------------------------------------------
// Virtual function for XML management
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::saveEmployesToXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode ) const
{
    XERCES_CPP_NAMESPACE_USE
    QString string;
    std::list< const CPersonnes * >::const_iterator ite;

    for( ite = listEmployes_.begin(); ite != listEmployes_.end(); ite++ )
        g_ParserEntses->createTextNode( "Employe", string.setNum( (*ite)->getID() ), xmlNode );
}

//-----------------------------------------------------------------------------
// Virtual function for XML management
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::loadEmployesFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE
    DOMNodeList *listNodes = xmlNode->getChildNodes();

    XMLSize_t size = listNodes->getLength();

    // Viewing list of nodes
    for( XMLSize_t i = 0; i < size; i++ )
    {
        const char *pt = 0;
        DOMNode *ptNode = listNodes->item( i );

        pt = CParser::getTextNode( ptNode, "Employe" );
        if( pt != 0 )
        {
            ushort usBeneficiaireID = XMLString::parseInt( XMLString::transcode( pt ) );

            const CPersonnes *pPer = CPersonnes::getItemFromID( usBeneficiaireID );            

            if( pPer )
            {
                CPersonnes *pPerC = const_cast< CPersonnes* >( pPer );
                pPerC->setEntreprise( this );
                addEmploye( *pPer );
            }
        }
    }
}

//-----------------------------------------------------------------------------
// Virtual function for XML management
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::saveGerantsToXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode ) const
{
    XERCES_CPP_NAMESPACE_USE
    QString string;
    std::list< t_PersonneGerant * >::const_iterator ite;

    for( ite = listGerants_.begin(); ite != listGerants_.end(); ite++ )
    {
        if( (*ite)->pPersonne_ != 0 )
        {
            XERCES_CPP_NAMESPACE::DOMElement *pElem;

            pElem = g_ParserEntses->createElementNode( "Gerant", xmlNode, "ID", string.setNum( (*ite)->pPersonne_->getID() ) );
            pElem->setAttribute( XMLString::transcode( "Parts" ), XMLString::transcode( string.setNum( (*ite)->ePart_ ) ) );
        }
    }
}

//-----------------------------------------------------------------------------
// Virtual function for XML management
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::loadGerantsFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE
    DOMNodeList *listNodes = xmlNode->getChildNodes();

    XMLSize_t size = listNodes->getLength();

    // Viewing list of nodes
    for( XMLSize_t i = 0; i < size; i++ )
    {
        DOMNode *ptNode = listNodes->item( i );

        if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Gerant" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
        {
            int iId;
            t_ePartsGerant eParts;

            iId = CParser::getIntElementAttribute( ptNode, "ID" );
            if( iId == -1 )
                continue ;
            eParts = ( t_ePartsGerant ) CParser::getIntElementAttribute( ptNode, "Parts" );

            const CPersonnes *pPer = CPersonnes::getItemFromID( iId );

            if( pPer != 0 )
            {
                CPersonnes *pPerC = const_cast< CPersonnes* >( pPer );
                
                pPerC->setEntreprise( this );
                addGerant( *pPer, eParts );
            }
        }
    }
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.lineEditRaisonSociale->setText( sRaisonSociale_ );

    switch( eSatus_ )
    {
        case eSARL: { amon.comboBoxFormeJuridique->setCurrentItem ( 0 ); break ; }
        case eSA: { amon.comboBoxFormeJuridique->setCurrentItem ( 1 ); break ; }
        case eSAS: { amon.comboBoxFormeJuridique->setCurrentItem ( 2 ); break ; }
        case eEURL: { amon.comboBoxFormeJuridique->setCurrentItem ( 3 ); break ; }
        case eSCP: { amon.comboBoxFormeJuridique->setCurrentItem ( 4 ); break ; }
        case eAutreStatus: { amon.comboBoxFormeJuridique->setCurrentItem ( 5 ); break ; }
        default: qDebug( "CEntreprise::loadInQT: Unsupported case" );
    }

    if( eSatus_ == eAutreStatus )
        amon.lineEditAutreFormeJuridique->setText( sAutre_ );

    amon.lineEditEntrepriseCodePostal->setText( Adresse_.sCodePostal_ );
    amon.lineEditEntrepriseComplement->setText( Adresse_.sComplement_ );
    amon.lineEditEntrepriseNomRue->setText( Adresse_.sRue_ );
    amon.lineEditEntrepriseVille->setText( Adresse_.sVille_ );

    amon.lineEditCodeNaf->setText( sCodeNAF_ );
    amon.lineEditNumSiret->setText( sNumSiret_ );
    amon.lineEditActivite->setText( sActivite_ );
    amon.lineEditConventionCollective->setText( sConvention_ );
    if( bAGA_ )
        amon.checkBoxAGA->setChecked( true );
    if( bCGA_ )
        amon.checkBoxCGA->setChecked( true );

    amon.lineEditColGer->setText( string.setNum( usCollegueGerance_ ) );
    amon.lineEditProche->setText( string.setNum( usProche_ ) );
    amon.lineEditAutre->setText( string.setNum( usAutre_ ) );

    amon.lineEditBenefN1->setText( string.setNum( uBeneficesN1_ ) );
    amon.lineEditBenefN2->setText( string.setNum( uBeneficesN2_ ) );

    amon.comboBoxRegimeFiscal->setCurrentItem( eRegimeFiscale_ ==  eImpotRevenus ? 0 : 1 );

    amon.lineEditDateCreation->setText( sDateCreation_ );
    amon.comboBoxSuiteEco->setCurrentItem( bSuiteEconomique_ ? 0 : 1 );
    amon.lineEditTelEnses->setText( sTelephone_ );
    amon.lineEditFaxEntses->setText( sFax_ );
    if( sSiteInternet_ != "" )
        amon.lineEdithttpentses->setText( sSiteInternet_ );
    else
        amon.lineEdithttpentses->setText( "Site internet" );

    t_listRetraites::const_iterator ite = listRetraites_.begin();
    for( ; ite != listRetraites_.end(); ite++ )
    {
        QListViewItem *item = new QListViewItem( amon.listViewEntrepriseRetraite,
            (*ite)->sContrat_,
            (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "",
            (*ite)->sCollegue_,
            string.setNum( (*ite)->usTA_ ),
            string.setNum( (*ite)->usTB_ ),
            string.setNum( (*ite)->usTC_ ),
            (*ite)->dEffet_.toString( Qt::LocalDate ),
            string.setNum( (*ite)->usFisc82_ ) );
        item->setText( 8, string.setNum( (*ite)->usFisc82AD_ ) );
        item->setText( 9, string.setNum( (*ite)->usFisc82SD_ ) );
        item->setText( 10, string.setNum( (*ite)->usFisc39_ ) );
    }

    // "Retraite" fields
    amon.lineEditOrganisme->setText( sPEEOrganisme_ );
    amon.dateEditEntreprisePEE->setDate( dPEEDate_ );
    amon.comboBoxEntrepriseInteressement->setCurrentItem( bInteressement_ ? 0 : 1 );
    amon.lineEditRetraiteInteressementN1->setText( string.setNum( uVersementN1_ ) );
    amon.lineEditRetraiteInteressementN2->setText( string.setNum( uVersementN2_ ) );

    loadEmployesInListView( amon.listViewEntsesParticipants );
    loadGerantsInListView( amon.listViewDirigeants );
    loadGerantsInListView( amon.listView29 );
    Salarie_.loadInQT( amon );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::copyFromQT( const dlgAmonSoft &amon )
{
    sRaisonSociale_         = amon.lineEditRaisonSociale->text();

    switch( amon.comboBoxFormeJuridique->currentItem() )
    {
        case 0: { eSatus_ = eSARL; break ; }
        case 1: { eSatus_ = eSA; break ; }
        case 2: { eSatus_ = eSAS; break ; }
        case 3: { eSatus_ = eEURL; break ; }
        case 4: { eSatus_ = eSCP; break ; }
        case 5: { eSatus_ = eAutreStatus; break ; }
        default: qDebug( "CEntreprise::copyFromQT: Unsupported case" );
    }

    if( eSatus_ == eAutreStatus )
        sAutre_             = amon.lineEditAutreFormeJuridique->text();
    Adresse_.sCodePostal_   = amon.lineEditEntrepriseCodePostal->text();
    Adresse_.sComplement_   = amon.lineEditEntrepriseComplement->text();
    Adresse_.sRue_          = amon.lineEditEntrepriseNomRue->text();
    Adresse_.sVille_        = amon.lineEditEntrepriseVille->text();

    sCodeNAF_               = amon.lineEditCodeNaf->text();
    sNumSiret_              = amon.lineEditNumSiret->text();
    sActivite_              = amon.lineEditActivite->text();
    sConvention_            = amon.lineEditConventionCollective->text();
    bAGA_                   = amon.checkBoxAGA->isChecked();
    bCGA_                   = amon.checkBoxCGA->isChecked();

    usCollegueGerance_      = get_ushort_from_qlineedit( amon.lineEditColGer );
    usProche_               = get_ushort_from_qlineedit( amon.lineEditProche );
    usAutre_                = get_ushort_from_qlineedit( amon.lineEditAutre );

    uBeneficesN1_           = get_uint_from_qlineedit( amon.lineEditBenefN1 );
    uBeneficesN2_           = get_uint_from_qlineedit( amon.lineEditBenefN2 );

    eRegimeFiscale_         = amon.comboBoxRegimeFiscal->currentItem() == 0 ? 
                                eImpotRevenus : eImpotSociete;

    sDateCreation_          = amon.lineEditDateCreation->text();
    bSuiteEconomique_       = amon.comboBoxSuiteEco->currentItem() == 0 ? true : false;
    sTelephone_             = amon.lineEditTelEnses->text();
    sFax_                   = amon.lineEditFaxEntses->text();
    sSiteInternet_          = amon.lineEdithttpentses->text();

    // "Retraite" fields
    sPEEOrganisme_          = amon.lineEditOrganisme->text();
    dPEEDate_               = amon.dateEditEntreprisePEE->date();
    bInteressement_         = amon.comboBoxEntrepriseInteressement->currentItem() == 0 ? true : false;
    uVersementN1_           = get_uint_from_qlineedit( amon.lineEditRetraiteInteressementN1 );
    uVersementN2_           = get_uint_from_qlineedit( amon.lineEditRetraiteInteressementN2 );
      
    Salarie_.copyFromQT( amon );
}

//-----------------------------------------------------------------------------
// Add "employe"
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CEntreprise::addEmploye( const CPersonnes &pPersonne )
{
    // TODO: Do not allow double entries of the same personne !
    listEmployes_.push_back( &pPersonne );
    return 1;
}


//-----------------------------------------------------------------------------
// Add boss
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CEntreprise::addGerant( const CPersonnes &pPersonne, t_ePartsGerant eParts )
{
    // TODO: Do not allow double entries of the same personne !
    t_PersonneGerant    *p = new struct s_PersonneGerant;

    p->pPersonne_   = &pPersonne;
    p->ePart_       = eParts;

    mAssert( p->pPersonne_->getID() > 0, "p->pPersonne_->getID() > 0" );

    listGerants_.push_back( p );
    return 1;
}

//-----------------------------------------------------------------------------
// Remove "employe"
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::removeEmploye( ushort uId )
{
    std::list< const CPersonnes * >::const_iterator ite;

    for( ite = listEmployes_.begin(); ite != listEmployes_.end(); ite++ )
        if( (*ite)->getID() == uId )
        {
            CPersonnes *pPer = const_cast< CPersonnes* >( *ite );
            pPer->removeEntreprise();
            listEmployes_.remove( *ite );
            return ;
        }
}

//-----------------------------------------------------------------------------
// Remove boss
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::removeGerant( ushort uId )
{
    std::list< t_PersonneGerant * >::const_iterator ite;

    for( ite = listGerants_.begin(); ite != listGerants_.end(); ite++ )
        if( (*ite)->pPersonne_->getID() == uId )
        {
            CPersonnes *pPer = const_cast< CPersonnes* >( (*ite)->pPersonne_ );
            pPer->removeEntreprise();
            listGerants_.remove( *ite );
            delete *ite;
            return ;
        }
}

//-----------------------------------------------------------------------------
// Remove "employe"
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::removeEmploye( CPersonnes *p )
{
    listEmployes_.remove( p );
}

//-----------------------------------------------------------------------------
// Remove boss
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::removeGerant( CPersonnes *p )
{
    std::list< t_PersonneGerant * >::const_iterator ite;

    for( ite = listGerants_.begin(); ite != listGerants_.end(); ite++ )
        if( (*ite)->pPersonne_ == p )
        {
            p->removeEntreprise();
            listGerants_.remove( *ite );
            delete *ite;
            return ;
        }
}

//-----------------------------------------------------------------------------
// Show list in QListView
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::loadEmployesInListView( QListView *list ) const
{
    mAssert( list != 0, "list != 0" );

    list->clear();
    std::list< const CPersonnes * >::const_iterator ite;

    for( ite = listEmployes_.begin(); ite != listEmployes_.end(); ite++ )
    {
        QString string;
        QListViewItem item = new QListViewItem( list,
            (*ite)->getNom(),
            (*ite)->getPrenom(),
            (*ite)->getDateNaissance().toString( Qt::ISODate ),
            string.setNum( (*ite)->getID() ) );
    }
}

//-----------------------------------------------------------------------------
// Show list in QListView
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEntreprise::loadGerantsInListView( QListView *list ) const
{
    mAssert( list != 0, "list != 0" );

    list->clear();

    std::list< t_PersonneGerant * >::const_iterator ite;

    for( ite = listGerants_.begin(); ite != listGerants_.end(); ite++ )
    {
        if( (*ite)->pPersonne_ == 0 )
        {
            qDebug( "Gerant invalide dans CEntreprise::listGerants_" );
            break ;
        }
        QString sParts, string;

        switch( (*ite)->ePart_ )
        {
            case eGerantMajoritaire: { sParts = "Majoritaire"; break ; }
            case eGerantMinoritaire: { sParts = "Minoritaire"; break ; }
            case eGerantAssocie: { sParts = "Associe"; break ; }
            default: { sParts = "Inconnu"; break ; }
        }

        QListViewItem item = new QListViewItem( list,
            (*ite)->pPersonne_->getNom(),
            (*ite)->pPersonne_->getPrenom(),
            (*ite)->pPersonne_->getDateNaissance().toString( Qt::ISODate ),
            sParts,
            string.setNum( (*ite)->pPersonne_->getID() ) );
    }
}

//-----------------------------------------------------------------------------
// CSalarie constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CSalarie::CSalarie()
{
    /*
     * Init
     */
    usNbCadres_ = 0;
    usNbETAM_ = 0;
    usNbNonCadres_ = 0;
    usNbAutre_ = 0;
    bDeleguePersonnel_ = false;
    bComiteEntreprise_ = false;
    bInteressement_ = false;
    usARRCOPS_ = 0;
    usARRCOPP_ = 0;
    usAGIRCPS_ = 0;
    usAGIRCPP_ = 0;
    usAutresPS_ = 0;
    usAutresPP_ = 0;
    usCongesPayes_ = 0;
    usTauxAccident_ = 0;
    uTaxeTransports_ = 0;
}

//-----------------------------------------------------------------------------
// CSalarie destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CSalarie::~CSalarie()
{
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CSalarie::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    QString string;

    if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Salarie" ) )
        return 0;

    DOMNodeList *listNodes = xmlNode->getChildNodes();

    XMLSize_t size = listNodes->getLength();

    // Viewing list of nodes
    for( XMLSize_t i = 0; i < size; i++ )
    {
        DOMNode *ptNode = listNodes->item( i );
        const char *pt;

        pt = CParser::getTextNode( ptNode, "NbCadres" );
        if( pt != 0 )
        {
            usNbCadres_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }       

        pt = CParser::getTextNode( ptNode, "NbNonCadres" );
        if( pt != 0 )
        {
            usNbNonCadres_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "NbETAM" );
        if( pt != 0 )
        {
            usNbETAM_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "NbAutre" );
        if( pt != 0 )
        {
            usNbAutre_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "ARRCOPS" );
        if( pt != 0 )
        {
            usARRCOPS_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "ARRCOPP" );
        if( pt != 0 )
        {
            usARRCOPP_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "AGIRCPS" );
        if( pt != 0 )
        {
            usAGIRCPS_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "AGIRCPP" );
        if( pt != 0 )
        {
            usAGIRCPP_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "AutresPS" );
        if( pt != 0 )
        {
            usAutresPS_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "AutresPP" );
        if( pt != 0 )
        {
            usAutresPP_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "CongesPayes" );
        if( pt != 0 )
        {
            usCongesPayes_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "TauxAccident" );
        if( pt != 0 )
        {
            usTauxAccident_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "TaxeTransports" );
        if( pt != 0 )
        {
            uTaxeTransports_ = XMLString::parseInt( XMLString::transcode( pt ) );
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "AInteressement" );
        if( pt != 0 )
        {
            if( strcmp( "oui", pt ) == 0 )
                bInteressement_ = true;
            else bInteressement_ = false;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "Interessement" );
        if( pt != 0 )
        {
            sInteressement_ = pt;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "DeleguePersonnel" );
        if( pt != 0 )
        {
            if( strcmp( "oui", pt ) == 0 )
                bDeleguePersonnel_ = true;
            else bDeleguePersonnel_ = false;
            continue ;
        }

        pt = CParser::getTextNode( ptNode, "ComiteEntreprise" );
        if( pt != 0 )
        {
            if( strcmp( "oui", pt ) == 0 )
                bComiteEntreprise_ = true;
            else bComiteEntreprise_ = false;
            continue ;
        }
    }

    return 0;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CSalarie::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
    XERCES_CPP_NAMESPACE_USE

    try {
        QString string;

        DOMElement    *pElem = CParser::createElementNode( xmlNode, "Salarie", node );
        CParser::createTextNode( xmlNode, "NbCadres", string.setNum( usNbCadres_ ), pElem );
        CParser::createTextNode( xmlNode, "NbNonCadres", string.setNum( usNbNonCadres_ ), pElem );
        CParser::createTextNode( xmlNode, "NbETAM", string.setNum( usNbETAM_ ), pElem );
        CParser::createTextNode( xmlNode, "NbAutre", string.setNum( usNbAutre_ ), pElem );
        CParser::createTextNode( xmlNode, "DeleguePersonnel", bDeleguePersonnel_ ? "oui" : "non", pElem );
        CParser::createTextNode( xmlNode, "ComiteEntreprise", bComiteEntreprise_ ? "oui" : "non", pElem );
        CParser::createTextNode( xmlNode, "AInteressement", bInteressement_? "oui" : "non", pElem );
        if( bInteressement_ )
            CParser::createTextNode( xmlNode, "Interessement", sInteressement_, pElem );
        CParser::createTextNode( xmlNode, "ARRCOPS", string.setNum( usARRCOPS_ ), pElem );
        CParser::createTextNode( xmlNode, "ARRCOPP", string.setNum( usARRCOPP_ ), pElem );
        CParser::createTextNode( xmlNode, "AGIRCPS", string.setNum( usAGIRCPS_ ), pElem );
        CParser::createTextNode( xmlNode, "AGIRCPP", string.setNum( usAGIRCPP_ ), pElem );
        CParser::createTextNode( xmlNode, "AutresPS", string.setNum( usAutresPS_ ), pElem );
        CParser::createTextNode( xmlNode, "AutresPP", string.setNum( usAutresPP_ ), pElem );
        CParser::createTextNode( xmlNode, "CongesPayes", string.setNum( usCongesPayes_ ), pElem );
        CParser::createTextNode( xmlNode, "TauxAccident", string.setNum( usTauxAccident_ ), pElem );
        CParser::createTextNode( xmlNode, "TaxeTransports", string.setNum( uTaxeTransports_ ), pElem );

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
void CSalarie::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.lineEditNbCadres->setText( string.setNum( usNbCadres_ ) );
    amon.lineEditNbETAM->setText( string.setNum( usNbETAM_ ) );
    amon.lineEditNbNonCadres->setText( string.setNum( usNbNonCadres_ ) );
    amon.lineEditNbAutreColleges->setText( string.setNum( usNbAutre_ ) );

    if( bDeleguePersonnel_ )
        amon.comboBoxDeleguePersonnel->setCurrentItem( 0 );
    else amon.comboBoxDeleguePersonnel->setCurrentItem( 1 );

    if( bComiteEntreprise_ )
        amon.comboBoxComiteEntreprise->setCurrentItem( 0 );
    else amon.comboBoxComiteEntreprise->setCurrentItem( 1 );

    if( bInteressement_ )
        amon.comboBoxInteressement->setCurrentItem( 0 );
    else amon.comboBoxInteressement->setCurrentItem( 1 );

    if( bInteressement_ )
        amon.lineEditInteressementMod->setText( sInteressement_ );

    amon.lineEditARRCOPS->setText( string.setNum( usARRCOPS_ ) );
    amon.lineEditARRCOPP->setText( string.setNum( usARRCOPP_ ) );
    amon.lineEditAGIRCPS->setText( string.setNum( usAGIRCPS_ ) );
    amon.lineEditAGIRCPP->setText( string.setNum( usAGIRCPP_ ) );
    amon.lineEditAutrePS->setText( string.setNum( usAutresPS_ ) );
    amon.lineEditAutrePP->setText( string.setNum( usAutresPP_ ) );

    amon.lineEditCaisseCongesPayes->setText( string.setNum( usCongesPayes_ ) );
    amon.lineEditTauxAccidentTravail->setText( string.setNum( usTauxAccident_ ) );
    amon.lineEditTaxeTransport->setText( string.setNum( uTaxeTransports_ ) );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CSalarie::copyFromQT( const dlgAmonSoft &amon )
{
    usNbCadres_             = get_ushort_from_qlineedit( amon.lineEditNbCadres );
    usNbETAM_               = get_ushort_from_qlineedit( amon.lineEditNbETAM );
    usNbNonCadres_          = get_ushort_from_qlineedit( amon.lineEditNbNonCadres );
    usNbAutre_              = get_ushort_from_qlineedit( amon.lineEditNbAutreColleges );
    bDeleguePersonnel_      = amon.comboBoxDeleguePersonnel->currentItem() == 0 ? true : false;
    bComiteEntreprise_      = amon.comboBoxComiteEntreprise->currentItem() == 0 ? true : false;
    bInteressement_         = amon.comboBoxInteressement->currentItem() == 0 ? true : false;
    if( bInteressement_ )
        sInteressement_     = amon.lineEditInteressementMod->text();
    usARRCOPS_              = get_ushort_from_qlineedit( amon.lineEditARRCOPS );
    usARRCOPP_              = get_ushort_from_qlineedit( amon.lineEditARRCOPP );
    usAGIRCPS_              = get_ushort_from_qlineedit( amon.lineEditAGIRCPS );
    usAGIRCPP_              = get_ushort_from_qlineedit( amon.lineEditAGIRCPP );
    usAutresPS_             = get_ushort_from_qlineedit( amon.lineEditAutrePS );
    usAutresPP_             = get_ushort_from_qlineedit( amon.lineEditAutrePP );
    usCongesPayes_          = get_ushort_from_qlineedit( amon.lineEditCaisseCongesPayes );
    usTauxAccident_         = get_ushort_from_qlineedit( amon.lineEditTauxAccidentTravail );
    uTaxeTransports_        = get_uint_from_qlineedit( amon.lineEditTaxeTransport );
}