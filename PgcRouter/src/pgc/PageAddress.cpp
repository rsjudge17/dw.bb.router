/*
 * PageAddress.cpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#include "PageAddress.hpp"
#include <QDataStream>

namespace dw {
namespace pgc {

PageAddress::PageAddress()
	: m_SegmentID(-1),
	  m_ShelfID(-1),
	  m_BookID(-1),
	  m_PageID(-1){
	// TODO Auto-generated constructor stub

}

PageAddress::~PageAddress() {
	// TODO Auto-generated destructor stub
}

QDataStream& operator<<(QDataStream& os, const PageAddress& pageAddress) {
	os << pageAddress.m_pageAddress;

	return os;
}

QDataStream& operator>>(QDataStream& is, PageAddress& pageAddress) {
	is >> pageAddress.m_pageAddress;
	pageAddress.SetPageAddress(pageAddress.m_pageAddress);

	return is;
}

void PageAddress::SetPageAddress(quint64 pageAddress) {
	m_pageAddress = pageAddress;

	m_PageID = (qint16)(pageAddress & 0xFFF);
	m_BookID = (qint16)((pageAddress >> 12) & 0xFFF);
	m_ShelfID = (qint16)((pageAddress >> 24) & 0xFFFF);
	m_SegmentID = (qint16)((pageAddress >> 40) & 0xFFF);
}

void PageAddress::SetPageAddress(const QString& addressString) {

}

bool PageAddress::IsEqual(const PageAddress& addressForCompare) {
	if (addressForCompare.m_PageID >= 0 &&
			m_PageID >= 0 &&
			m_PageID != addressForCompare.m_PageID)
		{
		return false;
		}

	if (addressForCompare.m_BookID >= 0 &&
			m_BookID >= 0 &&
		m_BookID != addressForCompare.m_BookID)
		{
		return false;
		}

	if (addressForCompare.m_SegmentID >= 0 &&
			m_SegmentID >= 0 &&
		m_SegmentID != addressForCompare.m_SegmentID)
		{
		return false;
		}

	if (addressForCompare.m_ShelfID >= 0 &&
			m_ShelfID >= 0 &&
		m_ShelfID != addressForCompare.m_ShelfID)
		{
		return false;
		}

	return true;
}

bool PageAddress::IsInvalid() {
	if (m_PageID >= 0)
		{
		return false;
		}

	if (m_BookID >= 0)
		{
		return false;
		}

	if (m_SegmentID >= 0)
		{
		return false;
		}

	if (m_ShelfID >= 0)
		{
		return false;
		}

	return true;
}

QString PageAddress:: GetFormatedPageAddress() {
	QString addr;

	addr = m_SegmentID + ".";
	addr += m_ShelfID + ".";
	addr += m_BookID + ".";
	addr += m_PageID;

	return addr;
}

} /* namespace pgc */
} /* namespace dw */
