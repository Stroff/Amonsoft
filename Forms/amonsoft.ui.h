/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#ifndef _MAIN_UI_H_
# define _MAIN_UI_H_

#include <string>

// Includes QT
#include <qdialog.h>
#include <qfiledialog.h>
#include <qwidgetstack.h>
#include <qaction.h>
#include <qlistview.h>
#include <qmessagebox.h>

#include "Forms/amonSoft.h"
#include "Forms/about.h"
#include "Forms/preferences.h"

// STL
#include <list>

// Includes Datas classes
#include "Datas/CDatas.h"
#include "Datas/CPersonnes.h"
#include "Datas/CEntreprise.h"
#include "Datas/CSearch.h"

#include "Forms/Dynamique.ui.h"

#include "main.h"
#include "XMLParser.h"
#include "exception.h"

/************************************************************************/
/* Globals variables                                                    */
/************************************************************************/
Datas::CPersonnes    *pCurrentPersonne   = 0;
Datas::CEntreprise   *pCurrentEntreprise = 0;

//----------------------------------------------------------------------------
// Functions and slot
//----------------------------------------------------------------------------
// Show tabWisget to add personn
void dlgAmonSoft::ajouter()
{   
    qDebug( "Calling slot ajouter()" );
    widgetStackMain->raiseWidget( 0 /* tabMain */ );
    // Reset current personne
    pCurrentPersonne = 0;
    widgetStackAjouter->raiseWidget( 0 /* tabMain */ );
    resetPersonne();
}

// Show list of CPersonnes in base
void dlgAmonSoft::lister()
{
    qDebug( "Calling slot lister()" );
    widgetStackMain->raiseWidget( 1 /* Call 1st elt of stack */ );
    this->setCaption( "AmonSoft" );
}

void dlgAmonSoft::pushButtonAjouterEntreprise_clicked()
{
    qDebug( "Calling slot ajouter entreprise" );
    widgetStackMain->raiseWidget( 2/* Call 1st elt of stack */ );
	pCurrentEntreprise = 0;
    resetEntses();
}

// List of enterprises
void dlgAmonSoft::pushButtonEntrepriseLister_clicked()
{
    qDebug( "Calling slot lister entreprise" );
    widgetStackMain->raiseWidget( 3/* Call 1st elt of stack */ );
    this->setCaption( "AmonSoft" );
}

// Activate open file dialog box
void dlgAmonSoft::ouvrir()
{/*
    QString fn = QFileDialog::getOpenFileName( QString::null, "*.xml", this );
    if ( !fn.isEmpty() )
    {
	    g_Parser = new CParser( fn );

        // FIXME: Delete previous CPersonne in list
        listView->clear();

        loadXercesData( *this );
    }*/
}

void dlgAmonSoft::filenew_itemSauvegarder_activated()
{ 
    g_App->saveXercesData();
}

// Active Save As dialog box
void dlgAmonSoft::sauvegarder()
{ /*
    using namespace Datas;

    QString fn = QFileDialog::getSaveFileName( QString::null, QString::null, this );
    if ( !fn.isEmpty() ) {

        // List of persons
        g_Parser->initWrite( "ListPersonnes" );

        // Search item in the global list
        // TODO: Try to find more efficient method
        std::list< CPersonnes* >::const_iterator    ite;
        for( ite = g_listPersonnes.begin(); 
            ite != g_listPersonnes.end(); ite++ )
        {
            // Write
            (*ite)->saveToXML( g_Parser->getDocument() );
        }        
        g_Parser->writeFile( fn );

        // List of societies
        g_ParserEntses->initWrite( "ListeEntreprises" );

        // Search item in the global list
        // TODO: Try to find more efficient method
        std::list< CEntreprise* >::const_iterator    ites;
        for( ites = g_listEntreprises.begin(); 
            ites != g_listEntreprises.end(); ites++ )
        {
            // Write
            (*ites)->saveToXML( g_ParserEntses->getDocument() );
        }        
        g_ParserEntses->writeFile( "./xml/entreprises.xml" );
    } */
}

// Load about box
void dlgAmonSoft::about()
{
    static QDialog *about = new dlgAbout();
    about->show();

    // FIXME: delete pointer
}

void dlgAmonSoft::preferences()
{
    static dlgPreferences *pref = new dlgPreferences(); 
    // Load Compagnies
    g_Preferences->getCompagnies().loadInQT( pref->listViewCompagnies );
    // Load Comptes
    Preferences::t_listQString::const_iterator ite;
    
    for( ite = g_Preferences->listComptes_.begin(); ite != g_Preferences->listComptes_.end(); ite++ )
        QListViewItem *l = new QListViewItem( pref->listViewComptes, **ite );

    // Load Epargne
    for( ite = g_Preferences->listEpargnes_.begin(); ite != g_Preferences->listEpargnes_.end(); ite++ )
        QListViewItem *l = new QListViewItem( pref->listViewEpargnes, **ite );

    // Load Conseillers
    g_Preferences->loadInQTCabinet( pref->listViewBureau );
    pref->widgetStack1->raiseWidget( 1 );
    pref->show();
}
//////////////////////////////////////////////////////////////////////////////
//                          Add screen functionality                        //
//////////////////////////////////////////////////////////////////////////////

void dlgAmonSoft::widgetStackAjouter_EtatCivil()
{
    qDebug( "Calling slot widgetStackAjouter_EtatCivil()" );
    widgetStackAjouter->raiseWidget( 0 /* tabMain */ );
}

void dlgAmonSoft::widgetStackAjouter_Famille()
{
    qDebug( "Calling slot widgetStackAjouter_Famille()" );
    tabWidgetFamille->setCurrentPage( 0 );
    widgetStackAjouter->raiseWidget( 1 /* tabMain */ );
}

void dlgAmonSoft::widgetStackAjouter_Carriere()
{
    qDebug( "Calling slot widgetStackAjouter_Carriere()" );
    widgetStackAjouter->raiseWidget( 2 /* tabMain */ );
}


void dlgAmonSoft::widgetStackAjouter_Prevoyance()
{
    qDebug( "Calling slot widgetStackAjouter_Prevoyance()" );
    tabWidget3->setCurrentPage( 0 );
    widgetStackAjouter->raiseWidget( 3 /* tabMain */ );
}


void dlgAmonSoft::widgetStackAjouter_Epargne()
{
    qDebug( "Calling slot widgetStackAjouter_Epargne()" );
    tabWidgetEpargne->setCurrentPage( 0 );
    widgetStackAjouter->raiseWidget( 4 /* tabMain */ );
}

void dlgAmonSoft::widgetStackAjouter_Patrimoine()
{
    qDebug( "Calling slot widgetStackAjouter_Patrimoine()" );
    widgetStackAjouter->raiseWidget( 5 /* tabMain */ );
}

void dlgAmonSoft::pushButtonBesoins_clicked()
{
    qDebug( "Calling slot pushButtonBesoins_clicked()" );
    widgetStackAjouter->raiseWidget( 6 /* tabMain */ );
}

void dlgAmonSoft::pushButtonDossierEntreprise_clicked()
{
    qDebug( "Calling slot DossierEntreprise" );
    tabWidgetEntreprise->setCurrentPage( 0 );
    widgetStackEntreprise->raiseWidget( 0 /* tabEntreprise */ );
}

void dlgAmonSoft::pushButtonParticipants_clicked()
{
    qDebug( "Calling slot DossierEntreprise" );
    widgetStackEntreprise->raiseWidget( 1 /* tabEntreprise */ );
}

void dlgAmonSoft::pushButtonTNS_clicked()
{
    qDebug( "Calling slot DossierEntreprise" );
    widgetStackEntreprise->raiseWidget( 2 /* tabEntreprise */ );
}

//----------------------------------------------------------------------------
// Add or update record in global list
//----------------------------------------------------------------------------
void dlgAmonSoft::AjouterValider()
{
    try
    {
        // Basic and speed check of consistency
        // Here we require only first and last name

        if(    lineEditEtatCivilNom->text().isEmpty()
            || lineEditEtatCivilPrenom->text().isEmpty() )
        {
            QMessageBox::critical ( this,
                                    "Erreur durant la validation",
                                    "Un champs obligatoire n'a pas été renseigné",
                                    QMessageBox::Ok,
                                    QMessageBox::NoButton );
            return ;
        }

        if( pCurrentPersonne == 0 )
        {
            QString string;
            // Add a new item
            Datas::CPersonnes   *personne = new Datas::CPersonnes();
            pCurrentPersonne = personne;

            // Get informations
            personne->copyFromQT( *this );

            // Adding class in global list
            Datas::g_listPersonnes.push_back( personne );

            QListViewItem *item = new QListViewItem( listView,
                personne->getNom(),
                personne->getPrenom(),
                personne->getTelephone(),
                personne->getEmail(),
                string.setNum( personne->getID() ) );
            listView->setSelected( item, true );
        }
        else
        {
            QString     string;
            // Update current person
            pCurrentPersonne->copyFromQT( *this );

            // We update listView of people
            QListViewItem *item = listView->currentItem();

            if( item == 0 )
                return ;

            item->setText( 0, pCurrentPersonne->getNom() );
            item->setText( 1, pCurrentPersonne->getPrenom() );
            item->setText( 2, pCurrentPersonne->getTelephone() );
            item->setText( 3, pCurrentPersonne->getEmail() );
            item->setText( 4, string.setNum( pCurrentPersonne->getID() ) );
        }

        // TODO !!!!
        // This way seems not to be the right, this make computer low with big base.
        g_App->saveXercesData();
    }
    catch( CException &a )
    {
            QMessageBox::critical ( this,
                                    "Erreur durant la validation",
                                    a.cause(),
                                    QMessageBox::Ok,
                                    QMessageBox::NoButton );
    }
}

//----------------------------------------------------------------------------
// Delete record from global list
//----------------------------------------------------------------------------
void dlgAmonSoft::toolButtonSupprimer_clicked()
{
    using namespace Datas;

    assert( widgetStackMain->visibleWidget() != 0 );

    switch( widgetStackMain->id( widgetStackMain->visibleWidget() ) )
    {
        case 0: // Add Personne
        {
            resetPersonne();
            break ;
        }
        case 1: // List Personne
        case 3: // List Entses
        {
            supprimer();
            break ;
        }
        case 2: // Add Entses
        {
            resetEntses();
            break ;
        }
        default : qDebug("dlgAmonSoft::charger() Unsupported case" );
    }
}

void dlgAmonSoft::supprimer()
{
    using namespace Datas;
    
    std::string sMsg( "Vous êtes sur le point de supprimer définitivement " );
    int iRep = 0;

    //
    // Step to delete an CPersonnes from list
	if( listView->isVisible() )
	{
		QListViewItem *item = listView->currentItem();

		if( item == 0 )
			return ;

        ushort usId = item->text( 4 ).toUShort();
        CPersonnes *pPersonne = getPersonne( usId );

        if( pPersonne == 0 )
            return ;

        // Before continuing, we ask confirmation !
        sMsg += pPersonne->getNom() + " " + pPersonne->getPrenom() + "\n";
        sMsg += "Etes-vous sûr de vouloir continuer ?";
                        
        iRep = QMessageBox::warning ( this,
                                    "Attention",
                                    sMsg.c_str(),
                                    QMessageBox::Yes,
                                    QMessageBox::No );

        if( iRep == QMessageBox::Yes )
        {
			// We delete record
			g_listPersonnes.remove( pPersonne );
            CEntreprise *entses = pPersonne->getEntreprise();
            if( entses != 0 )
            {
                entses->removeEmploye( pPersonne );
                entses->removeGerant( pPersonne );
            }
            delete pPersonne;
		    listView->takeItem( item );
		    delete item;
        }
        return ;
	}

    //
    // Step to delete an CEntreprises from list
	if( listViewEntses->isVisible() )
	{
		QListViewItem *item = listViewEntses->currentItem();

		if( item == 0 )
			return ;

        ushort  usId = item->text( 2 ).toUShort();
        CEntreprise *pEntreprise = getEntses( usId );

        if( pEntreprise == 0 )
            return ;

        // Before continuing, we ask confirmation !
        sMsg += pEntreprise->getRaisonSociale() + " " + pEntreprise->getNumeroSiret() + "\n";
        sMsg += "Etes-vous sûr de vouloir continuer ?";

        iRep = QMessageBox::warning ( this,
                                    "Attention",
                                    sMsg.c_str(),
                                    QMessageBox::Yes,
                                    QMessageBox::No );

        if( iRep == QMessageBox::Yes )
        {
			// We delete record
			g_listEntreprises.remove( pEntreprise );
			delete pEntreprise;
        }

        if( iRep == QMessageBox::Yes )
        {
		    listViewEntses->takeItem( item );
		    delete item;
        }
        return ;
	}    

    //
    // Step to delete current personne
    if( widgetStackAjouter->isVisible() )
    {
        // Before continuing, we ask confirmation !
        sMsg += pCurrentPersonne->getNom() + " " + pCurrentPersonne->getPrenom() + "\n";
        sMsg += "Etes-vous sûr de vouloir continuer ?";
                        
        iRep = QMessageBox::warning ( this,
                                    "Attention",
                                    sMsg.c_str(),
                                    QMessageBox::Yes,
                                    QMessageBox::No );

        if( iRep == QMessageBox::Yes )
        {            
			// We delete record
			g_listPersonnes.remove( pCurrentPersonne );

            CEntreprise *entses = pCurrentPersonne->getEntreprise();
            if( entses != 0 )
            {
                entses->removeEmploye( pCurrentPersonne );
                entses->removeGerant( pCurrentPersonne );
            }

            delete pCurrentPersonne;
            pCurrentPersonne = 0;

            // Be carrefull, we suppose that to load the current personne,
            // user has even selected it in the listView
            QListViewItem *item = listView->selectedItem();
		    listView->takeItem( item );
		    delete item;
            lister();
        }
        return ;
    }

    //
    // Step to delete current personne
    if( widgetStackEntreprise->isVisible() )
    {
        // Before continuing, we ask confirmation !
        sMsg += pCurrentEntreprise->getRaisonSociale() + " " + pCurrentEntreprise->getNumeroSiret() + "\n";
        sMsg += "Etes-vous sûr de vouloir continuer ?";
                        
        iRep = QMessageBox::warning ( this,
                                    "Attention",
                                    sMsg.c_str(),
                                    QMessageBox::Yes,
                                    QMessageBox::No );

        if( iRep == QMessageBox::Yes )
        {            
			// We delete record
			g_listEntreprises.remove( pCurrentEntreprise );
            delete pCurrentEntreprise;
            pCurrentEntreprise = 0;

            // Be carrefull, we suppose that to load the current entreprise,
            // user has even selected it in the listView
            QListViewItem *item = listViewEntses->selectedItem();
		    listViewEntses->takeItem( item );
		    delete item;
            pushButtonEntrepriseLister_clicked();
        }
        return ;
    }
}

//----------------------------------------------------------------------------
// Load record in interface
// TODO: Similar to main.cpp/loadXercesData delete one of them
//----------------------------------------------------------------------------
void dlgAmonSoft::charger()
{
    using namespace Datas;

    assert( widgetStackMain->visibleWidget() != 0 );

    switch( widgetStackMain->id( widgetStackMain->visibleWidget() ) )
    {
        case 0: // Add Personne
        {
            AjouterValider();
            break ;
        }
        case 1: // List Personne
        {
            chargerPersonne( listView->currentItem() );
            break ;
        }
        case 2: // Add Entses
        {
            ValiderAjoutEntses();
            break ;
        }
        case 3: // List Entses
        {
            chargerEntreprise();
            break ;
        }
        default : qDebug("dlgAmonSoft::charger() Unsupported case" );
    }
}

//----------------------------------------------------------------------------
// Activate on lineEdit
//----------------------------------------------------------------------------
void dlgAmonSoft::comboBoxInteressement_activated( int iVal )
{
    if( iVal == 0 )
    	lineEditInteressementMod->setEnabled( true );
    else
	    lineEditInteressementMod->setEnabled( false );
}

//----------------------------------------------------------------------------
// Get the list view
//----------------------------------------------------------------------------
QListView * dlgAmonSoft::getListViewPersonnes()
{
    return listView;
}

//----------------------------------------------------------------------------
// Get the list view
//----------------------------------------------------------------------------
QListView * dlgAmonSoft::getListViewEntses()
{
	return listViewEntses;
}

//----------------------------------------------------------------------------
// Add society in global list
//----------------------------------------------------------------------------
void dlgAmonSoft::ValiderAjoutEntses()
{
    // Basic and speed check of consistency
    // Here we require only first and last name

    if( lineEditRaisonSociale->text().isEmpty() )
    {
        QMessageBox::critical( this,
            "Erreur durant la validation",
            "Un champs obligatoire n'a pas été renseigné",
            QMessageBox::Ok,
            QMessageBox::NoButton );
        return ;
    }

    if( pCurrentEntreprise == 0 )
    {
        QString string;
        // Add a new item
        Datas::CEntreprise   *entses = new Datas::CEntreprise();
        pCurrentEntreprise = entses;

        // Get informations
        entses->copyFromQT( *this );

        // Adding class in global list
        Datas::g_listEntreprises.push_back( entses );

        QListViewItem *item = new QListViewItem( listViewEntses,
            entses->getRaisonSociale(),
            entses->getNumeroSiret(),
            string.setNum( entses->getID() ) );
        listViewEntses->setSelected( item, true );
    }
    else
    {
        QString string;
        // Update current person
        pCurrentEntreprise->copyFromQT( *this );

        // We update listView of people
        QListViewItem *item = listViewEntses->currentItem();

        if( item == 0 )
            return ;

        item->setText( 0, pCurrentEntreprise->getRaisonSociale() );
        item->setText( 1, pCurrentEntreprise->getNumeroSiret() );
        item->setText( 2, string.setNum( pCurrentEntreprise->getID() ) );
    }
//    widgetStackMain->raiseWidget( 3 /* Call 1st elt of stack */ );
//    this->setCaption( "AmonSoft" ); 

    // TODO !!!!
    // This way seems not to be the right, this make computer low with big base.
    g_App->saveXercesData();
}

//----------------------------------------------------------------------------
// Load person informations in interface
//----------------------------------------------------------------------------
void dlgAmonSoft::chargerPersonne( QListViewItem *item )
{
    using namespace Datas;
    ushort          usId = item->text( 4 ).toUShort();
    
    // TODO !!!!!
    // Fix problem with less column
    if( usId == 0 )
        usId = item->text( 3 ).toUShort();

    if( item == 0 )
        return ;

    // Clear all fields
    resetPersonne();
    widgetStackAjouter->raiseWidget( 0 /* tabMain */ );

    // Add an empty to unselect item
    comboBoxFamilleConjoint->insertItem( "" );

    pCurrentPersonne = Datas::getPersonne( usId );

    if( pCurrentPersonne == 0 )
        // Stop here, no way to load something
        return ;

    // We load record
    pCurrentPersonne->loadInQT( *this );

    QString sCiv = pCurrentPersonne->getNom() + " " + pCurrentPersonne->getPrenom();

    // Change caption
    QString str = "AmonSoft : ";
    QString strB = pCurrentPersonne->isBeneficiaire() ? " (Bénéficiaire)" : " (Prospect)";
    this->setCaption( str + sCiv + strB );
        
    // Change screen
    qDebug( "Load changing screen" );
    widgetStackMain->raiseWidget( 0 /* tabMain */ );

    std::list< Datas::CPersonnes * >::iterator ite;
    // Show list of possible maried personnes
    for( ite = g_listPersonnes.begin(); ite != g_listPersonnes.end(); ite++ )
    {
        // We add CPersonne in the list of possibily maried person
        if( (*ite)->getID() != (ushort) -1 )
        {
            // Filter list
            /*if( (*ite)->getFamille() != 0
                && (*ite)->getFamille()->getBeneficiaire() != *ite
                && (*ite)->getFamille()->getConjoint() != *ite )*/
                if( (   pCurrentPersonne->getTelephone().isEmpty()
                    ||  pCurrentPersonne->getTelephone() == (*ite)->getTelephone() )
                    && *ite != pCurrentPersonne )
                {
                    QString toto;
                    QString sId = toto.setNum( (*ite)->getID() );
                    QString str = sId + ":" + (*ite)->getNom() + "/" + (*ite)->getPrenom();
                    comboBoxFamilleConjoint->insertItem( str );
                }
        }
    }

    //
    if( pCurrentPersonne->getFamille() != 0 )
    {
        const CPersonnes *personne = 0; // Is boyfriend

        if( pCurrentPersonne->getFamille()->getBeneficiaire() != pCurrentPersonne )
            personne = pCurrentPersonne->getFamille()->getBeneficiaire();
        else
            personne = pCurrentPersonne->getFamille()->getConjoint();
        
        if( personne == 0 )
            return ;

        QString toto;
        QString sId = toto.setNum( personne->getID() );
        QString str = sId + ":" + personne->getNom() + "/" + personne->getPrenom();
        comboBoxFamilleConjoint->insertItem( "", 0 );
        comboBoxFamilleConjoint->setCurrentText( str );
    }
}

//----------------------------------------------------------------------------
// Load society informations in QT
//----------------------------------------------------------------------------
void dlgAmonSoft::chargerEntreprise()
{
    using namespace Datas;

    QListViewItem *item = listViewEntses->currentItem();

    if( item == 0 )
        return ;

    ushort  usId = item->text( 2 ).toUShort();

    pCurrentEntreprise = Datas::getEntses( usId );

    if( pCurrentEntreprise == 0 )
        return ;

    // We load record
    pCurrentEntreprise->loadInQT( *this );
    // Change screen
    qDebug( "Load changing screen" );
    widgetStackMain->raiseWidget( 2 /* tabMain */ );
    QString str = "AmonSoft : ";
    str += pCurrentEntreprise->getRaisonSociale();
    this->setCaption( str );
}

void dlgAmonSoft::resetEntses()
{
    using namespace Datas;

    // Search item in the global list
    // TODO: Try to find more efficient method
    std::list< CEntreprise* >::const_iterator    ite;
    for( ite = g_listEntreprises.begin(); 
        ite != g_listEntreprises.end(); ite++ )
    {
        if( (*ite)->getID() == (ushort) -1 )
        {
            (*ite)->loadInQT( *this );
            widgetStackMain->raiseWidget( 2 /* tabMain */ );
            QString str = "AmonSoft";
            listViewEntrepriseRetraite->clear();
            lineEditInteressementMod->setText( "Modalités de distribution" );
            this->setCaption( str );
            break ;
        }
    }
    pCurrentEntreprise = 0;
}

void dlgAmonSoft::resetPersonne()
{
    using namespace Datas;

    this->setCaption( "AmonSoft" );

    // Search item in the global list
    // TODO: Try to find more efficient method
    std::list< CPersonnes* >::const_iterator    ite;
    for( ite = g_listPersonnes.begin(); 
        ite != g_listPersonnes.end(); ite++ )
    {
        if( (*ite)->getID() == (ushort) -1 )
        {
            (*ite)->loadInQT( *this );
            comboBoxFamilleConjoint->insertItem( "" );
            continue ;
        }

        // We add CPersonne in the list of possibily maried person
        comboBoxFamilleConjoint->insertItem( (*ite)->getID() + ":" + (*ite)->getNom() + "/" + (*ite)->getPrenom() );
    }

    // Clear all listview
    // TODO: See why does it necessary, normally all listview are cleared
    // with load of CPersonne !
    comboBoxFamilleConjoint->clear();
    listViewCarriereEmploi->clear();
    listViewArretTravail->clear();
    listViewGarantieDeces->clear();
    listViewRenteEducation->clear();
    listViewEmprunt->clear();
    listViewEpargne->clear();
    listViewAssuranceVie->clear();
    listViewComptes->clear();
    listViewRevenus->clear();
    listViewCharges->clear();

    pCurrentPersonne = 0;
}

void dlgAmonSoft::comboBoxFamilleConjoint_textChanged( const QString &str )
{
    if( pCurrentPersonne == 0 )
    {
        QMessageBox::critical ( this,
                                "Erreur",
                                "Veuillez valider la fiche avant",
                                QMessageBox::Ok,
                                QMessageBox::NoButton );
        return ;
    }

    if( str == "" )
    {
        if( pCurrentPersonne->getFamille() != 0 )
            pCurrentPersonne->getFamille()->setConjoint( 0 );
        return ;
    }

    // else we have to get the correct pointer
    QStringList fields = QStringList::split( ':', str );
    qDebug( fields[0] );
    ushort usId = fields[0].toUShort();
    qDebug( str );
   
    if( pCurrentPersonne->getFamille() == 0 )
        pCurrentPersonne->setFamille( new Datas::CFamille( pCurrentPersonne ) );

    Datas::CPersonnes  *pPer = Datas::CPersonnes::getItemFromID( usId );
    if( pPer == 0 ) return ;
    pCurrentPersonne->getFamille()->setConjoint( pPer );

    // We load personnal information about maried in interface
    pPer->loadInQT( *this, true );
}

void dlgAmonSoft::sliderEpargneSensibilite_valueChanged( int i )
{
    QString string;

    if( pCurrentPersonne )
        pCurrentPersonne->getEpargne()->setSensibilite( i );
    textLabelSensibilie->setText( string.setNum( i ) );
}

void dlgAmonSoft::listViewProspect_doubleClicked( QListViewItem *item )
{
    if( item != 0 )
        chargerPersonne( item );
}

void dlgAmonSoft::comboBoxEtatCivilCabinetComptable_textChanged( const QString &str )
{
    Preferences::CCabinet   *cab = g_Preferences->getCabinet( str );

    if( cab == 0 ) return ;
    cab->loadInQT( comboBoxEtatCivilExpertComptable );
}

void dlgAmonSoft::comboBoxEtatCivilEtude_textChanged( const QString &str )
{
    Preferences::CCabinet   *cab = g_Preferences->getCabinet( str );

    if( cab == 0 ) return ;
    cab->loadInQT( comboBoxEtatCivilNotaire );
}

void dlgAmonSoft::comboBoxEtatCivilCabinetAvocat_textChanged( const QString &str )
{
    Preferences::CCabinet   *cab = g_Preferences->getCabinet( str );

    if( cab == 0 ) return ;
    cab->loadInQT( comboBoxEtatCivilAvocat );
}

void dlgAmonSoft::comboBoxBenefProspect_activated( int i )
{
    if( pCurrentPersonne == 0 )
    {
        QMessageBox::critical ( this,
                                "Erreur",
                                "Veuillez valider la fiche avant",
                                QMessageBox::Ok,
                                QMessageBox::NoButton );
        return ;
    }

    if( i == 1 ) // Beneficiaire
        pCurrentPersonne->setBeneficiaire( true );
    else // Prospect
        comboBoxFamilleConjoint->setDisabled( true );

    QString sCiv = pCurrentPersonne->getNom() + " " + pCurrentPersonne->getPrenom();

    // Change caption
    QString str = "AmonSoft : ";
    QString strB = pCurrentPersonne->isBeneficiaire() ? " (Bénéficiaire)" : " (Prospect)";
    this->setCaption( str + sCiv + strB );
}

void dlgAmonSoft::pushButtonDirigeantPlus_clicked()
{
    if( pCurrentEntreprise == 0 )
    {
        QMessageBox::critical ( this,
                                "Erreur",
                                "Veuillez valider la fiche avant",
                                QMessageBox::Ok,
                                QMessageBox::NoButton );
        return ;
    }

    QString     sNom = lineEditNomGerant->text(), sPrenom = lineEditPrenomGerant->text();
    QDate       dNaissance = dateEditNaissanceGerant->date();
    Datas::t_ePartsGerant eParts = (Datas::t_ePartsGerant) comboBoxPartsDirigeant->currentItem();

    lineEditNomGerant->clear();
    lineEditPrenomGerant->clear();

    Datas::CPersonnes    *pPersonne = Datas::getPersonne( sNom, sPrenom, dNaissance );

    if( pPersonne == 0 )
    {
        int iRep = 0;

        iRep = QMessageBox::warning ( this,
                                "Attention",
                                "Impossible de trouver une personne répondant à ces critères dans le système. Souhaitez-vous la crée en tant que prospect ?",
                                QMessageBox::Yes,
                                QMessageBox::No );

        if( iRep == QMessageBox::No )
            return ;
        
        //
        // CPersonnes construction
        QString string;
        // Add a new item
        Datas::CPersonnes   *personne = new Datas::CPersonnes( sNom, sPrenom, dNaissance );
        pPersonne = personne;

        // Get informations
// TO DELETE        personne->copyFromQT( *this );

        // Adding class in global list
        Datas::g_listPersonnes.push_back( personne );

        QListViewItem *item = new QListViewItem( listView,
            personne->getNom(),
            personne->getPrenom(),
            personne->getTelephone(),
            personne->getEmail(),
            string.setNum( personne->getID() ) );
        listView->setSelected( item, true );
    }
    //
    // Entses link

    QString sParts, string;

    switch( eParts )
    {
        case Datas::eGerantMajoritaire: { sParts = "Majoritaire"; break ; }
        case Datas::eGerantMinoritaire: { sParts = "Minoritaire"; break ; }
        case Datas::eGerantAssocie: { sParts = "Associe"; break ; }
        default: { sParts = "Inconnu"; break ; }
    }

    pPersonne->setEntreprise( pCurrentEntreprise, true );

    int iRet = pCurrentEntreprise->addGerant( *pPersonne, eParts );
    if( iRet == -1 )
    {
        QMessageBox::critical ( this,
            "Erreur durant la validation",
            "Ce gérant est déjà dans la liste",
            QMessageBox::Ok,
            QMessageBox::NoButton );
        return ;
    }
    QListViewItem item = new QListViewItem( listViewDirigeants,
        sNom,
        sPrenom,
        dNaissance.toString(),
        sParts,
        string.setNum( pPersonne->getID() ) );
}


void dlgAmonSoft::pushButtontDirigeantMinus_clicked()
{
    QListViewItem  *item = listViewDirigeants->currentItem();

    if( item == 0 ) return ;

    ushort usId = item->text( 4 ).toUShort();
    pCurrentEntreprise->removeGerant( usId );
    listViewDirigeants->takeItem( item );
}

void dlgAmonSoft::comboBoxEtatCivilRaisonSociale_activated( int i )
{
    if( pCurrentPersonne == 0 )
    {
        QMessageBox::critical ( this,
                                "Erreur",
                                "Veuillez valider la fiche avant",
                                QMessageBox::Ok,
                                QMessageBox::NoButton );
        return ;
    }
    Datas::CEntreprise *pEntreprise = pCurrentPersonne->getEntreprise();

    if( pEntreprise != 0 )
        pEntreprise->removeEmploye( pCurrentPersonne->getID() ); 

    if( i == -1 )
    {
        pCurrentPersonne->removeEntreprise();
        return ;
    }

    Datas::CEntreprise *entrepriseSelected = Datas::getEntses( i );
    assert( entrepriseSelected != 0 );
    pCurrentPersonne->setEntreprise( entrepriseSelected );
    entrepriseSelected->addEmploye( *pCurrentPersonne );
}

void dlgAmonSoft::pushButtonEnstesEmployeMinus_clicked()
{
    QListViewItem  *item = listViewEntsesParticipants->currentItem();

    if( item == 0 ) return ;

    ushort              usId = item->text( 4 ).toUShort();
    Datas::CPersonnes   *pPersonne = Datas::getPersonne( usId );
    if( pPersonne != 0 )
        pPersonne->removeEntreprise();
    pCurrentEntreprise->removeEmploye( usId );
    listViewEntsesParticipants->takeItem( item );
}

void dlgAmonSoft::pushButtonEnstesEmployePlus_clicked()
{
    QString     sNom = lineEditEntsesNomEmploye->text(), sPrenom = lineEditEntsesPrenomEmploye->text();
    QDate       dNaissance = dateEditEntsesNaissanceEmploye->date();

    lineEditEntsesNomEmploye->clear();
    lineEditEntsesPrenomEmploye->clear();

    Datas::CPersonnes    *pPersonne = Datas::getPersonne( sNom, sPrenom, dNaissance );
    if( pPersonne == 0 )
    {
        int iRep = 0;

        iRep = QMessageBox::warning ( this,
                                "Attention",
                                "Impossible de trouver une personne répondant à ces critères dans le système. Souhaitez-vous la crée en tant que prospect ?",
                                QMessageBox::Yes,
                                QMessageBox::No );

        // We get out if no new person
        if( iRep == QMessageBox::No )
            return ;

        //
        // CPersonne creation

        QString string;
        // Add a new item
        Datas::CPersonnes   *personne = new Datas::CPersonnes( sNom, sPrenom, dNaissance );
        
        pPersonne = personne;

        // Get informations
// TO DELETE        personne->copyFromQT( *this );

        // Adding class in global list
        Datas::g_listPersonnes.push_back( personne );

        QListViewItem *item = new QListViewItem( listView,
            personne->getNom(),
            personne->getPrenom(),
            personne->getTelephone(),
            personne->getEmail(),
            string.setNum( personne->getID() ) );
        listView->setSelected( item, true );

    }
    //
    // Entses link

    QString string;

    pPersonne->setEntreprise( pCurrentEntreprise );

    int iRet = pCurrentEntreprise->addEmploye( *pPersonne );
    if( iRet == -1 )
    {
        QMessageBox::critical ( this,
            "Erreur durant la validation",
            "Cet employé est déjà dans la liste",
            QMessageBox::Ok,
            QMessageBox::NoButton );
        return ;
    }
    QListViewItem item = new QListViewItem( listViewEntsesParticipants,
        sNom,
        sPrenom,
        dNaissance.toString(),
        string.setNum( pPersonne->getID() ) );
}

void dlgAmonSoft::listView29_doubleClicked( QListViewItem *item )
{
    if( item != 0 )
        chargerPersonne( item );
}


void dlgAmonSoft::listViewEntsesParticipants_doubleClicked( QListViewItem *item )
{
    if( item != 0 )
        chargerPersonne( item );
}


void dlgAmonSoft::listViewDirigeants_doubleClicked( QListViewItem *item )
{
    if( item != 0 )
        chargerPersonne( item );
}

//============================================================================
//                                  Importation
//
//============================================================================
void dlgAmonSoft::fichierImporterAction_activated()
{
    QString fn = QFileDialog::getOpenFileName( QString::null, "*.csv", this );
    if ( !fn.isEmpty() )
    {
        Datas::importerCSV( fn, this );
    }
}

//============================================================================
//                                  Filters
//
//============================================================================
void dlgAmonSoft::lineEditListerFiltreNom_textChanged( const QString &str )
{
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}

void dlgAmonSoft::lineEditListerFiltrePrenom_textChanged( const QString &str )
{
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}

void dlgAmonSoft::comboBoxSearchProspect_activated( int uId )
{
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}

void dlgAmonSoft::lineEditListerFiltreSiret_textChanged( const QString &str )
{
    Datas::loadEntsesInListView( listViewEntses, lineEditListerFiltreRaisonSociale->text(), str,
        *Datas::searchEntsesSimple );
}


void dlgAmonSoft::lineEditListerFiltreRaisonSociale_textChanged( const QString & str )
{
    Datas::loadEntsesInListView( listViewEntses, str, lineEditListerFiltreSiret->text(),
        *Datas::searchEntsesSimple );
}

void dlgAmonSoft::pushButtonEntsesFiltreEffacer_clicked()
{
    lineEditListerFiltreRaisonSociale->clear();
    lineEditListerFiltreSiret->clear();
    Datas::loadEntsesInListView( listViewEntses, "", "" );
}

void dlgAmonSoft::pushButtonPersonneFiltreEffacer_clicked()
{
    lineEditListerFiltreNom->clear();
    lineEditListerFiltrePrenom->clear();
    lineEditSearchValue1->clear();
    lineEditSearchValue2->clear();
    comboBoxSearchProspect->setCurrentItem( 0 );    
    comboBoxSearchFunction->setCurrentItem( 0 );
    Datas::g_Search->setSearchMethod( 0, *this );
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}

void dlgAmonSoft::lineEditSearchValue1_textChanged( const QString &str )
{
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}


void dlgAmonSoft::lineEditSearchValue2_textChanged( const QString &str )
{
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}

void dlgAmonSoft::comboBoxSearchFunction_activated( int i )
{
    if( i == 0 )
        pushButtonPersonneFiltreEffacer_clicked();
    else
    {
        Datas::g_Search->setSearchMethod( i, *this );
        Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
    }
}

void dlgAmonSoft::comboBoxSearchOp1_highlighted()
{
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}

void dlgAmonSoft::comboBoxSearchOp2_highlighted()
{
    Datas::loadPersonneInListView( listView, *Datas::g_Search, *this );
}

void dlgAmonSoft::fichierExporterAction_activated()
{
    assert( widgetStackMain->visibleWidget() != 0 );

    switch( widgetStackMain->id( widgetStackMain->visibleWidget() ) )
    {
        case 0: // Add Personne
        {
            QString fn = QFileDialog::getSaveFileName( QString::null, "*.xml", this );
            if ( !fn.isEmpty() )
            {
                QString fam = fn + "_famille.xml";
                fn += ".xml";
                Datas::exportPersonne( fn, fam, *pCurrentPersonne );

                QMessageBox::information ( this,
                                    "",
                                    "Exportation effectuée",
                                    QMessageBox::Ok );
            }
            break ;
        }
        case 1: // List Personne
        {
            assert( Datas::g_Search != 0 );

            QString fn = QFileDialog::getSaveFileName( QString::null, "*.csv", this );
            if ( !fn.isEmpty() )
            {
                fn += ".csv";
                Datas::g_Search->exportCVS( fn, *this );

                QMessageBox::information ( this,
                                    "",
                                    "Exportation effectuée",
                                    QMessageBox::Ok );
            }
            break;
        }
        case 3: // List Entses
        {
            break ;
        }
        case 2: // Add Entses
        {
            QString fn = QFileDialog::getSaveFileName( QString::null, "*.xml", this );
            if ( !fn.isEmpty() )
            {
                fn += ".xml";
                Datas::exportEntreprise( fn, *pCurrentEntreprise );

                QMessageBox::information ( this,
                                    "",
                                    "Exportation effectuée",
                                    QMessageBox::Ok );
            }
            break ;
        }
        default : qDebug("dlgAmonSoft::charger() Unsupported case" );
    }
}
#endif /* _MAIN_UI_H_ */

