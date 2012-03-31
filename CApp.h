/*
 * This software is a part to the amonsoft solution
 * 
 * Copyright Amon & Sesam Micro
 * Developper contact pascal.bart@sesam-micro.Fr
 * 
 * $Id: CApp.h,v 1.4 2006/11/09 13:39:48 pascal Exp $
 */

#ifndef CAPP_H_
# define CAPP_H_

#include <list>
#include "CrashReport/debug.h"
#include "Forms/amonsoft.h"

// Preferences
#include "Preferences/CPreferences.h"

#define APP_VERSION                     "0.2.6"
#define STR_APP_VERSION                 "0.2 build 6"
#define CONF_COMPTABILITY               "0.1.10"
#define CONF_VERSION                    "0.2.5"

// Be carefull to include the good files.
#define M_MESSAGEBOX_CRITIC( a, b )    QMessageBox::critical ( g_gui, \
                                        a, \
                                        b, \
                                        QMessageBox::Ok, \
                                        QMessageBox::NoButton );

class CParser;
class CApp;

extern CParser                          *g_Parser;
extern CParser                          *g_ParserEntses;
extern CParser                          *g_ParserFamille;
                                        
extern Preferences::CPreferences        *g_Preferences;
extern dlgAmonSoft                      *g_gui;
                                        
extern CApp                             *g_App;

class CApp
{
    private:
        int argc_;
        char **argv_;

    public:
        // Constructor
        CApp( int argc, char **argv );

        void runApp();

    private:
        // Load datas from XML
        int loadXercesData( dlgAmonSoft & ); // Must be the first one
        int loadXercesDataFamille( dlgAmonSoft & );
        int loadXercesDataEntses( dlgAmonSoft & );

    public:
        // Save datas to XML
        void saveXercesData();
        void makeBackup();
};

#endif /* CAPP_H_ */