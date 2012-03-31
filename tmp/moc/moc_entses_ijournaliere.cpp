/****************************************************************************
** dlgIJournaliere meta object code from reading C++ file 'entses_ijournaliere.h'
**
** Created: mar. 6. févr. 19:37:16 2007
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../Forms/entses_ijournaliere.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *dlgIJournaliere::className() const
{
    return "dlgIJournaliere";
}

QMetaObject *dlgIJournaliere::metaObj = 0;
static QMetaObjectCleanUp cleanUp_dlgIJournaliere( "dlgIJournaliere", &dlgIJournaliere::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString dlgIJournaliere::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgIJournaliere", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString dlgIJournaliere::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgIJournaliere", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* dlgIJournaliere::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"newSlot", 0, 0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "newSlot()", &slot_0, QMetaData::Public },
	{ "languageChange()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"dlgIJournaliere", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_dlgIJournaliere.setMetaObject( metaObj );
    return metaObj;
}

void* dlgIJournaliere::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "dlgIJournaliere" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool dlgIJournaliere::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newSlot(); break;
    case 1: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool dlgIJournaliere::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool dlgIJournaliere::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool dlgIJournaliere::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
