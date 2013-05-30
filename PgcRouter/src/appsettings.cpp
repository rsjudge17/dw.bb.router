/*
 * appsettings.cpp
 *
 *  Created on: May 27, 2013
 *      Author: ruel
 */


#include <bb/cascades/Application>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QString>
#include <QSettings>

#include "appsettings.h"

using namespace dw::config;

bool readXmlFile(QIODevice &device, QSettings::SettingsMap &map);
bool writeXmlFile(QIODevice &device, const QSettings::SettingsMap &map);

const QSettings::Format XmlFormat =
			QSettings::registerFormat("xml", readXmlFile, writeXmlFile);

AppSettings::AppSettings(bb::cascades::Application *app)
	: QSettings(XmlFormat, QSettings::UserScope,
			app->organizationName(),
			app->applicationName())
{
	m_routerConfig = new RouterConfig(this);
}

AppSettings::~AppSettings() {
	// TODO Auto-generated destructor stub
}

bool AppSettings::hasConfiguration() const
{
    int keysCount = 0;

    QString gname(m_routerConfig->groupName());
    //beginGroup(*gname);
    keysCount = allKeys().count();
    //endGroup();

    return keysCount > 0;
}

FormConfig* AppSettings::forms()
{
	return m_routerConfig->m_formConfig;
}

void AppSettings::loadFormXml(const QString& filename) {

	QFile config(filename);
	if (!config.open(QIODevice::ReadOnly)) {
		//qDebug << "Can't open config file: " << filename;

		return;
	}

	QXmlStreamReader reader( &config );
	reader >> (*m_routerConfig);

	if (reader.hasError())
		emit loadError(reader.errorString());
	else
		emit loadCompleted();

	config.close();
}

void AppSettings::saveToXml(const QString& filename) {
	QFile config(filename);
	if (!config.open(QIODevice::WriteOnly)) {
		//qDebug << "Can't open config file: " << filename;

		return;
	}

	QXmlStreamWriter writer( &config );
	writer.setAutoFormatting(true);
	writer << (*m_routerConfig);

	if (writer.hasError())
		emit saveError(filename);
	else
		emit saveCompleted();

	config.close();
}

bool readXmlFile(QIODevice& device, QSettings::SettingsMap& map)
{
	QXmlStreamReader reader( &device );

	QString currentElemName("");
	while( !reader.atEnd() ) {
		reader.readNext();
		while( reader.isStartElement() )
		{
			QString name = reader.name().toString();
			if (name == Config::QSETTINGS_CONFIG_GROUP)
			{
				reader.readNext();

				continue;
			}

			if (!currentElemName.isEmpty()) {
				currentElemName += "/";
			}

			currentElemName += reader.name().toString();
			reader.readNext();
		} // while

		if ( reader.isEndElement() )
			continue;

		if ( reader.isCharacters() && !reader.isWhitespace() )
		{
			QString key = currentElemName;
			QString value = reader.text().toString();

			map[ key ] = value;
			currentElemName.clear();
		}
	} // while

	if ( reader.hasError() )
		return false;

	return true;
}

bool writeXmlFile(QIODevice& device, const QSettings::SettingsMap& map)
{
	QXmlStreamWriter writer( &device );
	writer.setAutoFormatting(true);

	writer.writeStartDocument();
	writer.writeStartElement( Config::QSETTINGS_CONFIG_GROUP );
	for( QSettings::SettingsMap::const_iterator iter = map.begin(); iter != map.end(); ++iter )
	{
		//QString keys(iter.key());
		QStringList groups = iter.key().split("/", QString::SkipEmptyParts);

		for( QStringList::const_iterator giter = groups.begin(); giter != groups.end(); ++giter )
		{
			writer.writeStartElement( *giter );
		}
		writer.writeCharacters(iter.value().toString());
		for( QStringList::const_iterator giter = groups.begin(); giter != groups.end(); ++giter )
		{
			writer.writeEndElement();
		}
	}

	writer.writeEndElement();
	writer.writeEndDocument();

	if (writer.hasError())
		return false;

	return true;
}
