/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: CPreferences.h,v 1.3 2006/04/29 16:29:57 pascal Exp $
 * $Log: CPreferences.h,v $
 * Revision 1.3  2006/04/29 16:29:57  pascal
 * Version 0.1 build 13
 * - Correction d'un bug avec les listes 'static' qui étaient partagées
 * - Suppression des boutons "Valider" & "Rester"
 * - Modification des images des boutons
 * - Personnes et Entreprises ne sont plus manipulé que par Id
 * - Correction de bug : suppression de la liste des retraites
 * - Réactivation de la sauvegarde manuel et correction des bugs qui ont conduit à sa désactivation
 *
 * Revision 1.2  2006/04/16 22:20:52  pascal
 * - liens entre employés & entreprises
 * - correction de bug sur le chargement d'une personne depuis une autre
 * - chargement des gérants & employés depuis leur entreprise OK
 * - les tabulations sont dans le bon ordre
 * - version 0.1.10
 *
 * Revision 1.1  2006/03/21 10:42:25  pascal
 * *** empty log message ***
 *
 *
 */

#ifndef _CPREFERENCES_H_
# define _CPREFERENCES_H_

#include <qstring.h>
#include <list>

#include "XMLParser.h"
#include "Preferences/Compagnies.h"
#include "Preferences/Conseillers.h"

namespace Preferences
{
    typedef std::list< QString* >           t_listQString;

    // List of advisors
    typedef std::list< CCabinet * >         t_listCabinet;

    class CPreferences
    {
        public:
            // Carrefull ! Constructor will load information from preferences file
            CPreferences();
            ~CPreferences();

            void saveToXerces();

        public:
            t_listQString               listEpargnes_;
            t_listQString               listComptes_;

            CCompagnies                 &getCompagnies() { return compagnies_; }

            CCabinet                    *newCabinet( QString name, enum eTypeCabinet type );
            CCabinet                    *getCabinet( QString name );
            void                        delCabinet( QString name );

            void                        loadInQTCabinet( QListView * ) const;
            void                        loadInQTCabinet( QComboBox *, enum eTypeCabinet ) const;

        protected:
            void saveListToXML( t_listQString&, const char *,
                                XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const;
            void loadListFromXML( t_listQString&, const char *,
                                  XERCES_CPP_NAMESPACE::DOMNode *xmlNode );

        private:
            CCompagnies                 compagnies_;
            t_listCabinet               cabinets_;
            CParser                     *Parser_;
    };
}

#endif /* _CPREFERENCES_H_ */