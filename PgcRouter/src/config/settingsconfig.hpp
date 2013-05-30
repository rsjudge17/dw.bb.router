/*
 * settingsconfig.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef SETTINGSCONFIG_HPP_
#define SETTINGSCONFIG_HPP_

#include "config.hpp"

class QSettings;
class QXmlStreamReader;
class QXmlStreamWriter;

namespace dw {
namespace config {

class GeneralSettings;
class VerificationSettings;
class TrackerSettings;

class SettingsConfig: public Config {
	Q_OBJECT

	friend QXmlStreamReader& operator>>(QXmlStreamReader& reader, SettingsConfig& config);
	friend QXmlStreamWriter& operator<<(QXmlStreamWriter& writer, const SettingsConfig& config);
public:
	SettingsConfig(QSettings *settings);

	virtual bool load(const QSettings& settings);

protected:
	GeneralSettings 		*m_general;
	VerificationSettings 	*m_verification;
	TrackerSettings 		*m_tracker;
};

} /* namespace config */
} /* namespace dw */
#endif /* SETTINGSCONFIG_HPP_ */
