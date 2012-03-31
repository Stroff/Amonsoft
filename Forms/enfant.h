/****************************************************************************
** Form interface generated from reading ui file '.\Forms\enfant.ui'
**
** Created: ven. 6. avr. 16:32:11 2007
**      by: The User Interface Compiler ($Id: enfant.h,v 1.24 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGENFANT_H
#define DLGENFANT_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QDateEdit;
class QPushButton;

class dlgEnfant : public QDialog
{
    Q_OBJECT

public:
    dlgEnfant( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgEnfant();

    QLabel* labelFamilleEnfantDateNaissance;
    QLineEdit* lineEditFamilleNom;
    QLabel* labelFamillePrenom;
    QComboBox* comboBoxFamilleEnfantAcharge;
    QLineEdit* lineEditFamillePrenom;
    QComboBox* comboBoxFamilleFinancementEtudes;
    QLabel* labelFamilleNotes;
    QLineEdit* lineEditFamilleNotes;
    QLabel* labelFamilleNom;
    QLabel* labelFamilleCharge;
    QDateEdit* dateEditFamilleEnfantDateNaissance;
    QLabel* labelFamilleFinancementEtudes;
    QPushButton* pushButtonKo;
    QPushButton* pushButtonOk;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgEnfantLayout;
    QGridLayout* layout378;

protected slots:
    virtual void languageChange();

};

#endif // DLGENFANT_H
