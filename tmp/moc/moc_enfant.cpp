/****************************************************************************
** dlgEnfant meta object code from reading C++ file 'enfant.h'
**
** Created: jeu. 9. nov. 13:51:38 2006
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../Forms/enfant.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *dlgEnfant::className() const
{
    return "dlgEnfant";
}

QMetaObject *dlgEnfant::metaObj = 0;
static QMetaObjectCleanUp cleanUp_dlgEnfant( "dlgEnfant", &dlgEnfant::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString dlgEnfant::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgEnfant", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString dlgEnfant::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgEnfant", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* dlgEnfant::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"Ok", 0, 0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Ok()", &slot_0, QMetaData::Public },
	{ "languageChange()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"dlgEnfant", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_dlgEnfant.setMetaObject( metaObj );
    return metaObj;
}

void* dlgEnfant::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "dlgEnfant" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool dlgEnfant::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Ok(); break;
    case 1: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool dlgEnfant::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool dlgEnfant::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool dlgEnfant::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
