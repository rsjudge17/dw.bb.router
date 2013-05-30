/*
 * helpconfig.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef HELPCONFIG_HPP_
#define HELPCONFIG_HPP_

#include "config.hpp"

class QXmlStreamReader;
class QXmlStreamWriter;

namespace dw {
namespace config {

class HelpConfig: public Config {
	Q_OBJECT

	Q_PROPERTY(QString formVerfication READ formVerfication WRITE setFormVerfication);
public:
	HelpConfig(QSettings *settings);

	bool load(const QSettings& settings);

public:
	QString formVerfication() { return m_formVerfication; }
	void setFormVerfication(QString formVerfication) { m_formVerfication = formVerfication; }

private:
	QString m_formVerfication;
};

} /* namespace config */
} /* namespace dw */
#endif /* HELPCONFIG_HPP_ */
