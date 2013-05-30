/* Copyright (c) 2012 Research In Motion Limited.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "PgcMessages.hpp"

#include <bb/cascades/DropDown>
#include <bb/cascades/Option>
#include <bb/pim/account/AccountService>
#include <bb/pim/account/Account>
#include <bb/pim/account/Provider>
#include <bb/pim/message/MessageSearchFilter>

//#include "MessageComposer.hpp"
//#include "MessageViewer.hpp"

using namespace bb::cascades;
using namespace bb::pim::account;
using namespace bb::pim::message;

//! [0]
PgcMessages::PgcMessages(QObject *parent)
    : QObject(parent)
    , m_messageService(new MessageService(this))
    , m_model(new GroupDataModel(this))
    , m_currentMessageId(-1)
{
    // Disable grouping in data model
    m_model->setGrouping(ItemGrouping::None);

    // Ensure to invoke the filterMessages() method whenever a message has been added, changed or removed
    connect(m_messageService, SIGNAL(messagesAdded(bb::pim::account::AccountKey, QList<bb::pim::message::ConversationKey>, QList<bb::pim::message::MessageKey>)), SLOT(filterMessages()));
    connect(m_messageService, SIGNAL(messageAdded(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey)), SLOT(filterMessages()));
    connect(m_messageService, SIGNAL(messageUpdated(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey, bb::pim::message::MessageUpdate)), SLOT(filterMessages()));
    connect(m_messageService, SIGNAL(messageRemoved(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey, QString)), SLOT(filterMessages()));

    // Initialize the current account if there is any
    m_accountList = AccountService().accounts(Service::Messages);
    if(!m_accountList.isEmpty())
        m_currentAccount = m_accountList.first();

    // Fill the data model with messages initially
    inbox();
}
//! [0]

void PgcMessages::addAccounts(QObject* dropDownObject) const
{
    DropDown* dropDown = qobject_cast<DropDown*>(dropDownObject);

    bool selected = true;
    foreach (const Account &account, m_accountList) {
        const QString name = (account.displayName().isEmpty() ? tr("No Name") : account.displayName());

        Option::Builder option = Option::create().text(tr("%1 (%2)").arg(name, account.provider().name()))
                                                 .value(QVariant::fromValue(account.id()))
                                                 .selected(selected);

        selected = false;

        dropDown->add(option);
    }
}

void PgcMessages::setSelectedAccount(bb::cascades::Option *selectedOption)
{
    foreach (const Account &account, m_accountList) {
        if (account.id() == selectedOption->value().value<AccountKey>()) {
            m_currentAccount = account;
            break;
        }
    }

    filterMessages();
}

//! [1]
void PgcMessages::setCurrentMessage(const QVariantList &indexPath)
{
    // Extract the ID of the selected message from the model
    if (indexPath.isEmpty()) {
        m_currentMessageId = -1;
    } else {
        const QVariantMap entry = m_model->data(indexPath).toMap();
        m_currentMessageId = entry.value("messageId").toInt();
    }
}
//! [1]

//! [5]
void PgcMessages::deleteMessage()
{
    m_messageService->remove(m_currentAccount.id(), m_currentMessageId);
}
//! [5]

bb::cascades::GroupDataModel* PgcMessages::model() const
{
    return m_model;
}

void PgcMessages::inbox()
{
	m_folderid = bb::pim::message::MessageFolder::Inbox;
	setFilter("*");
}

void PgcMessages::outbox()
{
	m_folderid = bb::pim::message::MessageFolder::Outbox;
	setFilter("*");
}

void PgcMessages::sentItems()
{
	m_folderid = bb::pim::message::MessageFolder::Sent;
	setFilter("*");
}

QString PgcMessages::filter() const
{
    return m_filter;
}

//! [6]
void PgcMessages::setFilter(const QString &filter)
{
    if (m_filter == filter)
        return;

    m_filter = filter;
    emit filterChanged();

    // Update the model now that the filter criterion has changed
    filterMessages();
}
//! [6]

//MessageViewer* PgcMessages::messageViewer() const
//{
//    return m_messageViewer;
//}

//MessageComposer* PgcMessages::messageComposer() const
//{
//    return m_messageComposer;
//}

//! [7]
void PgcMessages::filterMessages()
{
    if (!m_currentAccount.isValid())
        return;

    // Use the entered filter string as search value
    MessageSearchFilter filter;
    filter.setFolderId(m_folderid);
    filter.addSearchCriteria(SearchFilterCriteria::Any, m_filter);

    const QList<Message> messages = m_messageService->searchLocal(m_currentAccount.id(), filter);

    // Clear the old message information from the model
    m_model->clear();

    // Iterate over the list of message IDs
    foreach (const Message &message, messages) {
        // Copy the data into a model entry
        QVariantMap entry;
        entry["messageId"] = message.id();
        entry["subject"] = message.subject();
        entry["time"] = message.serverTimestamp().toString();

        // Add the entry to the model
        m_model->insert(entry);
    }
}
//! [7]
