/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CCarriere.cpp,v 1.16 2006/11/10 10:48:06 pascal Exp $
* $Log: CCarriere.cpp,v $
* Revision 1.16  2006/11/10 10:48:06  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
* Revision 1.15  2006/05/12 16:22:43  pascal
* Version 0.1 build 14
* - Le fond de la form principale passe au bleu
* - [BUG] : Problème avec le chargement des dates depuis l'XML : Les dates sont désormais au format ISO
*
* Revision 1.14  2006/04/29 16:29:28  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.13  2006/04/21 00:08:16  pascal
* Version 0.1.12
*
* - correction du problème liée au reset des listes dynamique.
* - CPersonne ne crée par forcémment un CFamille (à surveiller !)
* - nouvelle image pour les prospects
* - correction bugs mineurs
*
* Revision 1.12  2006/01/20 13:18:44  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.11  2005/12/27 10:28:04  pascal
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
* Revision 1.10  2005/11/30 18:16:48  pascal
* - améliorations des chargements / enregistrements XML
* - CFamille peut désormais être sauvegarder dans un fichier
* - Correction de bugs pour l'XML des entses
*
* Revision 1.9  2005/11/12 15:04:55  pascal
* Mise à niveau ...
*
* Revision 1.8  2005/10/11 08:12:16  pascal
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
* Revision 1.5  2005/09/29 15:51:27  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.4  2005/09/27 15:28:10  pascal
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

// QT
#include <qstring.h> 
#include <qlineedit.h>
#include <qlistview.h>

#include "CCarriere.h"
#include "CRevenus.h"

using namespace Datas;

//=============================================================================
//                          CCarriere implementation
//
//=============================================================================

//-----------------------------------------------------------------------------
// CCarriere constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CCarriere::CCarriere()
{
    uDepartRetraite_ = 0;
    listEmplois_.empty();
}


//-----------------------------------------------------------------------------
// CCarriere destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CCarriere::~CCarriere()
{
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CCarriere::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE
    try
    {
        DOMElement  *ptNode = static_cast< DOMElement* >( xmlNode );

        if( ptNode && XMLString::equals( XMLString::transcode( ptNode->getTagName() ), "Carriere" ) )
        {
            DOMNodeList *listNodes = xmlNode->getChildNodes();

            XMLSize_t size = listNodes->getLength();

            // Viewing list of nodes
            for( XMLSize_t i = 0; i < size; i++ )
            {
                DOMNode *ptNode = listNodes->item( i );
                const char *pt;

                if ( XMLString::equals( XMLString::transcode( ptNode->getNodeName() ), "Emplois" ) 
                    && DOMNode::ELEMENT_NODE == ptNode->getNodeType() )
                {
                    DOMNodeList *plist = ptNode->getChildNodes();
                    listEmplois_.clear();

                    XMLSize_t asize = plist->getLength();

                    for( XMLSize_t iGarantie = 0; iGarantie < asize; iGarantie++ )
                    {
                        DOMNode *ptNodeArr = plist->item( iGarantie );
                        if( XMLString::equals( XMLString::transcode( ptNodeArr->getNodeName() ), "Emploi" ) )
                        {
                            struct SJobs *pJob = new struct SJobs();
                            DOMElement  *pTmp = static_cast< DOMElement* >( ptNodeArr );

                            pJob->dEntree_ = QDate::fromString( XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "DateEntree" ) ) ), Qt::ISODate );
                            pJob->dFin_ = QDate::fromString( XMLString::transcode( pTmp->getAttribute( XMLString::transcode( "DateFin" ) ) ), Qt::ISODate );
                            pJob->eStatut_ = (enum eStatutPro) XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Statut" ) ) );
                            pJob->uRevenus_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "Revenus" ) ) );
                            pJob->uPointsRCO_ = XMLString::parseInt( pTmp->getAttribute( XMLString::transcode( "PointsRCO" ) ) );

                            // We have to find an eventual node "Note"
                            DOMNodeList *plist = ptNodeArr->getChildNodes();
                            XMLSize_t asize = plist->getLength();
                            for( XMLSize_t iArret = 0; iArret < asize; iArret++ )
                            {
                                DOMNode    *ptNodeNote = plist->item( iArret );
                                pt = CParser::getTextNode( ptNodeNote, "Note" );
                                if( pt )
                                {
                                    pJob->sNotes_ = pt;
                                    break ;
                                }
                            }

                            listEmplois_.push_back( pJob );
                        }
                    }
                    continue ;
                }

                pt = CParser::getTextNode( ptNode, "AgeRetraite" );
                if( pt )
                {
                    uDepartRetraite_ = XMLString::parseInt( XMLString::transcode( pt ) );
                    continue ;
                }
            }
            return 1;
        }
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
int CCarriere::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try {
		QString                     sAgeRetraire;    
		t_listJobs::const_iterator  ite;

        DOMElement    *pElem = xmlNode->createElement( XMLString::transcode( "Carriere" ) );
        node->appendChild( pElem );

		CParser::createTextNode( xmlNode, "AgeRetraite", sAgeRetraire.setNum( uDepartRetraite_ ), pElem );

		DOMElement    *pElemEmp = CParser::createElementNode( xmlNode, "Emplois", pElem );

		// Load in interface all element from the list
		for ( ite = listEmplois_.begin(); ite != listEmplois_.end(); ite++ )
		{
			QString string;

			DOMElement    *pEmpl = xmlNode->createElement( XMLString::transcode( "Emploi" ) );
			pEmpl->setAttribute( XMLString::transcode( "DateEntree" ),
								 XMLString::transcode( (*ite)->dEntree_.toString( Qt::ISODate ) ) );
			pEmpl->setAttribute( XMLString::transcode( "DateFin" ),
							     XMLString::transcode( (*ite)->dFin_.toString( Qt::ISODate ) ) );
			pEmpl->setAttribute( XMLString::transcode( "Revenus" ),
								 XMLString::transcode( string.setNum( (*ite)->uRevenus_ ) ) );
			pEmpl->setAttribute( XMLString::transcode( "PointsRCO" ),
								 XMLString::transcode( string.setNum( (*ite)->uPointsRCO_ ) ) );
			pEmpl->setAttribute( XMLString::transcode( "Statut" ),
								 XMLString::transcode( string.setNum( (*ite)->eStatut_ ) ) );
			
			CParser::createTextNode( xmlNode, "Note", (*ite)->sNotes_, pEmpl );
			pElemEmp->appendChild( pEmpl );			
		}
	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}
  return 0;
}


//-----------------------------------------------------------------------------
// Convert statut into string
// By $Author: pascal $
//-----------------------------------------------------------------------------
QString CCarriere::statutToString( enum eStatutPro eStatut )
{
    QString status;

    // Convert statut in QString
    switch( eStatut )
    {
        case eSalarie: { status = "Salarie"; break ; }
        case eSalarieCadre: { status = "Salarie Cadre"; break ; }
        case eETAM: { status = "ETAM"; break ; }
        case eFonctionnaire: { status = "Fonctionnaire"; break ;}
        case eArtisant: { status = "Artisant"; break ;}
        case eCommercant: { status = "Commercant"; break ;}
        case eLiberal: { status = "Liberal"; break ;}
        case eExploitantAgricole: { status = "Exploitant agricole"; break ;}
        default: qDebug( "CCarriere::statutToString: Not supported case" );
    }

    return status;
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CCarriere::loadInQT( dlgAmonSoft &amon ) const
{
    QString                     sAgeRetraire;    
    t_listJobs::const_iterator  ite;

    amon.lineEditCarriereAgeRetraite->setText( sAgeRetraire.setNum( uDepartRetraite_ ) );
    amon.listViewCarriereEmploi->clear();

    // Load in interface all element from the list
    for ( ite = listEmplois_.begin(); ite != listEmplois_.end(); ite++ )
    {
        QString string;

        QListViewItem *item = new QListViewItem( amon.listViewCarriereEmploi,
            (*ite)->dEntree_.toString( Qt::ISODate ),
            (*ite)->dFin_.toString( Qt::ISODate ),
            string.setNum( (*ite)->uRevenus_ ),
            string.setNum( (*ite)->uPointsRCO_ ),
            statutToString( (*ite)->eStatut_ ),
            (*ite)->sNotes_ );
    }
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CCarriere::copyFromQT( const dlgAmonSoft &amon )
{
    uDepartRetraite_ = get_uint_from_qlineedit( amon.lineEditCarriereAgeRetraite );
}