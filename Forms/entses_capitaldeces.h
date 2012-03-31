/****************************************************************************
** Form interface generated from reading ui file '.\Forms\entses_capitaldeces.ui'
**
** Created: ven. 6. avr. 17:19:52 2007
**      by: The User Interface Compiler ($Id: entses_capitaldeces.h,v 1.2 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGCAPITALDECES_H
#define DLGCAPITALDECES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;

class dlgCapitalDeces : public QDialog
{
    Q_OBJECT

public:
    dlgCapitalDeces( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgCapitalDeces();

    QLabel* textLabel1;
    QLabel* textLabel2;
    QLineEdit* lineEditTB;
    QLineEdit* lineEditTA;
    QLineEdit* lineEditTC;
    QLabel* textLabel10;
    QLabel* textLabel9;
    QLabel* textLabel8;
    QComboBox* comboBoxTypeSal;
    QLineEdit* lineEditContrat;
    QComboBox* comboBoxCompagnie;
    QLineEdit* lineEditRenteConjoint;
    QLabel* textLabel6;
    QLabel* textLabel7;
    QLineEdit* lineEditRenteEducation;
    QLabel* textLabel3;
    QLineEdit* lineEditCVD;
    QLabel* textLabel4;
    QLineEdit* lineEditM;
    QLineEdit* lineEditMaj;
    QLabel* textLabel5;
    QPushButton* pushButtonko;
    QPushButton* pushButtonok;

protected:
    QGridLayout* dlgCapitalDecesLayout;
    QSpacerItem* spacer40;

protected slots:
    virtual void languageChange();

    virtual void Ok();


};

#endif // DLGCAPITALDECES_H
