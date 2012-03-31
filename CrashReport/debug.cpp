/*
* This software is a part to the amonsoft solution
* 
* Copyright Amon & Sesam Micro
* Developper contact pascal.bart@sesam-micro.Fr
*
* $Id: debug.cpp,v 1.1 2006/10/12 21:20:04 pascal Exp $
* $Log: debug.cpp,v $
* Revision 1.1  2006/10/12 21:20:04  pascal
* - Generation de minidump OK
*
* Revision 1.1  2006/10/09 10:06:07  pascal
* Version 0.2.4
*
* Nouvelles fonctionnalit�s
*
* - D�sormais lorsqu'une erreur "attendue" se d�clenche, un email nous est envoy� pour nous le signaler.
*
* - A chaque lancement du programme les fichiers de donn�es sont copi�s dans des fichiers ".bak", lesquels seront utilisables en cas de crash. Ce syst�me ne remplacement toutefois pas une sauvegarde quotidienne que l'on pourrait faire avec, e.g. http://www.clubic.com/telecharger-fiche11081-cobian-backup.html.
*
* - Lorsqu'une erreur est d�tect�e durant l'ex�cution du programme, le syst�me tant de faire une sauvegarde avant de se fermer.
*
* - G�n�ration de coredump, lors que le programme plante afin d'�tablir la raison du plantage. Ce module n'est pas tout � fait fonctionnel, il sera compl�ter dans la prochaine version.
*
* Correction de bugs
*
* - Correction d'un bug avec avec le bouton besoin / notes qui ne fonctionnait pas.
*
* Revision 1.1  2006/08/27 15:42:00  pascal
* - Syst�me de mise � jour automatique
*
*/

#include <qmessagebox.h>
#include <stdlib.h>
#include <qdir.h>

#include "debug.h"
#include "smtp.h"
#include "main.h"

void mAssert( bool b, const char *msg )
{
    if( b ) return ;

    // Gui warn
    M_MESSAGEBOX_CRITIC( "Une erreur de type Assert s'est produite", msg )

    // Mail report
    QString str = "Rapport d'Assert AmonSoft version ";
    str += STR_APP_VERSION;
    str += "\n";
    str += msg;

    Smtp *smtp = new Smtp( MAIL_FROM, MAIL_TO, SUBJECT, str );      
}

#define _WIN32_WINNT 0x0400

#include <windows.h>
#include <commctrl.h>
#include <DbgHelp.h>
//-----------------------------------------------------------------------------
// WriteMiniDump()
// 
//-----------------------------------------------------------------------------
int WriteMiniDump( LPEXCEPTION_POINTERS pExp )
{
    if( !IsDebuggerPresent() )
    {
            // Gui warn
        M_MESSAGEBOX_CRITIC( "Erreur irrecuperable", 
            "Generation d'un fichier de deboguage, veuillez contacter votre revendeur par mail � contact@sesam-micro.fr" )

// TODO: See to sent mail and upload through FTP
//        QString strMail = "Rapport d'exception\n";
//        strMail += "Minidump g�n�rer : contacter client";
//        Smtp *smtp = new Smtp( MAIL_FROM, MAIL_TO, SUBJECT, strMail ); 

        QString strFileName;
        strFileName = QString( "AmonSoft " ) + APP_VERSION + ".dmp";

        const char *str = strFileName;
        wchar_t    *pstr = new wchar_t[ strlen( str + 1 ) ];
        
        mbstowcs( pstr, str, strlen( str ) + 1 );
        HANDLE hDumpFile = CreateFile( pstr, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );

        if( hDumpFile == INVALID_HANDLE_VALUE )
        {
            qDebug( "Impossible de cr�er le fichier de d�bug !" );
            return EXCEPTION_EXECUTE_HANDLER;
        }

        MINIDUMP_EXCEPTION_INFORMATION eInfo;
        eInfo.ThreadId          = GetCurrentThreadId();
        eInfo.ExceptionPointers = pExp;
        eInfo.ClientPointers    = FALSE;
        
        bool b = MiniDumpWriteDump( GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpWithFullMemory, &eInfo, NULL, 0 );

        if( !b ) qDebug( "Impossible de generer minidump" );
        else qDebug( "Generation r�ussie" );

        CloseHandle( hDumpFile );
    }
    return EXCEPTION_EXECUTE_HANDLER;
}      

