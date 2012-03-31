/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 * 
 * $Id: main.cpp,v 1.23 2006/10/12 21:19:33 pascal Exp $
 */
#include <windows.h>
#include "main.h"

extern int WriteMiniDump( LPEXCEPTION_POINTERS );

/*
 *   Main function
 *   Entry point
 */

int main( int argc, char **argv )
{
    CApp app( argc, argv );

  __try
  {
      app.runApp();
  }
  __except( WriteMiniDump( GetExceptionInformation() ) )
  {
      __try
      {
        qDebug( "Sauvegarde des fichiers de données" );
        app.saveXercesData();
      }
      __except( EXCEPTION_EXECUTE_HANDLER )
      { qDebug("*Sauvegarde Impossible*" ); }
  }
  return 0;
}