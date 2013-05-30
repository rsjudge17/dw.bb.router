/*
 * trackersettings.cpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#include "trackersettings.hpp"
#include <QSettings>

namespace dw {
namespace config {

TrackerSettings::TrackerSettings(QSettings *settings)
	: Config(settings, Config::CONFIG_ELEM_TRACKER)
{
	// TODO Auto-generated constructor stub

}

bool TrackerSettings::load(const QSettings& settings)
{
	return true;
}

TrackerSettings::~TrackerSettings() {
	// TODO Auto-generated destructor stub
}

} /* namespace config */
} /* namespace dw */
