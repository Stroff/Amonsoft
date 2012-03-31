/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: CFamille.cpp,v 1.21 2006/11/10 10:48:07 pascal Exp $
 * $Log: CFamille.cpp,v $
 * Revision 1.21  2006/11/10 10:48:07  pascal
 * - V�rification de la coh�rence des donn�es lors de la validation. Pour le moment, on l�ve simplement une exception si l'on ne passe pas des entiers l� o� ils sont attendus.
 *
 * Revision 1.20  2006/10/13 14:39:46  pascal
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
 * Revision 1.19  2006/10/09 10:06:08  pascal
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
 * Revision 1.18  2006/08/04 11:21:48  pascal
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
 * Revision 1.17  2006/05/23 16:06:40  pascal
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
 * Revision 1.16  2006/05/12 16:22:43  pascal
 * Version 0.1 build 14
 * - Le fond de la form principale passe au bleu
 * - [BUG] : Probl�me avec le chargement des dates depuis l'XML : Les dates sont d�sormais au format ISO
 *
 * Revision 1.15  2006/04/29 16:29:28  pascal
 * Version 0.1 build 13
 * - Correction d'un bug avec les listes 'static' qui �taient partag�es
 * - Suppression des boutons "Valider" & "Rester"
 * - Modification des images des boutons
 * - Personnes et Entreprises ne sont plus manipul� que par Id
 * - Correction de bug : suppression de la liste des retraites
 * - R�activation de la sauvegarde manuel et correction des bugs qui ont conduit � sa d�sactivation
 *
 * Revision 1.14  2006/04/21 00:08:16  pascal
 * Version 0.1.12
 *
 * - correction du probl�me li�e au reset des listes dynamique.
 * - CPersonne ne cr�e par forc�mment un CFamille (� surveiller !)
 * - nouvelle image pour les prospects
 * - correction bugs mineurs
 *
 * Revision 1.13  2005/12/27 10:28:04  pascal
 * - Release 1.0.6 (build 1 & 2)
 * - Nouveaux champs pour les particuliers
 * - Corrections de bugs chargement XML / sauvegarde XML
 * - Corrections de bugs chargement QT / sauvegardes QT
 * - Modification de l'installeur pour ne pas �craser les fichiers de donn�es
 * - Modification de la mani�re dont sont g�r�s les QDate
 * - Correction du bug avec le slot DelAssuranceVie
 * - TODO : m�j
 * - Liens b�n�ficiaire / prospect corrig�s
 *
 * Revision 1.12  2005/12/18 19:30:59  pascal
 * - CFamille est d�sormais enregistr� dans un fichier
 * - Ajout dans main.cpp/h de ParserFamille
 * - CPersonne.savetoXML appel d�sormais l'enregistrement du CFamille correspondant
 * - Ajout dans main.cpp de la fonction de chargement des Familles
 * - amonsoft.ui.h: Ajout dans ChargerPersonne du code permettant de remplir la comboBox du conjoint
 * - Toutes les fonctions de chargements et d'enregistrement des Familles sont faites
 * - TODO: M�j de bugs
 *
 * Revision 1.11  2005/11/30 18:16:48  pascal
 * - am�liorations des chargements / enregistrements XML
 * - CFamille peut d�sormais �tre sauvegarder dans un fichier
 * - Correction de bugs pour l'XML des entses
 *
 * Revision 1.10  2005/11/12 15:04:55  pascal
 * Mise � niveau ...
 *
 * Revision 1.9  2005/10/11 22:53:57  pascal
 * - CPersonnes peut lire depuis le XML ses donn�es
 * - CConseillers aussi
 * - CEpargnes en cours !
 *
 * Revision 1.8  2005/10/11 08:12:17  pascal
 * - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
 * - les classes de donn�es n'h�ritent plus de CDatas � part CPersonne et CEntreprise
 * - les fonctions li�es � QT sont toutes impl�ment�es
 * - les fonctions saveToXML sont impl�ment�es pour les particuliers
 *
 * Revision 1.7  2005/10/05 17:14:23  pascal
 * - nouvelle structure de donn�es pour stocker les informations sur l'�pargne
 * - r�solution du probl�me li� � l'�pouse : m�thodes surcharg�es avec un bool suppl�mentaire permettant de savoir � qui l'on a � faire dans CPersonne et dans CRevenus.
 * - loadInQT impl�ment� pour toutes les classes
 *
 * Revision 1.6  2005/10/04 10:16:33  pascal
 * - ajout des dialogues dlgArretMaladie, dlgEmploi, dlgEnfant, dlgGarantieDeces et dlgRenteEducation
 * - les listes sont desormais static et public pour que l'interface puisse y ajouter des valeurs
 * - CJobs devient SJobs
 * - modification de la structure de CEnfant : plus de lien vers CFamille, nouvelle champ pr�nom et nouvelle m�thode pour acc�der aux variables
 * - les std::list sont encapsul�es dans des types pour une manipulation plus souple
 *
 * Revision 1.5  2005/09/29 15:51:27  pascal
 * - Les boutons des onglets de la section ajouter poss�dent d�sormais une image
 * - copyFromQT est bient�t impl�ment�e pour toutes les classes
 *
 * Revision 1.4  2005/09/27 15:28:11  pascal
 * - Mise en place dans CData des m�thodes relatives � l'interface : r�alisation du squelette
 *
 * Revision 1.3  2005/09/21 17:21:03  pascal
 * - Am�lioration pour la gestion des donn�es
 * - Fichier TODO
 * - Nouvelle classe de donn�es CPrevoyance
 *
 * Revision 1.2  2005/09/09 15:49:38  pascal
 * - Ajout de la classes virtuel pure CDatas
 * - Toutes les classes de Datas/ d�rive d�sormais de CDatas et d�finisse les classes virtuelles pures
 *
 */

#include <qradiobutton.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qtextedit.h>

#include <string.h>

#include "CrashReport/debug.h"
#include "CPersonnes.h"
#include "CFamille.h"
#include "XMLParser.h"

using namespace Datas;


//=============================================================================
//                                CFamille implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// CFamille constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CFamille::CFamille( const CPersonnes *pBeneficiaire )
{
    /*
     * Init
     */
    pBeneficiaire_ = pBeneficiaire;
    pConjoint_ = 0;
    usConjointId_ = 0;
    usRangMariage_ = 0;
    uDureePrecMariageBeneficiaire_ = 0;
    uDureePrecMariageConjoint_ = 0;
    TypeRelation_ = eMarie;
    RegimeMatrimonial_ = eCommunauteUniverselle;
    bDernierVivant_ = false;
    
    // This is unbelievable to have to clear list to initialize it !!
    listEnfants_.empty();
}

//-----------------------------------------------------------------------------
// CFamille destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CFamille::~CFamille()
{
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CFamille::loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    if( XMLString::equals( XMLString::transcode( xmlNode->getTagName() ), "Famille" ) )
    {
        const char *pt;

        pt = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "type" ) ) );
        if( pt )
        {
            TypeRelation_ = eNone;
            if( strcmp( pt, "Celibataire" ) == 0 )
                TypeRelation_ = eCelibataire;
            if( strcmp( pt, "Concubinage" ) == 0 )
                TypeRelation_ = eConcubinage;
            if( strcmp( pt, "Marie" ) == 0 )
                TypeRelation_ = eMarie;
            if( strcmp( pt, "Divorce" ) == 0 )
                TypeRelation_ = eDivorce;
            if( strcmp( pt, "PACS" ) == 0 )
                TypeRelation_ = ePACS;
            if( strcmp( pt, "UnionLibre" ) == 0 )
                TypeRelation_ = eUnionLibre;
            if( strcmp( pt, "Veuf" ) == 0 )
                TypeRelation_ = eVeuf;
        }

        // Load consumer informations & link
        pt = XMLString::transcode( xmlNode->getAttribute( XMLString::transcode( "ID" ) ) );
        ushort usBeneficiaireID = XMLString::parseInt( XMLString::transcode( pt ) );

        pBeneficiaire_ = CPersonnes::getItemFromID( usBeneficiaireID );
        if( pBeneficiaire_ == 0 )
            return -1;

        CPersonnes *pTemp = const_cast< CPersonnes* >( pBeneficiaire_ );
        pTemp->setFamille( this );

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );           

            pt = CParser::getTextNode( ptNode, "DureePrecMariage" );
            if( pt != 0 )
            {
                uDureePrecMariageBeneficiaire_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DureePrecMariageConjoint" );
            if( pt != 0 )
            {
                uDureePrecMariageConjoint_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "RegimeMatrimonial" );
            if( pt != 0 )
            {
                if( strcmp( pt, "CommunauteAcquets" ) == 0 )
                    RegimeMatrimonial_ = eCommunauteAcquets;
                if( strcmp( pt, "ParticipationAcquets" ) == 0 )
                    RegimeMatrimonial_ = eParticipationAcquets;
                if( strcmp( pt, "CommunauteUniverselle" ) == 0 )
                    RegimeMatrimonial_ = eCommunauteUniverselle;
                if( strcmp( pt, "SeparationBiens" ) == 0 )
                    RegimeMatrimonial_ = eSeparationBiens;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "IDConjoint" );
            if( pt != 0 )
            {
                if( strcmp( pt, "-1" ) == 0 ) pConjoint_ = 0;
                else
                {
                    usConjointId_ = XMLString::parseInt( XMLString::transcode( pt ) );
                    pConjoint_ = CPersonnes::getItemFromID( usConjointId_ );

                    if( pConjoint_ == 0 )
                        break ;

                    CPersonnes *pTemp2 = const_cast< CPersonnes* >( pConjoint_ );
                    mAssert( pTemp2 != 0, "pTemp2 != 0" );
                    pTemp2->setFamille( this );
                }
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DureeMariagePrec" );
            if( pt != 0 )
            {
                uDureePrecMariageBeneficiaire_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "RangMariage" );
            if( pt != 0 )
            {
                usRangMariage_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "NbEnfants" );
            if( pt != 0 )
            {
                usNbEnfantsBeneficiaire_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "NbEnfantsCommuns" );
            if( pt != 0 )
            {
                usNbEnfantsCommuns_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "AutresDispositions" );
            if( pt != 0 )
            {
                sAutresDispositions_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Testament" );
            if( pt != 0 )
            {
                sTestament_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DonationEntreEpoux" );
            if( pt != 0 )
            {
                sDonationEntreEpoux_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DernierVivant" );
            if( pt != 0 )
            {
                if( strcmp( pt, "oui" ) )
                    bDernierVivant_ = true;
                else bDernierVivant_ = false;
                continue ;
            }
                      
            if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Enfants" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )           
            {
                DOMNodeList *listNodes = ptNode->getChildNodes();

                XMLSize_t sizee = listNodes->getLength();

                // Viewing list of nodes
                for( XMLSize_t ii = 0; ii < sizee; ii++ )
                {
                    DOMNode *ptNodeE = listNodes->item( ii );

                    if ( XMLString::equals( XMLString::transcode( ptNodeE->getNodeName() ), "Enfant" ) )
                    {
                        CEnfants *pEnfant = new CEnfants();
                        pEnfant->loadFromXML( ptNodeE );
                        listEnfants_.push_back( pEnfant );
                    }
                }
            }
        }
    }

    return 0;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CFamille::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const
{
	XERCES_CPP_NAMESPACE_USE

	try {
		QString sRelation;
        QString string;

		// TODO: Saving informations about object here
		switch( TypeRelation_ )
		{
			case CFamille::eCelibataire:
				{ sRelation = "Celibataire"; break ; }
			case CFamille::eConcubinage:
				{ sRelation = "Concubinage"; break ; }
			case CFamille::eMarie:
				{ sRelation = "Marie" ; break ; }
			case CFamille::eDivorce:
				{ sRelation = "Divorce" ; break ; }
			case CFamille::ePACS:
				{ sRelation = "PACS" ; break ; }
			case CFamille::eUnionLibre:
				{ sRelation = "UnionLibre" ; break ; }
			case CFamille::eVeuf:
				{ sRelation = "Veuf" ; break ; }
            default: sRelation = "";
		}

		DOMElement *pElem = xmlNode->createElement( XMLString::transcode( "Famille" ) );
        pElem->setAttribute( XMLString::transcode( "type" ), XMLString::transcode( sRelation ) );
        pElem->setAttribute( XMLString::transcode( "ID" ), XMLString::transcode( string.setNum( pBeneficiaire_->getID() ) ) );

        CParser::createTextNode( xmlNode, "DureePrecMariage", sRelation.setNum( uDureePrecMariageBeneficiaire_ ), pElem );
        CParser::createTextNode( xmlNode, "DureePrecMariageConjoint", sRelation.setNum( uDureePrecMariageConjoint_ ), pElem );

		QString sRegime;
		switch( RegimeMatrimonial_ )
		{
			case eCommunauteAcquets: { sRegime = "CommunauteAcquets"; break ;  }
			case eParticipationAcquets: { sRegime = "ParticipationAcquets"; break ; }
			case eCommunauteUniverselle: { sRegime = "CommunauteUniverselle"; break ; }
			case eSeparationBiens: { sRegime = "SeparationBiens"; break ; }
			default: qDebug( "CFamille::loadInQT( const dlgAmonSoft &amon ): Unsupported case" );
		}

		CParser::createTextNode( xmlNode, "RegimeMatrimonial", sRegime, pElem );
		CParser::createTextNode( xmlNode, "Testament", sTestament_, pElem );
		CParser::createTextNode( xmlNode, "DonationEntreEpoux", sDonationEntreEpoux_, pElem );
		CParser::createTextNode( xmlNode, "AutresDispositions", sAutresDispositions_, pElem );
        CParser::createTextNode( xmlNode, "DernierVivant", bDernierVivant_ ? "oui" : "non", pElem );
        CParser::createTextNode( xmlNode, "RangMariage", string.setNum( usRangMariage_ ), pElem );
        CParser::createTextNode( xmlNode, "NbEnfants", string.setNum( usNbEnfantsBeneficiaire_ ), pElem );
        CParser::createTextNode( xmlNode, "NbEnfantsCommuns", string.setNum( usNbEnfantsCommuns_ ), pElem );
        CParser::createTextNode( xmlNode, "Testament", sTestament_, pElem );
        CParser::createTextNode( xmlNode, "DonationEntreEpoux", sDonationEntreEpoux_, pElem );

		//	Not need pConjoint_ is an CPersonne, which must be ref in global datas
        if( pConjoint_ )
            CParser::createTextNode( xmlNode, "IDConjoint", string.setNum( pConjoint_->getID() ) , pElem );
        else
            // No wife, we set an invalide id !
            CParser::createTextNode( xmlNode, "IDConjoint", "-1" , pElem );

        CParser::createTextNode( xmlNode, "DureeMariagePrec", string.setNum( uDureePrecMariageBeneficiaire_ ), pElem );

		DOMElement *pElemEnfant = CParser::createElementNode( xmlNode, "Enfants", pElem );

		//  Call depending class method        
		std::list< Datas::CEnfants* >::const_iterator   iteEnfants;

		for( iteEnfants = listEnfants_.begin(); iteEnfants != listEnfants_.end(); iteEnfants++ )
			(*iteEnfants)->saveToXML( xmlNode, pElemEnfant );

        DOMElement *node = xmlNode->getDocumentElement();
		node->appendChild( pElem );
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
void CFamille::copyFromQT( const dlgAmonSoft &amon )
{
    // Relation type
    TypeRelation_ = (enum Relation) amon.comboBoxEtatCivilSituationFamilliale->currentItem();

    // Time of last relations
    uDureePrecMariageBeneficiaire_      = get_uint_from_qlineedit( amon.lineEditFamilleDureeMariagesPrecedentsMonsieur );
    uDureePrecMariageConjoint_          = get_uint_from_qlineedit( amon.lineEditFamilleDureeMariagesPrecedentsMadame );
    usRangMariage_                      = get_ushort_from_qlineedit( amon.lineEditFamilleRgMariage );
    if( amon.checkBoxFamilleDonationDernierVivant->isChecked() )
        bDernierVivant_ = true;

    usNbEnfantsBeneficiaire_            = get_ushort_from_qlineedit( amon.lineEditFamilleNombreEnfantsMonsieur );
    usNbEnfantsProspect_                = get_ushort_from_qlineedit( amon.lineEditFamilleNombreEnfantsMadame );
    usNbEnfantsCommuns_                 = get_ushort_from_qlineedit( amon.lineEditFamilleNombreEnfantsCommuns );

    // Shared relation
    switch( amon.comboBoxFamilleRegimeMatrimonial->currentItem() )
    {
        case 0: RegimeMatrimonial_ = CFamille::eCommunauteAcquets; break ;
        case 1: RegimeMatrimonial_ = CFamille::eParticipationAcquets; break ;
        case 2: RegimeMatrimonial_ = CFamille::eCommunauteUniverselle; break ;
        case 3: RegimeMatrimonial_ = CFamille::eSeparationBiens; break ;
        default: qDebug( "CFamille::copyFromQT( const dlgAmonSoft &amon ): Unsupported case" );
    }

    sTestament_                         = amon.lineEditFamilleDispositionsTestamentaires->text();
    sDonationEntreEpoux_                = amon.lineEditFamilleDonationEntreEpoux->text();
    sAutresDispositions_                = amon.textEditFamilleAutreDispo->text();
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CFamille::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.comboBoxEtatCivilSituationFamilliale->setCurrentItem( TypeRelation_ );

    amon.lineEditFamilleDureeMariagesPrecedentsMonsieur->setText( string.setNum( uDureePrecMariageBeneficiaire_ ) );
    amon.lineEditFamilleDureeMariagesPrecedentsMadame->setText( string.setNum( uDureePrecMariageConjoint_ ) );
    amon.lineEditFamilleRgMariage->setText( string.setNum( usRangMariage_ ) );
    amon.checkBoxFamilleDonationDernierVivant->setChecked( bDernierVivant_ );

    amon.lineEditFamilleNombreEnfantsMonsieur->setText( string.setNum( usNbEnfantsBeneficiaire_ ) );
    amon.lineEditFamilleNombreEnfantsMadame->setText( string.setNum( usNbEnfantsProspect_ ) );
    amon.lineEditFamilleNombreEnfantsCommuns->setText( string.setNum( usNbEnfantsCommuns_ ) );

    switch( RegimeMatrimonial_ )
    {
        case eCommunauteAcquets: { amon.comboBoxFamilleRegimeMatrimonial->setCurrentItem( 0 ); break ;  }
        case eParticipationAcquets: { amon.comboBoxFamilleRegimeMatrimonial->setCurrentItem( 1 ); break ; }
        case eCommunauteUniverselle: { amon.comboBoxFamilleRegimeMatrimonial->setCurrentItem( 2 ); break ; }
        case eSeparationBiens: { amon.comboBoxFamilleRegimeMatrimonial->setCurrentItem( 3 ); break ; }
        default: qDebug( "CFamille::loadInQT( const dlgAmonSoft &amon ): Unsupported case" );
    }

    amon.lineEditFamilleDispositionsTestamentaires->setText( sTestament_ );
    amon.lineEditFamilleDonationEntreEpoux->setText( sDonationEntreEpoux_ );
    amon.textEditFamilleAutreDispo->setText( sAutresDispositions_ );

    // Reset list
    amon.listViewEnfants->clear();

    if( pBeneficiaire_->getID() != -1 )
    {
        //  Call depending class method
        std::list< Datas::CEnfants* >::const_iterator   iteEnfants;

        for( iteEnfants = listEnfants_.begin(); iteEnfants != listEnfants_.end(); iteEnfants++ )
        {
            (*iteEnfants)->loadInQT( amon );
            qDebug( "Load Enfant" );
        }
    }

    if( pConjoint_ )
        pConjoint_->loadInQT( amon, true );
}

//=============================================================================
//                                CEnfants implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// CEnfants destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CEnfants::~CEnfants()
{
    bACharge_ = true;
    bEnEtudes_ = true;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEnfants::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *ptNode )
{
    XERCES_CPP_NAMESPACE_USE

    if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Enfant" ) 
        && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
    {
        const char *pt;

        sNom_ = CParser::getElementAttribute( ptNode, "Nom" );
        sPrenom_ = CParser::getElementAttribute( ptNode, "Prenom" );

        pt = CParser::getElementAttribute( ptNode, "DateNaissance" );
        if( pt )
            dNaissance_ = QDate::fromString( pt, Qt::ISODate );

        pt = CParser::getElementAttribute( ptNode, "ACharge" );
        if( pt )
        {
            if( strcmp( "oui", pt ) == 0 )
                bACharge_ = true;
            else bACharge_ = false;
        }

        pt = CParser::getElementAttribute( ptNode, "EnEtude" );
        if( pt )
        {
            if( strcmp( "oui", pt ) == 0 )
                bEnEtudes_ = true;
            else bEnEtudes_ = false;
        }
    }
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEnfants::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try {
		DOMElement *pElem = xmlNode->createElement( XMLString::transcode( "Enfant" ) );
		pElem->setAttribute( XMLString::transcode( "Nom" ), XMLString::transcode( sNom_ ) );
		pElem->setAttribute( XMLString::transcode( "Prenom" ), XMLString::transcode( sPrenom_ ) );
		pElem->setAttribute( XMLString::transcode( "DateNaissance" ), XMLString::transcode( dNaissance_.toString( Qt::ISODate ) ) );
		pElem->setAttribute( XMLString::transcode( "ACharge" ), XMLString::transcode( bACharge_ ? "oui" : "non" ) );
		pElem->setAttribute( XMLString::transcode( "EnEtude" ), XMLString::transcode( bEnEtudes_ ? "oui" : "non" ) );
		node->appendChild( pElem );
	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}	
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
inline void CEnfants::loadInQT( dlgAmonSoft &amon ) const
{
    QListViewItem *item = new QListViewItem( amon.listViewEnfants,
        sNom_,
        sPrenom_,
        dNaissance_.toString( Qt::ISODate ),
        bACharge_ ? "oui" : "non",
        bEnEtudes_ ? "oui" : "non",
        sNote_ );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CEnfants::copyFromQT( const dlgAmonSoft &amon )
{ /* Empty */ }
