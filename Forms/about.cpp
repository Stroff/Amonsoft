/****************************************************************************
** Form implementation generated from reading ui file '.\Forms\about.ui'
**
** Created: ven. 6. avr. 16:32:32 2007
**      by: The User Interface Compiler ($Id: about.cpp,v 1.30 2007/04/06 15:34:43 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include ".\Forms\about.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a dlgAbout as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
dlgAbout::dlgAbout( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "dlgAbout" );
    setPaletteBackgroundColor( QColor( 255, 255, 255 ) );
    dlgAboutLayout = new QHBoxLayout( this, 11, 6, "dlgAboutLayout"); 

    textLabelAbout = new QLabel( this, "textLabelAbout" );
    dlgAboutLayout->addWidget( textLabelAbout );
    languageChange();
    resize( QSize(404, 150).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
dlgAbout::~dlgAbout()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dlgAbout::languageChange()
{
    setCaption( tr( "A propos" ) );
    textLabelAbout->setText( trUtf8( "\x3c\x68\x32\x3e\x41\x20\x70\x72\x6f\x70\x6f\x73\x20\x3a\x3c\x2f\x68\x32\x3e\xd\xa\xd\xa\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x43\x65\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x65\x20\x65\x73\x74\x20\x6c\x61\x20\x70\x72\x6f\x70\x72\x69\xc3\xa9\x74\xc3\xa9\x20\x63\x6f\x6e\x6a\x6f\x69\x6e\x74\x65\x20\x64\x65\x20\x6c\x61\x20\x73\x6f\x63\x69\xc3\xa9\x74\xc3\xa9\x20\x41\x6d\x6f\x6e\x20\x65\x74\x20\x53\x65\x73\x61\x6d\x27\x20\x6d\x69\x63\x72\x6f\x2e\x3c\x2f\x70\x3e\xd\xa\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x63\x65\x6e\x74\x65\x72\x22\x3e\x44\xc3\xa9\x74\x61\x69\x6c\x20\x73\x75\x72\x20\x6c\x61\x20\x6c\x69\x63\x65\x6e\x63\x65\x20\x64\x61\x6e\x73\x20\x6c\x65\x20\x66\x69\x63\x68\x69\x65\x72\x20\x6c\x69\x63\x65\x6e\x63\x65\x2e\x74\x78\x74\x3c\x2f\x70\x3e\xd\xa\xd\xa\x3c\x70\x20\x61\x6c\x69\x67\x6e\x3d\x22\x6c\x65\x66\x74\x22\x3e\x3c\x62\x3e\x43\x6f\x70\x79\x72\x69\x67\x68\x74\x3c\x2f\x62\x3e\x20\x32\x30\x30\x35\x2d\x32\x30\x30\x36\x20\x53\x65\x73\x61\x6d\x27\x20\x6d\x69\x63\x72\x6f\x20\x3c\x62\x3e\x56\x65\x72\x73\x69\x6f\x6e\x3c\x2f\x62\x3e\x20\x30\x2e\x32\x20\x62\x75\x69\x6c\x64\x20\x36\x3c\x2f\x70\x3e" ) );
}

