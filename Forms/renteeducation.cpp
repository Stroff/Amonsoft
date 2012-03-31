/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\renteeducation.ui'
**
** Created: ven. 6. avr. 16:32:06 2007
**      by: The User Interface Compiler ($Id: renteeducation.cpp,v 1.25 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\renteeducation.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "renteeducation.ui.h"
/*
 *  Constructs a dlgRenteEducation as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgRenteEducation::dlgRenteEducation( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgRenteEducation" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, sizePolicy().hasHeightForWidth() ) );
    dlgRenteEducationLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgRenteEducationLayout"); 

    pixmapLabel1 = new QLabel( this, "pixmapLabel1" );
    pixmapLabel1->setPixmap( QPixmap::fromMimeSource( "rente-education.png" ) );
    pixmapLabel1->setScaledContents( TRUE );

    dlgRenteEducationLayout->addMultiCellWidget( pixmapLabel1, 0, 0, 0, 1 );

    textLabel1 = new QLabel( this, "textLabel1" );

    dlgRenteEducationLayout->addWidget( textLabel1, 1, 0 );

    lineEditPrevoyanceDecesRenteEducationMontant = new QLineEdit( this, "lineEditPrevoyanceDecesRenteEducationMontant" );
    lineEditPrevoyanceDecesRenteEducationMontant->setFrameShape( QLineEdit::LineEditPanel );
    lineEditPrevoyanceDecesRenteEducationMontant->setFrameShadow( QLineEdit::Sunken );

    dlgRenteEducationLayout->addWidget( lineEditPrevoyanceDecesRenteEducationMontant, 1, 1 );

    textLabel1_2 = new QLabel( this, "textLabel1_2" );

    dlgRenteEducationLayout->addWidget( textLabel1_2, 2, 0 );

    lineEditPrevoyanceDecesRenteEducationMontantPourcent = new QLineEdit( this, "lineEditPrevoyanceDecesRenteEducationMontantPourcent" );
    lineEditPrevoyanceDecesRenteEducationMontantPourcent->setFrameShape( QLineEdit::LineEditPanel );
    lineEditPrevoyanceDecesRenteEducationMontantPourcent->setFrameShadow( QLineEdit::Sunken );

    dlgRenteEducationLayout->addWidget( lineEditPrevoyanceDecesRenteEducationMontantPourcent, 2, 1 );

    labelPrevoyanceDecesRenteEducationDe = new QLabel( this, "labelPrevoyanceDecesRenteEducationDe" );

    dlgRenteEducationLayout->addWidget( labelPrevoyanceDecesRenteEducationDe, 3, 0 );

    labelPrevoyanceDecesRenteEducationAu = new QLabel( this, "labelPrevoyanceDecesRenteEducationAu" );

    dlgRenteEducationLayout->addWidget( labelPrevoyanceDecesRenteEducationAu, 4, 0 );

    lineEditPrevoyanceDecesRenteEducationAu = new QLineEdit( this, "lineEditPrevoyanceDecesRenteEducationAu" );

    dlgRenteEducationLayout->addWidget( lineEditPrevoyanceDecesRenteEducationAu, 4, 1 );

    lineEditPrevoyanceDecesRenteEducationDu = new QLineEdit( this, "lineEditPrevoyanceDecesRenteEducationDu" );

    dlgRenteEducationLayout->addWidget( lineEditPrevoyanceDecesRenteEducationDu, 3, 1 );

    pushButtonOk = new QPushButton( this, "pushButtonOk" );

    dlgRenteEducationLayout->addMultiCellWidget( pushButtonOk, 5, 5, 0, 1 );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );

    dlgRenteEducationLayout->addMultiCellWidget( pushButtonKo, 6, 6, 0, 1 );
    languageChange();
    resize( QSize(231, 260).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( lineEditPrevoyanceDecesRenteEducationMontant, lineEditPrevoyanceDecesRenteEducationMontantPourcent );
    setTabOrder( lineEditPrevoyanceDecesRenteEducationMontantPourcent, lineEditPrevoyanceDecesRenteEducationDu );
    setTabOrder( lineEditPrevoyanceDecesRenteEducationDu, lineEditPrevoyanceDecesRenteEducationAu );
    setTabOrder( lineEditPrevoyanceDecesRenteEducationAu, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgRenteEducation::~dlgRenteEducation()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgRenteEducation::languageChange()
{
    setCaption( tr( "Ajouter une rente" ) );
    textLabel1->setText( trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x64\x65\x20\x6c\x61\x20\x72\x65\x6e\x74\x65\x20\x28\xe2\x82\xac\x29" ) );
    lineEditPrevoyanceDecesRenteEducationMontant->setInputMask( QString::null );
    textLabel1_2->setText( tr( "Pourcentage salaire (%)" ) );
    lineEditPrevoyanceDecesRenteEducationMontantPourcent->setInputMask( QString::null );
    labelPrevoyanceDecesRenteEducationDe->setText( trUtf8( "\x41\x67\x65\x20\x64\xc3\xa9\x62\x75\x74" ) );
    labelPrevoyanceDecesRenteEducationAu->setText( tr( "Age fin" ) );
    lineEditPrevoyanceDecesRenteEducationAu->setInputMask( QString::null );
    lineEditPrevoyanceDecesRenteEducationDu->setInputMask( QString::null );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
}

