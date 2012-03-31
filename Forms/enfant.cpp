/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\enfant.ui'
**
** Created: ven. 6. avr. 16:32:11 2007
**      by: The User Interface Compiler ($Id: enfant.cpp,v 1.24 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\enfant.h"

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

#include "enfant.ui.h"
/*
 *  Constructs a dlgEnfant as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgEnfant::dlgEnfant( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgEnfant" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, sizePolicy().hasHeightForWidth() ) );
    dlgEnfantLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgEnfantLayout"); 

    layout378 = new QGridLayout( 0, 1, 1, 0, 6, "layout378"); 

    labelFamilleEnfantDateNaissance = new QLabel( this, "labelFamilleEnfantDateNaissance" );
    labelFamilleEnfantDateNaissance->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleEnfantDateNaissance->sizePolicy().hasHeightForWidth() ) );
    labelFamilleEnfantDateNaissance->setMaximumSize( QSize( 32767, 20 ) );

    layout378->addMultiCellWidget( labelFamilleEnfantDateNaissance, 2, 2, 0, 1 );

    lineEditFamilleNom = new QLineEdit( this, "lineEditFamilleNom" );
    lineEditFamilleNom->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleNom->setFrameShadow( QLineEdit::Sunken );

    layout378->addMultiCellWidget( lineEditFamilleNom, 0, 0, 1, 2 );

    labelFamillePrenom = new QLabel( this, "labelFamillePrenom" );
    labelFamillePrenom->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamillePrenom->sizePolicy().hasHeightForWidth() ) );

    layout378->addWidget( labelFamillePrenom, 1, 0 );

    comboBoxFamilleEnfantAcharge = new QComboBox( FALSE, this, "comboBoxFamilleEnfantAcharge" );

    layout378->addMultiCellWidget( comboBoxFamilleEnfantAcharge, 3, 3, 1, 2 );

    lineEditFamillePrenom = new QLineEdit( this, "lineEditFamillePrenom" );

    layout378->addMultiCellWidget( lineEditFamillePrenom, 1, 1, 1, 2 );

    comboBoxFamilleFinancementEtudes = new QComboBox( FALSE, this, "comboBoxFamilleFinancementEtudes" );

    layout378->addMultiCellWidget( comboBoxFamilleFinancementEtudes, 4, 4, 1, 2 );

    labelFamilleNotes = new QLabel( this, "labelFamilleNotes" );
    labelFamilleNotes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleNotes->sizePolicy().hasHeightForWidth() ) );

    layout378->addWidget( labelFamilleNotes, 5, 0 );

    lineEditFamilleNotes = new QLineEdit( this, "lineEditFamilleNotes" );

    layout378->addMultiCellWidget( lineEditFamilleNotes, 5, 5, 1, 2 );

    labelFamilleNom = new QLabel( this, "labelFamilleNom" );
    labelFamilleNom->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleNom->sizePolicy().hasHeightForWidth() ) );

    layout378->addWidget( labelFamilleNom, 0, 0 );

    labelFamilleCharge = new QLabel( this, "labelFamilleCharge" );
    labelFamilleCharge->setEnabled( TRUE );
    labelFamilleCharge->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleCharge->sizePolicy().hasHeightForWidth() ) );

    layout378->addWidget( labelFamilleCharge, 3, 0 );

    dateEditFamilleEnfantDateNaissance = new QDateEdit( this, "dateEditFamilleEnfantDateNaissance" );
    dateEditFamilleEnfantDateNaissance->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditFamilleEnfantDateNaissance->sizePolicy().hasHeightForWidth() ) );

    layout378->addWidget( dateEditFamilleEnfantDateNaissance, 2, 2 );

    labelFamilleFinancementEtudes = new QLabel( this, "labelFamilleFinancementEtudes" );
    labelFamilleFinancementEtudes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleFinancementEtudes->sizePolicy().hasHeightForWidth() ) );

    layout378->addWidget( labelFamilleFinancementEtudes, 4, 0 );

    dlgEnfantLayout->addMultiCellLayout( layout378, 0, 0, 0, 1 );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );

    dlgEnfantLayout->addWidget( pushButtonKo, 1, 1 );

    pushButtonOk = new QPushButton( this, "pushButtonOk" );

    dlgEnfantLayout->addWidget( pushButtonOk, 1, 0 );
    languageChange();
    resize( QSize(262, 236).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( lineEditFamilleNom, lineEditFamillePrenom );
    setTabOrder( lineEditFamillePrenom, dateEditFamilleEnfantDateNaissance );
    setTabOrder( dateEditFamilleEnfantDateNaissance, comboBoxFamilleEnfantAcharge );
    setTabOrder( comboBoxFamilleEnfantAcharge, comboBoxFamilleFinancementEtudes );
    setTabOrder( comboBoxFamilleFinancementEtudes, lineEditFamilleNotes );
    setTabOrder( lineEditFamilleNotes, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgEnfant::~dlgEnfant()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgEnfant::languageChange()
{
    setCaption( tr( "Ajouter un enfant" ) );
    labelFamilleEnfantDateNaissance->setText( tr( "Date de naissance" ) );
    labelFamillePrenom->setText( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    comboBoxFamilleEnfantAcharge->clear();
    comboBoxFamilleEnfantAcharge->insertItem( tr( "Oui" ) );
    comboBoxFamilleEnfantAcharge->insertItem( tr( "Non" ) );
    comboBoxFamilleFinancementEtudes->clear();
    comboBoxFamilleFinancementEtudes->insertItem( tr( "Oui" ) );
    comboBoxFamilleFinancementEtudes->insertItem( tr( "Non" ) );
    labelFamilleNotes->setText( tr( "Notes" ) );
    labelFamilleNom->setText( tr( "Nom" ) );
    labelFamilleCharge->setText( tr( "A charge" ) );
    labelFamilleFinancementEtudes->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x46\x69\x6e\x61\x6e\x63\x65\x6d\x65\x6e\x74\x20\x64\x65\x73\x20\xc3\xa9\x74\x75\x64\x65\x73\x3c\x2f\x70\x3e" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    pushButtonOk->setText( tr( "Valider" ) );
}

