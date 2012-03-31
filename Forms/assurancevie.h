/****************************************************************************
** Form interface generated from reading ui file '.\Forms\assurancevie.ui'
**
** Created: ven. 6. avr. 16:32:16 2007
**      by: The User Interface Compiler ($Id: assurancevie.h,v 1.24 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGASSURANCEVIE_H
#define DLGASSURANCEVIE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QLabel;
class QPushButton;
class QDateEdit;
class QComboBox;

class dlgAssuranceVie : public QDialog
{
    Q_OBJECT

public:
    dlgAssuranceVie( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgAssuranceVie();

    QLineEdit* lineEditPEP;
    QLabel* textLabel33_2;
    QLabel* textLabel33_3;
    QLineEdit* lineEditMS;
    QLineEdit* lineEditFD;
    QLineEdit* lineEditDSK;
    QLabel* textLabel33_4;
    QLabel* textLabel33;
    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;
    QLabel* textLabel29;
    QLineEdit* lineEditContrat;
    QLabel* textLabel26;
    QDateEdit* dateEditDateCapital;
    QLabel* textLabel30;
    QLineEdit* lineEditTerme;
    QDateEdit* dateEditEffet;
    QLabel* textLabel27;
    QLineEdit* lineEditCapital;
    QLabel* textLabel31;
    QLabel* textLabel32;
    QLineEdit* lineEditInvAnnuel;
    QLabel* textLabel28;
    QComboBox* comboBoxCompagnie;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgAssuranceVieLayout;
    QGridLayout* layout61;
    QHBoxLayout* layout65;

protected slots:
    virtual void languageChange();

};

#endif // DLGASSURANCEVIE_H
