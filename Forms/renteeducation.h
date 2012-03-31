/****************************************************************************
** Form interface generated from reading ui file '.\Forms\renteeducation.ui'
**
** Created: ven. 6. avr. 16:32:06 2007
**      by: The User Interface Compiler ($Id: renteeducation.h,v 1.25 2007/04/06 15:34:45 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGRENTEEDUCATION_H
#define DLGRENTEEDUCATION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class dlgRenteEducation : public QDialog
{
    Q_OBJECT

public:
    dlgRenteEducation( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgRenteEducation();

    QLabel* pixmapLabel1;
    QLabel* textLabel1;
    QLineEdit* lineEditPrevoyanceDecesRenteEducationMontant;
    QLabel* textLabel1_2;
    QLineEdit* lineEditPrevoyanceDecesRenteEducationMontantPourcent;
    QLabel* labelPrevoyanceDecesRenteEducationDe;
    QLabel* labelPrevoyanceDecesRenteEducationAu;
    QLineEdit* lineEditPrevoyanceDecesRenteEducationAu;
    QLineEdit* lineEditPrevoyanceDecesRenteEducationDu;
    QPushButton* pushButtonOk;
    QPushButton* pushButtonKo;

public slots:
    virtual void Ok();

protected:
    QGridLayout* dlgRenteEducationLayout;

protected slots:
    virtual void languageChange();

};

#endif // DLGRENTEEDUCATION_H
