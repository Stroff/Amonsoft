/****************************************************************************
** Form interface generated from reading ui file '.\Forms\charges.ui'
**
** Created: ven. 6. avr. 16:32:15 2007
**      by: The User Interface Compiler ($Id: charges.h,v 1.24 2007/04/06 15:34:44 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGCHARGES_H
#define DLGCHARGES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QLabel;
class QPushButton;

class dlgCharges : public QDialog
{
    Q_OBJECT

public:
    dlgCharges( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgCharges();

    QLineEdit* lineEditDesignation;
    QLineEdit* lineEditMontant;
    QLabel* textLabel43;
    QLabel* textLabel44;
    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;

public slots:
    virtual void Ok();

protected:
    QVBoxLayout* dlgChargesLayout;
    QGridLayout* layout70;
    QHBoxLayout* layout72;

protected slots:
    virtual void languageChange();

};

#endif // DLGCHARGES_H
