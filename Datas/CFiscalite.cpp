/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CFiscalite.cpp,v 1.12 2006/11/10 10:48:07 pascal Exp $
* $Log: CFiscalite.cpp,v $
* Revision 1.12  2006/11/10 10:48:07  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
* Revision 1.11  2006/11/09 13:39:48  pascal
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
* Revision 1.10  2005/11/12 15:04:56  pascal
* Mise à niveau ...
*
* Revision 1.9  2005/10/26 10:11:07  pascal
* - CEntreprise : saveToXML réalisé
* - retouches divers
*
* Revision 1.8  2005/10/14 08:41:11  pascal
* - correction d'un bogue lors de la lecture du fichier XML : Un élément vide était ajouté
*
* Revision 1.7  2005/10/12 16:11:21  pascal
* - implementation des fonctions loadFromXerces des classes CPersonnes *
* - bug: ajout de CPrevoyance dans CPersonnes
*
* Revision 1.6  2005/10/11 08:12:17  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
* Revision 1.5  2005/10/05 17:14:23  pascal
* - nouvelle structure de données pour stocker les informations sur l'épargne
* - résolution du problème lié à l'épouse : méthodes surchargées avec un bool supplémentaire permettant de savoir à qui l'on a à faire dans CPersonne et dans CRevenus.
* - loadInQT implémenté pour toutes les classes
*
* Revision 1.4  2005/09/29 15:51:27  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.3  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
*
* Revision 1.2  2005/09/09 15:49:38  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
*
*/

#include <qlineedit.h>
#include <qcombobox.h>

#include <stdio.h>

#include "CFiscalite.h"

using namespace Datas;

//-----------------------------------------------------------------------------
// CFiscalite constructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CFiscalite::CFiscalite()
{
    /*
     * Init
     */
    uMontantISF_ = 0;
    uMontantImpot_ = 0;
    bISF_ = false;
    uMontantISF_ = 0;
    uDeductions_ = 0;
    bCGA_VGA_ = false;
}

//-----------------------------------------------------------------------------
// CFiscalite destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CFiscalite::~CFiscalite()
{
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CFiscalite::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE
    try{
        QString string;

        if( ! XMLString::equals( XMLString::transcode( xmlNode->getNodeName() ), "Fiscalite" ) )
            return 0;

        DOMNodeList *listNodes = xmlNode->getChildNodes();

        XMLSize_t size = listNodes->getLength();

        // Viewing list of nodes
        for( XMLSize_t i = 0; i < size; i++ )
        {
            DOMNode *ptNode = listNodes->item( i );
            const char *pt;

            pt = CParser::getTextNode( ptNode, "Montant" );
            if( pt != 0 )
            {
                uMontantImpot_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "ISF" );
            if( pt != 0 )
            {
                if( strcmp( pt, "oui" ) == 0 )
                    bISF_ = true;
                else bISF_ = false;
            }

            pt = CParser::getTextNode( ptNode, "MontantISF" );
            if( pt != 0 )
            {
                uMontantISF_ = XMLString::parseInt( XMLString::transcode( pt ) );
                continue ;
            }

            pt = CParser::getTextNode( ptNode, "CGA_VGA" );
            if( pt != 0 )
            {
                if( pt != 0 && strcmp( pt, "oui" ) == 0 )
                    bCGA_VGA_ = true;
                else bCGA_VGA_ = false;
            }

            pt = CParser::getTextNode( ptNode, "Deductions" );
            if( pt != 0 )
            {
                uDeductions_ = XMLString::parseInt( XMLString::transcode( pt ) );
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
int CFiscalite::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE
	try{
		QString string;

		DOMElement *pElem = CParser::createElementNode( xmlNode, "Fiscalite", node );

		CParser::createTextNode( xmlNode, "Montant", string.setNum( uMontantImpot_ ), pElem );
		CParser::createTextNode( xmlNode, "ISF", bISF_ ? "oui" : "non", pElem );
		if( bISF_ )
			CParser::createTextNode( xmlNode, "MontantISF", string.setNum( uMontantISF_ ), pElem );
		CParser::createTextNode( xmlNode, "CGA_VGA", bCGA_VGA_ ? "oui" : "non", pElem );
		CParser::createTextNode( xmlNode, "Deductions", string.setNum( uDeductions_ ), pElem );

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
void CFiscalite::loadInQT( dlgAmonSoft &amon ) const
{
    QString string;

    amon.lineEditCarriereMontantImpotMonsieur->setText( string.setNum( uMontantImpot_ ) );
    amon.comboBoxCarriereISF->setCurrentItem( bISF_ == true ? 0 : 1 );
    amon.lineEditCarriereMontantISF->setText( string.setNum( uMontantISF_ ) );
    amon.comboBoxCarriereCGA->setCurrentItem( bCGA_VGA_ == true ? 0 : 1 );
    amon.lineEditCarriereDeductionsMonsieur->setText( string.setNum( uDeductions_ ) );
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CFiscalite::copyFromQT( const dlgAmonSoft &amon )
{
    // FIXME: Warning, here we don't know, if we are mister or madame.
    // We need to know, if this is for the principal consumer.

    uMontantImpot_              = get_uint_from_qlineedit( amon.lineEditCarriereMontantImpotMonsieur );
    bISF_                       = amon.comboBoxCarriereISF->currentItem() == 0 ? true : false;
    uMontantISF_                = get_uint_from_qlineedit( amon.lineEditCarriereMontantISF );
    bCGA_VGA_                   = amon.comboBoxCarriereCGA->currentItem() == 0 ? true : false;
    uDeductions_                = get_uint_from_qlineedit( amon.lineEditCarriereDeductionsMonsieur );
    
}
