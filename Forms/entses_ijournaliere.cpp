/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\entses_ijournaliere.ui'
**
** Created: ven. 6. avr. 17:19:51 2007
**      by: The User Interface Compiler ($Id: entses_ijournaliere.cpp,v 1.2 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\entses_ijournaliere.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "entses_ijournaliere.ui.h"
/*
 *  Constructs a dlgIJournaliere as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgIJournaliere::dlgIJournaliere( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgIJournaliere" );
    dlgIJournaliereLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgIJournaliereLayout"); 

    textLabel2 = new QLabel( this, "textLabel2" );

    dlgIJournaliereLayout->addMultiCellWidget( textLabel2, 3, 5, 0, 1 );

    comboBoxTypeSal = new QComboBox( FALSE, this, "comboBoxTypeSal" );

    dlgIJournaliereLayout->addMultiCellWidget( comboBoxTypeSal, 0, 0, 0, 2 );

    lineEditContrat = new QLineEdit( this, "lineEditContrat" );

    dlgIJournaliereLayout->addMultiCellWidget( lineEditContrat, 1, 1, 1, 2 );

    comboBoxCompagnie = new QComboBox( FALSE, this, "comboBoxCompagnie" );

    dlgIJournaliereLayout->addMultiCellWidget( comboBoxCompagnie, 4, 5, 2, 2 );

    textLabel1 = new QLabel( this, "textLabel1" );

    dlgIJournaliereLayout->addMultiCellWidget( textLabel1, 1, 2, 0, 0 );

    pushButtonko = new QPushButton( this, "pushButtonko" );

    dlgIJournaliereLayout->addMultiCellWidget( pushButtonko, 9, 9, 3, 5 );

    pushButtonok = new QPushButton( this, "pushButtonok" );

    dlgIJournaliereLayout->addMultiCellWidget( pushButtonok, 9, 9, 0, 2 );

    textLabel13 = new QLabel( this, "textLabel13" );

    dlgIJournaliereLayout->addMultiCellWidget( textLabel13, 0, 0, 4, 5 );

    textLabel15 = new QLabel( this, "textLabel15" );

    dlgIJournaliereLayout->addMultiCellWidget( textLabel15, 6, 6, 0, 2 );

    textLabel16 = new QLabel( this, "textLabel16" );

    dlgIJournaliereLayout->addMultiCellWidget( textLabel16, 7, 7, 0, 1 );

    textLabel17 = new QLabel( this, "textLabel17" );

    dlgIJournaliereLayout->addMultiCellWidget( textLabel17, 8, 8, 0, 1 );

    textLabel20 = new QLabel( this, "textLabel20" );

    dlgIJournaliereLayout->addWidget( textLabel20, 8, 4 );

    lineEditInvMontant = new QLineEdit( this, "lineEditInvMontant" );

    dlgIJournaliereLayout->addWidget( lineEditInvMontant, 7, 2 );

    lineEditInvPartielle = new QLineEdit( this, "lineEditInvPartielle" );

    dlgIJournaliereLayout->addWidget( lineEditInvPartielle, 8, 2 );

    lineEditIJMontant = new QLineEdit( this, "lineEditIJMontant" );

    dlgIJournaliereLayout->addWidget( lineEditIJMontant, 1, 5 );

    lineEditIJFranchise = new QLineEdit( this, "lineEditIJFranchise" );

    dlgIJournaliereLayout->addMultiCellWidget( lineEditIJFranchise, 2, 3, 5, 5 );

    lineEditIJReduite = new QLineEdit( this, "lineEditIJReduite" );

    dlgIJournaliereLayout->addWidget( lineEditIJReduite, 5, 5 );

    lineEditTA = new QLineEdit( this, "lineEditTA" );

    dlgIJournaliereLayout->addWidget( lineEditTA, 6, 5 );

    lineEditTB = new QLineEdit( this, "lineEditTB" );
    lineEditTB->setFrameShape( QLineEdit::LineEditPanel );
    lineEditTB->setFrameShadow( QLineEdit::Sunken );

    dlgIJournaliereLayout->addWidget( lineEditTB, 7, 5 );

    lineEditTC = new QLineEdit( this, "lineEditTC" );

    dlgIJournaliereLayout->addWidget( lineEditTC, 8, 5 );
    spacer42 = new QSpacerItem( 20, 141, QSizePolicy::Minimum, QSizePolicy::Expanding );
    dlgIJournaliereLayout->addMultiCell( spacer42, 0, 8, 3, 3 );

    textLabel11 = new QLabel( this, "textLabel11" );

    dlgIJournaliereLayout->addWidget( textLabel11, 1, 4 );

    textLabel12 = new QLabel( this, "textLabel12" );

    dlgIJournaliereLayout->addMultiCellWidget( textLabel12, 2, 4, 4, 4 );

    textLabel14 = new QLabel( this, "textLabel14" );

    dlgIJournaliereLayout->addWidget( textLabel14, 5, 4 );

    textLabel18 = new QLabel( this, "textLabel18" );

    dlgIJournaliereLayout->addWidget( textLabel18, 6, 4 );

    textLabel19 = new QLabel( this, "textLabel19" );

    dlgIJournaliereLayout->addWidget( textLabel19, 7, 4 );
    languageChange();
    resize( QSize(487, 236).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonko, SIGNAL( clicked() ), this, SLOT( close() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgIJournaliere::~dlgIJournaliere()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgIJournaliere::languageChange()
{
    setCaption( trUtf8( "\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x20\x6a\x6f\x75\x72\x6e\x61\x6c\x69\xc3\xa8\x72\x65" ) );
    textLabel2->setText( tr( "Compagnie" ) );
    comboBoxTypeSal->clear();
    comboBoxTypeSal->insertItem( tr( "Non cadres" ) );
    comboBoxTypeSal->insertItem( tr( "Cadres" ) );
    textLabel1->setText( tr( "Contrat" ) );
    pushButtonko->setText( tr( "Annuler" ) );
    pushButtonok->setText( tr( "Valider" ) );
    textLabel13->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x3c\x62\x3e\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x20\x6a\x6f\x75\x72\x6e\x61\x6c\x69\xc3\xa8\x72\x65\x3c\x2f\x62\x3e\x3c\x2f\x70\x3e" ) );
    textLabel15->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x3c\x62\x3e\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x3c\x2f\x62\x3e\x3c\x2f\x70\x3e" ) );
    textLabel16->setText( tr( "Montant (%)" ) );
    textLabel17->setText( trUtf8( "\x50\x61\x72\x74\x69\x65\x6c\x6c\x65\x20\x28\xe2\x82\xac\x29" ) );
    textLabel20->setText( tr( "TC (%)" ) );
    textLabel11->setText( tr( "Montant (%)" ) );
    textLabel12->setText( trUtf8( "\x46\x72\x61\x6e\x63\x68\x69\x73\x65\x20\x28\xe2\x82\xac\x29" ) );
    textLabel14->setText( trUtf8( "\x52\xc3\xa9\x64\x75\x69\x74\x65\x20\x28\xe2\x82\xac\x29" ) );
    textLabel18->setText( tr( "TA (%)" ) );
    textLabel19->setText( tr( "TB (%)" ) );
}

