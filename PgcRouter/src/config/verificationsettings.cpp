/*
 * verificationsettings.cpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#include "verificationsettings.hpp"
#include <QSettings>

namespace dw {
namespace config {

VerificationSettings::VerificationSettings(QSettings *settings)
	: Config(settings, Config::CONFIG_ELEM_VER)
{
	// TODO Auto-generated constructor stub

}

VerificationSettings::~VerificationSettings() {
	// TODO Auto-generated destructor stub
}

bool VerificationSettings::load(const QSettings& settings)
{
	return true;
}

} /* namespace config */
} /* namespace dw */
