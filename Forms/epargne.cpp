/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\epargne.ui'
**
** Created: ven. 6. avr. 16:32:10 2007
**      by: The User Interface Compiler ($Id: epargne.cpp,v 1.25 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\epargne.h"

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

#include "epargne.ui.h"
/*
 *  Constructs a dlgEpargne as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgEpargne::dlgEpargne( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgEpargne" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)3, 0, 0, sizePolicy().hasHeightForWidth() ) );
    dlgEpargneLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgEpargneLayout"); 

    layout58 = new QHBoxLayout( 0, 0, 6, "layout58"); 

    pushButtonOk = new QPushButton( this, "pushButtonOk" );
    layout58->addWidget( pushButtonOk );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );
    layout58->addWidget( pushButtonKo );

    dlgEpargneLayout->addMultiCellLayout( layout58, 8, 8, 0, 4 );

    textLabel20 = new QLabel( this, "textLabel20" );

    dlgEpargneLayout->addWidget( textLabel20, 1, 0 );

    lineEditInvAnnuel = new QLineEdit( this, "lineEditInvAnnuel" );
    lineEditInvAnnuel->setFrameShape( QLineEdit::LineEditPanel );
    lineEditInvAnnuel->setFrameShadow( QLineEdit::Sunken );

    dlgEpargneLayout->addMultiCellWidget( lineEditInvAnnuel, 2, 2, 3, 4 );

    textLabel22 = new QLabel( this, "textLabel22" );

    dlgEpargneLayout->addWidget( textLabel22, 3, 0 );

    textLabel19 = new QLabel( this, "textLabel19" );

    dlgEpargneLayout->addWidget( textLabel19, 0, 0 );

    lineEditContrat = new QLineEdit( this, "lineEditContrat" );

    dlgEpargneLayout->addMultiCellWidget( lineEditContrat, 5, 5, 1, 4 );

    textLabel21 = new QLabel( this, "textLabel21" );

    dlgEpargneLayout->addMultiCellWidget( textLabel21, 2, 2, 0, 2 );

    textLabel25 = new QLabel( this, "textLabel25" );

    dlgEpargneLayout->addMultiCellWidget( textLabel25, 6, 7, 0, 2 );

    dateEditDateEpargne = new QDateEdit( this, "dateEditDateEpargne" );

    dlgEpargneLayout->addWidget( dateEditDateEpargne, 4, 4 );

    textLabel24 = new QLabel( this, "textLabel24" );

    dlgEpargneLayout->addWidget( textLabel24, 5, 0 );

    lineEditEpargne = new QLineEdit( this, "lineEditEpargne" );

    dlgEpargneLayout->addMultiCellWidget( lineEditEpargne, 3, 3, 3, 4 );

    comboBoxTypeEpargne = new QComboBox( FALSE, this, "comboBoxTypeEpargne" );

    dlgEpargneLayout->addMultiCellWidget( comboBoxTypeEpargne, 0, 0, 3, 4 );

    textLabel23 = new QLabel( this, "textLabel23" );

    dlgEpargneLayout->addMultiCellWidget( textLabel23, 4, 4, 0, 3 );

    dateEditDateEffet = new QDateEdit( this, "dateEditDateEffet" );
    dateEditDateEffet->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditDateEffet->sizePolicy().hasHeightForWidth() ) );

    dlgEpargneLayout->addMultiCellWidget( dateEditDateEffet, 1, 1, 3, 4 );

    comboBoxCompagnie = new QComboBox( FALSE, this, "comboBoxCompagnie" );

    dlgEpargneLayout->addMultiCellWidget( comboBoxCompagnie, 7, 7, 2, 4 );
    languageChange();
    resize( QSize(202, 242).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( comboBoxTypeEpargne, dateEditDateEffet );
    setTabOrder( dateEditDateEffet, lineEditInvAnnuel );
    setTabOrder( lineEditInvAnnuel, lineEditEpargne );
    setTabOrder( lineEditEpargne, dateEditDateEpargne );
    setTabOrder( dateEditDateEpargne, lineEditContrat );
    setTabOrder( lineEditContrat, comboBoxCompagnie );
    setTabOrder( comboBoxCompagnie, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgEpargne::~dlgEpargne()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgEpargne::languageChange()
{
    setCaption( tr( "Ajouter une retraite" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    textLabel20->setText( tr( "Date d'effet" ) );
    lineEditInvAnnuel->setInputMask( tr( " ; " ) );
    textLabel22->setText( trUtf8( "\x45\x70\x61\x72\x67\x6e\x65\x20\x28\xe2\x82\xac\x29" ) );
    textLabel19->setText( tr( "Type" ) );
    textLabel21->setText( trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    textLabel25->setText( tr( "Compagnie" ) );
    textLabel24->setText( tr( "Contrat" ) );
    lineEditEpargne->setInputMask( QString::null );
    comboBoxTypeEpargne->clear();
    comboBoxTypeEpargne->insertItem( tr( "Loi Madelin" ) );
    comboBoxTypeEpargne->insertItem( tr( "Art. 83" ) );
    comboBoxTypeEpargne->insertItem( tr( "Art. 82" ) );
    comboBoxTypeEpargne->insertItem( tr( "PERP" ) );
    comboBoxTypeEpargne->insertItem( tr( "PERCO" ) );
    comboBoxTypeEpargne->insertItem( tr( "Art. 39" ) );
    comboBoxTypeEpargne->insertItem( tr( "IFC" ) );
    comboBoxTypeEpargne->insertItem( tr( "Autre" ) );
    textLabel23->setText( tr( "Date du terme" ) );
}

