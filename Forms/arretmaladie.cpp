/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\arretmaladie.ui'
**
** Created: ven. 6. avr. 16:32:18 2007
**      by: The User Interface Compiler ($Id: arretmaladie.cpp,v 1.26 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\arretmaladie.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "arretmaladie.ui.h"
/*
 *  Constructs a dlgArretMaladie as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgArretMaladie::dlgArretMaladie( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgArretMaladie" );
    dlgArretMaladieLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgArretMaladieLayout"); 

    pixmapLabel2 = new QLabel( this, "pixmapLabel2" );
    pixmapLabel2->setPixmap( QPixmap::fromMimeSource( "Arret-travail.png" ) );
    pixmapLabel2->setScaledContents( TRUE );

    dlgArretMaladieLayout->addMultiCellWidget( pixmapLabel2, 0, 5, 0, 0 );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );

    dlgArretMaladieLayout->addMultiCellWidget( textLabel1, 0, 0, 1, 2 );

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );

    dlgArretMaladieLayout->addMultiCellWidget( textLabel2, 2, 2, 1, 2 );

    lineEditArretTravailMontant = new QLineEdit( this, "lineEditArretTravailMontant" );
    lineEditArretTravailMontant->setFrameShape( QLineEdit::LineEditPanel );
    lineEditArretTravailMontant->setFrameShadow( QLineEdit::Sunken );

    dlgArretMaladieLayout->addMultiCellWidget( lineEditArretTravailMontant, 1, 1, 1, 2 );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );

    dlgArretMaladieLayout->addWidget( pushButtonKo, 6, 2 );

    pushButtonOk = new QPushButton( this, "pushButtonOk" );

    dlgArretMaladieLayout->addMultiCellWidget( pushButtonOk, 6, 6, 0, 1 );

    lineEditArretTravailFranchise = new QLineEdit( this, "lineEditArretTravailFranchise" );

    dlgArretMaladieLayout->addMultiCellWidget( lineEditArretTravailFranchise, 3, 3, 1, 2 );

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );

    dlgArretMaladieLayout->addMultiCellWidget( textLabel3, 4, 4, 1, 2 );

    lineEditArretTravailDuree = new QLineEdit( this, "lineEditArretTravailDuree" );

    dlgArretMaladieLayout->addMultiCellWidget( lineEditArretTravailDuree, 5, 5, 1, 2 );
    languageChange();
    resize( QSize(252, 186).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );

    // tab order
    setTabOrder( lineEditArretTravailMontant, lineEditArretTravailFranchise );
    setTabOrder( lineEditArretTravailFranchise, lineEditArretTravailDuree );
    setTabOrder( lineEditArretTravailDuree, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgArretMaladie::~dlgArretMaladie()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgArretMaladie::languageChange()
{
    setCaption( tr( "Arret Maladie" ) );
    pixmapLabel2->setText( QString::null );
    textLabel1->setText( trUtf8( "\x49\x6e\x64\x65\x6d\x6e\x69\x74\xc3\xa9\x73\x20\x6a\x6f\x75\x72\x6e\x61\x6c\x69\xc3\xa8\x72\x65\x73\x20\x28\xe2\x82\xac\x29" ) );
    textLabel2->setText( trUtf8( "\x46\x72\x61\x6e\x63\x68\x69\x73\x65\x20\x28\xe2\x82\xac\x29" ) );
    lineEditArretTravailMontant->setInputMask( QString::null );
    QToolTip::add( lineEditArretTravailMontant, trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x65\x6d\x70\x72\x75\x6e\x74\xc3\xa9" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    lineEditArretTravailFranchise->setInputMask( QString::null );
    textLabel3->setText( trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );
    lineEditArretTravailDuree->setInputMask( QString::null );
}

