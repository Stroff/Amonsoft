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

#ifndef _EMPRUNT_UI_H_
# define _EMPRUNT_UI_H_

// QT
#include <qstring.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CPrevoyance.h"
#include "Forms/Dynamique.ui.h"


//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgEmprunt::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SCouvertureEmprunt *emprunt = new struct SCouvertureEmprunt;

        Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
        assert( pPrevoyance != 0 );

        emprunt->sBanque_               = lineEditEmpruntBanque->text();
        emprunt->uFranchise_            = get_uint_from_qlineedit( lineEditEmpruntFranchise );
        emprunt->uMontantRemboursement_ = get_uint_from_qlineedit( lineEditEmpruntMontant );
        emprunt->dDebut_		= lineEditEmpruntDateDebut->text();
        emprunt->usTerme_		= get_ushort_from_qlineedit( lineEditEmpruntTerme );
        emprunt->usTxMoyen_	= get_ushort_from_qlineedit( lineEditEmpruntTaux );
        emprunt->sTypeEmprunt_	= lineEditEmpruntType->text();

        // Adding in global list
        pPrevoyance->listCouvertureEmprunts_.push_back( emprunt );
        
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

#endif /* _EMPRUNT_UI_H_ */
