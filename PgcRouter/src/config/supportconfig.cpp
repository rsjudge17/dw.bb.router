/*
 * supportconfig.cpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#include "supportconfig.hpp"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QSettings>

namespace dw {
namespace config {

SupportConfig::SupportConfig(QSettings *settings)
	: Config(settings, Config::CONFIG_ELEM_SUPPORT)
{

}

bool SupportConfig::load(const QSettings& settings)
{
	return true;
}

/*QXmlStreamReader& operator >> (QXmlStreamReader &reader, SupportConfig& config)
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

QXmlStreamWriter& operator << (QXmlStreamWriter &writer, const SupportConfig& config)
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
}*/

} /* namespace config */
} /* namespace dw */
