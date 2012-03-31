/****************************************************************************
** AmonSoft meta object code from reading C++ file 'Dynamique.h'
**
** Created: lun. 20. nov. 16:46:29 2006
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../Forms/Dynamique.h"
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
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"showEmprunt", 1, param_slot_1 };
    static const QUMethod slot_2 = {"delEmprunt", 0, 0 };
    static const QUMethod slot_3 = {"showArretMaladie", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_4 = {"showArretMaladie", 1, param_slot_4 };
    static const QUMethod slot_5 = {"delArretMaladie", 0, 0 };
    static const QUMethod slot_6 = {"showRenteEducation", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_7 = {"showRenteEducation", 1, param_slot_7 };
    static const QUMethod slot_8 = {"delRenteEducation", 0, 0 };
    static const QUMethod slot_9 = {"showGarantieDeces", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_10 = {"showGarantieDeces", 1, param_slot_10 };
    static const QUMethod slot_11 = {"delGarantieDeces", 0, 0 };
    static const QUMethod slot_12 = {"showEmploi", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_13 = {"showEmploi", 1, param_slot_13 };
    static const QUMethod slot_14 = {"delEmploi", 0, 0 };
    static const QUMethod slot_15 = {"showEnfant", 0, 0 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_16 = {"showEnfant", 1, param_slot_16 };
    static const QUMethod slot_17 = {"delEnfant", 0, 0 };
    static const QUMethod slot_18 = {"showEpargne", 0, 0 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_19 = {"showEpargne", 1, param_slot_19 };
    static const QUMethod slot_20 = {"delEpargne", 0, 0 };
    static const QUMethod slot_21 = {"showAssuranceVie", 0, 0 };
    static const QUParameter param_slot_22[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_22 = {"showAssuranceVie", 1, param_slot_22 };
    static const QUMethod slot_23 = {"delAssuranceVie", 0, 0 };
    static const QUMethod slot_24 = {"showCompte", 0, 0 };
    static const QUParameter param_slot_25[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_25 = {"showCompte", 1, param_slot_25 };
    static const QUMethod slot_26 = {"delCompte", 0, 0 };
    static const QUMethod slot_27 = {"showRevenus", 0, 0 };
    static const QUParameter param_slot_28[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_28 = {"showRevenus", 1, param_slot_28 };
    static const QUMethod slot_29 = {"delRevenus", 0, 0 };
    static const QUMethod slot_30 = {"showCharges", 0, 0 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_31 = {"showCharges", 1, param_slot_31 };
    static const QUMethod slot_32 = {"delCharges", 0, 0 };
    static const QUMethod slot_33 = {"showRetraite", 0, 0 };
    static const QUParameter param_slot_34[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_34 = {"showRetraite", 1, param_slot_34 };
    static const QUMethod slot_35 = {"delRetraite", 0, 0 };
    static const QUMethod slot_36 = {"showKDeces", 0, 0 };
    static const QUParameter param_slot_37[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_37 = {"showKDeces", 1, param_slot_37 };
    static const QUMethod slot_38 = {"delKdeces", 0, 0 };
    static const QUMethod slot_39 = {"showIJournalier", 0, 0 };
    static const QUParameter param_slot_40[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_40 = {"showIJournalier", 1, param_slot_40 };
    static const QUMethod slot_41 = {"delIJournalier", 0, 0 };
    static const QUMethod slot_42 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "showEmprunt()", &slot_0, QMetaData::Public },
	{ "showEmprunt(QListViewItem*)", &slot_1, QMetaData::Public },
	{ "delEmprunt()", &slot_2, QMetaData::Public },
	{ "showArretMaladie()", &slot_3, QMetaData::Public },
	{ "showArretMaladie(QListViewItem*)", &slot_4, QMetaData::Public },
	{ "delArretMaladie()", &slot_5, QMetaData::Public },
	{ "showRenteEducation()", &slot_6, QMetaData::Public },
	{ "showRenteEducation(QListViewItem*)", &slot_7, QMetaData::Public },
	{ "delRenteEducation()", &slot_8, QMetaData::Public },
	{ "showGarantieDeces()", &slot_9, QMetaData::Public },
	{ "showGarantieDeces(QListViewItem*)", &slot_10, QMetaData::Public },
	{ "delGarantieDeces()", &slot_11, QMetaData::Public },
	{ "showEmploi()", &slot_12, QMetaData::Public },
	{ "showEmploi(QListViewItem*)", &slot_13, QMetaData::Public },
	{ "delEmploi()", &slot_14, QMetaData::Public },
	{ "showEnfant()", &slot_15, QMetaData::Public },
	{ "showEnfant(QListViewItem*)", &slot_16, QMetaData::Public },
	{ "delEnfant()", &slot_17, QMetaData::Public },
	{ "showEpargne()", &slot_18, QMetaData::Public },
	{ "showEpargne(QListViewItem*)", &slot_19, QMetaData::Public },
	{ "delEpargne()", &slot_20, QMetaData::Public },
	{ "showAssuranceVie()", &slot_21, QMetaData::Public },
	{ "showAssuranceVie(QListViewItem*)", &slot_22, QMetaData::Public },
	{ "delAssuranceVie()", &slot_23, QMetaData::Public },
	{ "showCompte()", &slot_24, QMetaData::Public },
	{ "showCompte(QListViewItem*)", &slot_25, QMetaData::Public },
	{ "delCompte()", &slot_26, QMetaData::Public },
	{ "showRevenus()", &slot_27, QMetaData::Public },
	{ "showRevenus(QListViewItem*)", &slot_28, QMetaData::Public },
	{ "delRevenus()", &slot_29, QMetaData::Public },
	{ "showCharges()", &slot_30, QMetaData::Public },
	{ "showCharges(QListViewItem*)", &slot_31, QMetaData::Public },
	{ "delCharges()", &slot_32, QMetaData::Public },
	{ "showRetraite()", &slot_33, QMetaData::Public },
	{ "showRetraite(QListViewItem*)", &slot_34, QMetaData::Public },
	{ "delRetraite()", &slot_35, QMetaData::Public },
	{ "showKDeces()", &slot_36, QMetaData::Public },
	{ "showKDeces(QListViewItem*)", &slot_37, QMetaData::Public },
	{ "delKdeces()", &slot_38, QMetaData::Public },
	{ "showIJournalier()", &slot_39, QMetaData::Public },
	{ "showIJournalier(QListViewItem*)", &slot_40, QMetaData::Public },
	{ "delIJournalier()", &slot_41, QMetaData::Public },
	{ "languageChange()", &slot_42, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"AmonSoft", parentObject,
	slot_tbl, 43,
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
    case 1: showEmprunt((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: delEmprunt(); break;
    case 3: showArretMaladie(); break;
    case 4: showArretMaladie((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 5: delArretMaladie(); break;
    case 6: showRenteEducation(); break;
    case 7: showRenteEducation((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 8: delRenteEducation(); break;
    case 9: showGarantieDeces(); break;
    case 10: showGarantieDeces((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 11: delGarantieDeces(); break;
    case 12: showEmploi(); break;
    case 13: showEmploi((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 14: delEmploi(); break;
    case 15: showEnfant(); break;
    case 16: showEnfant((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 17: delEnfant(); break;
    case 18: showEpargne(); break;
    case 19: showEpargne((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 20: delEpargne(); break;
    case 21: showAssuranceVie(); break;
    case 22: showAssuranceVie((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 23: delAssuranceVie(); break;
    case 24: showCompte(); break;
    case 25: showCompte((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 26: delCompte(); break;
    case 27: showRevenus(); break;
    case 28: showRevenus((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 29: delRevenus(); break;
    case 30: showCharges(); break;
    case 31: showCharges((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 32: delCharges(); break;
    case 33: showRetraite(); break;
    case 34: showRetraite((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 35: delRetraite(); break;
    case 36: showKDeces(); break;
    case 37: showKDeces((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 38: delKdeces(); break;
    case 39: showIJournalier(); break;
    case 40: showIJournalier((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 41: delIJournalier(); break;
    case 42: languageChange(); break;
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
