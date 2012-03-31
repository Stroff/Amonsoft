/****************************************************************************
** Form interface generated from reading ui file '.\Forms\preferences.ui'
**
** Created: ven. 6. avr. 16:32:07 2007
**      by: The User Interface Compiler ($Id: preferences.h,v 1.21 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGPREFERENCES_H
#define DLGPREFERENCES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QListBox;
class QListBoxItem;
class QWidgetStack;
class QWidget;
class QLabel;
class QComboBox;
class QLineEdit;
class QListView;
class QListViewItem;

class dlgPreferences : public QDialog
{
    Q_OBJECT

public:
    dlgPreferences( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgPreferences();

    QPushButton* buttonOk;
    QPushButton* buttonCancel;
    QListBox* listBox;
    QWidgetStack* widgetStack1;
    QWidget* WStackPage;
    QLabel* textLabel1_2;
    QLabel* textLabel2;
    QLabel* textLabel4;
    QLabel* textLabel3;
    QComboBox* comboBoxCompagnieType;
    QLineEdit* lineEditCompagnieDenomination;
    QLineEdit* lineEditCompagnieContact;
    QListView* listViewCompagnies;
    QPushButton* pushButtonCompagnieValider;
    QPushButton* pushButtonCompagnieSupprimer;
    QWidget* WStackPage_2;
    QLabel* textLabel1;
    QLabel* textLabel1_3;
    QWidget* WStackPage_3;
    QLabel* textLabel5;
    QLabel* textLabel6;
    QListView* listViewComptes;
    QPushButton* pushButtonComptesValider;
    QPushButton* pushButtonComptesSupprimer;
    QLineEdit* lineEditCompteNom;
    QWidget* WStackPage_4;
    QLabel* textLabel5_2;
    QListView* listViewEpargnes;
    QPushButton* pushButtonEpargneValider;
    QPushButton* pushButtonEpargneSupprimer;
    QLineEdit* lineEditEpargneNom;
    QLabel* textLabel7;
    QWidget* WStackPage_5;
    QLabel* textLabel1_4;
    QLabel* textLabel2_2;
    QListView* listViewBureau;
    QLabel* textLabel3_2;
    QLineEdit* lineEditNomEtude;
    QLabel* textLabel4_2;
    QComboBox* comboBoxTypeEtude;
    QPushButton* pushButtonValiderBureau;
    QPushButton* pushButtonSupprimerEtude;
    QLabel* textLabel5_3;
    QListView* listViewConseillers;
    QLabel* textLabel6_2;
    QLineEdit* lineEditNomConseillers;
    QPushButton* pushButtonValiderConseillers;
    QPushButton* pushButtonSupprimerConseillers;

public slots:
    virtual void listBox_selectionChanged( QListBoxItem * item );
    virtual void listViewCompagnies_selectionChanged( QListViewItem * item );
    virtual void pushButtonCompagnieValider_clicked();
    virtual void pushButtonCompagnieSupprimer_clicked();
    virtual void listViewEpargnes_selectionChanged( QListViewItem * item );
    virtual void pushButtonEpargneValider_clicked();
    virtual void pushButtonEpargneSupprimer_clicked();
    virtual void listViewComptes_selectionChanged( QListViewItem * item );
    virtual void pushButtonComptesValider_clicked();
    virtual void pushButtonComptesSupprimer_clicked();
    virtual void listViewBureau_selectionChanged( QListViewItem * );
    virtual void listViewConseillers_selectionChanged( QListViewItem * );
    virtual void pushButtonValiderBureau_clicked();
    virtual void pushButtonSupprimerEtude_clicked();
    virtual void pushButtonValiderConseillers_clicked();
    virtual void pushButtonSupprimerConseillers_clicked();

protected:
    QGridLayout* dlgPreferencesLayout;
    QHBoxLayout* Layout1;
    QSpacerItem* Horizontal_Spacing2;
    QGridLayout* WStackPageLayout;
    QSpacerItem* spacer33;
    QGridLayout* WStackPageLayout_2;
    QSpacerItem* spacer64;
    QGridLayout* WStackPageLayout_3;
    QSpacerItem* spacer64_2;
    QVBoxLayout* WStackPageLayout_4;
    QHBoxLayout* layout2;
    QHBoxLayout* layout3;
    QSpacerItem* spacer5;

protected slots:
    virtual void languageChange();

};

#endif // DLGPREFERENCES_H
