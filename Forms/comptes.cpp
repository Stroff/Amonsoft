/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\comptes.ui'
**
** Created: ven. 6. avr. 16:32:14 2007
**      by: The User Interface Compiler ($Id: comptes.cpp,v 1.23 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\comptes.h"

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

#include "comptes.ui.h"
/*
 *  Constructs a dlgComptes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgComptes::dlgComptes( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgComptes" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, sizePolicy().hasHeightForWidth() ) );
    dlgComptesLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgComptesLayout"); 

    layout65 = new QHBoxLayout( 0, 0, 6, "layout65"); 

    pushButtonOk = new QPushButton( this, "pushButtonOk" );
    layout65->addWidget( pushButtonOk );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );
    layout65->addWidget( pushButtonKo );

    dlgComptesLayout->addMultiCellLayout( layout65, 9, 9, 0, 3 );

    textLabel39 = new QLabel( this, "textLabel39" );

    dlgComptesLayout->addWidget( textLabel39, 6, 0 );

    lineEditCommentaire = new QLineEdit( this, "lineEditCommentaire" );
    lineEditCommentaire->setFrameShape( QLineEdit::LineEditPanel );
    lineEditCommentaire->setFrameShadow( QLineEdit::Sunken );

    dlgComptesLayout->addMultiCellWidget( lineEditCommentaire, 8, 8, 2, 3 );

    lineEditInvAnnuel = new QLineEdit( this, "lineEditInvAnnuel" );

    dlgComptesLayout->addMultiCellWidget( lineEditInvAnnuel, 3, 3, 2, 3 );

    textLabel35 = new QLabel( this, "textLabel35" );

    dlgComptesLayout->addMultiCellWidget( textLabel35, 1, 1, 0, 1 );

    textLabel40 = new QLabel( this, "textLabel40" );

    dlgComptesLayout->addWidget( textLabel40, 5, 0 );

    textLabel34 = new QLabel( this, "textLabel34" );

    dlgComptesLayout->addWidget( textLabel34, 0, 0 );

    comboBoxType = new QComboBox( FALSE, this, "comboBoxType" );

    dlgComptesLayout->addMultiCellWidget( comboBoxType, 0, 0, 1, 3 );

    lineEditRendement = new QLineEdit( this, "lineEditRendement" );
    lineEditRendement->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditRendement->sizePolicy().hasHeightForWidth() ) );

    dlgComptesLayout->addWidget( lineEditRendement, 7, 3 );

    lineEditTerme = new QLineEdit( this, "lineEditTerme" );

    dlgComptesLayout->addMultiCellWidget( lineEditTerme, 4, 4, 2, 3 );

    textLabel37 = new QLabel( this, "textLabel37" );

    dlgComptesLayout->addMultiCellWidget( textLabel37, 3, 3, 0, 1 );

    textLabel42 = new QLabel( this, "textLabel42" );

    dlgComptesLayout->addMultiCellWidget( textLabel42, 8, 8, 0, 1 );

    lineEditCapital = new QLineEdit( this, "lineEditCapital" );

    dlgComptesLayout->addMultiCellWidget( lineEditCapital, 5, 5, 2, 3 );

    textLabel36 = new QLabel( this, "textLabel36" );

    dlgComptesLayout->addWidget( textLabel36, 2, 0 );

    textLabel41 = new QLabel( this, "textLabel41" );

    dlgComptesLayout->addMultiCellWidget( textLabel41, 7, 7, 0, 2 );

    textLabel38 = new QLabel( this, "textLabel38" );

    dlgComptesLayout->addMultiCellWidget( textLabel38, 4, 4, 0, 1 );

    dateEditDateEffet = new QDateEdit( this, "dateEditDateEffet" );
    dateEditDateEffet->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditDateEffet->sizePolicy().hasHeightForWidth() ) );

    dlgComptesLayout->addMultiCellWidget( dateEditDateEffet, 2, 2, 2, 3 );

    dateEditCapital = new QDateEdit( this, "dateEditCapital" );
    dateEditCapital->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditCapital->sizePolicy().hasHeightForWidth() ) );

    dlgComptesLayout->addMultiCellWidget( dateEditCapital, 6, 6, 2, 3 );

    comboBoxCompagnie = new QComboBox( FALSE, this, "comboBoxCompagnie" );

    dlgComptesLayout->addMultiCellWidget( comboBoxCompagnie, 1, 1, 2, 3 );
    languageChange();
    resize( QSize(213, 286).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( comboBoxType, comboBoxCompagnie );
    setTabOrder( comboBoxCompagnie, dateEditDateEffet );
    setTabOrder( dateEditDateEffet, lineEditInvAnnuel );
    setTabOrder( lineEditInvAnnuel, lineEditTerme );
    setTabOrder( lineEditTerme, lineEditCapital );
    setTabOrder( lineEditCapital, dateEditCapital );
    setTabOrder( dateEditCapital, lineEditRendement );
    setTabOrder( lineEditRendement, lineEditCommentaire );
    setTabOrder( lineEditCommentaire, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgComptes::~dlgComptes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgComptes::languageChange()
{
    setCaption( tr( "Ajouter un compte" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    textLabel39->setText( tr( "A la date" ) );
    lineEditInvAnnuel->setInputMask( tr( "000000000; " ) );
    textLabel35->setText( tr( "Compagnie" ) );
    textLabel40->setText( trUtf8( "\x4b\x20\x28\xe2\x82\xac\x29" ) );
    textLabel34->setText( tr( "Type" ) );
    comboBoxType->clear();
    comboBoxType->insertItem( tr( "CODEVI/Livret A" ) );
    comboBoxType->insertItem( tr( "PEL" ) );
    comboBoxType->insertItem( tr( "CEL" ) );
    comboBoxType->insertItem( trUtf8( "\x53\x69\x63\x61\x76\x20\x4d\x6f\x6e\xc3\xa9\x74\x61\x69\x72\x65\x73" ) );
    comboBoxType->insertItem( tr( "Obligations" ) );
    comboBoxType->insertItem( tr( "Actions" ) );
    comboBoxType->insertItem( tr( "PEA" ) );
    comboBoxType->insertItem( tr( "PEP bancaire" ) );
    comboBoxType->insertItem( tr( "OPCVM" ) );
    lineEditRendement->setInputMask( QString::null );
    textLabel37->setText( trUtf8( "\x49\x6e\x76\x20\x41\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    textLabel42->setText( tr( "Commentaires" ) );
    lineEditCapital->setInputMask( tr( "000000000; " ) );
    textLabel36->setText( tr( "Date d'effet" ) );
    textLabel41->setText( tr( "Rendement N-1 (%)" ) );
    textLabel38->setText( tr( "Terme" ) );
}

