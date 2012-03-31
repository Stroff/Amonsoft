/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\assurancevie.ui'
**
** Created: ven. 6. avr. 16:32:17 2007
**      by: The User Interface Compiler ($Id: assurancevie.cpp,v 1.24 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\assurancevie.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "assurancevie.ui.h"
/*
 *  Constructs a dlgAssuranceVie as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgAssuranceVie::dlgAssuranceVie( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgAssuranceVie" );
    dlgAssuranceVieLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgAssuranceVieLayout"); 

    layout61 = new QGridLayout( 0, 1, 1, 0, 6, "layout61"); 

    lineEditPEP = new QLineEdit( this, "lineEditPEP" );
    lineEditPEP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditPEP->sizePolicy().hasHeightForWidth() ) );
    lineEditPEP->setFrameShape( QLineEdit::LineEditPanel );
    lineEditPEP->setFrameShadow( QLineEdit::Sunken );

    layout61->addWidget( lineEditPEP, 0, 3 );

    textLabel33_2 = new QLabel( this, "textLabel33_2" );

    layout61->addWidget( textLabel33_2, 0, 2 );

    textLabel33_3 = new QLabel( this, "textLabel33_3" );

    layout61->addWidget( textLabel33_3, 1, 0 );

    lineEditMS = new QLineEdit( this, "lineEditMS" );
    lineEditMS->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditMS->sizePolicy().hasHeightForWidth() ) );

    layout61->addWidget( lineEditMS, 1, 1 );

    lineEditFD = new QLineEdit( this, "lineEditFD" );
    lineEditFD->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFD->sizePolicy().hasHeightForWidth() ) );

    layout61->addWidget( lineEditFD, 1, 3 );

    lineEditDSK = new QLineEdit( this, "lineEditDSK" );
    lineEditDSK->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditDSK->sizePolicy().hasHeightForWidth() ) );

    layout61->addWidget( lineEditDSK, 0, 1 );

    textLabel33_4 = new QLabel( this, "textLabel33_4" );

    layout61->addWidget( textLabel33_4, 1, 2 );

    textLabel33 = new QLabel( this, "textLabel33" );

    layout61->addWidget( textLabel33, 0, 0 );

    dlgAssuranceVieLayout->addMultiCellLayout( layout61, 7, 7, 0, 1 );

    layout65 = new QHBoxLayout( 0, 0, 6, "layout65"); 

    pushButtonOk = new QPushButton( this, "pushButtonOk" );
    layout65->addWidget( pushButtonOk );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );
    layout65->addWidget( pushButtonKo );

    dlgAssuranceVieLayout->addMultiCellLayout( layout65, 8, 8, 0, 1 );

    textLabel29 = new QLabel( this, "textLabel29" );

    dlgAssuranceVieLayout->addWidget( textLabel29, 3, 0 );

    lineEditContrat = new QLineEdit( this, "lineEditContrat" );
    lineEditContrat->setFrameShape( QLineEdit::LineEditPanel );
    lineEditContrat->setFrameShadow( QLineEdit::Sunken );

    dlgAssuranceVieLayout->addWidget( lineEditContrat, 0, 1 );

    textLabel26 = new QLabel( this, "textLabel26" );

    dlgAssuranceVieLayout->addWidget( textLabel26, 0, 0 );

    dateEditDateCapital = new QDateEdit( this, "dateEditDateCapital" );
    dateEditDateCapital->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditDateCapital->sizePolicy().hasHeightForWidth() ) );

    dlgAssuranceVieLayout->addWidget( dateEditDateCapital, 6, 1 );

    textLabel30 = new QLabel( this, "textLabel30" );

    dlgAssuranceVieLayout->addWidget( textLabel30, 4, 0 );

    lineEditTerme = new QLineEdit( this, "lineEditTerme" );

    dlgAssuranceVieLayout->addWidget( lineEditTerme, 4, 1 );

    dateEditEffet = new QDateEdit( this, "dateEditEffet" );

    dlgAssuranceVieLayout->addWidget( dateEditEffet, 2, 1 );

    textLabel27 = new QLabel( this, "textLabel27" );

    dlgAssuranceVieLayout->addWidget( textLabel27, 1, 0 );

    lineEditCapital = new QLineEdit( this, "lineEditCapital" );

    dlgAssuranceVieLayout->addWidget( lineEditCapital, 5, 1 );

    textLabel31 = new QLabel( this, "textLabel31" );

    dlgAssuranceVieLayout->addWidget( textLabel31, 5, 0 );

    textLabel32 = new QLabel( this, "textLabel32" );

    dlgAssuranceVieLayout->addWidget( textLabel32, 6, 0 );

    lineEditInvAnnuel = new QLineEdit( this, "lineEditInvAnnuel" );

    dlgAssuranceVieLayout->addWidget( lineEditInvAnnuel, 3, 1 );

    textLabel28 = new QLabel( this, "textLabel28" );

    dlgAssuranceVieLayout->addWidget( textLabel28, 2, 0 );

    comboBoxCompagnie = new QComboBox( FALSE, this, "comboBoxCompagnie" );

    dlgAssuranceVieLayout->addWidget( comboBoxCompagnie, 1, 1 );
    languageChange();
    resize( QSize(275, 290).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( lineEditContrat, comboBoxCompagnie );
    setTabOrder( comboBoxCompagnie, dateEditEffet );
    setTabOrder( dateEditEffet, lineEditInvAnnuel );
    setTabOrder( lineEditInvAnnuel, lineEditTerme );
    setTabOrder( lineEditTerme, lineEditCapital );
    setTabOrder( lineEditCapital, dateEditDateCapital );
    setTabOrder( dateEditDateCapital, lineEditDSK );
    setTabOrder( lineEditDSK, lineEditPEP );
    setTabOrder( lineEditPEP, lineEditMS );
    setTabOrder( lineEditMS, lineEditFD );
    setTabOrder( lineEditFD, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgAssuranceVie::~dlgAssuranceVie()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgAssuranceVie::languageChange()
{
    setCaption( tr( "Ajouter une assurance vie" ) );
    lineEditPEP->setInputMask( QString::null );
    textLabel33_2->setText( tr( "PEP" ) );
    textLabel33_3->setText( tr( "MS" ) );
    lineEditMS->setInputMask( QString::null );
    lineEditFD->setInputMask( QString::null );
    lineEditDSK->setInputMask( QString::null );
    textLabel33_4->setText( trUtf8( "\x46\x44\x20\x28\xe2\x82\xac\x29" ) );
    textLabel33->setText( tr( "DSK" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    textLabel29->setText( trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    textLabel26->setText( tr( "Contrat" ) );
    textLabel30->setText( tr( "Terme" ) );
    textLabel27->setText( tr( "Compagnie" ) );
    lineEditCapital->setInputMask( QString::null );
    textLabel31->setText( trUtf8( "\x4b\x20\x63\x6f\x6e\x73\x74\x69\x74\x75\xc3\xa9\x20\x28\xe2\x82\xac\x29" ) );
    textLabel32->setText( tr( "A la date" ) );
    lineEditInvAnnuel->setInputMask( QString::null );
    textLabel28->setText( tr( "Date d'effet" ) );
}

