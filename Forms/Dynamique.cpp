/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\Dynamique.ui'
**
** Created: sam. 8. oct. 22:30:38 2005
**      by: The User Interface Compiler ($Id: Dynamique.cpp,v 1.5 2007/02/06 19:04:46 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\Dynamique.h"

#include <qvariant.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qpushbutton.h>

#include "Dynamique.ui.h"
/*
 *  Constructs a AmonSoft which is a child of 'parent', with the
 *  name 'name'.' 
 */
AmonSoft::AmonSoft( QWidget* parent,  const char* name )
    : dlgAmonSoft( parent, name )
{
    if ( !name )
	setName( "AmonSoft" );
    languageChange();

    // signals and slots connections
    connect( pushButtonEnfantPlus, SIGNAL( clicked() ), this, SLOT( showEnfant() ) );
    connect( pushButtonEnfantsMinus, SIGNAL( clicked() ), this, SLOT( delEnfant() ) );
    connect( pushButtonCarriereEmploiPlus, SIGNAL( clicked() ), this, SLOT( showEmploi() ) );
    connect( pushButtonCarriereEmploiMinus, SIGNAL( clicked() ), this, SLOT( delEmploi() ) );
    connect( pushButtonPrevoyanceEmpruntPlus, SIGNAL( clicked() ), this, SLOT( showEmprunt() ) );
    connect( pushButtonPrevoyanceEmpruntMinus, SIGNAL( clicked() ), this, SLOT( delEmprunt() ) );
    connect( pushButtonPrevoyanceGarantieDecesPlus, SIGNAL( clicked() ), this, SLOT( showGarantieDeces() ) );
    connect( pushButtonPrevoyanceGarantieDecesMinus, SIGNAL( clicked() ), this, SLOT( delGarantieDeces() ) );
    connect( pushButtonPrevoyanceRenteEducationPlus, SIGNAL( clicked() ), this, SLOT( showRenteEducation() ) );
    connect( pushButtonPrevoyanceRenteEducationMinus, SIGNAL( clicked() ), this, SLOT( delRenteEducation() ) );
    connect( pushButtonEpargneCapitalisationPlus, SIGNAL( clicked() ), this, SLOT( showEpargne() ) );
    connect( pushButtonEpargneCapitalisationMinus, SIGNAL( clicked() ), this, SLOT( delEpargne() ) );
    connect( pushButtonEpargneAssurancePlus, SIGNAL( clicked() ), this, SLOT( showAssuranceVie() ) );
    connect( pushButtonEpargneAssuranceMinus, SIGNAL( clicked() ), this, SLOT( delAssuranceVie() ) );
    connect( pushButtonEpargneComptePlus, SIGNAL( clicked() ), this, SLOT( showCompte() ) );
    connect( pushButtonEpargneCompteMinus, SIGNAL( clicked() ), this, SLOT( delCompte() ) );
    connect( pushButtonEpargneRevenusPlus, SIGNAL( clicked() ), this, SLOT( showRevenus() ) );
    connect( pushButtonEpargneRevenusMinus, SIGNAL( clicked() ), this, SLOT( delRevenus() ) );
    connect( pushButtonEpargneChargesPlus, SIGNAL( clicked() ), this, SLOT( showCharges() ) );
    connect( pushButtonEpargneChargesMinus, SIGNAL( clicked() ), this, SLOT( delCharges() ) );
    connect( pushButtonEntrepriseRetraitePlus, SIGNAL( clicked() ), this, SLOT( showRetraite() ) );
    connect( pushButtonEntrepriseRetraiteMinus, SIGNAL( clicked() ), this, SLOT( delRetraite() ) );
    connect( pushButtonPrevoyanceArretTravailPlus, SIGNAL( clicked() ), this, SLOT( showArretMaladie() ) );
    connect( pushButtonPrevoyanceArretTravailMinus, SIGNAL( clicked() ), this, SLOT( delArretMaladie() ) );
    connect( pushButtonPrevoyanceEntsesPlus, SIGNAL( clicked() ), this, SLOT( showKDeces() ) );
    connect( pushButtonPrevoyanceEntsesMinus, SIGNAL( clicked() ), this, SLOT( delKdeces() ) );
    connect( pushButtonPrevoyance2EntsesPlus, SIGNAL( clicked() ), this, SLOT( showIJournalier() ) );
    connect( pushButtonPrevoyance2EntsesMinus, SIGNAL( clicked() ), this, SLOT( delIJournalier() ) );

    connect( listViewEnfants, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showEnfant( QListViewItem * ) ) );
    connect( listViewEmprunt, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showEmprunt( QListViewItem * ) ) );
    connect( listViewArretTravail, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showArretMaladie( QListViewItem * ) ) );
    connect( listViewRenteEducation, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showRenteEducation( QListViewItem * ) ) );
    connect( listViewGarantieDeces, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showGarantieDeces( QListViewItem * ) ) );
    connect( listViewCarriereEmploi, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showEmploi( QListViewItem * ) ) );
    connect( listViewEpargne, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showEpargne( QListViewItem * ) ) );
    connect( listViewAssuranceVie, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showAssuranceVie( QListViewItem * ) ) );
    connect( listViewComptes, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showCompte( QListViewItem * ) ) );
    connect( listViewRevenus, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showRevenus( QListViewItem * ) ) );
    connect( listViewCharges, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showCharges( QListViewItem * ) ) );
    connect( listViewEntrepriseRetraite, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( showRetraite( QListViewItem * ) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AmonSoft::~AmonSoft()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AmonSoft::languageChange()
{
}