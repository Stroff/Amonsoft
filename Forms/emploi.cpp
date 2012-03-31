/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\emploi.ui'
**
** Created: ven. 6. avr. 16:32:13 2007
**      by: The User Interface Compiler ($Id: emploi.cpp,v 1.26 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\emploi.h"

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

#include "emploi.ui.h"
/*
 *  Constructs a dlgEmploi as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgEmploi::dlgEmploi( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgEmploi" );
    dlgEmploiLayout = new QVBoxLayout( this, 11, 6, "dlgEmploiLayout"); 

    layout239 = new QGridLayout( 0, 1, 1, 0, 6, "layout239"); 

    layout233 = new QHBoxLayout( 0, 0, 6, "layout233"); 

    labelCarriereRCO = new QLabel( this, "labelCarriereRCO" );
    labelCarriereRCO->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelCarriereRCO->sizePolicy().hasHeightForWidth() ) );
    layout233->addWidget( labelCarriereRCO );

    lineEditCarriereEmploisPoints = new QLineEdit( this, "lineEditCarriereEmploisPoints" );
    lineEditCarriereEmploisPoints->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditCarriereEmploisPoints->sizePolicy().hasHeightForWidth() ) );
    lineEditCarriereEmploisPoints->setFrameShape( QLineEdit::LineEditPanel );
    lineEditCarriereEmploisPoints->setFrameShadow( QLineEdit::Sunken );
    layout233->addWidget( lineEditCarriereEmploisPoints );

    layout239->addLayout( layout233, 1, 0 );

    layout234 = new QHBoxLayout( 0, 0, 6, "layout234"); 

    labelCarriereNotes = new QLabel( this, "labelCarriereNotes" );
    labelCarriereNotes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelCarriereNotes->sizePolicy().hasHeightForWidth() ) );
    layout234->addWidget( labelCarriereNotes );

    lineEditCarriereEmploisNotes = new QLineEdit( this, "lineEditCarriereEmploisNotes" );
    layout234->addWidget( lineEditCarriereEmploisNotes );

    layout239->addLayout( layout234, 2, 0 );

    layout231 = new QHBoxLayout( 0, 0, 6, "layout231"); 

    labelCarriereStatut = new QLabel( this, "labelCarriereStatut" );
    labelCarriereStatut->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelCarriereStatut->sizePolicy().hasHeightForWidth() ) );
    layout231->addWidget( labelCarriereStatut );

    comboBoxCarriereEmploiStatut = new QComboBox( FALSE, this, "comboBoxCarriereEmploiStatut" );
    layout231->addWidget( comboBoxCarriereEmploiStatut );

    layout239->addLayout( layout231, 2, 1 );

    layout232 = new QHBoxLayout( 0, 0, 6, "layout232"); 

    labelCarriereRevenus1 = new QLabel( this, "labelCarriereRevenus1" );
    labelCarriereRevenus1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelCarriereRevenus1->sizePolicy().hasHeightForWidth() ) );
    layout232->addWidget( labelCarriereRevenus1 );

    lineEditCarriereEmploisRevenus = new QLineEdit( this, "lineEditCarriereEmploisRevenus" );
    layout232->addWidget( lineEditCarriereEmploisRevenus );

    layout239->addLayout( layout232, 0, 0 );

    layout229 = new QHBoxLayout( 0, 0, 6, "layout229"); 

    labelCarriereDu = new QLabel( this, "labelCarriereDu" );
    layout229->addWidget( labelCarriereDu );

    dateEditCarriereEmploisDu = new QDateEdit( this, "dateEditCarriereEmploisDu" );
    layout229->addWidget( dateEditCarriereEmploisDu );

    layout239->addLayout( layout229, 0, 1 );

    layout230 = new QHBoxLayout( 0, 0, 6, "layout230"); 

    labelCarriereAu = new QLabel( this, "labelCarriereAu" );
    layout230->addWidget( labelCarriereAu );

    dateEditCarriereEmploisAu = new QDateEdit( this, "dateEditCarriereEmploisAu" );
    layout230->addWidget( dateEditCarriereEmploisAu );

    layout239->addLayout( layout230, 1, 1 );
    dlgEmploiLayout->addLayout( layout239 );

    pushButtonOk = new QPushButton( this, "pushButtonOk" );
    dlgEmploiLayout->addWidget( pushButtonOk );

    pushButtonKo = new QPushButton( this, "pushButtonKo" );
    dlgEmploiLayout->addWidget( pushButtonKo );
    languageChange();
    resize( QSize(337, 166).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonKo, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonOk, SIGNAL( clicked() ), this, SLOT( Ok() ) );

    // tab order
    setTabOrder( lineEditCarriereEmploisRevenus, dateEditCarriereEmploisDu );
    setTabOrder( dateEditCarriereEmploisDu, lineEditCarriereEmploisPoints );
    setTabOrder( lineEditCarriereEmploisPoints, dateEditCarriereEmploisAu );
    setTabOrder( dateEditCarriereEmploisAu, lineEditCarriereEmploisNotes );
    setTabOrder( lineEditCarriereEmploisNotes, comboBoxCarriereEmploiStatut );
    setTabOrder( comboBoxCarriereEmploiStatut, pushButtonOk );
    setTabOrder( pushButtonOk, pushButtonKo );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgEmploi::~dlgEmploi()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgEmploi::languageChange()
{
    setCaption( tr( "Ajouter un emploi" ) );
    labelCarriereRCO->setText( tr( "<p align=\"center\">RCO + points</p>" ) );
    lineEditCarriereEmploisPoints->setInputMask( QString::null );
    labelCarriereNotes->setText( tr( "<p align=\"center\">Notes</p>" ) );
    labelCarriereStatut->setText( tr( "<p align=\"center\">Statut</p>" ) );
    comboBoxCarriereEmploiStatut->clear();
    comboBoxCarriereEmploiStatut->insertItem( tr( "Salarie" ) );
    comboBoxCarriereEmploiStatut->insertItem( tr( "Salarie Cadre" ) );
    comboBoxCarriereEmploiStatut->insertItem( tr( "ETAM" ) );
    comboBoxCarriereEmploiStatut->insertItem( tr( "Fonctionnaire" ) );
    comboBoxCarriereEmploiStatut->insertItem( tr( "Artisant" ) );
    comboBoxCarriereEmploiStatut->insertItem( tr( "Commercant" ) );
    comboBoxCarriereEmploiStatut->insertItem( tr( "Liberal" ) );
    comboBoxCarriereEmploiStatut->insertItem( tr( "Exploitant agricole" ) );
    labelCarriereRevenus1->setText( tr( "<p align=\"center\">Revenus</p>" ) );
    lineEditCarriereEmploisRevenus->setInputMask( QString::null );
    labelCarriereDu->setText( tr( "Du" ) );
    labelCarriereAu->setText( tr( "au" ) );
    pushButtonOk->setText( tr( "Valider" ) );
    pushButtonKo->setText( tr( "Annuler" ) );
}

