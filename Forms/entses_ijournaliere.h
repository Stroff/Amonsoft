/****************************************************************************
** Form interface generated from reading ui file '.\Forms\entses_ijournaliere.ui'
**
** Created: ven. 6. avr. 17:19:50 2007
**      by: The User Interface Compiler ($Id: entses_ijournaliere.h,v 1.2 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGIJOURNALIERE_H
#define DLGIJOURNALIERE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;

class dlgIJournaliere : public QDialog
{
    Q_OBJECT

public:
    dlgIJournaliere( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgIJournaliere();

    QLabel* textLabel2;
    QComboBox* comboBoxTypeSal;
    QLineEdit* lineEditContrat;
    QComboBox* comboBoxCompagnie;
    QLabel* textLabel1;
    QPushButton* pushButtonko;
    QPushButton* pushButtonok;
    QLabel* textLabel13;
    QLabel* textLabel15;
    QLabel* textLabel16;
    QLabel* textLabel17;
    QLabel* textLabel20;
    QLineEdit* lineEditInvMontant;
    QLineEdit* lineEditInvPartielle;
    QLineEdit* lineEditIJMontant;
    QLineEdit* lineEditIJFranchise;
    QLineEdit* lineEditIJReduite;
    QLineEdit* lineEditTA;
    QLineEdit* lineEditTB;
    QLineEdit* lineEditTC;
    QLabel* textLabel11;
    QLabel* textLabel12;
    QLabel* textLabel14;
    QLabel* textLabel18;
    QLabel* textLabel19;

public slots:
    virtual void newSlot();

protected:
    QGridLayout* dlgIJournaliereLayout;
    QSpacerItem* spacer42;

protected slots:
    virtual void languageChange();

};

#endif // DLGIJOURNALIERE_H
