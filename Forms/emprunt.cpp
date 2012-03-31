/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\emprunt.ui'
**
** Created: ven. 6. avr. 16:32:12 2007
**      by: The User Interface Compiler ($Id: emprunt.cpp,v 1.26 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\emprunt.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "emprunt.ui.h"
/*
 *  Constructs a dlgEmprunt as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgEmprunt::dlgEmprunt( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgEmprunt" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, sizePolicy().hasHeightForWidth() ) );
    dlgEmpruntLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgEmpruntLayout"); 

    pixmapLabel2 = new QLabel( this, "pixmapLabel2" );
    pixmapLabel2->setPixmap( QPixmap::fromMimeSource( "dlg_emprunt.PNG" ) );
    pixmapLabel2->setScaledContents( TRUE );

    dlgEmpruntLayout->addMultiCellWidget( pixmapLabel2, 0, 11, 0, 0 );

    pushButtonOk = new QPushButton( this, "pushButtonOk" );

    dlgEmpruntLayout->addMultiCellWidget( pushButtonOk, 11, 11, 1, 4 );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );

    dlgEmpruntLayout->addWidget( pushButtonKo, 11, 5 );

    lineEditEmpruntFranchise = new QLineEdit( this, "lineEditEmpruntFranchise" );
    lineEditEmpruntFranchise->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEmpruntFranchise->setFrameShadow( QLineEdit::Sunken );

    dlgEmpruntLayout->addMultiCellWidget( lineEditEmpruntFranchise, 3, 3, 1, 5 );

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );

    dlgEmpruntLayout->addMultiCellWidget( textLabel3, 4, 4, 1, 5 );

    lineEditEmpruntMontant = new QLineEdit( this, "lineEditEmpruntMontant" );
    lineEditEmpruntMontant->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEmpruntMontant->setFrameShadow( QLineEdit::Sunken );

    dlgEmpruntLayout->addMultiCellWidget( lineEditEmpruntMontant, 1, 1, 1, 5 );

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );

    dlgEmpruntLayout->addMultiCellWidget( textLabel2, 2, 2, 1, 5 );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );

    dlgEmpruntLayout->addMultiCellWidget( textLabel1, 0, 0, 1, 5 );

    textLabel2_2 = new QLabel( this, "textLabel2_2" );

    dlgEmpruntLayout->addWidget( textLabel2_2, 6, 1 );

    textLabel3_2 = new QLabel( this, "textLabel3_2" );

    dlgEmpruntLayout->addWidget( textLabel3_2, 7, 1 );

    textLabel4 = new QLabel( this, "textLabel4" );

    dlgEmpruntLayout->addMultiCellWidget( textLabel4, 8, 8, 1, 2 );

    textLabel5 = new QLabel( this, "textLabel5" );

    dlgEmpruntLayout->addWidget( textLabel5, 9, 1 );

    lineEditEmpruntType = new QLineEdit( this, "lineEditEmpruntType" );

    dlgEmpruntLayout->addMultiCellWidget( lineEditEmpruntType, 10, 10, 1, 5 );

    lineEditEmpruntBanque = new QLineEdit( this, "lineEditEmpruntBanque" );

    dlgEmpruntLayout->addMultiCellWidget( lineEditEmpruntBanque, 5, 5, 1, 5 );

    lineEditEmpruntTaux = new QLineEdit( this, "lineEditEmpruntTaux" );
    lineEditEmpruntTaux->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lineEditEmpruntTaux->sizePolicy().hasHeightForWidth() ) );

    dlgEmpruntLayout->addWidget( lineEditEmpruntTaux, 8, 3 );

    lineEditEmpruntTerme = new QLineEdit( this, "lineEditEmpruntTerme" );
    lineEditEmpruntTerme->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)3, 0, 0, lineEditEmpruntTerme->sizePolicy().hasHeightForWidth() ) );

    dlgEmpruntLayout->addMultiCellWidget( lineEditEmpruntTerme, 7, 7, 2, 3 );

    lineEditEmpruntDateDebut = new QLineEdit( this, "lineEditEmpruntDateDebut" );
    lineEditEmpruntDateDebut->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEmpruntDateDebut->sizePolicy().hasHeightForWidth() ) );

    dlgEmpruntLayout->addMultiCellWidget( lineEditEmpruntDateDebut, 6, 6, 2, 3 );
    spacer31 = new QSpacerItem( 110, 101, QSizePolicy::Minimum, QSizePolicy::Expanding );
    dlgEmpruntLayout->addMultiCell( spacer31, 6, 9, 4, 5 );
    languageChange();
    resize( QSize(516, 319).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( lineEditEmpruntMontant, lineEditEmpruntFranchise );
    setTabOrder( lineEditEmpruntFranchise, lineEditEmpruntBanque );
    setTabOrder( lineEditEmpruntBanque, lineEditEmpruntDateDebut );
    setTabOrder( lineEditEmpruntDateDebut, lineEditEmpruntTerme );
    setTabOrder( lineEditEmpruntTerme, lineEditEmpruntTaux );
    setTabOrder( lineEditEmpruntTaux, lineEditEmpruntType );
    setTabOrder( lineEditEmpruntType, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgEmprunt::~dlgEmprunt()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgEmprunt::languageChange()
{
    setCaption( tr( "Ajouter un emprunt" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
    lineEditEmpruntFranchise->setInputMask( QString::null );
    QToolTip::add( lineEditEmpruntFranchise, tr( "Franchise de l'emprunt" ) );
    textLabel3->setText( tr( "Banque" ) );
    lineEditEmpruntMontant->setInputMask( QString::null );
    QToolTip::add( lineEditEmpruntMontant, trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x65\x6d\x70\x72\x75\x6e\x74\xc3\xa9" ) );
    textLabel2->setText( trUtf8( "\x46\x72\x61\x6e\x63\x68\x69\x73\x65\x20\x28\xe2\x82\xac\x29" ) );
    textLabel1->setText( tr( "Montant de l'emprunt" ) );
    textLabel2_2->setText( trUtf8( "\x44\x61\x74\x65\x20\x64\xc3\xa9\x62\x75\x74" ) );
    textLabel3_2->setText( tr( "Terme" ) );
    textLabel4->setText( tr( "Taux moyen (%)" ) );
    textLabel5->setText( tr( "Type emprunt" ) );
    QToolTip::add( lineEditEmpruntBanque, trUtf8( "\x42\x61\x6e\x71\x75\x65\x20\x64\x61\x6e\x73\x20\x6c\x61\x71\x75\x65\x6c\x6c\x65\x20\x6c\x27\x65\x6d\x70\x72\x75\x6e\x74\x20\x61\x20\xc3\xa9\x74\xc3\xa9\x20\x63\x6f\x6e\x74\x72\x61\x63\x74\xc3\xa9" ) );
    lineEditEmpruntTaux->setInputMask( QString::null );
    lineEditEmpruntTerme->setInputMask( QString::null );
    lineEditEmpruntDateDebut->setInputMask( tr( "00/00/0000;_" ) );
}

