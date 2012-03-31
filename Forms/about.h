/****************************************************************************
** Form interface generated from reading ui file '.\Forms\about.ui'
**
** Created: ven. 6. avr. 16:32:32 2007
**      by: The User Interface Compiler ($Id: about.h,v 1.30 2007/04/06 15:34:43 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DLGABOUT_H
#define DLGABOUT_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;

class dlgAbout : public QDialog
{
    Q_OBJECT

public:
    dlgAbout( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~dlgAbout();

    QLabel* textLabelAbout;

protected:
    QHBoxLayout* dlgAboutLayout;

protected slots:
    virtual void languageChange();

};

#endif // DLGABOUT_H
