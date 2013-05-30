/*
 * PgcProperty.hpp
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#ifndef PGCPROPERTY_HPP_
#define PGCPROPERTY_HPP_

#include <QObject>
#include <QString>
#include "pgcdef.hpp"

namespace dw {
namespace pgc {

class PgcProperty : public QObject {
	Q_OBJECT

public:
	PgcProperty();
	virtual ~PgcProperty();

	friend QDataStream& operator<<(QDataStream& os, const PgcProperty& pgcProperty);
	friend QDataStream& operator>>(QDataStream& is, PgcProperty& pgcProperty);

public:
	quint16 m_PropertyId;
	quint8 m_PropertyType;
	QString m_PropertyData;
};

} /* namespace pgc */
} /* namespace dw */
#endif /* PGCPROPERTY_HPP_ */
