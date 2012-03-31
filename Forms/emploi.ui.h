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

#ifndef _EMPLOI_UI_H_
# define _EMPLOI_UI_H_

// QT
#include <qstring.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qmessagebox.h>

#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CCarriere.h"
#include "Forms/Dynamique.ui.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgEmploi::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SJobs *job = new struct SJobs;

        Datas::CCarriere *pCarriere = pCurrentPersonne->getCarriere();
        assert( pCarriere != 0 );

        job->dEntree_           = dateEditCarriereEmploisDu->date();
        job->dFin_              = dateEditCarriereEmploisAu->date();
        job->sNotes_            = lineEditCarriereEmploisNotes->text();
        job->uPointsRCO_        = get_uint_from_qlineedit( lineEditCarriereEmploisPoints );
        job->uRevenus_          = get_uint_from_qlineedit( lineEditCarriereEmploisRevenus );

        // Kind of jobs
        job->eStatut_ = (enum eStatutPro) comboBoxCarriereEmploiStatut->currentItem();

        // Adding in global list
        pCarriere->listEmplois_.push_back( job );

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

#endif /* _EMPLOI_UI_H_ */
