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
#ifndef _ASSURANCEVIE_UI_H_
# define _ASSURANCEVIE_UI_H_

// QT
#include <qstring.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
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
void dlgAssuranceVie::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SAssuranceVie *assurance = new struct SAssuranceVie;

        Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
        assert( pEpargnes != 0 );

        assurance->dCapital_    = dateEditDateCapital->date();
        assurance->dEffet_      = dateEditEffet->date();
        assurance->pCompagnie_  = GET_COMP_FROM_TEXT( comboBoxCompagnie->currentText() );
        assurance->sContrat_    = lineEditContrat->text();
        assurance->sTerme_      = lineEditTerme->text();
        assurance->uCapital_    = get_uint_from_qlineedit( lineEditCapital );
        assurance->uDSK_        = get_uint_from_qlineedit( lineEditDSK );
        assurance->uFD_         = get_uint_from_qlineedit( lineEditFD );
        assurance->uInvAnnuel_  = get_uint_from_qlineedit( lineEditInvAnnuel );
        assurance->uMS_         = get_uint_from_qlineedit( lineEditMS );
        assurance->uPEP_        = get_uint_from_qlineedit( lineEditPEP );

        // Adding in global list
        pEpargnes->listAssurancesVie_.push_back( assurance );

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

#endif /* _ASSURANCEVIE_UI_H_ */
