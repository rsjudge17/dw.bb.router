/*
 * PageAddress.hpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#ifndef PAGEADDRESS_HPP_
#define PAGEADDRESS_HPP_

#include <QObject>
#include <QString>

#include "pgcdef.hpp"

namespace dw {
namespace pgc {

class PageAddress {
public:
	PageAddress();
	virtual ~PageAddress();

	friend QDataStream& operator<<(QDataStream& os, const PageAddress& pageAddress);
	friend QDataStream& operator>>(QDataStream& is, PageAddress& pageAddress);

	void SetPageAddress(quint64 pageAddress);
	void SetPageAddress(const QString& addressString);

	bool IsEqual(const PageAddress& addressForCompare);
	bool IsInvalid();
	QString GetFormatedPageAddress();

public:

	quint64 m_pageAddress;
	qint16 m_SegmentID;
	qint16 m_ShelfID;
	qint16 m_BookID;
	qint16 m_PageID;
};

} /* namespace pgc */
} /* namespace dw */
#endif /* PAGEADDRESS_HPP_ */
