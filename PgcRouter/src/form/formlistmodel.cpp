// List with context menu project template
#include "formlistmodel.hpp"

#include <QVariant>
#include <bb/data/JsonDataAccess>

using namespace bb::cascades;

namespace dw {
namespace form {

FormListModel::FormListModel(QObject* parent)
: bb::cascades::QVariantListDataModel()
{
    qDebug() << "Creating FormListModel object:" << this;
    setParent(parent);

    //bb::cascades::GroupDataModel::setSortingKeys( QStringList() << "time" );
    //setGrouping(ItemGrouping::None);
}

FormListModel::~FormListModel()
{
    qDebug() << "Destroying FormListModel object:" << this;
}

void FormListModel::load(const QString& file_name)
{
	m_filter = "Forms";

    bb::data::JsonDataAccess jda;
    mFormData = jda.load(file_name).value<QVariantList>();
    if (jda.hasError()) {
        bb::data::DataAccessError error = jda.error();
        qDebug() << file_name << "JSON loading error: " << error.errorType() << ": " << error.errorMessage();
    }
    else {
        qDebug() << file_name << "JSON data loaded OK!";
        append(mFormData);
    }
}

QString FormListModel::filter() const
{
    return m_filter;
}

//! [6]
void FormListModel::setFilter(const QString &filter)
{
    if (m_filter == filter)
        return;

    QVariantList filteredBucketData;

	// Remove all the old data.
	clear();

	if (filter == "Forms")
	{
		append(mFormData);
	}
	else
	{
		for (int i = 0; i < mFormData.size(); i++)
		{
			QVariant v = mFormData.value(i);
			QString value(v.toMap().value("status").toString());
			if (filter == QString("Inbox") && (value == QString("new") || value == QString("opened")) )
			{
				filteredBucketData << v;
				append(v.toMap());
			}
			else if (filter == "Outbox" && (value == "verified" || value == "sending"))
			{
				filteredBucketData << v;
				append(v.toMap());
			}
			else if (filter == "Sent Items" && value == "sent")
			{
				filteredBucketData << v;
				append(v.toMap());
			}
		}
	}

    m_filter = filter;
    emit filterChanged();
}

QVariant FormListModel::value(int ix, const QString &fld_name)
{
    QVariant ret;
    // model data are organized in a list of dictionaries
    if(ix >= 0 && ix < size()) {
        // get dictionary on index
        QVariantMap curr_val = QVariantListDataModel::value(ix).toMap();
        ret = curr_val.value(fld_name);
    }
    return ret;
}

void FormListModel::setValue(int ix, const QString& fld_name, const QVariant& val)
{
    // model data are organized in a list of dictionaries
    if(ix >= 0 && ix < size()) {
        // get dictionary on index
        QVariantMap curr_val = QVariantListDataModel::value(ix).value<QVariantMap>();
        // set dictionary value for key fld_name
        curr_val[fld_name] = val;
        // replace updated dictionary in array
        replace(ix, curr_val);
    }
}

} /* namespace form */
} /* namespace dw */

