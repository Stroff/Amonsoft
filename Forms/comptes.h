/****************************************************************************
** Form interface generated from reading ui file '.\Forms\comptes.ui'
**
** Created: ven. 6. avr. 16:32:14 2007
**      by: The User Interface Compiler ($Id: comptes.h,v 1.23 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGCOMPTES_H
#define DLGCOMPTES_H

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

class dlgComptes : public QDialog
{
    Q_OBJECT

public:
    dlgComptes( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgComptes();

    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;
    QLabel* textLabel39;
    QLineEdit* lineEditCommentaire;
    QLineEdit* lineEditInvAnnuel;
    QLabel* textLabel35;
    QLabel* textLabel40;
    QLabel* textLabel34;
    QComboBox* comboBoxType;
    QLineEdit* lineEditRendement;
    QLineEdit* lineEditTerme;
    QLabel* textLabel37;
    QLabel* textLabel42;
    QLineEdit* lineEditCapital;
    QLabel* textLabel36;
    QLabel* textLabel41;
    QLabel* textLabel38;
    QDateEdit* dateEditDateEffet;
    QDateEdit* dateEditCapital;
    QComboBox* comboBoxCompagnie;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgComptesLayout;
    QHBoxLayout* layout65;

protected slots:
    virtual void languageChange();

};

#endif // DLGCOMPTES_H
