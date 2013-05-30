/*
 * PgcProperty.cpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#include "PgcProperty.hpp"
#include <QDataStream>

namespace dw {
namespace pgc {

PgcProperty::PgcProperty() {
	// TODO Auto-generated constructor stub

}

PgcProperty::~PgcProperty() {
	// TODO Auto-generated destructor stub
}

QDataStream& operator<<(QDataStream& os, const PgcProperty& pgcProperty) {
	os << pgcProperty.m_PropertyId;
	os << pgcProperty.m_PropertyType;
	os << pgcProperty.m_PropertyData;

	return os;
}

QDataStream& operator>>(QDataStream& is, PgcProperty& pgcProperty) {
	is >> pgcProperty.m_PropertyId;
	is >> pgcProperty.m_PropertyType;
	quint16 propertyLength = 0;
	switch((int)(pgcProperty.m_PropertyType))
		{
	case VALUE_HEADER_TYPE_BOOLEAN:
	case VALUE_HEADER_TYPE_BYTE:
		propertyLength = 1;
		break;
	case VALUE_HEADER_TYPE_SHORT:
		propertyLength = 2;
		break;
	case VALUE_HEADER_TYPE_INTEGER:
		propertyLength = 4;
		break;
	case VALUE_HEADER_TYPE_LONG:
		propertyLength = 8;
		break;
	case VALUE_HEADER_TYPE_UNICODE:
		is >> propertyLength;
		//propertyLength = (TInt)ReadTUint16L();
		break;
		}


	//QByteArray data = new QByteArray(propertyLength);
	//pgcProperty.m_PropertyData;
	//TPtr8 ptr = (property.m_PropertyData)->Des();
	quint8 b;
	for (int i = 0; i < propertyLength; i++)
		{
			is >> b;
			pgcProperty.m_PropertyData += b;
		}
	//iFilePosition += propertyLength;

	return is;
}

} /* namespace pgc */
} /* namespace dw */
