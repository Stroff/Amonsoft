/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\garantiedeces.ui'
**
** Created: ven. 6. avr. 16:32:09 2007
**      by: The User Interface Compiler ($Id: garantiedeces.cpp,v 1.25 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\garantiedeces.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qdatetimeedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "garantiedeces.ui.h"
/*
 *  Constructs a dlgGarantieDeces as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgGarantieDeces::dlgGarantieDeces( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgGarantieDeces" );
    dlgGarantieDecesLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgGarantieDecesLayout"); 

    pushButtonKo = new QPushButton( this, "pushButtonKo" );

    dlgGarantieDecesLayout->addMultiCellWidget( pushButtonKo, 3, 3, 4, 8 );

    pushButtonOk = new QPushButton( this, "pushButtonOk" );

    dlgGarantieDecesLayout->addMultiCellWidget( pushButtonOk, 3, 3, 0, 3 );

    layout94 = new QHBoxLayout( 0, 0, 6, "layout94"); 

    labelPrevoyanceDecesCapital1 = new QLabel( this, "labelPrevoyanceDecesCapital1" );
    layout94->addWidget( labelPrevoyanceDecesCapital1 );

    lineEditPrevoyanceDecesCapital = new QLineEdit( this, "lineEditPrevoyanceDecesCapital" );
    lineEditPrevoyanceDecesCapital->setFrameShape( QLineEdit::LineEditPanel );
    lineEditPrevoyanceDecesCapital->setFrameShadow( QLineEdit::Sunken );
    layout94->addWidget( lineEditPrevoyanceDecesCapital );

    labelPrevoyanceDecesMaladie1 = new QLabel( this, "labelPrevoyanceDecesMaladie1" );
    layout94->addWidget( labelPrevoyanceDecesMaladie1 );

    lineEditPrevoyanceDecesMaladie = new QLineEdit( this, "lineEditPrevoyanceDecesMaladie" );
    layout94->addWidget( lineEditPrevoyanceDecesMaladie );

    labelPrevoyanceDecesAccident1 = new QLabel( this, "labelPrevoyanceDecesAccident1" );
    layout94->addWidget( labelPrevoyanceDecesAccident1 );

    lineEditPrevoyanceDecesAccident = new QLineEdit( this, "lineEditPrevoyanceDecesAccident" );
    layout94->addWidget( lineEditPrevoyanceDecesAccident );

    dlgGarantieDecesLayout->addMultiCellLayout( layout94, 0, 0, 0, 8 );

    layout95 = new QHBoxLayout( 0, 0, 6, "layout95"); 

    labelPrevoyanceDecesBeneficiaire1 = new QLabel( this, "labelPrevoyanceDecesBeneficiaire1" );
    layout95->addWidget( labelPrevoyanceDecesBeneficiaire1 );

    comboBoxPrevoyanceDecesBeneficiaire = new QComboBox( FALSE, this, "comboBoxPrevoyanceDecesBeneficiaire" );
    layout95->addWidget( comboBoxPrevoyanceDecesBeneficiaire );

    labelPrevoyanceDecesAutre1 = new QLabel( this, "labelPrevoyanceDecesAutre1" );
    labelPrevoyanceDecesAutre1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, labelPrevoyanceDecesAutre1->sizePolicy().hasHeightForWidth() ) );
    layout95->addWidget( labelPrevoyanceDecesAutre1 );

    lineEditPrevoyanceDecesPreciser = new QLineEdit( this, "lineEditPrevoyanceDecesPreciser" );
    layout95->addWidget( lineEditPrevoyanceDecesPreciser );

    dlgGarantieDecesLayout->addMultiCellLayout( layout95, 1, 1, 0, 8 );

    labelPrevoyanceDecesFiscalite1 = new QLabel( this, "labelPrevoyanceDecesFiscalite1" );

    dlgGarantieDecesLayout->addWidget( labelPrevoyanceDecesFiscalite1, 2, 0 );

    labelPrevoyanceDecesCompagnie1 = new QLabel( this, "labelPrevoyanceDecesCompagnie1" );

    dlgGarantieDecesLayout->addWidget( labelPrevoyanceDecesCompagnie1, 2, 2 );

    labelPrevoyanceDecesDate1 = new QLabel( this, "labelPrevoyanceDecesDate1" );

    dlgGarantieDecesLayout->addWidget( labelPrevoyanceDecesDate1, 2, 5 );

    dateEditPrevoyanceDecesDateEffet = new QDateEdit( this, "dateEditPrevoyanceDecesDateEffet" );

    dlgGarantieDecesLayout->addWidget( dateEditPrevoyanceDecesDateEffet, 2, 6 );

    labelPrevoyanceDecesDuree = new QLabel( this, "labelPrevoyanceDecesDuree" );

    dlgGarantieDecesLayout->addWidget( labelPrevoyanceDecesDuree, 2, 7 );

    comboBoxPrevoyanceDecesFiscalite = new QComboBox( FALSE, this, "comboBoxPrevoyanceDecesFiscalite" );

    dlgGarantieDecesLayout->addWidget( comboBoxPrevoyanceDecesFiscalite, 2, 1 );

    comboBoxPrevoyanceDecesCompagnie = new QComboBox( FALSE, this, "comboBoxPrevoyanceDecesCompagnie" );

    dlgGarantieDecesLayout->addMultiCellWidget( comboBoxPrevoyanceDecesCompagnie, 2, 2, 3, 4 );

    lineEditPrevoyanceDecesDuree = new QLineEdit( this, "lineEditPrevoyanceDecesDuree" );
    lineEditPrevoyanceDecesDuree->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditPrevoyanceDecesDuree->sizePolicy().hasHeightForWidth() ) );
    lineEditPrevoyanceDecesDuree->setMaximumSize( QSize( 30, 32767 ) );

    dlgGarantieDecesLayout->addWidget( lineEditPrevoyanceDecesDuree, 2, 8 );
    languageChange();
    resize( QSize(576, 140).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( lineEditPrevoyanceDecesCapital, lineEditPrevoyanceDecesMaladie );
    setTabOrder( lineEditPrevoyanceDecesMaladie, lineEditPrevoyanceDecesAccident );
    setTabOrder( lineEditPrevoyanceDecesAccident, comboBoxPrevoyanceDecesBeneficiaire );
    setTabOrder( comboBoxPrevoyanceDecesBeneficiaire, lineEditPrevoyanceDecesPreciser );
    setTabOrder( lineEditPrevoyanceDecesPreciser, comboBoxPrevoyanceDecesFiscalite );
    setTabOrder( comboBoxPrevoyanceDecesFiscalite, comboBoxPrevoyanceDecesCompagnie );
    setTabOrder( comboBoxPrevoyanceDecesCompagnie, dateEditPrevoyanceDecesDateEffet );
    setTabOrder( dateEditPrevoyanceDecesDateEffet, lineEditPrevoyanceDecesDuree );
    setTabOrder( lineEditPrevoyanceDecesDuree, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgGarantieDeces::~dlgGarantieDeces()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgGarantieDeces::languageChange()
{
    setCaption( trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x65\x20\x67\x61\x72\x61\x6e\x74\x69\x65\x20\x64\xc3\xa9\x63\xc3\xa8\x73" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    labelPrevoyanceDecesCapital1->setText( tr( "Capital" ) );
    lineEditPrevoyanceDecesCapital->setInputMask( QString::null );
    labelPrevoyanceDecesMaladie1->setText( tr( "Maladie" ) );
    lineEditPrevoyanceDecesMaladie->setInputMask( QString::null );
    labelPrevoyanceDecesAccident1->setText( tr( "Accident" ) );
    lineEditPrevoyanceDecesAccident->setInputMask( QString::null );
    labelPrevoyanceDecesBeneficiaire1->setText( trUtf8( "\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65" ) );
    comboBoxPrevoyanceDecesBeneficiaire->clear();
    comboBoxPrevoyanceDecesBeneficiaire->insertItem( tr( "Famille" ) );
    comboBoxPrevoyanceDecesBeneficiaire->insertItem( trUtf8( "\x41\x73\x73\x6f\x63\x69\xc3\xa9\x73" ) );
    comboBoxPrevoyanceDecesBeneficiaire->insertItem( tr( "Banque" ) );
    comboBoxPrevoyanceDecesBeneficiaire->insertItem( tr( "Entreprise" ) );
    comboBoxPrevoyanceDecesBeneficiaire->insertItem( tr( "Autre" ) );
    labelPrevoyanceDecesAutre1->setText( tr( "Si autre preciser" ) );
    labelPrevoyanceDecesFiscalite1->setText( trUtf8( "\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9" ) );
    labelPrevoyanceDecesCompagnie1->setText( tr( "Compagnie" ) );
    labelPrevoyanceDecesDate1->setText( tr( "Date d'effet" ) );
    labelPrevoyanceDecesDuree->setText( trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );
    comboBoxPrevoyanceDecesFiscalite->clear();
    comboBoxPrevoyanceDecesFiscalite->insertItem( tr( "Assurance vie" ) );
    comboBoxPrevoyanceDecesFiscalite->insertItem( tr( "Madelin" ) );
    lineEditPrevoyanceDecesDuree->setInputMask( QString::null );
}

