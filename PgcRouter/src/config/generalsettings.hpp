/*
 * generalsettings.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef GENERALSETTINGS_HPP_
#define GENERALSETTINGS_HPP_

#include "config.hpp"

namespace dw {
namespace config {

class GeneralSettings : public Config {
	Q_OBJECT

	Q_PROPERTY(bool billableEvents READ isBillableEvents WRITE setBillableEvents);
	Q_PROPERTY(QString mobileNumber READ mobileNumber WRITE setMobileNumber);
	Q_PROPERTY(int maxStorageDays READ maxStorageDays WRITE setMaxStorageDays);
public:
	GeneralSettings(QSettings *settings);
	virtual ~GeneralSettings();

	virtual bool load(const QSettings& settings);

public:
	bool isBillableEvents() { return m_billableEvents; }
	void setBillableEvents(bool billableEvents) { m_billableEvents = billableEvents; }
	QString mobileNumber() { return m_mobileNumber; }
	void setMobileNumber(QString mobileNumber) { m_mobileNumber = mobileNumber; }
	int maxStorageDays() { return m_maxStorageDays; }
	void setMaxStorageDays(int maxStorageDays) { m_maxStorageDays = maxStorageDays; }

private:
	QString m_mobileNumber;
	int m_maxStorageDays;
	bool m_billableEvents;

};

} /* namespace config */
} /* namespace dw */
#endif /* GENERALSETTINGS_HPP_ */
