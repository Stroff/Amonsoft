/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\preferences.ui'
**
** Created: ven. 6. avr. 16:32:07 2007
**      by: The User Interface Compiler ($Id: preferences.cpp,v 1.21 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\preferences.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlistbox.h>
#include <qwidgetstack.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "preferences.ui.h"
/*
 *  Constructs a dlgPreferences as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgPreferences::dlgPreferences( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgPreferences" );
    setSizeGripEnabled( TRUE );
    dlgPreferencesLayout = new QGridLayout( this, 1, 1, 11, 6, "dlgPreferencesLayout"); 

    Layout1 = new QHBoxLayout( 0, 0, 6, "Layout1"); 
    Horizontal_Spacing2 = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( Horizontal_Spacing2 );

    buttonOk = new QPushButton( this, "buttonOk" );
    buttonOk->setAutoDefault( TRUE );
    buttonOk->setDefault( TRUE );
    Layout1->addWidget( buttonOk );

    buttonCancel = new QPushButton( this, "buttonCancel" );
    buttonCancel->setAutoDefault( TRUE );
    Layout1->addWidget( buttonCancel );

    dlgPreferencesLayout->addMultiCellLayout( Layout1, 1, 1, 0, 1 );

    listBox = new QListBox( this, "listBox" );
    listBox->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, listBox->sizePolicy().hasHeightForWidth() ) );

    dlgPreferencesLayout->addWidget( listBox, 0, 0 );

    widgetStack1 = new QWidgetStack( this, "widgetStack1" );

    WStackPage = new QWidget( widgetStack1, "WStackPage" );
    WStackPageLayout = new QGridLayout( WStackPage, 1, 1, 11, 6, "WStackPageLayout"); 

    textLabel1_2 = new QLabel( WStackPage, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );

    WStackPageLayout->addMultiCellWidget( textLabel1_2, 0, 0, 0, 3 );

    textLabel2 = new QLabel( WStackPage, "textLabel2" );

    WStackPageLayout->addWidget( textLabel2, 2, 0 );

    textLabel4 = new QLabel( WStackPage, "textLabel4" );

    WStackPageLayout->addWidget( textLabel4, 4, 0 );

    textLabel3 = new QLabel( WStackPage, "textLabel3" );

    WStackPageLayout->addWidget( textLabel3, 3, 0 );

    comboBoxCompagnieType = new QComboBox( FALSE, WStackPage, "comboBoxCompagnieType" );

    WStackPageLayout->addWidget( comboBoxCompagnieType, 3, 1 );

    lineEditCompagnieDenomination = new QLineEdit( WStackPage, "lineEditCompagnieDenomination" );
    lineEditCompagnieDenomination->setFrameShape( QLineEdit::LineEditPanel );
    lineEditCompagnieDenomination->setFrameShadow( QLineEdit::Sunken );

    WStackPageLayout->addWidget( lineEditCompagnieDenomination, 2, 1 );

    lineEditCompagnieContact = new QLineEdit( WStackPage, "lineEditCompagnieContact" );

    WStackPageLayout->addWidget( lineEditCompagnieContact, 4, 1 );
    spacer33 = new QSpacerItem( 100, 70, QSizePolicy::Expanding, QSizePolicy::Minimum );
    WStackPageLayout->addMultiCell( spacer33, 2, 4, 2, 2 );

    listViewCompagnies = new QListView( WStackPage, "listViewCompagnies" );
    listViewCompagnies->addColumn( tr( "Compagnie" ) );
    listViewCompagnies->addColumn( tr( "Type" ) );
    listViewCompagnies->addColumn( tr( "Contact" ) );

    WStackPageLayout->addMultiCellWidget( listViewCompagnies, 1, 1, 0, 3 );

    pushButtonCompagnieValider = new QPushButton( WStackPage, "pushButtonCompagnieValider" );

    WStackPageLayout->addWidget( pushButtonCompagnieValider, 2, 3 );

    pushButtonCompagnieSupprimer = new QPushButton( WStackPage, "pushButtonCompagnieSupprimer" );

    WStackPageLayout->addMultiCellWidget( pushButtonCompagnieSupprimer, 3, 4, 3, 3 );
    widgetStack1->addWidget( WStackPage, 0 );

    WStackPage_2 = new QWidget( widgetStack1, "WStackPage_2" );

    textLabel1 = new QLabel( WStackPage_2, "textLabel1" );
    textLabel1->setGeometry( QRect( 230, 10, 106, 24 ) );

    textLabel1_3 = new QLabel( WStackPage_2, "textLabel1_3" );
    textLabel1_3->setGeometry( QRect( 250, 120, 51, 20 ) );
    widgetStack1->addWidget( WStackPage_2, 1 );

    WStackPage_3 = new QWidget( widgetStack1, "WStackPage_3" );
    WStackPageLayout_2 = new QGridLayout( WStackPage_3, 1, 1, 11, 6, "WStackPageLayout_2"); 

    textLabel5 = new QLabel( WStackPage_3, "textLabel5" );

    WStackPageLayout_2->addMultiCellWidget( textLabel5, 0, 0, 0, 3 );

    textLabel6 = new QLabel( WStackPage_3, "textLabel6" );

    WStackPageLayout_2->addWidget( textLabel6, 2, 0 );

    listViewComptes = new QListView( WStackPage_3, "listViewComptes" );
    listViewComptes->addColumn( tr( "Nom" ) );

    WStackPageLayout_2->addMultiCellWidget( listViewComptes, 1, 1, 0, 3 );

    pushButtonComptesValider = new QPushButton( WStackPage_3, "pushButtonComptesValider" );

    WStackPageLayout_2->addWidget( pushButtonComptesValider, 2, 3 );

    pushButtonComptesSupprimer = new QPushButton( WStackPage_3, "pushButtonComptesSupprimer" );

    WStackPageLayout_2->addWidget( pushButtonComptesSupprimer, 3, 3 );

    lineEditCompteNom = new QLineEdit( WStackPage_3, "lineEditCompteNom" );

    WStackPageLayout_2->addWidget( lineEditCompteNom, 2, 1 );
    spacer64 = new QSpacerItem( 260, 41, QSizePolicy::Expanding, QSizePolicy::Minimum );
    WStackPageLayout_2->addMultiCell( spacer64, 2, 3, 2, 2 );
    widgetStack1->addWidget( WStackPage_3, 2 );

    WStackPage_4 = new QWidget( widgetStack1, "WStackPage_4" );
    WStackPageLayout_3 = new QGridLayout( WStackPage_4, 1, 1, 11, 6, "WStackPageLayout_3"); 

    textLabel5_2 = new QLabel( WStackPage_4, "textLabel5_2" );

    WStackPageLayout_3->addMultiCellWidget( textLabel5_2, 0, 0, 0, 3 );
    spacer64_2 = new QSpacerItem( 260, 41, QSizePolicy::Expanding, QSizePolicy::Minimum );
    WStackPageLayout_3->addMultiCell( spacer64_2, 2, 3, 2, 2 );

    listViewEpargnes = new QListView( WStackPage_4, "listViewEpargnes" );
    listViewEpargnes->addColumn( tr( "Nom" ) );

    WStackPageLayout_3->addMultiCellWidget( listViewEpargnes, 1, 1, 0, 3 );

    pushButtonEpargneValider = new QPushButton( WStackPage_4, "pushButtonEpargneValider" );

    WStackPageLayout_3->addWidget( pushButtonEpargneValider, 2, 3 );

    pushButtonEpargneSupprimer = new QPushButton( WStackPage_4, "pushButtonEpargneSupprimer" );

    WStackPageLayout_3->addWidget( pushButtonEpargneSupprimer, 3, 3 );

    lineEditEpargneNom = new QLineEdit( WStackPage_4, "lineEditEpargneNom" );

    WStackPageLayout_3->addWidget( lineEditEpargneNom, 2, 1 );

    textLabel7 = new QLabel( WStackPage_4, "textLabel7" );

    WStackPageLayout_3->addWidget( textLabel7, 2, 0 );
    widgetStack1->addWidget( WStackPage_4, 3 );

    WStackPage_5 = new QWidget( widgetStack1, "WStackPage_5" );
    WStackPageLayout_4 = new QVBoxLayout( WStackPage_5, 11, 6, "WStackPageLayout_4"); 

    textLabel1_4 = new QLabel( WStackPage_5, "textLabel1_4" );
    WStackPageLayout_4->addWidget( textLabel1_4 );

    textLabel2_2 = new QLabel( WStackPage_5, "textLabel2_2" );
    WStackPageLayout_4->addWidget( textLabel2_2 );

    listViewBureau = new QListView( WStackPage_5, "listViewBureau" );
    listViewBureau->addColumn( tr( "Nom" ) );
    listViewBureau->addColumn( tr( "Type" ) );
    WStackPageLayout_4->addWidget( listViewBureau );

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    textLabel3_2 = new QLabel( WStackPage_5, "textLabel3_2" );
    layout2->addWidget( textLabel3_2 );

    lineEditNomEtude = new QLineEdit( WStackPage_5, "lineEditNomEtude" );
    layout2->addWidget( lineEditNomEtude );

    textLabel4_2 = new QLabel( WStackPage_5, "textLabel4_2" );
    layout2->addWidget( textLabel4_2 );

    comboBoxTypeEtude = new QComboBox( FALSE, WStackPage_5, "comboBoxTypeEtude" );
    layout2->addWidget( comboBoxTypeEtude );

    pushButtonValiderBureau = new QPushButton( WStackPage_5, "pushButtonValiderBureau" );
    layout2->addWidget( pushButtonValiderBureau );

    pushButtonSupprimerEtude = new QPushButton( WStackPage_5, "pushButtonSupprimerEtude" );
    layout2->addWidget( pushButtonSupprimerEtude );
    WStackPageLayout_4->addLayout( layout2 );

    textLabel5_3 = new QLabel( WStackPage_5, "textLabel5_3" );
    WStackPageLayout_4->addWidget( textLabel5_3 );

    listViewConseillers = new QListView( WStackPage_5, "listViewConseillers" );
    listViewConseillers->addColumn( tr( "Nom" ) );
    WStackPageLayout_4->addWidget( listViewConseillers );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    textLabel6_2 = new QLabel( WStackPage_5, "textLabel6_2" );
    layout3->addWidget( textLabel6_2 );

    lineEditNomConseillers = new QLineEdit( WStackPage_5, "lineEditNomConseillers" );
    layout3->addWidget( lineEditNomConseillers );
    spacer5 = new QSpacerItem( 151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer5 );

    pushButtonValiderConseillers = new QPushButton( WStackPage_5, "pushButtonValiderConseillers" );
    layout3->addWidget( pushButtonValiderConseillers );

    pushButtonSupprimerConseillers = new QPushButton( WStackPage_5, "pushButtonSupprimerConseillers" );
    layout3->addWidget( pushButtonSupprimerConseillers );
    WStackPageLayout_4->addLayout( layout3 );
    widgetStack1->addWidget( WStackPage_5, 4 );

    dlgPreferencesLayout->addWidget( widgetStack1, 0, 1 );
    languageChange();
    resize( QSize(681, 566).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( listBox, SIGNAL( selectionChanged(QListBoxItem*) ), this, SLOT( listBox_selectionChanged(QListBoxItem*) ) );
    connect( pushButtonCompagnieValider, SIGNAL( clicked() ), this, SLOT( pushButtonCompagnieValider_clicked() ) );
    connect( pushButtonCompagnieSupprimer, SIGNAL( clicked() ), this, SLOT( pushButtonCompagnieSupprimer_clicked() ) );
    connect( listViewCompagnies, SIGNAL( currentChanged(QListViewItem*) ), this, SLOT( listViewCompagnies_selectionChanged(QListViewItem*) ) );
    connect( listViewEpargnes, SIGNAL( selectionChanged(QListViewItem*) ), this, SLOT( listViewEpargnes_selectionChanged(QListViewItem*) ) );
    connect( pushButtonEpargneValider, SIGNAL( clicked() ), this, SLOT( pushButtonEpargneValider_clicked() ) );
    connect( pushButtonEpargneSupprimer, SIGNAL( clicked() ), this, SLOT( pushButtonEpargneSupprimer_clicked() ) );
    connect( listViewComptes, SIGNAL( selectionChanged(QListViewItem*) ), this, SLOT( listViewComptes_selectionChanged(QListViewItem*) ) );
    connect( pushButtonComptesValider, SIGNAL( clicked() ), this, SLOT( pushButtonComptesValider_clicked() ) );
    connect( pushButtonComptesSupprimer, SIGNAL( clicked() ), this, SLOT( pushButtonComptesSupprimer_clicked() ) );
    connect( listViewBureau, SIGNAL( selectionChanged(QListViewItem*) ), this, SLOT( listViewBureau_selectionChanged(QListViewItem*) ) );
    connect( listViewConseillers, SIGNAL( selectionChanged(QListViewItem*) ), this, SLOT( listViewConseillers_selectionChanged(QListViewItem*) ) );
    connect( pushButtonValiderBureau, SIGNAL( clicked() ), this, SLOT( pushButtonValiderBureau_clicked() ) );
    connect( pushButtonSupprimerEtude, SIGNAL( clicked() ), this, SLOT( pushButtonSupprimerEtude_clicked() ) );
    connect( pushButtonValiderConseillers, SIGNAL( clicked() ), this, SLOT( pushButtonValiderConseillers_clicked() ) );
    connect( pushButtonSupprimerConseillers, SIGNAL( clicked() ), this, SLOT( pushButtonSupprimerConseillers_clicked() ) );

    // tab order
    setTabOrder( listBox, listViewBureau );
    setTabOrder( listViewBureau, lineEditNomEtude );
    setTabOrder( lineEditNomEtude, comboBoxTypeEtude );
    setTabOrder( comboBoxTypeEtude, pushButtonValiderBureau );
    setTabOrder( pushButtonValiderBureau, pushButtonSupprimerEtude );
    setTabOrder( pushButtonSupprimerEtude, listViewConseillers );
    setTabOrder( listViewConseillers, lineEditNomConseillers );
    setTabOrder( lineEditNomConseillers, pushButtonValiderConseillers );
    setTabOrder( pushButtonValiderConseillers, pushButtonSupprimerConseillers );
    setTabOrder( pushButtonSupprimerConseillers, listViewCompagnies );
    setTabOrder( listViewCompagnies, lineEditCompagnieDenomination );
    setTabOrder( lineEditCompagnieDenomination, comboBoxCompagnieType );
    setTabOrder( comboBoxCompagnieType, lineEditCompagnieContact );
    setTabOrder( lineEditCompagnieContact, pushButtonCompagnieValider );
    setTabOrder( pushButtonCompagnieValider, pushButtonCompagnieSupprimer );
    setTabOrder( pushButtonCompagnieSupprimer, listViewComptes );
    setTabOrder( listViewComptes, lineEditCompteNom );
    setTabOrder( lineEditCompteNom, pushButtonComptesValider );
    setTabOrder( pushButtonComptesValider, pushButtonComptesSupprimer );
    setTabOrder( pushButtonComptesSupprimer, listViewEpargnes );
    setTabOrder( listViewEpargnes, lineEditEpargneNom );
    setTabOrder( lineEditEpargneNom, pushButtonEpargneValider );
    setTabOrder( pushButtonEpargneValider, pushButtonEpargneSupprimer );
    setTabOrder( pushButtonEpargneSupprimer, buttonOk );
    setTabOrder( buttonOk, buttonCancel );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgPreferences::~dlgPreferences()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgPreferences::languageChange()
{
    setCaption( trUtf8( "\x50\x72\xc3\xa9\x66\xc3\xa9\x72\x65\x6e\x63\x65\x73" ) );
    buttonOk->setText( tr( "&OK" ) );
    buttonOk->setAccel( QKeySequence( QString::null ) );
    buttonCancel->setText( tr( "&Cancel" ) );
    buttonCancel->setAccel( QKeySequence( QString::null ) );
    listBox->clear();
    listBox->insertItem( trUtf8( "\x50\x72\xc3\xa9\x66\xc3\xa9\x72\x65\x6e\x63\x65\x73" ) );
    listBox->insertItem( tr( "Compagnies" ) );
    listBox->insertItem( tr( "Epargnes" ) );
    listBox->insertItem( tr( "Comptes" ) );
    listBox->insertItem( tr( "Conseillers" ) );
    textLabel1_2->setText( tr( "<h1><p align=\"center\">Liste des compagnies</p></h1>" ) );
    textLabel2->setText( trUtf8( "\x44\xc3\xa9\x6e\x6f\x6d\x69\x6e\x61\x74\x69\x6f\x6e" ) );
    textLabel4->setText( tr( "Contact" ) );
    textLabel3->setText( tr( "Type" ) );
    comboBoxCompagnieType->clear();
    comboBoxCompagnieType->insertItem( tr( "Assurance" ) );
    comboBoxCompagnieType->insertItem( tr( "Banque" ) );
    comboBoxCompagnieType->insertItem( tr( "Banque / Assurance" ) );
    listViewCompagnies->header()->setLabel( 0, tr( "Compagnie" ) );
    listViewCompagnies->header()->setLabel( 1, tr( "Type" ) );
    listViewCompagnies->header()->setLabel( 2, tr( "Contact" ) );
    listViewCompagnies->clear();
    QListViewItem * item = new QListViewItem( listViewCompagnies, 0 );
    item->setText( 0, tr( "<Nouveau>" ) );

    pushButtonCompagnieValider->setText( tr( "Valider" ) );
    pushButtonCompagnieSupprimer->setText( tr( "Supprimer" ) );
    textLabel1->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x50\x72\xc3\xa9\x66\xc3\xa9\x72\x65\x6e\x63\x65\x73\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    textLabel1_3->setText( tr( "<i>a venir ...</i>" ) );
    textLabel5->setText( tr( "<h1><p align=\"center\">Liste des comptes</p></h1>" ) );
    textLabel6->setText( tr( "Nom" ) );
    listViewComptes->header()->setLabel( 0, tr( "Nom" ) );
    listViewComptes->clear();
    item = new QListViewItem( listViewComptes, 0 );
    item->setText( 0, tr( "<Nouveau>" ) );

    pushButtonComptesValider->setText( tr( "Valider" ) );
    pushButtonComptesSupprimer->setText( tr( "Supprimer" ) );
    textLabel5_2->setText( trUtf8( "\x3c\x68\x31\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x4c\x69\x73\x74\x65\x20\x64\x65\x73\x20\xc3\xa9\x70\x61\x72\x67\x6e\x65\x73\x3c\x2f\x70\x3e\x3c\x2f\x68\x31\x3e" ) );
    listViewEpargnes->header()->setLabel( 0, tr( "Nom" ) );
    listViewEpargnes->clear();
    item = new QListViewItem( listViewEpargnes, 0 );
    item->setText( 0, tr( "<Nouveau>" ) );

    pushButtonEpargneValider->setText( tr( "Valider" ) );
    pushButtonEpargneSupprimer->setText( tr( "Supprimer" ) );
    textLabel7->setText( tr( "Nom" ) );
    textLabel1_4->setText( tr( "<h1><p align=\"center\">Liste des conseillers</p></h1>" ) );
    textLabel2_2->setText( trUtf8( "\x3c\x68\x32\x3e\x42\x75\x72\x65\x61\x75\x20\x6f\x75\x20\xc3\xa9\x74\x75\x64\x65\x3c\x2f\x68\x32\x3e" ) );
    listViewBureau->header()->setLabel( 0, tr( "Nom" ) );
    listViewBureau->header()->setLabel( 1, tr( "Type" ) );
    listViewBureau->clear();
    item = new QListViewItem( listViewBureau, 0 );
    item->setText( 0, tr( "<Nouveau>" ) );

    textLabel3_2->setText( tr( "Nom" ) );
    textLabel4_2->setText( tr( "Type" ) );
    comboBoxTypeEtude->clear();
    comboBoxTypeEtude->insertItem( tr( "Cabinet comptable" ) );
    comboBoxTypeEtude->insertItem( tr( "Etude notariale" ) );
    comboBoxTypeEtude->insertItem( tr( "Cabinet avocats" ) );
    pushButtonValiderBureau->setText( tr( "Valider" ) );
    pushButtonSupprimerEtude->setText( tr( "Supprimer" ) );
    textLabel5_3->setText( tr( "<h2>Conseillers</h2>" ) );
    listViewConseillers->header()->setLabel( 0, tr( "Nom" ) );
    listViewConseillers->clear();
    item = new QListViewItem( listViewConseillers, 0 );
    item->setText( 0, tr( "<Nouveau>" ) );

    textLabel6_2->setText( tr( "Nom" ) );
    pushButtonValiderConseillers->setText( tr( "Valider" ) );
    pushButtonSupprimerConseillers->setText( tr( "Supprimer" ) );
}

