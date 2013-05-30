/*
 * penconfig.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef PENCONFIG_HPP_
#define PENCONFIG_HPP_

#include <QObject>
#include <QString>
#include <QSettings>
#include "config.hpp"

namespace dw {
namespace config {

class PenConfig: public Config {
	Q_OBJECT

	Q_PROPERTY(QString id READ id WRITE setId);

public:
	PenConfig(QSettings *settings);

	QString id() { return m_id; }
	void setId(QString id) { m_id = id; }

	bool load(const QSettings& settings);

private:
	QString m_id;
};

} /* namespace config */
} /* namespace dw */
#endif /* PENCONFIG_HPP_ */
