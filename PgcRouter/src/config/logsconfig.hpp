/*
 * logsconfig.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef LOGSCONFIG_HPP_
#define LOGSCONFIG_HPP_

#include "config.hpp"

class QXmlStreamReader;
class QXmlStreamWriter;

namespace dw {
namespace config {

class Config;

class LogsConfig: public Config {
	Q_OBJECT

	Q_PROPERTY(QString pgcRouter READ pgcRouter WRITE setPgcRouter);
	Q_PROPERTY(QString pgcVerifier READ pgcVerifier WRITE setPgcVerifier);
	Q_PROPERTY(QString pgcSender READ pgcSender WRITE setPgcSender);

public:
	LogsConfig(QSettings *settings);

	bool load(const QSettings& settings);

public:
	QString pgcRouter() { return m_pgcRouter; }
	void setPgcRouter(QString pgcRouter) { m_pgcRouter = pgcRouter; }
	QString pgcVerifier() { return m_pgcVerifier; }
	void setPgcVerifier(QString pgcVerifier) { m_pgcVerifier = pgcVerifier; }
	QString pgcSender() { return m_pgcSender; }
	void setPgcSender(QString pgcSender) { m_pgcSender = pgcSender; }

private:
	QString m_pgcRouter;
	QString m_pgcVerifier;
	QString m_pgcSender;
};

} /* namespace config */
} /* namespace dw */
#endif /* LOGSCONFIG_HPP_ */
