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
* Nouvelles fonctionnalités
*
* - Recherche complexe deuxième version
*     Les recherches sont définies dans le fichier search.ini qui se trouve par défaut dans "c:\program files\Amonsoft\".
*     La syntaxe de ce fichier est désormais de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE AND|OR [!] MOTCLE
*
*     Il est donc désormais possible de combiner deux critères de recherche.
*
* - Modification des mots clefs :
*         ANNIVERSAIRE renvoit désormais la liste des personnes dont c'est l'anniversaire (même jour et même mois que le système).
*         DATEANNIVERSAIRE nécessitera dans l'interface la saisie d'une date (même fonctionnement l'ancien ANNIVERSAIRE).
*
* - Les recherches par nom, prénom et type de clients sont combinés aux recherches complexes. Il est ainsi possible de chercher un client, par exemple, qui n'a pas de mutuelle et dont le prénom contient "dou".
*
* - "Exporter personnes" dans le menu Fichier, devient "Exporter". Il est désormais possible d'exporter une fiche entreprise en XML pour l'ouvrir avec Word.
*
* - Un système de mise à jour automatique est en place. La vérification s'effectue au lancement du programme, si une nouvelle version est disponible vous pouvez la télécharger. Lors du téléchargement de la nouvelle version, le programme est bloqué afin de ne pas y saisir d'information qui ne pourront être sauvegardée. La nouvelle version est téléchargée dans le répertoire courant du programme, une fois le téléchargement fini, l'installation est automatiquement lancée.
*
* Correction de bugs
*
* - Pas de corrections dans cette version
*
* Revision 1.2  2006/08/04 11:21:48  pascal
* Version 0.2.2
* Nouvelles fonctionnalités
*
* - Recherche complexe première version
*     Les recherches sont définies dans le fichier search.ini qui se trouve par défaut dans "c:\program files\Amonsoft\" (un fichier d'exemple est fourni lors de l'installation).
*     La syntaxe de ce fichier est de la forme :
*     # pour les commentaires
*     Nom:0:[!] MOTCLE
*
*     Toutes les lignes commençant par '#' ne seront pas interprétées par le programme.
*     Nom: représente le terme sous lequel vous retrouverez la recherche dans le programme.
*     0 signifie qu'il s'agît d'une recherche pour les particuliers.
*     ! facultatif, le point d'exclamation permet de renvoyer l'inverse des valeurs retournées par le MOTCLE
*     MOTCLE est une valeur dans la liste tel que
*         ANNIVERSAIRE nécessitera dans l'interface la saisie d'une date
*         AGE nécessitera dans l'interface la saisie d'une valeur numérique
*         REVENUS nécessitera dans l'interface la saisie d'une valeur numérique
*         BILAN nécessitera dans l'interface la saisie d'une valeur texte
*         MUTUELLE, RETRAITE, FISCALITERETRAITEMADELIN et ASSURANCEVIE ne requière aucune saisie dans l'interface
*
*     Attention pour le moment, les recherches par Nom, Prénom ou prospect ne tiennent pas comptent de la recherche complexe sélectionnée.
*     Par exemple, il n'est pas possible encore, d'avoir la liste des prospect, qui n'ont pas d'assurance vie.
*
* - Les espaces superflus ne sont plus sauvegardés dans les fichiers XML
* - Dans la liste des dossiers personnes Fichier/Exporter Personnes permet d'exporter la liste des personnes concernées par une recherche complexe dans un fichier CSV compatible avec Excel.
* - Lorsqu'une fiche client ou prospect est ouverte Fichier/Exporter Personnes permet d'exporter la personne courante dans deux fichiers XML compatible Word.
*
* Correction de bugs
*
* - La liste des revenus n'étaient pas sauvegardée dans les fichiers XML
* - Lors de l'ouverture des formulaires annexes d'une fiche les compagnies d'assurance n'étaient pas toujours correctement sélectionnées
* - Une personne ne peut plus être mariée qu'à une autre personne (plus de polygamie)
* - Les filtres simples par Nom, Prénom et Type de client souffraient de bugs lorsqu'on voulait utiliser les 3 critères de recherche
*
* Revision 1.1  2006/06/21 11:24:11  pascal
* - Fichier de recherche avancé
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