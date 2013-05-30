/*
 * PgcPage.cpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#include "PgcPage.hpp"
#include <QDataStream>

namespace dw {
namespace pgc {

PgcPage::PgcPage() {
	// TODO Auto-generated constructor stub

}

PgcPage::~PgcPage() {
	// TODO Auto-generated destructor stub
}

QDataStream& operator<<(QDataStream& os, const PgcPage& pgcPage) {
	os << pgcPage.m_PageAddress;

	os << pgcPage.m_StrokesDataSize;
	os << pgcPage.m_Flags;
	os << pgcPage.m_PidgetCount;

	quint8 skip;
	for (qint32 i = 0; i < pgcPage.m_StrokesDataSize; i++)
		{
		//is.operator >>(skip);
		os << skip;
		}

	//skip pidjets
	qint16 pidgetId;
	qint8 pidgetHeader;
	qint16 valueCount;

	for(qint16 j = 0; j < pgcPage.m_PidgetCount; j++)
		{
		os << pidgetId;
		os << pidgetHeader;
		os << valueCount;

		qint8 type;
		qint64 value;
		for (qint16 k = 0; k < valueCount; k++)
			{
			os << type;
			os << value;
			}
		}

	return os;
}

QDataStream& operator>>(QDataStream& is, PgcPage& pgcPage) {
	is >> pgcPage.m_PageAddress;

	//LOG_MSG(CDestinyLog::EDebug,
	//	_L("CDestinyPgcFileReader::ReadPageL iPageAddress=%d.%d.%d.%d"),
	//	page.iPageAddress.iSegmentID,
	//	page.iPageAddress.iShelfID,
	//	page.iPageAddress.iBookID,
	//	page.iPageAddress.iPageID);

	is >> pgcPage.m_StrokesDataSize;
	is >> pgcPage.m_Flags;
	is >> pgcPage.m_PidgetCount;
	//save start position for strokes data. It will be need for retrive
	//stroke information later.
	//pgcPage.m_StrokesOffset = iFilePosition;


	//LOG_MSG(CDestinyLog::EDebug,
	//	_L("CDestinyPgcFileReader::ReadPageL iStrokesDataSize=%d, iFlags=%d, iPidgetCount=%d"),
	//	page.iStrokesDataSize,
	//	page.iFlags,
	//	page.iPidgetCount);

	//skip stroke data
	quint8 skip;
	for (qint32 i = 0; i < pgcPage.m_StrokesDataSize; i++)
		{
		//is.operator >>(skip);
		is >> skip;
		}

	//skip pidjets
	qint16 pidgetId;
	qint8 pidgetHeader;
	qint16 valueCount;

	for(qint16 j = 0; j < pgcPage.m_PidgetCount; j++)
		{
		is >> pidgetId;
		is >> pidgetHeader;
		is >> valueCount;

		qint8 type;
		qint64 value;
		for (qint16 k = 0; k < valueCount; k++)
			{
			is >> type;
			is >> value;
			}
		}

	return is;
}

} /* namespace pgc */
} /* namespace dw */
