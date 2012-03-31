/****************************************************************************
** Form interface generated from reading ui file '.\Forms\arretmaladie.ui'
**
** Created: ven. 6. avr. 16:32:18 2007
**      by: The User Interface Compiler ($Id: arretmaladie.h,v 1.26 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGARRETMALADIE_H
#define DLGARRETMALADIE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class dlgArretMaladie : public QDialog
{
    Q_OBJECT

public:
    dlgArretMaladie( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgArretMaladie();

    QLabel* pixmapLabel2;
    QLabel* textLabel1;
    QLabel* textLabel2;
    QLineEdit* lineEditArretTravailMontant;
    QPushButton* pushButtonKo;
    QPushButton* pushButtonOk;
    QLineEdit* lineEditArretTravailFranchise;
    QLabel* textLabel3;
    QLineEdit* lineEditArretTravailDuree;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgArretMaladieLayout;

protected slots:
    virtual void languageChange();

};

#endif // DLGARRETMALADIE_H
