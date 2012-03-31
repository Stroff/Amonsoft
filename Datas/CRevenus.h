/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CRevenus.h,v 1.11 2006/10/12 11:29:46 pascal Exp $
* $Log: CRevenus.h,v $
* Revision 1.11  2006/10/12 11:29:46  pascal
* - Suppression des inpputs Masks
* - Bénéficiaire s'appel désormais client
* - Mois bilan utilise une comboBox
*
* Revision 1.10  2006/06/21 11:23:24  pascal
* - systeme de recherche avancé
* - correction de bug dans le chargement des Revenus et des Charges
* - correction de bug dans le chargement des XML des familles
*
* Revision 1.9  2006/01/20 13:18:45  pascal
* Version 1.0.8b
* - Modifications graphiques et moteurs à tout va, afin de correspondre au mieux aux exigences du client
* - Le double clique sur les listes permet désormais de modifier le contenus du champs correspondant
* - Grosses modifications des fichiers de données
*
* Revision 1.8  2005/12/27 10:28:05  pascal
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
* Revision 1.7  2005/10/12 16:11:21  pascal
* - implementation des fonctions loadFromXerces des classes CPersonnes *
* - bug: ajout de CPrevoyance dans CPersonnes
*
* Revision 1.6  2005/10/11 08:12:17  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de données n'héritent plus de CDatas à part CPersonne et CEntreprise
* - les fonctions liées à QT sont toutes implémentées
* - les fonctions saveToXML sont implémentées pour les particuliers
*
* Revision 1.5  2005/10/05 17:14:23  pascal
* - nouvelle structure de données pour stocker les informations sur l'épargne
* - résolution du problème lié à l'épouse : méthodes surchargées avec un bool supplémentaire permettant de savoir à qui l'on a à faire dans CPersonne et dans CRevenus.
* - loadInQT implémenté pour toutes les classes
*
* Revision 1.4  2005/09/29 15:51:28  pascal
* - Les boutons des onglets de la section ajouter possèdent désormais une image
* - copyFromQT est bientôt implémentée pour toutes les classes
*
* Revision 1.3  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des méthodes relatives à l'interface : réalisation du squelette
*
* Revision 1.2  2005/09/09 15:49:38  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ dérive désormais de CDatas et définisse les classes virtuelles pures
*
*/

#ifndef _CREVENUS_H_
# define _CREVENUS_H_

#include "defines.h"
#include "CDatas.h"

namespace Datas
{
    enum eStatutPro
    {
        eSalarie,
        eSalarieCadre,
        eETAM,
        eFonctionnaire,
        eArtisant,
        eCommercant,
        eLiberal,
        eExploitantAgricole
    };

    enum eMoisBilan
    {
        eJanvier,
        eFevrier,
        eMars,
        eAvril,
        eMai,
        eJuin,
        eJuillet,
        eAout,
        eSeptembre,
        eOctobre,
        eNovembre,
        eDecembre
    };


  /*
   * CRevenus
   * Contain informations about incomes
   */

  class CRevenus
  {
    protected:
      // Incoming after or before charges
      typedef enum  {
        eRevenusBrut,
        eRevenusNet }                             t_TypeRevenus;
      // Abstract incoming type
      typedef struct {
        uint               uSalaire;
        t_TypeRevenus      tTypeRevenus; }        t_Revenus;

    public:
      // Constructor
      CRevenus();
      // Destructor
      ~CRevenus();

    public:
      // CDatas virtual functions
      int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
      int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

      // Graphical functions
      virtual void loadInQT( dlgAmonSoft & ) const;
      virtual void copyFromQT( const dlgAmonSoft & );

      // Overloaded method for friend
      virtual void loadInQT( dlgAmonSoft &, bool bFriend ) const;
//      virtual void copyFromQT( const dlgAmonSoft &, bool bFriend );

      enum eMoisBilan       getMoisBilan() const { return eMoisBilan_; }

    private:
       t_Revenus            SalaireAnnuel_;
       uint                 uBNC_;
       uint                 uBIC_;
       uint                 uRevenusFonciers_;
       uint                 uDividendes_;
       uint                 uAutres_;
       enum eStatutPro      sStatutPro_;
       enum eMoisBilan      eMoisBilan_;
       QString              sEmployeur_;
       QString              sFonction_;
  };
}
#endif /* _CREVENUS_H_ */