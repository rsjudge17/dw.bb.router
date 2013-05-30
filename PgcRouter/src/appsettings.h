/*
 * appsettings.h
 *
 *  Created on: May 27, 2013
 *      Author: ruel
 */

#ifndef APPSETTINGS_H_
#define APPSETTINGS_H_

#include <QObject>
#include <QString>
#include <QSettings>

#include "config.hpp"
#include "formconfig.hpp"
#include "routerconfig.hpp"

namespace bb { namespace cascades { class Application; }}

class AppSettings : public QSettings {
	Q_OBJECT

	Q_PROPERTY(dw::config::FormConfig* forms READ forms);
public:
	AppSettings(bb::cascades::Application *app);
	virtual ~AppSettings();

public:
	dw::config::FormConfig* forms();

	bool hasConfiguration() const;
	void loadFormXml(const QString& filename);
	void saveToXml(const QString& filename);
//	bool readXmlFile(QIODevice& device, QSettings::SettingsMap& map);
//	bool writeXmlFile(QIODevice& device, const QSettings::SettingsMap& map);
	Q_SIGNALS:
	void loadError(const QString& errorStr);
	void loadCompleted();
	void saveError(const QString& errorStr);
	void saveCompleted();


public:
	dw::config::RouterConfig *m_routerConfig;
};

#endif /* APPSETTINGS_H_ */
