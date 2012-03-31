/****************************************************************************
** Form interface generated from reading ui file '.\Forms\emprunt.ui'
**
** Created: ven. 6. avr. 16:32:12 2007
**      by: The User Interface Compiler ($Id: emprunt.h,v 1.26 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGEMPRUNT_H
#define DLGEMPRUNT_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QPushButton;
class QLineEdit;

class dlgEmprunt : public QDialog
{
    Q_OBJECT

public:
    dlgEmprunt( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgEmprunt();

    QLabel* pixmapLabel2;
    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;
    QLineEdit* lineEditEmpruntFranchise;
    QLabel* textLabel3;
    QLineEdit* lineEditEmpruntMontant;
    QLabel* textLabel2;
    QLabel* textLabel1;
    QLabel* textLabel2_2;
    QLabel* textLabel3_2;
    QLabel* textLabel4;
    QLabel* textLabel5;
    QLineEdit* lineEditEmpruntType;
    QLineEdit* lineEditEmpruntBanque;
    QLineEdit* lineEditEmpruntTaux;
    QLineEdit* lineEditEmpruntTerme;
    QLineEdit* lineEditEmpruntDateDebut;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgEmpruntLayout;
    QSpacerItem* spacer31;

protected slots:
    virtual void languageChange();

};

#endif // DLGEMPRUNT_H
