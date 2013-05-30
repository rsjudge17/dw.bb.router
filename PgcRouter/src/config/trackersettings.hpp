/*
 * trackersettings.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef TRACKERSETTINGS_HPP_
#define TRACKERSETTINGS_HPP_

#include "config.hpp"

namespace dw {
namespace config {

class TrackerSettings : public Config {
	Q_OBJECT

	Q_PROPERTY(bool pollingStartSwitch READ isPollingStartSwitch WRITE setPollingStartSwitch);
	Q_PROPERTY(int pollingInterval READ pollingInterval WRITE setPollingInterval);
	Q_PROPERTY(int startTimeMonday READ startTimeMonday WRITE setStartTimeMonday);
	Q_PROPERTY(int endTimeMonday READ endTimeMonday WRITE setEndTimeMonday);
	Q_PROPERTY(int startTimeTuesday READ startTimeTuesday WRITE setStartTimeTuesday);
	Q_PROPERTY(int endTimeTuesday READ endTimeTuesday WRITE setEndTimeTuesday);
	Q_PROPERTY(int startTimeWednesday READ startTimeWednesday WRITE setStartTimeWednesday);
	Q_PROPERTY(int endTimeWednesday READ endTimeWednesday WRITE setEndTimeWednesday);
	Q_PROPERTY(int startTimeThursday READ startTimeThursday WRITE setStartTimeThursday);
	Q_PROPERTY(int endTimeThursday READ endTimeThursday WRITE setEndTimeThursday);
	Q_PROPERTY(int startTimeFriday READ startTimeFriday WRITE setStartTimeFriday);
	Q_PROPERTY(int endTimeFriday READ endTimeFriday WRITE setEndTimeFriday);
	Q_PROPERTY(int startTimeSaturday READ startTimeSaturday WRITE setStartTimeSaturday);
	Q_PROPERTY(int endTimeSaturday READ endTimeSaturday WRITE setEndTimeSaturday);
	Q_PROPERTY(int startTimeSunday READ startTimeSunday WRITE setStartTimeSunday);
	Q_PROPERTY(int endTimeSunday READ endTimeSunday WRITE setEndTimeSunday);

public:
	TrackerSettings(QSettings *settings);
	virtual ~TrackerSettings();

	virtual bool load(const QSettings& settings);

public:
	bool isPollingStartSwitch() { return m_pollingStartSwitch; }
	void setPollingStartSwitch(bool pollingStartSwitch) { m_pollingStartSwitch = pollingStartSwitch; }
	int pollingInterval() { return m_pollingInterval; }
	void setPollingInterval(int pollingInterval) { m_pollingInterval = pollingInterval; }
	int startTimeMonday() { return m_startTimeMonday; }
	void setStartTimeMonday(int startTimeMonday) { m_startTimeMonday = startTimeMonday; }
	int endTimeMonday() { return m_endTimeMonday; }
	void setEndTimeMonday(int endTimeMonday) { m_endTimeMonday = endTimeMonday; }

	int startTimeTuesday() { return m_startTimeTuesday; }
	void setStartTimeTuesday(int startTimeTuesday) { m_startTimeTuesday = startTimeTuesday; }
	int endTimeTuesday() { return m_endTimeTuesday; }
	void setEndTimeTuesday(int endTimeTuesday) { m_endTimeTuesday = endTimeTuesday; }

	int startTimeWednesday() { return m_startTimeWednesday; }
	void setStartTimeWednesday(int startTimeWednesday) { m_startTimeWednesday = startTimeWednesday; }
	int endTimeWednesday() { return m_endTimeWednesday; }
	void setEndTimeWednesday(int endTimeWednesday) { m_endTimeWednesday = endTimeWednesday; }

	int startTimeThursday() { return m_startTimeThursday; }
	void setStartTimeThursday(int startTimeThursday) { m_startTimeThursday = startTimeThursday; }
	int endTimeThursday() { return m_endTimeThursday; }
	void setEndTimeThursday(int endTimeThursday) { m_endTimeThursday = endTimeThursday; }

	int startTimeFriday() { return m_startTimeFriday; }
	void setStartTimeFriday(int startTimeFriday) { m_startTimeFriday = startTimeFriday; }
	int endTimeFriday() { return m_endTimeFriday; }
	void setEndTimeFriday(int endTimeFriday) { m_endTimeFriday = endTimeFriday; }

	int startTimeSaturday() { return m_startTimeSaturday; }
	void setStartTimeSaturday(int startTimeSaturday) { m_startTimeSaturday = startTimeSaturday; }
	int endTimeSaturday() { return m_endTimeSaturday; }
	void setEndTimeSaturday(int endTimeSaturday) { m_endTimeSaturday = endTimeSaturday; }

	int startTimeSunday() { return m_startTimeSunday; }
	void setStartTimeSunday(int startTimeSunday) { m_startTimeSunday = startTimeSunday; }
	int endTimeSunday() { return m_endTimeSunday; }
	void setEndTimeSunday(int endTimeSunday) { m_endTimeSunday = endTimeSunday; }
private:
	bool m_pollingStartSwitch;
	int m_pollingInterval;

	int m_startTimeMonday;
	int m_endTimeMonday;
	int m_startTimeTuesday;
	int m_endTimeTuesday;
	int m_startTimeWednesday;
	int m_endTimeWednesday;
	int m_startTimeThursday;
	int m_endTimeThursday;
	int m_startTimeFriday;
	int m_endTimeFriday;
	int m_startTimeSaturday;
	int m_endTimeSaturday;
	int m_startTimeSunday;
	int m_endTimeSunday;
};

} /* namespace config */
} /* namespace dw */
#endif /* TRACKERSETTINGS_HPP_ */
