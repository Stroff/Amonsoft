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

#ifndef _RENTEEDUCATION_UI_H_
# define _RENTEEDUCATION_UI_H_

// QT
#include <qstring.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qmessagebox.h>

#include "exception.h"
#include "Datas/defines.h"
#include "Datas/CPrevoyance.h"
#include "Forms/Dynamique.ui.h"

//----------------------------------------------------------------------------
// Validate choice
//----------------------------------------------------------------------------
void dlgRenteEducation::Ok()
{
    try
    {
        using namespace Datas;

        // Getting informations put in interface to Datas
        struct SRenteEducation *rente = new struct SRenteEducation;

        Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
        assert( pPrevoyance != 0 );
        Datas::CDeces *pDeces = pPrevoyance->getDeces();
        assert( pDeces != 0 );

        rente->uMontant_        = get_uint_from_qlineedit( lineEditPrevoyanceDecesRenteEducationMontant );
        rente->usPourcentageSalaire_ = get_ushort_from_qlineedit( lineEditPrevoyanceDecesRenteEducationMontantPourcent );
        rente->uAgeDebut_          = get_uint_from_qlineedit( lineEditPrevoyanceDecesRenteEducationDu );
        rente->uAgeFin_            = get_uint_from_qlineedit( lineEditPrevoyanceDecesRenteEducationAu );

        // Adding in global list
        pDeces->listRentesEducation_.push_back( rente );
        
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

#endif /* _RENTEEDUCATION_UI_H_ */
