/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\retraite.ui'
**
** Created: ven. 6. avr. 16:32:05 2007
**      by: The User Interface Compiler ($Id: retraite.cpp,v 1.22 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\retraite.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "retraite.ui.h"
/*
 *  Constructs a dlgRetraite as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgRetraite::dlgRetraite( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgRetraite" );
    dlgRetraiteLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgRetraiteLayout"); 

    layout83 = new QHBoxLayout( 0, 0, 6, "layout83"); 

    textLabel37 = new QLabel( this, "textLabel37" );
    layout83->addWidget( textLabel37 );

    lineEditContrat = new QLineEdit( this, "lineEditContrat" );
    lineEditContrat->setFrameShape( QLineEdit::LineEditPanel );
    lineEditContrat->setFrameShadow( QLineEdit::Sunken );
    layout83->addWidget( lineEditContrat );

    textLabel42 = new QLabel( this, "textLabel42" );
    layout83->addWidget( textLabel42 );

    dateEditEffet = new QDateEdit( this, "dateEditEffet" );
    dateEditEffet->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditEffet->sizePolicy().hasHeightForWidth() ) );
    layout83->addWidget( dateEditEffet );

    dlgRetraiteLayout->addMultiCellLayout( layout83, 0, 0, 0, 3 );

    layout81 = new QHBoxLayout( 0, 0, 6, "layout81"); 

    textLabel39 = new QLabel( this, "textLabel39" );
    layout81->addWidget( textLabel39 );

    lineEditCollegue = new QLineEdit( this, "lineEditCollegue" );
    lineEditCollegue->setFrameShape( QLineEdit::LineEditPanel );
    lineEditCollegue->setFrameShadow( QLineEdit::Sunken );
    layout81->addWidget( lineEditCollegue );

    dlgRetraiteLayout->addMultiCellLayout( layout81, 2, 2, 0, 1 );

    layout84 = new QGridLayout( 0, 1, 1, 0, 6, "layout84"); 

    textLabel47 = new QLabel( this, "textLabel47" );

    layout84->addWidget( textLabel47, 3, 0 );

    lineEditFisc82AD = new QLineEdit( this, "lineEditFisc82AD" );
    lineEditFisc82AD->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFisc82AD->sizePolicy().hasHeightForWidth() ) );

    layout84->addWidget( lineEditFisc82AD, 1, 1 );

    lineEditFisc82SD = new QLineEdit( this, "lineEditFisc82SD" );
    lineEditFisc82SD->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFisc82SD->sizePolicy().hasHeightForWidth() ) );

    layout84->addWidget( lineEditFisc82SD, 2, 1 );

    textLabel44 = new QLabel( this, "textLabel44" );

    layout84->addWidget( textLabel44, 0, 0 );

    lineEditFisc82 = new QLineEdit( this, "lineEditFisc82" );
    lineEditFisc82->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFisc82->sizePolicy().hasHeightForWidth() ) );

    layout84->addWidget( lineEditFisc82, 0, 1 );

    textLabel45 = new QLabel( this, "textLabel45" );

    layout84->addWidget( textLabel45, 1, 0 );

    lineEditFisc39 = new QLineEdit( this, "lineEditFisc39" );
    lineEditFisc39->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFisc39->sizePolicy().hasHeightForWidth() ) );

    layout84->addWidget( lineEditFisc39, 3, 1 );

    textLabel46 = new QLabel( this, "textLabel46" );

    layout84->addWidget( textLabel46, 2, 0 );

    dlgRetraiteLayout->addMultiCellLayout( layout84, 2, 3, 2, 3 );

    layout82 = new QGridLayout( 0, 1, 1, 0, 6, "layout82"); 

    textLabel40 = new QLabel( this, "textLabel40" );

    layout82->addMultiCellWidget( textLabel40, 0, 0, 0, 1 );

    lineEditTB = new QLineEdit( this, "lineEditTB" );
    lineEditTB->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditTB->sizePolicy().hasHeightForWidth() ) );
    lineEditTB->setMaximumSize( QSize( 30, 32767 ) );

    layout82->addWidget( lineEditTB, 1, 2 );

    lineEditTC = new QLineEdit( this, "lineEditTC" );
    lineEditTC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditTC->sizePolicy().hasHeightForWidth() ) );
    lineEditTC->setMaximumSize( QSize( 30, 32767 ) );

    layout82->addWidget( lineEditTC, 2, 2 );

    textLabel41_2 = new QLabel( this, "textLabel41_2" );

    layout82->addWidget( textLabel41_2, 2, 1 );

    textLabel41 = new QLabel( this, "textLabel41" );
    textLabel41->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel41->sizePolicy().hasHeightForWidth() ) );

    layout82->addWidget( textLabel41, 1, 1 );

    lineEditTA = new QLineEdit( this, "lineEditTA" );
    lineEditTA->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditTA->sizePolicy().hasHeightForWidth() ) );
    lineEditTA->setMaximumSize( QSize( 30, 32767 ) );

    layout82->addWidget( lineEditTA, 0, 2 );
    spacer23 = new QSpacerItem( 20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout82->addMultiCell( spacer23, 1, 2, 0, 0 );

    dlgRetraiteLayout->addMultiCellLayout( layout82, 3, 3, 0, 1 );

    layout65 = new QHBoxLayout( 0, 0, 6, "layout65"); 

    pushButtonOk = new QPushButton( this, "pushButtonOk" );
    layout65->addWidget( pushButtonOk );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );
    layout65->addWidget( pushButtonKo );

    dlgRetraiteLayout->addMultiCellLayout( layout65, 4, 4, 0, 3 );

    textLabel38 = new QLabel( this, "textLabel38" );

    dlgRetraiteLayout->addWidget( textLabel38, 1, 0 );

    comboBoxCompagnie = new QComboBox( FALSE, this, "comboBoxCompagnie" );

    dlgRetraiteLayout->addMultiCellWidget( comboBoxCompagnie, 1, 1, 1, 2 );

    textLabel43 = new QLabel( this, "textLabel43" );

    dlgRetraiteLayout->addWidget( textLabel43, 1, 3 );
    languageChange();
    resize( QSize(377, 214).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( lineEditContrat, dateEditEffet );
    setTabOrder( dateEditEffet, comboBoxCompagnie );
    setTabOrder( comboBoxCompagnie, lineEditCollegue );
    setTabOrder( lineEditCollegue, lineEditTA );
    setTabOrder( lineEditTA, lineEditTB );
    setTabOrder( lineEditTB, lineEditTC );
    setTabOrder( lineEditTC, lineEditFisc82 );
    setTabOrder( lineEditFisc82, lineEditFisc82AD );
    setTabOrder( lineEditFisc82AD, lineEditFisc82SD );
    setTabOrder( lineEditFisc82SD, lineEditFisc39 );
    setTabOrder( lineEditFisc39, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgRetraite::~dlgRetraite()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgRetraite::languageChange()
{
    setCaption( tr( "Ajouter une retraite" ) );
    textLabel37->setText( tr( "Contrat" ) );
    textLabel42->setText( tr( "Date d'effet" ) );
    textLabel39->setText( trUtf8( "\x43\x6f\x6c\x6c\xc3\xa8\x67\x75\x65" ) );
    textLabel47->setText( tr( "39" ) );
    lineEditFisc82AD->setInputMask( QString::null );
    lineEditFisc82SD->setInputMask( QString::null );
    textLabel44->setText( tr( "82" ) );
    lineEditFisc82->setInputMask( QString::null );
    textLabel45->setText( tr( "82AD" ) );
    lineEditFisc39->setInputMask( QString::null );
    textLabel46->setText( tr( "82SD" ) );
    textLabel40->setText( tr( "Taux TA (%)" ) );
    lineEditTB->setInputMask( QString::null );
    lineEditTC->setInputMask( QString::null );
    textLabel41_2->setText( tr( "TC (%)" ) );
    textLabel41->setText( tr( "TB (%)" ) );
    lineEditTA->setInputMask( QString::null );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    textLabel38->setText( tr( "Compagnie" ) );
    textLabel43->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x3c\x62\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x62\x3e\x3c\x2f\x70\x3e" ) );
}

