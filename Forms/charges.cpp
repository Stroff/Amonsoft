/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\charges.ui'
**
** Created: ven. 6. avr. 16:32:15 2007
**      by: The User Interface Compiler ($Id: charges.cpp,v 1.24 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\charges.h"

#include <qvariant.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "charges.ui.h"
/*
 *  Constructs a dlgCharges as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgCharges::dlgCharges( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgCharges" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, sizePolicy().hasHeightForWidth() ) );
    dlgChargesLayout = new QVBoxLayout( this, 11, 6, "dlgChargesLayout"); 

    layout70 = new QGridLayout( 0, 1, 1, 0, 6, "layout70"); 

    lineEditDesignation = new QLineEdit( this, "lineEditDesignation" );
    lineEditDesignation->setFrameShape( QLineEdit::LineEditPanel );
    lineEditDesignation->setFrameShadow( QLineEdit::Sunken );

    layout70->addMultiCellWidget( lineEditDesignation, 0, 0, 1, 2 );

    lineEditMontant = new QLineEdit( this, "lineEditMontant" );

    layout70->addWidget( lineEditMontant, 1, 2 );

    textLabel43 = new QLabel( this, "textLabel43" );

    layout70->addWidget( textLabel43, 0, 0 );

    textLabel44 = new QLabel( this, "textLabel44" );

    layout70->addMultiCellWidget( textLabel44, 1, 1, 0, 1 );
    dlgChargesLayout->addLayout( layout70 );

    layout72 = new QHBoxLayout( 0, 0, 6, "layout72"); 

    pushButtonOk = new QPushButton( this, "pushButtonOk" );
    layout72->addWidget( pushButtonOk );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );
    layout72->addWidget( pushButtonKo );
    dlgChargesLayout->addLayout( layout72 );
    languageChange();
    resize( QSize(235, 104).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgCharges::~dlgCharges()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgCharges::languageChange()
{
    setCaption( tr( "Ajouter des charges" ) );
    lineEditMontant->setInputMask( QString::null );
    textLabel43->setText( trUtf8( "\x44\xc3\xa9\x73\x69\x67\x6e\x61\x74\x69\x6f\x6e" ) );
    textLabel44->setText( trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
}

