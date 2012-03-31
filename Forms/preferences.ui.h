
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

#ifndef _PREFERENCES_UI_H_
# define _PREFERENCES_UI_H_

#include <qlistview.h>

#include "Preferences/CPreferences.h"
#include "main.h"

void dlgPreferences::listBox_selectionChanged( QListBoxItem *item )
{
    if( item == 0 )
        return ;

    if( item->text() == "Compagnies" )
    {
        widgetStack1->raiseWidget( 0 );
        return ;
    }

    if( item->text() == "Epargnes" )
    {
        widgetStack1->raiseWidget( 3 );
        return ;
    }

    if( item->text() == "Comptes" )
    {
        widgetStack1->raiseWidget( 2 );
        return ;
    }

    if( item->text() == "Conseillers" )
    {
        widgetStack1->raiseWidget( 4 );
        return ;
    }

    widgetStack1->raiseWidget( 1 );
}

void dlgPreferences::listViewCompagnies_selectionChanged( QListViewItem *item )
{
    QString str = item->text( 0 );

    if( str == "<Nouveau>" )
    {
        lineEditCompagnieDenomination->setText( "" );
        comboBoxCompagnieType->setCurrentItem( 0 );
        lineEditCompagnieContact->setText( "" );
        return ;
    }

    Preferences::SCompagnie *comp = g_Preferences->getCompagnies().getCompagnie( str );

    if( comp == 0 ) return ;

    lineEditCompagnieDenomination->setText( comp->sCompagnie_ );
    comboBoxCompagnieType->setCurrentItem( comp->eType_ );
    lineEditCompagnieContact->setText( comp->sContact_ );
}


void dlgPreferences::pushButtonCompagnieValider_clicked()
{
    QString str;

    if( listViewCompagnies->selectedItem() != 0 )
        str = listViewCompagnies->selectedItem()->text( 0 );

    Preferences::SCompagnie *comp = g_Preferences->getCompagnies().getCompagnie( str );

    if( listViewCompagnies->selectedItem() == 0 || comp == 0 ) 
    {
        Preferences::CCompagnies  &sComp = g_Preferences->getCompagnies();
        comp = sComp.addCompagnie( lineEditCompagnieDenomination->text(),
                                   (enum Preferences::eTypeCompagnie) comboBoxCompagnieType->currentItem(),
                                   lineEditCompagnieContact->text() );
        QListViewItem *l = new QListViewItem( listViewCompagnies,
            comp->sCompagnie_,
            Preferences::CCompagnies::typeCompagnieToString( comp->eType_ ),
            comp->sContact_ );
    }
    else          
    {
        comp->sCompagnie_ = lineEditCompagnieDenomination->text();
        comp->eType_ = (enum Preferences::eTypeCompagnie) comboBoxCompagnieType->currentItem();
        comp->sContact_ = lineEditCompagnieContact->text();
        QListViewItem *l = listViewCompagnies->selectedItem();

        if( l == 0 ) return ;

        l->setText( 0, comp->sCompagnie_ );
        l->setText( 1, Preferences::CCompagnies::typeCompagnieToString( comp->eType_ ) );
        l->setText( 2, comp->sContact_ );
    }
}


void dlgPreferences::pushButtonCompagnieSupprimer_clicked()
{
    if( listViewCompagnies->selectedItem() == 0 ) return ;

    QString str = listViewCompagnies->selectedItem()->text( 0 );
    g_Preferences->getCompagnies().delCompagnie( str );
    listViewCompagnies->removeItem( listViewCompagnies->selectedItem() );
}

void dlgPreferences::listViewEpargnes_selectionChanged( QListViewItem *item )
{
    QString str = item->text( 0 );

    if( str == "<Nouveau>" )
        lineEditEpargneNom->setText( "" );
    else
        lineEditEpargneNom->setText( str );
}


void dlgPreferences::pushButtonEpargneValider_clicked()
{
    QString str;

    if( listViewEpargnes->selectedItem() != 0 )
        str = listViewEpargnes->selectedItem()->text( 0 );

    if( listViewEpargnes->selectedItem() != 0 && str != "<Nouveau>" )
    {
        std::list< QString* >::iterator ite;
        for( ite = g_Preferences->listEpargnes_.begin();
            g_Preferences->listEpargnes_.end() != ite; ite++ )
        {
            if( **ite == str )
            {
                // We commit the changed name
                **ite = lineEditEpargneNom->text();
                break ;
            }
        }

        QListViewItem *l = listViewEpargnes->selectedItem();
        if( l == 0 ) return ;
        l->setText( 0, lineEditEpargneNom->text() );
    }
    else
    {
        g_Preferences->listEpargnes_.push_back( new QString( lineEditEpargneNom->text() ) );
        QListViewItem *l = new QListViewItem( listViewEpargnes, lineEditEpargneNom->text() );       
    }
}

void dlgPreferences::pushButtonEpargneSupprimer_clicked()
{
    if( listViewEpargnes->selectedItem() == 0 ) return ;

    QString str = listViewEpargnes->selectedItem()->text( 0 );
    std::list< QString* >::iterator ite;
    QString *it;
    for( ite = g_Preferences->listEpargnes_.begin();
        g_Preferences->listEpargnes_.end() != ite; ite++ )
    {
        if( **ite == str )
        {
            it = *ite;
            break ;
        }
    }
    g_Preferences->listEpargnes_.remove( it );
    delete it;
    listViewEpargnes->removeItem( listViewEpargnes->selectedItem() );
}

void dlgPreferences::listViewComptes_selectionChanged( QListViewItem *item )
{
    QString str = item->text( 0 );

    if( str == "<Nouveau>" )
        lineEditCompteNom->setText( "" );
    else
        lineEditCompteNom->setText( str );
}


void dlgPreferences::pushButtonComptesValider_clicked()
{
    QString str;

    if( listViewComptes->selectedItem() != 0 )
        str = listViewComptes->selectedItem()->text( 0 );

    if( listViewComptes->selectedItem() != 0 && str != "<Nouveau>" )
    {
        std::list< QString* >::iterator ite;
        for( ite = g_Preferences->listComptes_.begin();
            g_Preferences->listComptes_.end() != ite; ite++ )
        {
            if( **ite == str )
            {
                // We commit the changed name
                **ite = lineEditCompteNom->text();
                break ;
            }
        }

        QListViewItem *l = listViewComptes->selectedItem();
        if( l == 0 ) return ;
        l->setText( 0, lineEditCompteNom->text() );
    }
    else
    {
        g_Preferences->listComptes_.push_back( new QString( lineEditCompteNom->text() ) );
        QListViewItem *l = new QListViewItem( listViewComptes, lineEditCompteNom->text() );       
    }
}


void dlgPreferences::pushButtonComptesSupprimer_clicked()
{
    if( listViewComptes->selectedItem() == 0 ) return ;

    QString str = listViewComptes->selectedItem()->text( 0 );

    if( str == "<Nouveau>" || str == "" )
        return ;

    std::list< QString* >::iterator ite;
    QString *it;
    for( ite = g_Preferences->listComptes_.begin();
        g_Preferences->listComptes_.end() != ite; ite++ )
    {
        if( **ite == str )
        {
            it = *ite;
            break ;
        }
    }
    g_Preferences->listComptes_.remove( it );
    delete it;
    listViewComptes->removeItem( listViewComptes->selectedItem() );
}

void dlgPreferences::listViewBureau_selectionChanged( QListViewItem *item )
{
    QString str = item->text( 0 );

    Preferences::CCabinet *cabinet = g_Preferences->getCabinet( str );

    if( cabinet == 0 ) return ;
    
    lineEditNomEtude->setText( cabinet->getName() );
    comboBoxTypeEtude->setCurrentItem( cabinet->getType() );

    cabinet->loadInQT( listViewConseillers );
}


void dlgPreferences::listViewConseillers_selectionChanged( QListViewItem *item )
{
    QString str = item->text( 0 );

    if( str == "<Nouveau>" )
        lineEditNomConseillers->setText( "" );
    else
        lineEditNomConseillers->setText( str );
}


void dlgPreferences::pushButtonValiderBureau_clicked()
{
    QString str;

    if( listViewBureau->selectedItem() != 0 )
        str = listViewBureau->selectedItem()->text( 0 );

    if( listViewBureau->selectedItem() != 0 && str != "<Nouveau>" )
    {
        Preferences::CCabinet *cabinet = g_Preferences->getCabinet( str );
        if( cabinet == 0 ) return ;

        cabinet->setName( lineEditNomEtude->text() );
        cabinet->setType( (enum Preferences::eTypeCabinet) comboBoxTypeEtude->currentItem() );

        QListViewItem *l = listViewBureau->selectedItem();
        if( l == 0 ) return ;
        l->setText( 0, lineEditNomEtude->text() );
        l->setText( 1, comboBoxTypeEtude->currentText() );
    }
    else
    {
        Preferences::CCabinet *cabinet = 
            g_Preferences->newCabinet( lineEditNomEtude->text(), (enum Preferences::eTypeCabinet)comboBoxTypeEtude->currentItem() );

        QListViewItem *l = new QListViewItem( listViewBureau,
            lineEditNomEtude->text(),
            comboBoxTypeEtude->currentText() );

        cabinet->loadInQT( listViewConseillers );
    }
}


void dlgPreferences::pushButtonSupprimerEtude_clicked()
{
    if( listViewBureau->selectedItem() == 0 ) return ;

    QString str = listViewBureau->selectedItem()->text( 0 );
    if( str != "<Nouveau>" || str != "" )
        g_Preferences->delCabinet( str );

    listViewBureau->removeItem( listViewBureau->selectedItem() );
}


void dlgPreferences::pushButtonValiderConseillers_clicked()
{
    QString str;
    QString strCab;

    if( listViewConseillers->selectedItem() != 0 )
        str = listViewConseillers->selectedItem()->text( 0 );

    if( listViewBureau->selectedItem() != 0 )
        strCab = listViewBureau->selectedItem()->text( 0 );
    else return ;

    Preferences::CCabinet *cabinet = g_Preferences->getCabinet( strCab );
    assert( cabinet != 0 );

    if( listViewConseillers->selectedItem() != 0 && str != "<Nouveau>" )
    {
        QString *cons = cabinet->getConseiller( str );
        *cons = lineEditNomConseillers->text();

        QListViewItem *l = listViewConseillers->selectedItem();
        if( l == 0 ) return ;
        l->setText( 0, lineEditNomConseillers->text() );
    }
    else
    {
        cabinet->newConseiller( lineEditNomConseillers->text() );
        QListViewItem *l = new QListViewItem( listViewConseillers, lineEditNomConseillers->text() );       
    }
}


void dlgPreferences::pushButtonSupprimerConseillers_clicked()
{
    QString str;
    QString strCab;

    if( listViewConseillers->selectedItem() != 0 )
        str = listViewConseillers->selectedItem()->text( 0 );

    if( listViewBureau->selectedItem() != 0 )
        strCab = listViewBureau->selectedItem()->text( 0 );
    else return ;

    Preferences::CCabinet *cabinet = g_Preferences->getCabinet( strCab );
    assert( cabinet != 0 );

    cabinet->delConseiller( str );
    listViewConseillers->removeItem( listViewConseillers->selectedItem() );
}

#endif /* _PREFERENCES_UI_H_ */
