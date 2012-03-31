/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: exception.h,v 1.1 2006/11/10 10:48:08 pascal Exp $
* $Log: exception.h,v $
* Revision 1.1  2006/11/10 10:48:08  pascal
* - Vérification de la cohérence des données lors de la validation. Pour le moment, on lève simplement une exception si l'on ne passe pas des entiers là où ils sont attendus.
*
*
*/

#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

#include <string>

class CException
{
    public:
        CException( const char *str ) : str_( str ) {}
        const char *cause() const { return str_.c_str(); }

    private:
        std::string     str_;
};

#endif /* _EXCEPTION_H_ */