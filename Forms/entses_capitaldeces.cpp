/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\entses_capitaldeces.ui'
**
** Created: ven. 6. avr. 17:19:52 2007
**      by: The User Interface Compiler ($Id: entses_capitaldeces.cpp,v 1.2 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\entses_capitaldeces.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "entses_capitaldeces.ui.h"
/*
 *  Constructs a dlgCapitalDeces as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgCapitalDeces::dlgCapitalDeces( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgCapitalDeces" );
    dlgCapitalDecesLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgCapitalDecesLayout"); 

    textLabel1 = new QLabel( this, "textLabel1" );

    dlgCapitalDecesLayout->addWidget( textLabel1, 1, 0 );

    textLabel2 = new QLabel( this, "textLabel2" );

    dlgCapitalDecesLayout->addMultiCellWidget( textLabel2, 2, 2, 0, 1 );

    lineEditTB = new QLineEdit( this, "lineEditTB" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditTB, 1, 1, 8, 9 );

    lineEditTA = new QLineEdit( this, "lineEditTA" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditTA, 0, 0, 8, 9 );

    lineEditTC = new QLineEdit( this, "lineEditTC" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditTC, 2, 2, 8, 9 );

    textLabel10 = new QLabel( this, "textLabel10" );

    dlgCapitalDecesLayout->addWidget( textLabel10, 2, 7 );

    textLabel9 = new QLabel( this, "textLabel9" );

    dlgCapitalDecesLayout->addWidget( textLabel9, 1, 7 );

    textLabel8 = new QLabel( this, "textLabel8" );

    dlgCapitalDecesLayout->addWidget( textLabel8, 0, 7 );

    comboBoxTypeSal = new QComboBox( FALSE, this, "comboBoxTypeSal" );

    dlgCapitalDecesLayout->addMultiCellWidget( comboBoxTypeSal, 0, 0, 0, 5 );

    lineEditContrat = new QLineEdit( this, "lineEditContrat" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditContrat, 1, 1, 1, 5 );

    comboBoxCompagnie = new QComboBox( FALSE, this, "comboBoxCompagnie" );

    dlgCapitalDecesLayout->addMultiCellWidget( comboBoxCompagnie, 2, 2, 2, 5 );

    lineEditRenteConjoint = new QLineEdit( this, "lineEditRenteConjoint" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditRenteConjoint, 3, 3, 3, 5 );

    textLabel6 = new QLabel( this, "textLabel6" );

    dlgCapitalDecesLayout->addMultiCellWidget( textLabel6, 3, 4, 0, 2 );

    textLabel7 = new QLabel( this, "textLabel7" );

    dlgCapitalDecesLayout->addMultiCellWidget( textLabel7, 5, 5, 0, 3 );

    lineEditRenteEducation = new QLineEdit( this, "lineEditRenteEducation" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditRenteEducation, 5, 5, 4, 5 );

    textLabel3 = new QLabel( this, "textLabel3" );

    dlgCapitalDecesLayout->addMultiCellWidget( textLabel3, 3, 3, 7, 8 );

    lineEditCVD = new QLineEdit( this, "lineEditCVD" );

    dlgCapitalDecesLayout->addWidget( lineEditCVD, 3, 9 );

    textLabel4 = new QLabel( this, "textLabel4" );

    dlgCapitalDecesLayout->addMultiCellWidget( textLabel4, 4, 5, 7, 7 );

    lineEditM = new QLineEdit( this, "lineEditM" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditM, 4, 5, 8, 9 );
    spacer40 = new QSpacerItem( 43, 120, QSizePolicy::Expanding, QSizePolicy::Minimum );
    dlgCapitalDecesLayout->addMultiCell( spacer40, 0, 5, 6, 6 );

    lineEditMaj = new QLineEdit( this, "lineEditMaj" );

    dlgCapitalDecesLayout->addMultiCellWidget( lineEditMaj, 6, 6, 2, 9 );

    textLabel5 = new QLabel( this, "textLabel5" );

    dlgCapitalDecesLayout->addMultiCellWidget( textLabel5, 6, 6, 0, 1 );

    pushButtonko = new QPushButton( this, "pushButtonko" );

    dlgCapitalDecesLayout->addMultiCellWidget( pushButtonko, 7, 7, 5, 9 );

    pushButtonok = new QPushButton( this, "pushButtonok" );

    dlgCapitalDecesLayout->addMultiCellWidget( pushButtonok, 7, 7, 0, 4 );
    languageChange();
    resize( QSize(381, 209).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButtonko, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( pushButtonok, SIGNAL( clicked() ), this, SLOT( Ok() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgCapitalDeces::~dlgCapitalDeces()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgCapitalDeces::languageChange()
{
    setCaption( trUtf8( "\x43\x61\x70\x69\x74\x61\x6c\x20\x64\xc3\xa9\x63\xc3\xa8\x73" ) );
    textLabel1->setText( tr( "Contrat" ) );
    textLabel2->setText( tr( "Compagnie" ) );
    textLabel10->setText( tr( "TC (%)" ) );
    textLabel9->setText( tr( "TB (%)" ) );
    textLabel8->setText( tr( "TA (%)" ) );
    comboBoxTypeSal->clear();
    comboBoxTypeSal->insertItem( tr( "Non cadres" ) );
    comboBoxTypeSal->insertItem( tr( "Cadres" ) );
    textLabel6->setText( trUtf8( "\x52\x65\x6e\x74\x65\x20\x63\x6f\x6e\x6a\x6f\x69\x6e\x74\x20\x28\xe2\x82\xac\x29" ) );
    textLabel7->setText( trUtf8( "\x52\x65\x6e\x74\x65\x20\xc3\xa9\x64\x75\x63\x61\x74\x69\x6f\x6e\x20\x28\xe2\x82\xac\x29" ) );
    textLabel3->setText( tr( "CVD (%)" ) );
    textLabel4->setText( tr( "M (%)" ) );
    textLabel5->setText( tr( "Maj/enf. (%)" ) );
    pushButtonko->setText( tr( "Annuler" ) );
    pushButtonok->setText( tr( "Valider" ) );
}

