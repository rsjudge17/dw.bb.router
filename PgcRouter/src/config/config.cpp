/*
 * config.cpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#include <QSettings>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttributes>
#include <QXmlStreamAttribute>
#include <QString>
#include <QVariant>

#include "config.hpp"

namespace dw {
namespace config {

const QString Config::QSETTINGS_CONFIG_GROUP = QLatin1String("configuration");
const QString Config::QSETTINGS_CONFIG_FILENAME = "model/config.xml";
const QString Config::CONFIG_ELEM_ROOT = QLatin1String("config");

const QString Config::CONFIG_ELEM_DEBUG = QLatin1String("debug");
const QString Config::CONFIG_ELEM_APPNAME = QLatin1String("appName");
const QString Config::CONFIG_ELEM_APPVER = QLatin1String("appVersion");
const QString Config::CONFIG_ELEM_DEVNAME = QLatin1String("deviceName");
const QString Config::CONFIG_ELEM_PLATVER = QLatin1String("platformVersion");
const QString Config::CONFIG_ELEM_TRACKER_SUPPORT = QLatin1String("trackerSupport");
const QString Config::CONFIG_ELEM_FM_URL = QLatin1String("fmUrl");
const QString Config::CONFIG_ELEM_JMS_URL = QLatin1String("jmsUrl");

const QString Config::CONFIG_ELEM_FORMS = QLatin1String("forms");
const QString Config::CONFIG_ELEM_LOCATIONS = QLatin1String("locations");
const QString Config::CONFIG_ELEM_GENERAL = QLatin1String("general");
const QString Config::CONFIG_ELEM_VER = QLatin1String("verification");
const QString Config::CONFIG_ELEM_TRACKER = QLatin1String("tracker");
const QString Config::CONFIG_ELEM_PEN = QLatin1String("pen");
const QString Config::CONFIG_ELEM_SUPPORT = QLatin1String("support");
const QString Config::CONFIG_ELEM_HELP = QLatin1String("help");
const QString Config::CONFIG_ELEM_LOGS = QLatin1String("logs");
const QString Config::CONFIG_ELEM_SETTINGS = QLatin1String("settings");

void Config::setValue(const QString& elemName, const QXmlStreamAttributes& attrs)
{
	foreach(const QXmlStreamAttribute &attr, attrs) {
		QString attrName = attr.name().toString();
		QVariant attrVal = attr.value().toString();

		setValue(elemName, attrName, attrVal);
	}

	//if (value(elemName).isValid())
	//setValue(elemName, defaultValue(elemName));
}

void Config::setValue(const QString &fld_name, const QString &prop_name, const QVariant &val)
{
	if (prop_name == "default")
	{
		setDefaultValue(fld_name ,val);
		setValue(fld_name ,val);
	}
	else if (prop_name == "test")
		setTestValue(fld_name ,val);
	//else
	//	setValue(fld_name ,val);
}

QXmlStreamReader& operator >> (QXmlStreamReader &reader, Config& config)
{
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
			 QXmlStreamAttributes attrs = reader.attributes();
			if ( !attrs.isEmpty() )
			{
				config.setValue(currentElemName, attrs);
				currentElemName.clear();
			}
			reader.readNext();
		} // while

		if ( reader.isEndElement())
		{
			if ( reader.name().toString() == config.groupName() )
				break;
			else
				continue;
		}


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

QXmlStreamWriter& operator << (QXmlStreamWriter &writer, const Config& config)
{
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

	writer.writeEndElement();
	return writer;
}

} /* namespace config */
} /* namespace dw */
