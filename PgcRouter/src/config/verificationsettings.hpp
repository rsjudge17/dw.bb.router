/*
 * verificationsettings.hpp
 *
 *  Created on: May 28, 2013
 *      Author: ruel
 */

#ifndef VERIFICATIONSETTINGS_HPP_
#define VERIFICATIONSETTINGS_HPP_

#include "config.hpp"

namespace dw {
namespace config {

class VerificationSettings : public Config {
	Q_OBJECT

	Q_PROPERTY(bool autoStart READ isAutoStart WRITE setAutoStart);
	Q_PROPERTY(bool alwaysAttachPhoto READ isAlwaysAttachPhoto WRITE setAlwaysAttachPhoto);
	Q_PROPERTY(bool sendGPSDestiny READ isSendGPSDestiny WRITE setSendGPSDestiny);
	Q_PROPERTY(QString fileType READ fileType WRITE setFileType);

public:
	VerificationSettings(QSettings *settings);
	virtual ~VerificationSettings();

	virtual bool load(const QSettings& settings);

public:
	bool isAutoStart() { return m_autoStart; }
	void setAutoStart(bool autoStart) { m_autoStart = autoStart; }
	bool isAlwaysAttachPhoto() { return m_alwaysAttachPhoto; }
	void setAlwaysAttachPhoto(bool alwaysAttachPhoto) { m_alwaysAttachPhoto = alwaysAttachPhoto; }
	bool isSendGPSDestiny() { return m_sendGPSDestiny; }
	void setSendGPSDestiny(bool sendGPSDestiny) { m_sendGPSDestiny = sendGPSDestiny; }
	QString fileType() { return m_fileType; }
	void setFileType(QString fileType) { m_fileType = fileType; }

private:
	bool m_autoStart;
	bool m_alwaysAttachPhoto;
	bool m_sendGPSDestiny;
	QString m_fileType;
};

} /* namespace config */
} /* namespace dw */
#endif /* VERIFICATIONSETTINGS_HPP_ */
