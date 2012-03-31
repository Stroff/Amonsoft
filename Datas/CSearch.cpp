/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CSearch.cpp,v 1.7 2006/11/10 10:48:07 pascal Exp $
* $Log: CSearch.cpp,v $
* Revision 1.7  2006/11/10 10:48:07  pascal
* - V�rification de la coh�rence des donn�es lors de la validation. Pour le moment, on l�ve simplement une exception si l'on ne passe pas des entiers l� o� ils sont attendus.
*
* Revision 1.6  2006/10/13 14:39:46  pascal
* Version 0.2.5
*
* Nouvelles fonctionnalit�s
*
* - Syst�me de CrashReport complet: G�n�ration d'un fichier de dump (.dmp) lorsque le programme plante. Tentative de sauvegarde des fichiers lors d'un plantage.
*
* - MoisBilan est d�sormais une liste d�roulante.
*
* - Plus de masque de saisie, ce qui implique plus de v�rification au niveau des types de donn�es saisies. Cela corrige les probl�mes li�s au curseur au milieu de la case ou encore l'impossibilit� d'avoir des pourcentages utilisant des nombres r�els.
*
* - Le terme b�n�ficiaire a �t� remplac� par client.
*
* Correction de bugs
*
* - Il n'y a plus de bugs lorsqu'on supprime une personne employ�e dans une entreprise.
*
* Roadmap
*
* - Fin octobre
*  + Tests de coh�rences
*  + Mise en forme des exportations.
*  + Connexion pour les fiches entses.
*
* - Fin novembre
*  + Cryptage des fichiers de donn�es XML
*  + Am�lioration du syst�me de mise � jour
*  + Modification dans la gestion des listes d'�pargne, d'enfants, de revenus, des charges, etc.
*
* La version expire le 30/11/2006
*
* Revision 1.5  2006/10/12 11:29:46  pascal
* - Suppression des inpputs Masks
* - B�n�ficiaire s'appel d�sormais client
* - Mois bilan utilise une comboBox
*
* Revision 1.4  2006/10/09 10:06:08  pascal
* Version 0.2.4
*
* Nouvelles fonctionnalit�s
*
* - D�sormais lorsqu'une erreur "attendue" se d�clenche, un email nous est envoy� pour nous le signaler.
*
* - A chaque lancement du programme les fichiers de donn�es sont copi�s dans des fichiers ".bak", lesquels seront utilisables en cas de crash. Ce syst�me ne remplacement toutefois pas une sauvegarde quotidienne que l'on pourrait faire avec, e.g. http://www.clubic.com/telecharger-fiche11081-cobian-backup.html.
*
* - Lorsqu'une erreur est d�tect�e durant l'ex�cution du programme, le syst�me tant de faire une sauvegarde avant de se fermer.
*
* - G�n�ration de coredump, lors que le programme plante afin d'�tablir la raison du plantage. Ce module n'est pas tout � fait fonctionnel, il sera compl�ter dans la prochaine version.
*
* Correction de bugs
*
* - Correction d'un bug avec avec le bouton besoin / notes qui ne fonctionnait pas.
*
* Revision 1.3  2006/09/04 11:44:22  pascal
* Version 0.2.3
* Nouvelles fonctionnalit�s
*
* - Recherche complexe deuxi�me version
*     Les recherches sont d�finies dans le fichier search.ini qui se trouve par d�faut dans "c:\program files\Amonsoft\".
*     La syntaxe de ce fichier est d�sormais de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE AND|OR [!] MOTCLE
*
*     Il est donc d�sormais possible de combiner deux crit�res de recherche.
*
* - Modification des mots clefs :
*         ANNIVERSAIRE renvoit d�sormais la liste des personnes dont c'est l'anniversaire (m�me jour et m�me mois que le syst�me).
*         DATEANNIVERSAIRE n�cessitera dans l'interface la saisie d'une date (m�me fonctionnement l'ancien ANNIVERSAIRE).
*
* - Les recherches par nom, pr�nom et type de clients sont combin�s aux recherches complexes. Il est ainsi possible de chercher un client, par exemple, qui n'a pas de mutuelle et dont le pr�nom contient "dou".
*
* - "Exporter personnes" dans le menu Fichier, devient "Exporter". Il est d�sormais possible d'exporter une fiche entreprise en XML pour l'ouvrir avec Word.
*
* - Un syst�me de mise � jour automatique est en place. La v�rification s'effectue au lancement du programme, si une nouvelle version est disponible vous pouvez la t�l�charger. Lors du t�l�chargement de la nouvelle version, le programme est bloqu� afin de ne pas y saisir d'information qui ne pourront �tre sauvegard�e. La nouvelle version est t�l�charg�e dans le r�pertoire courant du programme, une fois le t�l�chargement fini, l'installation est automatiquement lanc�e.
*
* Correction de bugs
*
* - Pas de corrections dans cette version
*
* Revision 1.2  2006/08/04 11:21:48  pascal
* Version 0.2.2
* Nouvelles fonctionnalit�s
*
* - Recherche complexe premi�re version
*     Les recherches sont d�finies dans le fichier search.ini qui se trouve par d�faut dans "c:\program files\Amonsoft\" (un fichier d'exemple est fourni lors de l'installation).
*     La syntaxe de ce fichier est de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE
*
*     Toutes les lignes commen�ant par '#' ne seront pas interpr�t�es par le programme.
*     Nom: repr�sente le terme sous lequel vous retrouverez la recherche dans le programme.
*     0 signifie qu'il s'ag�t d'une recherche pour les particuliers.
*     ! facultatif, le point d'exclamation permet de renvoyer l'inverse des valeurs retourn�es par le MOTCLE
*     MOTCLE est une valeur dans la liste tel que
*         ANNIVERSAIRE n�cessitera dans l'interface la saisie d'une date
*         AGE n�cessitera dans l'interface la saisie d'une valeur num�rique
*         REVENUS n�cessitera dans l'interface la saisie d'une valeur num�rique
*         BILAN n�cessitera dans l'interface la saisie d'une valeur texte
*         MUTUELLE, RETRAITE, FISCALITERETRAITEMADELIN et ASSURANCEVIE ne requi�re aucune saisie dans l'interface
*
*     Attention pour le moment, les recherches par Nom, Pr�nom ou prospect ne tiennent pas comptent de la recherche complexe s�lectionn�e.
*     Par exemple, il n'est pas possible encore, d'avoir la liste des prospect, qui n'ont pas d'assurance vie.
*
* - Les espaces superflus ne sont plus sauvegard�s dans les fichiers XML
* - Dans la liste des dossiers personnes Fichier/Exporter Personnes permet d'exporter la liste des personnes concern�es par une recherche complexe dans un fichier CSV compatible avec Excel.
* - Lorsqu'une fiche client ou prospect est ouverte Fichier/Exporter Personnes permet d'exporter la personne courante dans deux fichiers XML compatible Word.
*
* Correction de bugs
*
* - La liste des revenus n'�taient pas sauvegard�e dans les fichiers XML
* - Lors de l'ouverture des formulaires annexes d'une fiche les compagnies d'assurance n'�taient pas toujours correctement s�lectionn�es
* - Une personne ne peut plus �tre mari�e qu'� une autre personne (plus de polygamie)
* - Les filtres simples par Nom, Pr�nom et Type de client souffraient de bugs lorsqu'on voulait utiliser les 3 crit�res de recherche
*
* Revision 1.1  2006/06/21 11:24:11  pascal
* - Fichier de recherche avanc�
*
*
*/
#include <list>

// basic file operations
#include <iostream>
#include <fstream>

#include <qstring.h>
#include <qstringlist.h>
#include <qcombobox.h>
#include <qregexp.h>
#include <qlineedit.h>

#include "CrashReport/debug.h"

#include "Datas/CDatas.h"
#include "Datas/CPersonnes.h"
#include "Datas/CSearch.h"

using namespace Datas;

//----------------------------------------------------------------------------
// Load list of method in comboBox
//----------------------------------------------------------------------------
void CSearch::loadInComboBox( QComboBox *combo, bool bPersonne ) const
{
    std::list< t_searchMethod* >::const_iterator ite;

    mAssert( combo != 0, "combo != 0" );

    combo->insertItem( "", 0 );

    for( ite = listMethods_.begin(); ite != listMethods_.end(); ite++ )
    {
        if( bPersonne && (*ite)->bPersonne_ )
            combo->insertItem( (*ite)->sNom_, (*ite)->uId_ );
    }
}

//----------------------------------------------------------------------------
// Get selected search method
//----------------------------------------------------------------------------
void CSearch::setSearchMethod( uint idMethod, dlgAmonSoft &amon )
{ 
    std::list< t_searchMethod* >::const_iterator ite;

    if( idMethod == 0 )
    {
        amon.comboBoxSearchOp1->setEnabled( false );
        amon.comboBoxSearchOp2->setEnabled( false );
        amon.lineEditSearchValue1->setEnabled( false );
        amon.lineEditSearchValue2->setEnabled( false );
        searchMethod_ = 0;
        return ;
    }

    for( ite = listMethods_.begin(); ite != listMethods_.end(); ite++ )
    {
        if( (*ite)->uId_ == idMethod )
        {
            amon.comboBoxSearchOp1->setEnabled( true );
            amon.lineEditSearchValue1->setEnabled( true );
            searchMethod_ = *ite;
            if( searchMethod_->pFuncSearch1 == sDateAnniversaire )           
                amon.lineEditSearchValue1->setInputMask( "9999/99/99;_" );
            else
                amon.lineEditSearchValue1->setInputMask( "" );

            if( searchMethod_->pFuncSearch2 )
            {
                amon.comboBoxSearchOp2->setEnabled( true );
                amon.lineEditSearchValue2->setEnabled( true );
                if( searchMethod_->pFuncSearch2 == sDateAnniversaire )           
                    amon.lineEditSearchValue2->setInputMask( "9999/99/99;_" );
                else
                    amon.lineEditSearchValue2->setInputMask( "" );
            }
            break ;
        }
    }    
}

//----------------------------------------------------------------------------
// Evaluate search
//----------------------------------------------------------------------------
bool CSearch::isPrintable( const CPersonnes *p, dlgAmonSoft &amon ) const
{
    // Simple mask search with First Name, Last Name and Id
    bool bSimpleSearch = true;
    bool bGroupOk = true;

    mAssert( p != 0, "p != 0" );    

    switch( (uint) amon.comboBoxSearchProspect->currentItem() )
    {
        case 0: { break ; }
        case 1: { bGroupOk = ! p->isBeneficiaire(); break ; }
        case 2: { bGroupOk = p->isBeneficiaire(); break ; }
    }

    bSimpleSearch = p->getNom().find( amon.lineEditListerFiltreNom->text(), 0, false ) > -1
        && p->getPrenom().find( amon.lineEditListerFiltrePrenom->text(), 0, false ) > -1
        && bGroupOk;

    if( searchMethod_ == 0  || ! bSimpleSearch )
        return bSimpleSearch;

    bool bSearchMethod1 = searchMethod_->pFuncSearch1( p,
        amon.lineEditSearchValue1->text(),
        (enum operators) amon.comboBoxSearchOp1->currentItem(),
        searchMethod_->iDate1_ );

    if( searchMethod_->bNegatif1_ )
        bSearchMethod1 = ! bSearchMethod1;

    if( searchMethod_->eLiaison_ == eLiaisonNone )
        return bSearchMethod1;

    bool bSearchMethod2 = true;
    if( searchMethod_->pFuncSearch2 != 0 )
    {
        bSearchMethod2 = searchMethod_->pFuncSearch2( p,
            amon.lineEditSearchValue2->text(),
            (enum operators) amon.comboBoxSearchOp2->currentItem(),
            searchMethod_->iDate2_ );
        if( searchMethod_->bNegatif2_ )
            bSearchMethod2 = ! bSearchMethod2;
    }

    bool bReturn = true;
    switch( searchMethod_->eLiaison_ )
    { 
        case eLiaisonAND : { bReturn = bSearchMethod1 && bSearchMethod2; break ;  }
        case eLiaisonOR : { bReturn = bSearchMethod1 || bSearchMethod2; break ; }
    }

    return bReturn;
}

//----------------------------------------------------------------------------
// Load ressource file, which describe defined search
// Line format is Search Name:0:[!]command1 [AND|OR command2]
//----------------------------------------------------------------------------
static QStringList  splitLineConf( QString str )
{
    //QRegExp     sSeparator( "[;\t]" );
    QStringList listStr;

    listStr = QStringList::split( ":", str, true );

    QString     last = listStr.last();
    listStr.pop_back();

    QStringList listBisStr = QStringList::split( " ", last );

    for( uint i = 0; i < listBisStr.size(); i++ )
        listStr.append( listBisStr[i].stripWhiteSpace() );

    return listStr;
}

//----------------------------------------------------------------------------
// Get function according keyword
//----------------------------------------------------------------------------
t_SearchFunction  CSearch::getFunction( QString str )
{
    if( str == "AGE" )
        return sAge;
    if( str == "DATEANNIVERSAIRE" )
        return sDateAnniversaire;
    if( str == "ANNIVERSAIRE" )
        return sAnniversaire;
    if( str == "MUTUELLE" )
        return sMutuelle;
    if( str == "RETRAITE" )
        return sRetraite;
    if( str == "FISCALITERETRAITEMADELIN" )
        return sFiscaliteRetraiteMadelin;
    if( str == "REVENUS" )
        return sRevenus;
    if( str == "ASSURANCEVIE" )
        return sAssuranceVie;
    if( str == "BILAN" )
        return sBilan;
    mAssert( false, "false" ); // Invalid case
    return 0;
}

//----------------------------------------------------------------------------
// Get DATE attribute
//----------------------------------------------------------------------------
static bool lFSGetDate( QString strDeb, QString strFin, int *iDate )
{
    *iDate = 0;
    if( strDeb != "DANS" )
        return false;

    mAssert( iDate != 0, "iDate != 0" );
    mAssert( ! strFin.isEmpty(), "! strFin.isEmpty()" );

    QChar cUnite = strFin.at( strFin.length() - 1 );
    if( cUnite != QChar::null )
        strFin.remove( cUnite );

    int iNb = strFin.toInt();
    QDate currentDate = QDate::currentDate();
    QDate NDate = currentDate;
    
    if ( cUnite == 'a' || cUnite == 'A' )
        NDate.addYears( iNb );
    else
    {
        if ( cUnite == 'm' || cUnite == 'M' )
            NDate.addMonths( iNb );
        else
            NDate.addDays( iNb );
    }

    *iDate = currentDate.daysTo( NDate );  
    return true;
}

//----------------------------------------------------------------------------
// Load file search in memory
//----------------------------------------------------------------------------
void CSearch::loadFileSearch( QString filename )
{
    // TODO
    // Maybe should we return error list with errors
    std::string     temp;
    
    std::ifstream searchFile;
    searchFile.open( filename );

    if( ! searchFile.is_open() )
    { qDebug( "Unable to open file" ); return ; }

    uint id = 1;
    uint bar;
    while( std::getline( searchFile,temp ) )
    {
        bar = 0;
        if( temp.c_str()[0] == '#' ) // Comment out
            continue ;

        QStringList listStr = splitLineConf( temp.c_str() );

        t_searchMethod      *search = new t_searchMethod;
        search->uId_ = id++;
        search->sNom_ = listStr[bar++];
        if( listStr[bar++].contains( "0" ) )
            search->bPersonne_ = true;
        else
            search->bPersonne_ = false;
        
        if( listStr[bar].contains( "!" ) )
        {
            search->bNegatif1_ = true;
            bar++;
        }
        else
            search->bNegatif1_ = false;

        search->pFuncSearch1 = getFunction( listStr[bar++] );

        if( lFSGetDate( listStr[bar], listStr[bar + 1], &search->iDate1_ ) )
            bar += 2;

        qDebug( "Date:::: %i", search->iDate1_ );

        if( bar >= listStr.size() )
        {
            search->eLiaison_ = eLiaisonNone;
            search->pFuncSearch2 = 0;
            listMethods_.push_back( search );
            continue ;
        }

        if( listStr[bar] == "AND" )
            search->eLiaison_ = eLiaisonAND;
        else
            if( listStr[bar] == "OR" )
                search->eLiaison_ = eLiaisonOR;
            else search->eLiaison_ = eLiaisonNone;

        if( listStr[++bar].contains( "!" ) )
        {
            search->bNegatif2_ = true;
            bar++;
        }
        else
            search->bNegatif2_ = false;

        search->pFuncSearch2 = getFunction( listStr[bar++] );

        if( bar < listStr.size() )
            lFSGetDate( listStr[bar], listStr[bar + 1], &search->iDate2_ );

        listMethods_.push_back( search );
    }

    searchFile.close();
}

//----------------------------------------------------------------------------
// Export result of current search to CVS file
//----------------------------------------------------------------------------
void CSearch::exportCVS( QString strfile, dlgAmonSoft &amon ) const
{
    std::list< Datas::CPersonnes * >::const_iterator ite;

    qDebug( "CSearch::exportCVS" );

    std::ofstream searchFile;
    searchFile.open( strfile );

    if( ! searchFile.is_open() )
    { qDebug( "Unable to create file" ); return ; }

    searchFile << "Nom;Prenom;Adresse1;Adresse2;Code Postal;Ville;Telephone;Email\n";
    searchFile.flush();

    for( ite = g_listPersonnes.begin(); ite != g_listPersonnes.end(); ite++ )
    {
        if( isPrintable( *ite, amon ) && (*ite)->getID() < (ushort) -1 )
        {
            t_Adresse adresse = (*ite)->getAdresse();

            QString sline = (*ite)->getNom() + ";" + (*ite)->getPrenom() + ";";
            if( ! adresse.sRue_.isNull() )
                sline += adresse.sRue_;
            sline += ";";
            if( ! adresse.sComplement_.isNull() )
                sline += adresse.sComplement_;
            sline += ";";
            if( ! adresse.sCodePostal_.isNull() )
                sline += adresse.sCodePostal_;
            sline += ";";
            if( ! adresse.sVille_.isNull() )
                sline += adresse.sVille_;
            sline += ";";
            if( !(*ite)->getTelephone().isNull() )
                sline += (*ite)->getTelephone();
            sline += ";";
            if( ! (*ite)->getEmail().isNull() )
                sline += (*ite)->getEmail();
            
            searchFile << sline << "\n";
            searchFile.flush();
        }
    }
}

/*****************************************************************************
 *                          Low level search function                        *
 ****************************************************************************/
bool CSearch::sAge( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    mAssert( p != 0, "p != 0" );

    if( str.isEmpty() )
        return true;

    QDate currentDate = QDate::currentDate();
    QDate naissanceDate = p->getDateNaissance();
    if( naissanceDate.isNull() ) return false;

    ushort usAge = 0;

    usAge = currentDate.year() - naissanceDate.year();

    if( currentDate.month() < naissanceDate.month() )
        usAge--;
    if( currentDate.month() == naissanceDate.month() )
        if( currentDate.day() < naissanceDate.day() )
            usAge--;

    switch( op )
    {
        case eInf: { return usAge < str.toUShort(); }
        case eSup: { return usAge > str.toUShort(); }
        case eEgal: { return usAge == str.toUShort(); }
        case eDiff: { return usAge != str.toUShort(); }
        default: return false;
    }
}
bool CSearch::sAnniversaire( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    mAssert( p != 0, "p != 0" );

    QDate currentDate = QDate::currentDate();
    QDate naissanceDate = p->getDateNaissance();

    if( currentDate.month() == naissanceDate.month() 
        && currentDate.day() == naissanceDate.day() )
            return true;
    return false;
}
bool CSearch::sDateAnniversaire( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    mAssert( p != 0, "p != 0" );

    if( str.isEmpty() )
        return true;

    QDate speDate;
    QDate naissanceDate = p->getDateNaissance();
    speDate = speDate.fromString( str, Qt::ISODate );

    if( naissanceDate.isNull() ) return false;
    if( speDate.isNull() ) return true;

    switch( op )
    {
        case eInf: { return naissanceDate < speDate; }
        case eSup: { return naissanceDate > speDate; }
        case eEgal: { return naissanceDate == speDate; }
        case eDiff: { return naissanceDate != speDate; }
        default: return false;
    }
}
bool CSearch::sMutuelle( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    assert( p!= 0 );

    if( p->getPrevoyance() != 0 && p->getPrevoyance()->hasGaranties() )
        return true;
    return false;
}
bool CSearch::sRetraite( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    mAssert( p != 0, "p != 0" );

    if( p->getEpargne() != 0 && p->getEpargne()->listEpargnes_.size() != 0 )
        return true;
    return false;
}
bool CSearch::sFiscaliteRetraiteMadelin( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    mAssert( p != 0, "p != 0" );

    if( p->getEpargne() == 0 || p->getEpargne()->listEpargnes_.size() == 0 )
        return false;

    t_listEpargnes::const_iterator ite;
    for( ite = p->getEpargne()->listEpargnes_.begin();
         ite != p->getEpargne()->listEpargnes_.end(); ite++ )
    {
        if( (*ite)->eType_ == eLoiMadelin )
            return true;
    }
    return false;
}
bool CSearch::sRevenus( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    int     iRev = 0;
    int     iSpe = str.toInt();
    mAssert( p != 0, "p != 0" );

    if( str.isEmpty() )
        return true;

    if( p->getEpargne() != 0 && p->getEpargne()->listRevenus_.size() != 0 )
    {
        t_listRevenus::const_iterator ite;
        for( ite = p->getEpargne()->listRevenus_.begin();
            ite != p->getEpargne()->listRevenus_.end(); ite++ )
        {
            iRev += (*ite)->uMontant_;
        }
    }

    switch( op )
    {
        case eInf: { return iRev < iSpe; }
        case eSup: { return iRev > iSpe; }
        case eEgal: { return iRev == iSpe; }
        case eDiff: { return iRev != iSpe; }
    }
    return false;
}
bool CSearch::sAssuranceVie( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    mAssert( p != 0, "p != 0" );

    if( p->getEpargne() != 0 && p->getEpargne()->listAssurancesVie_.size() != 0 )
        return true;
    return false;
}
bool CSearch::sBilan( const CPersonnes *p, QString str, enum operators op, int date = 0 )
{
    mAssert( p != 0, "p != 0" );

    if( str.isEmpty() )
        return true;

    int uVal = -1;
    
    // Convert str for enum
    if( str.contains( "janv" ) > 0 ) uVal = 0;
    if( str.contains( "f�v" ) > 0 || str.contains( "fev" ) > 0 ) uVal = 1;
    if( str.contains( "mar" ) > 0 ) uVal = 2;
    if( str.contains( "avr" ) > 0 ) uVal = 3;
    if( str.contains( "mai" ) > 0 ) uVal = 4;
    if( str.contains( "juin" ) > 0 ) uVal = 5;
    if( str.contains( "juil" ) > 0 ) uVal = 6;
    if( str.contains( "ao" ) > 0 ) uVal = 7;
    if( str.contains( "sep" ) > 0 ) uVal = 8;
    if( str.contains( "oct" ) > 0 ) uVal = 9;
    if( str.contains( "nov" ) > 0 ) uVal = 10;
    if( str.contains( "dec" ) > 0 || str.contains( "d�c" ) > 0 ) uVal = 11;

    enum eMoisBilan bilan = p->getRevenus().getMoisBilan();

    if( bilan == (enum eMoisBilan) uVal )
        return true;
    return false;

    // TODO: See to use field MoisBilan in combobox.
/*    switch( op )
    {
        case eInf: { return naissanceDate < speDate; }
        case eSup: { return naissanceDate > speDate; }
        case eEgal: { return naissanceDate == speDate; }
        case eDiff: { return naissanceDate != speDate; }
        default: return false;
    }*/
}