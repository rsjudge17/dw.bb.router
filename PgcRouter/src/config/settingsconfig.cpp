/*
 * settingsconfig.cpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */


#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QSettings>

#include "settingsconfig.hpp"
#include "routerconfig.hpp"
#include "generalsettings.hpp"
#include "verificationsettings.hpp"
#include "trackersettings.hpp"

namespace dw {
namespace config {

SettingsConfig::SettingsConfig(QSettings *settings)
	: Config(settings, Config::CONFIG_ELEM_SETTINGS)
	, m_general(new GeneralSettings(settings))
	, m_verification(new VerificationSettings(settings))
	, m_tracker(new TrackerSettings(settings))
{

}

bool SettingsConfig::load(const QSettings& settings)
{
	return true;
}

QXmlStreamReader& operator >> (QXmlStreamReader &reader, SettingsConfig& config)
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
			if (currentElemName == Config::CONFIG_ELEM_GENERAL )
			{
				reader >> (*config.m_general);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_VER )
			{
				reader >> (*config.m_verification);
				currentElemName.clear();

				reader.readNext();
				continue;
			}
			else if (currentElemName == Config::CONFIG_ELEM_TRACKER )
			{
				reader >> (*config.m_tracker);
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

QXmlStreamWriter& operator << (QXmlStreamWriter &writer, const SettingsConfig& config)
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
