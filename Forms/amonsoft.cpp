/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\amonsoft.ui'
**
** Created: ven. 6. avr. 16:32:20 2007
**      by: The User Interface Compiler ($Id: amonsoft.cpp,v 1.30 2007/04/06 15:34:43 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\amonsoft.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qwidgetstack.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qframe.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qtabwidget.h>
#include <qcheckbox.h>
#include <qtextedit.h>
#include <qheader.h>
#include <qlistview.h>
#include <qslider.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>
#include <qimage.h>
#include <qpixmap.h>

#include "amonsoft.ui.h"
/*
 *  Constructs a dlgAmonSoft as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
dlgAmonSoft::dlgAmonSoft( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "dlgMain" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setMinimumSize( QSize( 720, 725 ) );
    setPaletteForegroundColor( QColor( 194, 194, 194 ) );
    setPaletteBackgroundColor( QColor( 2, 104, 152 ) );
    setIcon( QPixmap::fromMimeSource( "icone.png" ) );
    setCentralWidget( new QWidget( this, "qt_central_widget" ) );
    dlgMainLayout = new QVBoxLayout( centralWidget(), 11, 6, "dlgMainLayout"); 

    layout182 = new QHBoxLayout( 0, 0, 6, "layout182"); 

    pushButtonPersonneLister = new QPushButton( centralWidget(), "pushButtonPersonneLister" );
    pushButtonPersonneLister->setPixmap( QPixmap::fromMimeSource( "listepers.png" ) );
    layout182->addWidget( pushButtonPersonneLister );

    pushButtonPersonneAjouter = new QPushButton( centralWidget(), "pushButtonPersonneAjouter" );
    pushButtonPersonneAjouter->setPixmap( QPixmap::fromMimeSource( "ajoutpers.png" ) );
    layout182->addWidget( pushButtonPersonneAjouter );

    pushButtonEntrepriseLister = new QPushButton( centralWidget(), "pushButtonEntrepriseLister" );
    pushButtonEntrepriseLister->setPixmap( QPixmap::fromMimeSource( "listeent.png" ) );
    layout182->addWidget( pushButtonEntrepriseLister );

    pushButton44 = new QPushButton( centralWidget(), "pushButton44" );
    pushButton44->setPixmap( QPixmap::fromMimeSource( "ajoutent.png" ) );
    pushButton44->setFlat( TRUE );
    layout182->addWidget( pushButton44 );
    spacer118 = new QSpacerItem( 16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout182->addItem( spacer118 );

    pushButtonCharger = new QPushButton( centralWidget(), "pushButtonCharger" );
    pushButtonCharger->setMinimumSize( QSize( 0, 0 ) );
    pushButtonCharger->setMaximumSize( QSize( 32767, 32767 ) );
    pushButtonCharger->setPixmap( QPixmap::fromMimeSource( "valid.png" ) );
    layout182->addWidget( pushButtonCharger );

    pushButtonSupprimer = new QPushButton( centralWidget(), "pushButtonSupprimer" );
    pushButtonSupprimer->setPixmap( QPixmap::fromMimeSource( "annul.png" ) );
    layout182->addWidget( pushButtonSupprimer );
    dlgMainLayout->addLayout( layout182 );

    widgetStackMain = new QWidgetStack( centralWidget(), "widgetStackMain" );

    WStackPage = new QWidget( widgetStackMain, "WStackPage" );
    WStackPageLayout = new QHBoxLayout( WStackPage, 11, 6, "WStackPageLayout"); 

    layout70 = new QVBoxLayout( 0, 0, 6, "layout70"); 

    pushButtonEtatCivil = new QPushButton( WStackPage, "pushButtonEtatCivil" );
    pushButtonEtatCivil->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, pushButtonEtatCivil->sizePolicy().hasHeightForWidth() ) );
    pushButtonEtatCivil->setMinimumSize( QSize( 50, 0 ) );
    pushButtonEtatCivil->setMaximumSize( QSize( 50, 32767 ) );
    pushButtonEtatCivil->setPixmap( QPixmap::fromMimeSource( "etatcivil.PNG" ) );
    layout70->addWidget( pushButtonEtatCivil );

    pushButtonFamille = new QPushButton( WStackPage, "pushButtonFamille" );
    pushButtonFamille->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, pushButtonFamille->sizePolicy().hasHeightForWidth() ) );
    pushButtonFamille->setMinimumSize( QSize( 50, 0 ) );
    pushButtonFamille->setMaximumSize( QSize( 50, 32767 ) );
    pushButtonFamille->setPixmap( QPixmap::fromMimeSource( "famille.PNG" ) );
    layout70->addWidget( pushButtonFamille );

    pushButtonCarriere = new QPushButton( WStackPage, "pushButtonCarriere" );
    pushButtonCarriere->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, pushButtonCarriere->sizePolicy().hasHeightForWidth() ) );
    pushButtonCarriere->setMinimumSize( QSize( 50, 0 ) );
    pushButtonCarriere->setMaximumSize( QSize( 50, 32767 ) );
    pushButtonCarriere->setPixmap( QPixmap::fromMimeSource( "carriere.PNG" ) );
    layout70->addWidget( pushButtonCarriere );

    pushButtonPrevoyance = new QPushButton( WStackPage, "pushButtonPrevoyance" );
    pushButtonPrevoyance->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, pushButtonPrevoyance->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyance->setMinimumSize( QSize( 50, 0 ) );
    pushButtonPrevoyance->setMaximumSize( QSize( 50, 32767 ) );
    pushButtonPrevoyance->setPixmap( QPixmap::fromMimeSource( "prevoyance.PNG" ) );
    layout70->addWidget( pushButtonPrevoyance );

    pushButtonEpargne = new QPushButton( WStackPage, "pushButtonEpargne" );
    pushButtonEpargne->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, pushButtonEpargne->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargne->setMinimumSize( QSize( 50, 0 ) );
    pushButtonEpargne->setMaximumSize( QSize( 50, 32767 ) );
    pushButtonEpargne->setPixmap( QPixmap::fromMimeSource( "epargne.PNG" ) );
    layout70->addWidget( pushButtonEpargne );

    pushButtonPatrimoine = new QPushButton( WStackPage, "pushButtonPatrimoine" );
    pushButtonPatrimoine->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, pushButtonPatrimoine->sizePolicy().hasHeightForWidth() ) );
    pushButtonPatrimoine->setMinimumSize( QSize( 50, 0 ) );
    pushButtonPatrimoine->setMaximumSize( QSize( 50, 32767 ) );
    pushButtonPatrimoine->setPixmap( QPixmap::fromMimeSource( "patrimoine.PNG" ) );
    layout70->addWidget( pushButtonPatrimoine );

    pushButtonBesoins = new QPushButton( WStackPage, "pushButtonBesoins" );
    pushButtonBesoins->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, pushButtonBesoins->sizePolicy().hasHeightForWidth() ) );
    pushButtonBesoins->setMinimumSize( QSize( 50, 0 ) );
    pushButtonBesoins->setMaximumSize( QSize( 50, 32767 ) );
    layout70->addWidget( pushButtonBesoins );
    WStackPageLayout->addLayout( layout70 );

    widgetStackAjouter = new QWidgetStack( WStackPage, "widgetStackAjouter" );

    WStackPage_2 = new QWidget( widgetStackAjouter, "WStackPage_2" );
    WStackPageLayout_2 = new QVBoxLayout( WStackPage_2, 11, 6, "WStackPageLayout_2"); 

    labelEtatCivil = new QLabel( WStackPage_2, "labelEtatCivil" );
    labelEtatCivil->setLineWidth( 1 );
    WStackPageLayout_2->addWidget( labelEtatCivil );

    frameBeneficiaire = new QFrame( WStackPage_2, "frameBeneficiaire" );
    frameBeneficiaire->setFrameShape( QFrame::StyledPanel );
    frameBeneficiaire->setFrameShadow( QFrame::Raised );
    frameBeneficiaireLayout = new QGridLayout( frameBeneficiaire, 1, 1, 11, 6, "frameBeneficiaireLayout"); 

    textLabelEtatCivilRue = new QLabel( frameBeneficiaire, "textLabelEtatCivilRue" );

    frameBeneficiaireLayout->addWidget( textLabelEtatCivilRue, 3, 0 );

    textLabelEtatCivilAdresseComplement = new QLabel( frameBeneficiaire, "textLabelEtatCivilAdresseComplement" );

    frameBeneficiaireLayout->addWidget( textLabelEtatCivilAdresseComplement, 4, 0 );

    textLabelCodePostal = new QLabel( frameBeneficiaire, "textLabelCodePostal" );

    frameBeneficiaireLayout->addWidget( textLabelCodePostal, 5, 0 );

    labelEtatCivilTelephone = new QLabel( frameBeneficiaire, "labelEtatCivilTelephone" );

    frameBeneficiaireLayout->addWidget( labelEtatCivilTelephone, 7, 0 );

    labelEtatCivilTelephone_2 = new QLabel( frameBeneficiaire, "labelEtatCivilTelephone_2" );

    frameBeneficiaireLayout->addWidget( labelEtatCivilTelephone_2, 8, 0 );

    layout68 = new QHBoxLayout( 0, 0, 6, "layout68"); 

    textLabel2 = new QLabel( frameBeneficiaire, "textLabel2" );
    layout68->addWidget( textLabel2 );

    comboBoxEtatCivilCivilite = new QComboBox( FALSE, frameBeneficiaire, "comboBoxEtatCivilCivilite" );
    layout68->addWidget( comboBoxEtatCivilCivilite );

    labelEtatCivilNom = new QLabel( frameBeneficiaire, "labelEtatCivilNom" );
    layout68->addWidget( labelEtatCivilNom );

    lineEditEtatCivilNom = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilNom" );
    layout68->addWidget( lineEditEtatCivilNom );

    textLabel3_2 = new QLabel( frameBeneficiaire, "textLabel3_2" );
    layout68->addWidget( textLabel3_2 );

    lineEditEtatCivilNomJeuneFille = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilNomJeuneFille" );
    layout68->addWidget( lineEditEtatCivilNomJeuneFille );

    frameBeneficiaireLayout->addMultiCellLayout( layout68, 0, 0, 0, 6 );

    layout69 = new QHBoxLayout( 0, 0, 6, "layout69"); 

    labelEtatCivilPrenom = new QLabel( frameBeneficiaire, "labelEtatCivilPrenom" );
    layout69->addWidget( labelEtatCivilPrenom );

    lineEditEtatCivilPrenom = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilPrenom" );
    lineEditEtatCivilPrenom->setMaximumSize( QSize( 32767, 32767 ) );
    lineEditEtatCivilPrenom->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEtatCivilPrenom->setFrameShadow( QLineEdit::Sunken );
    layout69->addWidget( lineEditEtatCivilPrenom );

    labelEtatCivilDateNaissance = new QLabel( frameBeneficiaire, "labelEtatCivilDateNaissance" );
    layout69->addWidget( labelEtatCivilDateNaissance );

    dateEditEtatCivilDateNaissance = new QDateEdit( frameBeneficiaire, "dateEditEtatCivilDateNaissance" );
    dateEditEtatCivilDateNaissance->setEnabled( TRUE );
    dateEditEtatCivilDateNaissance->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditEtatCivilDateNaissance->sizePolicy().hasHeightForWidth() ) );
    layout69->addWidget( dateEditEtatCivilDateNaissance );

    textLabel1_4 = new QLabel( frameBeneficiaire, "textLabel1_4" );
    layout69->addWidget( textLabel1_4 );

    lineEditEtatCivilLieuNaissance = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilLieuNaissance" );
    layout69->addWidget( lineEditEtatCivilLieuNaissance );

    frameBeneficiaireLayout->addMultiCellLayout( layout69, 1, 1, 0, 6 );

    labelEtatCivilRue = new QLabel( frameBeneficiaire, "labelEtatCivilRue" );

    frameBeneficiaireLayout->addMultiCellWidget( labelEtatCivilRue, 2, 2, 0, 2 );

    textLabelEtatCivilVille = new QLabel( frameBeneficiaire, "textLabelEtatCivilVille" );

    frameBeneficiaireLayout->addWidget( textLabelEtatCivilVille, 6, 0 );

    comboBoxBenefProspect = new QComboBox( FALSE, frameBeneficiaire, "comboBoxBenefProspect" );

    frameBeneficiaireLayout->addMultiCellWidget( comboBoxBenefProspect, 9, 9, 0, 1 );

    lineEditEtatCivilEmail = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilEmail" );
    lineEditEtatCivilEmail->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEtatCivilEmail->setFrameShadow( QLineEdit::Sunken );

    frameBeneficiaireLayout->addMultiCellWidget( lineEditEtatCivilEmail, 9, 9, 4, 6 );
    spacer36 = new QSpacerItem( 142, 40, QSizePolicy::Expanding, QSizePolicy::Minimum );
    frameBeneficiaireLayout->addMultiCell( spacer36, 9, 10, 2, 2 );

    labelEtatCivilEmail = new QLabel( frameBeneficiaire, "labelEtatCivilEmail" );

    frameBeneficiaireLayout->addWidget( labelEtatCivilEmail, 9, 3 );

    labelEtatCivilRaisonSociale = new QLabel( frameBeneficiaire, "labelEtatCivilRaisonSociale" );

    frameBeneficiaireLayout->addWidget( labelEtatCivilRaisonSociale, 10, 3 );

    comboBoxEtatCivilRaisonSociale = new QComboBox( FALSE, frameBeneficiaire, "comboBoxEtatCivilRaisonSociale" );

    frameBeneficiaireLayout->addMultiCellWidget( comboBoxEtatCivilRaisonSociale, 10, 10, 4, 6 );

    lineEditEtatCivilRue = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilRue" );
    lineEditEtatCivilRue->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEditEtatCivilRue->sizePolicy().hasHeightForWidth() ) );
    lineEditEtatCivilRue->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEtatCivilRue->setFrameShadow( QLineEdit::Sunken );

    frameBeneficiaireLayout->addMultiCellWidget( lineEditEtatCivilRue, 3, 3, 1, 2 );

    lineEditEtatCivilAdresseComplement = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilAdresseComplement" );

    frameBeneficiaireLayout->addMultiCellWidget( lineEditEtatCivilAdresseComplement, 4, 4, 1, 2 );

    lineEditEtatCivilVille = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilVille" );

    frameBeneficiaireLayout->addMultiCellWidget( lineEditEtatCivilVille, 6, 6, 1, 2 );

    lineEditEtatCivilTelephonePortable = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilTelephonePortable" );
    lineEditEtatCivilTelephonePortable->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEtatCivilTelephonePortable->sizePolicy().hasHeightForWidth() ) );

    frameBeneficiaireLayout->addMultiCellWidget( lineEditEtatCivilTelephonePortable, 8, 8, 1, 2 );

    lineEditEtatCivilTelephone = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilTelephone" );
    lineEditEtatCivilTelephone->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEtatCivilTelephone->sizePolicy().hasHeightForWidth() ) );

    frameBeneficiaireLayout->addMultiCellWidget( lineEditEtatCivilTelephone, 7, 7, 1, 2 );

    lineEditEtatCivilCodePostal = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilCodePostal" );
    lineEditEtatCivilCodePostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEtatCivilCodePostal->sizePolicy().hasHeightForWidth() ) );
    lineEditEtatCivilCodePostal->setMaximumSize( QSize( 60, 32767 ) );
    lineEditEtatCivilCodePostal->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEtatCivilCodePostal->setFrameShadow( QLineEdit::Sunken );

    frameBeneficiaireLayout->addWidget( lineEditEtatCivilCodePostal, 5, 1 );

    lineEditEtatCivilAdresseComplementGestion = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilAdresseComplementGestion" );
    lineEditEtatCivilAdresseComplementGestion->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEtatCivilAdresseComplementGestion->setFrameShadow( QLineEdit::Sunken );

    frameBeneficiaireLayout->addWidget( lineEditEtatCivilAdresseComplementGestion, 4, 6 );

    lineEditEtatCivilCodePostalGestion = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilCodePostalGestion" );
    lineEditEtatCivilCodePostalGestion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEtatCivilCodePostalGestion->sizePolicy().hasHeightForWidth() ) );
    lineEditEtatCivilCodePostalGestion->setMaximumSize( QSize( 60, 32767 ) );
    lineEditEtatCivilCodePostalGestion->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEtatCivilCodePostalGestion->setFrameShadow( QLineEdit::Sunken );

    frameBeneficiaireLayout->addWidget( lineEditEtatCivilCodePostalGestion, 5, 6 );

    lineEditEtatCivilVilleGestion = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilVilleGestion" );

    frameBeneficiaireLayout->addWidget( lineEditEtatCivilVilleGestion, 6, 6 );

    lineEditEtatCivilTelephonePro = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilTelephonePro" );
    lineEditEtatCivilTelephonePro->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEtatCivilTelephonePro->sizePolicy().hasHeightForWidth() ) );

    frameBeneficiaireLayout->addWidget( lineEditEtatCivilTelephonePro, 7, 6 );

    lineEditEtatCivilTelephoneFax = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilTelephoneFax" );
    lineEditEtatCivilTelephoneFax->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEtatCivilTelephoneFax->sizePolicy().hasHeightForWidth() ) );

    frameBeneficiaireLayout->addWidget( lineEditEtatCivilTelephoneFax, 8, 6 );

    textLabelEtatCivilRue_2 = new QLabel( frameBeneficiaire, "textLabelEtatCivilRue_2" );

    frameBeneficiaireLayout->addWidget( textLabelEtatCivilRue_2, 3, 5 );

    textLabelEtatCivilAdresseComplement_2 = new QLabel( frameBeneficiaire, "textLabelEtatCivilAdresseComplement_2" );

    frameBeneficiaireLayout->addWidget( textLabelEtatCivilAdresseComplement_2, 4, 5 );

    labelEtatCivilTelephone_3 = new QLabel( frameBeneficiaire, "labelEtatCivilTelephone_3" );

    frameBeneficiaireLayout->addWidget( labelEtatCivilTelephone_3, 7, 5 );

    textLabelCodePostal_2 = new QLabel( frameBeneficiaire, "textLabelCodePostal_2" );

    frameBeneficiaireLayout->addWidget( textLabelCodePostal_2, 5, 5 );

    labelEtatCivilTelephone_3_2 = new QLabel( frameBeneficiaire, "labelEtatCivilTelephone_3_2" );

    frameBeneficiaireLayout->addWidget( labelEtatCivilTelephone_3_2, 8, 5 );

    textLabelEtatCivilVille_2 = new QLabel( frameBeneficiaire, "textLabelEtatCivilVille_2" );

    frameBeneficiaireLayout->addWidget( textLabelEtatCivilVille_2, 6, 5 );
    spacer118_2 = new QSpacerItem( 61, 170, QSizePolicy::Expanding, QSizePolicy::Minimum );
    frameBeneficiaireLayout->addMultiCell( spacer118_2, 2, 8, 3, 4 );

    labelEtatCivilRue_2 = new QLabel( frameBeneficiaire, "labelEtatCivilRue_2" );

    frameBeneficiaireLayout->addMultiCellWidget( labelEtatCivilRue_2, 2, 2, 5, 6 );

    lineEditEtatCivilRueGestion = new QLineEdit( frameBeneficiaire, "lineEditEtatCivilRueGestion" );
    lineEditEtatCivilRueGestion->setFrameShape( QLineEdit::LineEditPanel );
    lineEditEtatCivilRueGestion->setFrameShadow( QLineEdit::Sunken );

    frameBeneficiaireLayout->addWidget( lineEditEtatCivilRueGestion, 3, 6 );
    WStackPageLayout_2->addWidget( frameBeneficiaire );

    layout65 = new QHBoxLayout( 0, 0, 6, "layout65"); 

    labelEtatCivilSituationFamilliale = new QLabel( WStackPage_2, "labelEtatCivilSituationFamilliale" );
    labelEtatCivilSituationFamilliale->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilSituationFamilliale->sizePolicy().hasHeightForWidth() ) );
    layout65->addWidget( labelEtatCivilSituationFamilliale );

    comboBoxEtatCivilSituationFamilliale = new QComboBox( FALSE, WStackPage_2, "comboBoxEtatCivilSituationFamilliale" );
    layout65->addWidget( comboBoxEtatCivilSituationFamilliale );
    WStackPageLayout_2->addLayout( layout65 );

    labelEtatCivilConseils = new QLabel( WStackPage_2, "labelEtatCivilConseils" );
    labelEtatCivilConseils->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilConseils->sizePolicy().hasHeightForWidth() ) );
    WStackPageLayout_2->addWidget( labelEtatCivilConseils );

    frameEtatCivilConseils = new QFrame( WStackPage_2, "frameEtatCivilConseils" );
    frameEtatCivilConseils->setFrameShape( QFrame::StyledPanel );
    frameEtatCivilConseils->setFrameShadow( QFrame::Raised );
    frameEtatCivilConseilsLayout = new QGridLayout( frameEtatCivilConseils, 1, 1, 11, 6, "frameEtatCivilConseilsLayout"); 

    comboBoxEtatCivilCabinetComptable = new QComboBox( FALSE, frameEtatCivilConseils, "comboBoxEtatCivilCabinetComptable" );
    comboBoxEtatCivilCabinetComptable->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, comboBoxEtatCivilCabinetComptable->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( comboBoxEtatCivilCabinetComptable, 0, 2 );

    comboBoxEtatCivilExpertComptable = new QComboBox( FALSE, frameEtatCivilConseils, "comboBoxEtatCivilExpertComptable" );
    comboBoxEtatCivilExpertComptable->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, comboBoxEtatCivilExpertComptable->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( comboBoxEtatCivilExpertComptable, 0, 6 );

    labelEtatCivilExpertComptable_3 = new QLabel( frameEtatCivilConseils, "labelEtatCivilExpertComptable_3" );
    labelEtatCivilExpertComptable_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilExpertComptable_3->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( labelEtatCivilExpertComptable_3, 0, 4 );

    labelEtatCivilNotaire_3 = new QLabel( frameEtatCivilConseils, "labelEtatCivilNotaire_3" );
    labelEtatCivilNotaire_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilNotaire_3->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( labelEtatCivilNotaire_3, 1, 4 );

    labelEtatCivilAvocat_3 = new QLabel( frameEtatCivilConseils, "labelEtatCivilAvocat_3" );
    labelEtatCivilAvocat_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilAvocat_3->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( labelEtatCivilAvocat_3, 2, 4 );
    spacer2_3 = new QSpacerItem( 20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding );
    frameEtatCivilConseilsLayout->addMultiCell( spacer2_3, 0, 2, 5, 5 );
    spacer3_3 = new QSpacerItem( 21, 70, QSizePolicy::Minimum, QSizePolicy::Expanding );
    frameEtatCivilConseilsLayout->addMultiCell( spacer3_3, 0, 2, 3, 3 );

    labelEtatCivilCabinetComptable_3 = new QLabel( frameEtatCivilConseils, "labelEtatCivilCabinetComptable_3" );
    labelEtatCivilCabinetComptable_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilCabinetComptable_3->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( labelEtatCivilCabinetComptable_3, 0, 0 );

    labelEtatCivilEtude_3 = new QLabel( frameEtatCivilConseils, "labelEtatCivilEtude_3" );
    labelEtatCivilEtude_3->setEnabled( TRUE );
    labelEtatCivilEtude_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilEtude_3->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( labelEtatCivilEtude_3, 1, 0 );

    labelEtatCivilCabinetAvocat_3 = new QLabel( frameEtatCivilConseils, "labelEtatCivilCabinetAvocat_3" );
    labelEtatCivilCabinetAvocat_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelEtatCivilCabinetAvocat_3->sizePolicy().hasHeightForWidth() ) );

    frameEtatCivilConseilsLayout->addWidget( labelEtatCivilCabinetAvocat_3, 2, 0 );
    spacer4_3 = new QSpacerItem( 21, 70, QSizePolicy::Minimum, QSizePolicy::Expanding );
    frameEtatCivilConseilsLayout->addMultiCell( spacer4_3, 0, 2, 1, 1 );

    comboBoxEtatCivilEtude = new QComboBox( FALSE, frameEtatCivilConseils, "comboBoxEtatCivilEtude" );

    frameEtatCivilConseilsLayout->addWidget( comboBoxEtatCivilEtude, 1, 2 );

    comboBoxEtatCivilCabinetAvocat = new QComboBox( FALSE, frameEtatCivilConseils, "comboBoxEtatCivilCabinetAvocat" );

    frameEtatCivilConseilsLayout->addWidget( comboBoxEtatCivilCabinetAvocat, 2, 2 );

    comboBoxEtatCivilNotaire = new QComboBox( FALSE, frameEtatCivilConseils, "comboBoxEtatCivilNotaire" );

    frameEtatCivilConseilsLayout->addWidget( comboBoxEtatCivilNotaire, 1, 6 );

    comboBoxEtatCivilAvocat = new QComboBox( FALSE, frameEtatCivilConseils, "comboBoxEtatCivilAvocat" );

    frameEtatCivilConseilsLayout->addWidget( comboBoxEtatCivilAvocat, 2, 6 );
    WStackPageLayout_2->addWidget( frameEtatCivilConseils );
    widgetStackAjouter->addWidget( WStackPage_2, 0 );

    WStackPage_3 = new QWidget( widgetStackAjouter, "WStackPage_3" );
    WStackPageLayout_3 = new QVBoxLayout( WStackPage_3, 11, 6, "WStackPageLayout_3"); 

    tabWidgetFamille = new QTabWidget( WStackPage_3, "tabWidgetFamille" );

    tab = new QWidget( tabWidgetFamille, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    frameConjoint = new QFrame( tab, "frameConjoint" );
    frameConjoint->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, frameConjoint->sizePolicy().hasHeightForWidth() ) );
    frameConjoint->setFrameShape( QFrame::StyledPanel );
    frameConjoint->setFrameShadow( QFrame::Raised );
    frameConjointLayout = new QGridLayout( frameConjoint, 1, 1, 11, 6, "frameConjointLayout"); 

    labelFamilleNom = new QLabel( frameConjoint, "labelFamilleNom" );

    frameConjointLayout->addWidget( labelFamilleNom, 0, 0 );

    labelFamilleAdresse = new QLabel( frameConjoint, "labelFamilleAdresse" );
    labelFamilleAdresse->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleAdresse->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addWidget( labelFamilleAdresse, 2, 0 );

    labelFamilleDateNaissance = new QLabel( frameConjoint, "labelFamilleDateNaissance" );

    frameConjointLayout->addWidget( labelFamilleDateNaissance, 1, 0 );

    textLabelFamilleRue = new QLabel( frameConjoint, "textLabelFamilleRue" );
    textLabelFamilleRue->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabelFamilleRue->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addWidget( textLabelFamilleRue, 2, 2 );

    textLabelFamilleAdresseComplement = new QLabel( frameConjoint, "textLabelFamilleAdresseComplement" );
    textLabelFamilleAdresseComplement->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabelFamilleAdresseComplement->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addWidget( textLabelFamilleAdresseComplement, 3, 2 );

    textLabelFamilleCodePostal = new QLabel( frameConjoint, "textLabelFamilleCodePostal" );
    textLabelFamilleCodePostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabelFamilleCodePostal->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addWidget( textLabelFamilleCodePostal, 4, 2 );

    lineEditFamilleCodePostal = new QLineEdit( frameConjoint, "lineEditFamilleCodePostal" );
    lineEditFamilleCodePostal->setEnabled( FALSE );
    lineEditFamilleCodePostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFamilleCodePostal->sizePolicy().hasHeightForWidth() ) );
    lineEditFamilleCodePostal->setMaximumSize( QSize( 60, 32767 ) );
    lineEditFamilleCodePostal->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleCodePostal->setFrameShadow( QLineEdit::Sunken );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleCodePostal, 4, 4, 3, 4 );

    textLabelFamilleVille = new QLabel( frameConjoint, "textLabelFamilleVille" );
    textLabelFamilleVille->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabelFamilleVille->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addWidget( textLabelFamilleVille, 4, 5 );

    lineEditFamilleVille = new QLineEdit( frameConjoint, "lineEditFamilleVille" );
    lineEditFamilleVille->setEnabled( FALSE );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleVille, 4, 4, 6, 7 );

    comboBoxFamilleConjoint = new QComboBox( FALSE, frameConjoint, "comboBoxFamilleConjoint" );

    frameConjointLayout->addMultiCellWidget( comboBoxFamilleConjoint, 0, 0, 2, 7 );

    textLabel4 = new QLabel( frameConjoint, "textLabel4" );

    frameConjointLayout->addWidget( textLabel4, 1, 4 );

    dateEditFamilleDateNaissance = new QDateEdit( frameConjoint, "dateEditFamilleDateNaissance" );
    dateEditFamilleDateNaissance->setEnabled( FALSE );
    dateEditFamilleDateNaissance->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditFamilleDateNaissance->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addMultiCellWidget( dateEditFamilleDateNaissance, 1, 1, 2, 3 );

    lineEditFamilleNomRue = new QLineEdit( frameConjoint, "lineEditFamilleNomRue" );
    lineEditFamilleNomRue->setEnabled( FALSE );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleNomRue, 2, 2, 3, 7 );

    labelFamilleTelephone = new QLabel( frameConjoint, "labelFamilleTelephone" );
    labelFamilleTelephone->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleTelephone->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addWidget( labelFamilleTelephone, 5, 0 );

    lineEditFamilleTelephone = new QLineEdit( frameConjoint, "lineEditFamilleTelephone" );
    lineEditFamilleTelephone->setEnabled( FALSE );
    lineEditFamilleTelephone->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleTelephone->setFrameShadow( QLineEdit::Sunken );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleTelephone, 5, 5, 2, 4 );

    labelFamilleTelephone_2 = new QLabel( frameConjoint, "labelFamilleTelephone_2" );
    labelFamilleTelephone_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleTelephone_2->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addMultiCellWidget( labelFamilleTelephone_2, 5, 5, 5, 6 );

    lineEditFamilleEmail = new QLineEdit( frameConjoint, "lineEditFamilleEmail" );
    lineEditFamilleEmail->setEnabled( FALSE );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleEmail, 7, 7, 2, 7 );

    labelFamilleEmail = new QLabel( frameConjoint, "labelFamilleEmail" );

    frameConjointLayout->addWidget( labelFamilleEmail, 7, 0 );

    labelFamilleTelephone_3 = new QLabel( frameConjoint, "labelFamilleTelephone_3" );
    labelFamilleTelephone_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleTelephone_3->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addWidget( labelFamilleTelephone_3, 6, 0 );

    labelFamilleTelephone_2_2 = new QLabel( frameConjoint, "labelFamilleTelephone_2_2" );
    labelFamilleTelephone_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelFamilleTelephone_2_2->sizePolicy().hasHeightForWidth() ) );

    frameConjointLayout->addMultiCellWidget( labelFamilleTelephone_2_2, 6, 6, 5, 6 );
    spacer1_2_2 = new QSpacerItem( 20, 240, QSizePolicy::Preferred, QSizePolicy::Minimum );
    frameConjointLayout->addMultiCell( spacer1_2_2, 0, 7, 1, 1 );

    lineEditFamilleLieuNaissance = new QLineEdit( frameConjoint, "lineEditFamilleLieuNaissance" );
    lineEditFamilleLieuNaissance->setEnabled( FALSE );
    lineEditFamilleLieuNaissance->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleLieuNaissance->setFrameShadow( QLineEdit::Sunken );
    lineEditFamilleLieuNaissance->setReadOnly( FALSE );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleLieuNaissance, 1, 1, 5, 6 );

    lineEditFamilleTelephonePro = new QLineEdit( frameConjoint, "lineEditFamilleTelephonePro" );
    lineEditFamilleTelephonePro->setEnabled( FALSE );
    lineEditFamilleTelephonePro->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleTelephonePro->setFrameShadow( QLineEdit::Sunken );

    frameConjointLayout->addWidget( lineEditFamilleTelephonePro, 5, 7 );

    lineEditFamilleTelephonePortable = new QLineEdit( frameConjoint, "lineEditFamilleTelephonePortable" );
    lineEditFamilleTelephonePortable->setEnabled( FALSE );
    lineEditFamilleTelephonePortable->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleTelephonePortable->setFrameShadow( QLineEdit::Sunken );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleTelephonePortable, 6, 6, 2, 4 );

    lineEditFamilleTelephoneFax = new QLineEdit( frameConjoint, "lineEditFamilleTelephoneFax" );
    lineEditFamilleTelephoneFax->setEnabled( FALSE );
    lineEditFamilleTelephoneFax->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleTelephoneFax->setFrameShadow( QLineEdit::Sunken );

    frameConjointLayout->addWidget( lineEditFamilleTelephoneFax, 6, 7 );

    lineEditFamilleAdresseComplement = new QLineEdit( frameConjoint, "lineEditFamilleAdresseComplement" );
    lineEditFamilleAdresseComplement->setEnabled( FALSE );

    frameConjointLayout->addMultiCellWidget( lineEditFamilleAdresseComplement, 3, 3, 3, 7 );

    tabLayout->addMultiCellWidget( frameConjoint, 0, 0, 0, 1 );

    frame8 = new QFrame( tab, "frame8" );
    frame8->setFrameShape( QFrame::StyledPanel );
    frame8->setFrameShadow( QFrame::Raised );
    frame8Layout = new QVBoxLayout( frame8, 11, 6, "frame8Layout"); 

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    labelFamilleSalaireAnnuel = new QLabel( frame8, "labelFamilleSalaireAnnuel" );
    layout14->addWidget( labelFamilleSalaireAnnuel );

    labelFamilleBNC = new QLabel( frame8, "labelFamilleBNC" );
    layout14->addWidget( labelFamilleBNC );

    labelFamilleBIC = new QLabel( frame8, "labelFamilleBIC" );
    layout14->addWidget( labelFamilleBIC );

    labelFamilleRevenusFonciers = new QLabel( frame8, "labelFamilleRevenusFonciers" );
    layout14->addWidget( labelFamilleRevenusFonciers );

    labelFamilleDividendes = new QLabel( frame8, "labelFamilleDividendes" );
    layout14->addWidget( labelFamilleDividendes );

    labelFamilleAutresRevenus = new QLabel( frame8, "labelFamilleAutresRevenus" );
    layout14->addWidget( labelFamilleAutresRevenus );
    layout15->addLayout( layout14 );

    layout13 = new QGridLayout( 0, 1, 1, 0, 6, "layout13"); 

    comboBoxFamilleNetBrut = new QComboBox( FALSE, frame8, "comboBoxFamilleNetBrut" );
    comboBoxFamilleNetBrut->setEnabled( FALSE );

    layout13->addWidget( comboBoxFamilleNetBrut, 0, 2 );

    lineEditFamilleAutresRevenus = new QLineEdit( frame8, "lineEditFamilleAutresRevenus" );
    lineEditFamilleAutresRevenus->setEnabled( FALSE );

    layout13->addWidget( lineEditFamilleAutresRevenus, 5, 0 );

    lineEditFamilleDividendes = new QLineEdit( frame8, "lineEditFamilleDividendes" );
    lineEditFamilleDividendes->setEnabled( FALSE );

    layout13->addWidget( lineEditFamilleDividendes, 4, 0 );

    lineEditFamilleBNC = new QLineEdit( frame8, "lineEditFamilleBNC" );
    lineEditFamilleBNC->setEnabled( FALSE );

    layout13->addWidget( lineEditFamilleBNC, 1, 0 );

    lineEditFamilleBIC = new QLineEdit( frame8, "lineEditFamilleBIC" );
    lineEditFamilleBIC->setEnabled( FALSE );
    lineEditFamilleBIC->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleBIC->setFrameShadow( QLineEdit::Sunken );

    layout13->addWidget( lineEditFamilleBIC, 2, 0 );

    lineEditFamilleSalaireAnnuel = new QLineEdit( frame8, "lineEditFamilleSalaireAnnuel" );
    lineEditFamilleSalaireAnnuel->setEnabled( FALSE );

    layout13->addWidget( lineEditFamilleSalaireAnnuel, 0, 0 );

    lineEditFamilleRevenusFonciers = new QLineEdit( frame8, "lineEditFamilleRevenusFonciers" );
    lineEditFamilleRevenusFonciers->setEnabled( FALSE );
    lineEditFamilleRevenusFonciers->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleRevenusFonciers->setFrameShadow( QLineEdit::Sunken );

    layout13->addWidget( lineEditFamilleRevenusFonciers, 3, 0 );
    spacer18 = new QSpacerItem( 20, 191, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout13->addMultiCell( spacer18, 0, 5, 1, 1 );
    layout15->addLayout( layout13 );
    frame8Layout->addLayout( layout15 );

    tabLayout->addWidget( frame8, 1, 0 );
    spacer32 = new QSpacerItem( 141, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addMultiCell( spacer32, 1, 1, 1, 2 );
    spacer33_2 = new QSpacerItem( 81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout->addItem( spacer33_2, 0, 2 );
    tabWidgetFamille->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidgetFamille, "tab_2" );
    tabLayout_2 = new QVBoxLayout( tab_2, 11, 6, "tabLayout_2"); 

    layout66 = new QHBoxLayout( 0, 0, 6, "layout66"); 

    labelFamilleDateMariage = new QLabel( tab_2, "labelFamilleDateMariage" );
    layout66->addWidget( labelFamilleDateMariage );

    dateEditFamilleDateMariage = new QDateEdit( tab_2, "dateEditFamilleDateMariage" );
    dateEditFamilleDateMariage->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditFamilleDateMariage->sizePolicy().hasHeightForWidth() ) );
    layout66->addWidget( dateEditFamilleDateMariage );

    textLabel5 = new QLabel( tab_2, "textLabel5" );
    layout66->addWidget( textLabel5 );

    lineEditFamilleRgMariage = new QLineEdit( tab_2, "lineEditFamilleRgMariage" );
    lineEditFamilleRgMariage->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFamilleRgMariage->sizePolicy().hasHeightForWidth() ) );
    lineEditFamilleRgMariage->setMaximumSize( QSize( 30, 32767 ) );
    lineEditFamilleRgMariage->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleRgMariage->setFrameShadow( QLineEdit::Sunken );
    layout66->addWidget( lineEditFamilleRgMariage );
    tabLayout_2->addLayout( layout66 );

    layout67 = new QHBoxLayout( 0, 0, 6, "layout67"); 

    labelFamilleRegimeMatrimonial = new QLabel( tab_2, "labelFamilleRegimeMatrimonial" );
    layout67->addWidget( labelFamilleRegimeMatrimonial );

    comboBoxFamilleRegimeMatrimonial = new QComboBox( FALSE, tab_2, "comboBoxFamilleRegimeMatrimonial" );
    comboBoxFamilleRegimeMatrimonial->setEnabled( TRUE );
    layout67->addWidget( comboBoxFamilleRegimeMatrimonial );

    checkBoxFamilleDonationDernierVivant = new QCheckBox( tab_2, "checkBoxFamilleDonationDernierVivant" );
    layout67->addWidget( checkBoxFamilleDonationDernierVivant );
    tabLayout_2->addLayout( layout67 );

    layout68_2 = new QHBoxLayout( 0, 0, 6, "layout68_2"); 

    textLabel2_4 = new QLabel( tab_2, "textLabel2_4" );
    layout68_2->addWidget( textLabel2_4 );

    textEditFamilleAutreDispo = new QTextEdit( tab_2, "textEditFamilleAutreDispo" );
    layout68_2->addWidget( textEditFamilleAutreDispo );
    tabLayout_2->addLayout( layout68_2 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    labelFamilleDureeMariages = new QLabel( tab_2, "labelFamilleDureeMariages" );
    layout9->addWidget( labelFamilleDureeMariages );

    labelFamilleMonsieur = new QLabel( tab_2, "labelFamilleMonsieur" );
    layout9->addWidget( labelFamilleMonsieur );

    lineEditFamilleDureeMariagesPrecedentsMonsieur = new QLineEdit( tab_2, "lineEditFamilleDureeMariagesPrecedentsMonsieur" );
    lineEditFamilleDureeMariagesPrecedentsMonsieur->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFamilleDureeMariagesPrecedentsMonsieur->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( lineEditFamilleDureeMariagesPrecedentsMonsieur );

    labelFamilleMadame = new QLabel( tab_2, "labelFamilleMadame" );
    layout9->addWidget( labelFamilleMadame );

    lineEditFamilleDureeMariagesPrecedentsMadame = new QLineEdit( tab_2, "lineEditFamilleDureeMariagesPrecedentsMadame" );
    lineEditFamilleDureeMariagesPrecedentsMadame->setEnabled( TRUE );
    lineEditFamilleDureeMariagesPrecedentsMadame->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFamilleDureeMariagesPrecedentsMadame->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( lineEditFamilleDureeMariagesPrecedentsMadame );
    tabLayout_2->addLayout( layout9 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    labelFamilleNombreEnfants = new QLabel( tab_2, "labelFamilleNombreEnfants" );
    layout8->addWidget( labelFamilleNombreEnfants );

    lineEditFamilleNombreEnfantsCommuns = new QLineEdit( tab_2, "lineEditFamilleNombreEnfantsCommuns" );
    lineEditFamilleNombreEnfantsCommuns->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFamilleNombreEnfantsCommuns->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( lineEditFamilleNombreEnfantsCommuns );

    labelFamilleNombreEnfantsMonsieur = new QLabel( tab_2, "labelFamilleNombreEnfantsMonsieur" );
    layout8->addWidget( labelFamilleNombreEnfantsMonsieur );

    lineEditFamilleNombreEnfantsMonsieur = new QLineEdit( tab_2, "lineEditFamilleNombreEnfantsMonsieur" );
    lineEditFamilleNombreEnfantsMonsieur->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFamilleNombreEnfantsMonsieur->sizePolicy().hasHeightForWidth() ) );
    lineEditFamilleNombreEnfantsMonsieur->setFrameShape( QLineEdit::LineEditPanel );
    lineEditFamilleNombreEnfantsMonsieur->setFrameShadow( QLineEdit::Sunken );
    layout8->addWidget( lineEditFamilleNombreEnfantsMonsieur );

    labelFamilleNombreEnfantsMadame = new QLabel( tab_2, "labelFamilleNombreEnfantsMadame" );
    layout8->addWidget( labelFamilleNombreEnfantsMadame );

    lineEditFamilleNombreEnfantsMadame = new QLineEdit( tab_2, "lineEditFamilleNombreEnfantsMadame" );
    lineEditFamilleNombreEnfantsMadame->setEnabled( TRUE );
    lineEditFamilleNombreEnfantsMadame->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditFamilleNombreEnfantsMadame->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( lineEditFamilleNombreEnfantsMadame );
    tabLayout_2->addLayout( layout8 );

    layout376 = new QHBoxLayout( 0, 0, 6, "layout376"); 

    textLabel3 = new QLabel( tab_2, "textLabel3" );
    layout376->addWidget( textLabel3 );

    pushButtonEnfantPlus = new QPushButton( tab_2, "pushButtonEnfantPlus" );
    pushButtonEnfantPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEnfantPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEnfantPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout376->addWidget( pushButtonEnfantPlus );

    pushButtonEnfantsMinus = new QPushButton( tab_2, "pushButtonEnfantsMinus" );
    pushButtonEnfantsMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEnfantsMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEnfantsMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout376->addWidget( pushButtonEnfantsMinus );
    tabLayout_2->addLayout( layout376 );

    listViewEnfants = new QListView( tab_2, "listViewEnfants" );
    listViewEnfants->addColumn( tr( "Nom" ) );
    listViewEnfants->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listViewEnfants->addColumn( tr( "Date de naissance" ) );
    listViewEnfants->addColumn( tr( "A charge" ) );
    listViewEnfants->addColumn( trUtf8( "\x46\x69\x6e\x61\x6e\x63\x65\x6d\x65\x6e\x74\x20\x64\x65\x73\x20\xc3\xa9\x74\x75\x64\x65\x73" ) );
    listViewEnfants->addColumn( tr( "Notes" ) );
    listViewEnfants->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, listViewEnfants->sizePolicy().hasHeightForWidth() ) );
    tabLayout_2->addWidget( listViewEnfants );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    labelFamilleDispositionsTestamentaires = new QLabel( tab_2, "labelFamilleDispositionsTestamentaires" );
    layout6->addWidget( labelFamilleDispositionsTestamentaires );

    labelFamilleDonationEntreEpoux = new QLabel( tab_2, "labelFamilleDonationEntreEpoux" );
    layout6->addWidget( labelFamilleDonationEntreEpoux );
    layout17->addLayout( layout6 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    lineEditFamilleDispositionsTestamentaires = new QLineEdit( tab_2, "lineEditFamilleDispositionsTestamentaires" );
    layout16->addWidget( lineEditFamilleDispositionsTestamentaires );

    lineEditFamilleDonationEntreEpoux = new QLineEdit( tab_2, "lineEditFamilleDonationEntreEpoux" );
    layout16->addWidget( lineEditFamilleDonationEntreEpoux );
    layout17->addLayout( layout16 );
    tabLayout_2->addLayout( layout17 );
    tabWidgetFamille->insertTab( tab_2, QString::fromLatin1("") );
    WStackPageLayout_3->addWidget( tabWidgetFamille );
    widgetStackAjouter->addWidget( WStackPage_3, 1 );

    WStackPage_4 = new QWidget( widgetStackAjouter, "WStackPage_4" );
    WStackPageLayout_4 = new QGridLayout( WStackPage_4, 1, 1, 11, 6, "WStackPageLayout_4"); 

    labelCarriereRevenus = new QLabel( WStackPage_4, "labelCarriereRevenus" );
    labelCarriereRevenus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelCarriereRevenus->sizePolicy().hasHeightForWidth() ) );

    WStackPageLayout_4->addMultiCellWidget( labelCarriereRevenus, 0, 0, 0, 1 );

    frame8_2 = new QFrame( WStackPage_4, "frame8_2" );
    frame8_2->setFrameShape( QFrame::StyledPanel );
    frame8_2->setFrameShadow( QFrame::Raised );
    frame8_2Layout = new QVBoxLayout( frame8_2, 11, 6, "frame8_2Layout"); 

    layout15_2 = new QHBoxLayout( 0, 0, 6, "layout15_2"); 

    layout14_2 = new QVBoxLayout( 0, 0, 6, "layout14_2"); 

    labelCarriereSalaireAnnuel = new QLabel( frame8_2, "labelCarriereSalaireAnnuel" );
    layout14_2->addWidget( labelCarriereSalaireAnnuel );

    labelCarriereBNC = new QLabel( frame8_2, "labelCarriereBNC" );
    layout14_2->addWidget( labelCarriereBNC );

    labelCarriereBIC = new QLabel( frame8_2, "labelCarriereBIC" );
    layout14_2->addWidget( labelCarriereBIC );

    labelCarriereRevenusFonciers = new QLabel( frame8_2, "labelCarriereRevenusFonciers" );
    layout14_2->addWidget( labelCarriereRevenusFonciers );

    labelCarriereDividendes = new QLabel( frame8_2, "labelCarriereDividendes" );
    layout14_2->addWidget( labelCarriereDividendes );

    labelCarriereAutresRevenus = new QLabel( frame8_2, "labelCarriereAutresRevenus" );
    layout14_2->addWidget( labelCarriereAutresRevenus );
    layout15_2->addLayout( layout14_2 );

    layout13_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_2"); 

    comboBoxCarriereNetBrut = new QComboBox( FALSE, frame8_2, "comboBoxCarriereNetBrut" );

    layout13_2->addWidget( comboBoxCarriereNetBrut, 0, 2 );

    lineEditCarriereAutresRevenus = new QLineEdit( frame8_2, "lineEditCarriereAutresRevenus" );
    lineEditCarriereAutresRevenus->setEnabled( TRUE );
    lineEditCarriereAutresRevenus->setFrameShape( QLineEdit::LineEditPanel );
    lineEditCarriereAutresRevenus->setFrameShadow( QLineEdit::Sunken );

    layout13_2->addWidget( lineEditCarriereAutresRevenus, 5, 0 );

    lineEditCarriereDividendes = new QLineEdit( frame8_2, "lineEditCarriereDividendes" );

    layout13_2->addWidget( lineEditCarriereDividendes, 4, 0 );

    lineEditCarriereBNC = new QLineEdit( frame8_2, "lineEditCarriereBNC" );
    lineEditCarriereBNC->setEnabled( TRUE );

    layout13_2->addWidget( lineEditCarriereBNC, 1, 0 );

    lineEditCarriereBIC = new QLineEdit( frame8_2, "lineEditCarriereBIC" );

    layout13_2->addWidget( lineEditCarriereBIC, 2, 0 );

    lineEditCarriereSalaireAnnuel = new QLineEdit( frame8_2, "lineEditCarriereSalaireAnnuel" );
    lineEditCarriereSalaireAnnuel->setFrameShadow( QLineEdit::Sunken );

    layout13_2->addWidget( lineEditCarriereSalaireAnnuel, 0, 0 );

    lineEditCarriereRevenusFonciers = new QLineEdit( frame8_2, "lineEditCarriereRevenusFonciers" );

    layout13_2->addWidget( lineEditCarriereRevenusFonciers, 3, 0 );
    spacer18_2 = new QSpacerItem( 20, 191, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout13_2->addMultiCell( spacer18_2, 0, 5, 1, 1 );
    layout15_2->addLayout( layout13_2 );
    frame8_2Layout->addLayout( layout15_2 );

    WStackPageLayout_4->addWidget( frame8_2, 1, 0 );
    spacer33 = new QSpacerItem( 272, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    WStackPageLayout_4->addItem( spacer33, 1, 1 );

    layout61 = new QGridLayout( 0, 1, 1, 0, 6, "layout61"); 
    spacer27 = new QSpacerItem( 20, 129, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout61->addMultiCell( spacer27, 0, 3, 1, 1 );

    lineEditRevenusEmployeur = new QLineEdit( WStackPage_4, "lineEditRevenusEmployeur" );

    layout61->addWidget( lineEditRevenusEmployeur, 3, 3 );

    textLabel3_3 = new QLabel( WStackPage_4, "textLabel3_3" );

    layout61->addWidget( textLabel3_3, 0, 2 );

    textLabel5_3 = new QLabel( WStackPage_4, "textLabel5_3" );

    layout61->addWidget( textLabel5_3, 3, 2 );

    frame10 = new QFrame( WStackPage_4, "frame10" );
    frame10->setEnabled( TRUE );
    frame10->setFrameShape( QFrame::StyledPanel );
    frame10->setFrameShadow( QFrame::Raised );
    frame10Layout = new QVBoxLayout( frame10, 11, 6, "frame10Layout"); 

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    labelCarriereMontantImpot = new QLabel( frame10, "labelCarriereMontantImpot" );
    layout21->addWidget( labelCarriereMontantImpot );

    labelCarriereMontantImpotMonsieur = new QLabel( frame10, "labelCarriereMontantImpotMonsieur" );
    layout21->addWidget( labelCarriereMontantImpotMonsieur );

    lineEditCarriereMontantImpotMonsieur = new QLineEdit( frame10, "lineEditCarriereMontantImpotMonsieur" );
    layout21->addWidget( lineEditCarriereMontantImpotMonsieur );

    labelCarriereMontantImpotMadame = new QLabel( frame10, "labelCarriereMontantImpotMadame" );
    layout21->addWidget( labelCarriereMontantImpotMadame );

    lineEditCarriereMontantImpotMadame = new QLineEdit( frame10, "lineEditCarriereMontantImpotMadame" );
    lineEditCarriereMontantImpotMadame->setEnabled( FALSE );
    layout21->addWidget( lineEditCarriereMontantImpotMadame );
    frame10Layout->addLayout( layout21 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    labelCarriereISF = new QLabel( frame10, "labelCarriereISF" );
    layout26->addWidget( labelCarriereISF );

    comboBoxCarriereISF = new QComboBox( FALSE, frame10, "comboBoxCarriereISF" );
    layout26->addWidget( comboBoxCarriereISF );

    labelCarriereMontant = new QLabel( frame10, "labelCarriereMontant" );
    layout26->addWidget( labelCarriereMontant );

    lineEditCarriereMontantISF = new QLineEdit( frame10, "lineEditCarriereMontantISF" );
    layout26->addWidget( lineEditCarriereMontantISF );

    labelCarriereCGA = new QLabel( frame10, "labelCarriereCGA" );
    layout26->addWidget( labelCarriereCGA );

    comboBoxCarriereCGA = new QComboBox( FALSE, frame10, "comboBoxCarriereCGA" );
    layout26->addWidget( comboBoxCarriereCGA );
    frame10Layout->addLayout( layout26 );

    layout21_2 = new QHBoxLayout( 0, 0, 6, "layout21_2"); 

    labelCarriereDeductions = new QLabel( frame10, "labelCarriereDeductions" );
    layout21_2->addWidget( labelCarriereDeductions );

    labelCarriereDeductionsMonsieur = new QLabel( frame10, "labelCarriereDeductionsMonsieur" );
    layout21_2->addWidget( labelCarriereDeductionsMonsieur );

    lineEditCarriereDeductionsMonsieur = new QLineEdit( frame10, "lineEditCarriereDeductionsMonsieur" );
    lineEditCarriereDeductionsMonsieur->setEnabled( TRUE );
    layout21_2->addWidget( lineEditCarriereDeductionsMonsieur );

    labelCarriereDeductionMadame = new QLabel( frame10, "labelCarriereDeductionMadame" );
    layout21_2->addWidget( labelCarriereDeductionMadame );

    lineEditCarriereDeductionsMadame = new QLineEdit( frame10, "lineEditCarriereDeductionsMadame" );
    lineEditCarriereDeductionsMadame->setEnabled( FALSE );
    layout21_2->addWidget( lineEditCarriereDeductionsMadame );
    frame10Layout->addLayout( layout21_2 );

    layout61->addMultiCellWidget( frame10, 1, 3, 0, 0 );

    comboBoxRevenusMoisBilan = new QComboBox( FALSE, WStackPage_4, "comboBoxRevenusMoisBilan" );

    layout61->addWidget( comboBoxRevenusMoisBilan, 2, 3 );

    comboBoxStatutPro = new QComboBox( FALSE, WStackPage_4, "comboBoxStatutPro" );

    layout61->addWidget( comboBoxStatutPro, 0, 3 );

    textLabel4_3 = new QLabel( WStackPage_4, "textLabel4_3" );

    layout61->addWidget( textLabel4_3, 2, 2 );

    labelCarriereFiscalite = new QLabel( WStackPage_4, "labelCarriereFiscalite" );
    labelCarriereFiscalite->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelCarriereFiscalite->sizePolicy().hasHeightForWidth() ) );

    layout61->addWidget( labelCarriereFiscalite, 0, 0 );

    textLabel6 = new QLabel( WStackPage_4, "textLabel6" );

    layout61->addWidget( textLabel6, 1, 2 );

    lineEditRevenusFonction = new QLineEdit( WStackPage_4, "lineEditRevenusFonction" );

    layout61->addWidget( lineEditRevenusFonction, 1, 3 );

    WStackPageLayout_4->addMultiCellLayout( layout61, 2, 2, 0, 1 );

    layout223 = new QHBoxLayout( 0, 0, 6, "layout223"); 

    labelCarriereEmplois = new QLabel( WStackPage_4, "labelCarriereEmplois" );
    labelCarriereEmplois->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelCarriereEmplois->sizePolicy().hasHeightForWidth() ) );
    layout223->addWidget( labelCarriereEmplois );

    pushButtonCarriereEmploiPlus = new QPushButton( WStackPage_4, "pushButtonCarriereEmploiPlus" );
    pushButtonCarriereEmploiPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonCarriereEmploiPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonCarriereEmploiPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout223->addWidget( pushButtonCarriereEmploiPlus );

    pushButtonCarriereEmploiMinus = new QPushButton( WStackPage_4, "pushButtonCarriereEmploiMinus" );
    pushButtonCarriereEmploiMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonCarriereEmploiMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonCarriereEmploiMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout223->addWidget( pushButtonCarriereEmploiMinus );

    WStackPageLayout_4->addMultiCellLayout( layout223, 3, 3, 0, 1 );

    listViewCarriereEmploi = new QListView( WStackPage_4, "listViewCarriereEmploi" );
    listViewCarriereEmploi->addColumn( trUtf8( "\x44\x61\x74\x65\x20\x64\x27\x65\x6e\x74\x72\xc3\xa9\x65" ) );
    listViewCarriereEmploi->addColumn( tr( "Date de sortie" ) );
    listViewCarriereEmploi->addColumn( trUtf8( "\x52\x65\x76\x65\x6e\x75\x73\x20\x28\xe2\x82\xac\x29" ) );
    listViewCarriereEmploi->addColumn( tr( "Points RCO" ) );
    listViewCarriereEmploi->addColumn( tr( "Status" ) );
    listViewCarriereEmploi->addColumn( tr( "Note" ) );

    WStackPageLayout_4->addMultiCellWidget( listViewCarriereEmploi, 4, 4, 0, 1 );

    layout65_2 = new QHBoxLayout( 0, 0, 6, "layout65_2"); 

    labelCarriereAgeRetraite = new QLabel( WStackPage_4, "labelCarriereAgeRetraite" );
    layout65_2->addWidget( labelCarriereAgeRetraite );

    lineEditCarriereAgeRetraite = new QLineEdit( WStackPage_4, "lineEditCarriereAgeRetraite" );
    layout65_2->addWidget( lineEditCarriereAgeRetraite );
    spacer39 = new QSpacerItem( 380, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout65_2->addItem( spacer39 );

    WStackPageLayout_4->addMultiCellLayout( layout65_2, 5, 5, 0, 1 );
    widgetStackAjouter->addWidget( WStackPage_4, 2 );

    WStackPage_5 = new QWidget( widgetStackAjouter, "WStackPage_5" );
    WStackPageLayout_5 = new QHBoxLayout( WStackPage_5, 11, 6, "WStackPageLayout_5"); 

    tabWidget3 = new QTabWidget( WStackPage_5, "tabWidget3" );

    tab_3 = new QWidget( tabWidget3, "tab_3" );
    tabLayout_3 = new QGridLayout( tab_3, 1, 1, 11, 6, "tabLayout_3"); 

    comboBoxPrevoyanceSanteSource = new QComboBox( FALSE, tab_3, "comboBoxPrevoyanceSanteSource" );

    tabLayout_3->addMultiCellWidget( comboBoxPrevoyanceSanteSource, 4, 4, 1, 2 );

    checkBoxPrevoyanceSanteCaractereViagerEntreprise = new QCheckBox( tab_3, "checkBoxPrevoyanceSanteCaractereViagerEntreprise" );

    tabLayout_3->addMultiCellWidget( checkBoxPrevoyanceSanteCaractereViagerEntreprise, 2, 2, 7, 9 );

    lineEditPrevoyanceSanteNiveauGarantie = new QLineEdit( tab_3, "lineEditPrevoyanceSanteNiveauGarantie" );

    tabLayout_3->addMultiCellWidget( lineEditPrevoyanceSanteNiveauGarantie, 0, 0, 2, 3 );

    labelPrevoyanceSanteCompagnie = new QLabel( tab_3, "labelPrevoyanceSanteCompagnie" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceSanteCompagnie, 3, 3, 3, 4 );

    labelPrevoyanceCotisationAnnuelle = new QLabel( tab_3, "labelPrevoyanceCotisationAnnuelle" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceCotisationAnnuelle, 0, 0, 9, 10 );

    labelPrevoyanceNiveauGarantie = new QLabel( tab_3, "labelPrevoyanceNiveauGarantie" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceNiveauGarantie, 0, 0, 0, 1 );

    textLabel1_5 = new QLabel( tab_3, "textLabel1_5" );

    tabLayout_3->addWidget( textLabel1_5, 4, 0 );

    checkBoxPrevoyanceSanteCaractereViagerNon = new QCheckBox( tab_3, "checkBoxPrevoyanceSanteCaractereViagerNon" );

    tabLayout_3->addMultiCellWidget( checkBoxPrevoyanceSanteCaractereViagerNon, 2, 2, 3, 4 );

    checkBoxPrevoyanceSanteCaractereViagerOui = new QCheckBox( tab_3, "checkBoxPrevoyanceSanteCaractereViagerOui" );

    tabLayout_3->addWidget( checkBoxPrevoyanceSanteCaractereViagerOui, 2, 2 );

    labelPrevoyanceSanteFiscalite = new QLabel( tab_3, "labelPrevoyanceSanteFiscalite" );

    tabLayout_3->addWidget( labelPrevoyanceSanteFiscalite, 3, 0 );

    labelPrevoyanceSanteCaractereViager = new QLabel( tab_3, "labelPrevoyanceSanteCaractereViager" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceSanteCaractereViager, 2, 2, 0, 1 );

    labelPrevoyanceSanteDateEffet = new QLabel( tab_3, "labelPrevoyanceSanteDateEffet" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceSanteDateEffet, 0, 0, 4, 5 );

    dateEditPrevoyanceDateEffet = new QDateEdit( tab_3, "dateEditPrevoyanceDateEffet" );
    dateEditPrevoyanceDateEffet->setDate( QDate( 2000, 1, 1 ) );

    tabLayout_3->addMultiCellWidget( dateEditPrevoyanceDateEffet, 0, 0, 6, 8 );

    lineEditPrevoyanceSanteFiscalite = new QLineEdit( tab_3, "lineEditPrevoyanceSanteFiscalite" );
    lineEditPrevoyanceSanteFiscalite->setFrameShape( QLineEdit::LineEditPanel );
    lineEditPrevoyanceSanteFiscalite->setFrameShadow( QLineEdit::Sunken );

    tabLayout_3->addMultiCellWidget( lineEditPrevoyanceSanteFiscalite, 3, 3, 1, 2 );
    spacer30 = new QSpacerItem( 282, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout_3->addMultiCell( spacer30, 4, 4, 3, 9 );

    lineEditPrevoyanceSanteCotisationAnnuelle = new QLineEdit( tab_3, "lineEditPrevoyanceSanteCotisationAnnuelle" );
    lineEditPrevoyanceSanteCotisationAnnuelle->setMaximumSize( QSize( 60, 32767 ) );

    tabLayout_3->addWidget( lineEditPrevoyanceSanteCotisationAnnuelle, 0, 11 );

    lineEditPrevoyanceSanteContrat = new QLineEdit( tab_3, "lineEditPrevoyanceSanteContrat" );

    tabLayout_3->addMultiCellWidget( lineEditPrevoyanceSanteContrat, 3, 3, 10, 11 );

    labelPrevoyanceIndiceSatisfaction = new QLabel( tab_3, "labelPrevoyanceIndiceSatisfaction" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceIndiceSatisfaction, 1, 1, 0, 1 );

    labelPrevoyanceBeneficiaires = new QLabel( tab_3, "labelPrevoyanceBeneficiaires" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceBeneficiaires, 1, 1, 5, 6 );

    lineEditPrevoyanceSanteIndiceSatisfaction = new QLineEdit( tab_3, "lineEditPrevoyanceSanteIndiceSatisfaction" );
    lineEditPrevoyanceSanteIndiceSatisfaction->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditPrevoyanceSanteIndiceSatisfaction->sizePolicy().hasHeightForWidth() ) );
    lineEditPrevoyanceSanteIndiceSatisfaction->setMaximumSize( QSize( 20, 32767 ) );

    tabLayout_3->addWidget( lineEditPrevoyanceSanteIndiceSatisfaction, 1, 2 );

    labelPrevoyanceSanteContrat = new QLabel( tab_3, "labelPrevoyanceSanteContrat" );

    tabLayout_3->addMultiCellWidget( labelPrevoyanceSanteContrat, 3, 3, 8, 9 );

    checkBoxPrevoyanceSanteCaractereViagerPersonnel = new QCheckBox( tab_3, "checkBoxPrevoyanceSanteCaractereViagerPersonnel" );

    tabLayout_3->addMultiCellWidget( checkBoxPrevoyanceSanteCaractereViagerPersonnel, 2, 2, 5, 6 );

    comboBoxPrevoyanceSanteBeneficiaires = new QComboBox( FALSE, tab_3, "comboBoxPrevoyanceSanteBeneficiaires" );

    tabLayout_3->addMultiCellWidget( comboBoxPrevoyanceSanteBeneficiaires, 1, 1, 7, 9 );

    textEditNotesPrevoyanceSante = new QTextEdit( tab_3, "textEditNotesPrevoyanceSante" );

    tabLayout_3->addMultiCellWidget( textEditNotesPrevoyanceSante, 6, 6, 0, 11 );

    textLabel1_6 = new QLabel( tab_3, "textLabel1_6" );

    tabLayout_3->addWidget( textLabel1_6, 5, 0 );

    comboBoxPrevoyanceSanteCompagnie = new QComboBox( FALSE, tab_3, "comboBoxPrevoyanceSanteCompagnie" );

    tabLayout_3->addMultiCellWidget( comboBoxPrevoyanceSanteCompagnie, 3, 3, 5, 7 );
    tabWidget3->insertTab( tab_3, QString::fromLatin1("") );

    TabPage = new QWidget( tabWidget3, "TabPage" );
    TabPageLayout = new QGridLayout( TabPage, 1, 1, 11, 6, "TabPageLayout"); 

    textLabel34 = new QLabel( TabPage, "textLabel34" );
    textLabel34->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)3, 0, 0, textLabel34->sizePolicy().hasHeightForWidth() ) );

    TabPageLayout->addMultiCellWidget( textLabel34, 2, 2, 0, 1 );

    frame13 = new QFrame( TabPage, "frame13" );
    frame13->setFrameShape( QFrame::StyledPanel );
    frame13->setFrameShadow( QFrame::Raised );
    frame13Layout = new QGridLayout( frame13, 1, 1, 11, 6, "frame13Layout"); 

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 

    labelPrevoyanceSanteCapitauxInvalidite = new QLabel( frame13, "labelPrevoyanceSanteCapitauxInvalidite" );
    labelPrevoyanceSanteCapitauxInvalidite->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, labelPrevoyanceSanteCapitauxInvalidite->sizePolicy().hasHeightForWidth() ) );
    labelPrevoyanceSanteCapitauxInvalidite->setMaximumSize( QSize( 32767, 20 ) );
    layout30->addWidget( labelPrevoyanceSanteCapitauxInvalidite );

    lineEditPrevoyanceSanteCapitauxInvalidite = new QLineEdit( frame13, "lineEditPrevoyanceSanteCapitauxInvalidite" );
    lineEditPrevoyanceSanteCapitauxInvalidite->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditPrevoyanceSanteCapitauxInvalidite->sizePolicy().hasHeightForWidth() ) );
    layout30->addWidget( lineEditPrevoyanceSanteCapitauxInvalidite );

    frame13Layout->addMultiCellLayout( layout30, 4, 4, 0, 4 );

    labelPrevoyanceSanteInvalidite33 = new QLabel( frame13, "labelPrevoyanceSanteInvalidite33" );

    frame13Layout->addWidget( labelPrevoyanceSanteInvalidite33, 2, 1 );

    labelPrevoyanceSanteInvaliditeMiseAJour = new QLabel( frame13, "labelPrevoyanceSanteInvaliditeMiseAJour" );

    frame13Layout->addWidget( labelPrevoyanceSanteInvaliditeMiseAJour, 3, 3 );

    labelPrevoyanceSanteInvalidite66 = new QLabel( frame13, "labelPrevoyanceSanteInvalidite66" );

    frame13Layout->addWidget( labelPrevoyanceSanteInvalidite66, 1, 1 );

    labelPrevoyanceSanteMontantRente = new QLabel( frame13, "labelPrevoyanceSanteMontantRente" );

    frame13Layout->addWidget( labelPrevoyanceSanteMontantRente, 0, 0 );

    labelPrevoyanceSanteInvalidite100 = new QLabel( frame13, "labelPrevoyanceSanteInvalidite100" );

    frame13Layout->addWidget( labelPrevoyanceSanteInvalidite100, 0, 1 );

    dateEditPrevoyanceSanteInvaliditeDateEffet = new QDateEdit( frame13, "dateEditPrevoyanceSanteInvaliditeDateEffet" );

    frame13Layout->addWidget( dateEditPrevoyanceSanteInvaliditeDateEffet, 2, 4 );

    labelPrevoyanceSanteInvaliditeProfessionnelle = new QLabel( frame13, "labelPrevoyanceSanteInvaliditeProfessionnelle" );

    frame13Layout->addMultiCellWidget( labelPrevoyanceSanteInvaliditeProfessionnelle, 3, 3, 0, 1 );

    lineEditPrevoyanceSanteInvalidite100 = new QLineEdit( frame13, "lineEditPrevoyanceSanteInvalidite100" );

    frame13Layout->addWidget( lineEditPrevoyanceSanteInvalidite100, 2, 2 );

    lineEditPrevoyanceSanteInvalidite33 = new QLineEdit( frame13, "lineEditPrevoyanceSanteInvalidite33" );

    frame13Layout->addWidget( lineEditPrevoyanceSanteInvalidite33, 0, 2 );

    dateEditPRevoyanceSanteInvaliditeMiseAJour = new QDateEdit( frame13, "dateEditPRevoyanceSanteInvaliditeMiseAJour" );

    frame13Layout->addWidget( dateEditPRevoyanceSanteInvaliditeMiseAJour, 3, 4 );

    comboBoxPrevoyanceSanteInvaliditeProfessionnelle = new QComboBox( FALSE, frame13, "comboBoxPrevoyanceSanteInvaliditeProfessionnelle" );

    frame13Layout->addWidget( comboBoxPrevoyanceSanteInvaliditeProfessionnelle, 3, 2 );

    labelPrevoyanceSanteInvaliditeDateEffet = new QLabel( frame13, "labelPrevoyanceSanteInvaliditeDateEffet" );

    frame13Layout->addWidget( labelPrevoyanceSanteInvaliditeDateEffet, 2, 3 );

    lineEditPrevoyanceSanteInvalidite66 = new QLineEdit( frame13, "lineEditPrevoyanceSanteInvalidite66" );

    frame13Layout->addWidget( lineEditPrevoyanceSanteInvalidite66, 1, 2 );

    comboBoxPrevoyanceSanteInvaliditeFiscalite = new QComboBox( FALSE, frame13, "comboBoxPrevoyanceSanteInvaliditeFiscalite" );

    frame13Layout->addWidget( comboBoxPrevoyanceSanteInvaliditeFiscalite, 0, 4 );

    labelPrevoyanceSanteInvaliditeCompagnie = new QLabel( frame13, "labelPrevoyanceSanteInvaliditeCompagnie" );

    frame13Layout->addWidget( labelPrevoyanceSanteInvaliditeCompagnie, 1, 3 );

    comboBoxPrevoyanceSanteInvaliditeCompagnie = new QComboBox( FALSE, frame13, "comboBoxPrevoyanceSanteInvaliditeCompagnie" );

    frame13Layout->addWidget( comboBoxPrevoyanceSanteInvaliditeCompagnie, 1, 4 );

    labelPrevoyanceSanteInvaliditeFiscalite = new QLabel( frame13, "labelPrevoyanceSanteInvaliditeFiscalite" );

    frame13Layout->addWidget( labelPrevoyanceSanteInvaliditeFiscalite, 0, 3 );

    TabPageLayout->addMultiCellWidget( frame13, 3, 3, 0, 1 );

    textEditNotesPrevoyanceInvalidite = new QTextEdit( TabPage, "textEditNotesPrevoyanceInvalidite" );
    textEditNotesPrevoyanceInvalidite->setLineWidth( 2 );
    textEditNotesPrevoyanceInvalidite->setTabStopWidth( 40 );

    TabPageLayout->addWidget( textEditNotesPrevoyanceInvalidite, 4, 1 );

    textLabel2_5 = new QLabel( TabPage, "textLabel2_5" );

    TabPageLayout->addWidget( textLabel2_5, 4, 0 );

    frameArretDeTravail = new QFrame( TabPage, "frameArretDeTravail" );
    frameArretDeTravail->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, frameArretDeTravail->sizePolicy().hasHeightForWidth() ) );
    frameArretDeTravail->setFrameShape( QFrame::StyledPanel );
    frameArretDeTravail->setFrameShadow( QFrame::Raised );
    frameArretDeTravailLayout = new QGridLayout( frameArretDeTravail, 1, 1, 11, 6, "frameArretDeTravailLayout"); 

    layout28_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout28_2"); 

    labelPrevoyanceSanteArretTravailAccordAssocies = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteArretTravailAccordAssocies" );

    layout28_2->addWidget( labelPrevoyanceSanteArretTravailAccordAssocies, 2, 0 );

    labelPrevoyanceSanteArretTravailDateEffet = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteArretTravailDateEffet" );

    layout28_2->addWidget( labelPrevoyanceSanteArretTravailDateEffet, 0, 0 );

    dateEditPrevoyanceSanteArretTravailDateEffet = new QDateEdit( frameArretDeTravail, "dateEditPrevoyanceSanteArretTravailDateEffet" );

    layout28_2->addWidget( dateEditPrevoyanceSanteArretTravailDateEffet, 0, 1 );

    labelPrevoyanceSanteArretTravailDuree = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteArretTravailDuree" );

    layout28_2->addWidget( labelPrevoyanceSanteArretTravailDuree, 2, 2 );

    comboBoxPrevoyanceSanteArretTravailAccordAssocies = new QComboBox( FALSE, frameArretDeTravail, "comboBoxPrevoyanceSanteArretTravailAccordAssocies" );

    layout28_2->addWidget( comboBoxPrevoyanceSanteArretTravailAccordAssocies, 2, 1 );

    labelPrevoyanceSanteArretTravailDateMiseAJour = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteArretTravailDateMiseAJour" );

    layout28_2->addWidget( labelPrevoyanceSanteArretTravailDateMiseAJour, 1, 0 );

    lineEditPrevoyanceSanteArretTravailDuree = new QLineEdit( frameArretDeTravail, "lineEditPrevoyanceSanteArretTravailDuree" );
    lineEditPrevoyanceSanteArretTravailDuree->setMaximumSize( QSize( 18, 32767 ) );

    layout28_2->addWidget( lineEditPrevoyanceSanteArretTravailDuree, 2, 3 );

    dateEditPrevoyanceSanteArretTravailDateMiseAJour = new QDateEdit( frameArretDeTravail, "dateEditPrevoyanceSanteArretTravailDateMiseAJour" );

    layout28_2->addWidget( dateEditPrevoyanceSanteArretTravailDateMiseAJour, 1, 1 );

    frameArretDeTravailLayout->addMultiCellLayout( layout28_2, 4, 4, 3, 7 );

    pushButtonPrevoyanceArretTravailMinus = new QPushButton( frameArretDeTravail, "pushButtonPrevoyanceArretTravailMinus" );
    pushButtonPrevoyanceArretTravailMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceArretTravailMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceArretTravailMinus->setMaximumSize( QSize( 20, 32767 ) );

    frameArretDeTravailLayout->addWidget( pushButtonPrevoyanceArretTravailMinus, 0, 2 );

    pushButtonPrevoyanceArretTravailPlus = new QPushButton( frameArretDeTravail, "pushButtonPrevoyanceArretTravailPlus" );
    pushButtonPrevoyanceArretTravailPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceArretTravailPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceArretTravailPlus->setMaximumSize( QSize( 20, 32767 ) );

    frameArretDeTravailLayout->addWidget( pushButtonPrevoyanceArretTravailPlus, 0, 1 );
    spacer12_2 = new QSpacerItem( 151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    frameArretDeTravailLayout->addItem( spacer12_2, 0, 0 );

    listViewArretTravail = new QListView( frameArretDeTravail, "listViewArretTravail" );
    listViewArretTravail->addColumn( trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x49\x4a\x20\x28\xe2\x82\xac\x29" ) );
    listViewArretTravail->addColumn( trUtf8( "\x46\x72\x61\x6e\x63\x68\x69\x73\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewArretTravail->addColumn( trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );
    listViewArretTravail->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, listViewArretTravail->sizePolicy().hasHeightForWidth() ) );
    listViewArretTravail->setMinimumSize( QSize( 220, 0 ) );

    frameArretDeTravailLayout->addMultiCellWidget( listViewArretTravail, 1, 4, 0, 2 );

    labelPrevoyanceSanteContratArretTravail = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteContratArretTravail" );

    frameArretDeTravailLayout->addWidget( labelPrevoyanceSanteContratArretTravail, 2, 6 );

    labelPrevoyanceSanteFranchises = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteFranchises" );
    labelPrevoyanceSanteFranchises->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, labelPrevoyanceSanteFranchises->sizePolicy().hasHeightForWidth() ) );

    frameArretDeTravailLayout->addWidget( labelPrevoyanceSanteFranchises, 0, 3 );

    lineEditPrevoyanceSanteHospitalisation = new QLineEdit( frameArretDeTravail, "lineEditPrevoyanceSanteHospitalisation" );

    frameArretDeTravailLayout->addWidget( lineEditPrevoyanceSanteHospitalisation, 3, 4 );

    lineEditPrevoyanceSanteMaladie = new QLineEdit( frameArretDeTravail, "lineEditPrevoyanceSanteMaladie" );

    frameArretDeTravailLayout->addWidget( lineEditPrevoyanceSanteMaladie, 1, 4 );
    spacer8 = new QSpacerItem( 20, 72, QSizePolicy::Minimum, QSizePolicy::Expanding );
    frameArretDeTravailLayout->addMultiCell( spacer8, 1, 3, 5, 5 );

    labelPrevoyanceSanteCompagnieArretTravail = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteCompagnieArretTravail" );

    frameArretDeTravailLayout->addWidget( labelPrevoyanceSanteCompagnieArretTravail, 1, 6 );

    labelPrevoyanceanteHospitalisation = new QLabel( frameArretDeTravail, "labelPrevoyanceanteHospitalisation" );

    frameArretDeTravailLayout->addWidget( labelPrevoyanceanteHospitalisation, 3, 3 );

    labelPrevoyanceSanteFiscaliteArretTravail = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteFiscaliteArretTravail" );

    frameArretDeTravailLayout->addWidget( labelPrevoyanceSanteFiscaliteArretTravail, 3, 6 );

    labelPrevoyanceAccident = new QLabel( frameArretDeTravail, "labelPrevoyanceAccident" );

    frameArretDeTravailLayout->addWidget( labelPrevoyanceAccident, 2, 3 );

    labelPrevoyanceSanteMaladie = new QLabel( frameArretDeTravail, "labelPrevoyanceSanteMaladie" );

    frameArretDeTravailLayout->addWidget( labelPrevoyanceSanteMaladie, 1, 3 );

    lineEditPrevoyanceSanteContratArretTravail = new QLineEdit( frameArretDeTravail, "lineEditPrevoyanceSanteContratArretTravail" );

    frameArretDeTravailLayout->addWidget( lineEditPrevoyanceSanteContratArretTravail, 2, 7 );

    lineEditPrevoyanceSanteAccident = new QLineEdit( frameArretDeTravail, "lineEditPrevoyanceSanteAccident" );

    frameArretDeTravailLayout->addWidget( lineEditPrevoyanceSanteAccident, 2, 4 );

    comboBoxPrevoyanceSanteFiscaliteArretTravail = new QComboBox( FALSE, frameArretDeTravail, "comboBoxPrevoyanceSanteFiscaliteArretTravail" );

    frameArretDeTravailLayout->addWidget( comboBoxPrevoyanceSanteFiscaliteArretTravail, 3, 7 );

    comboBoxPrevoyanceSanteCompagnieArretTravail = new QComboBox( FALSE, frameArretDeTravail, "comboBoxPrevoyanceSanteCompagnieArretTravail" );

    frameArretDeTravailLayout->addWidget( comboBoxPrevoyanceSanteCompagnieArretTravail, 1, 7 );

    TabPageLayout->addMultiCellWidget( frameArretDeTravail, 1, 1, 0, 1 );

    labelPrevoyanceArretTravail = new QLabel( TabPage, "labelPrevoyanceArretTravail" );
    labelPrevoyanceArretTravail->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelPrevoyanceArretTravail->sizePolicy().hasHeightForWidth() ) );
    labelPrevoyanceArretTravail->setMaximumSize( QSize( 32767, 30 ) );

    TabPageLayout->addMultiCellWidget( labelPrevoyanceArretTravail, 0, 0, 0, 1 );
    tabWidget3->insertTab( TabPage, QString::fromLatin1("") );

    TabPage_2 = new QWidget( tabWidget3, "TabPage_2" );
    TabPageLayout_2 = new QGridLayout( TabPage_2, 1, 1, 11, 6, "TabPageLayout_2"); 

    layout101 = new QHBoxLayout( 0, 0, 6, "layout101"); 

    textLabelPrevoyanceDecesGarantie = new QLabel( TabPage_2, "textLabelPrevoyanceDecesGarantie" );
    textLabelPrevoyanceDecesGarantie->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabelPrevoyanceDecesGarantie->sizePolicy().hasHeightForWidth() ) );
    textLabelPrevoyanceDecesGarantie->setMaximumSize( QSize( 32767, 20 ) );
    layout101->addWidget( textLabelPrevoyanceDecesGarantie );

    pushButtonPrevoyanceGarantieDecesPlus = new QPushButton( TabPage_2, "pushButtonPrevoyanceGarantieDecesPlus" );
    pushButtonPrevoyanceGarantieDecesPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceGarantieDecesPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceGarantieDecesPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout101->addWidget( pushButtonPrevoyanceGarantieDecesPlus );

    pushButtonPrevoyanceGarantieDecesMinus = new QPushButton( TabPage_2, "pushButtonPrevoyanceGarantieDecesMinus" );
    pushButtonPrevoyanceGarantieDecesMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceGarantieDecesMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceGarantieDecesMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout101->addWidget( pushButtonPrevoyanceGarantieDecesMinus );

    TabPageLayout_2->addMultiCellLayout( layout101, 0, 0, 0, 10 );

    listViewGarantieDeces = new QListView( TabPage_2, "listViewGarantieDeces" );
    listViewGarantieDeces->addColumn( tr( "Capital" ) );
    listViewGarantieDeces->addColumn( tr( "Maladie" ) );
    listViewGarantieDeces->addColumn( tr( "Accident" ) );
    listViewGarantieDeces->addColumn( trUtf8( "\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65" ) );
    listViewGarantieDeces->addColumn( trUtf8( "\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9" ) );
    listViewGarantieDeces->addColumn( tr( "Compagnie" ) );
    listViewGarantieDeces->addColumn( tr( "Date d'effet" ) );
    listViewGarantieDeces->addColumn( trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );

    TabPageLayout_2->addMultiCellWidget( listViewGarantieDeces, 1, 1, 0, 10 );

    labelPrevoyanceDecesRenteConjoint_2 = new QLabel( TabPage_2, "labelPrevoyanceDecesRenteConjoint_2" );
    labelPrevoyanceDecesRenteConjoint_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelPrevoyanceDecesRenteConjoint_2->sizePolicy().hasHeightForWidth() ) );

    TabPageLayout_2->addMultiCellWidget( labelPrevoyanceDecesRenteConjoint_2, 5, 5, 0, 10 );

    layout69_2 = new QHBoxLayout( 0, 0, 6, "layout69_2"); 

    textLabel1_7 = new QLabel( TabPage_2, "textLabel1_7" );
    layout69_2->addWidget( textLabel1_7 );

    textEditPrevoyanceDecesNotes = new QTextEdit( TabPage_2, "textEditPrevoyanceDecesNotes" );
    layout69_2->addWidget( textEditPrevoyanceDecesNotes );

    TabPageLayout_2->addMultiCellLayout( layout69_2, 9, 9, 0, 10 );

    labelPrevoyanceDecesRenteConjointCompagnie = new QLabel( TabPage_2, "labelPrevoyanceDecesRenteConjointCompagnie" );

    TabPageLayout_2->addWidget( labelPrevoyanceDecesRenteConjointCompagnie, 4, 3 );

    dateEditPrevoyanceDecesRenteConjointDateEffet = new QDateEdit( TabPage_2, "dateEditPrevoyanceDecesRenteConjointDateEffet" );

    TabPageLayout_2->addWidget( dateEditPrevoyanceDecesRenteConjointDateEffet, 4, 10 );

    labelPeevoyanceDecesRenteFiscalite = new QLabel( TabPage_2, "labelPeevoyanceDecesRenteFiscalite" );

    TabPageLayout_2->addMultiCellWidget( labelPeevoyanceDecesRenteFiscalite, 4, 4, 0, 1 );

    labelPrevoyanceDecesRenteConjointDateEffet = new QLabel( TabPage_2, "labelPrevoyanceDecesRenteConjointDateEffet" );

    TabPageLayout_2->addMultiCellWidget( labelPrevoyanceDecesRenteConjointDateEffet, 4, 4, 8, 9 );

    comboBoxPrevoyanceDecesRenteConjointFiscalite = new QComboBox( FALSE, TabPage_2, "comboBoxPrevoyanceDecesRenteConjointFiscalite" );

    TabPageLayout_2->addWidget( comboBoxPrevoyanceDecesRenteConjointFiscalite, 4, 2 );

    labelPeevoyanceDecesRenteMontant = new QLabel( TabPage_2, "labelPeevoyanceDecesRenteMontant" );

    TabPageLayout_2->addMultiCellWidget( labelPeevoyanceDecesRenteMontant, 3, 3, 0, 1 );

    lineEditPrevoyanceDecesRenteConjointMontant = new QLineEdit( TabPage_2, "lineEditPrevoyanceDecesRenteConjointMontant" );
    lineEditPrevoyanceDecesRenteConjointMontant->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditPrevoyanceDecesRenteConjointMontant->sizePolicy().hasHeightForWidth() ) );

    TabPageLayout_2->addWidget( lineEditPrevoyanceDecesRenteConjointMontant, 3, 2 );

    lineEditPrevoyanceRenteConjointDuree = new QLineEdit( TabPage_2, "lineEditPrevoyanceRenteConjointDuree" );
    lineEditPrevoyanceRenteConjointDuree->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditPrevoyanceRenteConjointDuree->sizePolicy().hasHeightForWidth() ) );
    lineEditPrevoyanceRenteConjointDuree->setMaximumSize( QSize( 30, 32767 ) );

    TabPageLayout_2->addMultiCellWidget( lineEditPrevoyanceRenteConjointDuree, 3, 3, 6, 7 );

    comboBoxPrevoyanceDecesCompagnieConjoint = new QComboBox( FALSE, TabPage_2, "comboBoxPrevoyanceDecesCompagnieConjoint" );

    TabPageLayout_2->addMultiCellWidget( comboBoxPrevoyanceDecesCompagnieConjoint, 4, 4, 4, 5 );

    labelPeevoyanceDecesRenteDuree = new QLabel( TabPage_2, "labelPeevoyanceDecesRenteDuree" );

    TabPageLayout_2->addWidget( labelPeevoyanceDecesRenteDuree, 3, 5 );
    spacer40 = new QSpacerItem( 120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    TabPageLayout_2->addMultiCell( spacer40, 3, 3, 3, 4 );

    dateEditPrevoyanceDecesRenteEducationDateEffet = new QDateEdit( TabPage_2, "dateEditPrevoyanceDecesRenteEducationDateEffet" );

    TabPageLayout_2->addMultiCellWidget( dateEditPrevoyanceDecesRenteEducationDateEffet, 8, 8, 9, 10 );

    labelPrevoyanceDecesRenteEducationDateEffet = new QLabel( TabPage_2, "labelPrevoyanceDecesRenteEducationDateEffet" );

    TabPageLayout_2->addMultiCellWidget( labelPrevoyanceDecesRenteEducationDateEffet, 8, 8, 7, 8 );

    layout49 = new QVBoxLayout( 0, 0, 6, "layout49"); 

    pushButtonPrevoyanceRenteEducationPlus = new QPushButton( TabPage_2, "pushButtonPrevoyanceRenteEducationPlus" );
    pushButtonPrevoyanceRenteEducationPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceRenteEducationPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceRenteEducationPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout49->addWidget( pushButtonPrevoyanceRenteEducationPlus );

    pushButtonPrevoyanceRenteEducationMinus = new QPushButton( TabPage_2, "pushButtonPrevoyanceRenteEducationMinus" );
    pushButtonPrevoyanceRenteEducationMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceRenteEducationMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceRenteEducationMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout49->addWidget( pushButtonPrevoyanceRenteEducationMinus );

    TabPageLayout_2->addMultiCellLayout( layout49, 6, 8, 0, 0 );

    labelPrevoyanceDecesRenteEducationFiscalite = new QLabel( TabPage_2, "labelPrevoyanceDecesRenteEducationFiscalite" );

    TabPageLayout_2->addMultiCellWidget( labelPrevoyanceDecesRenteEducationFiscalite, 6, 6, 7, 8 );

    labelPrevoyanceDecesRenteEducationCompagnie = new QLabel( TabPage_2, "labelPrevoyanceDecesRenteEducationCompagnie" );

    TabPageLayout_2->addMultiCellWidget( labelPrevoyanceDecesRenteEducationCompagnie, 7, 7, 7, 8 );

    listViewRenteEducation = new QListView( TabPage_2, "listViewRenteEducation" );
    listViewRenteEducation->addColumn( trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x64\x65\x20\x6c\x61\x20\x72\x65\x6e\x74\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewRenteEducation->addColumn( tr( "Pourcentage salaire (%)" ) );
    listViewRenteEducation->addColumn( trUtf8( "\x41\x67\x65\x20\x64\xc3\xa9\x62\x75\x74" ) );
    listViewRenteEducation->addColumn( tr( "Age fin" ) );
    listViewRenteEducation->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, listViewRenteEducation->sizePolicy().hasHeightForWidth() ) );

    TabPageLayout_2->addMultiCellWidget( listViewRenteEducation, 6, 8, 1, 6 );

    comboBoxPrevoyanceDecesRenteEducationFiscalite = new QComboBox( FALSE, TabPage_2, "comboBoxPrevoyanceDecesRenteEducationFiscalite" );

    TabPageLayout_2->addMultiCellWidget( comboBoxPrevoyanceDecesRenteEducationFiscalite, 6, 6, 9, 10 );

    comboBoxPrevoyanceDecesRenteEducationCompagnie = new QComboBox( FALSE, TabPage_2, "comboBoxPrevoyanceDecesRenteEducationCompagnie" );

    TabPageLayout_2->addMultiCellWidget( comboBoxPrevoyanceDecesRenteEducationCompagnie, 7, 7, 9, 10 );

    labelPrevoyanceDecesRenteConjoint = new QLabel( TabPage_2, "labelPrevoyanceDecesRenteConjoint" );
    labelPrevoyanceDecesRenteConjoint->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, labelPrevoyanceDecesRenteConjoint->sizePolicy().hasHeightForWidth() ) );

    TabPageLayout_2->addMultiCellWidget( labelPrevoyanceDecesRenteConjoint, 2, 2, 0, 10 );
    tabWidget3->insertTab( TabPage_2, QString::fromLatin1("") );

    tab_4 = new QWidget( tabWidget3, "tab_4" );
    tabLayout_4 = new QVBoxLayout( tab_4, 11, 6, "tabLayout_4"); 

    labelPrevoyanceSanteFraixGeneraux = new QLabel( tab_4, "labelPrevoyanceSanteFraixGeneraux" );
    labelPrevoyanceSanteFraixGeneraux->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, labelPrevoyanceSanteFraixGeneraux->sizePolicy().hasHeightForWidth() ) );
    tabLayout_4->addWidget( labelPrevoyanceSanteFraixGeneraux );

    frame11 = new QFrame( tab_4, "frame11" );
    frame11->setFrameShape( QFrame::StyledPanel );
    frame11->setFrameShadow( QFrame::Raised );
    frame11Layout = new QGridLayout( frame11, 1, 1, 11, 6, "frame11Layout"); 

    labelPrevoyanceSanteCouvertureMensuelle = new QLabel( frame11, "labelPrevoyanceSanteCouvertureMensuelle" );

    frame11Layout->addWidget( labelPrevoyanceSanteCouvertureMensuelle, 0, 0 );

    labelPrevoyanceSanteCompagnieFraisGeneraux = new QLabel( frame11, "labelPrevoyanceSanteCompagnieFraisGeneraux" );

    frame11Layout->addWidget( labelPrevoyanceSanteCompagnieFraisGeneraux, 0, 3 );

    lineEditPrevoyanceSanteCouvertureMensuelle = new QLineEdit( frame11, "lineEditPrevoyanceSanteCouvertureMensuelle" );

    frame11Layout->addWidget( lineEditPrevoyanceSanteCouvertureMensuelle, 0, 1 );

    lineEditPrevoyanceSanteFranchise = new QLineEdit( frame11, "lineEditPrevoyanceSanteFranchise" );
    lineEditPrevoyanceSanteFranchise->setFrameShape( QLineEdit::LineEditPanel );
    lineEditPrevoyanceSanteFranchise->setFrameShadow( QLineEdit::Sunken );

    frame11Layout->addWidget( lineEditPrevoyanceSanteFranchise, 1, 1 );

    dateEditPrevoyanceSanteDureeFraisGeneraux = new QDateEdit( frame11, "dateEditPrevoyanceSanteDureeFraisGeneraux" );
    dateEditPrevoyanceSanteDureeFraisGeneraux->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditPrevoyanceSanteDureeFraisGeneraux->sizePolicy().hasHeightForWidth() ) );

    frame11Layout->addWidget( dateEditPrevoyanceSanteDureeFraisGeneraux, 2, 1 );
    spacer9 = new QSpacerItem( 20, 70, QSizePolicy::Minimum, QSizePolicy::Expanding );
    frame11Layout->addMultiCell( spacer9, 0, 2, 2, 2 );

    labelPrevoyanceSanteFranchise = new QLabel( frame11, "labelPrevoyanceSanteFranchise" );

    frame11Layout->addWidget( labelPrevoyanceSanteFranchise, 1, 0 );

    lineEditPrevoyanceSanteContratFraisGeneraux = new QLineEdit( frame11, "lineEditPrevoyanceSanteContratFraisGeneraux" );

    frame11Layout->addWidget( lineEditPrevoyanceSanteContratFraisGeneraux, 2, 4 );

    labelPrevoyanceSanteContratFraisGeneraux = new QLabel( frame11, "labelPrevoyanceSanteContratFraisGeneraux" );

    frame11Layout->addWidget( labelPrevoyanceSanteContratFraisGeneraux, 2, 3 );

    labelPrevoyanceSanteDureeFraisGeneraux = new QLabel( frame11, "labelPrevoyanceSanteDureeFraisGeneraux" );

    frame11Layout->addWidget( labelPrevoyanceSanteDureeFraisGeneraux, 2, 0 );

    comboBoxPrevoyanceSanteCompagnieFraisGeneraux = new QComboBox( FALSE, frame11, "comboBoxPrevoyanceSanteCompagnieFraisGeneraux" );

    frame11Layout->addWidget( comboBoxPrevoyanceSanteCompagnieFraisGeneraux, 0, 4 );
    tabLayout_4->addWidget( frame11 );

    layout50 = new QHBoxLayout( 0, 0, 6, "layout50"); 

    textLabel31 = new QLabel( tab_4, "textLabel31" );
    textLabel31->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel31->sizePolicy().hasHeightForWidth() ) );
    textLabel31->setMaximumSize( QSize( 32767, 30 ) );
    layout50->addWidget( textLabel31 );

    pushButtonPrevoyanceEmpruntPlus = new QPushButton( tab_4, "pushButtonPrevoyanceEmpruntPlus" );
    pushButtonPrevoyanceEmpruntPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceEmpruntPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceEmpruntPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout50->addWidget( pushButtonPrevoyanceEmpruntPlus );

    pushButtonPrevoyanceEmpruntMinus = new QPushButton( tab_4, "pushButtonPrevoyanceEmpruntMinus" );
    pushButtonPrevoyanceEmpruntMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonPrevoyanceEmpruntMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonPrevoyanceEmpruntMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout50->addWidget( pushButtonPrevoyanceEmpruntMinus );
    tabLayout_4->addLayout( layout50 );

    listViewEmprunt = new QListView( tab_4, "listViewEmprunt" );
    listViewEmprunt->addColumn( tr( "Montant emprunt" ) );
    listViewEmprunt->addColumn( tr( "Franchise" ) );
    listViewEmprunt->addColumn( tr( "Banque" ) );
    listViewEmprunt->addColumn( trUtf8( "\x44\x61\x74\x65\x20\x64\xc3\xa9\x62\x75\x74" ) );
    listViewEmprunt->addColumn( tr( "Terme" ) );
    listViewEmprunt->addColumn( tr( "Taux moyen (%)" ) );
    listViewEmprunt->addColumn( tr( "Type emprunt" ) );
    tabLayout_4->addWidget( listViewEmprunt );

    layout71 = new QHBoxLayout( 0, 0, 6, "layout71"); 

    textLabel1_8 = new QLabel( tab_4, "textLabel1_8" );
    layout71->addWidget( textLabel1_8 );

    textEditPrevoyanceElpruntNotes = new QTextEdit( tab_4, "textEditPrevoyanceElpruntNotes" );
    layout71->addWidget( textEditPrevoyanceElpruntNotes );
    tabLayout_4->addLayout( layout71 );
    tabWidget3->insertTab( tab_4, QString::fromLatin1("") );
    WStackPageLayout_5->addWidget( tabWidget3 );
    widgetStackAjouter->addWidget( WStackPage_5, 3 );

    WStackPage_6 = new QWidget( widgetStackAjouter, "WStackPage_6" );
    WStackPageLayout_6 = new QVBoxLayout( WStackPage_6, 11, 6, "WStackPageLayout_6"); 

    tabWidgetEpargne = new QTabWidget( WStackPage_6, "tabWidgetEpargne" );

    tab_5 = new QWidget( tabWidgetEpargne, "tab_5" );
    tabLayout_5 = new QGridLayout( tab_5, 1, 1, 11, 6, "tabLayout_5"); 

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    textLabelEpargne = new QLabel( tab_5, "textLabelEpargne" );
    layout35->addWidget( textLabelEpargne );

    pushButtonEpargneCapitalisationPlus = new QPushButton( tab_5, "pushButtonEpargneCapitalisationPlus" );
    pushButtonEpargneCapitalisationPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneCapitalisationPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneCapitalisationPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout35->addWidget( pushButtonEpargneCapitalisationPlus );

    pushButtonEpargneCapitalisationMinus = new QPushButton( tab_5, "pushButtonEpargneCapitalisationMinus" );
    pushButtonEpargneCapitalisationMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneCapitalisationMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneCapitalisationMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout35->addWidget( pushButtonEpargneCapitalisationMinus );

    tabLayout_5->addMultiCellLayout( layout35, 0, 0, 0, 9 );

    listViewEpargne = new QListView( tab_5, "listViewEpargne" );
    listViewEpargne->addColumn( tr( "Type" ) );
    listViewEpargne->addColumn( tr( "Date effet" ) );
    listViewEpargne->addColumn( trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    listViewEpargne->addColumn( trUtf8( "\x45\x70\x61\x72\x67\x6e\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewEpargne->addColumn( tr( "A la date du" ) );
    listViewEpargne->addColumn( tr( "Contrat" ) );
    listViewEpargne->addColumn( tr( "Compagnie" ) );

    tabLayout_5->addMultiCellWidget( listViewEpargne, 1, 1, 0, 9 );

    layout35_2 = new QHBoxLayout( 0, 0, 6, "layout35_2"); 

    textLabelEpargne_2 = new QLabel( tab_5, "textLabelEpargne_2" );
    layout35_2->addWidget( textLabelEpargne_2 );

    pushButtonEpargneAssurancePlus = new QPushButton( tab_5, "pushButtonEpargneAssurancePlus" );
    pushButtonEpargneAssurancePlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneAssurancePlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneAssurancePlus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2->addWidget( pushButtonEpargneAssurancePlus );

    pushButtonEpargneAssuranceMinus = new QPushButton( tab_5, "pushButtonEpargneAssuranceMinus" );
    pushButtonEpargneAssuranceMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneAssuranceMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneAssuranceMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2->addWidget( pushButtonEpargneAssuranceMinus );

    tabLayout_5->addMultiCellLayout( layout35_2, 2, 2, 0, 9 );

    listViewAssuranceVie = new QListView( tab_5, "listViewAssuranceVie" );
    listViewAssuranceVie->addColumn( tr( "Contrat" ) );
    listViewAssuranceVie->addColumn( tr( "Compagnie" ) );
    listViewAssuranceVie->addColumn( tr( "Date d'effet" ) );
    listViewAssuranceVie->addColumn( trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    listViewAssuranceVie->addColumn( tr( "Terme" ) );
    listViewAssuranceVie->addColumn( trUtf8( "\x4b\x20\x63\x6f\x6e\x73\x74\x69\x74\x75\xc3\xa9" ) );
    listViewAssuranceVie->addColumn( tr( "A la date" ) );
    listViewAssuranceVie->addColumn( tr( "DSK" ) );
    listViewAssuranceVie->addColumn( tr( "PEP" ) );
    listViewAssuranceVie->addColumn( tr( "MS" ) );
    listViewAssuranceVie->addColumn( trUtf8( "\x46\x64\x20\x28\xe2\x82\xac\x29" ) );

    tabLayout_5->addMultiCellWidget( listViewAssuranceVie, 3, 3, 0, 9 );

    textLabel14 = new QLabel( tab_5, "textLabel14" );

    tabLayout_5->addWidget( textLabel14, 5, 9 );
    spacer14 = new QSpacerItem( 90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout_5->addMultiCell( spacer14, 5, 5, 0, 1 );

    textLabel13 = new QLabel( tab_5, "textLabel13" );

    tabLayout_5->addMultiCellWidget( textLabel13, 5, 5, 2, 5 );
    spacer13 = new QSpacerItem( 340, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout_5->addMultiCell( spacer13, 5, 5, 6, 8 );

    textLabel12 = new QLabel( tab_5, "textLabel12" );

    tabLayout_5->addMultiCellWidget( textLabel12, 4, 4, 0, 2 );

    textLabelSensibilie = new QLabel( tab_5, "textLabelSensibilie" );

    tabLayout_5->addWidget( textLabelSensibilie, 4, 3 );

    sliderEpargneSensibilite = new QSlider( tab_5, "sliderEpargneSensibilite" );
    sliderEpargneSensibilite->setLineStep( 10 );
    sliderEpargneSensibilite->setPageStep( 100 );
    sliderEpargneSensibilite->setOrientation( QSlider::Horizontal );

    tabLayout_5->addMultiCellWidget( sliderEpargneSensibilite, 4, 4, 4, 9 );

    textLabel15 = new QLabel( tab_5, "textLabel15" );

    tabLayout_5->addWidget( textLabel15, 6, 0 );

    comboBoxMotivation = new QComboBox( FALSE, tab_5, "comboBoxMotivation" );

    tabLayout_5->addMultiCellWidget( comboBoxMotivation, 6, 6, 1, 4 );

    comboBoxMotivation_2 = new QComboBox( FALSE, tab_5, "comboBoxMotivation_2" );

    tabLayout_5->addMultiCellWidget( comboBoxMotivation_2, 6, 6, 5, 6 );

    comboBoxMotivation_3 = new QComboBox( FALSE, tab_5, "comboBoxMotivation_3" );

    tabLayout_5->addWidget( comboBoxMotivation_3, 6, 7 );

    comboBoxMotivation_4 = new QComboBox( FALSE, tab_5, "comboBoxMotivation_4" );

    tabLayout_5->addMultiCellWidget( comboBoxMotivation_4, 6, 6, 8, 9 );
    tabWidgetEpargne->insertTab( tab_5, QString::fromLatin1("") );

    tab_6 = new QWidget( tabWidgetEpargne, "tab_6" );
    tabLayout_6 = new QVBoxLayout( tab_6, 11, 6, "tabLayout_6"); 

    layout35_2_2 = new QHBoxLayout( 0, 0, 6, "layout35_2_2"); 

    textLabelEpargne_2_2 = new QLabel( tab_6, "textLabelEpargne_2_2" );
    layout35_2_2->addWidget( textLabelEpargne_2_2 );

    pushButtonEpargneComptePlus = new QPushButton( tab_6, "pushButtonEpargneComptePlus" );
    pushButtonEpargneComptePlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneComptePlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneComptePlus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2_2->addWidget( pushButtonEpargneComptePlus );

    pushButtonEpargneCompteMinus = new QPushButton( tab_6, "pushButtonEpargneCompteMinus" );
    pushButtonEpargneCompteMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneCompteMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneCompteMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2_2->addWidget( pushButtonEpargneCompteMinus );
    tabLayout_6->addLayout( layout35_2_2 );

    listViewComptes = new QListView( tab_6, "listViewComptes" );
    listViewComptes->addColumn( tr( "Type" ) );
    listViewComptes->addColumn( tr( "Compagnie" ) );
    listViewComptes->addColumn( tr( "Date d'effet" ) );
    listViewComptes->addColumn( trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    listViewComptes->addColumn( tr( "Terme" ) );
    listViewComptes->addColumn( trUtf8( "\x4b\x20\x28\xe2\x82\xac\x29" ) );
    listViewComptes->addColumn( tr( "A la date" ) );
    listViewComptes->addColumn( tr( "Rendement N - 1 (%)" ) );
    listViewComptes->addColumn( tr( "Commentaires" ) );
    tabLayout_6->addWidget( listViewComptes );

    layout35_2_2_2 = new QHBoxLayout( 0, 0, 6, "layout35_2_2_2"); 

    textLabelEpargne_2_2_2 = new QLabel( tab_6, "textLabelEpargne_2_2_2" );
    layout35_2_2_2->addWidget( textLabelEpargne_2_2_2 );

    pushButtonEpargneRevenusPlus = new QPushButton( tab_6, "pushButtonEpargneRevenusPlus" );
    pushButtonEpargneRevenusPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneRevenusPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneRevenusPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2_2_2->addWidget( pushButtonEpargneRevenusPlus );

    pushButtonEpargneRevenusMinus = new QPushButton( tab_6, "pushButtonEpargneRevenusMinus" );
    pushButtonEpargneRevenusMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneRevenusMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneRevenusMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2_2_2->addWidget( pushButtonEpargneRevenusMinus );
    tabLayout_6->addLayout( layout35_2_2_2 );

    listViewRevenus = new QListView( tab_6, "listViewRevenus" );
    listViewRevenus->addColumn( trUtf8( "\x44\xc3\xa9\x73\x69\x67\x6e\x61\x74\x69\x6f\x6e" ) );
    listViewRevenus->addColumn( trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    tabLayout_6->addWidget( listViewRevenus );

    layout35_2_2_2_2 = new QHBoxLayout( 0, 0, 6, "layout35_2_2_2_2"); 

    textLabelEpargne_2_2_2_2 = new QLabel( tab_6, "textLabelEpargne_2_2_2_2" );
    layout35_2_2_2_2->addWidget( textLabelEpargne_2_2_2_2 );

    pushButtonEpargneChargesPlus = new QPushButton( tab_6, "pushButtonEpargneChargesPlus" );
    pushButtonEpargneChargesPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneChargesPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneChargesPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2_2_2_2->addWidget( pushButtonEpargneChargesPlus );

    pushButtonEpargneChargesMinus = new QPushButton( tab_6, "pushButtonEpargneChargesMinus" );
    pushButtonEpargneChargesMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEpargneChargesMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEpargneChargesMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout35_2_2_2_2->addWidget( pushButtonEpargneChargesMinus );
    tabLayout_6->addLayout( layout35_2_2_2_2 );

    listViewCharges = new QListView( tab_6, "listViewCharges" );
    listViewCharges->addColumn( trUtf8( "\x44\xc3\xa9\x73\x69\x67\x6e\x61\x74\x69\x6f\x6e" ) );
    listViewCharges->addColumn( trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    tabLayout_6->addWidget( listViewCharges );

    textLabel17_2 = new QLabel( tab_6, "textLabel17_2" );
    tabLayout_6->addWidget( textLabel17_2 );

    textLabel17 = new QLabel( tab_6, "textLabel17" );
    tabLayout_6->addWidget( textLabel17 );

    textLabel17_2_2 = new QLabel( tab_6, "textLabel17_2_2" );
    tabLayout_6->addWidget( textLabel17_2_2 );
    tabWidgetEpargne->insertTab( tab_6, QString::fromLatin1("") );
    WStackPageLayout_6->addWidget( tabWidgetEpargne );
    widgetStackAjouter->addWidget( WStackPage_6, 4 );

    WStackPage_7 = new QWidget( widgetStackAjouter, "WStackPage_7" );

    textLabel18 = new QLabel( WStackPage_7, "textLabel18" );
    textLabel18->setGeometry( QRect( 210, 41, 123, 29 ) );
    widgetStackAjouter->addWidget( WStackPage_7, 5 );

    WStackPage_8 = new QWidget( widgetStackAjouter, "WStackPage_8" );
    WStackPageLayout_7 = new QVBoxLayout( WStackPage_8, 11, 6, "WStackPageLayout_7"); 

    textLabel7 = new QLabel( WStackPage_8, "textLabel7" );
    textLabel7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel7->sizePolicy().hasHeightForWidth() ) );
    WStackPageLayout_7->addWidget( textLabel7 );

    layout72 = new QGridLayout( 0, 1, 1, 0, 6, "layout72"); 

    lineEditBesoinPrevoyance = new QLineEdit( WStackPage_8, "lineEditBesoinPrevoyance" );

    layout72->addWidget( lineEditBesoinPrevoyance, 1, 2 );

    lineEditBesoinPatrimoine = new QLineEdit( WStackPage_8, "lineEditBesoinPatrimoine" );

    layout72->addWidget( lineEditBesoinPatrimoine, 4, 2 );

    textLabel8 = new QLabel( WStackPage_8, "textLabel8" );

    layout72->addWidget( textLabel8, 0, 0 );

    textLabel12_2 = new QLabel( WStackPage_8, "textLabel12_2" );

    layout72->addWidget( textLabel12_2, 4, 0 );

    lineEditBesoinsRetraite = new QLineEdit( WStackPage_8, "lineEditBesoinsRetraite" );

    layout72->addWidget( lineEditBesoinsRetraite, 0, 2 );
    spacer28_2 = new QSpacerItem( 20, 151, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout72->addMultiCell( spacer28_2, 0, 4, 1, 1 );

    textLabel11 = new QLabel( WStackPage_8, "textLabel11" );

    layout72->addWidget( textLabel11, 3, 0 );

    lineEditBesoinSante = new QLineEdit( WStackPage_8, "lineEditBesoinSante" );

    layout72->addWidget( lineEditBesoinSante, 2, 2 );

    textLabel10 = new QLabel( WStackPage_8, "textLabel10" );

    layout72->addWidget( textLabel10, 2, 0 );

    textLabel9 = new QLabel( WStackPage_8, "textLabel9" );

    layout72->addWidget( textLabel9, 1, 0 );

    lineEditBesoinEpargne = new QLineEdit( WStackPage_8, "lineEditBesoinEpargne" );

    layout72->addWidget( lineEditBesoinEpargne, 3, 2 );
    WStackPageLayout_7->addLayout( layout72 );

    textLabel13_2 = new QLabel( WStackPage_8, "textLabel13_2" );
    WStackPageLayout_7->addWidget( textLabel13_2 );

    textEditBesoinNotes = new QTextEdit( WStackPage_8, "textEditBesoinNotes" );
    WStackPageLayout_7->addWidget( textEditBesoinNotes );
    spacer29 = new QSpacerItem( 20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding );
    WStackPageLayout_7->addItem( spacer29 );
    widgetStackAjouter->addWidget( WStackPage_8, 6 );
    WStackPageLayout->addWidget( widgetStackAjouter );
    widgetStackMain->addWidget( WStackPage, 0 );

    WStackPage_9 = new QWidget( widgetStackMain, "WStackPage_9" );
    WStackPageLayout_8 = new QVBoxLayout( WStackPage_9, 11, 6, "WStackPageLayout_8"); 

    frameRechercher = new QFrame( WStackPage_9, "frameRechercher" );
    frameRechercher->setFrameShape( QFrame::StyledPanel );
    frameRechercher->setFrameShadow( QFrame::Raised );
    frameRechercherLayout = new QGridLayout( frameRechercher, 1, 1, 11, 6, "frameRechercherLayout"); 

    textLabelListerFiltreNom = new QLabel( frameRechercher, "textLabelListerFiltreNom" );
    textLabelListerFiltreNom->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabelListerFiltreNom->sizePolicy().hasHeightForWidth() ) );

    frameRechercherLayout->addWidget( textLabelListerFiltreNom, 0, 0 );

    lineEditListerFiltreNom = new QLineEdit( frameRechercher, "lineEditListerFiltreNom" );
    lineEditListerFiltreNom->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditListerFiltreNom->sizePolicy().hasHeightForWidth() ) );

    frameRechercherLayout->addWidget( lineEditListerFiltreNom, 0, 1 );

    comboBoxSearchProspect = new QComboBox( FALSE, frameRechercher, "comboBoxSearchProspect" );

    frameRechercherLayout->addMultiCellWidget( comboBoxSearchProspect, 0, 0, 5, 7 );

    lineEditListerFiltrePrenom = new QLineEdit( frameRechercher, "lineEditListerFiltrePrenom" );
    lineEditListerFiltrePrenom->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditListerFiltrePrenom->sizePolicy().hasHeightForWidth() ) );

    frameRechercherLayout->addMultiCellWidget( lineEditListerFiltrePrenom, 0, 0, 3, 4 );

    textLabelListerFiltrePrenom = new QLabel( frameRechercher, "textLabelListerFiltrePrenom" );
    textLabelListerFiltrePrenom->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabelListerFiltrePrenom->sizePolicy().hasHeightForWidth() ) );

    frameRechercherLayout->addWidget( textLabelListerFiltrePrenom, 0, 2 );
    spacer41 = new QSpacerItem( 80, 20, QSizePolicy::Preferred, QSizePolicy::Minimum );
    frameRechercherLayout->addMultiCell( spacer41, 0, 0, 8, 9 );

    pushButtonPersonneFiltreEffacer = new QPushButton( frameRechercher, "pushButtonPersonneFiltreEffacer" );

    frameRechercherLayout->addWidget( pushButtonPersonneFiltreEffacer, 0, 10 );

    comboBoxSearchFunction = new QComboBox( FALSE, frameRechercher, "comboBoxSearchFunction" );

    frameRechercherLayout->addMultiCellWidget( comboBoxSearchFunction, 1, 1, 0, 1 );

    comboBoxSearchOp1 = new QComboBox( FALSE, frameRechercher, "comboBoxSearchOp1" );
    comboBoxSearchOp1->setEnabled( FALSE );

    frameRechercherLayout->addWidget( comboBoxSearchOp1, 1, 3 );

    textLabelSearch1 = new QLabel( frameRechercher, "textLabelSearch1" );

    frameRechercherLayout->addWidget( textLabelSearch1, 1, 2 );

    lineEditSearchValue1 = new QLineEdit( frameRechercher, "lineEditSearchValue1" );
    lineEditSearchValue1->setEnabled( FALSE );

    frameRechercherLayout->addMultiCellWidget( lineEditSearchValue1, 1, 1, 4, 5 );

    lineEditSearchValue2 = new QLineEdit( frameRechercher, "lineEditSearchValue2" );
    lineEditSearchValue2->setEnabled( FALSE );

    frameRechercherLayout->addWidget( lineEditSearchValue2, 1, 8 );

    textLabelSearch2 = new QLabel( frameRechercher, "textLabelSearch2" );

    frameRechercherLayout->addWidget( textLabelSearch2, 1, 6 );

    comboBoxSearchOp2 = new QComboBox( FALSE, frameRechercher, "comboBoxSearchOp2" );
    comboBoxSearchOp2->setEnabled( FALSE );

    frameRechercherLayout->addWidget( comboBoxSearchOp2, 1, 7 );
    spacer40_2 = new QSpacerItem( 171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    frameRechercherLayout->addMultiCell( spacer40_2, 1, 1, 9, 10 );
    WStackPageLayout_8->addWidget( frameRechercher );

    listView = new QListView( WStackPage_9, "listView" );
    listView->addColumn( tr( "Nom" ) );
    listView->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listView->addColumn( trUtf8( "\x54\xc3\xa9\x6c\xc3\xa9\x70\x68\x6f\x6e\x65" ) );
    listView->addColumn( tr( "Email" ) );
    listView->addColumn( tr( "Id" ) );
    WStackPageLayout_8->addWidget( listView );
    widgetStackMain->addWidget( WStackPage_9, 1 );

    WStackPage_10 = new QWidget( widgetStackMain, "WStackPage_10" );
    WStackPageLayout_9 = new QHBoxLayout( WStackPage_10, 11, 6, "WStackPageLayout_9"); 

    layout168 = new QVBoxLayout( 0, 0, 6, "layout168"); 

    pushButtonDossierEntreprise = new QPushButton( WStackPage_10, "pushButtonDossierEntreprise" );
    pushButtonDossierEntreprise->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonDossierEntreprise->sizePolicy().hasHeightForWidth() ) );
    layout168->addWidget( pushButtonDossierEntreprise );

    pushButtonParticipants = new QPushButton( WStackPage_10, "pushButtonParticipants" );
    pushButtonParticipants->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonParticipants->sizePolicy().hasHeightForWidth() ) );
    layout168->addWidget( pushButtonParticipants );

    pushButtonTNS = new QPushButton( WStackPage_10, "pushButtonTNS" );
    pushButtonTNS->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonTNS->sizePolicy().hasHeightForWidth() ) );
    layout168->addWidget( pushButtonTNS );
    spacer47 = new QSpacerItem( 21, 331, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout168->addItem( spacer47 );
    WStackPageLayout_9->addLayout( layout168 );

    widgetStackEntreprise = new QWidgetStack( WStackPage_10, "widgetStackEntreprise" );

    WStackPage_11 = new QWidget( widgetStackEntreprise, "WStackPage_11" );
    WStackPageLayout_10 = new QGridLayout( WStackPage_11, 1, 1, 11, 6, "WStackPageLayout_10"); 

    tabWidgetEntreprise = new QTabWidget( WStackPage_11, "tabWidgetEntreprise" );

    tab_7 = new QWidget( tabWidgetEntreprise, "tab_7" );
    tabLayout_7 = new QGridLayout( tab_7, 1, 1, 11, 6, "tabLayout_7"); 

    layout45_2 = new QHBoxLayout( 0, 0, 6, "layout45_2"); 

    textLabel1_2 = new QLabel( tab_7, "textLabel1_2" );
    layout45_2->addWidget( textLabel1_2 );

    lineEditRaisonSociale = new QLineEdit( tab_7, "lineEditRaisonSociale" );
    layout45_2->addWidget( lineEditRaisonSociale );

    tabLayout_7->addMultiCellLayout( layout45_2, 0, 0, 0, 5 );

    layout48_2 = new QHBoxLayout( 0, 0, 6, "layout48_2"); 

    textLabel6_2 = new QLabel( tab_7, "textLabel6_2" );
    layout48_2->addWidget( textLabel6_2 );

    lineEditCodeNaf = new QLineEdit( tab_7, "lineEditCodeNaf" );
    lineEditCodeNaf->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditCodeNaf->sizePolicy().hasHeightForWidth() ) );
    layout48_2->addWidget( lineEditCodeNaf );

    textLabel7_2 = new QLabel( tab_7, "textLabel7_2" );
    layout48_2->addWidget( textLabel7_2 );

    lineEditNumSiret = new QLineEdit( tab_7, "lineEditNumSiret" );
    lineEditNumSiret->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lineEditNumSiret->sizePolicy().hasHeightForWidth() ) );
    layout48_2->addWidget( lineEditNumSiret );

    tabLayout_7->addMultiCellLayout( layout48_2, 3, 3, 0, 9 );

    layout50_3 = new QHBoxLayout( 0, 0, 6, "layout50_3"); 

    textLabel8_2 = new QLabel( tab_7, "textLabel8_2" );
    layout50_3->addWidget( textLabel8_2 );

    lineEditActivite = new QLineEdit( tab_7, "lineEditActivite" );
    layout50_3->addWidget( lineEditActivite );

    textLabel9_2 = new QLabel( tab_7, "textLabel9_2" );
    layout50_3->addWidget( textLabel9_2 );

    lineEditConventionCollective = new QLineEdit( tab_7, "lineEditConventionCollective" );
    layout50_3->addWidget( lineEditConventionCollective );

    tabLayout_7->addMultiCellLayout( layout50_3, 4, 4, 0, 9 );

    textLabel15_2_2 = new QLabel( tab_7, "textLabel15_2_2" );
    textLabel15_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel15_2_2->sizePolicy().hasHeightForWidth() ) );
    textLabel15_2_2->setMaximumSize( QSize( 32000, 20 ) );

    tabLayout_7->addMultiCellWidget( textLabel15_2_2, 6, 6, 0, 9 );

    layout52_2 = new QHBoxLayout( 0, 0, 6, "layout52_2"); 

    textLabel12_2_2 = new QLabel( tab_7, "textLabel12_2_2" );
    layout52_2->addWidget( textLabel12_2_2 );

    lineEditColGer = new QLineEdit( tab_7, "lineEditColGer" );
    lineEditColGer->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditColGer->sizePolicy().hasHeightForWidth() ) );
    lineEditColGer->setMaximumSize( QSize( 20, 32767 ) );
    layout52_2->addWidget( lineEditColGer );

    textLabel13_2_2 = new QLabel( tab_7, "textLabel13_2_2" );
    layout52_2->addWidget( textLabel13_2_2 );

    lineEditProche = new QLineEdit( tab_7, "lineEditProche" );
    lineEditProche->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditProche->sizePolicy().hasHeightForWidth() ) );
    lineEditProche->setMaximumSize( QSize( 20, 32767 ) );
    layout52_2->addWidget( lineEditProche );

    textLabel14_2_2 = new QLabel( tab_7, "textLabel14_2_2" );
    layout52_2->addWidget( textLabel14_2_2 );

    lineEditAutre = new QLineEdit( tab_7, "lineEditAutre" );
    lineEditAutre->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditAutre->sizePolicy().hasHeightForWidth() ) );
    lineEditAutre->setMaximumSize( QSize( 20, 32767 ) );
    layout52_2->addWidget( lineEditAutre );

    tabLayout_7->addMultiCellLayout( layout52_2, 7, 7, 0, 9 );

    layout65_2_2 = new QHBoxLayout( 0, 0, 6, "layout65_2_2"); 

    textLabel16_2 = new QLabel( tab_7, "textLabel16_2" );
    layout65_2_2->addWidget( textLabel16_2 );

    layout53_2 = new QHBoxLayout( 0, 0, 6, "layout53_2"); 

    textLabel17_3_3 = new QLabel( tab_7, "textLabel17_3_3" );
    textLabel17_3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel17_3_3->sizePolicy().hasHeightForWidth() ) );
    layout53_2->addWidget( textLabel17_3_3 );

    lineEditBenefN1 = new QLineEdit( tab_7, "lineEditBenefN1" );
    lineEditBenefN1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditBenefN1->sizePolicy().hasHeightForWidth() ) );
    layout53_2->addWidget( lineEditBenefN1 );

    textLabel17_3_2_2 = new QLabel( tab_7, "textLabel17_3_2_2" );
    layout53_2->addWidget( textLabel17_3_2_2 );

    lineEditBenefN2 = new QLineEdit( tab_7, "lineEditBenefN2" );
    lineEditBenefN2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditBenefN2->sizePolicy().hasHeightForWidth() ) );
    layout53_2->addWidget( lineEditBenefN2 );
    layout65_2_2->addLayout( layout53_2 );

    tabLayout_7->addMultiCellLayout( layout65_2_2, 8, 8, 0, 9 );

    layout66_2 = new QHBoxLayout( 0, 0, 6, "layout66_2"); 

    textLabel18_2_2 = new QLabel( tab_7, "textLabel18_2_2" );
    layout66_2->addWidget( textLabel18_2_2 );

    comboBoxRegimeFiscal = new QComboBox( FALSE, tab_7, "comboBoxRegimeFiscal" );
    layout66_2->addWidget( comboBoxRegimeFiscal );

    tabLayout_7->addMultiCellLayout( layout66_2, 9, 9, 0, 9 );

    layout44_2 = new QHBoxLayout( 0, 0, 6, "layout44_2"); 

    textLabel2_2 = new QLabel( tab_7, "textLabel2_2" );
    layout44_2->addWidget( textLabel2_2 );

    comboBoxFormeJuridique = new QComboBox( FALSE, tab_7, "comboBoxFormeJuridique" );
    layout44_2->addWidget( comboBoxFormeJuridique );

    textLabel3_2_2 = new QLabel( tab_7, "textLabel3_2_2" );
    layout44_2->addWidget( textLabel3_2_2 );

    lineEditAutreFormeJuridique = new QLineEdit( tab_7, "lineEditAutreFormeJuridique" );
    layout44_2->addWidget( lineEditAutreFormeJuridique );

    tabLayout_7->addMultiCellLayout( layout44_2, 1, 1, 0, 5 );
    spacer133 = new QSpacerItem( 20, 51, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_7->addMultiCell( spacer133, 0, 1, 6, 6 );

    textLabel1_9 = new QLabel( tab_7, "textLabel1_9" );

    tabLayout_7->addMultiCellWidget( textLabel1_9, 0, 0, 7, 8 );

    lineEditDateCreation = new QLineEdit( tab_7, "lineEditDateCreation" );

    tabLayout_7->addWidget( lineEditDateCreation, 0, 9 );

    comboBoxSuiteEco = new QComboBox( FALSE, tab_7, "comboBoxSuiteEco" );

    tabLayout_7->addWidget( comboBoxSuiteEco, 1, 9 );

    textLabel2_6 = new QLabel( tab_7, "textLabel2_6" );

    tabLayout_7->addMultiCellWidget( textLabel2_6, 1, 1, 7, 8 );

    checkBoxAGA = new QCheckBox( tab_7, "checkBoxAGA" );

    tabLayout_7->addWidget( checkBoxAGA, 5, 0 );

    checkBoxCGA = new QCheckBox( tab_7, "checkBoxCGA" );

    tabLayout_7->addWidget( checkBoxCGA, 5, 1 );

    layout47_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout47_2"); 

    textLabelEtatCivilRue_2_2 = new QLabel( tab_7, "textLabelEtatCivilRue_2_2" );

    layout47_2->addWidget( textLabelEtatCivilRue_2_2, 0, 2 );
    spacer15_2 = new QSpacerItem( 20, 71, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout47_2->addMultiCell( spacer15_2, 0, 2, 1, 1 );

    lineEditEntrepriseComplement = new QLineEdit( tab_7, "lineEditEntrepriseComplement" );

    layout47_2->addMultiCellWidget( lineEditEntrepriseComplement, 1, 1, 3, 5 );

    textLabelEtatCivilAdresseComplement_2_2 = new QLabel( tab_7, "textLabelEtatCivilAdresseComplement_2_2" );

    layout47_2->addWidget( textLabelEtatCivilAdresseComplement_2_2, 1, 2 );

    textLabel5_2 = new QLabel( tab_7, "textLabel5_2" );

    layout47_2->addWidget( textLabel5_2, 2, 4 );

    textLabel4_2 = new QLabel( tab_7, "textLabel4_2" );

    layout47_2->addWidget( textLabel4_2, 0, 0 );

    lineEditEntrepriseNomRue = new QLineEdit( tab_7, "lineEditEntrepriseNomRue" );

    layout47_2->addMultiCellWidget( lineEditEntrepriseNomRue, 0, 0, 3, 5 );

    textLabelCodePostal_2_2 = new QLabel( tab_7, "textLabelCodePostal_2_2" );

    layout47_2->addWidget( textLabelCodePostal_2_2, 2, 2 );

    lineEditEntrepriseCodePostal = new QLineEdit( tab_7, "lineEditEntrepriseCodePostal" );
    lineEditEntrepriseCodePostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditEntrepriseCodePostal->sizePolicy().hasHeightForWidth() ) );
    lineEditEntrepriseCodePostal->setMaximumSize( QSize( 60, 32767 ) );

    layout47_2->addWidget( lineEditEntrepriseCodePostal, 2, 3 );

    lineEditEntrepriseVille = new QLineEdit( tab_7, "lineEditEntrepriseVille" );

    layout47_2->addWidget( lineEditEntrepriseVille, 2, 5 );

    tabLayout_7->addMultiCellLayout( layout47_2, 2, 2, 0, 9 );

    lineEditTelEnses = new QLineEdit( tab_7, "lineEditTelEnses" );

    tabLayout_7->addWidget( lineEditTelEnses, 5, 3 );

    textLabel3_4 = new QLabel( tab_7, "textLabel3_4" );

    tabLayout_7->addWidget( textLabel3_4, 5, 2 );

    lineEditFaxEntses = new QLineEdit( tab_7, "lineEditFaxEntses" );

    tabLayout_7->addMultiCellWidget( lineEditFaxEntses, 5, 5, 5, 7 );

    textLabel3_4_2 = new QLabel( tab_7, "textLabel3_4_2" );

    tabLayout_7->addWidget( textLabel3_4_2, 5, 4 );

    lineEdithttpentses = new QLineEdit( tab_7, "lineEdithttpentses" );

    tabLayout_7->addMultiCellWidget( lineEdithttpentses, 5, 5, 8, 9 );

    layout60 = new QHBoxLayout( 0, 0, 6, "layout60"); 

    textLabel20_2 = new QLabel( tab_7, "textLabel20_2" );
    textLabel20_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel20_2->sizePolicy().hasHeightForWidth() ) );
    layout60->addWidget( textLabel20_2 );

    lineEditNomGerant = new QLineEdit( tab_7, "lineEditNomGerant" );
    layout60->addWidget( lineEditNomGerant );

    textLabel7_3 = new QLabel( tab_7, "textLabel7_3" );
    layout60->addWidget( textLabel7_3 );

    lineEditPrenomGerant = new QLineEdit( tab_7, "lineEditPrenomGerant" );
    layout60->addWidget( lineEditPrenomGerant );

    textLabel8_3 = new QLabel( tab_7, "textLabel8_3" );
    layout60->addWidget( textLabel8_3 );

    dateEditNaissanceGerant = new QDateEdit( tab_7, "dateEditNaissanceGerant" );
    layout60->addWidget( dateEditNaissanceGerant );

    comboBoxPartsDirigeant = new QComboBox( FALSE, tab_7, "comboBoxPartsDirigeant" );
    layout60->addWidget( comboBoxPartsDirigeant );

    pushButtonDirigeantPlus = new QPushButton( tab_7, "pushButtonDirigeantPlus" );
    pushButtonDirigeantPlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 15, 0, pushButtonDirigeantPlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonDirigeantPlus->setMaximumSize( QSize( 20, 32767 ) );
    layout60->addWidget( pushButtonDirigeantPlus );

    pushButtontDirigeantMinus = new QPushButton( tab_7, "pushButtontDirigeantMinus" );
    pushButtontDirigeantMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 15, 0, pushButtontDirigeantMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtontDirigeantMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout60->addWidget( pushButtontDirigeantMinus );

    tabLayout_7->addMultiCellLayout( layout60, 11, 11, 0, 9 );

    listViewDirigeants = new QListView( tab_7, "listViewDirigeants" );
    listViewDirigeants->addColumn( tr( "Nom" ) );
    listViewDirigeants->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listViewDirigeants->addColumn( tr( "Date naissance" ) );
    listViewDirigeants->addColumn( tr( "Parts sociales" ) );
    listViewDirigeants->addColumn( tr( "Id" ) );

    tabLayout_7->addMultiCellWidget( listViewDirigeants, 12, 12, 0, 9 );

    textLabel19_2 = new QLabel( tab_7, "textLabel19_2" );
    textLabel19_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel19_2->sizePolicy().hasHeightForWidth() ) );

    tabLayout_7->addMultiCellWidget( textLabel19_2, 10, 10, 0, 9 );
    tabWidgetEntreprise->insertTab( tab_7, QString::fromLatin1("") );

    TabPage_3 = new QWidget( tabWidgetEntreprise, "TabPage_3" );
    TabPageLayout_3 = new QVBoxLayout( TabPage_3, 11, 6, "TabPageLayout_3"); 

    layout71_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout71_2"); 

    layout67_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout67_2"); 

    lineEditNbCadres = new QLineEdit( TabPage_3, "lineEditNbCadres" );
    lineEditNbCadres->setMaximumSize( QSize( 30, 32767 ) );

    layout67_2->addWidget( lineEditNbCadres, 0, 1 );

    lineEditNbNonCadres = new QLineEdit( TabPage_3, "lineEditNbNonCadres" );
    lineEditNbNonCadres->setMaximumSize( QSize( 30, 32767 ) );

    layout67_2->addWidget( lineEditNbNonCadres, 2, 1 );

    textLabel22_2_2 = new QLabel( TabPage_3, "textLabel22_2_2" );
    textLabel22_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel22_2_2->sizePolicy().hasHeightForWidth() ) );

    layout67_2->addWidget( textLabel22_2_2, 1, 0 );

    lineEditNbAutreColleges = new QLineEdit( TabPage_3, "lineEditNbAutreColleges" );
    lineEditNbAutreColleges->setMaximumSize( QSize( 30, 32767 ) );

    layout67_2->addWidget( lineEditNbAutreColleges, 3, 1 );

    lineEditNbETAM = new QLineEdit( TabPage_3, "lineEditNbETAM" );
    lineEditNbETAM->setMaximumSize( QSize( 30, 32767 ) );

    layout67_2->addWidget( lineEditNbETAM, 1, 1 );

    textLabel22_4_2 = new QLabel( TabPage_3, "textLabel22_4_2" );
    textLabel22_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel22_4_2->sizePolicy().hasHeightForWidth() ) );

    layout67_2->addWidget( textLabel22_4_2, 3, 0 );

    textLabel22_5 = new QLabel( TabPage_3, "textLabel22_5" );
    textLabel22_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel22_5->sizePolicy().hasHeightForWidth() ) );

    layout67_2->addWidget( textLabel22_5, 0, 0 );

    textLabel22_3_2 = new QLabel( TabPage_3, "textLabel22_3_2" );
    textLabel22_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel22_3_2->sizePolicy().hasHeightForWidth() ) );

    layout67_2->addWidget( textLabel22_3_2, 2, 0 );

    layout71_2->addLayout( layout67_2, 0, 0 );

    layout68_2_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout68_2_2"); 

    textLabel23_3_2 = new QLabel( TabPage_3, "textLabel23_3_2" );

    layout68_2_2->addWidget( textLabel23_3_2, 2, 0 );

    comboBoxDeleguePersonnel = new QComboBox( FALSE, TabPage_3, "comboBoxDeleguePersonnel" );
    comboBoxDeleguePersonnel->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBoxDeleguePersonnel->sizePolicy().hasHeightForWidth() ) );

    layout68_2_2->addWidget( comboBoxDeleguePersonnel, 0, 1 );

    textLabel23_4 = new QLabel( TabPage_3, "textLabel23_4" );

    layout68_2_2->addWidget( textLabel23_4, 0, 0 );

    lineEditInteressementMod = new QLineEdit( TabPage_3, "lineEditInteressementMod" );
    lineEditInteressementMod->setMinimumSize( QSize( 200, 0 ) );

    layout68_2_2->addWidget( lineEditInteressementMod, 2, 2 );

    comboBoxInteressement = new QComboBox( FALSE, TabPage_3, "comboBoxInteressement" );
    comboBoxInteressement->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBoxInteressement->sizePolicy().hasHeightForWidth() ) );

    layout68_2_2->addWidget( comboBoxInteressement, 2, 1 );

    comboBoxComiteEntreprise = new QComboBox( FALSE, TabPage_3, "comboBoxComiteEntreprise" );
    comboBoxComiteEntreprise->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBoxComiteEntreprise->sizePolicy().hasHeightForWidth() ) );

    layout68_2_2->addWidget( comboBoxComiteEntreprise, 1, 1 );

    textLabel23_2_2 = new QLabel( TabPage_3, "textLabel23_2_2" );

    layout68_2_2->addWidget( textLabel23_2_2, 1, 0 );

    layout71_2->addLayout( layout68_2_2, 0, 1 );
    TabPageLayout_3->addLayout( layout71_2 );

    textLabel25_2 = new QLabel( TabPage_3, "textLabel25_2" );
    textLabel25_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel25_2->sizePolicy().hasHeightForWidth() ) );
    TabPageLayout_3->addWidget( textLabel25_2 );

    layout73_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout73_2"); 

    lineEditARRCOPP = new QLineEdit( TabPage_3, "lineEditARRCOPP" );

    layout73_2->addWidget( lineEditARRCOPP, 1, 2 );

    lineEditARRCOPS = new QLineEdit( TabPage_3, "lineEditARRCOPS" );

    layout73_2->addWidget( lineEditARRCOPS, 1, 1 );

    textLabel26_2 = new QLabel( TabPage_3, "textLabel26_2" );
    textLabel26_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel26_2->sizePolicy().hasHeightForWidth() ) );

    layout73_2->addWidget( textLabel26_2, 1, 0 );

    textLabel29_2_2 = new QLabel( TabPage_3, "textLabel29_2_2" );

    layout73_2->addWidget( textLabel29_2_2, 0, 2 );

    lineEditAGIRCPP = new QLineEdit( TabPage_3, "lineEditAGIRCPP" );

    layout73_2->addWidget( lineEditAGIRCPP, 2, 2 );

    textLabel27_2 = new QLabel( TabPage_3, "textLabel27_2" );
    textLabel27_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel27_2->sizePolicy().hasHeightForWidth() ) );

    layout73_2->addMultiCellWidget( textLabel27_2, 2, 3, 0, 0 );

    lineEditAutrePS = new QLineEdit( TabPage_3, "lineEditAutrePS" );

    layout73_2->addWidget( lineEditAutrePS, 4, 1 );

    textLabel29_3 = new QLabel( TabPage_3, "textLabel29_3" );

    layout73_2->addWidget( textLabel29_3, 0, 1 );

    lineEditAGIRCPS = new QLineEdit( TabPage_3, "lineEditAGIRCPS" );

    layout73_2->addMultiCellWidget( lineEditAGIRCPS, 2, 3, 1, 1 );

    textLabel28_2 = new QLabel( TabPage_3, "textLabel28_2" );
    textLabel28_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel28_2->sizePolicy().hasHeightForWidth() ) );

    layout73_2->addWidget( textLabel28_2, 4, 0 );

    lineEditAutrePP = new QLineEdit( TabPage_3, "lineEditAutrePP" );

    layout73_2->addMultiCellWidget( lineEditAutrePP, 3, 4, 2, 2 );
    spacer18_3_2 = new QSpacerItem( 155, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout73_2->addItem( spacer18_3_2, 0, 0 );
    TabPageLayout_3->addLayout( layout73_2 );

    layout74_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout74_2"); 

    textLabel30_2_2 = new QLabel( TabPage_3, "textLabel30_2_2" );

    layout74_2->addWidget( textLabel30_2_2, 1, 0 );

    lineEditCaisseCongesPayes = new QLineEdit( TabPage_3, "lineEditCaisseCongesPayes" );
    lineEditCaisseCongesPayes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditCaisseCongesPayes->sizePolicy().hasHeightForWidth() ) );
    lineEditCaisseCongesPayes->setMaximumSize( QSize( 30, 32767 ) );

    layout74_2->addWidget( lineEditCaisseCongesPayes, 0, 1 );

    textLabel30_3_2 = new QLabel( TabPage_3, "textLabel30_3_2" );

    layout74_2->addWidget( textLabel30_3_2, 2, 0 );

    lineEditTauxAccidentTravail = new QLineEdit( TabPage_3, "lineEditTauxAccidentTravail" );
    lineEditTauxAccidentTravail->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditTauxAccidentTravail->sizePolicy().hasHeightForWidth() ) );
    lineEditTauxAccidentTravail->setMaximumSize( QSize( 30, 32767 ) );

    layout74_2->addWidget( lineEditTauxAccidentTravail, 1, 1 );

    textLabel30_4 = new QLabel( TabPage_3, "textLabel30_4" );

    layout74_2->addWidget( textLabel30_4, 0, 0 );

    lineEditTaxeTransport = new QLineEdit( TabPage_3, "lineEditTaxeTransport" );
    lineEditTaxeTransport->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEditTaxeTransport->sizePolicy().hasHeightForWidth() ) );
    lineEditTaxeTransport->setMaximumSize( QSize( 60, 32767 ) );

    layout74_2->addWidget( lineEditTaxeTransport, 2, 1 );
    TabPageLayout_3->addLayout( layout74_2 );
    spacer19_2 = new QSpacerItem( 61, 111, QSizePolicy::Minimum, QSizePolicy::Expanding );
    TabPageLayout_3->addItem( spacer19_2 );
    tabWidgetEntreprise->insertTab( TabPage_3, QString::fromLatin1("") );

    TabPage_4 = new QWidget( tabWidgetEntreprise, "TabPage_4" );
    TabPageLayout_4 = new QGridLayout( TabPage_4, 1, 1, 11, 6, "TabPageLayout_4"); 
    spacer35 = new QSpacerItem( 20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding );
    TabPageLayout_4->addItem( spacer35, 5, 0 );

    layout75_2 = new QHBoxLayout( 0, 0, 6, "layout75_2"); 

    textLabel31_2_2 = new QLabel( TabPage_4, "textLabel31_2_2" );
    layout75_2->addWidget( textLabel31_2_2 );

    pushButtonEntrepriseRetraitePlus = new QPushButton( TabPage_4, "pushButtonEntrepriseRetraitePlus" );
    pushButtonEntrepriseRetraitePlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEntrepriseRetraitePlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEntrepriseRetraitePlus->setMaximumSize( QSize( 20, 32767 ) );
    layout75_2->addWidget( pushButtonEntrepriseRetraitePlus );

    pushButtonEntrepriseRetraiteMinus = new QPushButton( TabPage_4, "pushButtonEntrepriseRetraiteMinus" );
    pushButtonEntrepriseRetraiteMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEntrepriseRetraiteMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEntrepriseRetraiteMinus->setMaximumSize( QSize( 20, 32767 ) );
    layout75_2->addWidget( pushButtonEntrepriseRetraiteMinus );

    TabPageLayout_4->addLayout( layout75_2, 0, 0 );

    layout76_2 = new QHBoxLayout( 0, 0, 6, "layout76_2"); 
    spacer22_2 = new QSpacerItem( 351, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout76_2->addItem( spacer22_2 );

    textLabel32_2 = new QLabel( TabPage_4, "textLabel32_2" );
    textLabel32_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel32_2->sizePolicy().hasHeightForWidth() ) );
    textLabel32_2->setMinimumSize( QSize( 150, 0 ) );
    layout76_2->addWidget( textLabel32_2 );

    TabPageLayout_4->addLayout( layout76_2, 1, 0 );

    listViewEntrepriseRetraite = new QListView( TabPage_4, "listViewEntrepriseRetraite" );
    listViewEntrepriseRetraite->addColumn( tr( "Contrat" ) );
    listViewEntrepriseRetraite->addColumn( tr( "Compagnie" ) );
    listViewEntrepriseRetraite->addColumn( trUtf8( "\x43\x6f\x6c\x6c\xc3\xa8\x67\x75\x65" ) );
    listViewEntrepriseRetraite->addColumn( tr( "TA (%)" ) );
    listViewEntrepriseRetraite->addColumn( tr( "TB (%)" ) );
    listViewEntrepriseRetraite->addColumn( tr( "TC (%)" ) );
    listViewEntrepriseRetraite->addColumn( tr( "Date d'effet" ) );
    listViewEntrepriseRetraite->addColumn( tr( "83" ) );
    listViewEntrepriseRetraite->addColumn( tr( "82AD" ) );
    listViewEntrepriseRetraite->addColumn( tr( "82SD" ) );
    listViewEntrepriseRetraite->addColumn( tr( "39" ) );

    TabPageLayout_4->addWidget( listViewEntrepriseRetraite, 2, 0 );

    layout77_2 = new QHBoxLayout( 0, 0, 6, "layout77_2"); 

    textLabel33_2 = new QLabel( TabPage_4, "textLabel33_2" );
    textLabel33_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)5, 0, 0, textLabel33_2->sizePolicy().hasHeightForWidth() ) );
    layout77_2->addWidget( textLabel33_2 );

    lineEditOrganisme = new QLineEdit( TabPage_4, "lineEditOrganisme" );
    layout77_2->addWidget( lineEditOrganisme );

    textLabel34_2_2 = new QLabel( TabPage_4, "textLabel34_2_2" );
    layout77_2->addWidget( textLabel34_2_2 );

    dateEditEntreprisePEE = new QDateEdit( TabPage_4, "dateEditEntreprisePEE" );
    dateEditEntreprisePEE->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, dateEditEntreprisePEE->sizePolicy().hasHeightForWidth() ) );
    layout77_2->addWidget( dateEditEntreprisePEE );

    TabPageLayout_4->addLayout( layout77_2, 3, 0 );

    layout90_2 = new QHBoxLayout( 0, 0, 6, "layout90_2"); 

    textLabel35_2 = new QLabel( TabPage_4, "textLabel35_2" );
    layout90_2->addWidget( textLabel35_2 );

    comboBoxEntrepriseInteressement = new QComboBox( FALSE, TabPage_4, "comboBoxEntrepriseInteressement" );
    comboBoxEntrepriseInteressement->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboBoxEntrepriseInteressement->sizePolicy().hasHeightForWidth() ) );
    layout90_2->addWidget( comboBoxEntrepriseInteressement );

    textLabel36_3 = new QLabel( TabPage_4, "textLabel36_3" );
    layout90_2->addWidget( textLabel36_3 );

    lineEditRetraiteInteressementN1 = new QLineEdit( TabPage_4, "lineEditRetraiteInteressementN1" );
    layout90_2->addWidget( lineEditRetraiteInteressementN1 );

    textLabel36_2_2 = new QLabel( TabPage_4, "textLabel36_2_2" );
    layout90_2->addWidget( textLabel36_2_2 );

    lineEditRetraiteInteressementN2 = new QLineEdit( TabPage_4, "lineEditRetraiteInteressementN2" );
    layout90_2->addWidget( lineEditRetraiteInteressementN2 );

    TabPageLayout_4->addLayout( layout90_2, 4, 0 );
    tabWidgetEntreprise->insertTab( TabPage_4, QString::fromLatin1("") );

    TabPage_5 = new QWidget( tabWidgetEntreprise, "TabPage_5" );
    TabPageLayout_5 = new QGridLayout( TabPage_5, 1, 1, 11, 6, "TabPageLayout_5"); 

    textLabel2_7 = new QLabel( TabPage_5, "textLabel2_7" );

    TabPageLayout_5->addWidget( textLabel2_7, 5, 3 );

    textLabel3_5 = new QLabel( TabPage_5, "textLabel3_5" );

    TabPageLayout_5->addMultiCellWidget( textLabel3_5, 5, 5, 4, 5 );

    textLabel4_4 = new QLabel( TabPage_5, "textLabel4_4" );

    TabPageLayout_5->addMultiCellWidget( textLabel4_4, 5, 5, 6, 7 );
    spacer37 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );
    TabPageLayout_5->addMultiCell( spacer37, 5, 5, 0, 2 );

    listViewPrevoyanceEntses = new QListView( TabPage_5, "listViewPrevoyanceEntses" );
    listViewPrevoyanceEntses->addColumn( tr( "Contrat" ) );
    listViewPrevoyanceEntses->addColumn( tr( "Compagnie" ) );
    listViewPrevoyanceEntses->addColumn( tr( "CVD (%)" ) );
    listViewPrevoyanceEntses->addColumn( tr( "M (%)" ) );
    listViewPrevoyanceEntses->addColumn( tr( "Maj/enf. (%)" ) );
    listViewPrevoyanceEntses->addColumn( tr( "Rente conjoint" ) );
    listViewPrevoyanceEntses->addColumn( trUtf8( "\x52\x65\x6e\x74\x65\x20\xc3\xa9\x64\x75\x63\x61\x74\x69\x6f\x6e" ) );
    listViewPrevoyanceEntses->addColumn( tr( "TA" ) );
    listViewPrevoyanceEntses->addColumn( tr( "TB" ) );
    listViewPrevoyanceEntses->addColumn( tr( "TC" ) );

    TabPageLayout_5->addMultiCellWidget( listViewPrevoyanceEntses, 3, 3, 0, 7 );

    listViewPrevoyance2Entses = new QListView( TabPage_5, "listViewPrevoyance2Entses" );
    listViewPrevoyance2Entses->addColumn( tr( "Contrat" ) );
    listViewPrevoyance2Entses->addColumn( tr( "Compagnie" ) );
    listViewPrevoyance2Entses->addColumn( tr( "Montant (%)" ) );
    listViewPrevoyance2Entses->addColumn( trUtf8( "\x46\x72\x61\x6e\x63\x68\x69\x73\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewPrevoyance2Entses->addColumn( trUtf8( "\x52\xc3\xa9\x64\x75\x69\x74\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewPrevoyance2Entses->addColumn( tr( "Montant (%)" ) );
    listViewPrevoyance2Entses->addColumn( trUtf8( "\x50\x61\x72\x74\x69\x65\x6c\x6c\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewPrevoyance2Entses->addColumn( tr( "TA" ) );
    listViewPrevoyance2Entses->addColumn( tr( "TB" ) );
    listViewPrevoyance2Entses->addColumn( tr( "TC" ) );

    TabPageLayout_5->addMultiCellWidget( listViewPrevoyance2Entses, 6, 6, 0, 7 );

    pushButtonPrevoyanceEntsesMinus = new QPushButton( TabPage_5, "pushButtonPrevoyanceEntsesMinus" );
    pushButtonPrevoyanceEntsesMinus->setMaximumSize( QSize( 20, 32767 ) );

    TabPageLayout_5->addWidget( pushButtonPrevoyanceEntsesMinus, 1, 7 );

    pushButtonPrevoyanceEntsesPlus = new QPushButton( TabPage_5, "pushButtonPrevoyanceEntsesPlus" );
    pushButtonPrevoyanceEntsesPlus->setMaximumSize( QSize( 20, 32767 ) );

    TabPageLayout_5->addWidget( pushButtonPrevoyanceEntsesPlus, 1, 6 );
    spacer36_2 = new QSpacerItem( 520, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    TabPageLayout_5->addMultiCell( spacer36_2, 1, 1, 0, 5 );
    spacer38 = new QSpacerItem( 130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    TabPageLayout_5->addItem( spacer38, 2, 0 );

    textLabel5_4 = new QLabel( TabPage_5, "textLabel5_4" );
    textLabel5_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_4->sizePolicy().hasHeightForWidth() ) );

    TabPageLayout_5->addWidget( textLabel5_4, 2, 1 );
    spacer39_2 = new QSpacerItem( 170, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    TabPageLayout_5->addMultiCell( spacer39_2, 2, 2, 2, 4 );

    textLabel6_3 = new QLabel( TabPage_5, "textLabel6_3" );

    TabPageLayout_5->addMultiCellWidget( textLabel6_3, 2, 2, 5, 7 );

    pushButtonPrevoyance2EntsesMinus = new QPushButton( TabPage_5, "pushButtonPrevoyance2EntsesMinus" );
    pushButtonPrevoyance2EntsesMinus->setMaximumSize( QSize( 20, 32767 ) );

    TabPageLayout_5->addWidget( pushButtonPrevoyance2EntsesMinus, 4, 7 );

    pushButtonPrevoyance2EntsesPlus = new QPushButton( TabPage_5, "pushButtonPrevoyance2EntsesPlus" );
    pushButtonPrevoyance2EntsesPlus->setMaximumSize( QSize( 20, 32767 ) );

    TabPageLayout_5->addWidget( pushButtonPrevoyance2EntsesPlus, 4, 6 );
    spacer36_2_2 = new QSpacerItem( 520, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    TabPageLayout_5->addMultiCell( spacer36_2_2, 4, 4, 0, 5 );

    textLabel1_10 = new QLabel( TabPage_5, "textLabel1_10" );

    TabPageLayout_5->addMultiCellWidget( textLabel1_10, 0, 0, 0, 7 );
    tabWidgetEntreprise->insertTab( TabPage_5, QString::fromLatin1("") );

    WStackPageLayout_10->addWidget( tabWidgetEntreprise, 0, 0 );
    widgetStackEntreprise->addWidget( WStackPage_11, 0 );

    WStackPage_12 = new QWidget( widgetStackEntreprise, "WStackPage_12" );
    WStackPageLayout_11 = new QVBoxLayout( WStackPage_12, 11, 6, "WStackPageLayout_11"); 

    layout60_2 = new QHBoxLayout( 0, 0, 6, "layout60_2"); 

    textLabel1_11 = new QLabel( WStackPage_12, "textLabel1_11" );
    layout60_2->addWidget( textLabel1_11 );

    lineEditEntsesNomEmploye = new QLineEdit( WStackPage_12, "lineEditEntsesNomEmploye" );
    layout60_2->addWidget( lineEditEntsesNomEmploye );

    textLabel2_8 = new QLabel( WStackPage_12, "textLabel2_8" );
    layout60_2->addWidget( textLabel2_8 );

    lineEditEntsesPrenomEmploye = new QLineEdit( WStackPage_12, "lineEditEntsesPrenomEmploye" );
    layout60_2->addWidget( lineEditEntsesPrenomEmploye );

    textLabel3_6 = new QLabel( WStackPage_12, "textLabel3_6" );
    layout60_2->addWidget( textLabel3_6 );

    dateEditEntsesNaissanceEmploye = new QDateEdit( WStackPage_12, "dateEditEntsesNaissanceEmploye" );
    layout60_2->addWidget( dateEditEntsesNaissanceEmploye );

    pushButtonEnstesEmployePlus = new QPushButton( WStackPage_12, "pushButtonEnstesEmployePlus" );
    pushButtonEnstesEmployePlus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEnstesEmployePlus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEnstesEmployePlus->setMaximumSize( QSize( 25, 25 ) );
    layout60_2->addWidget( pushButtonEnstesEmployePlus );

    pushButtonEnstesEmployeMinus = new QPushButton( WStackPage_12, "pushButtonEnstesEmployeMinus" );
    pushButtonEnstesEmployeMinus->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, pushButtonEnstesEmployeMinus->sizePolicy().hasHeightForWidth() ) );
    pushButtonEnstesEmployeMinus->setMaximumSize( QSize( 25, 25 ) );
    layout60_2->addWidget( pushButtonEnstesEmployeMinus );
    WStackPageLayout_11->addLayout( layout60_2 );

    textLabel1_3 = new QLabel( WStackPage_12, "textLabel1_3" );
    WStackPageLayout_11->addWidget( textLabel1_3 );

    listViewEntsesParticipants = new QListView( WStackPage_12, "listViewEntsesParticipants" );
    listViewEntsesParticipants->addColumn( tr( "Nom" ) );
    listViewEntsesParticipants->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listViewEntsesParticipants->addColumn( tr( "Date de naissance" ) );
    listViewEntsesParticipants->addColumn( tr( "Id" ) );
    WStackPageLayout_11->addWidget( listViewEntsesParticipants );
    widgetStackEntreprise->addWidget( WStackPage_12, 1 );

    WStackPage_13 = new QWidget( widgetStackEntreprise, "WStackPage_13" );
    WStackPageLayout_12 = new QVBoxLayout( WStackPage_13, 11, 6, "WStackPageLayout_12"); 

    textLabel2_3 = new QLabel( WStackPage_13, "textLabel2_3" );
    WStackPageLayout_12->addWidget( textLabel2_3 );

    listView29 = new QListView( WStackPage_13, "listView29" );
    listView29->addColumn( tr( "Nom" ) );
    listView29->addColumn( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listView29->addColumn( tr( "Date de naissance" ) );
    listView29->addColumn( tr( "Parts sociales" ) );
    listView29->addColumn( tr( "Id" ) );
    WStackPageLayout_12->addWidget( listView29 );
    widgetStackEntreprise->addWidget( WStackPage_13, 2 );
    WStackPageLayout_9->addWidget( widgetStackEntreprise );
    widgetStackMain->addWidget( WStackPage_10, 2 );

    WStackPage_14 = new QWidget( widgetStackMain, "WStackPage_14" );
    WStackPageLayout_13 = new QVBoxLayout( WStackPage_14, 11, 6, "WStackPageLayout_13"); 

    frameRechercher_2 = new QFrame( WStackPage_14, "frameRechercher_2" );
    frameRechercher_2->setFrameShape( QFrame::StyledPanel );
    frameRechercher_2->setFrameShadow( QFrame::Raised );
    frameRechercher_2Layout = new QGridLayout( frameRechercher_2, 1, 1, 11, 6, "frameRechercher_2Layout"); 

    textLabelListerFiltreNom_2 = new QLabel( frameRechercher_2, "textLabelListerFiltreNom_2" );
    textLabelListerFiltreNom_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabelListerFiltreNom_2->sizePolicy().hasHeightForWidth() ) );

    frameRechercher_2Layout->addWidget( textLabelListerFiltreNom_2, 0, 0 );

    lineEditListerFiltreRaisonSociale = new QLineEdit( frameRechercher_2, "lineEditListerFiltreRaisonSociale" );
    lineEditListerFiltreRaisonSociale->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditListerFiltreRaisonSociale->sizePolicy().hasHeightForWidth() ) );

    frameRechercher_2Layout->addWidget( lineEditListerFiltreRaisonSociale, 0, 1 );

    textLabelListerFiltrePrenom_2 = new QLabel( frameRechercher_2, "textLabelListerFiltrePrenom_2" );
    textLabelListerFiltrePrenom_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabelListerFiltrePrenom_2->sizePolicy().hasHeightForWidth() ) );

    frameRechercher_2Layout->addWidget( textLabelListerFiltrePrenom_2, 0, 2 );

    lineEditListerFiltreSiret = new QLineEdit( frameRechercher_2, "lineEditListerFiltreSiret" );
    lineEditListerFiltreSiret->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, lineEditListerFiltreSiret->sizePolicy().hasHeightForWidth() ) );

    frameRechercher_2Layout->addWidget( lineEditListerFiltreSiret, 0, 3 );

    pushButtonListerFiltrerPlus_2 = new QPushButton( frameRechercher_2, "pushButtonListerFiltrerPlus_2" );
    pushButtonListerFiltrerPlus_2->setMaximumSize( QSize( 20, 20 ) );

    frameRechercher_2Layout->addWidget( pushButtonListerFiltrerPlus_2, 1, 6 );

    pushButtonEntsesFiltreEffacer = new QPushButton( frameRechercher_2, "pushButtonEntsesFiltreEffacer" );

    frameRechercher_2Layout->addMultiCellWidget( pushButtonEntsesFiltreEffacer, 0, 0, 5, 6 );
    spacer79 = new QSpacerItem( 140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    frameRechercher_2Layout->addItem( spacer79, 0, 4 );
    spacer12_3 = new QSpacerItem( 521, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    frameRechercher_2Layout->addMultiCell( spacer12_3, 1, 1, 0, 5 );
    WStackPageLayout_13->addWidget( frameRechercher_2 );

    listViewEntses = new QListView( WStackPage_14, "listViewEntses" );
    listViewEntses->addColumn( tr( "Raison Sociale" ) );
    listViewEntses->addColumn( tr( "Siret" ) );
    listViewEntses->addColumn( tr( "Id" ) );
    WStackPageLayout_13->addWidget( listViewEntses );
    widgetStackMain->addWidget( WStackPage_14, 3 );
    dlgMainLayout->addWidget( widgetStackMain );

    // actions
    filenew_itemOuvrir = new QAction( this, "filenew_itemOuvrir" );
    filenew_itemOuvrir->setEnabled( FALSE );
    filenew_itemSauvegarder = new QAction( this, "filenew_itemSauvegarder" );
    filenew_itemSauvegarder->setEnabled( TRUE );
    filenew_itemQuitter = new QAction( this, "filenew_itemQuitter" );
    filenew_itemSauvegarderSous = new QAction( this, "filenew_itemSauvegarderSous" );
    filenew_itemSauvegarderSous->setEnabled( FALSE );
    help_itemAbout = new QAction( this, "help_itemAbout" );
    outils__itemPreferences = new QAction( this, "outils__itemPreferences" );
    menuChargerAction = new QAction( this, "menuChargerAction" );
    fichierImporterAction = new QAction( this, "fichierImporterAction" );
    filenew_itemSauvegarderSousnew_itemAction = new QAction( this, "filenew_itemSauvegarderSousnew_itemAction" );
    fichierExporterAction = new QAction( this, "fichierExporterAction" );


    // toolbars


    // menubar
    MenuBar = new QMenuBar( this, "MenuBar" );


    Fichier = new QPopupMenu( this );
    Fichier->insertSeparator();
    Fichier->insertSeparator();
    filenew_itemOuvrir->addTo( Fichier );
    filenew_itemSauvegarder->addTo( Fichier );
    filenew_itemSauvegarderSous->addTo( Fichier );
    fichierImporterAction->addTo( Fichier );
    fichierExporterAction->addTo( Fichier );
    Fichier->insertSeparator();
    filenew_itemQuitter->addTo( Fichier );
    MenuBar->insertItem( QString(""), Fichier, 1 );

    Edition = new QPopupMenu( this );
    Edition->insertSeparator();
    Edition->insertSeparator();
    MenuBar->insertItem( QString(""), Edition, 2 );

    Outils = new QPopupMenu( this );
    outils__itemPreferences->addTo( Outils );
    MenuBar->insertItem( QString(""), Outils, 3 );

    Aide = new QPopupMenu( this );
    Aide->insertSeparator();
    help_itemAbout->addTo( Aide );
    MenuBar->insertItem( QString(""), Aide, 4 );

    MenuBar->insertSeparator( 5 );

    languageChange();
    resize( QSize(727, 725).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( filenew_itemQuitter, SIGNAL( activated() ), this, SLOT( close() ) );
    connect( filenew_itemOuvrir, SIGNAL( activated() ), this, SLOT( ouvrir() ) );
    connect( filenew_itemSauvegarderSous, SIGNAL( activated() ), this, SLOT( sauvegarder() ) );
    connect( help_itemAbout, SIGNAL( activated() ), this, SLOT( about() ) );
    connect( pushButtonEtatCivil, SIGNAL( clicked() ), this, SLOT( widgetStackAjouter_EtatCivil() ) );
    connect( pushButtonFamille, SIGNAL( clicked() ), this, SLOT( widgetStackAjouter_Famille() ) );
    connect( pushButtonCarriere, SIGNAL( clicked() ), this, SLOT( widgetStackAjouter_Carriere() ) );
    connect( pushButtonPrevoyance, SIGNAL( clicked() ), this, SLOT( widgetStackAjouter_Prevoyance() ) );
    connect( pushButtonEpargne, SIGNAL( clicked() ), this, SLOT( widgetStackAjouter_Epargne() ) );
    connect( pushButtonPatrimoine, SIGNAL( clicked() ), this, SLOT( widgetStackAjouter_Patrimoine() ) );
    connect( pushButtonDossierEntreprise, SIGNAL( clicked() ), this, SLOT( pushButtonDossierEntreprise_clicked() ) );
    connect( pushButtonParticipants, SIGNAL( clicked() ), this, SLOT( pushButtonParticipants_clicked() ) );
    connect( pushButtonTNS, SIGNAL( clicked() ), this, SLOT( pushButtonTNS_clicked() ) );
    connect( filenew_itemSauvegarder, SIGNAL( activated() ), this, SLOT( filenew_itemSauvegarder_activated() ) );
    connect( listView, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( charger() ) );
    connect( pushButtonPersonneAjouter, SIGNAL( clicked() ), this, SLOT( ajouter() ) );
    connect( pushButtonPersonneLister, SIGNAL( clicked() ), this, SLOT( lister() ) );
    connect( pushButtonSupprimer, SIGNAL( clicked() ), this, SLOT( toolButtonSupprimer_clicked() ) );
    connect( pushButtonCharger, SIGNAL( clicked() ), this, SLOT( charger() ) );
    connect( pushButton44, SIGNAL( clicked() ), this, SLOT( pushButtonAjouterEntreprise_clicked() ) );
    connect( pushButtonEntrepriseLister, SIGNAL( clicked() ), this, SLOT( pushButtonEntrepriseLister_clicked() ) );
    connect( listViewEntses, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( charger() ) );
    connect( outils__itemPreferences, SIGNAL( activated() ), this, SLOT( preferences() ) );
    connect( pushButtonBesoins, SIGNAL( clicked() ), this, SLOT( pushButtonBesoins_clicked() ) );
    connect( comboBoxFamilleConjoint, SIGNAL( activated(const QString&) ), this, SLOT( comboBoxFamilleConjoint_textChanged(const QString&) ) );
    connect( sliderEpargneSensibilite, SIGNAL( valueChanged(int) ), this, SLOT( sliderEpargneSensibilite_valueChanged(int) ) );
    connect( comboBoxEtatCivilCabinetComptable, SIGNAL( highlighted(const QString&) ), this, SLOT( comboBoxEtatCivilCabinetComptable_textChanged(const QString&) ) );
    connect( comboBoxEtatCivilEtude, SIGNAL( highlighted(const QString&) ), this, SLOT( comboBoxEtatCivilEtude_textChanged(const QString&) ) );
    connect( comboBoxEtatCivilCabinetAvocat, SIGNAL( highlighted(const QString&) ), this, SLOT( comboBoxEtatCivilCabinetAvocat_textChanged(const QString&) ) );
    connect( pushButtonDirigeantPlus, SIGNAL( clicked() ), this, SLOT( pushButtonDirigeantPlus_clicked() ) );
    connect( pushButtontDirigeantMinus, SIGNAL( clicked() ), this, SLOT( pushButtontDirigeantMinus_clicked() ) );
    connect( comboBoxBenefProspect, SIGNAL( activated(int) ), this, SLOT( comboBoxBenefProspect_activated(int) ) );
    connect( comboBoxEtatCivilRaisonSociale, SIGNAL( activated(int) ), this, SLOT( comboBoxEtatCivilRaisonSociale_activated(int) ) );
    connect( pushButtonEnstesEmployeMinus, SIGNAL( clicked() ), this, SLOT( pushButtonEnstesEmployeMinus_clicked() ) );
    connect( pushButtonEnstesEmployePlus, SIGNAL( clicked() ), this, SLOT( pushButtonEnstesEmployePlus_clicked() ) );
    connect( listView29, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( listView29_doubleClicked(QListViewItem*) ) );
    connect( listViewEntsesParticipants, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( listViewEntsesParticipants_doubleClicked(QListViewItem*) ) );
    connect( listViewDirigeants, SIGNAL( doubleClicked(QListViewItem*) ), this, SLOT( listViewDirigeants_doubleClicked(QListViewItem*) ) );
    connect( lineEditListerFiltreNom, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEditListerFiltreNom_textChanged(const QString&) ) );
    connect( lineEditListerFiltrePrenom, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEditListerFiltrePrenom_textChanged(const QString&) ) );
    connect( fichierImporterAction, SIGNAL( activated() ), this, SLOT( fichierImporterAction_activated() ) );
    connect( comboBoxSearchProspect, SIGNAL( activated(int) ), this, SLOT( comboBoxSearchProspect_activated(int) ) );
    connect( lineEditListerFiltreSiret, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEditListerFiltreSiret_textChanged(const QString&) ) );
    connect( lineEditListerFiltreRaisonSociale, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEditListerFiltreRaisonSociale_textChanged(const QString&) ) );
    connect( pushButtonEntsesFiltreEffacer, SIGNAL( clicked() ), this, SLOT( pushButtonEntsesFiltreEffacer_clicked() ) );
    connect( pushButtonPersonneFiltreEffacer, SIGNAL( clicked() ), this, SLOT( pushButtonPersonneFiltreEffacer_clicked() ) );
    connect( lineEditSearchValue1, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEditSearchValue1_textChanged(const QString&) ) );
    connect( lineEditSearchValue2, SIGNAL( textChanged(const QString&) ), this, SLOT( lineEditSearchValue2_textChanged(const QString&) ) );
    connect( comboBoxSearchFunction, SIGNAL( activated(int) ), this, SLOT( comboBoxSearchFunction_activated(int) ) );
    connect( comboBoxSearchOp1, SIGNAL( activated(int) ), this, SLOT( comboBoxSearchOp1_highlighted() ) );
    connect( comboBoxSearchOp2, SIGNAL( activated(int) ), this, SLOT( comboBoxSearchOp2_highlighted() ) );
    connect( fichierExporterAction, SIGNAL( activated() ), this, SLOT( fichierExporterAction_activated() ) );

    // tab order
    setTabOrder( pushButtonPersonneLister, pushButtonPersonneAjouter );
    setTabOrder( pushButtonPersonneAjouter, pushButtonEntrepriseLister );
    setTabOrder( pushButtonEntrepriseLister, pushButton44 );
    setTabOrder( pushButton44, pushButtonSupprimer );
    setTabOrder( pushButtonSupprimer, pushButtonCharger );
    setTabOrder( pushButtonCharger, lineEditListerFiltreRaisonSociale );
    setTabOrder( lineEditListerFiltreRaisonSociale, lineEditListerFiltreSiret );
    setTabOrder( lineEditListerFiltreSiret, pushButtonListerFiltrerPlus_2 );
    setTabOrder( pushButtonListerFiltrerPlus_2, listViewEntses );
    setTabOrder( listViewEntses, pushButtonEtatCivil );
    setTabOrder( pushButtonEtatCivil, pushButtonFamille );
    setTabOrder( pushButtonFamille, pushButtonCarriere );
    setTabOrder( pushButtonCarriere, pushButtonPrevoyance );
    setTabOrder( pushButtonPrevoyance, pushButtonEpargne );
    setTabOrder( pushButtonEpargne, pushButtonPatrimoine );
    setTabOrder( pushButtonPatrimoine, pushButtonBesoins );
    setTabOrder( pushButtonBesoins, comboBoxEtatCivilCivilite );
    setTabOrder( comboBoxEtatCivilCivilite, lineEditEtatCivilNom );
    setTabOrder( lineEditEtatCivilNom, lineEditEtatCivilNomJeuneFille );
    setTabOrder( lineEditEtatCivilNomJeuneFille, lineEditEtatCivilPrenom );
    setTabOrder( lineEditEtatCivilPrenom, dateEditEtatCivilDateNaissance );
    setTabOrder( dateEditEtatCivilDateNaissance, lineEditEtatCivilLieuNaissance );
    setTabOrder( lineEditEtatCivilLieuNaissance, lineEditEtatCivilRue );
    setTabOrder( lineEditEtatCivilRue, lineEditEtatCivilAdresseComplement );
    setTabOrder( lineEditEtatCivilAdresseComplement, lineEditEtatCivilCodePostal );
    setTabOrder( lineEditEtatCivilCodePostal, lineEditEtatCivilVille );
    setTabOrder( lineEditEtatCivilVille, lineEditEtatCivilTelephone );
    setTabOrder( lineEditEtatCivilTelephone, lineEditEtatCivilTelephonePortable );
    setTabOrder( lineEditEtatCivilTelephonePortable, lineEditEtatCivilRueGestion );
    setTabOrder( lineEditEtatCivilRueGestion, lineEditEtatCivilAdresseComplementGestion );
    setTabOrder( lineEditEtatCivilAdresseComplementGestion, lineEditEtatCivilCodePostalGestion );
    setTabOrder( lineEditEtatCivilCodePostalGestion, lineEditEtatCivilVilleGestion );
    setTabOrder( lineEditEtatCivilVilleGestion, lineEditEtatCivilTelephonePro );
    setTabOrder( lineEditEtatCivilTelephonePro, lineEditEtatCivilTelephoneFax );
    setTabOrder( lineEditEtatCivilTelephoneFax, comboBoxBenefProspect );
    setTabOrder( comboBoxBenefProspect, lineEditEtatCivilEmail );
    setTabOrder( lineEditEtatCivilEmail, comboBoxEtatCivilRaisonSociale );
    setTabOrder( comboBoxEtatCivilRaisonSociale, comboBoxEtatCivilSituationFamilliale );
    setTabOrder( comboBoxEtatCivilSituationFamilliale, comboBoxEtatCivilCabinetComptable );
    setTabOrder( comboBoxEtatCivilCabinetComptable, comboBoxEtatCivilExpertComptable );
    setTabOrder( comboBoxEtatCivilExpertComptable, comboBoxEtatCivilEtude );
    setTabOrder( comboBoxEtatCivilEtude, comboBoxEtatCivilNotaire );
    setTabOrder( comboBoxEtatCivilNotaire, comboBoxEtatCivilCabinetAvocat );
    setTabOrder( comboBoxEtatCivilCabinetAvocat, comboBoxEtatCivilAvocat );
    setTabOrder( comboBoxEtatCivilAvocat, tabWidgetFamille );
    setTabOrder( tabWidgetFamille, comboBoxFamilleConjoint );
    setTabOrder( comboBoxFamilleConjoint, dateEditFamilleDateMariage );
    setTabOrder( dateEditFamilleDateMariage, lineEditFamilleRgMariage );
    setTabOrder( lineEditFamilleRgMariage, comboBoxFamilleRegimeMatrimonial );
    setTabOrder( comboBoxFamilleRegimeMatrimonial, checkBoxFamilleDonationDernierVivant );
    setTabOrder( checkBoxFamilleDonationDernierVivant, textEditFamilleAutreDispo );
    setTabOrder( textEditFamilleAutreDispo, lineEditFamilleDureeMariagesPrecedentsMonsieur );
    setTabOrder( lineEditFamilleDureeMariagesPrecedentsMonsieur, lineEditFamilleNombreEnfantsCommuns );
    setTabOrder( lineEditFamilleNombreEnfantsCommuns, lineEditFamilleNombreEnfantsMonsieur );
    setTabOrder( lineEditFamilleNombreEnfantsMonsieur, pushButtonEnfantPlus );
    setTabOrder( pushButtonEnfantPlus, pushButtonEnfantsMinus );
    setTabOrder( pushButtonEnfantsMinus, lineEditFamilleDispositionsTestamentaires );
    setTabOrder( lineEditFamilleDispositionsTestamentaires, lineEditFamilleDonationEntreEpoux );
    setTabOrder( lineEditFamilleDonationEntreEpoux, lineEditCarriereSalaireAnnuel );
    setTabOrder( lineEditCarriereSalaireAnnuel, comboBoxCarriereNetBrut );
    setTabOrder( comboBoxCarriereNetBrut, lineEditCarriereBNC );
    setTabOrder( lineEditCarriereBNC, lineEditCarriereBIC );
    setTabOrder( lineEditCarriereBIC, lineEditCarriereRevenusFonciers );
    setTabOrder( lineEditCarriereRevenusFonciers, lineEditCarriereDividendes );
    setTabOrder( lineEditCarriereDividendes, lineEditCarriereAutresRevenus );
    setTabOrder( lineEditCarriereAutresRevenus, lineEditCarriereMontantImpotMonsieur );
    setTabOrder( lineEditCarriereMontantImpotMonsieur, comboBoxCarriereISF );
    setTabOrder( comboBoxCarriereISF, lineEditCarriereMontantISF );
    setTabOrder( lineEditCarriereMontantISF, comboBoxCarriereCGA );
    setTabOrder( comboBoxCarriereCGA, lineEditCarriereDeductionsMonsieur );
    setTabOrder( lineEditCarriereDeductionsMonsieur, comboBoxStatutPro );
    setTabOrder( comboBoxStatutPro, lineEditRevenusFonction );
    setTabOrder( lineEditRevenusFonction, lineEditRevenusEmployeur );
    setTabOrder( lineEditRevenusEmployeur, pushButtonCarriereEmploiPlus );
    setTabOrder( pushButtonCarriereEmploiPlus, pushButtonCarriereEmploiMinus );
    setTabOrder( pushButtonCarriereEmploiMinus, listViewCarriereEmploi );
    setTabOrder( listViewCarriereEmploi, lineEditCarriereAgeRetraite );
    setTabOrder( lineEditCarriereAgeRetraite, lineEditPrevoyanceSanteNiveauGarantie );
    setTabOrder( lineEditPrevoyanceSanteNiveauGarantie, dateEditPrevoyanceDateEffet );
    setTabOrder( dateEditPrevoyanceDateEffet, lineEditPrevoyanceSanteCotisationAnnuelle );
    setTabOrder( lineEditPrevoyanceSanteCotisationAnnuelle, lineEditPrevoyanceSanteIndiceSatisfaction );
    setTabOrder( lineEditPrevoyanceSanteIndiceSatisfaction, comboBoxPrevoyanceSanteBeneficiaires );
    setTabOrder( comboBoxPrevoyanceSanteBeneficiaires, checkBoxPrevoyanceSanteCaractereViagerOui );
    setTabOrder( checkBoxPrevoyanceSanteCaractereViagerOui, checkBoxPrevoyanceSanteCaractereViagerNon );
    setTabOrder( checkBoxPrevoyanceSanteCaractereViagerNon, checkBoxPrevoyanceSanteCaractereViagerPersonnel );
    setTabOrder( checkBoxPrevoyanceSanteCaractereViagerPersonnel, checkBoxPrevoyanceSanteCaractereViagerEntreprise );
    setTabOrder( checkBoxPrevoyanceSanteCaractereViagerEntreprise, lineEditPrevoyanceSanteFiscalite );
    setTabOrder( lineEditPrevoyanceSanteFiscalite, comboBoxPrevoyanceSanteSource );
    setTabOrder( comboBoxPrevoyanceSanteSource, comboBoxPrevoyanceSanteCompagnie );
    setTabOrder( comboBoxPrevoyanceSanteCompagnie, lineEditPrevoyanceSanteContrat );
    setTabOrder( lineEditPrevoyanceSanteContrat, textEditNotesPrevoyanceSante );
    setTabOrder( textEditNotesPrevoyanceSante, pushButtonPrevoyanceArretTravailPlus );
    setTabOrder( pushButtonPrevoyanceArretTravailPlus, pushButtonPrevoyanceArretTravailMinus );
    setTabOrder( pushButtonPrevoyanceArretTravailMinus, listViewArretTravail );
    setTabOrder( listViewArretTravail, lineEditPrevoyanceSanteMaladie );
    setTabOrder( lineEditPrevoyanceSanteMaladie, lineEditPrevoyanceSanteAccident );
    setTabOrder( lineEditPrevoyanceSanteAccident, lineEditPrevoyanceSanteHospitalisation );
    setTabOrder( lineEditPrevoyanceSanteHospitalisation, comboBoxPrevoyanceSanteCompagnieArretTravail );
    setTabOrder( comboBoxPrevoyanceSanteCompagnieArretTravail, lineEditPrevoyanceSanteContratArretTravail );
    setTabOrder( lineEditPrevoyanceSanteContratArretTravail, comboBoxPrevoyanceSanteFiscaliteArretTravail );
    setTabOrder( comboBoxPrevoyanceSanteFiscaliteArretTravail, dateEditPrevoyanceSanteArretTravailDateEffet );
    setTabOrder( dateEditPrevoyanceSanteArretTravailDateEffet, dateEditPrevoyanceSanteArretTravailDateMiseAJour );
    setTabOrder( dateEditPrevoyanceSanteArretTravailDateMiseAJour, comboBoxPrevoyanceSanteArretTravailAccordAssocies );
    setTabOrder( comboBoxPrevoyanceSanteArretTravailAccordAssocies, lineEditPrevoyanceSanteArretTravailDuree );
    setTabOrder( lineEditPrevoyanceSanteArretTravailDuree, lineEditPrevoyanceSanteInvalidite33 );
    setTabOrder( lineEditPrevoyanceSanteInvalidite33, lineEditPrevoyanceSanteInvalidite66 );
    setTabOrder( lineEditPrevoyanceSanteInvalidite66, lineEditPrevoyanceSanteInvalidite100 );
    setTabOrder( lineEditPrevoyanceSanteInvalidite100, comboBoxPrevoyanceSanteInvaliditeProfessionnelle );
    setTabOrder( comboBoxPrevoyanceSanteInvaliditeProfessionnelle, comboBoxPrevoyanceSanteInvaliditeFiscalite );
    setTabOrder( comboBoxPrevoyanceSanteInvaliditeFiscalite, comboBoxPrevoyanceSanteInvaliditeCompagnie );
    setTabOrder( comboBoxPrevoyanceSanteInvaliditeCompagnie, dateEditPrevoyanceSanteInvaliditeDateEffet );
    setTabOrder( dateEditPrevoyanceSanteInvaliditeDateEffet, dateEditPRevoyanceSanteInvaliditeMiseAJour );
    setTabOrder( dateEditPRevoyanceSanteInvaliditeMiseAJour, lineEditPrevoyanceSanteCapitauxInvalidite );
    setTabOrder( lineEditPrevoyanceSanteCapitauxInvalidite, textEditNotesPrevoyanceInvalidite );
    setTabOrder( textEditNotesPrevoyanceInvalidite, pushButtonPrevoyanceGarantieDecesPlus );
    setTabOrder( pushButtonPrevoyanceGarantieDecesPlus, pushButtonPrevoyanceGarantieDecesMinus );
    setTabOrder( pushButtonPrevoyanceGarantieDecesMinus, listViewGarantieDeces );
    setTabOrder( listViewGarantieDeces, lineEditPrevoyanceDecesRenteConjointMontant );
    setTabOrder( lineEditPrevoyanceDecesRenteConjointMontant, lineEditPrevoyanceRenteConjointDuree );
    setTabOrder( lineEditPrevoyanceRenteConjointDuree, comboBoxPrevoyanceDecesRenteConjointFiscalite );
    setTabOrder( comboBoxPrevoyanceDecesRenteConjointFiscalite, comboBoxPrevoyanceDecesCompagnieConjoint );
    setTabOrder( comboBoxPrevoyanceDecesCompagnieConjoint, dateEditPrevoyanceDecesRenteConjointDateEffet );
    setTabOrder( dateEditPrevoyanceDecesRenteConjointDateEffet, pushButtonPrevoyanceRenteEducationPlus );
    setTabOrder( pushButtonPrevoyanceRenteEducationPlus, pushButtonPrevoyanceRenteEducationMinus );
    setTabOrder( pushButtonPrevoyanceRenteEducationMinus, listViewRenteEducation );
    setTabOrder( listViewRenteEducation, comboBoxPrevoyanceDecesRenteEducationFiscalite );
    setTabOrder( comboBoxPrevoyanceDecesRenteEducationFiscalite, tabWidget3 );
    setTabOrder( tabWidget3, comboBoxPrevoyanceDecesRenteEducationCompagnie );
    setTabOrder( comboBoxPrevoyanceDecesRenteEducationCompagnie, dateEditPrevoyanceDecesRenteEducationDateEffet );
    setTabOrder( dateEditPrevoyanceDecesRenteEducationDateEffet, textEditPrevoyanceDecesNotes );
    setTabOrder( textEditPrevoyanceDecesNotes, lineEditPrevoyanceSanteCouvertureMensuelle );
    setTabOrder( lineEditPrevoyanceSanteCouvertureMensuelle, comboBoxPrevoyanceSanteCompagnieFraisGeneraux );
    setTabOrder( comboBoxPrevoyanceSanteCompagnieFraisGeneraux, lineEditPrevoyanceSanteFranchise );
    setTabOrder( lineEditPrevoyanceSanteFranchise, dateEditPrevoyanceSanteDureeFraisGeneraux );
    setTabOrder( dateEditPrevoyanceSanteDureeFraisGeneraux, lineEditPrevoyanceSanteContratFraisGeneraux );
    setTabOrder( lineEditPrevoyanceSanteContratFraisGeneraux, pushButtonPrevoyanceEmpruntPlus );
    setTabOrder( pushButtonPrevoyanceEmpruntPlus, pushButtonPrevoyanceEmpruntMinus );
    setTabOrder( pushButtonPrevoyanceEmpruntMinus, listViewEmprunt );
    setTabOrder( listViewEmprunt, textEditPrevoyanceElpruntNotes );
    setTabOrder( textEditPrevoyanceElpruntNotes, tabWidgetEpargne );
    setTabOrder( tabWidgetEpargne, pushButtonEpargneCapitalisationPlus );
    setTabOrder( pushButtonEpargneCapitalisationPlus, pushButtonEpargneCapitalisationMinus );
    setTabOrder( pushButtonEpargneCapitalisationMinus, listViewEpargne );
    setTabOrder( listViewEpargne, pushButtonEpargneAssurancePlus );
    setTabOrder( pushButtonEpargneAssurancePlus, pushButtonEpargneAssuranceMinus );
    setTabOrder( pushButtonEpargneAssuranceMinus, listViewAssuranceVie );
    setTabOrder( listViewAssuranceVie, sliderEpargneSensibilite );
    setTabOrder( sliderEpargneSensibilite, comboBoxMotivation );
    setTabOrder( comboBoxMotivation, comboBoxMotivation_2 );
    setTabOrder( comboBoxMotivation_2, comboBoxMotivation_3 );
    setTabOrder( comboBoxMotivation_3, comboBoxMotivation_4 );
    setTabOrder( comboBoxMotivation_4, pushButtonEpargneComptePlus );
    setTabOrder( pushButtonEpargneComptePlus, pushButtonEpargneCompteMinus );
    setTabOrder( pushButtonEpargneCompteMinus, listViewComptes );
    setTabOrder( listViewComptes, pushButtonEpargneRevenusPlus );
    setTabOrder( pushButtonEpargneRevenusPlus, pushButtonEpargneRevenusMinus );
    setTabOrder( pushButtonEpargneRevenusMinus, listViewRevenus );
    setTabOrder( listViewRevenus, pushButtonEpargneChargesPlus );
    setTabOrder( pushButtonEpargneChargesPlus, pushButtonEpargneChargesMinus );
    setTabOrder( pushButtonEpargneChargesMinus, listViewCharges );
    setTabOrder( listViewCharges, lineEditBesoinsRetraite );
    setTabOrder( lineEditBesoinsRetraite, lineEditBesoinPrevoyance );
    setTabOrder( lineEditBesoinPrevoyance, lineEditBesoinSante );
    setTabOrder( lineEditBesoinSante, lineEditBesoinEpargne );
    setTabOrder( lineEditBesoinEpargne, lineEditBesoinPatrimoine );
    setTabOrder( lineEditBesoinPatrimoine, textEditBesoinNotes );
    setTabOrder( textEditBesoinNotes, lineEditListerFiltreNom );
    setTabOrder( lineEditListerFiltreNom, lineEditListerFiltrePrenom );
    setTabOrder( lineEditListerFiltrePrenom, listView );
    setTabOrder( listView, lineEditRaisonSociale );
    setTabOrder( lineEditRaisonSociale, lineEditDateCreation );
    setTabOrder( lineEditDateCreation, comboBoxFormeJuridique );
    setTabOrder( comboBoxFormeJuridique, lineEditAutreFormeJuridique );
    setTabOrder( lineEditAutreFormeJuridique, comboBoxSuiteEco );
    setTabOrder( comboBoxSuiteEco, lineEditEntrepriseNomRue );
    setTabOrder( lineEditEntrepriseNomRue, lineEditEntrepriseComplement );
    setTabOrder( lineEditEntrepriseComplement, lineEditEntrepriseCodePostal );
    setTabOrder( lineEditEntrepriseCodePostal, lineEditEntrepriseVille );
    setTabOrder( lineEditEntrepriseVille, lineEditCodeNaf );
    setTabOrder( lineEditCodeNaf, lineEditNumSiret );
    setTabOrder( lineEditNumSiret, lineEditActivite );
    setTabOrder( lineEditActivite, lineEditConventionCollective );
    setTabOrder( lineEditConventionCollective, checkBoxAGA );
    setTabOrder( checkBoxAGA, checkBoxCGA );
    setTabOrder( checkBoxCGA, lineEditTelEnses );
    setTabOrder( lineEditTelEnses, lineEditFaxEntses );
    setTabOrder( lineEditFaxEntses, lineEdithttpentses );
    setTabOrder( lineEdithttpentses, lineEditColGer );
    setTabOrder( lineEditColGer, lineEditProche );
    setTabOrder( lineEditProche, lineEditAutre );
    setTabOrder( lineEditAutre, lineEditBenefN1 );
    setTabOrder( lineEditBenefN1, lineEditBenefN2 );
    setTabOrder( lineEditBenefN2, comboBoxRegimeFiscal );
    setTabOrder( comboBoxRegimeFiscal, lineEditNomGerant );
    setTabOrder( lineEditNomGerant, lineEditPrenomGerant );
    setTabOrder( lineEditPrenomGerant, dateEditNaissanceGerant );
    setTabOrder( dateEditNaissanceGerant, comboBoxPartsDirigeant );
    setTabOrder( comboBoxPartsDirigeant, pushButtonDirigeantPlus );
    setTabOrder( pushButtonDirigeantPlus, pushButtontDirigeantMinus );
    setTabOrder( pushButtontDirigeantMinus, listViewDirigeants );
    setTabOrder( listViewDirigeants, tabWidgetEntreprise );
    setTabOrder( tabWidgetEntreprise, lineEditNbCadres );
    setTabOrder( lineEditNbCadres, lineEditNbETAM );
    setTabOrder( lineEditNbETAM, lineEditNbNonCadres );
    setTabOrder( lineEditNbNonCadres, lineEditNbAutreColleges );
    setTabOrder( lineEditNbAutreColleges, comboBoxDeleguePersonnel );
    setTabOrder( comboBoxDeleguePersonnel, comboBoxComiteEntreprise );
    setTabOrder( comboBoxComiteEntreprise, comboBoxInteressement );
    setTabOrder( comboBoxInteressement, lineEditInteressementMod );
    setTabOrder( lineEditInteressementMod, lineEditARRCOPS );
    setTabOrder( lineEditARRCOPS, lineEditAGIRCPS );
    setTabOrder( lineEditAGIRCPS, lineEditAutrePS );
    setTabOrder( lineEditAutrePS, lineEditARRCOPP );
    setTabOrder( lineEditARRCOPP, lineEditAGIRCPP );
    setTabOrder( lineEditAGIRCPP, lineEditAutrePP );
    setTabOrder( lineEditAutrePP, lineEditCaisseCongesPayes );
    setTabOrder( lineEditCaisseCongesPayes, lineEditTauxAccidentTravail );
    setTabOrder( lineEditTauxAccidentTravail, lineEditTaxeTransport );
    setTabOrder( lineEditTaxeTransport, pushButtonEntrepriseRetraitePlus );
    setTabOrder( pushButtonEntrepriseRetraitePlus, pushButtonEntrepriseRetraiteMinus );
    setTabOrder( pushButtonEntrepriseRetraiteMinus, listViewEntrepriseRetraite );
    setTabOrder( listViewEntrepriseRetraite, lineEditOrganisme );
    setTabOrder( lineEditOrganisme, dateEditEntreprisePEE );
    setTabOrder( dateEditEntreprisePEE, comboBoxEntrepriseInteressement );
    setTabOrder( comboBoxEntrepriseInteressement, lineEditRetraiteInteressementN1 );
    setTabOrder( lineEditRetraiteInteressementN1, lineEditRetraiteInteressementN2 );
    setTabOrder( lineEditRetraiteInteressementN2, pushButtonPrevoyanceEntsesPlus );
    setTabOrder( pushButtonPrevoyanceEntsesPlus, pushButtonPrevoyanceEntsesMinus );
    setTabOrder( pushButtonPrevoyanceEntsesMinus, listViewPrevoyanceEntses );
    setTabOrder( listViewPrevoyanceEntses, pushButtonPrevoyance2EntsesPlus );
    setTabOrder( pushButtonPrevoyance2EntsesPlus, pushButtonPrevoyance2EntsesMinus );
    setTabOrder( pushButtonPrevoyance2EntsesMinus, listViewPrevoyance2Entses );
    setTabOrder( listViewPrevoyance2Entses, listViewEntsesParticipants );
    setTabOrder( listViewEntsesParticipants, listView29 );
    setTabOrder( listView29, pushButtonDossierEntreprise );
    setTabOrder( pushButtonDossierEntreprise, pushButtonParticipants );
    setTabOrder( pushButtonParticipants, pushButtonTNS );
    setTabOrder( pushButtonTNS, dateEditFamilleDateNaissance );
    setTabOrder( dateEditFamilleDateNaissance, lineEditFamilleNomRue );
    setTabOrder( lineEditFamilleNomRue, lineEditFamilleAdresseComplement );
    setTabOrder( lineEditFamilleAdresseComplement, lineEditFamilleCodePostal );
    setTabOrder( lineEditFamilleCodePostal, lineEditFamilleVille );
    setTabOrder( lineEditFamilleVille, lineEditFamilleTelephone );
    setTabOrder( lineEditFamilleTelephone, lineEditFamilleEmail );
    setTabOrder( lineEditFamilleEmail, lineEditFamilleDureeMariagesPrecedentsMadame );
    setTabOrder( lineEditFamilleDureeMariagesPrecedentsMadame, lineEditFamilleNombreEnfantsMadame );
    setTabOrder( lineEditFamilleNombreEnfantsMadame, listViewEnfants );
    setTabOrder( listViewEnfants, lineEditCarriereMontantImpotMadame );
    setTabOrder( lineEditCarriereMontantImpotMadame, lineEditCarriereDeductionsMadame );
    setTabOrder( lineEditCarriereDeductionsMadame, lineEditFamilleLieuNaissance );
    setTabOrder( lineEditFamilleLieuNaissance, lineEditFamilleTelephonePro );
    setTabOrder( lineEditFamilleTelephonePro, lineEditFamilleTelephonePortable );
    setTabOrder( lineEditFamilleTelephonePortable, lineEditFamilleTelephoneFax );
    setTabOrder( lineEditFamilleTelephoneFax, comboBoxFamilleNetBrut );
    setTabOrder( comboBoxFamilleNetBrut, lineEditFamilleAutresRevenus );
    setTabOrder( lineEditFamilleAutresRevenus, lineEditFamilleDividendes );
    setTabOrder( lineEditFamilleDividendes, lineEditFamilleBNC );
    setTabOrder( lineEditFamilleBNC, lineEditFamilleBIC );
    setTabOrder( lineEditFamilleBIC, lineEditFamilleSalaireAnnuel );
    setTabOrder( lineEditFamilleSalaireAnnuel, lineEditFamilleRevenusFonciers );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgAmonSoft::~dlgAmonSoft()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgAmonSoft::languageChange()
{
    setCaption( tr( "AmonSoft" ) );
    pushButtonPersonneLister->setText( QString::null );
    QToolTip::add( pushButtonPersonneLister, tr( "Lister les personnes" ) );
    pushButtonPersonneAjouter->setText( QString::null );
    QToolTip::add( pushButtonPersonneAjouter, tr( "Ajouter une personne" ) );
    pushButtonEntrepriseLister->setText( QString::null );
    QToolTip::add( pushButtonEntrepriseLister, trUtf8( "\x43\x68\x61\x72\x67\x65\x72\x20\x75\x6e\x65\x20\x73\x6f\x63\x69\xc3\xa9\x74\xc3\xa9" ) );
    pushButton44->setText( QString::null );
    QToolTip::add( pushButton44, trUtf8( "\x41\x6a\x6f\x75\x74\x65\x72\x20\x75\x6e\x65\x20\x73\x6f\x63\x69\xc3\xa9\x74\xc3\xa9" ) );
    pushButtonCharger->setText( QString::null );
    QToolTip::add( pushButtonCharger, tr( "Charger / Sauvegarder" ) );
    pushButtonSupprimer->setText( QString::null );
    QToolTip::add( pushButtonSupprimer, tr( "Supprimer / Reset" ) );
    pushButtonEtatCivil->setText( QString::null );
    pushButtonFamille->setText( QString::null );
    pushButtonCarriere->setText( QString::null );
    pushButtonPrevoyance->setText( QString::null );
    pushButtonEpargne->setText( QString::null );
    pushButtonPatrimoine->setText( QString::null );
    pushButtonBesoins->setText( tr( "Besoins /\n"
"Notes" ) );
    labelEtatCivil->setText( tr( "<h1><p align=\"center\">Client</p></h1>" ) );
    textLabelEtatCivilRue->setText( tr( "Nom de rue" ) );
    textLabelEtatCivilAdresseComplement->setText( trUtf8( "\x43\x6f\x6d\x70\x6c\xc3\xa9\x6d\x65\x6e\x74" ) );
    textLabelCodePostal->setText( tr( "Code Postal" ) );
    labelEtatCivilTelephone->setText( trUtf8( "\x54\xc3\xa9\x6c\x2e\x20\x64\x6f\x6d\x69\x63\x69\x6c\x65" ) );
    labelEtatCivilTelephone_2->setText( trUtf8( "\x54\xc3\xa9\x6c\x2e\x20\x70\x6f\x72\x74\x61\x62\x6c\x65" ) );
    textLabel2->setText( trUtf8( "\x43\x69\x76\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxEtatCivilCivilite->clear();
    comboBoxEtatCivilCivilite->insertItem( tr( "Mr." ) );
    comboBoxEtatCivilCivilite->insertItem( tr( "Melle" ) );
    comboBoxEtatCivilCivilite->insertItem( tr( "Mde" ) );
    labelEtatCivilNom->setText( tr( "Nom" ) );
    textLabel3_2->setText( tr( "Nom jeune fille" ) );
    labelEtatCivilPrenom->setText( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    labelEtatCivilDateNaissance->setText( tr( "Date de naissance" ) );
    textLabel1_4->setText( trUtf8( "\xc3\xa0" ) );
    labelEtatCivilRue->setText( tr( "<p align=\"center\"><b>Adresse personelle</b></p>" ) );
    textLabelEtatCivilVille->setText( tr( "Ville" ) );
    comboBoxBenefProspect->clear();
    comboBoxBenefProspect->insertItem( tr( "Prospect" ) );
    comboBoxBenefProspect->insertItem( trUtf8( "\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65" ) );
    lineEditEtatCivilEmail->setText( QString::null );
    lineEditEtatCivilEmail->setInputMask( QString::null );
    labelEtatCivilEmail->setText( tr( "<p align=\"right\">Email</p>" ) );
    labelEtatCivilRaisonSociale->setText( tr( "<p align=\"right\">Raison sociale</p>" ) );
    lineEditEtatCivilAdresseComplement->setText( QString::null );
    lineEditEtatCivilTelephonePortable->setText( tr( "...." ) );
    lineEditEtatCivilTelephonePortable->setInputMask( tr( "99.99.99.99.99;_" ) );
    lineEditEtatCivilTelephone->setInputMask( tr( "99.99.99.99.99;_" ) );
    lineEditEtatCivilCodePostal->setInputMask( tr( "00000; " ) );
    lineEditEtatCivilAdresseComplementGestion->setText( QString::null );
    lineEditEtatCivilCodePostalGestion->setInputMask( tr( "00000; " ) );
    lineEditEtatCivilTelephonePro->setInputMask( tr( "99.99.99.99.99;_" ) );
    lineEditEtatCivilTelephoneFax->setInputMask( tr( "99.99.99.99.99;_" ) );
    textLabelEtatCivilRue_2->setText( tr( "Nom de rue" ) );
    textLabelEtatCivilAdresseComplement_2->setText( trUtf8( "\x43\x6f\x6d\x70\x6c\xc3\xa9\x6d\x65\x6e\x74" ) );
    labelEtatCivilTelephone_3->setText( trUtf8( "\x54\xc3\xa9\x6c\x2e\x20\x70\x72\x6f" ) );
    textLabelCodePostal_2->setText( tr( "Code Postal" ) );
    labelEtatCivilTelephone_3_2->setText( tr( "Fax" ) );
    textLabelEtatCivilVille_2->setText( tr( "Ville" ) );
    labelEtatCivilRue_2->setText( tr( "<p align=\"center\"><b>Adresse de gestion</b></p>" ) );
    labelEtatCivilSituationFamilliale->setText( tr( "Situation familliale" ) );
    comboBoxEtatCivilSituationFamilliale->clear();
    comboBoxEtatCivilSituationFamilliale->insertItem( QString::null );
    comboBoxEtatCivilSituationFamilliale->insertItem( trUtf8( "\x4d\x61\x72\x69\xc3\xa9\x28\x65\x29" ) );
    comboBoxEtatCivilSituationFamilliale->insertItem( trUtf8( "\x43\xc3\xa9\x6c\x69\x62\x61\x74\x61\x69\x72\x65" ) );
    comboBoxEtatCivilSituationFamilliale->insertItem( tr( "Veuf(ve)" ) );
    comboBoxEtatCivilSituationFamilliale->insertItem( trUtf8( "\x44\x69\x76\x6f\x72\x63\xc3\xa9\x28\x65\x29" ) );
    comboBoxEtatCivilSituationFamilliale->insertItem( tr( "PACS" ) );
    comboBoxEtatCivilSituationFamilliale->insertItem( tr( "Union libre" ) );
    comboBoxEtatCivilSituationFamilliale->insertItem( tr( "Concubinage" ) );
    labelEtatCivilConseils->setText( tr( "<h2><p align=\"center\">Conseils</p></h2>" ) );
    labelEtatCivilExpertComptable_3->setText( tr( "Expert comptable" ) );
    labelEtatCivilNotaire_3->setText( tr( "Notaire" ) );
    labelEtatCivilAvocat_3->setText( tr( "Avocat" ) );
    labelEtatCivilCabinetComptable_3->setText( tr( "Cabinet" ) );
    labelEtatCivilEtude_3->setText( tr( "Etude" ) );
    labelEtatCivilCabinetAvocat_3->setText( tr( "Cabinet" ) );
    labelFamilleNom->setText( trUtf8( "\x4e\x6f\x6d\x20\x2f\x20\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    labelFamilleAdresse->setText( tr( "Adresse" ) );
    labelFamilleDateNaissance->setText( tr( "Date de naissance" ) );
    textLabelFamilleRue->setText( tr( "Nom de rue" ) );
    textLabelFamilleAdresseComplement->setText( trUtf8( "\x43\x6f\x6d\x70\x6c\xc3\xa9\x6d\x65\x6e\x74" ) );
    textLabelFamilleCodePostal->setText( tr( "Code Postal" ) );
    lineEditFamilleCodePostal->setInputMask( tr( "00000; " ) );
    textLabelFamilleVille->setText( tr( "Ville" ) );
    textLabel4->setText( trUtf8( "\xc3\xa0" ) );
    labelFamilleTelephone->setText( trUtf8( "\x54\xc3\xa9\x6c\x2e\x20\x64\x6f\x6d\x69\x63\x69\x6c\x65" ) );
    lineEditFamilleTelephone->setInputMask( tr( "00.00.00.00.00;_" ) );
    labelFamilleTelephone_2->setText( trUtf8( "\x54\xc3\xa9\x6c\x2e\x20\x70\x72\x6f" ) );
    lineEditFamilleEmail->setInputMask( tr( "X@X.A; " ) );
    labelFamilleEmail->setText( tr( "Email" ) );
    labelFamilleTelephone_3->setText( trUtf8( "\x54\xc3\xa9\x6c\x2e\x20\x70\x6f\x72\x74\x61\x62\x6c\x65" ) );
    labelFamilleTelephone_2_2->setText( tr( "Fax" ) );
    lineEditFamilleTelephonePro->setInputMask( tr( "00.00.00.00.00;_" ) );
    lineEditFamilleTelephonePortable->setInputMask( tr( "00.00.00.00.00;_" ) );
    lineEditFamilleTelephoneFax->setInputMask( tr( "00.00.00.00.00;_" ) );
    labelFamilleSalaireAnnuel->setText( trUtf8( "\x53\x61\x6c\x61\x69\x72\x65\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    labelFamilleBNC->setText( tr( "BNC" ) );
    labelFamilleBIC->setText( tr( "BIC" ) );
    labelFamilleRevenusFonciers->setText( trUtf8( "\x52\x65\x76\x65\x6e\x75\x73\x20\x66\x6f\x6e\x63\x69\x65\x72\x73\x20\x28\xe2\x82\xac\x29" ) );
    labelFamilleDividendes->setText( trUtf8( "\x44\x69\x76\x69\x64\x65\x6e\x64\x65\x73\x20\x28\xe2\x82\xac\x29" ) );
    labelFamilleAutresRevenus->setText( tr( "Autres revenus (BA...)" ) );
    comboBoxFamilleNetBrut->clear();
    comboBoxFamilleNetBrut->insertItem( tr( "Net" ) );
    comboBoxFamilleNetBrut->insertItem( tr( "Brut" ) );
    tabWidgetFamille->changeTab( tab, tr( "Etat Civil && revenus du conjoint" ) );
    labelFamilleDateMariage->setText( tr( "<p align=\"right\">Date du mariage</p>" ) );
    textLabel5->setText( tr( "<p align=\"right\">Rang de mariage</p>" ) );
    lineEditFamilleRgMariage->setInputMask( QString::null );
    labelFamilleRegimeMatrimonial->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x52\xc3\xa9\x67\x69\x6d\x65\x20\x6d\x61\x74\x72\x69\x6d\x6f\x6e\x69\x61\x6c\x3c\x2f\x70\x3e" ) );
    comboBoxFamilleRegimeMatrimonial->clear();
    comboBoxFamilleRegimeMatrimonial->insertItem( trUtf8( "\x43\x6f\x6d\x6d\x75\x6e\x61\x75\x74\xc3\xa9\x20\x61\x63\x71\x75\xc3\xaa\x74\x73" ) );
    comboBoxFamilleRegimeMatrimonial->insertItem( trUtf8( "\x50\x61\x72\x74\x69\x63\x69\x70\x61\x74\x69\x6f\x6e\x20\x61\x75\x78\x20\x61\x63\x71\x75\xc3\xaa\x74\x73" ) );
    comboBoxFamilleRegimeMatrimonial->insertItem( trUtf8( "\x43\x6f\x6d\x6d\x75\x6e\x61\x75\x74\xc3\xa9\x20\x75\x6e\x69\x76\x65\x72\x73\x65\x6c\x6c\x65" ) );
    comboBoxFamilleRegimeMatrimonial->insertItem( trUtf8( "\x53\xc3\xa9\x70\x61\x72\x61\x74\x69\x6f\x6e\x20\x64\x65\x20\x62\x69\x65\x6e\x73" ) );
    checkBoxFamilleDonationDernierVivant->setText( tr( "Donation au dernier vivant" ) );
    textLabel2_4->setText( tr( "Autres dispositions" ) );
    labelFamilleDureeMariages->setText( trUtf8( "\x44\x75\x72\xc3\xa9\x65\x20\x64\x65\x73\x20\x6d\x61\x72\x69\x61\x67\x65\x73\x20\x70\x72\xc3\xa9\x63\xc3\xa9\x64\x65\x6e\x74\x73\x20\x3a" ) );
    labelFamilleMonsieur->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65\x20\x3a\x3c\x2f\x70\x3e" ) );
    lineEditFamilleDureeMariagesPrecedentsMonsieur->setInputMask( QString::null );
    labelFamilleMadame->setText( tr( "<p align=\"right\">Conjoint :</p>" ) );
    lineEditFamilleDureeMariagesPrecedentsMadame->setInputMask( QString::null );
    labelFamilleNombreEnfants->setText( tr( "Nombre d'enfants :  Communs : " ) );
    lineEditFamilleNombreEnfantsCommuns->setText( QString::null );
    lineEditFamilleNombreEnfantsCommuns->setInputMask( QString::null );
    labelFamilleNombreEnfantsMonsieur->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65\x20\x3a\x3c\x2f\x70\x3e" ) );
    lineEditFamilleNombreEnfantsMonsieur->setText( QString::null );
    lineEditFamilleNombreEnfantsMonsieur->setInputMask( QString::null );
    labelFamilleNombreEnfantsMadame->setText( tr( "<p align=\"right\">Conjoint :</p>" ) );
    lineEditFamilleNombreEnfantsMadame->setText( QString::null );
    lineEditFamilleNombreEnfantsMadame->setInputMask( QString::null );
    textLabel3->setText( tr( "<h2><p align=\"center\">Enfants</p></h2>" ) );
    pushButtonEnfantPlus->setText( tr( "+" ) );
    pushButtonEnfantsMinus->setText( tr( "-" ) );
    listViewEnfants->header()->setLabel( 0, tr( "Nom" ) );
    listViewEnfants->header()->setLabel( 1, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listViewEnfants->header()->setLabel( 2, tr( "Date de naissance" ) );
    listViewEnfants->header()->setLabel( 3, tr( "A charge" ) );
    listViewEnfants->header()->setLabel( 4, trUtf8( "\x46\x69\x6e\x61\x6e\x63\x65\x6d\x65\x6e\x74\x20\x64\x65\x73\x20\xc3\xa9\x74\x75\x64\x65\x73" ) );
    listViewEnfants->header()->setLabel( 5, tr( "Notes" ) );
    labelFamilleDispositionsTestamentaires->setText( tr( "Dispositions testamentaires :" ) );
    labelFamilleDonationEntreEpoux->setText( trUtf8( "\x44\x6f\x6e\x61\x74\x69\x6f\x6e\x20\x65\x6e\x74\x72\x65\x20\xc3\xa9\x70\x6f\x75\x78\x20\x3a" ) );
    tabWidgetFamille->changeTab( tab_2, tr( "Situation familiale" ) );
    labelCarriereRevenus->setText( tr( "<h2><p align=\"center\">Revenus</p></h2>" ) );
    labelCarriereSalaireAnnuel->setText( trUtf8( "\x53\x61\x6c\x61\x69\x72\x65\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    labelCarriereBNC->setText( tr( "BNC" ) );
    labelCarriereBIC->setText( tr( "BIC" ) );
    labelCarriereRevenusFonciers->setText( trUtf8( "\x52\x65\x76\x65\x6e\x75\x73\x20\x66\x6f\x6e\x63\x69\x65\x72\x73\x20\x28\xe2\x82\xac\x29" ) );
    labelCarriereDividendes->setText( trUtf8( "\x44\x69\x76\x69\x64\x65\x6e\x64\x65\x73\x20\x28\xe2\x82\xac\x29" ) );
    labelCarriereAutresRevenus->setText( tr( "Autres revenus (BA...)" ) );
    comboBoxCarriereNetBrut->clear();
    comboBoxCarriereNetBrut->insertItem( tr( "Net" ) );
    comboBoxCarriereNetBrut->insertItem( tr( "Brut" ) );
    lineEditCarriereAutresRevenus->setInputMask( QString::null );
    lineEditCarriereDividendes->setInputMask( QString::null );
    lineEditCarriereBNC->setInputMask( QString::null );
    lineEditCarriereBIC->setInputMask( QString::null );
    lineEditCarriereSalaireAnnuel->setInputMask( QString::null );
    lineEditCarriereRevenusFonciers->setInputMask( QString::null );
    textLabel3_3->setText( tr( "Statut Pro" ) );
    textLabel5_3->setText( tr( "Employeur" ) );
    labelCarriereMontantImpot->setText( trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x64\x65\x20\x6c\x27\x69\x6d\x70\xc3\xb4\x74" ) );
    labelCarriereMontantImpotMonsieur->setText( tr( "Monsieur" ) );
    lineEditCarriereMontantImpotMonsieur->setInputMask( QString::null );
    labelCarriereMontantImpotMadame->setText( tr( "Madame" ) );
    lineEditCarriereMontantImpotMadame->setInputMask( tr( "000000000; " ) );
    labelCarriereISF->setText( tr( "ISF" ) );
    comboBoxCarriereISF->clear();
    comboBoxCarriereISF->insertItem( tr( "Oui" ) );
    comboBoxCarriereISF->insertItem( tr( "Non" ) );
    labelCarriereMontant->setText( tr( "Montant" ) );
    lineEditCarriereMontantISF->setInputMask( QString::null );
    labelCarriereCGA->setText( tr( "CGA/AGA" ) );
    comboBoxCarriereCGA->clear();
    comboBoxCarriereCGA->insertItem( tr( "Oui" ) );
    comboBoxCarriereCGA->insertItem( tr( "Non" ) );
    labelCarriereDeductions->setText( trUtf8( "\x44\xc3\xa9\x64\x75\x63\x74\x69\x6f\x6e\x73" ) );
    labelCarriereDeductionsMonsieur->setText( tr( "Monsieur" ) );
    lineEditCarriereDeductionsMonsieur->setInputMask( QString::null );
    labelCarriereDeductionMadame->setText( tr( "Madame" ) );
    lineEditCarriereDeductionsMadame->setInputMask( tr( "000000000; " ) );
    comboBoxRevenusMoisBilan->clear();
    comboBoxRevenusMoisBilan->insertItem( tr( "Janvier" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Fevrier" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Mars" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Avril" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Mai" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Juin" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Juillet" ) );
    comboBoxRevenusMoisBilan->insertItem( trUtf8( "\x41\x6f\xc3\xbb\x74" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Septembre" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Octobre" ) );
    comboBoxRevenusMoisBilan->insertItem( tr( "Novembre" ) );
    comboBoxRevenusMoisBilan->insertItem( trUtf8( "\x44\xc3\xa9\x63\x65\x6d\x62\x72\x65" ) );
    comboBoxStatutPro->clear();
    comboBoxStatutPro->insertItem( trUtf8( "\x53\x61\x6c\x61\x72\x69\xc3\xa9" ) );
    comboBoxStatutPro->insertItem( trUtf8( "\x53\x61\x6c\x61\x72\x69\xc3\xa9\x20\x43\x61\x64\x72\x65" ) );
    comboBoxStatutPro->insertItem( tr( "ETAM" ) );
    comboBoxStatutPro->insertItem( tr( "Fonctionnaire" ) );
    comboBoxStatutPro->insertItem( tr( "Artisan" ) );
    comboBoxStatutPro->insertItem( trUtf8( "\x43\x6f\x6d\x6d\x65\x72\xc3\xa7\x61\x6e\x74" ) );
    comboBoxStatutPro->insertItem( trUtf8( "\x4c\x69\x62\xc3\xa9\x72\x61\x6c" ) );
    comboBoxStatutPro->insertItem( tr( "Exploitant agricole" ) );
    textLabel4_3->setText( tr( "Mois du bilan" ) );
    labelCarriereFiscalite->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    textLabel6->setText( tr( "Profession" ) );
    labelCarriereEmplois->setText( tr( "<h2><p align=\"center\">Emplois</p></h2>" ) );
    pushButtonCarriereEmploiPlus->setText( tr( "+" ) );
    pushButtonCarriereEmploiMinus->setText( tr( "-" ) );
    listViewCarriereEmploi->header()->setLabel( 0, trUtf8( "\x44\x61\x74\x65\x20\x64\x27\x65\x6e\x74\x72\xc3\xa9\x65" ) );
    listViewCarriereEmploi->header()->setLabel( 1, tr( "Date de sortie" ) );
    listViewCarriereEmploi->header()->setLabel( 2, trUtf8( "\x52\x65\x76\x65\x6e\x75\x73\x20\x28\xe2\x82\xac\x29" ) );
    listViewCarriereEmploi->header()->setLabel( 3, tr( "Points RCO" ) );
    listViewCarriereEmploi->header()->setLabel( 4, tr( "Status" ) );
    listViewCarriereEmploi->header()->setLabel( 5, tr( "Note" ) );
    labelCarriereAgeRetraite->setText( trUtf8( "\x41\x67\x65\x20\x64\x65\x20\x64\xc3\xa9\x70\x61\x72\x74\x20\x65\x6e\x20\x72\x65\x74\x72\x61\x69\x74\x65\x20\x73\x6f\x75\x68\x61\x69\x74\xc3\xa9" ) );
    lineEditCarriereAgeRetraite->setInputMask( QString::null );
    comboBoxPrevoyanceSanteSource->clear();
    comboBoxPrevoyanceSanteSource->insertItem( tr( "Amon" ) );
    comboBoxPrevoyanceSanteSource->insertItem( tr( "Concurrence" ) );
    checkBoxPrevoyanceSanteCaractereViagerEntreprise->setText( tr( "Entreprise" ) );
    lineEditPrevoyanceSanteNiveauGarantie->setInputMask( QString::null );
    labelPrevoyanceSanteCompagnie->setText( tr( "<p align=\"right\">Compagnie</p>" ) );
    labelPrevoyanceCotisationAnnuelle->setText( tr( "Cotisation annuelle" ) );
    labelPrevoyanceNiveauGarantie->setText( tr( "Niveau de garantie / TC" ) );
    textLabel1_5->setText( tr( "Source" ) );
    checkBoxPrevoyanceSanteCaractereViagerNon->setText( tr( "Non" ) );
    checkBoxPrevoyanceSanteCaractereViagerOui->setText( tr( "Oui" ) );
    labelPrevoyanceSanteFiscalite->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x70\x3e" ) );
    labelPrevoyanceSanteCaractereViager->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x43\x61\x72\x61\x63\x74\xc3\xa8\x72\x65\x20\x76\x69\x61\x67\x65\x72\x20\x3a\x3c\x2f\x70\x3e" ) );
    labelPrevoyanceSanteDateEffet->setText( tr( "Date d'effet" ) );
    lineEditPrevoyanceSanteCotisationAnnuelle->setInputMask( tr( "99999999; " ) );
    labelPrevoyanceIndiceSatisfaction->setText( tr( "<p align=\"right\">Indice de satisfaction</p>" ) );
    labelPrevoyanceBeneficiaires->setText( trUtf8( "\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65\x73" ) );
    lineEditPrevoyanceSanteIndiceSatisfaction->setInputMask( QString::null );
    labelPrevoyanceSanteContrat->setText( tr( "<p align=\"right\">Contrat</p>" ) );
    checkBoxPrevoyanceSanteCaractereViagerPersonnel->setText( tr( "Personnel" ) );
    comboBoxPrevoyanceSanteBeneficiaires->clear();
    comboBoxPrevoyanceSanteBeneficiaires->insertItem( trUtf8( "\x49\x73\x6f\x6c\xc3\xa9" ) );
    comboBoxPrevoyanceSanteBeneficiaires->insertItem( trUtf8( "\x49\x73\x6f\x6c\xc3\xa9\x20\x2b\x20\x65\x6e\x66\x61\x6e\x74\x73" ) );
    comboBoxPrevoyanceSanteBeneficiaires->insertItem( tr( "Famille" ) );
    textLabel1_6->setText( tr( "<b>Notes</b>" ) );
    tabWidget3->changeTab( tab_3, trUtf8( "\x53\x61\x6e\x74\xc3\xa9" ) );
    textLabel34->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    labelPrevoyanceSanteCapitauxInvalidite->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x43\x61\x70\x69\x74\x61\x75\x78\x20\x69\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x3a\x20\x20\x36\x36\x25\x20\x28\xe2\x82\xac\x29\x3c\x2f\x70\x3e" ) );
    lineEditPrevoyanceSanteCapitauxInvalidite->setInputMask( QString::null );
    labelPrevoyanceSanteInvalidite33->setText( trUtf8( "\x31\x30\x30\x25\x20\x28\xe2\x82\xac\x29" ) );
    labelPrevoyanceSanteInvaliditeMiseAJour->setText( trUtf8( "\x44\x65\x72\x6e\x69\xc3\xa8\x72\x65\x20\x6d\x69\x73\x65\x20\xc3\xa0\x20\x6a\x6f\x75\x72" ) );
    labelPrevoyanceSanteInvalidite66->setText( trUtf8( "\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x20\x36\x36\x25\x20\x28\xe2\x82\xac\x29" ) );
    labelPrevoyanceSanteMontantRente->setText( tr( "Montant de la rente" ) );
    labelPrevoyanceSanteInvalidite100->setText( trUtf8( "\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x20\x33\x33\x20\xc3\xa0\x20\x36\x36\x25\x20\x28\xe2\x82\xac\x29" ) );
    labelPrevoyanceSanteInvaliditeProfessionnelle->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x20\x70\x72\x6f\x66\x65\x73\x73\x69\x6f\x6e\x6e\x65\x6c\x6c\x65\x3c\x2f\x70\x3e" ) );
    lineEditPrevoyanceSanteInvalidite100->setInputMask( QString::null );
    lineEditPrevoyanceSanteInvalidite33->setInputMask( QString::null );
    comboBoxPrevoyanceSanteInvaliditeProfessionnelle->clear();
    comboBoxPrevoyanceSanteInvaliditeProfessionnelle->insertItem( tr( "Oui" ) );
    comboBoxPrevoyanceSanteInvaliditeProfessionnelle->insertItem( tr( "Non" ) );
    labelPrevoyanceSanteInvaliditeDateEffet->setText( tr( "<p align=\"right\">Date d'effet</p>" ) );
    lineEditPrevoyanceSanteInvalidite66->setInputMask( QString::null );
    comboBoxPrevoyanceSanteInvaliditeFiscalite->clear();
    comboBoxPrevoyanceSanteInvaliditeFiscalite->insertItem( tr( "Assurance vie" ) );
    comboBoxPrevoyanceSanteInvaliditeFiscalite->insertItem( tr( "Madelin" ) );
    labelPrevoyanceSanteInvaliditeCompagnie->setText( tr( "<p align=\"right\">Compagnie</p>" ) );
    labelPrevoyanceSanteInvaliditeFiscalite->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x70\x3e" ) );
    textLabel2_5->setText( tr( "<b>Notes</b>" ) );
    labelPrevoyanceSanteArretTravailAccordAssocies->setText( trUtf8( "\x41\x63\x63\x6f\x72\x64\x20\x65\x6e\x74\x72\x65\x20\x61\x73\x73\x6f\x63\x69\xc3\xa9\x73" ) );
    labelPrevoyanceSanteArretTravailDateEffet->setText( tr( "Date d'effet" ) );
    labelPrevoyanceSanteArretTravailDuree->setText( trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );
    comboBoxPrevoyanceSanteArretTravailAccordAssocies->clear();
    comboBoxPrevoyanceSanteArretTravailAccordAssocies->insertItem( tr( "Oui" ) );
    comboBoxPrevoyanceSanteArretTravailAccordAssocies->insertItem( tr( "Non" ) );
    labelPrevoyanceSanteArretTravailDateMiseAJour->setText( trUtf8( "\x44\x65\x72\x6e\x69\xc3\xa8\x72\x65\x20\x6d\x69\x73\x65\x20\xc3\xa0\x20\x6a\x6f\x75\x72" ) );
    lineEditPrevoyanceSanteArretTravailDuree->setInputMask( QString::null );
    pushButtonPrevoyanceArretTravailMinus->setText( tr( "-" ) );
    pushButtonPrevoyanceArretTravailPlus->setText( tr( "+" ) );
    listViewArretTravail->header()->setLabel( 0, trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x49\x4a\x20\x28\xe2\x82\xac\x29" ) );
    listViewArretTravail->header()->setLabel( 1, trUtf8( "\x46\x72\x61\x6e\x63\x68\x69\x73\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewArretTravail->header()->setLabel( 2, trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );
    labelPrevoyanceSanteContratArretTravail->setText( tr( "<p align=\"right\">Contrat</p>" ) );
    labelPrevoyanceSanteFranchises->setText( tr( "<b>Franchises</b>" ) );
    lineEditPrevoyanceSanteHospitalisation->setText( QString::null );
    lineEditPrevoyanceSanteHospitalisation->setInputMask( QString::null );
    lineEditPrevoyanceSanteMaladie->setInputMask( QString::null );
    labelPrevoyanceSanteCompagnieArretTravail->setText( tr( "<p align=\"right\">Compagnie</p>" ) );
    labelPrevoyanceanteHospitalisation->setText( tr( "Hospitalisation" ) );
    labelPrevoyanceSanteFiscaliteArretTravail->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x70\x3e" ) );
    labelPrevoyanceAccident->setText( tr( "<p align=\"right\">Accident</p>" ) );
    labelPrevoyanceSanteMaladie->setText( tr( "<p align=\"right\">Maladie</p>" ) );
    lineEditPrevoyanceSanteAccident->setInputMask( QString::null );
    comboBoxPrevoyanceSanteFiscaliteArretTravail->clear();
    comboBoxPrevoyanceSanteFiscaliteArretTravail->insertItem( tr( "Assurance vie" ) );
    comboBoxPrevoyanceSanteFiscaliteArretTravail->insertItem( tr( "Madelin" ) );
    labelPrevoyanceArretTravail->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x41\x72\x72\xc3\xaa\x74\x20\x64\x65\x20\x74\x72\x61\x76\x61\x69\x6c\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    tabWidget3->changeTab( TabPage, trUtf8( "\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x20\x2f\x20\x49\x6e\x63\x61\x70\x61\x63\x69\x74\xc3\xa9" ) );
    textLabelPrevoyanceDecesGarantie->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x47\x61\x72\x61\x6e\x74\x69\x65\x73\x20\x64\xc3\xa9\x63\xc3\xa8\x73\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    pushButtonPrevoyanceGarantieDecesPlus->setText( tr( "+" ) );
    pushButtonPrevoyanceGarantieDecesMinus->setText( tr( "-" ) );
    listViewGarantieDeces->header()->setLabel( 0, tr( "Capital" ) );
    listViewGarantieDeces->header()->setLabel( 1, tr( "Maladie" ) );
    listViewGarantieDeces->header()->setLabel( 2, tr( "Accident" ) );
    listViewGarantieDeces->header()->setLabel( 3, trUtf8( "\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x69\x61\x69\x72\x65" ) );
    listViewGarantieDeces->header()->setLabel( 4, trUtf8( "\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9" ) );
    listViewGarantieDeces->header()->setLabel( 5, tr( "Compagnie" ) );
    listViewGarantieDeces->header()->setLabel( 6, tr( "Date d'effet" ) );
    listViewGarantieDeces->header()->setLabel( 7, trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );
    labelPrevoyanceDecesRenteConjoint_2->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x52\x65\x6e\x74\x65\x20\xc3\xa9\x64\x75\x63\x61\x74\x69\x6f\x6e\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    textLabel1_7->setText( tr( "<b>Notes</b>" ) );
    labelPrevoyanceDecesRenteConjointCompagnie->setText( tr( "Compagnie" ) );
    labelPeevoyanceDecesRenteFiscalite->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x70\x3e" ) );
    labelPrevoyanceDecesRenteConjointDateEffet->setText( tr( "<p align=\"right\">Date d'effet</p>" ) );
    comboBoxPrevoyanceDecesRenteConjointFiscalite->clear();
    comboBoxPrevoyanceDecesRenteConjointFiscalite->insertItem( tr( "Assurance vie" ) );
    comboBoxPrevoyanceDecesRenteConjointFiscalite->insertItem( tr( "Madelin" ) );
    labelPeevoyanceDecesRenteMontant->setText( tr( "<p align=\"right\">Montant</p>" ) );
    lineEditPrevoyanceRenteConjointDuree->setInputMask( QString::null );
    labelPeevoyanceDecesRenteDuree->setText( trUtf8( "\x44\x75\x72\xc3\xa9\x65" ) );
    labelPrevoyanceDecesRenteEducationDateEffet->setText( tr( "<p align=\"right\">Date d'effet</p>" ) );
    pushButtonPrevoyanceRenteEducationPlus->setText( tr( "+" ) );
    pushButtonPrevoyanceRenteEducationMinus->setText( tr( "-" ) );
    labelPrevoyanceDecesRenteEducationFiscalite->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x70\x3e" ) );
    labelPrevoyanceDecesRenteEducationCompagnie->setText( tr( "<p align=\"right\">Compagnie</p>" ) );
    listViewRenteEducation->header()->setLabel( 0, trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x64\x65\x20\x6c\x61\x20\x72\x65\x6e\x74\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewRenteEducation->header()->setLabel( 1, tr( "Pourcentage salaire (%)" ) );
    listViewRenteEducation->header()->setLabel( 2, trUtf8( "\x41\x67\x65\x20\x64\xc3\xa9\x62\x75\x74" ) );
    listViewRenteEducation->header()->setLabel( 3, tr( "Age fin" ) );
    comboBoxPrevoyanceDecesRenteEducationFiscalite->clear();
    comboBoxPrevoyanceDecesRenteEducationFiscalite->insertItem( tr( "Assurance vie" ) );
    comboBoxPrevoyanceDecesRenteEducationFiscalite->insertItem( tr( "Madelin" ) );
    labelPrevoyanceDecesRenteConjoint->setText( tr( "<h2><p align=\"center\">Rente du conjoint</p></h2>" ) );
    tabWidget3->changeTab( TabPage_2, trUtf8( "\x44\xc3\xa9\x63\xc3\xa8\x73" ) );
    labelPrevoyanceSanteFraixGeneraux->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x46\x72\x61\x69\x73\x20\x67\xc3\xa9\x6e\xc3\xa9\x72\x61\x75\x78\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    labelPrevoyanceSanteCouvertureMensuelle->setText( tr( "Couverture mensuelle" ) );
    labelPrevoyanceSanteCompagnieFraisGeneraux->setText( tr( "Compagnie" ) );
    lineEditPrevoyanceSanteCouvertureMensuelle->setInputMask( QString::null );
    lineEditPrevoyanceSanteFranchise->setInputMask( QString::null );
    labelPrevoyanceSanteFranchise->setText( tr( "<p align=\"right\">Franchise</p>" ) );
    labelPrevoyanceSanteContratFraisGeneraux->setText( tr( "Contrat" ) );
    labelPrevoyanceSanteDureeFraisGeneraux->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x44\x75\x72\xc3\xa9\x65\x3c\x2f\x70\x3e" ) );
    textLabel31->setText( tr( "<h2><p align=\"center\">Converture d'emprunt</p></h2>" ) );
    pushButtonPrevoyanceEmpruntPlus->setText( tr( "+" ) );
    pushButtonPrevoyanceEmpruntMinus->setText( tr( "-" ) );
    listViewEmprunt->header()->setLabel( 0, tr( "Montant emprunt" ) );
    listViewEmprunt->header()->setLabel( 1, tr( "Franchise" ) );
    listViewEmprunt->header()->setLabel( 2, tr( "Banque" ) );
    listViewEmprunt->header()->setLabel( 3, trUtf8( "\x44\x61\x74\x65\x20\x64\xc3\xa9\x62\x75\x74" ) );
    listViewEmprunt->header()->setLabel( 4, tr( "Terme" ) );
    listViewEmprunt->header()->setLabel( 5, tr( "Taux moyen (%)" ) );
    listViewEmprunt->header()->setLabel( 6, tr( "Type emprunt" ) );
    textLabel1_8->setText( tr( "<b>Notes</b>" ) );
    tabWidget3->changeTab( tab_4, trUtf8( "\x46\x72\x61\x69\x73\x20\x67\xc3\xa9\x6e\xc3\xa9\x72\x61\x75\x78\x20\x2f\x20\x43\x6f\x75\x76\x65\x72\x74\x75\x72\x65\x20\x64\x27\x65\x6d\x70\x72\x75\x6e\x74" ) );
    textLabelEpargne->setText( tr( "<h2><p align=\"center\">Retraite</p></h2>" ) );
    pushButtonEpargneCapitalisationPlus->setText( tr( "+" ) );
    pushButtonEpargneCapitalisationMinus->setText( tr( "-" ) );
    listViewEpargne->header()->setLabel( 0, tr( "Type" ) );
    listViewEpargne->header()->setLabel( 1, tr( "Date effet" ) );
    listViewEpargne->header()->setLabel( 2, trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    listViewEpargne->header()->setLabel( 3, trUtf8( "\x45\x70\x61\x72\x67\x6e\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewEpargne->header()->setLabel( 4, tr( "A la date du" ) );
    listViewEpargne->header()->setLabel( 5, tr( "Contrat" ) );
    listViewEpargne->header()->setLabel( 6, tr( "Compagnie" ) );
    textLabelEpargne_2->setText( tr( "<h2><p align=\"center\">Assurance vie</p></h2>" ) );
    pushButtonEpargneAssurancePlus->setText( tr( "+" ) );
    pushButtonEpargneAssuranceMinus->setText( tr( "-" ) );
    listViewAssuranceVie->header()->setLabel( 0, tr( "Contrat" ) );
    listViewAssuranceVie->header()->setLabel( 1, tr( "Compagnie" ) );
    listViewAssuranceVie->header()->setLabel( 2, tr( "Date d'effet" ) );
    listViewAssuranceVie->header()->setLabel( 3, trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    listViewAssuranceVie->header()->setLabel( 4, tr( "Terme" ) );
    listViewAssuranceVie->header()->setLabel( 5, trUtf8( "\x4b\x20\x63\x6f\x6e\x73\x74\x69\x74\x75\xc3\xa9" ) );
    listViewAssuranceVie->header()->setLabel( 6, tr( "A la date" ) );
    listViewAssuranceVie->header()->setLabel( 7, tr( "DSK" ) );
    listViewAssuranceVie->header()->setLabel( 8, tr( "PEP" ) );
    listViewAssuranceVie->header()->setLabel( 9, tr( "MS" ) );
    listViewAssuranceVie->header()->setLabel( 10, trUtf8( "\x46\x64\x20\x28\xe2\x82\xac\x29" ) );
    textLabel14->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x52\xc3\xa9\x67\x75\x6c\x61\x72\x69\x74\xc3\xa9\xd\xa\x53\xc3\xa9\x63\x75\x72\x69\x74\xc3\xa9\x3c\x2f\x70\x3e" ) );
    textLabel13->setText( tr( "<p align=\"center\">Performance\n"
"Fluctuation</p>" ) );
    textLabel12->setText( trUtf8( "\x56\x6f\x74\x72\x65\x20\x73\x65\x6e\x73\x69\x62\x69\x6c\x69\x74\xc3\xa9\x20\x61\x75\x20\x72\x69\x73\x71\x75\x65\x20\x3a" ) );
    textLabelSensibilie->setText( tr( "0" ) );
    textLabel15->setText( tr( "Vos motivations" ) );
    comboBoxMotivation->clear();
    comboBoxMotivation->insertItem( trUtf8( "\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation->insertItem( trUtf8( "\x44\x69\x73\x70\x6f\x6e\x69\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation->insertItem( trUtf8( "\x53\xc3\xa9\x63\x75\x72\x69\x74\xc3\xa9" ) );
    comboBoxMotivation->insertItem( trUtf8( "\x52\x65\x6e\x74\x61\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_2->clear();
    comboBoxMotivation_2->insertItem( trUtf8( "\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_2->insertItem( trUtf8( "\x44\x69\x73\x70\x6f\x6e\x69\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_2->insertItem( trUtf8( "\x53\xc3\xa9\x63\x75\x72\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_2->insertItem( trUtf8( "\x52\x65\x6e\x74\x61\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_3->clear();
    comboBoxMotivation_3->insertItem( trUtf8( "\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_3->insertItem( trUtf8( "\x44\x69\x73\x70\x6f\x6e\x69\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_3->insertItem( trUtf8( "\x53\xc3\xa9\x63\x75\x72\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_3->insertItem( trUtf8( "\x52\x65\x6e\x74\x61\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_4->clear();
    comboBoxMotivation_4->insertItem( trUtf8( "\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_4->insertItem( trUtf8( "\x44\x69\x73\x70\x6f\x6e\x69\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_4->insertItem( trUtf8( "\x53\xc3\xa9\x63\x75\x72\x69\x74\xc3\xa9" ) );
    comboBoxMotivation_4->insertItem( trUtf8( "\x52\x65\x6e\x74\x61\x62\x69\x6c\x69\x74\xc3\xa9" ) );
    tabWidgetEpargne->changeTab( tab_5, tr( "Epargne (1/2)" ) );
    textLabelEpargne_2_2->setText( tr( "<h2><p align=\"center\">Comptes</p></h2>" ) );
    pushButtonEpargneComptePlus->setText( tr( "+" ) );
    pushButtonEpargneCompteMinus->setText( tr( "-" ) );
    listViewComptes->header()->setLabel( 0, tr( "Type" ) );
    listViewComptes->header()->setLabel( 1, tr( "Compagnie" ) );
    listViewComptes->header()->setLabel( 2, tr( "Date d'effet" ) );
    listViewComptes->header()->setLabel( 3, trUtf8( "\x49\x6e\x76\x2e\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    listViewComptes->header()->setLabel( 4, tr( "Terme" ) );
    listViewComptes->header()->setLabel( 5, trUtf8( "\x4b\x20\x28\xe2\x82\xac\x29" ) );
    listViewComptes->header()->setLabel( 6, tr( "A la date" ) );
    listViewComptes->header()->setLabel( 7, tr( "Rendement N - 1 (%)" ) );
    listViewComptes->header()->setLabel( 8, tr( "Commentaires" ) );
    textLabelEpargne_2_2_2->setText( tr( "<h2><p align=\"center\">Revenus</p></h2>" ) );
    pushButtonEpargneRevenusPlus->setText( tr( "+" ) );
    pushButtonEpargneRevenusMinus->setText( tr( "-" ) );
    listViewRevenus->header()->setLabel( 0, trUtf8( "\x44\xc3\xa9\x73\x69\x67\x6e\x61\x74\x69\x6f\x6e" ) );
    listViewRevenus->header()->setLabel( 1, trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    textLabelEpargne_2_2_2_2->setText( tr( "<h2><p align=\"center\">Charges</p></h2>" ) );
    pushButtonEpargneChargesPlus->setText( tr( "+" ) );
    pushButtonEpargneChargesMinus->setText( tr( "-" ) );
    listViewCharges->header()->setLabel( 0, trUtf8( "\x44\xc3\xa9\x73\x69\x67\x6e\x61\x74\x69\x6f\x6e" ) );
    listViewCharges->header()->setLabel( 1, trUtf8( "\x4d\x6f\x6e\x74\x61\x6e\x74\x20\x61\x6e\x6e\x75\x65\x6c\x20\x28\xe2\x82\xac\x29" ) );
    textLabel17_2->setText( tr( "<b>Total charges</b>" ) );
    textLabel17->setText( tr( "<b>Total revenus</b>" ) );
    textLabel17_2_2->setText( trUtf8( "\x3c\x68\x33\x3e\x43\x61\x70\x61\x63\x69\x74\xc3\xa9\x20\x64\x27\xc3\xa9\x70\x61\x72\x67\x6e\x65\x20\x28\x52\x65\x76\x65\x6e\x75\x73\x20\x2d\x20\x63\x68\x61\x72\x67\x65\x73\x29\x3c\x2f\x68\x33\x3e" ) );
    tabWidgetEpargne->changeTab( tab_6, tr( "Epargne (2/2)" ) );
    textLabel18->setText( tr( "<h1><p align=\"center\">Patrimoine</p></h1>" ) );
    textLabel7->setText( trUtf8( "\x3c\x68\x31\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x42\x65\x73\x6f\x69\x6e\x73\x20\x49\x64\x65\x6e\x74\x69\x66\x69\xc3\xa9\x73\x3c\x2f\x70\x3e\x3c\x2f\x68\x31\x3e" ) );
    textLabel8->setText( tr( "Retraite" ) );
    textLabel12_2->setText( tr( "Protection Patrimoine" ) );
    textLabel11->setText( tr( "Epargne" ) );
    textLabel10->setText( trUtf8( "\x53\x61\x6e\x74\xc3\xa9" ) );
    textLabel9->setText( trUtf8( "\x50\x72\xc3\xa9\x76\x6f\x79\x61\x6e\x63\x65" ) );
    textLabel13_2->setText( tr( "<b>Notes</b>" ) );
    textLabelListerFiltreNom->setText( tr( "Nom" ) );
    comboBoxSearchProspect->clear();
    comboBoxSearchProspect->insertItem( QString::null );
    comboBoxSearchProspect->insertItem( tr( "Prospect" ) );
    comboBoxSearchProspect->insertItem( tr( "Client" ) );
    textLabelListerFiltrePrenom->setText( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    pushButtonPersonneFiltreEffacer->setText( tr( "Effacer" ) );
    comboBoxSearchOp1->clear();
    comboBoxSearchOp1->insertItem( tr( "<" ) );
    comboBoxSearchOp1->insertItem( tr( ">" ) );
    comboBoxSearchOp1->insertItem( tr( "==" ) );
    comboBoxSearchOp1->insertItem( tr( "!=" ) );
    textLabelSearch1->setText( tr( "Param1" ) );
    textLabelSearch2->setText( tr( "Param2" ) );
    comboBoxSearchOp2->clear();
    comboBoxSearchOp2->insertItem( tr( "<" ) );
    comboBoxSearchOp2->insertItem( tr( ">" ) );
    comboBoxSearchOp2->insertItem( tr( "==" ) );
    comboBoxSearchOp2->insertItem( tr( "!=" ) );
    listView->header()->setLabel( 0, tr( "Nom" ) );
    listView->header()->setLabel( 1, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listView->header()->setLabel( 2, trUtf8( "\x54\xc3\xa9\x6c\xc3\xa9\x70\x68\x6f\x6e\x65" ) );
    listView->header()->setLabel( 3, tr( "Email" ) );
    listView->header()->setLabel( 4, tr( "Id" ) );
    pushButtonDossierEntreprise->setText( tr( "Dossier\n"
"entreprise" ) );
    pushButtonParticipants->setText( tr( "Participants" ) );
    pushButtonTNS->setText( tr( "T.N.S." ) );
    textLabel1_2->setText( tr( "Raison sociale" ) );
    textLabel6_2->setText( tr( "<p align=\"right\">Code NAF</p>" ) );
    lineEditCodeNaf->setInputMask( tr( "ddda; " ) );
    textLabel7_2->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x4e\x75\x6d\xc3\xa9\x72\x6f\x20\x64\x65\x20\x53\x49\x52\x45\x54\x3c\x2f\x70\x3e" ) );
    lineEditNumSiret->setInputMask( tr( "ddd ddd ddd ddddd;_" ) );
    textLabel8_2->setText( trUtf8( "\x41\x63\x74\x69\x76\x69\x74\xc3\xa9" ) );
    textLabel9_2->setText( tr( "Convention collective" ) );
    textLabel15_2_2->setText( tr( "<b><p align=\"center\">Ventilation du capital social</p></b>" ) );
    textLabel12_2_2->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x43\x6f\x6c\x6c\xc3\xa9\x67\x65\x20\x64\x65\x20\x67\xc3\xa9\x72\x61\x6e\x63\x65\x20\x28\x25\x29\x3c\x2f\x70\x3e" ) );
    lineEditColGer->setInputMask( QString::null );
    textLabel13_2_2->setText( tr( "<p align=\"right\">Proche (famille) (%)</p>" ) );
    lineEditProche->setInputMask( QString::null );
    textLabel14_2_2->setText( tr( "<p align=\"right\">Autre (%)</p>" ) );
    lineEditAutre->setInputMask( QString::null );
    textLabel16_2->setText( trUtf8( "\x3c\x62\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x42\xc3\xa9\x6e\xc3\xa9\x66\x69\x63\x65\x73\x20\x64\x69\x73\x74\x72\x69\x62\x75\xc3\xa9\x73\x3c\x2f\x70\x3e\x3c\x2f\x62\x3e" ) );
    textLabel17_3_3->setText( tr( "N-1" ) );
    lineEditBenefN1->setInputMask( QString::null );
    textLabel17_3_2_2->setText( tr( "<p align=\"right\">N-2</p>" ) );
    lineEditBenefN2->setInputMask( QString::null );
    textLabel18_2_2->setText( trUtf8( "\x3c\x62\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x52\xc3\xa9\x67\x69\x6d\x65\x20\x66\x69\x73\x63\x61\x6c\x3c\x2f\x70\x3e\x3c\x3c\x2f\x62\x3e" ) );
    comboBoxRegimeFiscal->clear();
    comboBoxRegimeFiscal->insertItem( trUtf8( "\x49\x6d\x70\xc3\xb4\x74\x73\x20\x73\x75\x72\x20\x6c\x65\x73\x20\x72\x65\x76\x65\x6e\x75\x73" ) );
    comboBoxRegimeFiscal->insertItem( trUtf8( "\x49\x6d\x70\xc3\xb4\x74\x73\x20\x73\x75\x72\x20\x6c\x65\x73\x20\x73\x6f\x63\x69\xc3\xa9\x74\xc3\xa9\x73" ) );
    textLabel2_2->setText( tr( "Forme juridique" ) );
    comboBoxFormeJuridique->clear();
    comboBoxFormeJuridique->insertItem( tr( "SARL" ) );
    comboBoxFormeJuridique->insertItem( tr( "SA" ) );
    comboBoxFormeJuridique->insertItem( tr( "SAS" ) );
    comboBoxFormeJuridique->insertItem( tr( "EURL" ) );
    comboBoxFormeJuridique->insertItem( tr( "SCP" ) );
    comboBoxFormeJuridique->insertItem( tr( "Autre" ) );
    textLabel3_2_2->setText( trUtf8( "\x53\x69\x20\x61\x75\x74\x72\x65\x20\x70\x72\xc3\xa9\x63\x69\x73\x65\x72" ) );
    textLabel1_9->setText( trUtf8( "\x44\x61\x74\x65\x20\x64\x65\x20\x63\x72\xc3\xa9\x61\x74\x69\x6f\x6e" ) );
    lineEditDateCreation->setInputMask( tr( "99/99/9999; " ) );
    comboBoxSuiteEco->clear();
    comboBoxSuiteEco->insertItem( tr( "oui" ) );
    comboBoxSuiteEco->insertItem( tr( "non" ) );
    textLabel2_6->setText( trUtf8( "\x53\x75\x69\x74\x65\x20\xc3\xa9\x63\x6f\x6e\x6f\x6d\x69\x71\x75\x65" ) );
    checkBoxAGA->setText( tr( "AGA" ) );
    checkBoxCGA->setText( tr( "CGA" ) );
    textLabelEtatCivilRue_2_2->setText( tr( "Nom de rue" ) );
    textLabelEtatCivilAdresseComplement_2_2->setText( trUtf8( "\x43\x6f\x6d\x70\x6c\xc3\xa9\x6d\x65\x6e\x74" ) );
    textLabel5_2->setText( tr( "Ville" ) );
    textLabel4_2->setText( trUtf8( "\x41\x64\x72\x65\x73\x73\x65\x20\x64\x75\x20\x73\x69\xc3\xa8\x67\x65\x20\x73\x6f\x63\x69\x61\x6c" ) );
    textLabelCodePostal_2_2->setText( tr( "Code Postal" ) );
    lineEditEntrepriseCodePostal->setInputMask( tr( "00000; " ) );
    lineEditTelEnses->setInputMask( tr( "99.99.99.99.99;_" ) );
    textLabel3_4->setText( trUtf8( "\x54\xc3\xa9\x6c\xc3\xa9\x70\x68\x6f\x6e\x65" ) );
    lineEditFaxEntses->setInputMask( tr( "99.99.99.99.99;_" ) );
    textLabel3_4_2->setText( tr( "Fax" ) );
    lineEdithttpentses->setText( tr( "Site internet" ) );
    textLabel20_2->setText( tr( "Nom" ) );
    textLabel7_3->setText( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    textLabel8_3->setText( tr( "Date Nais." ) );
    comboBoxPartsDirigeant->clear();
    comboBoxPartsDirigeant->insertItem( tr( "Majoritaire" ) );
    comboBoxPartsDirigeant->insertItem( tr( "Minoritaire" ) );
    comboBoxPartsDirigeant->insertItem( trUtf8( "\x41\x73\x73\x6f\x63\x69\xc3\xa9" ) );
    pushButtonDirigeantPlus->setText( tr( "+" ) );
    pushButtontDirigeantMinus->setText( tr( "-" ) );
    listViewDirigeants->header()->setLabel( 0, tr( "Nom" ) );
    listViewDirigeants->header()->setLabel( 1, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listViewDirigeants->header()->setLabel( 2, tr( "Date naissance" ) );
    listViewDirigeants->header()->setLabel( 3, tr( "Parts sociales" ) );
    listViewDirigeants->header()->setLabel( 4, tr( "Id" ) );
    textLabel19_2->setText( tr( "<h2><p align=\"center\">Dirigeants</p></h2>" ) );
    tabWidgetEntreprise->changeTab( tab_7, tr( "Votre entreprise" ) );
    lineEditNbCadres->setInputMask( QString::null );
    lineEditNbNonCadres->setInputMask( QString::null );
    textLabel22_2_2->setText( tr( "ETAM" ) );
    lineEditNbAutreColleges->setInputMask( QString::null );
    lineEditNbETAM->setInputMask( QString::null );
    textLabel22_4_2->setText( trUtf8( "\x41\x75\x74\x72\x65\x20\x63\x6f\x6c\x6c\xc3\xa8\x67\x65" ) );
    textLabel22_5->setText( tr( "Nombre de cadres" ) );
    textLabel22_3_2->setText( tr( "Nombre de non cadres" ) );
    textLabel23_3_2->setText( trUtf8( "\x49\x6e\x74\xc3\xa9\x72\x65\x73\x73\x65\x6d\x65\x6e\x74" ) );
    comboBoxDeleguePersonnel->clear();
    comboBoxDeleguePersonnel->insertItem( tr( "Oui" ) );
    comboBoxDeleguePersonnel->insertItem( tr( "Non" ) );
    textLabel23_4->setText( trUtf8( "\x44\xc3\xa9\x6c\xc3\xa9\x67\x75\xc3\xa9\x73\x20\x64\x75\x20\x70\x65\x72\x73\x6f\x6e\x6e\x65\x6c" ) );
    lineEditInteressementMod->setText( trUtf8( "\x4d\x6f\x64\x61\x6c\x69\x74\xc3\xa9\x73\x20\x64\x65\x20\x64\x69\x73\x74\x72\x69\x62\x75\x74\x69\x6f\x6e" ) );
    comboBoxInteressement->clear();
    comboBoxInteressement->insertItem( tr( "Oui" ) );
    comboBoxInteressement->insertItem( tr( "Non" ) );
    comboBoxComiteEntreprise->clear();
    comboBoxComiteEntreprise->insertItem( tr( "Oui" ) );
    comboBoxComiteEntreprise->insertItem( tr( "Non" ) );
    textLabel23_2_2->setText( trUtf8( "\x43\x6f\x6d\x69\x74\xc3\xa9\x20\x64\x27\x65\x6e\x74\x72\x65\x70\x72\x69\x73\x65" ) );
    textLabel25_2->setText( tr( "<b>Charges sociales</b>" ) );
    textLabel26_2->setText( tr( "<p align=\"right\">ARRCO</p>" ) );
    textLabel29_2_2->setText( tr( "<p align=\"center\">Part patronale (%)</p>" ) );
    textLabel27_2->setText( tr( "<p align=\"right\">AGIRC</p>" ) );
    textLabel29_3->setText( tr( "<p align=\"center\">Part salariales (%)</p>" ) );
    textLabel28_2->setText( tr( "<p align=\"right\">Autre</p>" ) );
    textLabel30_2_2->setText( tr( "<p align=\"right\">Taux accident du travail (%)</p>" ) );
    lineEditCaisseCongesPayes->setInputMask( QString::null );
    textLabel30_3_2->setText( tr( "<p align=\"right\">Taxe sur les transports</p>" ) );
    lineEditTauxAccidentTravail->setInputMask( QString::null );
    textLabel30_4->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x72\x69\x67\x68\x74\x22\x3e\x43\x61\x69\x73\x73\x65\x20\x63\x6f\x6e\x67\xc3\xa9\x73\x20\x70\x61\x79\xc3\xa9\x73\x20\x28\x25\x29\x3c\x2f\x70\x3e" ) );
    lineEditTaxeTransport->setInputMask( QString::null );
    tabWidgetEntreprise->changeTab( TabPage_3, trUtf8( "\x53\x61\x6c\x61\x72\x69\xc3\xa9\x73" ) );
    textLabel31_2_2->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x52\x65\x74\x72\x61\x69\x74\x65\x20\x26\x20\xc3\xa9\x70\x61\x72\x67\x6e\x65\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    pushButtonEntrepriseRetraitePlus->setText( tr( "+" ) );
    pushButtonEntrepriseRetraiteMinus->setText( tr( "-" ) );
    textLabel32_2->setText( trUtf8( "\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x3c\x62\x3e\x46\x69\x73\x63\x61\x6c\x69\x74\xc3\xa9\x3c\x2f\x62\x3e\x3c\x2f\x70\x3e" ) );
    listViewEntrepriseRetraite->header()->setLabel( 0, tr( "Contrat" ) );
    listViewEntrepriseRetraite->header()->setLabel( 1, tr( "Compagnie" ) );
    listViewEntrepriseRetraite->header()->setLabel( 2, trUtf8( "\x43\x6f\x6c\x6c\xc3\xa8\x67\x75\x65" ) );
    listViewEntrepriseRetraite->header()->setLabel( 3, tr( "TA (%)" ) );
    listViewEntrepriseRetraite->header()->setLabel( 4, tr( "TB (%)" ) );
    listViewEntrepriseRetraite->header()->setLabel( 5, tr( "TC (%)" ) );
    listViewEntrepriseRetraite->header()->setLabel( 6, tr( "Date d'effet" ) );
    listViewEntrepriseRetraite->header()->setLabel( 7, tr( "83" ) );
    listViewEntrepriseRetraite->header()->setLabel( 8, tr( "82AD" ) );
    listViewEntrepriseRetraite->header()->setLabel( 9, tr( "82SD" ) );
    listViewEntrepriseRetraite->header()->setLabel( 10, tr( "39" ) );
    textLabel33_2->setText( tr( "<p align=\"right\"><b>PEE</b>  Organisme</p>" ) );
    textLabel34_2_2->setText( tr( "Date d'effet" ) );
    textLabel35_2->setText( trUtf8( "\x49\x6e\x74\xc3\xa9\x72\xc3\xa9\x73\x73\x65\x6d\x65\x6e\x74" ) );
    comboBoxEntrepriseInteressement->clear();
    comboBoxEntrepriseInteressement->insertItem( tr( "Oui" ) );
    comboBoxEntrepriseInteressement->insertItem( tr( "Non" ) );
    textLabel36_3->setText( trUtf8( "\x56\x65\x72\x73\x65\x6d\x65\x6e\x74\x20\x4e\x2d\x31\x20\x28\xe2\x82\xac\x29" ) );
    lineEditRetraiteInteressementN1->setInputMask( QString::null );
    textLabel36_2_2->setText( trUtf8( "\x56\x65\x72\x73\x65\x6d\x65\x6e\x74\x20\x4e\x2d\x32\x20\x28\xe2\x82\xac\x29" ) );
    lineEditRetraiteInteressementN2->setInputMask( QString::null );
    tabWidgetEntreprise->changeTab( TabPage_4, trUtf8( "\x52\x65\x74\x72\x61\x69\x74\x65\x20\x26\x26\x20\xc3\xa9\x70\x61\x72\x67\x6e\x65" ) );
    textLabel2_7->setText( tr( "<h3><p align=\"center\">IJ</p></h3>" ) );
    textLabel3_5->setText( trUtf8( "\x3c\x68\x33\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x49\x6e\x76\x61\x6c\x69\x64\x69\x74\xc3\xa9\x3c\x2f\x70\x3e\x3c\x2f\x68\x33\x3e" ) );
    textLabel4_4->setText( tr( "<h3><p align=\"center\">Taux</p></h3>" ) );
    listViewPrevoyanceEntses->header()->setLabel( 0, tr( "Contrat" ) );
    listViewPrevoyanceEntses->header()->setLabel( 1, tr( "Compagnie" ) );
    listViewPrevoyanceEntses->header()->setLabel( 2, tr( "CVD (%)" ) );
    listViewPrevoyanceEntses->header()->setLabel( 3, tr( "M (%)" ) );
    listViewPrevoyanceEntses->header()->setLabel( 4, tr( "Maj/enf. (%)" ) );
    listViewPrevoyanceEntses->header()->setLabel( 5, tr( "Rente conjoint" ) );
    listViewPrevoyanceEntses->header()->setLabel( 6, trUtf8( "\x52\x65\x6e\x74\x65\x20\xc3\xa9\x64\x75\x63\x61\x74\x69\x6f\x6e" ) );
    listViewPrevoyanceEntses->header()->setLabel( 7, tr( "TA" ) );
    listViewPrevoyanceEntses->header()->setLabel( 8, tr( "TB" ) );
    listViewPrevoyanceEntses->header()->setLabel( 9, tr( "TC" ) );
    listViewPrevoyanceEntses->clear();
    QListViewItem * item = new QListViewItem( listViewPrevoyanceEntses, 0 );
    item->setText( 0, tr( "Non cadres" ) );

    item = new QListViewItem( listViewPrevoyanceEntses, item );
    item->setText( 0, tr( "Cadres" ) );

    listViewPrevoyance2Entses->header()->setLabel( 0, tr( "Contrat" ) );
    listViewPrevoyance2Entses->header()->setLabel( 1, tr( "Compagnie" ) );
    listViewPrevoyance2Entses->header()->setLabel( 2, tr( "Montant (%)" ) );
    listViewPrevoyance2Entses->header()->setLabel( 3, trUtf8( "\x46\x72\x61\x6e\x63\x68\x69\x73\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewPrevoyance2Entses->header()->setLabel( 4, trUtf8( "\x52\xc3\xa9\x64\x75\x69\x74\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewPrevoyance2Entses->header()->setLabel( 5, tr( "Montant (%)" ) );
    listViewPrevoyance2Entses->header()->setLabel( 6, trUtf8( "\x50\x61\x72\x74\x69\x65\x6c\x6c\x65\x20\x28\xe2\x82\xac\x29" ) );
    listViewPrevoyance2Entses->header()->setLabel( 7, tr( "TA" ) );
    listViewPrevoyance2Entses->header()->setLabel( 8, tr( "TB" ) );
    listViewPrevoyance2Entses->header()->setLabel( 9, tr( "TC" ) );
    listViewPrevoyance2Entses->clear();
    item = new QListViewItem( listViewPrevoyance2Entses, 0 );
    item->setText( 0, tr( "Non cadres" ) );

    item = new QListViewItem( listViewPrevoyance2Entses, item );
    item->setText( 0, tr( "Cadres" ) );

    pushButtonPrevoyanceEntsesMinus->setText( tr( "-" ) );
    pushButtonPrevoyanceEntsesPlus->setText( tr( "+" ) );
    textLabel5_4->setText( trUtf8( "\x3c\x68\x33\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x4b\x20\x64\xc3\xa9\x63\xc3\xa8\x73\x3c\x2f\x70\x3e\x3c\x2f\x68\x33\x3e" ) );
    textLabel6_3->setText( tr( "<h3><p align=\"center\">Taux</p></h3>" ) );
    pushButtonPrevoyance2EntsesMinus->setText( tr( "-" ) );
    pushButtonPrevoyance2EntsesPlus->setText( tr( "+" ) );
    textLabel1_10->setText( trUtf8( "\x3c\x68\x31\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x50\x72\xc3\xa9\x76\x6f\x79\x61\x6e\x63\x65\x3c\x2f\x70\x3e\x3c\x2f\x68\x31\x3e" ) );
    tabWidgetEntreprise->changeTab( TabPage_5, trUtf8( "\x52\xc3\xa9\x67\x69\x6d\x65\x73\x20\x63\x6f\x6d\x70\x6c\xc3\xa9\x6d\x65\x6e\x74\x61\x69\x72\x65\x73" ) );
    textLabel1_11->setText( tr( "Nom" ) );
    textLabel2_8->setText( trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    textLabel3_6->setText( tr( "Date de naissance" ) );
    pushButtonEnstesEmployePlus->setText( tr( "+" ) );
    pushButtonEnstesEmployeMinus->setText( tr( "-" ) );
    textLabel1_3->setText( tr( "<h2><p align=\"center\">Liste des participants</p></h2>" ) );
    listViewEntsesParticipants->header()->setLabel( 0, tr( "Nom" ) );
    listViewEntsesParticipants->header()->setLabel( 1, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listViewEntsesParticipants->header()->setLabel( 2, tr( "Date de naissance" ) );
    listViewEntsesParticipants->header()->setLabel( 3, tr( "Id" ) );
    textLabel2_3->setText( trUtf8( "\x3c\x68\x32\x3e\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x4c\x69\x73\x74\x65\x20\x64\x65\x20\x67\xc3\xa9\x72\x61\x6e\x74\x73\x20\x28\x54\x2e\x4e\x2e\x53\x29\x3c\x2f\x70\x3e\x3c\x2f\x68\x32\x3e" ) );
    listView29->header()->setLabel( 0, tr( "Nom" ) );
    listView29->header()->setLabel( 1, trUtf8( "\x50\x72\xc3\xa9\x6e\x6f\x6d" ) );
    listView29->header()->setLabel( 2, tr( "Date de naissance" ) );
    listView29->header()->setLabel( 3, tr( "Parts sociales" ) );
    listView29->header()->setLabel( 4, tr( "Id" ) );
    textLabelListerFiltreNom_2->setText( tr( "Raison Sociale" ) );
    textLabelListerFiltrePrenom_2->setText( tr( "Siret" ) );
    pushButtonListerFiltrerPlus_2->setText( tr( "+" ) );
    pushButtonEntsesFiltreEffacer->setText( tr( "Effacer" ) );
    listViewEntses->header()->setLabel( 0, tr( "Raison Sociale" ) );
    listViewEntses->header()->setLabel( 1, tr( "Siret" ) );
    listViewEntses->header()->setLabel( 2, tr( "Id" ) );
    filenew_itemOuvrir->setText( tr( "&Ouvrir" ) );
    filenew_itemOuvrir->setMenuText( tr( "&Ouvrir une autre base" ) );
    filenew_itemSauvegarder->setText( tr( "&Sauvegarder" ) );
    filenew_itemSauvegarder->setMenuText( tr( "&Sauvegarder" ) );
    filenew_itemQuitter->setText( tr( "&Quitter" ) );
    filenew_itemQuitter->setMenuText( tr( "&Quitter" ) );
    filenew_itemSauvegarderSous->setText( tr( "&Sauvegarder sous" ) );
    filenew_itemSauvegarderSous->setMenuText( tr( "&Sauvegarder sous" ) );
    help_itemAbout->setText( tr( "&A propos" ) );
    help_itemAbout->setMenuText( tr( "&A propos" ) );
    outils__itemPreferences->setText( trUtf8( "\x26\x50\x72\xc3\xa9\x66\xc3\xa9\x72\x65\x6e\x63\x65\x73" ) );
    outils__itemPreferences->setMenuText( trUtf8( "\x26\x50\x72\xc3\xa9\x66\xc3\xa9\x72\x65\x6e\x63\x65\x73" ) );
    menuChargerAction->setText( tr( "Charger" ) );
    menuChargerAction->setMenuText( tr( "Charger" ) );
    fichierImporterAction->setText( tr( "&Importer personnes" ) );
    fichierImporterAction->setMenuText( tr( "&Importer personnes" ) );
    filenew_itemSauvegarderSousnew_itemAction->setText( tr( "new item" ) );
    filenew_itemSauvegarderSousnew_itemAction->setMenuText( tr( "new item" ) );
    fichierExporterAction->setText( tr( "&Exporter" ) );
    fichierExporterAction->setMenuText( tr( "&Exporter" ) );
    if (MenuBar->findItem(1))
        MenuBar->findItem(1)->setText( tr( "&Fichier" ) );
    if (MenuBar->findItem(2))
        MenuBar->findItem(2)->setText( tr( "&Edition" ) );
    if (MenuBar->findItem(3))
        MenuBar->findItem(3)->setText( tr( "&Outils" ) );
    if (MenuBar->findItem(4))
        MenuBar->findItem(4)->setText( tr( "&Aide" ) );
}

