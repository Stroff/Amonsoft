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

#ifndef _ENTSES_CAPITALDECES_UI_H_
# define _ENTSES_CAPITALDECES_UI_H_

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
void dlgCapitalDeces::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SCapitalDeces *capitalDeces = new struct SCapitalDeces;

        capitalDeces->eTypeSalarie_ = (t_eTypeSalarie) comboBoxTypeSal->currentItem();
        capitalDeces->sContrat_     = lineEditContrat->text();
        capitalDeces->pCompagnie_   = GET_COMP_FROM_TEXT( comboBoxCompagnie->currentText() );
        capitalDeces->usCDV_        = get_ushort_from_qlineedit( lineEditCVD );
        capitalDeces->usTA_         = get_ushort_from_qlineedit( lineEditTA );
        capitalDeces->usTB_         = get_ushort_from_qlineedit( lineEditTB );
        capitalDeces->usTC_         = get_ushort_from_qlineedit( lineEditTC );
        capitalDeces->usM_          = get_ushort_from_qlineedit( lineEditM );
        capitalDeces->usMaj_        = get_ushort_from_qlineedit( lineEditMaj );
        capitalDeces->uRenteConjoint_ = get_uint_from_qlineedit( lineEditRenteConjoint );
        capitalDeces->uRenteEdu_    = get_uint_from_qlineedit( lineEditRenteEducation );
        
        // Adding in global list
        pCurrentEntreprise->listCapitalDeces_.push_back( capitalDeces );

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

#endif /* _ENTSES_CAPITALDECES_UI_H_ */
