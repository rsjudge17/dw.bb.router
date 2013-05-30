/*
 * formitem.cpp
 *
 *  Created on: May 30, 2013
 *      Author: ruel
 */

#include "formentry.hpp"

namespace dw {
namespace form {

FormEntry::FormEntry() {
	// TODO Auto-generated constructor stub

}

FormEntry::~FormEntry() {
	// TODO Auto-generated destructor stub
}

QString FormEntry::title() const
{
	return m_title;
}

void FormEntry::setTitle(QString &title)
{
	m_title = title;
}

QString FormEntry::desc() const
{
	return m_desc;
}

void FormEntry::setDesc(QString &desc){
	m_desc = desc;
}

QString FormEntry::status() const{
	return m_status;
}

void FormEntry::setStatus(QString &status){
	m_status = status;
}

QString FormEntry::time() const{
	return m_time;
}

void FormEntry::setTime(QString &time){
	m_time = time;
}

} /* namespace form */
} /* namespace dw */
