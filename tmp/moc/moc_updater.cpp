/****************************************************************************
** CUpdater meta object code from reading C++ file 'updater.h'
**
** Created: jeu. 9. nov. 13:51:51 2006
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../updater.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CUpdater::className() const
{
    return "CUpdater";
}

QMetaObject *CUpdater::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CUpdater( "CUpdater", &CUpdater::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CUpdater::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CUpdater", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CUpdater::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CUpdater", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CUpdater::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "done", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"done", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "done(bool)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CUpdater", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CUpdater.setMetaObject( metaObj );
    return metaObj;
}

void* CUpdater::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CUpdater" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool CUpdater::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: done((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CUpdater::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CUpdater::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool CUpdater::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
