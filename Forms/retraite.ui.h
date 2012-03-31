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
#ifndef _RETRAITE_UI_H_
# define _RETRAITE_UI_H_

// QT
#include <qstring.h>
#include <qdatetimeedit.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "main.h"
#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CEntreprise.h"
#include "Forms/Dynamique.ui.h"
#include "Preferences/CPreferences.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgRetraite::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SRetraite *retraite = new struct SRetraite;

        retraite->dEffet_               = dateEditEffet->date();
        retraite->sCollegue_            = lineEditCollegue->text();
        retraite->pCompagnie_           = GET_COMP_FROM_TEXT( comboBoxCompagnie->currentText() );
        retraite->sContrat_             = lineEditContrat->text();
        retraite->usFisc39_             = get_ushort_from_qlineedit( lineEditFisc39 );
        retraite->usFisc82_             = get_ushort_from_qlineedit( lineEditFisc82 );
        retraite->usFisc82AD_           = get_ushort_from_qlineedit( lineEditFisc82AD );
        retraite->usFisc82SD_           = get_ushort_from_qlineedit( lineEditFisc82SD );
        retraite->usTA_                 = get_ushort_from_qlineedit( lineEditTA );
        retraite->usTB_                 = get_ushort_from_qlineedit( lineEditTB );
        retraite->usTC_                 = get_ushort_from_qlineedit( lineEditTC );

        // Adding in global list
        pCurrentEntreprise->listRetraites_.push_back( retraite );

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

#endif /* _RETRAITE_UI_H_ */
