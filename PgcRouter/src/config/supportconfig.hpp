/*
 * supportconfig.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef SUPPORTCONFIG_HPP_
#define SUPPORTCONFIG_HPP_

#include "config.hpp"

class QXmlStreamReader;
class QXmlStreamWriter;

namespace dw {
namespace config {

class SupportConfig: public Config {
	Q_OBJECT

	Q_PROPERTY(QString supportNumber READ supportNumber WRITE setSupportNumber);
	Q_PROPERTY(QString supportEmail READ supportEmail WRITE setSupportEmail);
	Q_PROPERTY(QString webSite READ webSite WRITE setWebSite);

	//friend QXmlStreamReader& operator>>(QXmlStreamReader& reader, SupportConfig& config);
	//friend QXmlStreamWriter& operator<<(QXmlStreamWriter& writer, const SupportConfig& config);
public:
	SupportConfig(QSettings *settings);

	virtual bool load(const QSettings& settings);
public:
	QString supportNumber() { return m_supportNumber; }
	void setSupportNumber(QString supportNumber) { m_supportNumber = supportNumber; }

	QString supportEmail() { return m_supportEmail; }
	void setSupportEmail(QString supportEmail) { m_supportEmail = supportEmail; }

	QString webSite() { return m_webSite; }
	void setWebSite(QString webSite) { m_webSite = webSite; }

private:
	QString m_supportNumber;
	QString m_supportEmail;
	QString m_webSite;
};

} /* namespace config */
} /* namespace dw */
#endif /* SUPPORTCONFIG_HPP_ */
