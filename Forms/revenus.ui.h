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
#ifndef _REVENUS_UI_H_
# define _REVENUS_UI_H_

#include <qstring.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "Datas/defines.h"
#include "Datas/CEpargne.h"
#include "Forms/Dynamique.ui.h"
#include "exception.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgRevenus::Ok()
{
    try
    {
        using namespace Datas;

        CEpargnes   *pEpargne = pCurrentPersonne->getEpargne();
        assert( pEpargne != 0 );

        // Getting informations put in interface to Datas
        struct SRevenus *revenus = new struct SRevenus;

        revenus->sDesignation_   = lineEditDesignation->text();
        revenus->uMontant_       = get_uint_from_qlineedit( lineEditMontant );

        // Adding in global list
        pEpargne->listRevenus_.push_back( revenus );

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
#endif /* _REVENUS_UI_H_ */
