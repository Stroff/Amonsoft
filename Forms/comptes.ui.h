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
#ifndef _COMPTES_UI_H_
# define _COMPTES_UI_H_

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
void dlgComptes::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SComptes *compte = new struct SComptes;

        Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
        assert( pEpargnes != 0 );

        compte->dCapital_       = dateEditCapital->date();
        compte->dEffet_         = dateEditDateEffet->date();

        switch( comboBoxType->currentItem() )
        {
            case 0: compte->eType_ = eCodevi; break ;
            case 1: compte->eType_ = ePEL; break ;
            case 2: compte->eType_ = eCEL; break ;
            case 3: compte->eType_ = eSICAV; break ;
            case 4: compte->eType_ = eObligations; break ;
            case 5: compte->eType_ = eActions; break ;
            case 6: compte->eType_ = ePEA; break ;
            case 7: compte->eType_ = ePEP; break ;
            case 8: compte->eType_ = eOPCVM; break ;
            default: qDebug( "dlgComptes::Ok() : Unsupported case" );
        }    

        compte->pCompagnie_     = GET_COMP_FROM_TEXT( comboBoxCompagnie->currentText() );
        compte->sNotes_         = lineEditCommentaire->text();
        compte->sTerme_         = lineEditTerme->text();
        compte->uCapital_       = get_uint_from_qlineedit( lineEditCapital );
        compte->uInvAnnuel_     = get_uint_from_qlineedit( lineEditInvAnnuel );
        compte->usRendement_    = lineEditRendement->text().toUShort();

        // Adding in global list
        pEpargnes->listComptes_.push_back( compte );

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

#endif /* _COMPTES_UI_H_ */
