/****************************************************************************
** Form interface generated from reading ui file '.\Forms\Dynamique.ui'
**
** Created: sam. 8. oct. 22:30:38 2005
**      by: The User Interface Compiler ($Id: Dynamique.h,v 1.5 2007/02/06 19:04:46 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef AMONSOFT_H
#define AMONSOFT_H

#include <qvariant.h>

#include "Forms/amonsoft.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;

class AmonSoft : public dlgAmonSoft
{
    Q_OBJECT

public:
    AmonSoft( QWidget* parent = 0, const char* name = 0 );
    ~AmonSoft();


public slots:
    virtual void showEmprunt();
    virtual void showEmprunt( QListViewItem * );
    virtual void delEmprunt();
    virtual void showArretMaladie();
    virtual void showArretMaladie( QListViewItem * );
    virtual void delArretMaladie();
    virtual void showRenteEducation();
    virtual void showRenteEducation( QListViewItem * );
    virtual void delRenteEducation();
    virtual void showGarantieDeces();
    virtual void showGarantieDeces( QListViewItem * );
    virtual void delGarantieDeces();
    virtual void showEmploi();
    virtual void showEmploi( QListViewItem *);
    virtual void delEmploi();
    virtual void showEnfant();
    virtual void showEnfant( QListViewItem * );
    virtual void delEnfant();
    virtual void showEpargne();
    virtual void showEpargne( QListViewItem * );
    virtual void delEpargne();
    virtual void showAssuranceVie();
    virtual void showAssuranceVie( QListViewItem * );
    virtual void delAssuranceVie();
    virtual void showCompte();
    virtual void showCompte( QListViewItem * );
    virtual void delCompte();
    virtual void showRevenus();
    virtual void showRevenus( QListViewItem * );
    virtual void delRevenus();
    virtual void showCharges();
    virtual void showCharges( QListViewItem * );
    virtual void delCharges();
    virtual void showRetraite();
    virtual void showRetraite( QListViewItem * );
    virtual void delRetraite();
    virtual void showKDeces();
    virtual void showKDeces( QListViewItem * );
    virtual void delKdeces();
    virtual void showIJournalier();
    virtual void showIJournalier( QListViewItem * );
    virtual void delIJournalier();

protected:

protected slots:
    virtual void languageChange();

};

#endif // AMONSOFT_H
