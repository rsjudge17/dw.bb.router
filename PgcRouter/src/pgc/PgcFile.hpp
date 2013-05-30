/*
 * PgcFile.hpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#ifndef PGCFILE_HPP_
#define PGCFILE_HPP_

#include <QObject>
#include <QList>

#include "pgcdef.hpp"
#include "PgcPage.hpp"
#include "PgcProperty.hpp"

namespace dw {
namespace pgc {

//class PgcPage;
//class PgcProperty;

typedef QList<PgcPage*> PgcPageList;
typedef QList<PgcProperty*> PgcPropertyList;

class PgcFile : public QObject {
	Q_OBJECT

public:
	PgcFile(QObject *parent = 0);
	virtual ~PgcFile();

	friend QDataStream& operator<<(QDataStream& os, const PgcFile& pgcFile);
	friend QDataStream& operator>>(QDataStream& is, PgcFile& pgcFile);

	void readHeader(QDataStream& is);
	void writeHeader(QDataStream& os) const;

public:
	quint8 m_ProtocolMajorVersion;
	quint8 m_ProtocolMinorVersion;

	qint64 m_SendingPageAddress;
	qint16 m_SendingPidgetId;

	qint16 m_HeaderSize;
	qint16 m_PageHeaderSize;
	qint16 m_PidgetHeaderSize;
	qint16 m_PropertyHeaderSize;
	qint16 m_ValueHeaderSize;
	qint16 m_PageCount;
	qint16 m_PropertyCount;

	PgcPageList m_PagesList;
	PgcPropertyList m_PropertiesList;
};

} /* namespace pgc */
} /* namespace dw */
#endif /* PGCFILE_HPP_ */
