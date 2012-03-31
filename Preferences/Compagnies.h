/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 *
 * $Id: Compagnies.h,v 1.1 2006/03/21 10:42:25 pascal Exp $
 * $Log: Compagnies.h,v $
 * Revision 1.1  2006/03/21 10:42:25  pascal
 * *** empty log message ***
 *
 *
 */

#ifndef _COMPAGNIES_H_
# define _COMPAGNIES_H_

#include <qstring.h>
#include <qlistview.h>
#include <qcombobox.h>
#include <list>

#include "XMLParser.h"

namespace Preferences
{
    enum eTypeCompagnie
    {
        eTCAssurance,
        eTCBanque,
        eTCBanqueAssurance
    };

    struct SCompagnie
    {
        QString             sCompagnie_;
        enum eTypeCompagnie eType_;
        QString             sContact_;
        bool                bDelete_;
    };

    // TODO : Overload operator to use SCompagnie easylier

    typedef std::list< struct SCompagnie* >     t_listCompagnies;

    class CCompagnies
    {
        public:
            // Constructor
            CCompagnies() {}

            // Destructor
            ~CCompagnies() 
            {
                t_listCompagnies::iterator  ite = listCompagnies_.begin();

                for( ; ite != listCompagnies_.end(); ite++ )
                    delete *ite;
            }

            struct SCompagnie   *addCompagnie( QString name, enum eTypeCompagnie type, QString contact );
            void                delCompagnie( QString name );
            struct SCompagnie   *getCompagnie( QString name );

            void saveToXML( XERCES_CPP_NAMESPACE::DOMDocument *xmlNode ) const;
            void loadFromXML( XERCES_CPP_NAMESPACE::DOMNode *xmlNode );

            void loadInQT( QListView * ) const;
            void loadInQT( QComboBox * ) const;

        protected:
            t_listCompagnies  listCompagnies_;

        public:
            static QString        typeCompagnieToString( enum eTypeCompagnie );
    };
}

#endif /* _COMPAGNIES_H_ */