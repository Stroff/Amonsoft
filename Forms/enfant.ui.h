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
#ifndef _ENFANT_UI_H_
# define _ENFANT_UI_H_

// QT
#include <qstring.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qmessagebox.h>

#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CFamille.h"
#include "Forms/Dynamique.ui.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgEnfant::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        CEnfants *enfant = new CEnfants(
                        lineEditFamilleNom->text(),
                        lineEditFamillePrenom->text(),
                        dateEditFamilleEnfantDateNaissance->date(),
                        comboBoxFamilleEnfantAcharge->currentItem() == 0 ? true : false,
                        comboBoxFamilleFinancementEtudes->currentItem() == 0 ? true : false,
                        lineEditFamilleNotes->text() );

        // Adding in global list
        Datas::CFamille *pFamille = pCurrentPersonne->getFamille();

        if( pFamille != 0 )
        {
            pFamille->listEnfants_.push_back( enfant );
        }
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

#endif /* _ENFANT_UI_H_ */
