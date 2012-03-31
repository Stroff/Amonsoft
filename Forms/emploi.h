/****************************************************************************
** Form interface generated from reading ui file '.\Forms\emploi.ui'
**
** Created: ven. 6. avr. 16:32:13 2007
**      by: The User Interface Compiler ($Id: emploi.h,v 1.26 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGEMPLOI_H
#define DLGEMPLOI_H

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

class dlgEmploi : public QDialog
{
    Q_OBJECT

public:
    dlgEmploi( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgEmploi();

    QLabel* labelCarriereRCO;
    QLineEdit* lineEditCarriereEmploisPoints;
    QLabel* labelCarriereNotes;
    QLineEdit* lineEditCarriereEmploisNotes;
    QLabel* labelCarriereStatut;
    QComboBox* comboBoxCarriereEmploiStatut;
    QLabel* labelCarriereRevenus1;
    QLineEdit* lineEditCarriereEmploisRevenus;
    QLabel* labelCarriereDu;
    QDateEdit* dateEditCarriereEmploisDu;
    QLabel* labelCarriereAu;
    QDateEdit* dateEditCarriereEmploisAu;
    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;

public slots:
    virtual void Ok();

protected:
    QVBoxLayout* dlgEmploiLayout;
    QGridLayout* layout239;
    QHBoxLayout* layout233;
    QHBoxLayout* layout234;
    QHBoxLayout* layout231;
    QHBoxLayout* layout232;
    QHBoxLayout* layout229;
    QHBoxLayout* layout230;

protected slots:
    virtual void languageChange();

};

#endif // DLGEMPLOI_H
