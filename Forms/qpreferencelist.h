/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
* 
* $Id: main.cpp,v 1.5 2005/10/11 07:57:25 pascal Exp $
*/
#ifndef _QPREFERENCELIST_H_
# define _QPREFERENCELIST_H_


#include <qwidget.h>

class QPreferenceList : public QWidget
{
    Q_OBJECT

    public:
        QPreferenceList( QWidget *parent = 0, const char *name = 0 ) :
            QWidget( parent, name )
        {
            QHBoxLayout *layout = new QHBoxLayout( this );
            layout->setMargin( 0 );
        }
        ~QPreferenceList() {}
};

#endif /* _QPREFERENCELIST_H_ */