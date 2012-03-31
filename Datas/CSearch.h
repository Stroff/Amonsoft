/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CSearch.h,v 1.3 2006/09/04 11:44:23 pascal Exp $
* $Log: CSearch.h,v $
* Revision 1.3  2006/09/04 11:44:23  pascal
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

#ifndef _CSEARCH_H_
# define _CSEARCH_H_

#include "defines.h"

namespace Datas
{
    // We want to have a meta search engine, which is able to find maximum
    // data with minimum code writing.

    enum operators
    {
        eInf, // "<"
        eSup, // ">"
        eEgal, // "="
        eDiff  // "!="
    };

    enum searchLiaison
    {
        eLiaisonAND,
        eLiaisonOR,
        eLiaisonNone
    };

    typedef bool (*t_SearchFunction)( const CPersonnes*, QString, enum operators, int );

    // We need a struct to keep in memory tuple Name:COM1 [[AND|OR] COM2]
    typedef struct
    {
        uint        uId_;
        QString     sNom_;
        bool        bPersonne_;
        bool        bNegatif1_;
        int         iDate1_;
        t_SearchFunction    pFuncSearch1;
        enum searchLiaison eLiaison_;
        bool        bNegatif2_;
        int         iDate2_;
        t_SearchFunction    pFuncSearch2;
    } t_searchMethod;

    class CSearch
    {
        public:
            CSearch() { searchMethod_ = 0; }
            ~CSearch() { /* TODO: Delete pointers */ }

            void loadFileSearch( QString filename );

            void loadInComboBox( QComboBox *, bool bPersonne ) const;

            void setSearchMethod( uint, dlgAmonSoft &amon );
            bool isPrintable( const CPersonnes*, dlgAmonSoft &amon ) const;

            void exportCVS( QString strfile, dlgAmonSoft &amon ) const;

        protected:
            t_SearchFunction  getFunction( QString );
            static bool sAge( const CPersonnes*, QString, enum operators, int date );
            static bool sAnniversaire( const CPersonnes*, QString, enum operators, int date );
            static bool sDateAnniversaire( const CPersonnes*, QString, enum operators, int date );
            static bool sMutuelle( const CPersonnes*, QString, enum operators, int date );
            static bool sRetraite( const CPersonnes*, QString, enum operators, int date );
            static bool sFiscaliteRetraiteMadelin( const CPersonnes*, QString, enum operators, int date );
            static bool sRevenus( const CPersonnes*, QString, enum operators, int date );
            static bool sAssuranceVie( const CPersonnes*, QString, enum operators, int date );
            static bool sBilan( const CPersonnes*, QString, enum operators, int date);

        private:
            t_searchMethod                      *searchMethod_;
            std::list< t_searchMethod* >        listMethods_;
    };
}

#endif /* _CSEARCH_H_ */