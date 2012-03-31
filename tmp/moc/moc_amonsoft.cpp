/****************************************************************************
** dlgAmonSoft meta object code from reading C++ file 'amonsoft.h'
**
** Created: lun. 20. nov. 16:46:28 2006
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../Forms/amonsoft.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *dlgAmonSoft::className() const
{
    return "dlgAmonSoft";
}

QMetaObject *dlgAmonSoft::metaObj = 0;
static QMetaObjectCleanUp cleanUp_dlgAmonSoft( "dlgAmonSoft", &dlgAmonSoft::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString dlgAmonSoft::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgAmonSoft", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString dlgAmonSoft::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "dlgAmonSoft", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* dlgAmonSoft::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"ajouter", 0, 0 };
    static const QUMethod slot_1 = {"lister", 0, 0 };
    static const QUMethod slot_2 = {"pushButtonAjouterEntreprise_clicked", 0, 0 };
    static const QUMethod slot_3 = {"pushButtonEntrepriseLister_clicked", 0, 0 };
    static const QUMethod slot_4 = {"ouvrir", 0, 0 };
    static const QUMethod slot_5 = {"filenew_itemSauvegarder_activated", 0, 0 };
    static const QUMethod slot_6 = {"sauvegarder", 0, 0 };
    static const QUMethod slot_7 = {"about", 0, 0 };
    static const QUMethod slot_8 = {"preferences", 0, 0 };
    static const QUMethod slot_9 = {"widgetStackAjouter_EtatCivil", 0, 0 };
    static const QUMethod slot_10 = {"widgetStackAjouter_Famille", 0, 0 };
    static const QUMethod slot_11 = {"widgetStackAjouter_Carriere", 0, 0 };
    static const QUMethod slot_12 = {"widgetStackAjouter_Prevoyance", 0, 0 };
    static const QUMethod slot_13 = {"widgetStackAjouter_Epargne", 0, 0 };
    static const QUMethod slot_14 = {"widgetStackAjouter_Patrimoine", 0, 0 };
    static const QUMethod slot_15 = {"pushButtonBesoins_clicked", 0, 0 };
    static const QUMethod slot_16 = {"pushButtonDossierEntreprise_clicked", 0, 0 };
    static const QUMethod slot_17 = {"pushButtonParticipants_clicked", 0, 0 };
    static const QUMethod slot_18 = {"pushButtonTNS_clicked", 0, 0 };
    static const QUMethod slot_19 = {"toolButtonSupprimer_clicked", 0, 0 };
    static const QUMethod slot_20 = {"charger", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ "iVal", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"comboBoxInteressement_activated", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_22 = {"chargerPersonne", 1, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"comboBoxFamilleConjoint_textChanged", 1, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ "i", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"sliderEpargneSensibilite_valueChanged", 1, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_25 = {"listViewProspect_doubleClicked", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"comboBoxEtatCivilCabinetComptable_textChanged", 1, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"comboBoxEtatCivilEtude_textChanged", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"comboBoxEtatCivilCabinetAvocat_textChanged", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ "i", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"comboBoxBenefProspect_activated", 1, param_slot_29 };
    static const QUMethod slot_30 = {"pushButtonDirigeantPlus_clicked", 0, 0 };
    static const QUMethod slot_31 = {"pushButtontDirigeantMinus_clicked", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "i", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"comboBoxEtatCivilRaisonSociale_activated", 1, param_slot_32 };
    static const QUMethod slot_33 = {"pushButtonEnstesEmployeMinus_clicked", 0, 0 };
    static const QUMethod slot_34 = {"pushButtonEnstesEmployePlus_clicked", 0, 0 };
    static const QUParameter param_slot_35[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_35 = {"listView29_doubleClicked", 1, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_36 = {"listViewEntsesParticipants_doubleClicked", 1, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_37 = {"listViewDirigeants_doubleClicked", 1, param_slot_37 };
    static const QUMethod slot_38 = {"fichierImporterAction_activated", 0, 0 };
    static const QUParameter param_slot_39[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"lineEditListerFiltreNom_textChanged", 1, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_40 = {"lineEditListerFiltrePrenom_textChanged", 1, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ "uId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_41 = {"comboBoxSearchProspect_activated", 1, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_42 = {"lineEditListerFiltreSiret_textChanged", 1, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"lineEditListerFiltreRaisonSociale_textChanged", 1, param_slot_43 };
    static const QUMethod slot_44 = {"pushButtonEntsesFiltreEffacer_clicked", 0, 0 };
    static const QUMethod slot_45 = {"pushButtonPersonneFiltreEffacer_clicked", 0, 0 };
    static const QUParameter param_slot_46[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_46 = {"lineEditSearchValue1_textChanged", 1, param_slot_46 };
    static const QUParameter param_slot_47[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_47 = {"lineEditSearchValue2_textChanged", 1, param_slot_47 };
    static const QUParameter param_slot_48[] = {
	{ "i", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_48 = {"comboBoxSearchFunction_activated", 1, param_slot_48 };
    static const QUMethod slot_49 = {"comboBoxSearchOp1_highlighted", 0, 0 };
    static const QUMethod slot_50 = {"comboBoxSearchOp2_highlighted", 0, 0 };
    static const QUMethod slot_51 = {"fichierExporterAction_activated", 0, 0 };
    static const QUMethod slot_52 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "ajouter()", &slot_0, QMetaData::Public },
	{ "lister()", &slot_1, QMetaData::Public },
	{ "pushButtonAjouterEntreprise_clicked()", &slot_2, QMetaData::Public },
	{ "pushButtonEntrepriseLister_clicked()", &slot_3, QMetaData::Public },
	{ "ouvrir()", &slot_4, QMetaData::Public },
	{ "filenew_itemSauvegarder_activated()", &slot_5, QMetaData::Public },
	{ "sauvegarder()", &slot_6, QMetaData::Public },
	{ "about()", &slot_7, QMetaData::Public },
	{ "preferences()", &slot_8, QMetaData::Public },
	{ "widgetStackAjouter_EtatCivil()", &slot_9, QMetaData::Public },
	{ "widgetStackAjouter_Famille()", &slot_10, QMetaData::Public },
	{ "widgetStackAjouter_Carriere()", &slot_11, QMetaData::Public },
	{ "widgetStackAjouter_Prevoyance()", &slot_12, QMetaData::Public },
	{ "widgetStackAjouter_Epargne()", &slot_13, QMetaData::Public },
	{ "widgetStackAjouter_Patrimoine()", &slot_14, QMetaData::Public },
	{ "pushButtonBesoins_clicked()", &slot_15, QMetaData::Public },
	{ "pushButtonDossierEntreprise_clicked()", &slot_16, QMetaData::Public },
	{ "pushButtonParticipants_clicked()", &slot_17, QMetaData::Public },
	{ "pushButtonTNS_clicked()", &slot_18, QMetaData::Public },
	{ "toolButtonSupprimer_clicked()", &slot_19, QMetaData::Public },
	{ "charger()", &slot_20, QMetaData::Public },
	{ "comboBoxInteressement_activated(int)", &slot_21, QMetaData::Public },
	{ "chargerPersonne(QListViewItem*)", &slot_22, QMetaData::Public },
	{ "comboBoxFamilleConjoint_textChanged(const QString&)", &slot_23, QMetaData::Public },
	{ "sliderEpargneSensibilite_valueChanged(int)", &slot_24, QMetaData::Public },
	{ "listViewProspect_doubleClicked(QListViewItem*)", &slot_25, QMetaData::Public },
	{ "comboBoxEtatCivilCabinetComptable_textChanged(const QString&)", &slot_26, QMetaData::Public },
	{ "comboBoxEtatCivilEtude_textChanged(const QString&)", &slot_27, QMetaData::Public },
	{ "comboBoxEtatCivilCabinetAvocat_textChanged(const QString&)", &slot_28, QMetaData::Public },
	{ "comboBoxBenefProspect_activated(int)", &slot_29, QMetaData::Public },
	{ "pushButtonDirigeantPlus_clicked()", &slot_30, QMetaData::Public },
	{ "pushButtontDirigeantMinus_clicked()", &slot_31, QMetaData::Public },
	{ "comboBoxEtatCivilRaisonSociale_activated(int)", &slot_32, QMetaData::Public },
	{ "pushButtonEnstesEmployeMinus_clicked()", &slot_33, QMetaData::Public },
	{ "pushButtonEnstesEmployePlus_clicked()", &slot_34, QMetaData::Public },
	{ "listView29_doubleClicked(QListViewItem*)", &slot_35, QMetaData::Public },
	{ "listViewEntsesParticipants_doubleClicked(QListViewItem*)", &slot_36, QMetaData::Public },
	{ "listViewDirigeants_doubleClicked(QListViewItem*)", &slot_37, QMetaData::Public },
	{ "fichierImporterAction_activated()", &slot_38, QMetaData::Public },
	{ "lineEditListerFiltreNom_textChanged(const QString&)", &slot_39, QMetaData::Public },
	{ "lineEditListerFiltrePrenom_textChanged(const QString&)", &slot_40, QMetaData::Public },
	{ "comboBoxSearchProspect_activated(int)", &slot_41, QMetaData::Public },
	{ "lineEditListerFiltreSiret_textChanged(const QString&)", &slot_42, QMetaData::Public },
	{ "lineEditListerFiltreRaisonSociale_textChanged(const QString&)", &slot_43, QMetaData::Public },
	{ "pushButtonEntsesFiltreEffacer_clicked()", &slot_44, QMetaData::Public },
	{ "pushButtonPersonneFiltreEffacer_clicked()", &slot_45, QMetaData::Public },
	{ "lineEditSearchValue1_textChanged(const QString&)", &slot_46, QMetaData::Public },
	{ "lineEditSearchValue2_textChanged(const QString&)", &slot_47, QMetaData::Public },
	{ "comboBoxSearchFunction_activated(int)", &slot_48, QMetaData::Public },
	{ "comboBoxSearchOp1_highlighted()", &slot_49, QMetaData::Public },
	{ "comboBoxSearchOp2_highlighted()", &slot_50, QMetaData::Public },
	{ "fichierExporterAction_activated()", &slot_51, QMetaData::Public },
	{ "languageChange()", &slot_52, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"dlgAmonSoft", parentObject,
	slot_tbl, 53,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_dlgAmonSoft.setMetaObject( metaObj );
    return metaObj;
}

void* dlgAmonSoft::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "dlgAmonSoft" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool dlgAmonSoft::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: ajouter(); break;
    case 1: lister(); break;
    case 2: pushButtonAjouterEntreprise_clicked(); break;
    case 3: pushButtonEntrepriseLister_clicked(); break;
    case 4: ouvrir(); break;
    case 5: filenew_itemSauvegarder_activated(); break;
    case 6: sauvegarder(); break;
    case 7: about(); break;
    case 8: preferences(); break;
    case 9: widgetStackAjouter_EtatCivil(); break;
    case 10: widgetStackAjouter_Famille(); break;
    case 11: widgetStackAjouter_Carriere(); break;
    case 12: widgetStackAjouter_Prevoyance(); break;
    case 13: widgetStackAjouter_Epargne(); break;
    case 14: widgetStackAjouter_Patrimoine(); break;
    case 15: pushButtonBesoins_clicked(); break;
    case 16: pushButtonDossierEntreprise_clicked(); break;
    case 17: pushButtonParticipants_clicked(); break;
    case 18: pushButtonTNS_clicked(); break;
    case 19: toolButtonSupprimer_clicked(); break;
    case 20: charger(); break;
    case 21: comboBoxInteressement_activated((int)static_QUType_int.get(_o+1)); break;
    case 22: chargerPersonne((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 23: comboBoxFamilleConjoint_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 24: sliderEpargneSensibilite_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 25: listViewProspect_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 26: comboBoxEtatCivilCabinetComptable_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 27: comboBoxEtatCivilEtude_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 28: comboBoxEtatCivilCabinetAvocat_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 29: comboBoxBenefProspect_activated((int)static_QUType_int.get(_o+1)); break;
    case 30: pushButtonDirigeantPlus_clicked(); break;
    case 31: pushButtontDirigeantMinus_clicked(); break;
    case 32: comboBoxEtatCivilRaisonSociale_activated((int)static_QUType_int.get(_o+1)); break;
    case 33: pushButtonEnstesEmployeMinus_clicked(); break;
    case 34: pushButtonEnstesEmployePlus_clicked(); break;
    case 35: listView29_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 36: listViewEntsesParticipants_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 37: listViewDirigeants_doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 38: fichierImporterAction_activated(); break;
    case 39: lineEditListerFiltreNom_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 40: lineEditListerFiltrePrenom_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 41: comboBoxSearchProspect_activated((int)static_QUType_int.get(_o+1)); break;
    case 42: lineEditListerFiltreSiret_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 43: lineEditListerFiltreRaisonSociale_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 44: pushButtonEntsesFiltreEffacer_clicked(); break;
    case 45: pushButtonPersonneFiltreEffacer_clicked(); break;
    case 46: lineEditSearchValue1_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 47: lineEditSearchValue2_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 48: comboBoxSearchFunction_activated((int)static_QUType_int.get(_o+1)); break;
    case 49: comboBoxSearchOp1_highlighted(); break;
    case 50: comboBoxSearchOp2_highlighted(); break;
    case 51: fichierExporterAction_activated(); break;
    case 52: languageChange(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool dlgAmonSoft::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool dlgAmonSoft::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool dlgAmonSoft::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
