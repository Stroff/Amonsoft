/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#ifndef _ARRETMALADIE_UI_H
# define _ARRETMALADIE_UI_H

// QT
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qmessagebox.h>

#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CPrevoyance.h"
#include "Forms/Dynamique.ui.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgArretMaladie::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SArretTravail *arret = new struct SArretTravail;

        Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
        assert( pPrevoyance != 0 );
        Datas::CArretMaladie *pArret = pPrevoyance->getArretMaladie();
        assert( pArret != 0 );

        arret->uMontantIJ_              = get_uint_from_qlineedit( lineEditArretTravailMontant );
        arret->uFranchise_              = get_uint_from_qlineedit( lineEditArretTravailFranchise );
        arret->uDuree_                  = get_uint_from_qlineedit( lineEditArretTravailDuree );

        // Adding in global list
        pArret->listArretTravail_.push_back( arret );

        // Close dialog
        this->done( QDialog::Accepted  );
    }
    catch( CException &a )
    {
            QMessageBox::critical ( this,
                                    "Erreur durant la validation",
                                    a.cause(),
                                    QMessageBox::Ok,
                                    QMessageBox::NoButton );
    }
}

#endif /* _ARRETMALADIE_UI_H */
