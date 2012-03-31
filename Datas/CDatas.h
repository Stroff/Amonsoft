/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CDatas.h,v 1.12 2006/11/10 10:48:06 pascal Exp $
* $Log: CDatas.h,v $
* Revision 1.12  2006/11/10 10:48:06  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
* Revision 1.11  2006/09/04 11:44:22  pascal
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
* Revision 1.10  2006/08/04 11:21:48  pascal
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
* Revision 1.9  2006/06/21 11:23:23  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.8  2006/06/02 19:11:17  pascal
* Version 0.2.0
* - Importation depuis CSV format : Last Name / First Name / Birthday / address1 / address2 / ZIP / City / Phone
* - Suppression des masques sur les pourcentages dans QT
*
* Revision 1.7  2006/05/23 16:06:39  pascal
* - Correction du bugs sur les clients phantômes
* - Début des fonctionnalités de recherche
* - Correction du bugs sur les listes de status pro
* - Charger / Valider: Enregistre également les XML désormais
* - Correction du bugs avec le chargement des enfants dans famille
* - Correction du bug qui empéchait le chargement d'un client depuis une entrses
* - Amélioration interface : champs plus larges et corrections divers
* - Correction du bug avec l'enregistrement des dates de naissance
* - L'ajout d'un dirigeant ou d'un employé permet de crée des clients prospect directement
* - Suppression de l'onglet liste des prospects dans les fiches personnelles
*
* Revision 1.6  2006/04/16 22:12:24  pascal
* - liens entre employés & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des gérants & employés depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.5  2005/10/11 22:53:57  pascal
* - CPersonnes peut lire depuis le XML ses données
* - CConseillers aussi
* - CEpargnes en cours !
*
* Revision 1.4  2005/10/11 08:12:16  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
* Revision 1.3  2005/09/29 15:51:27  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.2  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
*
* Revision 1.1  2005/09/09 15:49:39  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
*
*/

#ifndef _CDATAS_H_
# define _CDATAS_H_

#include <qcombobox.h>
#include <list>

#include "defines.h"

#include "Forms/amonsoft.h"
#include "XMLParser.h"

namespace Datas
{
    class CPersonnes;
    class CEntreprise;
    class CSearch;

    extern std::list< Datas::CPersonnes * >        g_listPersonnes;
    extern std::list< Datas::CEntreprise * >       g_listEntreprises;

    extern CSearch                                 *g_Search;

    void        loadEntsesInComboBox( QComboBox * );
    CEntreprise *getEntses( ushort uId );

    void        loadPersonneInListView( QListView *, CSearch &, dlgAmonSoft &amon );
    void        loadEntsesInListView( QListView *, const QString patRaison, const QString patSiret,
            bool (*cmp)(const Datas::CEntreprise*, QString strRaison, QString strSiret) = 0 );

    // Search function
    bool         searchEntsesSimple( const CEntreprise*,
                                    const QString strRaison,
                                    const QString strSiret );

    CPersonnes   *getPersonne( ushort usId );
    CPersonnes   *getPersonne( QString sNom, QString sPrenom, QDate dNaissance );

    void         exportPersonne( QString filename, QString filenameF, const CPersonnes & );
    void         exportEntreprise( QString filename, const CEntreprise & );

    void         importerCSV( QString fn, dlgAmonSoft *amon );

    unsigned int get_uint_from_qlineedit( QLineEdit *a );
    unsigned short get_ushort_from_qlineedit( QLineEdit *a );

    // Address container
    typedef struct  {
        QString       sRue_;
        QString       sComplement_;
        QString       sCodePostal_;
        QString       sVille_;
    }                                              t_Adresse;

    class CDatas
    {
        public:
        // Xerces call functions
        virtual int loadFromXML( XERCES_CPP_NAMESPACE::DOMElement * )      = 0;
        virtual int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument * ) const = 0;
    };

}

#endif /* _CDATAS_H_ */