/*
 * generalsettings.cpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#include "generalsettings.hpp"
#include <QSettings>

namespace dw {
namespace config {

GeneralSettings::GeneralSettings(QSettings *settings)
	: Config(settings, Config::CONFIG_ELEM_GENERAL)
{
	// TODO Auto-generated constructor stub

}

GeneralSettings::~GeneralSettings() {
	// TODO Auto-generated destructor stub
}

bool GeneralSettings::load(const QSettings& settings)
{
	return true;
}

/*bool GeneralSettings::readXmlFile(QIODevice& device, QSettings::SettingsMap& map)
{
	return true;
}

bool GeneralSettings::writeXmlFile(QIODevice& device, const QSettings::SettingsMap& map)
{
	return true;
}*/

} /* namespace config */
} /* namespace dw */
