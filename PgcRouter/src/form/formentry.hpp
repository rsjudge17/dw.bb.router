/*
 * formitem.hpp
 *
 *  Created on: May 30, 2013
 *      Author: ruel
 */

#ifndef FORMENTRY_HPP_
#define FORMENTRY_HPP_

#include <QtCore>

namespace dw {
namespace form {

class FormEntry: public QObject {
	Q_OBJECT

	Q_PROPERTY(QString title READ title WRITE setTitle);
	Q_PROPERTY(QString desc READ desc WRITE setDesc);
	Q_PROPERTY(QString status READ status WRITE setStatus);
	Q_PROPERTY(QString time READ time WRITE setTime);

public:
	FormEntry();
	virtual ~FormEntry();

private:
    // The accessor methods of the properties
   QString title() const;
   void setTitle(QString &title);
   QString desc() const;
   void setDesc(QString &desc);
   QString status() const;
   void setStatus(QString &status);
   QString time() const;
   void setTime(QString &time);

private:

	QString  m_title;
	QString  m_desc;
	QString  m_status;
	QString	 m_time;
	QDate	 m_date;
	QMap<QString, QString> mAttachments;
};

} /* namespace form */
} /* namespace dw */
#endif /* FORMENTRY_HPP_ */
