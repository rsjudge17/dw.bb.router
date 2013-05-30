/*
 * routerconfig.cpp
 *
 *  Created on: May 22, 2013
 *      Author: ruel
 */

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttributes>
#include <QXmlStreamAttribute>
#include <QSettings>
#include <QStringList>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <string>
#include <vector>

#include "routerconfig.hpp"
#include "formconfig.hpp"
#include "settingsconfig.hpp"
#include "logsconfig.hpp"
#include "helpconfig.hpp"
#include "penconfig.hpp"
#include "supportconfig.hpp"

namespace dw {
namespace config {

//const QString Config::m_groupName = QLatin1String("config");

RouterConfig::RouterConfig(QSettings *settings)
	: Config(settings, Config::CONFIG_ELEM_ROOT) {
	m_formConfig = new FormConfig(settings);
	m_locationsConfig = new LocationsConfig(settings);
	m_settingsConfig = new SettingsConfig(settings);
	m_supportConfig = new SupportConfig(settings);
	m_helpConfig = new HelpConfig(settings);
	m_logConfig = new LogsConfig(settings);
	m_penConfig = new PenConfig(settings);
}

RouterConfig::~RouterConfig() {
	delete m_formConfig;
	delete m_settingsConfig;
	delete m_supportConfig;
	delete m_helpConfig;
	delete m_logConfig;
	delete m_penConfig;
}

QXmlStreamReader& operator >> (QXmlStreamReader &reader, RouterConfig& config) {

	//QXmlStreamReader reader( &device );

	QString currentElemName("");
	while( !reader.atEnd() ) {
		reader.readNext();
		while( reader.isStartElement() )
		{
			QString name = reader.name().toString();
			if (name == config.groupName())
			{
				reader.readNext();

				continue;
			}

			if (!currentElemName.isEmpty()) {
				currentElemName += "/";
			}

			currentElemName += reader.name().toString();
			if (currentElemName == Config::CONFIG_ELEM_FORMS )
			{
				reader >> *(config.m_formConfig);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_LOCATIONS )
			{
				reader >> *(config.m_locationsConfig);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_SETTINGS )
			{
				reader >> *(config.m_settingsConfig);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_PEN)
			{
				reader >> *(config.m_penConfig);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_SUPPORT)
			{
				reader >> *(config.m_supportConfig);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_HELP)
			{
				reader >> *(config.m_helpConfig);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_LOGS)
			{
				reader >> *(config.m_logConfig);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else
			{
				QXmlStreamAttributes attrs = reader.attributes();
				if ( !attrs.isEmpty() )
				{
					config.setValue(currentElemName, attrs);
					currentElemName.clear();
				}
			}

			reader.readNext();
		} // while

		if ( reader.isEndElement() )
			continue;


		if ( reader.isCharacters() && !reader.isWhitespace() )
		{
			QString key = currentElemName;
			QVariant value = reader.text().toString();

			config.setValue(key, value);
			currentElemName.clear();
		}
	} // while

	return reader;
}

QXmlStreamWriter& operator << (QXmlStreamWriter &writer, const RouterConfig& config)
{
	writer.setAutoFormatting(true);

	writer.writeStartDocument();
	writer.writeStartElement( config.groupName() );

	const QMetaObject* meta = config.metaObject();
	for (int i=0; i < meta->propertyCount(); ++i)
	{
		const QMetaProperty qmp = meta->property(i);
		writer.writeStartElement( qmp.name() );

		QString propName(qmp.name());
		QString attrName("test");
		QString attrValue( config.testValue( propName ).toString() );
		writer.writeAttribute( attrName,  attrValue);

		attrName = "default";
		attrValue = config.defaultValue( propName ).toString();
		writer.writeAttribute( attrName, attrValue );

		QVariant value = config.property( qmp.name() );
		writer.writeCharacters( value.toString() );

		writer.writeEndElement();
	}

	writer << *(config.m_formConfig);
	writer << *(config.m_locationsConfig);
	writer << *(config.m_settingsConfig);
	writer << *(config.m_penConfig);
	writer << *(config.m_supportConfig);
	writer << *(config.m_helpConfig);
	writer << *(config.m_logConfig);

	writer.writeEndElement();
	writer.writeEndDocument();

	return writer;
}

bool RouterConfig::load(const QSettings& settings)
{
	setDebug(settings.value(Config::CONFIG_ELEM_DEBUG).toBool());
	setAppName(settings.value(Config::CONFIG_ELEM_APPNAME).toString());
	setAppVersion(settings.value(Config::CONFIG_ELEM_APPVER).toString());
	setDeviceName(settings.value(Config::CONFIG_ELEM_DEVNAME).toString());
	setPlatformVersion(settings.value(Config::CONFIG_ELEM_PLATVER).toString());
	setFmUrl(settings.value(Config::CONFIG_ELEM_FM_URL).toString());
	setJmsUrl(settings.value(Config::CONFIG_ELEM_JMS_URL).toString());
	setTrackerSupport(settings.value(Config::CONFIG_ELEM_TRACKER_SUPPORT).toBool());

	return true;
}

} /* namespace config */
} /* namespace dw */
