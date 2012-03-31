/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: Dynamique.ui.cpp,v 1.8 2007/02/06 19:04:46 pascal Exp $
* $Log: Dynamique.ui.cpp,v $
* Revision 1.8  2007/02/06 19:04:46  pascal
* - Début nouvelles Forms dans l'interface entreprise
* - Modification date validité
* - Ajout nouveaux fichiers pour les nouvelles Forms, il reste les liens Dynamique a créer
*
* Revision 1.7  2006/06/21 11:23:24  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.6  2006/04/29 16:29:29  pascal
* Version 0.1 build 13
* - Correction d'un bug avec les listes 'static' qui étaient partagées
* - Suppression des boutons "Valider" & "Rester"
* - Modification des images des boutons
* - Personnes et Entreprises ne sont plus manipulé que par Id
* - Correction de bug : suppression de la liste des retraites
* - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
*
* Revision 1.5  2006/03/21 10:42:20  pascal
* *** empty log message ***
*
* Revision 1.4  2006/01/20 13:18:48  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.3  2005/12/27 10:28:09  pascal
* - Release 1.0.6 (build 1 & 2)
* - Nouveaux champs pour les particuliers
* - Corrections de bugs chargement XML / sauvegarde XML
* - Corrections de bugs chargement QT / sauvegardes QT
* - Modification de l'installeur pour ne pas écraser les fichiers de données
* - Modification de la manière dont sont gérés les QDate
* - Correction du bug avec le slot DelAssuranceVie
* - TODO : màj
* - Liens bénéficiaire / prospect corrigés
*
* Revision 1.2  2005/10/11 08:08:43  pascal
* - Main.* ont été renommé amonsoft.*
* - la classe générée par QT Designer pour l'interface globale s'appelle maintenant dlgMain
* - AmonSoft est désormais définie dans les fichiers Dynamique.* est hérite de dlgMain
* - AmonSoft définie les actions liées aux formulaires annexes qui permettent de saisir les données
* - liens avec le parser pour les ouvertures et les sauvegardes
* - ouvrir un fichier devient ouvrir une autre base de donnée, par défaut on ouvre un fichier dans xml/
* - début de l'interface de préférence
* - les informations entreprises sont différenciées de celle des particuliers
* - ajout des listes permettant de retrouver les participants et les prospects
* - modifications de prévoyance suite à la demande du client
* - ajout de dlgRetraite
*
* Revision 1.1  2005/10/04 10:12:37  pascal
* - ajout des dialogues dlgArretMaladie, dlgEmploi, dlgEnfant, dlgGarantieDeces et dlgRenteEducation
* - renommage des dialogues avec le prefixe dlg
* - modification de l'interface principale pour qu'elle support les nouvelles fenêtre de dialogue et pour qu'elle affiche les informations ajoutées par ces dialogues dans des listView
* - nouvelles images pour les nouvelles fenêtre de dialogue
*
*
*/

// QT
#include <qpushbutton.h> 
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qcombobox.h>

// STL
#include <list>

#include "main.h"
#include "Dynamique.ui.h"

#include "Forms/emprunt.h"
#include "Forms/arretmaladie.h"
#include "Forms/renteeducation.h"
#include "Forms/garantiedeces.h"
#include "Forms/emploi.h"
#include "Forms/enfant.h"
#include "Forms/epargne.h"
#include "Forms/assurancevie.h"
#include "Forms/comptes.h"
#include "Forms/revenus.h"
#include "Forms/charges.h"
#include "Forms/retraite.h"
#include "Forms/entses_capitaldeces.h"

#include "Preferences/CPreferences.h"

// Includes Datas classes
#include "Datas/CDatas.h"
#include "Datas/CPersonnes.h"
#include "Datas/CPrevoyance.h"
#include "Datas/CCarriere.h"
#include "Datas/CFamille.h"
#include "Datas/CEpargne.h"
#include "Datas/CEntreprise.h"

//****************************************************************************
// Functions
//****************************************************************************
//----------------------------------------------------------------------------
// Show the dialog Emprunt
//----------------------------------------------------------------------------
void AmonSoft::showEmprunt()
{
    dlgEmprunt *emprunt = new dlgEmprunt();

    // We show and wait the dialog closed
    if( emprunt->exec() == QDialog::Accepted )
    {
        Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
        assert( pPrevoyance != 0 );

        // Get the latest insert item
        struct Datas::SCouvertureEmprunt *emprunt = pPrevoyance->listCouvertureEmprunts_.back();
        QString string;
        QListViewItem *item = new QListViewItem( listViewEmprunt,
            string.setNum( emprunt->uMontantRemboursement_ ),
            string.setNum( emprunt->uFranchise_ ),
            emprunt->sBanque_,
            emprunt->dDebut_,
            string.setNum( emprunt->usTerme_ ),
            string.setNum( emprunt->usTxMoyen_ ),
            emprunt->sTypeEmprunt_ );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showEmprunt( QListViewItem *current )
{
    dlgEmprunt *foo = new dlgEmprunt();
    struct Datas::SCouvertureEmprunt *pEmprunt = 0;
    QString string;

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();

    assert( pPrevoyance != 0 );

    Datas::t_listEmprunts::iterator ite;
    for( ite = pPrevoyance->listCouvertureEmprunts_.begin(); ite != pPrevoyance->listCouvertureEmprunts_.end(); ite++ )
    {
        if(     string.setNum( (*ite)->uMontantRemboursement_ ) == current->text( 0 )
            &&  string.setNum( (*ite)->uFranchise_ ) == current->text( 1 )
            &&  (*ite)->sBanque_ == current->text( 2 )
            &&  (*ite)->dDebut_ == current->text( 3 ) )
        {
            foo->lineEditEmpruntMontant->setText( string.setNum( (*ite)->uMontantRemboursement_ ) );
            foo->lineEditEmpruntFranchise->setText( string.setNum( (*ite)->uFranchise_ ) );
            foo->lineEditEmpruntBanque->setText( (*ite)->sBanque_ );
            foo->lineEditEmpruntDateDebut->setText( (*ite)->dDebut_ );
            foo->lineEditEmpruntTerme->setText( string.setNum( (*ite)->usTerme_ ) );
            foo->lineEditEmpruntTaux->setText( string.setNum( (*ite)->usTxMoyen_ ) );
            foo->lineEditEmpruntType->setText( (*ite)->sTypeEmprunt_ );

            pEmprunt = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pPrevoyance->listCouvertureEmprunts_.remove( pEmprunt );
        delete( pEmprunt );

        // Get the latest insert item
        struct Datas::SCouvertureEmprunt *emprunt = pPrevoyance->listCouvertureEmprunts_.back();

        current->setText( 0, string.setNum( emprunt->uMontantRemboursement_ ) );
        current->setText( 1, string.setNum( emprunt->uFranchise_ ) );
        current->setText( 2, emprunt->sBanque_ );
        current->setText( 3, emprunt->dDebut_ );
        current->setText( 4, string.setNum( emprunt->usTerme_ ) );
        current->setText( 5, string.setNum( emprunt->usTxMoyen_ ) );
        current->setText( 6, emprunt->sTypeEmprunt_ );
    }
}

//----------------------------------------------------------------------------
// Delete an emprunt
//----------------------------------------------------------------------------
void AmonSoft::delEmprunt()
{
    QListViewItem *item = listViewEmprunt->currentItem();

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();

    assert( pPrevoyance != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listEmprunts::iterator    ite;
    for( ite = pPrevoyance->listCouvertureEmprunts_.begin(); 
        ite != pPrevoyance->listCouvertureEmprunts_.end(); ite++ )
    {
        if(     (*ite)->sBanque_ == item->text( 2 )
            &&  (*ite)->uFranchise_ == item->text( 1 ).toUInt()
            &&  (*ite)->uMontantRemboursement_ == item->text( 0 ).toUInt() )
        {
            // We delete record
            pPrevoyance->listCouvertureEmprunts_.remove( *ite );
            listViewEmprunt->takeItem( item );
            delete item;
            /* delete *ite; */
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog ArretMaladie
//----------------------------------------------------------------------------
void AmonSoft::showArretMaladie()
{
    dlgArretMaladie *arret = new dlgArretMaladie();

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CArretMaladie *pArret = pPrevoyance->getArretMaladie();
    assert( pArret != 0 );

    // We show and wait the dialog closed
    if( arret->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SArretTravail *arret = pArret->listArretTravail_.back();
        QString string;
        QListViewItem *item = new QListViewItem( listViewArretTravail,
            string.setNum( arret->uMontantIJ_ ),
            string.setNum( arret->uFranchise_ ),
            string.setNum( arret->uDuree_ ) );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showArretMaladie( QListViewItem *current )
{
    dlgArretMaladie *foo = new dlgArretMaladie();
    struct Datas::SArretTravail *pArret = 0;
    QString string;

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CArretMaladie *pArretM = pPrevoyance->getArretMaladie();
    assert( pArretM != 0 );

    Datas::t_listArretTravail::iterator ite;
    for( ite = pArretM->listArretTravail_.begin(); ite != pArretM->listArretTravail_.end(); ite++ )
    {
        if(     string.setNum( (*ite)->uMontantIJ_ ) == current->text( 0 )
            &&  string.setNum( (*ite)->uFranchise_ ) == current->text( 1 )
            &&  string.setNum( (*ite)->uDuree_ ) == current->text( 2 ) )
        {
            foo->lineEditArretTravailMontant->setText( string.setNum( (*ite)->uMontantIJ_ ) );
            foo->lineEditArretTravailFranchise->setText( string.setNum( (*ite)->uFranchise_ ) );
            foo->lineEditArretTravailDuree->setText( string.setNum( (*ite)->uDuree_ ) );

            pArret = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pArretM->listArretTravail_.remove( pArret );
        delete( pArret );

        // Get the latest insert item
        struct Datas::SArretTravail *arret = pArretM->listArretTravail_.back();

        current->setText( 0, string.setNum( arret->uMontantIJ_ ) );
        current->setText( 1, string.setNum( arret->uFranchise_ ) );
        current->setText( 2, string.setNum( arret->uDuree_ ) );
    }
}

//----------------------------------------------------------------------------
// Delete an ArretMaladie
//----------------------------------------------------------------------------
void AmonSoft::delArretMaladie()
{
    QListViewItem *item = listViewArretTravail->currentItem();

    if( item == 0 )
        return ;

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CArretMaladie *pArretM = pPrevoyance->getArretMaladie();
    assert( pArretM != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listArretTravail::iterator    ite;
    for( ite = pArretM->listArretTravail_.begin(); 
        ite != pArretM->listArretTravail_.end(); ite++ )
    {
        if(     (*ite)->uMontantIJ_ == item->text( 0 ).toUInt()
            &&  (*ite)->uFranchise_ == item->text( 1 ).toUInt()
            &&  (*ite)->uDuree_ == item->text( 2 ).toUInt() )
        {
            // We delete record
            pArretM->listArretTravail_.remove( *ite );
            /* delete *ite; */
            listViewArretTravail->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog RenteEducation
//----------------------------------------------------------------------------
void AmonSoft::showRenteEducation()
{
    dlgRenteEducation *rente = new dlgRenteEducation();

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CDeces *pDeces = pPrevoyance->getDeces();
    assert( pDeces != 0 );

    // We show and wait the dialog closed
    if( rente->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SRenteEducation *rente = pDeces->listRentesEducation_.back();
        QString string;
        QListViewItem *item = new QListViewItem( listViewRenteEducation,
            string.setNum( rente->uMontant_ ),
            string.setNum( rente->usPourcentageSalaire_ ),
            string.setNum( rente->uAgeDebut_ ),
            string.setNum( rente->uAgeFin_ ) );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showRenteEducation( QListViewItem *current )
{
    dlgRenteEducation *foo = new dlgRenteEducation();
    struct Datas::SRenteEducation *pRente = 0;
    QString string;

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CDeces *pDeces = pPrevoyance->getDeces();
    assert( pDeces != 0 );

    Datas::t_listRenteEducation::iterator ite;
    for( ite = pDeces->listRentesEducation_.begin(); ite != pDeces->listRentesEducation_.end(); ite++ )
    {
        if(     string.setNum( (*ite)->uMontant_ ) == current->text( 0 )
            &&  string.setNum( (*ite)->usPourcentageSalaire_ ) == current->text( 1 )
            &&  string.setNum( (*ite)->uAgeDebut_ ) == current->text( 2 ) )
        {
            foo->lineEditPrevoyanceDecesRenteEducationMontant->setText( string.setNum( (*ite)->uMontant_ ) );
            foo->lineEditPrevoyanceDecesRenteEducationMontantPourcent->setText( string.setNum( (*ite)->usPourcentageSalaire_ ) );
            foo->lineEditPrevoyanceDecesRenteEducationDu->setText( string.setNum( (*ite)->uAgeDebut_ ) );
            foo->lineEditPrevoyanceDecesRenteEducationAu->setText( string.setNum( (*ite)->uAgeFin_ ) );

            pRente = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pDeces->listRentesEducation_.remove( pRente );
        delete( pRente );

        // Get the latest insert item
        struct Datas::SRenteEducation *rente = pDeces->listRentesEducation_.back();

        current->setText( 0, string.setNum( rente->uMontant_ ) );
        current->setText( 1, string.setNum( rente->usPourcentageSalaire_ ) );
        current->setText( 2, string.setNum( rente->uAgeDebut_ ) );
        current->setText( 3, string.setNum( rente->uAgeFin_ ) );
    }
}

//----------------------------------------------------------------------------
// Delete an RenteEducation
//----------------------------------------------------------------------------
void AmonSoft::delRenteEducation()
{
    QListViewItem *item = listViewRenteEducation->currentItem();

    if( item == 0 )
        return ;

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CDeces *pDeces = pPrevoyance->getDeces();
    assert( pDeces != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listRenteEducation::iterator    ite;
    for( ite = pDeces->listRentesEducation_.begin(); 
        ite != pDeces->listRentesEducation_.end(); ite++ )
    {
        if(     (*ite)->uMontant_ == item->text( 0 ).toUInt()
            &&  (*ite)->usPourcentageSalaire_ == item->text( 1 ).toUShort()
            &&  (*ite)->uAgeDebut_ == item->text( 2 ).toUInt()
            &&  (*ite)->uAgeFin_ == item->text( 3 ).toUInt()  )
        {
            // We delete record
            pDeces->listRentesEducation_.remove( *ite );
            /* delete *ite; */
            listViewRenteEducation->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showGarantieDeces()
{
    dlgGarantieDeces *garantie = new dlgGarantieDeces();

    g_Preferences->getCompagnies().loadInQT( garantie->comboBoxPrevoyanceDecesCompagnie );

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CDeces *pDeces = pPrevoyance->getDeces();
    assert( pDeces != 0 );

    // We show and wait the dialog closed
    if( garantie->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SGarantieDeces *garantied = pDeces->listGarantiesDeces_.back();
        QString string;
        QString beneficiaire;

        switch( garantied->eBeneficiaire_ )
        {
        case Datas::eFamille: { beneficiaire = "Famille"; break ; }
        case Datas::eEntreprise: { beneficiaire = "Entreprise"; break ; }
        case Datas::eBanque: { beneficiaire = "Banque"; break ; }
        case Datas::eAssocie: { beneficiaire = "Associe"; break ; }
        case Datas::eAutre: { beneficiaire = garantied->sOther_; break ; }
        default: qDebug( "AmonSoft::showGarantieDeces(): Not support case" );
        }

        QListViewItem *item = new QListViewItem( listViewGarantieDeces,
            string.setNum( garantied->uCapitaux_ ),
            string.setNum( garantied->uMaladie_ ),
            string.setNum( garantied->uAccident_ ),
            beneficiaire,
            garantied->eFiscalite_ == Datas::eAssuranceVie ? "Assurance vie" : "Madelin",
            garantied->pCompagnie_ ? garantied->pCompagnie_->sCompagnie_ : "",
            garantied->dDateEffet_.toString( Qt::LocalDate ),
            string.setNum( garantied->uDuree_ ) );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showGarantieDeces( QListViewItem *current )
{
    dlgGarantieDeces *foo = new dlgGarantieDeces();
    struct Datas::SGarantieDeces *pGarantie = 0;
    QString string;

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxPrevoyanceDecesCompagnie );

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CDeces *pDeces = pPrevoyance->getDeces();
    assert( pDeces != 0 );

    Datas::t_listGarantieDeces::iterator ite;
    for( ite = pDeces->listGarantiesDeces_.begin(); ite != pDeces->listGarantiesDeces_.end(); ite++ )
    {
        if(     string.setNum( (*ite)->uCapitaux_ ) == current->text( 0 )
            &&  string.setNum( (*ite)->uMaladie_ ) == current->text( 1 )
            &&  string.setNum( (*ite)->uAccident_ ) == current->text( 2 ) )
        {
            foo->lineEditPrevoyanceDecesCapital->setText( string.setNum( (*ite)->uCapitaux_ ) );
            foo->lineEditPrevoyanceDecesMaladie->setText( string.setNum( (*ite)->uMaladie_ ) );
            foo->lineEditPrevoyanceDecesAccident->setText( string.setNum( (*ite)->uAccident_ ) );
            foo->comboBoxPrevoyanceDecesBeneficiaire->setCurrentItem( (*ite)->eBeneficiaire_ );
            foo->lineEditPrevoyanceDecesPreciser->setText( (*ite)->sOther_ );
            foo->comboBoxPrevoyanceDecesFiscalite->setCurrentItem( (*ite)->eFiscalite_ );

            if( (*ite)->pCompagnie_ == 0 || (*ite)->pCompagnie_->bDelete_ )
                foo->comboBoxPrevoyanceDecesCompagnie->setCurrentText( "" );
            else
                foo->comboBoxPrevoyanceDecesCompagnie->setCurrentText( (*ite)->pCompagnie_->sCompagnie_ );
            foo->dateEditPrevoyanceDecesDateEffet->setDate( (*ite)->dDateEffet_ );
            foo->lineEditPrevoyanceDecesDuree->setText( string.setNum( (*ite)->uDuree_ ) );

            pGarantie = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pDeces->listGarantiesDeces_.remove( pGarantie );
        delete( pGarantie );

        // Get the latest insert item
        struct Datas::SGarantieDeces *garantie = pDeces->listGarantiesDeces_.back();

        QString beneficiaire;

        switch( garantie->eBeneficiaire_ )
        {
        case Datas::eFamille: { beneficiaire = "Famille"; break ; }
        case Datas::eEntreprise: { beneficiaire = "Entreprise"; break ; }
        case Datas::eBanque: { beneficiaire = "Banque"; break ; }
        case Datas::eAssocie: { beneficiaire = "Associe"; break ; }
        case Datas::eAutre: { beneficiaire = garantie->sOther_; break ; }
        default: qDebug( "AmonSoft::showGarantieDeces(): Not support case" );
        }

        current->setText( 0, string.setNum( garantie->uCapitaux_ ) );
        current->setText( 1, string.setNum( garantie->uMaladie_ ) );
        current->setText( 2, string.setNum( garantie->uAccident_ ) );
        current->setText( 3, beneficiaire );
        current->setText( 4, garantie->eFiscalite_ == Datas::eAssuranceVie ? "Assurance vie" : "Madelin" );
        current->setText( 5, garantie->pCompagnie_ ? garantie->pCompagnie_->sCompagnie_ : "" );
        current->setText( 6, garantie->dDateEffet_.toString( Qt::LocalDate ) );
        current->setText( 7, string.setNum( garantie->uDuree_ ) );
    }
}

//----------------------------------------------------------------------------
// Delete an garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::delGarantieDeces()
{
    QListViewItem *item = listViewGarantieDeces->currentItem();

    if( item == 0 )
        return ;

    Datas::CPrevoyance *pPrevoyance = pCurrentPersonne->getPrevoyance();
    assert( pPrevoyance != 0 );
    Datas::CDeces *pDeces = pPrevoyance->getDeces();
    assert( pDeces != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listGarantieDeces::iterator    ite;
    for( ite = pDeces->listGarantiesDeces_.begin(); 
        ite != pDeces->listGarantiesDeces_.end(); ite++ )
    {
        if(     (*ite)->uCapitaux_ == item->text( 0 ).toUInt()
            &&  (*ite)->uMaladie_ == item->text( 1 ).toUInt()
            &&  (*ite)->uAccident_ == item->text( 2 ).toUInt()
            /* TODO: Check beneficiaire */
            &&  (*ite)->uDuree_ == item->text( 7 ).toUInt()  )
        {
            // We delete record
            pDeces->listGarantiesDeces_.remove( *ite );
            /* delete *ite; */
            listViewGarantieDeces->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showEmploi()
{
    dlgEmploi *foo = new dlgEmploi();

    Datas::CCarriere *pCarriere = pCurrentPersonne->getCarriere();
    assert( pCarriere != 0 );

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SJobs *emploid = pCarriere->listEmplois_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewCarriereEmploi,
            emploid->dEntree_.toString( Qt::LocalDate ),
            emploid->dFin_.toString( Qt::LocalDate ),
            string.setNum( emploid->uRevenus_ ),
            string.setNum( emploid->uPointsRCO_ ),
            Datas::CCarriere::statutToString( emploid->eStatut_ ),
            emploid->sNotes_ );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showEmploi( QListViewItem *current )
{
    dlgEmploi *foo = new dlgEmploi();
    struct Datas::SJobs *pJob = 0;
    QString string;

    Datas::CCarriere *pCarriere = pCurrentPersonne->getCarriere();
    assert( pCarriere != 0 );

    Datas::t_listJobs::iterator ite;
    for( ite = pCarriere->listEmplois_.begin(); ite != pCarriere->listEmplois_.end(); ite++ )
    {
        if(     (*ite)->dEntree_.toString( Qt::LocalDate ) == current->text( 0 )
            &&  (*ite)->dFin_.toString( Qt::LocalDate ) == current->text( 1 )
            &&  string.setNum( (*ite)->uRevenus_ ) == current->text( 2 ) )
        {
            foo->lineEditCarriereEmploisRevenus->setText( string.setNum( (*ite)->uRevenus_ ) );
            foo->lineEditCarriereEmploisPoints->setText( string.setNum( (*ite)->uPointsRCO_ ) );
            foo->lineEditCarriereEmploisNotes->setText( (*ite)->sNotes_ );
            foo->dateEditCarriereEmploisDu->setDate( (*ite)->dEntree_ );
            foo->dateEditCarriereEmploisAu->setDate( (*ite)->dFin_ );
            foo->comboBoxCarriereEmploiStatut->setCurrentItem( (*ite)->eStatut_ );

            pJob = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pCarriere->listEmplois_.remove( pJob );
        delete( pJob );

        // Get the latest insert item
        struct Datas::SJobs *job = pCarriere->listEmplois_.back();

        current->setText( 0, job->dEntree_.toString( Qt::LocalDate ) );
        current->setText( 1, job->dFin_.toString( Qt::LocalDate ) );
        current->setText( 2, string.setNum( job->uRevenus_ ) );
        current->setText( 3, string.setNum( job->uPointsRCO_ ) );
        current->setText( 4, Datas::CCarriere::statutToString( job->eStatut_ ) );
        current->setText( 5, job->sNotes_ );
    }
}

//----------------------------------------------------------------------------
// Delete an garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::delEmploi()
{
    QListViewItem *item = listViewCarriereEmploi->currentItem();

    if( item == 0 )
        return ;

    Datas::CCarriere *pCarriere = pCurrentPersonne->getCarriere();
    assert( pCarriere != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listJobs::iterator    ite;
    for( ite = pCarriere->listEmplois_.begin(); 
        ite != pCarriere->listEmplois_.end(); ite++ )
    {
        if(     (*ite)->dEntree_.toString( Qt::LocalDate ) == item->text( 0 )
            &&  (*ite)->dFin_.toString( Qt::LocalDate ) == item->text( 1 )
            &&  (*ite)->uRevenus_ == item->text( 2 ).toUInt()
            &&  (*ite)->uPointsRCO_ == item->text( 3 ).toUInt()
            /* TODO: Check statut */ )
        {
            // We delete record
            pCarriere->listEmplois_.remove( *ite );
            listViewCarriereEmploi->takeItem( item );
            delete item;
            /* delete *ite; */
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showEnfant()
{
    dlgEnfant *foo = new dlgEnfant();

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        Datas::CFamille *pFamille = pCurrentPersonne->getFamille();

        assert( pFamille != 0 );

        // Get the latest insert item
        Datas::CEnfants *enfant = pFamille->listEnfants_.back();

        QListViewItem *item = new QListViewItem( listViewEnfants,
            enfant->GetNom(),
            enfant->GetPrenom(),
            enfant->GetDate().toString( Qt::LocalDate ),
            enfant->ACharge() == true ? "oui" : "non",
            enfant->EnEtudes() == true ? "oui" : "non",
            enfant->GetNote() );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showEnfant( QListViewItem *current )
{
    dlgEnfant *foo = new dlgEnfant();
    Datas::CEnfants *pEnfant = 0;

    Datas::CFamille *pFamille = pCurrentPersonne->getFamille();

    assert( pFamille != 0 );

    std::list< Datas::CEnfants* >::iterator ite;
    for( ite = pFamille->listEnfants_.begin(); ite != pFamille->listEnfants_.end(); ite++ )
    {
        if(     (*ite)->GetNom() == current->text( 0 )
            &&  (*ite)->GetPrenom() == current->text( 1 ) )
        {
            foo->lineEditFamilleNom->setText( (*ite)->GetNom() );
            foo->lineEditFamillePrenom->setText( (*ite)->GetPrenom() );
            foo->dateEditFamilleEnfantDateNaissance->setDate( (*ite)->GetDate() );
            foo->comboBoxFamilleEnfantAcharge->setCurrentItem( (*ite)->ACharge() ? 0 : 1 );
            foo->comboBoxFamilleFinancementEtudes->setCurrentItem( (*ite)->EnEtudes() ? 0 : 1 );
            foo->lineEditFamilleNotes->setText( (*ite)->GetNote() );
            pEnfant = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pFamille->listEnfants_.remove( pEnfant );
        delete( pEnfant );

        // Get the latest insert item
        Datas::CEnfants *enfant = pFamille->listEnfants_.back();

        current->setText( 0, enfant->GetNom() );
        current->setText( 1, enfant->GetPrenom() );
        current->setText( 2, enfant->GetDate().toString( Qt::LocalDate ) );
        current->setText( 3, enfant->ACharge() == true ? "oui" : "non" );
        current->setText( 4, enfant->EnEtudes() == true ? "oui" : "non" );
        current->setText( 5, enfant->GetNote() );
    }
}

//----------------------------------------------------------------------------
// Delete an garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::delEnfant()
{
    QListViewItem *item = listViewEnfants->currentItem();

    if( item == 0 )
        return ;

    Datas::CFamille *pFamille = pCurrentPersonne->getFamille();

    assert( pFamille != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listEnfants::iterator    ite;
    for( ite = pFamille->listEnfants_.begin(); 
        ite != pFamille->listEnfants_.end(); ite++ )
    {
        if(     (*ite)->GetNom() == item->text( 0 )
            &&  (*ite)->GetPrenom() == item->text( 1 ) )
        {
            // We delete record
            pFamille->listEnfants_.remove( *ite );
            /* delete *ite; */
            listViewEnfants->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog epargne
//----------------------------------------------------------------------------
void AmonSoft::showEpargne()
{
    dlgEpargne *foo = new dlgEpargne();

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SEpargne *epargne = pEpargnes->listEpargnes_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewEpargne,
            Datas::CEpargnes::typeEpargneToString( epargne->eType_ ),
            epargne->dEffet_.toString( Qt::LocalDate ),
            string.setNum( epargne->uInvAnnuel_ ),
            string.setNum( epargne->uEpargne_ ),
            epargne->dEpargne_.toString( Qt::LocalDate ),
            epargne->sContrat_,
            epargne->pCompagnie_ ? epargne->pCompagnie_->sCompagnie_ : "" );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showEpargne( QListViewItem *current )
{
    dlgEpargne *foo = new dlgEpargne();
    struct Datas::SEpargne *pEpargne = 0;
    QString string;

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    Datas::t_listEpargnes::iterator ite;
    for( ite = pEpargnes->listEpargnes_.begin(); ite != pEpargnes->listEpargnes_.end(); ite++ )
    {
        if(     /* Type */
            (*ite)->dEffet_.toString( Qt::LocalDate ) == current->text( 1 )
            &&  (*ite)->uInvAnnuel_ == current->text( 2 ).toUInt()
            &&  (*ite)->uEpargne_ == current->text( 3 ).toUInt()
            &&  (*ite)->dEpargne_.toString( Qt::LocalDate ) == current->text( 4 )
            &&  (*ite)->sContrat_ == current->text( 5 ) )
        {
            foo->comboBoxTypeEpargne->setCurrentItem( (*ite)->eType_ );
            foo->dateEditDateEffet->setDate( (*ite)->dEffet_ );
            foo->lineEditInvAnnuel->setText( string.setNum( (*ite)->uInvAnnuel_ ) );
            foo->lineEditEpargne->setText( string.setNum( (*ite)->uEpargne_ ) );
            foo->dateEditDateEpargne->setDate( (*ite)->dEpargne_ );
            foo->lineEditContrat->setText( (*ite)->sContrat_ );
            if( (*ite)->pCompagnie_ == 0 || (*ite)->pCompagnie_->bDelete_ )
                foo->comboBoxCompagnie->setCurrentText( "" );
            else
                foo->comboBoxCompagnie->setCurrentText( (*ite)->pCompagnie_->sCompagnie_ );

            pEpargne = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pEpargnes->listEpargnes_.remove( pEpargne );
        delete( pEpargne );

        // Get the latest insert item
        struct Datas::SEpargne *epargne = pEpargnes->listEpargnes_.back();

        current->setText( 0, Datas::CEpargnes::typeEpargneToString( epargne->eType_ ) );
        current->setText( 1, epargne->dEffet_.toString( Qt::LocalDate ) );
        current->setText( 2, string.setNum( epargne->uInvAnnuel_ ) );
        current->setText( 3, string.setNum( epargne->uEpargne_ ) );
        current->setText( 4, epargne->dEpargne_.toString( Qt::LocalDate ) );
        current->setText( 5, epargne->sContrat_ );
        current->setText( 6, epargne->pCompagnie_ ? epargne->pCompagnie_->sCompagnie_ : "" );
    }
}

//----------------------------------------------------------------------------
// Delete an epargne
//----------------------------------------------------------------------------
void AmonSoft::delEpargne()
{
    QListViewItem *item = listViewEpargne->currentItem();

    if( item == 0 )
        return ;

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listEpargnes::iterator    ite;
    for( ite = pEpargnes->listEpargnes_.begin(); 
        ite != pEpargnes->listEpargnes_.end(); ite++ )
    {
        if(     /* Type */
            (*ite)->dEffet_.toString( Qt::LocalDate ) == item->text( 1 )
            &&  (*ite)->uInvAnnuel_ == item->text( 2 ).toUInt()
            &&  (*ite)->uEpargne_ == item->text( 3 ).toUInt()
            &&  (*ite)->dEpargne_.toString( Qt::LocalDate ) == item->text( 4 )
            &&  (*ite)->sContrat_ == item->text( 5 ) )
        {
            // We delete record
            pEpargnes->listEpargnes_.remove( *ite );
            /* delete *ite; */
            listViewEpargne->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog assurance vie
//----------------------------------------------------------------------------
void AmonSoft::showAssuranceVie()
{
    dlgAssuranceVie *foo = new dlgAssuranceVie();

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SAssuranceVie *assurance = pEpargnes->listAssurancesVie_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewAssuranceVie,
            assurance->sContrat_,
            assurance->pCompagnie_ ? assurance->pCompagnie_->sCompagnie_ : "",
            assurance->dEffet_.toString( Qt::LocalDate ),
            string.setNum( assurance->uInvAnnuel_ ),
            assurance->sTerme_,
            string.setNum( assurance->uCapital_ ),
            assurance->dCapital_.toString( Qt::LocalDate ) );

        item->setText( 7, string.setNum( assurance->uDSK_ ) );
        item->setText( 8, string.setNum( assurance->uPEP_ ) );
        item->setText( 9, string.setNum( assurance->uMS_) );
        item->setText( 10, string.setNum( assurance->uFD_ ) );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showAssuranceVie( QListViewItem *current )
{
    dlgAssuranceVie *foo = new dlgAssuranceVie();
    struct Datas::SAssuranceVie *pAssuranceVie = 0;
    QString string;

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    Datas::t_listAssurancesVie::iterator ite;
    for( ite = pEpargnes->listAssurancesVie_.begin(); ite != pEpargnes->listAssurancesVie_.end(); ite++ )
    {
        if(     (*ite)->sContrat_ == current->text( 0 )
            &&  (*ite)->dEffet_.toString( Qt::LocalDate ) == current->text( 2 )
            &&  (*ite)->uInvAnnuel_ == current->text( 3 ).toUInt()
            &&  (*ite)->sTerme_ == current->text( 4 )
            &&  (*ite)->uCapital_ == current->text( 5 ).toUInt()
            &&  (*ite)->dCapital_.toString( Qt::LocalDate ) == current->text( 6 )
            &&  (*ite)->uDSK_ == current->text( 7 ).toUInt()
            &&  (*ite)->uPEP_ == current->text( 8 ).toUInt()
            &&  (*ite)->uMS_ == current->text( 9 ).toUInt()
            &&  (*ite)->uFD_ == current->text( 10 ).toUInt() )
        {
            foo->lineEditContrat->setText( (*ite)->sContrat_ );
            if( (*ite)->pCompagnie_ == 0 || (*ite)->pCompagnie_->bDelete_ )
                foo->comboBoxCompagnie->setCurrentText( "" );
            else
                foo->comboBoxCompagnie->setCurrentText( (*ite)->pCompagnie_->sCompagnie_ );
            foo->dateEditEffet->setDate( (*ite)->dEffet_ );
            foo->lineEditInvAnnuel->setText( string.setNum( (*ite)->uInvAnnuel_ ) );
            foo->lineEditTerme->setText( (*ite)->sTerme_ );
            foo->lineEditCapital->setText( string.setNum( (*ite)->uCapital_ ) );
            foo->dateEditDateCapital->setDate( (*ite)->dCapital_ );
            foo->lineEditDSK->setText( string.setNum( (*ite)->uDSK_ ) );
            foo->lineEditMS->setText( string.setNum( (*ite)->uMS_ ) );
            foo->lineEditPEP->setText( string.setNum( (*ite)->uPEP_ ) );
            foo->lineEditFD->setText( string.setNum( (*ite)->uFD_ ) );

            pAssuranceVie = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pEpargnes->listAssurancesVie_.remove( pAssuranceVie );
        delete( pAssuranceVie );

        // Get the latest insert item
        struct Datas::SAssuranceVie *assurance = pEpargnes->listAssurancesVie_.back();

        current->setText( 0, assurance->sContrat_ );
        current->setText( 1, assurance->pCompagnie_ ? assurance->pCompagnie_->sCompagnie_ : "" );
        current->setText( 2, assurance->dEffet_.toString( Qt::LocalDate ) );
        current->setText( 3, string.setNum( assurance->uInvAnnuel_ ) );
        current->setText( 4, assurance->sTerme_ );
        current->setText( 5, string.setNum( assurance->uCapital_ ) );
        current->setText( 6, assurance->dCapital_.toString( Qt::LocalDate ) );
        current->setText( 7, string.setNum( assurance->uDSK_ ) );
        current->setText( 8, string.setNum( assurance->uPEP_ ) );
        current->setText( 9, string.setNum( assurance->uMS_) );
        current->setText( 10, string.setNum( assurance->uFD_ ) ); 
    }
}

//----------------------------------------------------------------------------
// Delete an assurance vie
//----------------------------------------------------------------------------
void AmonSoft::delAssuranceVie()
{
    QListViewItem *item = listViewAssuranceVie->currentItem();

    if( item == 0 )
        return ;

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listAssurancesVie::iterator    ite;
    for( ite = pEpargnes->listAssurancesVie_.begin(); 
        ite != pEpargnes->listAssurancesVie_.end(); ite++ )
    {
        if(     (*ite)->sContrat_ == item->text( 0 )
            &&  (*ite)->dEffet_.toString( Qt::LocalDate ) == item->text( 2 )
            &&  (*ite)->uInvAnnuel_ == item->text( 3 ).toUInt()
            &&  (*ite)->sTerme_ == item->text( 4 )
            &&  (*ite)->uCapital_ == item->text( 5 ).toUInt()
            &&  (*ite)->dCapital_.toString( Qt::LocalDate ) == item->text( 6 )
            &&  (*ite)->uDSK_ == item->text( 7 ).toUInt()
            &&  (*ite)->uPEP_ == item->text( 8 ).toUInt()
            &&  (*ite)->uMS_ == item->text( 9 ).toUInt()
            &&  (*ite)->uFD_ == item->text( 10 ).toUInt() )
        {
            // We delete record
            pEpargnes->listAssurancesVie_.remove( *ite );
            /* delete *ite; */
            listViewAssuranceVie->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog compte
//----------------------------------------------------------------------------
void AmonSoft::showCompte()
{
    dlgComptes *foo = new dlgComptes();

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SComptes *compte = pEpargnes->listComptes_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewComptes,
            Datas::CEpargnes::typeCompteToString( compte->eType_ ),
            compte->pCompagnie_ ? compte->pCompagnie_->sCompagnie_ : "",
            compte->dEffet_.toString( Qt::LocalDate ),
            string.setNum( compte->uInvAnnuel_ ),
            compte->sTerme_,
            string.setNum( compte->uCapital_ ),
            compte->dCapital_.toString( Qt::LocalDate ),
            string.setNum( compte->usRendement_ ) );
        item->setText( 8, compte->sNotes_ );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showCompte( QListViewItem *current )
{
    dlgComptes *foo = new dlgComptes();
    struct Datas::SComptes *pComptes = 0;
    QString string;

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    Datas::t_listComptes::iterator ite;
    for( ite = pEpargnes->listComptes_.begin(); ite != pEpargnes->listComptes_.end(); ite++ )
    {
        if(     /* type */
            (*ite)->dEffet_.toString( Qt::LocalDate ) == current->text( 2 )
            &&  (*ite)->uInvAnnuel_ == current->text( 3 ).toUInt()
            &&  (*ite)->sTerme_ == current->text( 4 )
            &&  (*ite)->uCapital_ == current->text( 5 ).toUInt()
            &&  (*ite)->dCapital_.toString( Qt::LocalDate ) == current->text( 6 )
            &&  (*ite)->usRendement_ == current->text( 7 ).toUShort() )
        {
            foo->comboBoxType->setCurrentItem( (*ite)->eType_ );
            if( (*ite)->pCompagnie_ == 0 || (*ite)->pCompagnie_->bDelete_ )
                foo->comboBoxCompagnie->setCurrentText( "" );
            else
                foo->comboBoxCompagnie->setCurrentText( (*ite)->pCompagnie_->sCompagnie_ );
            foo->dateEditDateEffet->setDate( (*ite)->dEffet_ );
            foo->lineEditInvAnnuel->setText( string.setNum( (*ite)->uInvAnnuel_ ) );
            foo->lineEditTerme->setText( (*ite)->sTerme_ );
            foo->lineEditCapital->setText( string.setNum( (*ite)->uCapital_ ) );
            foo->dateEditCapital->setDate( (*ite)->dCapital_ );
            foo->lineEditRendement->setText( string.setNum( (*ite)->usRendement_ ) );
            foo->lineEditCommentaire->setText( (*ite)->sNotes_ );

            pComptes = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pEpargnes->listComptes_.remove( pComptes );
        delete( pComptes );

        // Get the latest insert item
        struct Datas::SComptes *compte = pEpargnes->listComptes_.back();

        current->setText( 0, Datas::CEpargnes::typeCompteToString( compte->eType_ ) );
        current->setText( 1, compte->pCompagnie_ ? compte->pCompagnie_->sCompagnie_ : "" );
        current->setText( 2, compte->dEffet_.toString( Qt::LocalDate ) );
        current->setText( 3, string.setNum( compte->uInvAnnuel_ ) );
        current->setText( 4, compte->sTerme_ );
        current->setText( 5, string.setNum( compte->uCapital_ ) );
        current->setText( 6, compte->dCapital_.toString( Qt::LocalDate ) );
        current->setText( 7, string.setNum( compte->usRendement_ ) );
        current->setText( 8, compte->sNotes_ );
    }
}

//----------------------------------------------------------------------------
// Delete an compte
//----------------------------------------------------------------------------
void AmonSoft::delCompte()
{
    QListViewItem *item = listViewComptes->currentItem();

    if( item == 0 )
        return ;

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listComptes::iterator    ite;
    for( ite = pEpargnes->listComptes_.begin(); 
        ite != pEpargnes->listComptes_.end(); ite++ )
    {
        if(     /* type */
            (*ite)->uInvAnnuel_ == item->text( 3 ).toUInt()
            &&  (*ite)->sTerme_ == item->text( 4 )
            &&  (*ite)->uCapital_ == item->text( 5 ).toUInt()
            &&  (*ite)->usRendement_ == item->text( 7 ).toUShort() )
        {
            // We delete record
            pEpargnes->listComptes_.remove( *ite );
            /* delete *ite; */
            listViewComptes->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog revenus
//----------------------------------------------------------------------------
void AmonSoft::showRevenus()
{
    dlgRevenus *foo = new dlgRevenus();

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SRevenus *revenus = pEpargnes->listRevenus_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewRevenus,
            revenus->sDesignation_,
            string.setNum( revenus->uMontant_ ) );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showRevenus( QListViewItem *current )
{
    dlgRevenus *foo = new dlgRevenus();
    struct Datas::SRevenus *pRevenus = 0;
    QString string;

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    Datas::t_listRevenus::iterator ite;
    for( ite = pEpargnes->listRevenus_.begin(); ite != pEpargnes->listRevenus_.end(); ite++ )
    {
        if(     (*ite)->sDesignation_ == current->text( 0 )
            &&  (*ite)->uMontant_ == current->text( 1 ).toUInt() )
        {
            foo->lineEditDesignation->setText( (*ite)->sDesignation_ );
            foo->lineEditMontant->setText( string.setNum( (*ite)->uMontant_ ) );

            pRevenus = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pEpargnes->listRevenus_.remove( pRevenus );
        delete( pRevenus );

        // Get the latest insert item
        struct Datas::SRevenus *revenus = pEpargnes->listRevenus_.back();

        current->setText( 0, revenus->sDesignation_ );
        current->setText( 1, string.setNum( revenus->uMontant_ ) );
    }
}

//----------------------------------------------------------------------------
// Delete an revenus
//----------------------------------------------------------------------------
void AmonSoft::delRevenus()
{
    QListViewItem *item = listViewRevenus->currentItem();

    if( item == 0 )
        return ;

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listRevenus::iterator    ite;
    for( ite = pEpargnes->listRevenus_.begin(); 
        ite != pEpargnes->listRevenus_.end(); ite++ )
    {
        if(     (*ite)->sDesignation_ == item->text( 0 )
            &&  (*ite)->uMontant_== item->text( 1 ).toUInt() )
        {
            // We delete record
            pEpargnes->listRevenus_.remove( *ite );
            /* delete *ite; */
            listViewRevenus->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog charges
//----------------------------------------------------------------------------
void AmonSoft::showCharges()
{
    dlgCharges *foo = new dlgCharges();

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SRevenus *revenus = pEpargnes->listCharges_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewCharges,
            revenus->sDesignation_,
            string.setNum( revenus->uMontant_ ) );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showCharges( QListViewItem *current )
{
    dlgCharges *foo = new dlgCharges();
    struct Datas::SRevenus *pRevenus = 0;
    QString string;

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    Datas::t_listCharges::iterator ite;
    for( ite = pEpargnes->listCharges_.begin(); ite != pEpargnes->listCharges_.end(); ite++ )
    {
        if(     (*ite)->sDesignation_ == current->text( 0 )
            &&  (*ite)->uMontant_ == current->text( 1 ).toUInt() )
        {
            foo->lineEditDesignation->setText( (*ite)->sDesignation_ );
            foo->lineEditMontant->setText( string.setNum( (*ite)->uMontant_ ) );

            pRevenus = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pEpargnes->listRevenus_.remove( pRevenus );
        delete( pRevenus );

        // Get the latest insert item
        struct Datas::SRevenus *revenus = pEpargnes->listCharges_.back();

        current->setText( 0, revenus->sDesignation_ );
        current->setText( 1, string.setNum( revenus->uMontant_ ) );
    }
}

//----------------------------------------------------------------------------
// Delete an revenus
//----------------------------------------------------------------------------
void AmonSoft::delCharges()
{
    QListViewItem *item = listViewCharges->currentItem();

    if( item == 0 )
        return ;

    Datas::CEpargnes    *pEpargnes = pCurrentPersonne->getEpargne();
    assert( pEpargnes != 0 );

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listCharges::iterator    ite;
    for( ite = pEpargnes->listCharges_.begin(); 
        ite != pEpargnes->listCharges_.end(); ite++ )
    {
        if(     (*ite)->sDesignation_ == item->text( 0 )
            &&  (*ite)->uMontant_== item->text( 1 ).toUInt() )
        {
            // We delete record
            pEpargnes->listCharges_.remove( *ite );
            /* delete *ite; */
            listViewCharges->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show the dialog retraite
//----------------------------------------------------------------------------
void AmonSoft::showRetraite()
{
    dlgRetraite *foo = new dlgRetraite();

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );    

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SRetraite *retraite = pCurrentEntreprise->listRetraites_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewEntrepriseRetraite,
            retraite->sContrat_,
            retraite->pCompagnie_ ? retraite->pCompagnie_->sCompagnie_ : "",
            retraite->sCollegue_,
            string.setNum( retraite->usTA_ ),
            string.setNum( retraite->usTB_ ),
            string.setNum( retraite->usTC_ ),
            retraite->dEffet_.toString( Qt::LocalDate ),
            string.setNum( retraite->usFisc82_ ) );
        item->setText( 8, string.setNum( retraite->usFisc82AD_ ) );
        item->setText( 9, string.setNum( retraite->usFisc82SD_ ) );
        item->setText( 10, string.setNum( retraite->usFisc39_ ) );
    }
}

//----------------------------------------------------------------------------
// Show the dialog garantieDeces
//----------------------------------------------------------------------------
void AmonSoft::showRetraite( QListViewItem *current )
{
    dlgRetraite *foo = new dlgRetraite();
    struct Datas::SRetraite *pRetraite = 0;
    QString string;

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );

    Datas::t_listRetraites::iterator ite;
    for( ite = pCurrentEntreprise->listRetraites_.begin(); ite != pCurrentEntreprise->listRetraites_.end(); ite++ )
    {
        if(     (*ite)->sContrat_ == current->text( 0 )
            &&  (*ite)->sCollegue_ == current->text( 2 ) )
        {
            foo->lineEditContrat->setText( (*ite)->sContrat_ );
            foo->dateEditEffet->setDate( (*ite)->dEffet_ );
            foo->lineEditCollegue->setText( (*ite)->sCollegue_ );
            foo->lineEditTA->setText( string.setNum( (*ite)->usTA_ ) );
            foo->lineEditTB->setText( string.setNum( (*ite)->usTB_ ) );
            foo->lineEditTC->setText( string.setNum( (*ite)->usTC_ ) );
            foo->lineEditFisc82->setText( string.setNum( (*ite)->usFisc82_ ) );
            foo->lineEditFisc82AD->setText( string.setNum( (*ite)->usFisc82AD_ ) );
            foo->lineEditFisc82SD->setText( string.setNum( (*ite)->usFisc82SD_ ) );
            foo->lineEditFisc39->setText( string.setNum( (*ite)->usFisc39_ ) );

            if( (*ite)->pCompagnie_ == 0 || (*ite)->pCompagnie_->bDelete_ )
                foo->comboBoxCompagnie->setCurrentText( "" );
            else
                foo->comboBoxCompagnie->setCurrentText( (*ite)->pCompagnie_->sCompagnie_ );

            pRetraite = *ite;
            break ;
        }
    }

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // If user accepts changes, we delete the current selected child, to get the last one,
        // which contain modifications.
        pCurrentEntreprise->listRetraites_.remove( pRetraite );
        delete( pRetraite );

        // Get the latest insert item
        struct Datas::SRetraite *retraite = pCurrentEntreprise->listRetraites_.back();

        current->setText( 0, retraite->sContrat_ );
        current->setText( 1, retraite->pCompagnie_ ? retraite->pCompagnie_->sCompagnie_ : "" );
        current->setText( 2, retraite->sCollegue_ );
        current->setText( 3, string.setNum( retraite->usTA_ ) );
        current->setText( 4, string.setNum( retraite->usTB_ ) );
        current->setText( 5, string.setNum( retraite->usTC_ ) );
        current->setText( 6, retraite->dEffet_.toString( Qt::LocalDate ) );
        current->setText( 7, string.setNum( retraite->usFisc82_ ) );
        current->setText( 8, string.setNum( retraite->usFisc82AD_ ) );
        current->setText( 9, string.setNum( retraite->usFisc82SD_ ) );
        current->setText( 10, string.setNum( retraite->usFisc39_ ) );
    }
}

//----------------------------------------------------------------------------
// Delete an retraite
//----------------------------------------------------------------------------
void AmonSoft::delRetraite()
{
    QListViewItem *item = listViewEntrepriseRetraite->currentItem();

    if( item == 0 )
        return ;

    // Search item in the global list
    // TODO: Try to find more efficient method
    Datas::t_listRetraites::iterator    ite;
    for( ite = pCurrentEntreprise->listRetraites_.begin(); 
        ite != pCurrentEntreprise->listRetraites_.end(); ite++ )
    {
        if(     (*ite)->sContrat_ == item->text( 0 )
            &&  (*ite)->sCollegue_ == item->text( 2 ) )
        {
            // We delete record
            pCurrentEntreprise->listRetraites_.remove( *ite );
            /* delete *ite; */
            listViewEntrepriseRetraite->takeItem( item );
            delete item;
            break ;
        }
    }
}

//----------------------------------------------------------------------------
// Show dead capital
//----------------------------------------------------------------------------
void AmonSoft::showKDeces()
{ /* TODO




    dlgCapitalDeces *foo = new dlgCapitalDeces();

    g_Preferences->getCompagnies().loadInQT( foo->comboBoxCompagnie );    

    // We show and wait the dialog closed
    if( foo->exec() == QDialog::Accepted )
    {
        // Get the latest insert item
        struct Datas::SCapitalDeces *kDeces = pCurrentEntreprise->listCapitalDeces_.back();
        QString string;

        QListViewItem *item = new QListViewItem( listViewPrevoyanceEntses, TODO
            retraite->sContrat_,
            retraite->pCompagnie_ ? retraite->pCompagnie_->sCompagnie_ : "",
            retraite->sCollegue_,
            string.setNum( retraite->usTA_ ),
            string.setNum( retraite->usTB_ ),
            string.setNum( retraite->usTC_ ),
            retraite->dEffet_.toString( Qt::LocalDate ),
            string.setNum( retraite->usFisc82_ ) );
        item->setText( 8, string.setNum( retraite->usFisc82AD_ ) );
        item->setText( 9, string.setNum( retraite->usFisc82SD_ ) );
        item->setText( 10, string.setNum( retraite->usFisc39_ ) );
    }*/
}

//----------------------------------------------------------------------------
// Show dead capital
//----------------------------------------------------------------------------
void AmonSoft::showKDeces( QListViewItem * )
{ /*TODO*/ }

//----------------------------------------------------------------------------
// Delete dead capital
//----------------------------------------------------------------------------
void AmonSoft::delKdeces()
{}

//----------------------------------------------------------------------------
// Show day interet
//----------------------------------------------------------------------------
void AmonSoft::showIJournalier()
{}

//----------------------------------------------------------------------------
// Show day interet
//----------------------------------------------------------------------------
void AmonSoft::showIJournalier( QListViewItem * )
{}

//----------------------------------------------------------------------------
// Delete day interet
//----------------------------------------------------------------------------
void AmonSoft::delIJournalier()
{}