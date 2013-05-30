/*
 * config.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <QtCore>

class QSettings;
class QXmlStreamAttributes;
class QXmlStreamAttribute;

namespace dw {
namespace config {

class Config: public QObject {
	Q_OBJECT

	Q_PROPERTY(QString groupName READ groupName);

	friend QXmlStreamReader& operator>>(QXmlStreamReader& reader, Config& config);
	friend QXmlStreamWriter& operator<<(QXmlStreamWriter& writer, const Config& config);

public:
	Config(QSettings *settings, const QString &groupName) { m_settings = settings; m_groupName = groupName; }

	QString groupName() const { return m_groupName; }
	void setValue(const QString& elemName, const QXmlStreamAttributes& attrs);
	void setValue(const QString &fld_name, const QVariant &val) {
		m_settings->setValue(fld_name ,val);
		QObject::setProperty(fld_name.toLocal8Bit(), val);
	}
	QVariant value(const QString &fld_name) const
	{
		return m_settings->value(fld_name);
	}
	void setDefaultValue(const QString &fld_name, const QVariant &val) {
		m_settings->setValue(QString(fld_name+"default") ,val);
	}
	QVariant defaultValue(const QString &fld_name) const
	{
		return m_settings->value(QString(fld_name+"default"));
	}
	void setTestValue(const QString &fld_name, const QVariant &val) {
		m_settings->setValue(QString(fld_name+"test") ,val);
	}
	QVariant testValue(const QString &fld_name) const
	{
		return m_settings->value(QString(fld_name+"test"));
	}
	void setValue(const QString &fld_name, const QString &prop_name, const QVariant &val);

	//virtual bool readXmlFile(QIODevice& device, QSettings::SettingsMap& map);
	//virtual bool writeXmlFile(QIODevice& device, const QSettings::SettingsMap& map);
	virtual bool load(const QSettings& settings) = 0;

public:
	QString m_groupName;

	static const QString QSETTINGS_CONFIG_GROUP;
	static const QString QSETTINGS_CONFIG_FILENAME;
	static const QString CONFIG_ELEM_ROOT;
	static const QString CONFIG_ELEM_DEBUG;
	static const QString CONFIG_ELEM_APPNAME;
	static const QString CONFIG_ELEM_APPVER;
	static const QString CONFIG_ELEM_DEVNAME;
	static const QString CONFIG_ELEM_PLATVER;
	static const QString CONFIG_ELEM_TRACKER_SUPPORT;
	static const QString CONFIG_ELEM_FM_URL;
	static const QString CONFIG_ELEM_JMS_URL;
	static const QString CONFIG_ELEM_FORMS;
	static const QString CONFIG_ELEM_LOCATIONS;
	static const QString CONFIG_ELEM_GENERAL;
	static const QString CONFIG_ELEM_VER;
	static const QString CONFIG_ELEM_TRACKER;
	static const QString CONFIG_ELEM_PEN;
	static const QString CONFIG_ELEM_SUPPORT;
	static const QString CONFIG_ELEM_HELP;
	static const QString CONFIG_ELEM_LOGS;
	static const QString CONFIG_ELEM_SETTINGS;

protected:
	QSettings	*m_settings;
};

} /* namespace config */
} /* namespace dw */
#endif /* CONFIG_HPP_ */
