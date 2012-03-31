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

#ifndef _GARANTIEDECES_UI_H_
# define _GARANTIEDECES_UI_H_

// QT
#include <qstring.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>
#include <qmessagebox.h>

#include "main.h"
#include "exception.h"
#include "Preferences/CPreferences.h"
#include "Datas/defines.h"
#include "Datas/CPrevoyance.h"
#include "Forms/Dynamique.ui.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgGarantieDeces::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SGarantieDeces *garantie = new struct SGarantieDeces;

        Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
        assert( pPrevoyance != 0 );
        Datas::CDeces *pDeces = pPrevoyance->getDeces();
        assert( pDeces != 0 );

        garantie->dDateEffet_   = dateEditPrevoyanceDecesDateEffet->date();
        
        switch( comboBoxPrevoyanceDecesBeneficiaire->currentItem() )
        {
            case 0: garantie->eBeneficiaire_ = eFamille; break ;
            case 1: garantie->eBeneficiaire_ = eAssocie; break ;
            case 2: garantie->eBeneficiaire_ = eBanque; break ;
            case 3: garantie->eBeneficiaire_ = eEntreprise; break ;
            case 4: garantie->eBeneficiaire_ = eAutre; break ;
            default: qDebug( "garantieDeces::Ok() : Unsupported case" );
        }
        
        if( garantie->eBeneficiaire_ == eAutre )
            garantie->sOther_ = lineEditPrevoyanceDecesPreciser->text();

        garantie->uAccident_    = get_uint_from_qlineedit( lineEditPrevoyanceDecesAccident );
        garantie->pCompagnie_   = GET_COMP_FROM_TEXT(  comboBoxPrevoyanceDecesCompagnie->currentText() );
        garantie->eFiscalite_   = (enum eTypeFiscalite) comboBoxPrevoyanceDecesFiscalite->currentItem();
        garantie->uMaladie_     = get_uint_from_qlineedit( lineEditPrevoyanceDecesMaladie );
        garantie->uCapitaux_    = get_uint_from_qlineedit( lineEditPrevoyanceDecesCapital );
        garantie->uDuree_       = get_uint_from_qlineedit( lineEditPrevoyanceDecesDuree );

        // Adding in global list
        pDeces->listGarantiesDeces_.push_back( garantie );

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

#endif /* _GARANTIEDECES_UI_H_ */
