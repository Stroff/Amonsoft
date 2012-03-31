/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: CConseiller.h,v 1.10 2006/04/16 22:12:24 pascal Exp $
* $Log: CConseiller.h,v $
* Revision 1.10  2006/04/16 22:12:24  pascal
* - liens entre employ�s & entreprises
* - correction de bug sur le chargement d'une personne depuis une autre
* - chargement des g�rants & employ�s depuis leur entreprise OK
* - les tabulations sont dans le bon ordre
* - version 0.1.10
*
* Revision 1.9  2006/03/21 10:42:16  pascal
* *** empty log message ***
*
* Revision 1.8  2005/12/27 10:28:04  pascal
* - Release 1.0.6 (build 1 & 2)
* - Nouveaux champs pour les particuliers
* - Corrections de bugs chargement XML / sauvegarde XML
* - Corrections de bugs chargement QT / sauvegardes QT
* - Modification de l'installeur pour ne pas �craser les fichiers de donn�es
* - Modification de la mani�re dont sont g�r�s les QDate
* - Correction du bug avec le slot DelAssuranceVie
* - TODO : m�j
* - Liens b�n�ficiaire / prospect corrig�s
*
* Revision 1.7  2005/10/14 08:41:10  pascal
* - correction d'un bogue lors de la lecture du fichier XML : Un �l�ment vide �tait ajout�
*
* Revision 1.6  2005/10/11 22:53:57  pascal
* - CPersonnes peut lire depuis le XML ses donn�es
* - CConseillers aussi
* - CEpargnes en cours !
*
* Revision 1.5  2005/10/11 08:12:16  pascal
* - nouvelle CEntreprise dans les nouveaux fichiers CEntreprise.*
* - les classes de donn�es n'h�ritent plus de CDatas � part CPersonne et CEntreprise
* - les fonctions li�es � QT sont toutes impl�ment�es
* - les fonctions saveToXML sont impl�ment�es pour les particuliers
*
* Revision 1.4  2005/09/29 15:51:27  pascal
* - Les boutons des onglets de la section ajouter poss�dent d�sormais une image
* - copyFromQT est bient�t impl�ment�e pour toutes les classes
*
* Revision 1.3  2005/09/27 15:28:11  pascal
* - Mise en place dans CData des m�thodes relatives � l'interface : r�alisation du squelette
*
* Revision 1.2  2005/09/09 15:49:38  pascal
* - Ajout de la classes virtuel pure CDatas
* - Toutes les classes de Datas/ d�rive d�sormais de CDatas et d�finisse les classes virtuelles pures
*
*/

#ifndef _CCONSEILLER_H_
# define _CCONSEILLER_H_

// QT basic types
#include <qstring.h>

#include "CDatas.h"
#include "defines.h"
#include "Preferences/CPreferences.h"

namespace Datas
{

  /*
   * CConseiller
   * Contain information about known advisers
   */

  class CConseiller
  {
    public:
      // Constructor
      CConseiller( enum Preferences::eTypeCabinet type, QString nom, const Preferences::CCabinet *societe ) :
          eType_( type ),
          sNom_( nom ),
          sSociete_( societe ) {}
      CConseiller( enum Preferences::eTypeCabinet type )
      { eType_ = type; sSociete_ = 0; }
      // Destructor
      ~CConseiller();

    public:
      // CDatas virtual functions
      virtual int loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );
      virtual int saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode, XERCES_CPP_NAMESPACE::DOMElement * ) const;

      // Graphical functions
      virtual void loadInQT( dlgAmonSoft & ) const;
      virtual void copyFromQT( const dlgAmonSoft & );

    private:
      enum Preferences::eTypeCabinet    eType_;
      QString                           sNom_;
      const Preferences::CCabinet       *sSociete_;
  };
}

#endif /* _CCONSEILLER_H_ */