/****************************************************************************
** Form interface generated from reading ui file '.\Forms\retraite.ui'
**
** Created: ven. 6. avr. 16:32:04 2007
**      by: The User Interface Compiler ($Id: retraite.h,v 1.22 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGRETRAITE_H
#define DLGRETRAITE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QDateEdit;
class QPushButton;
class QComboBox;

class dlgRetraite : public QDialog
{
    Q_OBJECT

public:
    dlgRetraite( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgRetraite();

    QLabel* textLabel37;
    QLineEdit* lineEditContrat;
    QLabel* textLabel42;
    QDateEdit* dateEditEffet;
    QLabel* textLabel39;
    QLineEdit* lineEditCollegue;
    QLabel* textLabel47;
    QLineEdit* lineEditFisc82AD;
    QLineEdit* lineEditFisc82SD;
    QLabel* textLabel44;
    QLineEdit* lineEditFisc82;
    QLabel* textLabel45;
    QLineEdit* lineEditFisc39;
    QLabel* textLabel46;
    QLabel* textLabel40;
    QLineEdit* lineEditTB;
    QLineEdit* lineEditTC;
    QLabel* textLabel41_2;
    QLabel* textLabel41;
    QLineEdit* lineEditTA;
    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;
    QLabel* textLabel38;
    QComboBox* comboBoxCompagnie;
    QLabel* textLabel43;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgRetraiteLayout;
    QHBoxLayout* layout83;
    QHBoxLayout* layout81;
    QGridLayout* layout84;
    QGridLayout* layout82;
    QSpacerItem* spacer23;
    QHBoxLayout* layout65;

protected slots:
    virtual void languageChange();

};

#endif // DLGRETRAITE_H
