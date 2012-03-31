/****************************************************************************
** AmonSoft meta object code from reading C++ file 'Dynamique.h'
**
** Created: mer. 12. oct. 22:49:25 2005
**      by: The Qt MOC ($Id: moc_Dynamique.cpp,v 1.2 2005/10/12 22:26:43 pascal Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Dynamique.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *AmonSoft::className() const
{
    return "AmonSoft";
}

QMetaObject *AmonSoft::metaObj = 0;
static QMetaObjectCleanUp cleanUp_AmonSoft( "AmonSoft", &AmonSoft::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString AmonSoft::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "AmonSoft", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString AmonSoft::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "AmonSoft", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* AmonSoft::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = dlgAmonSoft::staticMetaObject();
    static const QUMethod slot_0 = {"showEmprunt", 0, 0 };
    static const QUMethod slot_1 = {"delEmprunt", 0, 0 };
    static const QUMethod slot_2 = {"showArretMaladie", 0, 0 };
    static const QUMethod slot_3 = {"delArretMaladie", 0, 0 };
    static const QUMethod slot_4 = {"showRenteEducation", 0, 0 };
    static const QUMethod slot_5 = {"delRenteEducation", 0, 0 };
    static const QUMethod slot_6 = {"showGarantieDeces", 0, 0 };
    static const QUMethod slot_7 = {"delGarantieDeces", 0, 0 };
    static const QUMethod slot_8 = {"showEmploi", 0, 0 };
    static const QUMethod slot_9 = {"delEmploi", 0, 0 };
    static const QUMethod slot_10 = {"showEnfant", 0, 0 };
    static const QUMethod slot_11 = {"delEnfant", 0, 0 };
    static const QUMethod slot_12 = {"showEpargne", 0, 0 };
    static const QUMethod slot_13 = {"delEpargne", 0, 0 };
    static const QUMethod slot_14 = {"showAssurancieVie", 0, 0 };
    static const QUMethod slot_15 = {"delAssurranceVie", 0, 0 };
    static const QUMethod slot_16 = {"showCompte", 0, 0 };
    static const QUMethod slot_17 = {"delCompte", 0, 0 };
    static const QUMethod slot_18 = {"showRevenus", 0, 0 };
    static const QUMethod slot_19 = {"delRevenus", 0, 0 };
    static const QUMethod slot_20 = {"showCharges", 0, 0 };
    static const QUMethod slot_21 = {"delCharges", 0, 0 };
    static const QUMethod slot_22 = {"showRetraite", 0, 0 };
    static const QUMethod slot_23 = {"delRetraite", 0, 0 };
    static const QUMethod slot_24 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "showEmprunt()", &slot_0, QMetaData::Public },
	{ "delEmprunt()", &slot_1, QMetaData::Public },
	{ "showArretMaladie()", &slot_2, QMetaData::Public },
	{ "delArretMaladie()", &slot_3, QMetaData::Public },
	{ "showRenteEducation()", &slot_4, QMetaData::Public },
	{ "delRenteEducation()", &slot_5, QMetaData::Public },
	{ "showGarantieDeces()", &slot_6, QMetaData::Public },
	{ "delGarantieDeces()", &slot_7, QMetaData::Public },
	{ "showEmploi()", &slot_8, QMetaData::Public },
	{ "delEmploi()", &slot_9, QMetaData::Public },
	{ "showEnfant()", &slot_10, QMetaData::Public },
	{ "delEnfant()", &slot_11, QMetaData::Public },
	{ "showEpargne()", &slot_12, QMetaData::Public },
	{ "delEpargne()", &slot_13, QMetaData::Public },
	{ "showAssurancieVie()", &slot_14, QMetaData::Public },
	{ "delAssurranceVie()", &slot_15, QMetaData::Public },
	{ "showCompte()", &slot_16, QMetaData::Public },
	{ "delCompte()", &slot_17, QMetaData::Public },
	{ "showRevenus()", &slot_18, QMetaData::Public },
	{ "delRevenus()", &slot_19, QMetaData::Public },
	{ "showCharges()", &slot_20, QMetaData::Public },
	{ "delCharges()", &slot_21, QMetaData::Public },
	{ "showRetraite()", &slot_22, QMetaData::Public },
	{ "delRetraite()", &slot_23, QMetaData::Public },
	{ "languageChange()", &slot_24, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"AmonSoft", parentObject,
	slot_tbl, 25,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_AmonSoft.setMetaObject( metaObj );
    return metaObj;
}

void* AmonSoft::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "AmonSoft" ) )
	return this;
    return dlgAmonSoft::qt_cast( clname );
}

bool AmonSoft::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: showEmprunt(); break;
    case 1: delEmprunt(); break;
    case 2: showArretMaladie(); break;
    case 3: delArretMaladie(); break;
    case 4: showRenteEducation(); break;
    case 5: delRenteEducation(); break;
    case 6: showGarantieDeces(); break;
    case 7: delGarantieDeces(); break;
    case 8: showEmploi(); break;
    case 9: delEmploi(); break;
    case 10: showEnfant(); break;
    case 11: delEnfant(); break;
    case 12: showEpargne(); break;
    case 13: delEpargne(); break;
    case 14: showAssuranceVie(); break;
    case 15: delAssurranceVie(); break;
    case 16: showCompte(); break;
    case 17: delCompte(); break;
    case 18: showRevenus(); break;
    case 19: delRevenus(); break;
    case 20: showCharges(); break;
    case 21: delCharges(); break;
    case 22: showRetraite(); break;
    case 23: delRetraite(); break;
    case 24: languageChange(); break;
    default:
	return dlgAmonSoft::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool AmonSoft::qt_emit( int _id, QUObject* _o )
{
    return dlgAmonSoft::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool AmonSoft::qt_property( int id, int f, QVariant* v)
{
    return dlgAmonSoft::qt_property( id, f, v);
}

bool AmonSoft::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
