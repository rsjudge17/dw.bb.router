/*
 * PgcFile.cpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#include "PgcFile.hpp"
#include <QDataStream>

namespace dw {
namespace pgc {

PgcFile::PgcFile(QObject *parent)
{
	setParent(parent);
}

PgcFile::~PgcFile() {
	//delete m_PagesList;
	//delete m_PropertiesList;
}

QDataStream& operator << (QDataStream &os, const PgcFile& pgcFile) {

	pgcFile.writeHeader(os);

	int size = pgcFile.m_PagesList.size();
	for (int i = 0; i < size; i++)
		{
		PgcPage* pgcPage = pgcFile.m_PagesList.at(i);
		os << *pgcPage;
		}

	size = pgcFile.m_PropertiesList.size();
	for (int j = 0; j < size; j++)
		{
		PgcProperty* pgcProperty = pgcFile.m_PropertiesList.at(j);
		os << *pgcProperty;
		}

	return os;
}

QDataStream& operator >> (QDataStream &is, PgcFile& pgcFile) {

	pgcFile.readHeader(is);

	for (qint16 i = 0; i < pgcFile.m_PageCount; i++)
		{
		PgcPage pgcPage;
		is >> pgcPage;

		pgcFile.m_PagesList.append(&pgcPage);
		}

	for (qint16 j = 0; j < pgcFile.m_PropertyCount; j++)
		{
		PgcProperty pgcProperty;
		is >> pgcProperty;

		pgcFile.m_PropertiesList.append(&pgcProperty);
		}

	return is;
}

void PgcFile::readHeader(QDataStream& is) {
	is >> m_ProtocolMajorVersion;
	is >> m_ProtocolMinorVersion;
	is >> m_HeaderSize;
	is >> m_SendingPageAddress;
	is >> m_SendingPidgetId;
	is >> m_PageHeaderSize;
	is >> m_PidgetHeaderSize;
	is >> m_PropertyHeaderSize;
	is >> m_ValueHeaderSize;
	is >> m_PageCount;
	is >> m_PropertyCount;
}

void PgcFile::writeHeader(QDataStream& os) const {
	os << m_ProtocolMajorVersion;
	os << m_ProtocolMinorVersion;
	os << m_HeaderSize;
	os << m_SendingPageAddress;
	os << m_SendingPidgetId;
	os << m_PageHeaderSize;
	os << m_PidgetHeaderSize;
	os << m_PropertyHeaderSize;
	os << m_ValueHeaderSize;
	os << m_PageCount;
	os << m_PropertyCount;
}

} /* namespace pgc */
} /* namespace dw */
