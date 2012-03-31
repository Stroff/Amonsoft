/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: Conseillers.h,v 1.2 2006/04/16 22:20:53 pascal Exp $
 * $Log: Conseillers.h,v $
 * Revision 1.2  2006/04/16 22:20:53  pascal
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

#ifndef _CONSEILLERS_H_
# define _CONSEILLERS_H_

#include <qstring.h>
#include <qlistview.h>
#include <qcombobox.h>
#include <list>

#include "XMLParser.h"

namespace Preferences
{

    enum eTypeCabinet
    {       
        eComptable,
        eNotaire,
        eAvocat
    };

    class CCabinet
    {
        public:
            // Constructor
            CCabinet( QString nom, enum eTypeCabinet eType )
                : sNom_( nom ), eCabinet_( eType ) {};
            CCabinet() {};
            // Destructor
            ~CCabinet()
            {
                if( listConseillers_.size() > 0 )
                {
                    std::list< QString * >::iterator    ite;
                    for( ite = listConseillers_.begin(); ite != listConseillers_.end(); ite++ )
                        delete *ite;
                }
            }

            void saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode,
                            XERCES_CPP_NAMESPACE::DOMElement *xmlElement ) const;
            void loadFromXML( XERCES_CPP_NAMESPACE::DOMElement *xmlNode );

            void loadInQT( QListView * ) const;
            void loadInQT( QComboBox * ) const;

            void                deleteIt() { bDeleted_ = true; }
            enum eTypeCabinet   getType() const { return eCabinet_; }
            QString             getTypeText() const
            { 
                switch( eCabinet_ )
                {
                    case eComptable: return "Cabinet comptable";
                    case eNotaire: return "Etude notariale";
                    case eAvocat: return "Cabinet avocats";
                    default: return "Inconnu";
                }
            }
            QString             getName() const { return sNom_; }

            void                setName( QString str ) { sNom_ = str; }
            void                setType( enum eTypeCabinet type ) { eCabinet_ = type; }

            void                newConseiller( QString name ) { listConseillers_.push_back( new QString( name ) ); }
            QString             *getConseiller( QString name );
            void                delConseiller( QString name )
            {
                QString *nn = getConseiller( name );
                if( nn == 0 ) return;
                listConseillers_.remove( nn );
                delete nn;
            }

        private:
            std::list< QString* >   listConseillers_;
            enum eTypeCabinet       eCabinet_;
            QString                 sNom_;
            bool                    bDeleted_;
    };
}

#endif /* _CONSEILLERS_H_ */