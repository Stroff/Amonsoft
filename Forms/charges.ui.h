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
#ifndef _CHARGES_UI_H_
# define _CHARGES_UI_H_

#include <qstring.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CEpargne.h"
#include "Forms/Dynamique.ui.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgCharges::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SRevenus *revenus = new struct SRevenus;

        Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
        assert( pEpargnes != 0 );

        revenus->sDesignation_   = lineEditDesignation->text();
        revenus->uMontant_       = get_uint_from_qlineedit( lineEditMontant );

        // Adding in global list
        pEpargnes->listCharges_.push_back( revenus );

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
#endif /* _CHARGES_UI_H_ */
