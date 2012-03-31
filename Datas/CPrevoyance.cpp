/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CPrevoyance.cpp,v 1.20 2006/11/10 10:48:07 pascal Exp $
* $Log: CPrevoyance.cpp,v $
* Revision 1.20  2006/11/10 10:48:07  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
* Revision 1.19  2006/11/09 13:39:48  pascal
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
* Revision 1.18  2006/05/12 16:22:43  pascal
* Version 0.1 build 14
* - Le fond de la form principale passe au bleu
* - [BUG] : Problème avec le chargement des dates depuis l'XML : Les dates sont désormais au format ISO
*
* Revision 1.17  2006/04/29 16:29:28  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.16  2006/04/21 00:08:16  pascal
* Version 0.1.12
*
* - correction du problème liée au reset des listes dynamique.
* - CPersonne ne crée par forcémment un CFamille (à surveiller !)
* - nouvelle image pour les prospects
* - correction bugs mineurs
*
* Revision 1.15  2006/04/16 22:12:25  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.14  2006/03/21 10:42:16  pascal
* *** empty log message ***
*
* Revision 1.13  2006/01/20 13:18:44  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.12  2005/12/27 10:28:04  pascal
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
* Revision 1.11  2005/11/12 15:04:56  pascal
* Mise à niveau ...
*
* Revision 1.10  2005/10/26 10:11:07  pascal
* - CEntreprise : saveToXML réalisé
* - retouches divers
*
* Revision 1.9  2005/10/12 16:11:21  pascal
* - implementation des fonctions loadFromXerces des classes CPersonnes *
* - bug: ajout de CPrevoyance dans CPersonnes
*
* Revision 1.8  2005/10/11 08:12:17  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
* Revision 1.7  2005/10/05 17:14:23  pascal
* - nouvelle structure de données pour stocker les informations sur l'épargne
* - résolution du problème lié à l'épouse : méthodes surchargées avec un bool supplémentaire permettant de savoir à qui l'on a à faire dans CPersonne et dans CRevenus.
* - loadInQT implémenté pour toutes les classes
*
* Revision 1.6  2005/10/04 10:16:33  pascal
* - ajout des dialogues dlgArretMaladie, dlgEmploi, dlgEnfant, dlgGarantieDeces et dlgRenteEducation
* - les listes sont desormais static et public pour que l'interface puisse y ajouter des valeurs
* - CJobs devient SJobs
* - modification de la structure de CEnfant : plus de lien vers CFamille, nouvelle champ prénom et nouvelle méthode pour accéder aux variables
* - les std::list sont encapsulées dans des types pour une manipulation plus souple
*
* Revision 1.5  2005/10/01 17:10:11  pascal
* - Ajout d'une nouvelle dialogue pour les emprunts
* - Ajout d'une nouvelle image pour le dialogue sur les emprunts
* - Dynamique.ui.h permet de séparer les fonctions dynamiques (données) de l'interface
* - LoadFromQT pour la prévoyance est terminée
*
* Revision 1.4  2005/09/29 15:51:28  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.3  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
*
* Revision 1.2  2005/09/27 12:22:06  pascal
* - Toutes les containeurs pour l'interface réalisée sont en place
* - Retouche de l'interface avec une barre verticale pour l'ajout
*
* Revision 1.1  2005/09/21 17:21:03  pascal
* - Amélioration pour la gestion des données
* - Fichier TODO
* - Nouvelle classe de données CPrevoyance
*
*
*/

#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qtextedit.h>

#include <stdio.h>
#include <list>

#include "main.h"
#include "CRevenus.h"
#include "CPrevoyance.h"
#include "Forms/Dynamique.ui.h"
#include "Preferences/CPreferences.h"

using namespace Datas;

//=============================================================================
//                          CPrevoyance implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// CPrevoyance constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CPrevoyance::CPrevoyance()
{
    uCotisationAnnuelle_ = 0;
    uIndiceSatisfaction_ = 0;
    listCouvertureEmprunts_.empty();
    bViager_ = false;
    eTypeViager_ = ePasEnViager;
    pCompagnie_ = 0;
}

//-----------------------------------------------------------------------------
// CPrevoyance destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CPrevoyance::~CPrevoyance()
{
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CPrevoyance::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try{
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Prevoyance" ) )
            return 0;

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();
        pCompagnie_ = 0;

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            if( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Viager" ) )
            {
                DOMElement *pTmp = static_cast< DOMElement* >( ptNode );

                std::string sViager = XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "Enviager" ) ) );
                std::string sType = XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "type" ) ) );
                
                if( sViager == "oui" )
                    bViager_ = true;
                else bViager_ = false;

                if( sType == "Personnel" )
                    eTypeViager_ = ePersonnel;
                else eTypeViager_ = eProfessionnel;
            }

            if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "ListeCouvertureEmprunt" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
            {
                DOMNodeList *plistCouvertureEmprunt = ptNode->getChildNodes();
                qDebug( XMLString::transcode( ptNode->getNodeName() ) );

                XMLSize_t asize = plistCouvertureEmprunt->getLength();
                listCouvertureEmprunts_.clear();

                for( XMLSize_t iArret = 0; iArret < asize; iArret++ )
                {
                    DOMNode    *ptNodeArr = plistCouvertureEmprunt->item( iArret );
                    if( XMLString::equals( XMLString::transcode( ptNodeArr->getNodeName() ), "Emprunt" ) )
                    {
                        struct SCouvertureEmprunt *pCouverture = new struct SCouvertureEmprunt();
                        listCouvertureEmprunts_.push_back( pCouverture );

                        DOMElement *pTmp = static_cast< DOMElement* >( ptNodeArr );
                                     
                        pCouverture->sBanque_ = XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "Banque" ) ) );
                        pCouverture->uFranchise_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Franchise" ) ) );
                        pCouverture->uMontantRemboursement_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Montant" ) ) );
                    }
                }
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "NiveauGaranties" );
            if( pt != 0 )
            {
                sNiveauGaranties_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "IndiceSatisfaction" );
            if( pt != 0 )
            {
                uIndiceSatisfaction_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "CotisationAnnuelle" );
            if( pt != 0 )
            {
                uCotisationAnnuelle_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }
            
            pt = CParser::getTextNode( ptNode, "Fiscalite" );
            if( pt != 0 )
            {
                sFiscalite_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Contrat" );
            if( pt != 0 )
            {
                sContrat_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Compagnie" );
            if( pt != 0 )
            {
                pCompagnie_ = GET_COMP_FROM_TEXT( pt );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Beneficiaires" );
            if( pt != 0 )
            {
                eBeneficiaires_ = (enum eTypeBeneficaires) XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Notes" );
            if( pt != 0 )
            {
                sNotes_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DateEffet" );
            if( pt != 0 )
            {
                dDateEffet_ = QDate::fromString( pt, Qt::ISODate );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Source" );
            if( pt != 0 )
            {
                eSanteSource_ = Concurrence;
                if( strcmp( pt, "Amon" ) == 0 )
                    eSanteSource_ = Amon;
            }

            ArretMaladie_.loadFromXML( ptNode );
            FraisGeneraux_.loadFromXML( ptNode );
            Invalidite_.loadFromXML( ptNode );
            Deces_.loadFromXML( ptNode );
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }

    return 1;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CPrevoyance::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try{

		QString string;
		DOMElement *pElem = CParser::createElementNode( xmlNode, "Prevoyance", node );

		CParser::createTextNode( xmlNode, "NiveauGaranties", sNiveauGaranties_, pElem );
		CParser::createTextNode( xmlNode, "IndiceSatisfaction", string.setNum( uIndiceSatisfaction_ ), pElem );
		CParser::createTextNode( xmlNode, "CotisationAnnuelle", string.setNum( uCotisationAnnuelle_ ), pElem );
		CParser::createTextNode( xmlNode, "Fiscalite", sFiscalite_, pElem );
		CParser::createTextNode( xmlNode, "Contrat", sContrat_, pElem );
        CParser::createTextNode( xmlNode, "Compagnie", pCompagnie_ ? pCompagnie_->sCompagnie_ : "", pElem );
		CParser::createTextNode( xmlNode, "Beneficiaires", string.setNum( eBeneficiaires_ ), pElem );
        CParser::createTextNode( xmlNode, "Notes", sNotes_, pElem );

		DOMElement *pElemViager = xmlNode->createElement( XMLString::transcode( "Viager" ) );
		pElemViager->setAttribute( XMLString::transcode( "EnViager" ), XMLString::transcode( bViager_ ? "oui" : "non" ) );
		pElemViager->setAttribute( XMLString::transcode( "type" ),
			XMLString::transcode( eTypeViager_ == ePersonnel ? "Personnel" : "Professionnel" ) );

		pElem->appendChild( pElemViager );

		CParser::createTextNode( xmlNode, "DateEffet", dDateEffet_.toString( Qt::ISODate ), pElem );
        CParser::createTextNode( xmlNode, "Source", eSanteSource_ == Amon ? "Amon" : "Concurrence", pElem );

        DOMElement  *pElemCouvertureEmprunt = CParser::createElementNode( xmlNode, "ListeCouvertureEmprunt", pElem );
        std::list< struct SCouvertureEmprunt* const >::const_iterator ite = listCouvertureEmprunts_.begin();
        for( ; ite != listCouvertureEmprunts_.end(); ite++ )
        {
            DOMElement  *pElemArretTravailL = CParser::createElementNode( xmlNode, "Emprunt", pElemCouvertureEmprunt );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Montant" ), XMLString::transcode( string.setNum( (*ite)->uMontantRemboursement_ ) ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Franchise" ), XMLString::transcode( string.setNum( (*ite)->uFranchise_ ) ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Banque" ), XMLString::transcode( (*ite)->sBanque_ ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Debut" ), XMLString::transcode( (*ite)->dDebut_ ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Terme" ), XMLString::transcode( string.setNum( (*ite)->usTerme_ ) ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "TauxMoyen" ), XMLString::transcode( string.setNum( (*ite)->usTxMoyen_ ) ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "TypeEmprunt" ), XMLString::transcode( (*ite)->sTypeEmprunt_ ) );
        }

		ArretMaladie_.saveToXML( xmlNode, pElem );
		FraisGeneraux_.saveToXML( xmlNode, pElem );
		Invalidite_.saveToXML( xmlNode, pElem );
		Deces_.saveToXML( xmlNode, pElem );

	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}
	return 1;
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CPrevoyance::copyFromQT( const dlgAmonSoft &amon )
{
    sNiveauGaranties_           = amon.lineEditPrevoyanceSanteNiveauGarantie->text();
    uIndiceSatisfaction_        = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteIndiceSatisfaction );
    uCotisationAnnuelle_        = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteCotisationAnnuelle );
    sFiscalite_                 = amon.lineEditPrevoyanceSanteFiscalite->text();
    sContrat_                   = amon.lineEditPrevoyanceSanteContrat->text();
    pCompagnie_                 = GET_COMP_FROM_TEXT( amon.comboBoxPrevoyanceSanteCompagnie->currentText() );
    eBeneficiaires_             = ( enum eTypeBeneficaires ) amon.comboBoxPrevoyanceSanteBeneficiaires->currentItem();

    // TODO: Prefer to user comBox, that's a better way
    if( amon.checkBoxPrevoyanceSanteCaractereViagerNon->isChecked() )
    {
        bViager_     = false;
        eTypeViager_ = ePasEnViager;
    }
    else
    {
        bViager_     = true;
        if( amon.checkBoxPrevoyanceSanteCaractereViagerOui
            && amon.checkBoxPrevoyanceSanteCaractereViagerPersonnel )
            eTypeViager_ = ePersonnel;
        else
            eTypeViager_ = eProfessionnel;
    }
    dDateEffet_                     = amon.dateEditPrevoyanceDateEffet->date();
    eSanteSource_                   = (enum SanteSource) amon.comboBoxPrevoyanceSanteSource->currentItem();
    sNotes_                         = amon.textEditNotesPrevoyanceSante->text();

    ArretMaladie_.copyFromQT( amon );
    FraisGeneraux_.copyFromQT( amon );
    Invalidite_.copyFromQT( amon );
    Deces_.copyFromQT( amon );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CPrevoyance::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.lineEditPrevoyanceSanteNiveauGarantie->setText( sNiveauGaranties_ );
    amon.lineEditPrevoyanceSanteIndiceSatisfaction->setText( string.setNum( uIndiceSatisfaction_ ) );
    amon.lineEditPrevoyanceSanteCotisationAnnuelle->setText( string.setNum( uCotisationAnnuelle_ ) );

    amon.lineEditPrevoyanceSanteFiscalite->setText( sFiscalite_ );
    amon.lineEditPrevoyanceSanteContrat->setText( sContrat_ );
    g_Preferences->getCompagnies().loadInQT( amon.comboBoxPrevoyanceSanteCompagnie );
    if( pCompagnie_ == 0 || pCompagnie_->bDelete_ )
        amon.comboBoxPrevoyanceSanteCompagnie->setCurrentText( "" );
    else
        amon.comboBoxPrevoyanceSanteCompagnie->setCurrentText( pCompagnie_->sCompagnie_ );
    amon.comboBoxPrevoyanceSanteBeneficiaires->setCurrentItem( eBeneficiaires_ );

    if( bViager_ == false )
        amon.checkBoxPrevoyanceSanteCaractereViagerNon->setChecked( true );
    else
    {
        amon.checkBoxPrevoyanceSanteCaractereViagerOui->setChecked( true );
        switch( eTypeViager_ )
        {
            case ePersonnel: { amon.checkBoxPrevoyanceSanteCaractereViagerPersonnel->setChecked( true ); break ; }
            case eProfessionnel: { amon.checkBoxPrevoyanceSanteCaractereViagerEntreprise->setChecked( true ); break ; }
            default: qDebug( "CPrevoyance::loadInQT: Unsupported case" );
        }
    }

    amon.dateEditPrevoyanceDateEffet->setDate( dDateEffet_ );
    amon.comboBoxPrevoyanceSanteSource->setCurrentItem( eSanteSource_ );
    amon.textEditNotesPrevoyanceSante->setText( sNotes_ );

    amon.listViewEmprunt->clear();
    std::list< struct SCouvertureEmprunt*const >::const_iterator ite = listCouvertureEmprunts_.begin();
    for( ;ite != listCouvertureEmprunts_.end(); ++ite )
    {
        QListViewItem *item = new QListViewItem( amon.listViewEmprunt,
            string.setNum( (*ite)->uMontantRemboursement_ ),
            string.setNum( (*ite)->uFranchise_ ),
            (*ite)->sBanque_,
            (*ite)->dDebut_,
            string.setNum( (*ite)->usTerme_ ),
            string.setNum( (*ite)->usTxMoyen_ ),
            (*ite)->sTypeEmprunt_ );
    }

    ArretMaladie_.loadInQT( amon );
    FraisGeneraux_.loadInQT( amon );
    Invalidite_.loadInQT( amon );
    Deces_.loadInQT( amon );   
}

//=============================================================================
//                          CArretMaladie implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CArretMaladie::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try
    {
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "ArretMaladie" ) )
            return 0;

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();
        pCompagnie_ = 0;

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "ListeArretTravail" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
            {
                listArretTravail_.clear();
                DOMNodeList *plistArretMaladie = ptNode->getChildNodes();

                XMLSize_t asize = plistArretMaladie->getLength();

                for( XMLSize_t iArret = 0; iArret < asize; iArret++ )
                {
                    DOMNode *ptNodeArr =  plistArretMaladie->item( iArret );                    
                    
                    if( XMLString::equals( XMLString::transcode( ptNodeArr->getNodeName() ), "Arret" ) )
                    {
                        struct SArretTravail *sArret = new struct SArretTravail();
                        listArretTravail_.push_back( sArret );

                        DOMElement *pTmp = static_cast< DOMElement* >( ptNodeArr );

                        sArret->uFranchise_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Franchise" ) ) );
                        sArret->uDuree_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Duree" ) ) );
                        sArret->uMontantIJ_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Montant" ) ) ) ;
                    }
                }
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "AccordAssocies" );
            if( pt != 0 )
            {
                if( strcmp( pt, "oui" ) == 0 )
                    bAccordEntreAssocies_ = true;
                else bAccordEntreAssocies_ = false;
                continue ;
            }
            
            pt = CParser::getTextNode( ptNode, "DateEffet" );
            if( pt != 0 )
            {
                dDateEffet_ = QDate::fromString( pt, Qt::ISODate );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DateMiseAJour" );
            if( pt != 0 )
            {
                dDateMiseAJour_ = QDate::fromString( pt, Qt::ISODate );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Compagnie" );
            if( pt != 0 )
            {
                pCompagnie_ = GET_COMP_FROM_TEXT( pt );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Contrat" );
            if( pt != 0 )
            {
                sContrat_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Fiscalite" );
            if( pt != 0 )
            {
                eFiscalite_ = (enum eTypeFiscalite) XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DureeAccord" );
            if( pt != 0 )
            {
                uDureeAccord_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }
            
            pt = CParser::getTextNode( ptNode, "FranchiseAccident" );
            if( pt != 0 )
            {
                uFranchiseAccident_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "FranchiseHopital" );
            if( pt != 0 )
            {
                uFranchiseHopital_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "FranchiseMaladie" );
            if( pt != 0 )
            {
                uFranchiseMaladie_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 1;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CArretMaladie::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try{
		
		QString string;

		DOMElement *pElem = CParser::createElementNode( xmlNode, "ArretMaladie", node );

		CParser::createTextNode( xmlNode, "AccordAssocies", bAccordEntreAssocies_ ? "oui" : "non", pElem );
		CParser::createTextNode( xmlNode, "DateEffet", dDateEffet_.toString( Qt::ISODate ), pElem );
		CParser::createTextNode( xmlNode, "DateMiseAJour", dDateMiseAJour_.toString( Qt::ISODate ), pElem );
        CParser::createTextNode( xmlNode, "Compagnie", pCompagnie_ ? pCompagnie_->sCompagnie_ : "", pElem );
		CParser::createTextNode( xmlNode, "Contrat", sContrat_, pElem );
		CParser::createTextNode( xmlNode, "Fiscalite", string.setNum( eFiscalite_ ), pElem );
		CParser::createTextNode( xmlNode, "DureeAccord", string.setNum( uDureeAccord_ ), pElem );
		CParser::createTextNode( xmlNode, "FranchiseAccident", string.setNum( uFranchiseAccident_ ), pElem );
		CParser::createTextNode( xmlNode, "FranchiseHopital", string.setNum( uFranchiseHopital_ ), pElem );
		CParser::createTextNode( xmlNode, "FranchiseMaladie", string.setNum( uFranchiseMaladie_ ), pElem );

        DOMElement  *pElemArretTravail = CParser::createElementNode( xmlNode, "ListeArretTravail", pElem );
        std::list< struct SArretTravail* const >::const_iterator ite = listArretTravail_.begin();
        for( ; ite != listArretTravail_.end(); ite++ )
        {
            DOMElement  *pElemArretTravailL = CParser::createElementNode( xmlNode, "Arret", pElemArretTravail );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Franchise" ), XMLString::transcode( string.setNum( (*ite)->uFranchise_ ) ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Duree" ), XMLString::transcode( string.setNum( (*ite)->uDuree_ ) ) );
            pElemArretTravailL->setAttribute( XMLString::transcode( "Montant" ), XMLString::transcode( string.setNum( (*ite)->uMontantIJ_ ) ) );
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
void CArretMaladie::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.comboBoxPrevoyanceSanteArretTravailAccordAssocies->setCurrentItem( bAccordEntreAssocies_ ? 0 : 1 );
    amon.dateEditPrevoyanceSanteArretTravailDateEffet->setDate( dDateEffet_ );
    amon.dateEditPrevoyanceSanteArretTravailDateMiseAJour->setDate( dDateMiseAJour_);

    g_Preferences->getCompagnies().loadInQT( amon.comboBoxPrevoyanceSanteCompagnieArretTravail );
    if( pCompagnie_ != 0 )
        amon.comboBoxPrevoyanceSanteCompagnieArretTravail->setCurrentText( pCompagnie_->sCompagnie_ );

    if( pCompagnie_ == 0 || pCompagnie_->bDelete_ )
        amon.comboBoxPrevoyanceSanteCompagnieArretTravail->setCurrentText( "" );
    else
        amon.comboBoxPrevoyanceSanteCompagnieArretTravail->setCurrentText( pCompagnie_->sCompagnie_ );
    amon.lineEditPrevoyanceSanteContratArretTravail->setText( sContrat_ );
    amon.comboBoxPrevoyanceSanteFiscaliteArretTravail->setCurrentItem( eFiscalite_ );

    amon.lineEditPrevoyanceSanteArretTravailDuree->setText( string.setNum( uDureeAccord_ ) );
    amon.lineEditPrevoyanceSanteAccident->setText( string.setNum( uFranchiseAccident_ ) );
    amon.lineEditPrevoyanceSanteHospitalisation->setText( string.setNum( uFranchiseHopital_ ) );
    amon.lineEditPrevoyanceSanteMaladie->setText( string.setNum( uFranchiseMaladie_ ) );

    amon.listViewArretTravail->clear();
    std::list< struct SArretTravail* const >::const_iterator  ite;
    for( ite = listArretTravail_.begin(); ite != listArretTravail_.end(); ++ite )
    {
        QListViewItem *item = new QListViewItem( amon.listViewArretTravail,
            string.setNum( (*ite)->uMontantIJ_ ),
            string.setNum( (*ite)->uFranchise_ ),
            string.setNum( (*ite)->uDuree_ ) );
    }
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CArretMaladie::copyFromQT( const dlgAmonSoft &amon )
{
    bAccordEntreAssocies_           = amon.comboBoxPrevoyanceSanteArretTravailAccordAssocies->currentItem() == 0 ? true : false;
    dDateEffet_                     = amon.dateEditPrevoyanceSanteArretTravailDateEffet->date();
    dDateMiseAJour_                 = amon.dateEditPrevoyanceSanteArretTravailDateMiseAJour->date();

    pCompagnie_                     = GET_COMP_FROM_TEXT( amon.comboBoxPrevoyanceSanteCompagnieArretTravail->currentText() );
    sContrat_                       = amon.lineEditPrevoyanceSanteContratArretTravail->text();
    eFiscalite_                     = (enum eTypeFiscalite) amon.comboBoxPrevoyanceSanteFiscaliteArretTravail->currentItem();

    uDureeAccord_                   = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteArretTravailDuree );
    uFranchiseAccident_             = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteAccident );
    uFranchiseHopital_              = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteHospitalisation );
    uFranchiseMaladie_              = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteMaladie );
}

//=============================================================================
//                          CFraisGeneraux implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CFraisGeneraux::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try
    {
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "FraisGeneraux" ) )
            return 0;

        dDuree_ = QDate::fromString( CParser::getElementAttribute( xmlNode, "Duree" ), Qt::ISODate );
        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();
        pCompagnie_ = 0;

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            pt = CParser::getTextNode( ptNode, "Compagnie" );
            if( pt != 0 )
            {
                pCompagnie_ = GET_COMP_FROM_TEXT( pt );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Contrat" );
            if( pt != 0 )
            {
                sContrat_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "CouvertureMensuelle" );
            if( pt != 0 )
            {
                uCouvertureMensuelle_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Franchise" );
            if( pt != 0 )
            {
                uFranchiseFraisGeneraux_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Notes" );
            if( pt != 0 )
            {
                sNotes_ = pt;
                continue ;
            }
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 1;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CFraisGeneraux::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try{

		QString string;

		DOMElement *pElem = CParser::createElementNode( xmlNode, "FraisGeneraux",
			node, "Duree", dDuree_.toString( Qt::ISODate ) );

        CParser::createTextNode( xmlNode, "Compagnie", pCompagnie_ ? pCompagnie_->sCompagnie_ : "", pElem );
		CParser::createTextNode( xmlNode, "Contrat", sContrat_, pElem );
		CParser::createTextNode( xmlNode, "CouvertureMensuelle", string.setNum( uCouvertureMensuelle_ ), pElem );
		CParser::createTextNode( xmlNode, "Franchise", string.setNum( uFranchiseFraisGeneraux_ ), pElem );
        CParser::createTextNode( xmlNode, "Notes", sNotes_, pElem );

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
void CFraisGeneraux::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.dateEditPrevoyanceSanteDureeFraisGeneraux->setDate( dDuree_ );

    g_Preferences->getCompagnies().loadInQT( amon.comboBoxPrevoyanceSanteCompagnieFraisGeneraux );

    if( pCompagnie_ == 0 || pCompagnie_->bDelete_ )
        amon.comboBoxPrevoyanceSanteCompagnieFraisGeneraux->setCurrentText( "" );
    else
        amon.comboBoxPrevoyanceSanteCompagnieFraisGeneraux->setCurrentText( pCompagnie_->sCompagnie_ );
    amon.lineEditPrevoyanceSanteContratFraisGeneraux->setText( sContrat_ );

    amon.lineEditPrevoyanceSanteCouvertureMensuelle->setText( string.setNum( uCouvertureMensuelle_ ) );
    amon.lineEditPrevoyanceSanteFranchise->setText( string.setNum( uFranchiseFraisGeneraux_ ) );
    amon.textEditPrevoyanceElpruntNotes->setText( sNotes_ );

}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CFraisGeneraux::copyFromQT( const dlgAmonSoft &amon )
{
    dDuree_                 = amon.dateEditPrevoyanceSanteDureeFraisGeneraux->date();
    pCompagnie_             = GET_COMP_FROM_TEXT( amon.comboBoxPrevoyanceSanteCompagnieFraisGeneraux->currentText() );
    sContrat_               = amon.lineEditPrevoyanceSanteContratFraisGeneraux->text();
    uCouvertureMensuelle_   = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteCouvertureMensuelle );
    uFranchiseFraisGeneraux_= get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteFranchise );
    sNotes_                 = amon.textEditPrevoyanceElpruntNotes->text();
}

//=============================================================================
//                          CInvalidite implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CInvalidite::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try
    {
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Invalidite" ) )
            return 0;

        const char *sPro = CParser::getElementAttribute( xmlNode, "Professionnel" );
        if( sPro != 0 && strcmp( sPro, "oui" ) == 0 )
            bProfessionnelle_ = true;
        else bProfessionnelle_ = false;

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();
        pCompagnie_ = 0;

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            pt = CParser::getTextNode( ptNode, "DateEffet" );
            if( pt != 0 )
            {
                dDateEffet_ = QDate::fromString( pt, Qt::ISODate );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DateMiseAJour" );
            if( pt != 0 )
            {
                dDateMiseAJour_ = QDate::fromString( pt, Qt::ISODate );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Compagnie" );
            if( pt != 0 )
            {
                pCompagnie_ = GET_COMP_FROM_TEXT( pt );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Fiscalite" );
            if( pt != 0 )
            {
                eFiscalite_ = (enum eTypeFiscalite) XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Notes" );
            if( pt != 0 )
            {
                sNotes_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "CapitauxInvalidite60" );
            if( pt != 0 )
            {
                uCapitauxInvalidite60_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "RenteInvalidite100" );
            if( pt != 0 )
            {
                uMontantRenteInvalidite100_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "RenteInvalidite66" );
            if( pt != 0 )
            {
                uMontantRenteInvalidite66_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "RenteInvalidite33" );
            if( pt != 0 )
            {
                uMontantRenteInvalidite33_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 1;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CInvalidite::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try{

		QString string;

		DOMElement *pElem = CParser::createElementNode( xmlNode, "Invalidite",
			node, "Professionnel", bProfessionnelle_ ? "oui" : "non" );

		CParser::createTextNode( xmlNode, "DateEffet", dDateEffet_.toString( Qt::ISODate ), pElem );
		CParser::createTextNode( xmlNode, "DateMiseAJour", dDateMiseAJour_.toString( Qt::ISODate ), pElem );
        CParser::createTextNode( xmlNode, "Compagnie", pCompagnie_ ? pCompagnie_->sCompagnie_ : "", pElem );
		CParser::createTextNode( xmlNode, "Fiscalite", string.setNum( eFiscalite_ ), pElem );
        CParser::createTextNode( xmlNode, "Notes", sNotes_, pElem );

		CParser::createTextNode( xmlNode, "CapitauxInvalidite60", string.setNum( uCapitauxInvalidite60_ ), pElem );
		CParser::createTextNode( xmlNode, "RenteInvalidite100", string.setNum( uMontantRenteInvalidite100_ ), pElem );
		CParser::createTextNode( xmlNode, "RenteInvalidite66", string.setNum( uMontantRenteInvalidite66_ ), pElem );
		CParser::createTextNode( xmlNode, "RenteInvalidite33", string.setNum( uMontantRenteInvalidite33_ ), pElem );

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
void CInvalidite::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    if( bProfessionnelle_ )
        amon.comboBoxPrevoyanceSanteInvaliditeProfessionnelle->setCurrentItem( 0 );
    else
        amon.comboBoxPrevoyanceSanteInvaliditeProfessionnelle->setCurrentItem( 1 );

    amon.dateEditPrevoyanceSanteInvaliditeDateEffet->setDate( dDateEffet_ );
    amon.dateEditPRevoyanceSanteInvaliditeMiseAJour->setDate( dDateMiseAJour_ );

    g_Preferences->getCompagnies().loadInQT( amon.comboBoxPrevoyanceSanteInvaliditeCompagnie );

    if( pCompagnie_ == 0 || pCompagnie_->bDelete_ )
        amon.comboBoxPrevoyanceSanteInvaliditeCompagnie->setCurrentText( "" );
    else
        amon.comboBoxPrevoyanceSanteInvaliditeCompagnie->setCurrentText( pCompagnie_->sCompagnie_ );
    amon.comboBoxPrevoyanceSanteInvaliditeFiscalite->setCurrentItem( eFiscalite_ );
    amon.textEditNotesPrevoyanceInvalidite->setText( sNotes_ );

    amon.lineEditPrevoyanceSanteCapitauxInvalidite->setText( string.setNum( uCapitauxInvalidite60_ ) );
    amon.lineEditPrevoyanceSanteInvalidite100->setText( string.setNum( uMontantRenteInvalidite100_ ) );
    amon.lineEditPrevoyanceSanteInvalidite66->setText( string.setNum( uMontantRenteInvalidite66_ ) );
    amon.lineEditPrevoyanceSanteInvalidite33->setText( string.setNum( uMontantRenteInvalidite33_ ) );

}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CInvalidite::copyFromQT( const dlgAmonSoft &amon )
{
    if( amon.comboBoxPrevoyanceSanteInvaliditeProfessionnelle->currentItem() == 0 )
        bProfessionnelle_ = true;
    else bProfessionnelle_ = false;
    
    dDateEffet_             = amon.dateEditPrevoyanceSanteInvaliditeDateEffet->date();
    dDateMiseAJour_         = amon.dateEditPRevoyanceSanteInvaliditeMiseAJour->date();
    pCompagnie_             = GET_COMP_FROM_TEXT( amon.comboBoxPrevoyanceSanteInvaliditeCompagnie->currentText() );
    eFiscalite_             = (enum eTypeFiscalite) amon.comboBoxPrevoyanceSanteInvaliditeFiscalite->currentItem();
    sNotes_                 = amon.textEditNotesPrevoyanceInvalidite->text();

    uCapitauxInvalidite60_  = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteCapitauxInvalidite );
    uMontantRenteInvalidite100_ = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteInvalidite100 );
    uMontantRenteInvalidite66_  = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteInvalidite66 );
    uMontantRenteInvalidite33_  = get_uint_from_qlineedit( amon.lineEditPrevoyanceSanteInvalidite33 );
}

//=============================================================================
//                          CDeces implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CDeces::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try
    {
        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Deces" ) )
            return 0;

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "ListeGarantiesDeces" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
            {
                DOMNodeList *plistGarantieDeces = ptNode->getChildNodes();

                XMLSize_t asize = plistGarantieDeces->getLength();
                listGarantiesDeces_.clear();

                for( XMLSize_t iGarantie = 0; iGarantie < asize; iGarantie++ )
                {
                    DOMNode *ptNodeArr = plistGarantieDeces->item( iGarantie );
                    if( XMLString::equals( XMLString::transcode( ptNodeArr->getNodeName() ), "GarantieDeces" ) )
                    {                    
                        struct SGarantieDeces *pGarantie = new struct SGarantieDeces();
                        listGarantiesDeces_.push_back( pGarantie );

                        DOMElement *pTmp = static_cast< DOMElement* >( ptNodeArr );

                        pGarantie->uCapitaux_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Capitaux" ) ) );
                        pGarantie->uMaladie_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Maladie" ) ) );
                        pGarantie->uAccident_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Accident" ) ) );
                        pGarantie->uDuree_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Duree" ) ) );
                        pGarantie->eBeneficiaire_ = (enum e_Beneficiaire) XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Beneficiaire" ) ) );
                        pGarantie->sOther_ = XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "Autre" ) ) );
                        pGarantie->pCompagnie_ = GET_COMP_FROM_TEXT( XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "Compagnie" ) ) ) );
                        pGarantie->eFiscalite_ = (enum eTypeFiscalite) XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Fiscalite" ) ) );
                        pGarantie->dDateEffet_ = QDate::fromString( XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "DateEffet" ) ) ), Qt::ISODate );
                    }
                }
                continue ;
            }

            if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "ListeRenteEducation" ) 
             && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
            {
                DOMNodeList *plistArretMaladie = ptNode->getChildNodes();

                XMLSize_t asize = plistArretMaladie->getLength();
                listRentesEducation_.clear();

                for( XMLSize_t iArret = 0; iArret < asize; iArret++ )
                {
                    DOMNode *ptNodeArr = plistArretMaladie->item( iArret );
                    if ( XMLString::equals( XMLString::transcode( ptNodeArr->getNodeName() ), "Rente" ) )
                    {
                        struct SRenteEducation *sArret = new struct SRenteEducation();
                        listRentesEducation_.push_back( sArret );

                        DOMElement *pTmp = static_cast< DOMElement* >( ptNodeArr );

                        sArret->uAgeDebut_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Debut" ) ) );
                        sArret->uAgeFin_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Fin" ) ) );
                        sArret->usPourcentageSalaire_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Pourcentage" ) ) );
                        sArret->uMontant_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Montant" ) ) );
                    }
                }
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DateEffetConjoint" );
            if( pt != 0 )
            {
                dDateEffetConjoint_ = QDate::fromString( pt, Qt::ISODate );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DateEffetEducation" );
            if( pt != 0 )
            {
                dDateEffetEducation_ = QDate::fromString( pt, Qt::ISODate );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "CompagnieConjoint" );
            if( pt != 0 )
            {
                pCompagnieConjoint_ = GET_COMP_FROM_TEXT( pt );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "FiscaliteConjoint" );
            if( pt != 0 )
            {
                eFiscaliteConjoint_ = (enum eTypeFiscalite) XMLString::parseInt( XMLString::transcode(  pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "FiscaliteEducation" );
            if( pt != 0 )
            {
                eFiscaliteEducation_ = (enum eTypeFiscalite) XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "CompagnieEducation" );
            if( pt != 0 )
            {
                pCompagnieEducation_ = GET_COMP_FROM_TEXT( pt );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "Notes" );
            if( pt != 0 )
            {
                sNotes_ = pt;
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "DureeRenteConjoint" );
            if( pt != 0 )
            {
                uDureeRenteConjoint_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "MontantRenteConjoint" );
            if( pt != 0 )
            {
                uRenteConjoint_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }
        }
    }
    catch( DOMException &e )
    {
        qDebug( XMLString::transcode( e.getMessage() ) );
    }
    return 1;
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CDeces::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

    try{
		    QString string;

		    DOMElement *pElem = CParser::createElementNode( xmlNode, "Deces", node );

		    CParser::createTextNode( xmlNode, "DateEffetConjoint", dDateEffetConjoint_.toString( Qt::ISODate ), pElem );
		    CParser::createTextNode( xmlNode, "DateEffetEducation", dDateEffetEducation_.toString( Qt::ISODate ), pElem );
            CParser::createTextNode( xmlNode, "CompagnieConjoint", pCompagnieConjoint_ ? pCompagnieConjoint_->sCompagnie_ : "", pElem );
		    CParser::createTextNode( xmlNode, "FiscaliteConjoint", string.setNum( eFiscaliteConjoint_ ), pElem );

		    CParser::createTextNode( xmlNode, "FiscaliteEducation", string.setNum( eFiscaliteEducation_ ), pElem );
		    CParser::createTextNode( xmlNode, "DureeRenteConjoint", string.setNum( uDureeRenteConjoint_ ), pElem );
		    CParser::createTextNode( xmlNode, "MontantRenteConjoint", string.setNum( uRenteConjoint_ ), pElem );
            CParser::createTextNode( xmlNode, "CompagnieEducation", pCompagnieEducation_ ? pCompagnieEducation_->sCompagnie_ : "", pElem );
            CParser::createTextNode( xmlNode, "Notes", sNotes_, pElem );

            DOMElement  *pElemGarantieDeces = CParser::createElementNode( xmlNode, "ListeGarantiesDeces", pElem );
            std::list< struct SGarantieDeces* const >::const_iterator ite = listGarantiesDeces_.begin();
            for( ; ite != listGarantiesDeces_.end(); ite++ )
            {
                DOMElement  *pElemGarantieDecesL = CParser::createElementNode( xmlNode, "GarantieDeces", pElemGarantieDeces );

                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Capitaux" ), XMLString::transcode( string.setNum( (*ite)->uCapitaux_ ) ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Maladie" ), XMLString::transcode( string.setNum( (*ite)->uMaladie_ ) ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Accident" ), XMLString::transcode( string.setNum( (*ite)->uAccident_ ) ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Beneficiaire" ), XMLString::transcode( string.setNum( (*ite)->eBeneficiaire_ ) ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Autre" ), XMLString::transcode( (*ite)->sOther_ ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Fiscalite" ), XMLString::transcode( string.setNum( (*ite)->eFiscalite_ ) ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Compagnie" ), XMLString::transcode( (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "" ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "DateEffet" ), XMLString::transcode( (*ite)->dDateEffet_.toString( Qt::ISODate ) ) );
                pElemGarantieDecesL->setAttribute( XMLString::transcode( "Duree" ), XMLString::transcode( string.setNum( (*ite)->uDuree_ ) ) );
            }

            DOMElement  *pElemRente = CParser::createElementNode( xmlNode, "ListeRenteEducation", pElem );
            std::list< struct SRenteEducation* const >::const_iterator iteRente = listRentesEducation_.begin();
            for( ; iteRente != listRentesEducation_.end(); iteRente++ )
            {
                DOMElement  *pElemArretTravailL = CParser::createElementNode( xmlNode, "Rente", pElemRente );
                pElemArretTravailL->setAttribute( XMLString::transcode( "Debut" ), XMLString::transcode( string.setNum( (*iteRente)->uAgeDebut_ ) ) );
                pElemArretTravailL->setAttribute( XMLString::transcode( "Fin" ), XMLString::transcode( string.setNum( (*iteRente)->uAgeFin_  ) ) );
                pElemArretTravailL->setAttribute( XMLString::transcode( "Pourcentage" ), XMLString::transcode( string.setNum( (*iteRente)->usPourcentageSalaire_ ) ) );
                pElemArretTravailL->setAttribute( XMLString::transcode( "Montant" ), XMLString::transcode( string.setNum( (*iteRente)->uMontant_ ) ) );
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
void CDeces::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.dateEditPrevoyanceDecesRenteConjointDateEffet->setDate( dDateEffetConjoint_ );
    amon.dateEditPrevoyanceDecesRenteEducationDateEffet->setDate( dDateEffetEducation_ );

    g_Preferences->getCompagnies().loadInQT( amon.comboBoxPrevoyanceDecesCompagnieConjoint );

    if( pCompagnieConjoint_ == 0 || pCompagnieConjoint_->bDelete_ )
        amon.comboBoxPrevoyanceDecesCompagnieConjoint->setCurrentText( "" );
    else
        amon.comboBoxPrevoyanceDecesCompagnieConjoint->setCurrentText( pCompagnieConjoint_->sCompagnie_ );
    
    g_Preferences->getCompagnies().loadInQT( amon.comboBoxPrevoyanceDecesRenteEducationCompagnie );

    if( pCompagnieEducation_ == 0 || pCompagnieEducation_->bDelete_ )
        amon.comboBoxPrevoyanceDecesRenteEducationCompagnie->setCurrentText( "" );
    else
        amon.comboBoxPrevoyanceDecesRenteEducationCompagnie->setCurrentText( pCompagnieEducation_->sCompagnie_ );

    amon.comboBoxPrevoyanceDecesRenteConjointFiscalite->setCurrentItem( eFiscaliteConjoint_ );
    amon.comboBoxPrevoyanceDecesRenteEducationFiscalite->setCurrentItem( eFiscaliteEducation_ );
    
    amon.lineEditPrevoyanceRenteConjointDuree->setText( string.setNum( uDureeRenteConjoint_ ) );
    amon.lineEditPrevoyanceDecesRenteConjointMontant->setText( string.setNum( uRenteConjoint_ ) );
    amon.textEditPrevoyanceDecesNotes->setText( sNotes_ );

    QString beneficiaire;
    amon.listViewGarantieDeces->clear();

    std::list< struct SGarantieDeces* const >::const_iterator ite;
    for( ite = listGarantiesDeces_.begin(); ite != listGarantiesDeces_.end(); ++ite )
    {
        switch( (*ite)->eBeneficiaire_ )
        {
        case Datas::eFamille: { beneficiaire = "Famille"; break ; }
        case Datas::eEntreprise: { beneficiaire = "Entreprise"; break ; }
        case Datas::eBanque: { beneficiaire = "Banque"; break ; }
        case Datas::eAssocie: { beneficiaire = "Associe"; break ; }
        case Datas::eAutre: { beneficiaire = (*ite)->sOther_; break ; }
        default: qDebug( "AmonSoft::showGarantieDeces(): Not support case" );
        }

        QListViewItem *item = new QListViewItem( amon.listViewGarantieDeces,
            string.setNum( (*ite)->uCapitaux_ ),
            string.setNum( (*ite)->uMaladie_ ),
            string.setNum( (*ite)->uAccident_ ),
            beneficiaire,
            (*ite)->eFiscalite_ == eAssuranceVie ? "Assurance vie" : "Madelin",
            (*ite)->pCompagnie_ ? (*ite)->pCompagnie_->sCompagnie_ : "",
            (*ite)->dDateEffet_.toString( Qt::ISODate ),
            string.setNum( (*ite)->uDuree_ ) );
    }

    amon.listViewRenteEducation->clear();
    std::list< struct SRenteEducation* const >::const_iterator iteE;
    for( iteE = listRentesEducation_.begin(); iteE != listRentesEducation_.end(); ++iteE )
    {
        QListViewItem *item = new QListViewItem( amon.listViewRenteEducation,
            string.setNum( (*iteE)->uMontant_ ),
            string.setNum( (*iteE)->usPourcentageSalaire_ ),
            string.setNum( (*iteE)->uAgeDebut_ ),
            string.setNum( (*iteE)->uAgeFin_ ) );
    }
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CDeces::copyFromQT( const dlgAmonSoft &amon )
{
    dDateEffetConjoint_         = amon.dateEditPrevoyanceDecesRenteConjointDateEffet->date();
    dDateEffetEducation_        = amon.dateEditPrevoyanceDecesRenteEducationDateEffet->date();

    pCompagnieConjoint_         = GET_COMP_FROM_TEXT( amon.comboBoxPrevoyanceDecesCompagnieConjoint->currentText() );
    pCompagnieEducation_        = GET_COMP_FROM_TEXT( amon.comboBoxPrevoyanceDecesRenteEducationCompagnie->currentText() );
    eFiscaliteConjoint_         = (enum eTypeFiscalite) amon.comboBoxPrevoyanceDecesRenteConjointFiscalite->currentItem();
    eFiscaliteEducation_        = (enum eTypeFiscalite) amon.comboBoxPrevoyanceDecesRenteEducationFiscalite->currentItem();
    uDureeRenteConjoint_        = get_uint_from_qlineedit( amon.lineEditPrevoyanceRenteConjointDuree );
    uRenteConjoint_             = get_uint_from_qlineedit( amon.lineEditPrevoyanceDecesRenteConjointMontant );
    sNotes_                     = amon.textEditPrevoyanceDecesNotes->text();
}