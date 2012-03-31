/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CConseiller.cpp,v 1.11 2006/04/16 22:12:24 pascal Exp $
* $Log: CConseiller.cpp,v $
* Revision 1.11  2006/04/16 22:12:24  pascal
* - liens entre employ�s & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des g�rants & employ�s depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.10  2005/12/27 10:28:04  pascal
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
* Revision 1.9  2005/10/14 08:41:10  pascal
* - correction d'un bogue lors de la lecture du fichier XML : Un �l�ment vide �tait ajout�
*
* Revision 1.8  2005/10/12 16:11:20  pascal
* - implementation des fonctions loadFromXerces des classes CPersonnes *
* - bug: ajout de CPrevoyance dans CPersonnes
*
* Revision 1.7  2005/10/11 22:53:57  pascal
* - CPersonnes peut lire depuis le XML ses donn�es
* - CConseillers aussi
* - CEpargnes en cours !
*
* Revision 1.6  2005/10/11 08:12:16  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de donn�es n'h�ritent plus de CDatas � part CPersonne et CEntreprise
* - les fonctions li�es � QT sont toutes impl�ment�es
* - les fonctions saveToXML sont impl�ment�es pour les particuliers
*
* Revision 1.5  2005/10/05 17:14:23  pascal
* - nouvelle structure de donn�es pour stocker les informations sur l'�pargne
* - r�solution du probl�me li� � l'�pouse : m�thodes surcharg�es avec un bool suppl�mentaire permettant de savoir � qui l'on a � faire dans CPersonne et dans CRevenus.
* - loadInQT impl�ment� pour toutes les classes
*
* Revision 1.4  2005/09/29 15:51:27  pascal
* - Les boutons des onglets de la section ajouter poss�dent d�sormais une image
* - copyFromQT est bient�t impl�ment�e pour toutes les classes
*
* Revision 1.3  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des m�thodes relatives � l'interface : r�alisation du squelette
*
* Revision 1.2  2005/09/09 15:49:38  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ d�rive d�sormais de CDatas et d�finisse les classes virtuelles pures
*
*/

// QT
#include <qlineedit.h>
#include <qcombobox.h>

#include "main.h"
#include "Preferences/CPreferences.h"
#include "CConseiller.h"
#include <iostream>

using namespace Datas;

//-----------------------------------------------------------------------------
// CConseiller destructor
// By $Author: pascal $
//-----------------------------------------------------------------------------
CConseiller::~CConseiller()
{
}

//-----------------------------------------------------------------------------
// Virtual function for Xerces
// By $Author: pascal $
//-----------------------------------------------------------------------------
int CConseiller::loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode )
{
    XERCES_CPP_NAMESPACE_USE

    try{
        DOMElement *pNode = static_cast< DOMElement* > ( xmlNode );

        sNom_ = XMLString::transcode( pNode->getAttribute( XMLString::transcode( "Nom" ) ) );
        sSociete_ = g_Preferences->getCabinet( XMLString::transcode( pNode->getAttribute( XMLString::transcode( "Societe" ) ) ) );
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
int CConseiller::saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement *node ) const
{
	XERCES_CPP_NAMESPACE_USE

	try {
		DOMElement *pElem = xmlNode->createElement( XMLString::transcode( "Conseiller" ) );

        QString string;

        pElem->setAttribute( XMLString::transcode( "Type" ), XMLString::transcode( string.setNum( eType_ ) ) );
		pElem->setAttribute( XMLString::transcode( "Nom" ), XMLString::transcode( sNom_ ) );
        pElem->setAttribute( XMLString::transcode( "Societe" ), XMLString::transcode( sSociete_ != 0 ? sSociete_->getName() : "" ) );

		node->appendChild( pElem );
	}
	catch( DOMException &e )
	{
		qDebug( XMLString::transcode( e.getMessage() ) );
	}

	return 0;
}

/* The CConseiller class is too generic to load or copy itself in the graphic
   interface. Advisers can have different type, which determine the graphical
   widget to use.  */

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CConseiller::loadInQT( dlgAmonSoft &amon ) const
{ 
    QComboBox   *cSoc;
    QComboBox   *cCons;

    switch( eType_ )
    {
        case Preferences::eNotaire:
        {
            cCons = amon.comboBoxEtatCivilNotaire;
            cSoc  = amon.comboBoxEtatCivilEtude;
            break ;
        }
        case Preferences::eAvocat:
        {
            cCons = amon.comboBoxEtatCivilAvocat;
            cSoc  = amon.comboBoxEtatCivilCabinetAvocat;
            break ;
        }
        case Preferences::eComptable:
        {
            cCons = amon.comboBoxEtatCivilExpertComptable;
            cSoc  = amon.comboBoxEtatCivilCabinetComptable;
            break ;
        }
        default: qDebug( "CConseiller::loadInQT : Unsupported case" ); return ;
    }

    cCons->clear();
    cSoc->clear();

    g_Preferences->loadInQTCabinet( cSoc, eType_ );
    if( sSociete_ )
    {
        cSoc->setCurrentText( sSociete_->getName() );
        sSociete_->loadInQT( cCons );
        if( sNom_ != "" )
            cCons->setCurrentText( sNom_ );
    }
}

//-----------------------------------------------------------------------------
// Virtual function for QT
// By $Author: pascal $
//-----------------------------------------------------------------------------
void CConseiller::copyFromQT( const dlgAmonSoft &amon )
{ 
    switch( eType_ )
    {
        case Preferences::eNotaire:
        {
            sNom_ = amon.comboBoxEtatCivilNotaire->currentText();
            sSociete_ = g_Preferences->getCabinet( amon.comboBoxEtatCivilEtude->currentText() );
            break ;
        }
        case Preferences::eAvocat:
        {
            sNom_ = amon.comboBoxEtatCivilAvocat->currentText();
            sSociete_ = g_Preferences->getCabinet( amon.comboBoxEtatCivilCabinetAvocat->currentText() );
            break ;
        }
        case Preferences::eComptable:
        {
            sNom_ = amon.comboBoxEtatCivilExpertComptable->currentText();
            sSociete_ = g_Preferences->getCabinet( amon.comboBoxEtatCivilCabinetComptable->currentText() );
            break ;
        }
        default: qDebug( "CConseiller::loadInQT : Unsupported case" );
    }
}