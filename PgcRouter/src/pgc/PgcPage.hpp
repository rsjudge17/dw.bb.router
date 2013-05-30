/*
 * PgcPage.hpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#ifndef PGCPAGE_HPP_
#define PGCPAGE_HPP_

#include <QObject>
#include "pgcdef.hpp"
#include "PageAddress.hpp"

namespace dw {
namespace pgc {

class PgcPage : public QObject {
	Q_OBJECT

public:
	PgcPage();
	virtual ~PgcPage();

	friend QDataStream& operator<<(QDataStream& os, const PgcPage& pgcPage);
	friend QDataStream& operator>>(QDataStream& is, PgcPage& pgcPage);

public:
	PageAddress m_PageAddress;
	qint32 m_StrokesOffset;
	qint32 m_StrokesDataSize;
	qint8 m_Flags;
	qint16 m_PidgetCount;
};

} /* namespace pgc */
} /* namespace dw */
#endif /* PGCPAGE_HPP_ */
