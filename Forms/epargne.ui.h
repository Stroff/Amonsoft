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
#ifndef _EPARGNE_UI_H_
# define _EPARGNE_UI_H_

// QT
#include <qstring.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qmessagebox.h>

#include "main.h"
#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CEpargne.h"
#include "Forms/Dynamique.ui.h"
#include "Preferences/CPreferences.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgEpargne::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SEpargne *epargne = new struct SEpargne;

        Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
        assert( pEpargnes != 0 );

        epargne->dEffet_    = dateEditDateEffet->date();
        epargne->dEpargne_  = dateEditDateEpargne->date();
        
        epargne->pCompagnie_ = GET_COMP_FROM_TEXT( comboBoxCompagnie->currentText() );
        epargne->sContrat_   = lineEditContrat->text();
        epargne->uEpargne_   = get_uint_from_qlineedit( lineEditEpargne );
        epargne->uInvAnnuel_ = get_uint_from_qlineedit( lineEditInvAnnuel );
        epargne->eType_ = (t_eTypeEpargne) comboBoxTypeEpargne->currentItem();

        // Adding in global list
        pEpargnes->listEpargnes_.push_back( epargne );

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

#endif /* _EPARGNE_UI_H_ */
