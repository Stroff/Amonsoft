/****************************************************************************
** Form interface generated from reading ui file '.\Forms\garantiedeces.ui'
**
** Created: ven. 6. avr. 16:32:08 2007
**      by: The User Interface Compiler ($Id: garantiedeces.h,v 1.25 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGGARANTIEDECES_H
#define DLGGARANTIEDECES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QComboBox;
class QDateEdit;

class dlgGarantieDeces : public QDialog
{
    Q_OBJECT

public:
    dlgGarantieDeces( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgGarantieDeces();

    QPushButton* pushButtonKo;
    QPushButton* pushButtonOk;
    QLabel* labelPrevoyanceDecesCapital1;
    QLineEdit* lineEditPrevoyanceDecesCapital;
    QLabel* labelPrevoyanceDecesMaladie1;
    QLineEdit* lineEditPrevoyanceDecesMaladie;
    QLabel* labelPrevoyanceDecesAccident1;
    QLineEdit* lineEditPrevoyanceDecesAccident;
    QLabel* labelPrevoyanceDecesBeneficiaire1;
    QComboBox* comboBoxPrevoyanceDecesBeneficiaire;
    QLabel* labelPrevoyanceDecesAutre1;
    QLineEdit* lineEditPrevoyanceDecesPreciser;
    QLabel* labelPrevoyanceDecesFiscalite1;
    QLabel* labelPrevoyanceDecesCompagnie1;
    QLabel* labelPrevoyanceDecesDate1;
    QDateEdit* dateEditPrevoyanceDecesDateEffet;
    QLabel* labelPrevoyanceDecesDuree;
    QComboBox* comboBoxPrevoyanceDecesFiscalite;
    QComboBox* comboBoxPrevoyanceDecesCompagnie;
    QLineEdit* lineEditPrevoyanceDecesDuree;

protected:
    QGridLayout* dlgGarantieDecesLayout;
    QHBoxLayout* layout94;
    QHBoxLayout* layout95;

protected slots:
    virtual void languageChange();

    virtual void Ok();


};

#endif // DLGGARANTIEDECES_H
