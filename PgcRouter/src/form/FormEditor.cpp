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

#include "FormEditor.hpp"

#include <bb/pim/notebook/NotebookEntry>
#include <bb/pim/notebook/NotebookEntryStatus>

using namespace bb::pim::notebook;

//! [1]
FormEditor::FormEditor(NotebookService *service, QObject *parent)
    : QObject(parent)
    , m_notebookService(service)
    , m_dueDateTime(QDateTime::currentDateTime())
    , m_completed(false)
    , m_mode(CreateMode)
{
}
//! [1]

//! [2]
void FormEditor::loadNote(const NotebookEntryId &noteId)
{
    m_noteId = noteId;

    // Load the note from the persistent storage
    const NotebookEntry note = m_notebookService->notebookEntry(m_noteId);

    // Update the properties with the data from the note
    m_title = note.title();
    m_description = note.description();
    m_dueDateTime = note.dueDateTime();
    m_completed = (note.status() == NotebookEntryStatus::Completed);

    // Emit the change notifications
    emit titleChanged();
    emit descriptionChanged();
    emit dueDateTimeChanged();
    emit completedChanged();
}
//! [2]

//! [3]
void FormEditor::saveNote()
{
    if (m_mode == CreateMode) {
        NotebookEntry *note = new NotebookEntry;

        note->setTitle(m_title);
        note->setDescription(m_description);
        note->setDueDateTime(m_dueDateTime);
        note->setStatus(m_completed ? NotebookEntryStatus::Completed : NotebookEntryStatus::NotCompleted);

        // Save the note to persistent storage (always store in system default notebook)
        m_notebookService->addNotebookEntry(note, m_notebookService->defaultNotebook().id());

    } else if (m_mode == EditMode) {
        // Load the note from persistent storage
        NotebookEntry note = m_notebookService->notebookEntry(m_noteId);

        if (note.isValid()) {
            // Update the single attributes
            note.setTitle(m_title);
            note.setDescription(m_description);
            note.setDueDateTime(m_dueDateTime);
            note.setStatus(m_completed ? NotebookEntryStatus::Completed : NotebookEntryStatus::NotCompleted);

            // Save the updated note back to persistent storage
            m_notebookService->updateNotebookEntry(note);
        }
    }
}
//! [3]

//! [4]
void FormEditor::reset()
{
    // Reset all properties
    m_title.clear();
    m_description = NotebookEntryDescription();
    m_dueDateTime = QDateTime::currentDateTime();
    m_completed = false;

    // Emit the change notifications
    emit titleChanged();
    emit descriptionChanged();
    emit dueDateTimeChanged();
    emit completedChanged();
}
//! [4]

void FormEditor::setTitle(const QString &title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged();
}

QString FormEditor::title() const
{
    return m_title;
}

void FormEditor::setDescription(const QString &description)
{
    if (m_description.plainText() == description)
        return;

    m_description.setText(description);
    emit descriptionChanged();
}

QString FormEditor::description() const
{
    return m_description.plainText();
}

void FormEditor::setDueDateTime(const QDateTime &dueDateTime)
{
    if (m_dueDateTime == dueDateTime)
        return;

    m_dueDateTime = dueDateTime;
    emit dueDateTimeChanged();
}

QDateTime FormEditor::dueDateTime() const
{
    return m_dueDateTime;
}

void FormEditor::setCompleted(bool completed)
{
    if (m_completed == completed)
        return;

    m_completed = completed;
    emit completedChanged();
}

bool FormEditor::completed() const
{
    return m_completed;
}

void FormEditor::setMode(Mode mode)
{
    if (m_mode == mode)
        return;

    m_mode = mode;
    emit modeChanged();
}

FormEditor::Mode FormEditor::mode() const
{
    return m_mode;
}
