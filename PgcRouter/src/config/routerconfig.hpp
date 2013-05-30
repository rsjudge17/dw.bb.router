/*
 * routerconfig.hpp
 *
 *  Created on: May 22, 2013
 *      Author: ruel
 */

#ifndef ROUTERCONFIG_HPP_
#define ROUTERCONFIG_HPP_

#include <QObject>
#include <QSettings>
#include <QString>
#include <QVariant>
#include <QMap>
#include "config.hpp"

class QXmlStreamReader;
class QXmlStreamWriter;
class QXmlStreamAttributes;
class QXmlStreamAttribute;

namespace dw {
namespace config {

//class Config;
class FormConfig;
class LocationsConfig;
class SettingsConfig;
class SupportConfig;
class HelpConfig;
class LogsConfig;
class PenConfig;

class RouterConfig: public Config {
	Q_OBJECT

	Q_PROPERTY(bool debug READ isDebug WRITE setDebug NOTIFY debugValueChanged);
	Q_PROPERTY(QString appName READ appName WRITE setAppName);
	Q_PROPERTY(QString appVersion READ appVersion WRITE setAppVersion);
	Q_PROPERTY(QString deviceName READ getDeviceName WRITE setDeviceName);
	Q_PROPERTY(QString platformVersion READ getPlatformVersion WRITE setPlatformVersion);
	Q_PROPERTY(QString fmUrl READ getFmUrl WRITE setFmUrl NOTIFY fmUrlValueChanged);
	Q_PROPERTY(QString jmsUrl READ getJmsUrl WRITE setJmsUrl NOTIFY jmsUrlValueChanged);
	Q_PROPERTY(bool trackerSupport READ isTrackerSupported WRITE setTrackerSupport NOTIFY trackerSupportValueChanged);

	friend QXmlStreamReader& operator>>(QXmlStreamReader& reader, RouterConfig& config);
	friend QXmlStreamWriter& operator<<(QXmlStreamWriter& writer, const RouterConfig& config);

public:
	bool isDebug() { return m_debug; }
	void setDebug(bool debug) { m_debug = debug; emit debugValueChanged(m_debug); }

	QString appName() { return m_appName; }
	void setAppName(QString appName) { m_appName = appName; }
	QString appVersion() { return m_appVersion; }
	void setAppVersion(QString appVersion) { m_appVersion = appVersion; }
	QString getDeviceName() { return m_deviceName; }
	void setDeviceName(QString deviceName) { m_deviceName = deviceName; }
	QString getPlatformVersion() { return m_platformVersion; }
	void setPlatformVersion(QString platformVersion) { m_platformVersion = platformVersion; }
	QString getFmUrl() { return m_fmUrl; }
	void setFmUrl(QString fmUrl) { m_fmUrl = fmUrl; emit fmUrlValueChanged(m_fmUrl); }
	QString getJmsUrl() { return m_jmsUrl; }
	void setJmsUrl(QString jmsUrl) { m_jmsUrl = jmsUrl; emit jmsUrlValueChanged(m_jmsUrl); }
	bool isTrackerSupported() { return m_trackerSupport; }
	void setTrackerSupport(bool value) { m_trackerSupport = value; emit trackerSupportValueChanged(m_trackerSupport); }

	//virtual bool readXmlFile(QIODevice& device, QSettings::SettingsMap& map);
	//virtual bool writeXmlFile(QIODevice& device, const QSettings::SettingsMap& map);
	virtual bool load(const QSettings& settings);

public:
	RouterConfig(QSettings *settings);
	virtual ~RouterConfig();
	//void loadFormXml(const QString& filename);

//public:
//	Q_INVOKABLE void load();

//private:
	//void loadForms(QXmlStreamReader& reader);
	//void loadConfig(QXmlStreamReader& reader, Config& config);
	//void loadSettings(QXmlStreamReader& reader, Config& config);

Q_SIGNALS:
	void debugValueChanged(bool newDebug);
	void trackerSupportValueChanged(bool newValue);
	void fmUrlValueChanged(const QString& newValue);
	void jmsUrlValueChanged(const QString& newValue);
	void loadCompleted();

private:
	QString 		m_elemName;
	//QStandardItem*	m_currentItem;

	bool 			m_debug;
	QString			m_appName;
	QString			m_appVersion;
	QString			m_deviceName;
	QString			m_platformVersion;
	QString			m_fmUrl;
	QString			m_jmsUrl;
	bool			m_trackerSupport;

public:
	FormConfig* 	m_formConfig;
	LocationsConfig* m_locationsConfig;
	SettingsConfig* m_settingsConfig;
	SupportConfig*	m_supportConfig;
	HelpConfig*		m_helpConfig;
	LogsConfig*		m_logConfig;
	PenConfig*		m_penConfig;
};

} /* namespace config */
} /* namespace dw */
#endif /* ROUTERCONFIG_HPP_ */
