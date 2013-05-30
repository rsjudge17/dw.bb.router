/*
 * formconfig.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef FORMCONFIG_HPP_
#define FORMCONFIG_HPP_

#include <QObject>
#include "config.hpp"

class QXmlStreamReader;
class QXmlStreamWriter;
class QXmlStreamAttributes;
class QXmlStreamAttribute;

namespace dw {
namespace config {

class FormConfig: public Config {
	Q_OBJECT

	Q_PROPERTY(QString dir READ dir WRITE setDir);
	Q_PROPERTY(QString filename READ filename WRITE setFilename);
	Q_PROPERTY(QString inboxFile READ inboxFile WRITE setInboxFile);
	Q_PROPERTY(QString inboxDir READ inboxDir WRITE setInboxDir);
	Q_PROPERTY(QString outboxFile READ outboxFile WRITE setOutboxFile);
	Q_PROPERTY(QString outboxDir READ outboxDir WRITE setOutboxDir);
	Q_PROPERTY(QString sentItemsFile READ sentItemsFile WRITE setSentItemsFile);
	Q_PROPERTY(QString sentItemsDir READ sentItemsDir WRITE setSentItemsDir);
	Q_PROPERTY(QString bluetoothDir READ bluetoothDir WRITE setBluetoothDir);

	//friend QXmlStreamReader& operator>>(QXmlStreamReader& reader, FormConfig& config);
	//friend QXmlStreamWriter& operator<<(QXmlStreamWriter& writer, const FormConfig& config);

public:
	FormConfig(QSettings *settings);
	FormConfig(QSettings *settings, const QString &groupName)
		: Config(settings, groupName) {} ;

	virtual bool load(const QSettings& settings);
public:
	QString dir() { return m_dir; }
	void setDir(QString dir) { m_dir = dir; }
	QString filename() { return m_filename; }
	void setFilename(QString filename) { m_filename = filename; }

	QString inboxFile() { return m_inboxFile; }
	void setInboxFile(QString inboxFile) { m_inboxFile = inboxFile; }

	QString inboxDir() { return m_inboxDir; }
	void setInboxDir(QString inboxDir) { m_inboxDir = inboxDir; }

	QString outboxFile() { return m_outboxFile; }
	void setOutboxFile(QString outboxFile) { m_outboxFile = outboxFile; }

	QString outboxDir() { return m_outboxDir; }
	void setOutboxDir(QString outboxDir) { m_outboxDir = outboxDir; }

	QString sentItemsFile() { return m_sentItemsFile; }
	void setSentItemsFile(QString sentItemsFile) { m_sentItemsFile = sentItemsFile; }

	QString sentItemsDir() { return m_sentItemsDir; }
	void setSentItemsDir(QString sentItemsDir) { m_sentItemsDir = sentItemsDir; }

	QString bluetoothDir() { return m_bluetoothDir; }
	void setBluetoothDir(QString bluetoothDir) { m_bluetoothDir = bluetoothDir; }

	QString m_dir;
	QString m_filename;
	QString m_inboxDir;
	QString m_inboxFile;
	QString m_outboxDir;
	QString m_outboxFile;
	QString m_sentItemsDir;
	QString m_sentItemsFile;
	QString m_bluetoothDir;

	QMap<QString, QString> m_pfdMap;
	QMap<QString, QString> m_mfdMap;

};

class LocationsConfig: public FormConfig {
	Q_OBJECT

public:
	LocationsConfig(QSettings *settings)
		: FormConfig(settings, Config::CONFIG_ELEM_LOCATIONS) {}
};

} /* namespace config */
} /* namespace dw */
#endif /* FORMCONFIG_HPP_ */
