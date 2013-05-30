// List with context menu project template
/*
 * ListModel.h
 */

#ifndef FormListModel_HPP_
#define FormListModel_HPP_

#include <QObject>
#include <QString>
#include <QVariant>
#include <QMetaType>
#include <bb/cascades/QListDataModel>

namespace dw {
namespace form {

/*!
 * @brief Mutable list model implementation
 */
class FormListModel : public bb::cascades::QVariantListDataModel
{
    Q_OBJECT

    // The pattern to filter the list of messages
    Q_PROPERTY(QString filter READ filter WRITE setFilter NOTIFY filterChanged);

public:
    /*!
     * @brief Convenience method for loading data from JSON file.
     *
     * @param file_name  file to load
     */
    Q_INVOKABLE void load(const QString& file_name);
    /*!
     * @brief Convenience method to read the model data.
     *
     * @param ix  index of the list item
     * @param fld_name  name of data field
     */
    Q_INVOKABLE QVariant value(int ix, const QString &fld_name);
    /*!
     * @brief Convenience method to set the model data.
     *
     * @param ix  index of the list item
     * @param fld_name  name of data field
     * @param val  new value
     */
    Q_INVOKABLE void setValue(int ix, const QString &fld_name, const QVariant &val);
public:
    FormListModel(QObject* parent = 0);
    virtual ~FormListModel();


Q_SIGNALS:
	// The change notification signal for the property
	void filterChanged();

public:
    QString filter() const;
    Q_INVOKABLE void setFilter(const QString &filter);
private:
    QString m_filter;
    QVariantList mFormData;
};

} /* namespace form */
} /* namespace dw */
#endif /* FormListModel_HPP_ */
