/****************************************************************************
** Form interface generated from reading ui file '.\Forms\epargne.ui'
**
** Created: ven. 6. avr. 16:32:10 2007
**      by: The User Interface Compiler ($Id: epargne.h,v 1.25 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGEPARGNE_H
#define DLGEPARGNE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QDateEdit;
class QComboBox;

class dlgEpargne : public QDialog
{
    Q_OBJECT

public:
    dlgEpargne( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgEpargne();

    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;
    QLabel* textLabel20;
    QLineEdit* lineEditInvAnnuel;
    QLabel* textLabel22;
    QLabel* textLabel19;
    QLineEdit* lineEditContrat;
    QLabel* textLabel21;
    QLabel* textLabel25;
    QDateEdit* dateEditDateEpargne;
    QLabel* textLabel24;
    QLineEdit* lineEditEpargne;
    QComboBox* comboBoxTypeEpargne;
    QLabel* textLabel23;
    QDateEdit* dateEditDateEffet;
    QComboBox* comboBoxCompagnie;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgEpargneLayout;
    QHBoxLayout* layout58;

protected slots:
    virtual void languageChange();

};

#endif // DLGEPARGNE_H
