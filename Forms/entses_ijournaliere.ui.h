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

#ifndef _ENTSES_IJOURNALIERE_UI_H_
# define _ENTSES_IJOURNALIERE_UI_H_

#include <qstring.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "Datas/defines.h"
#include "Datas/CEntreprise.h"
#include "Forms/Dynamique.ui.h"
#include "exception.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgIJournaliere::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SIJournaliere *IJ = new struct SIJournaliere;

        IJ->eTypeSalarie_ = (t_eTypeSalarie) comboBoxTypeSal->currentItem();
        IJ->sContrat_     = lineEditContrat->text();
        IJ->pCompagnie_   = GET_COMP_FROM_TEXT( comboBoxCompagnie->currentText() );        
        IJ->usTA_         = get_ushort_from_qlineedit( lineEditTA );
        IJ->usTB_         = get_ushort_from_qlineedit( lineEditTB );
        IJ->usTC_         = get_ushort_from_qlineedit( lineEditTC );
        IJ->usIJMontant_  = get_ushort_from_qlineedit( lineEditIJMontant );
        IJ->uIJReduite_   = get_uint_from_qlineedit( lineEditIJReduite );
        IJ->uIJFranchise_ = get_uint_from_qlineedit( lineEditIJFranchise );
        IJ->usInvMontant_ = get_ushort_from_qlineedit( lineEditInvMontant );
        IJ->uInvPartielle_= get_ushort_from_qlineedit( lineEditInvPartielle );
        
        // Adding in global list
        pCurrentEntreprise->listIJournaliere_.push_back( IJ );

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

#endif /* _ENTSES_IJOURNALIERE_UI_H_ */