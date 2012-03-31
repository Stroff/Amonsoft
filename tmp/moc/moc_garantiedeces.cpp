/****************************************************************************
** dlgGarantieDeces meta object code from reading C++ file 'garantiedeces.h'
**
** Created: jeu. 9. nov. 13:51:40 2006
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../Forms/garantiedeces.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *dlgGarantieDeces::className() const
{
    return "dlgGarantieDeces";
}

QMetaObject *dlgGarantieDeces::metaObj = 0;
static QMetaObjectCleanUp cleanUp_dlgGarantieDeces( "dlgGarantieDeces", &dlgGarantieDeces::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString dlgGarantieDeces::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgGarantieDeces", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString dlgGarantieDeces::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgGarantieDeces", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* dlgGarantieDeces::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"Ok", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "Ok()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"dlgGarantieDeces", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_dlgGarantieDeces.setMetaObject( metaObj );
    return metaObj;
}

void* dlgGarantieDeces::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "dlgGarantieDeces" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool dlgGarantieDeces::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: Ok(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool dlgGarantieDeces::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool dlgGarantieDeces::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool dlgGarantieDeces::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
