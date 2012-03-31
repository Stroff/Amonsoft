/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: exception.h,v 1.1 2006/11/10 10:48:08 pascal Exp $
* $Log: exception.h,v $
* Revision 1.1  2006/11/10 10:48:08  pascal
* - V�rification de la coh�rence des donn�es lors de la validation. Pour le moment, on l�ve simplement une exception si l'on ne passe pas des entiers l� o� ils sont attendus.
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