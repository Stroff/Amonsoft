/****************************************************************************
** dlgPreferences meta object code from reading C++ file 'preferences.h'
**
** Created: jeu. 9. nov. 13:51:42 2006
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../Forms/preferences.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *dlgPreferences::className() const
{
    return "dlgPreferences";
}

QMetaObject *dlgPreferences::metaObj = 0;
static QMetaObjectCleanUp cleanUp_dlgPreferences( "dlgPreferences", &dlgPreferences::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString dlgPreferences::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgPreferences", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString dlgPreferences::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgPreferences", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* dlgPreferences::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "item", &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"listBox_selectionChanged", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"listViewCompagnies_selectionChanged", 1, param_slot_1 };
    static const QUMethod slot_2 = {"pushButtonCompagnieValider_clicked", 0, 0 };
    static const QUMethod slot_3 = {"pushButtonCompagnieSupprimer_clicked", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_4 = {"listViewEpargnes_selectionChanged", 1, param_slot_4 };
    static const QUMethod slot_5 = {"pushButtonEpargneValider_clicked", 0, 0 };
    static const QUMethod slot_6 = {"pushButtonEpargneSupprimer_clicked", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_7 = {"listViewComptes_selectionChanged", 1, param_slot_7 };
    static const QUMethod slot_8 = {"pushButtonComptesValider_clicked", 0, 0 };
    static const QUMethod slot_9 = {"pushButtonComptesSupprimer_clicked", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_10 = {"listViewBureau_selectionChanged", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_11 = {"listViewConseillers_selectionChanged", 1, param_slot_11 };
    static const QUMethod slot_12 = {"pushButtonValiderBureau_clicked", 0, 0 };
    static const QUMethod slot_13 = {"pushButtonSupprimerEtude_clicked", 0, 0 };
    static const QUMethod slot_14 = {"pushButtonValiderConseillers_clicked", 0, 0 };
    static const QUMethod slot_15 = {"pushButtonSupprimerConseillers_clicked", 0, 0 };
    static const QUMethod slot_16 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "listBox_selectionChanged(QListBoxItem*)", &slot_0, QMetaData::Public },
	{ "listViewCompagnies_selectionChanged(QListViewItem*)", &slot_1, QMetaData::Public },
	{ "pushButtonCompagnieValider_clicked()", &slot_2, QMetaData::Public },
	{ "pushButtonCompagnieSupprimer_clicked()", &slot_3, QMetaData::Public },
	{ "listViewEpargnes_selectionChanged(QListViewItem*)", &slot_4, QMetaData::Public },
	{ "pushButtonEpargneValider_clicked()", &slot_5, QMetaData::Public },
	{ "pushButtonEpargneSupprimer_clicked()", &slot_6, QMetaData::Public },
	{ "listViewComptes_selectionChanged(QListViewItem*)", &slot_7, QMetaData::Public },
	{ "pushButtonComptesValider_clicked()", &slot_8, QMetaData::Public },
	{ "pushButtonComptesSupprimer_clicked()", &slot_9, QMetaData::Public },
	{ "listViewBureau_selectionChanged(QListViewItem*)", &slot_10, QMetaData::Public },
	{ "listViewConseillers_selectionChanged(QListViewItem*)", &slot_11, QMetaData::Public },
	{ "pushButtonValiderBureau_clicked()", &slot_12, QMetaData::Public },
	{ "pushButtonSupprimerEtude_clicked()", &slot_13, QMetaData::Public },
	{ "pushButtonValiderConseillers_clicked()", &slot_14, QMetaData::Public },
	{ "pushButtonSupprimerConseillers_clicked()", &slot_15, QMetaData::Public },
	{ "languageChange()", &slot_16, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"dlgPreferences", parentObject,
	slot_tbl, 17,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_dlgPreferences.setMetaObject( metaObj );
    return metaObj;
}

void* dlgPreferences::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "dlgPreferences" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool dlgPreferences::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: listBox_selectionChanged((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: listViewCompagnies_selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: pushButtonCompagnieValider_clicked(); break;
    case 3: pushButtonCompagnieSupprimer_clicked(); break;
    case 4: listViewEpargnes_selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 5: pushButtonEpargneValider_clicked(); break;
    case 6: pushButtonEpargneSupprimer_clicked(); break;
    case 7: listViewComptes_selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 8: pushButtonComptesValider_clicked(); break;
    case 9: pushButtonComptesSupprimer_clicked(); break;
    case 10: listViewBureau_selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 11: listViewConseillers_selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 12: pushButtonValiderBureau_clicked(); break;
    case 13: pushButtonSupprimerEtude_clicked(); break;
    case 14: pushButtonValiderConseillers_clicked(); break;
    case 15: pushButtonSupprimerConseillers_clicked(); break;
    case 16: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool dlgPreferences::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool dlgPreferences::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool dlgPreferences::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
