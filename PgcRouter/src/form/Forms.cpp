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

#include "Forms.hpp"

#include "FormEditor.hpp"
#include "FormViewer.hpp"

#include <bb/pim/notebook/NotebookEntry>

using namespace bb::cascades;
using namespace bb::pim::notebook;

//! [0]
Forms::Forms(QObject *parent)
    : QObject(parent)
    , m_formbookService(new NotebookService(this))
    , m_model(new GroupDataModel(this))
    , m_formViewer(new FormViewer(m_formbookService, this))
    , m_formEditor(new FormEditor(m_formbookService, this))
{
    // Disable grouping in data model
    m_model->setGrouping(ItemGrouping::None);

    // Ensure to invoke the filterNotes() method whenever a note has been added, changed or removed
    connect(m_formbookService, SIGNAL(notebookEntriesAdded(QList<bb::pim::notebook::NotebookEntryId>)), SLOT(filterNotes()));
    connect(m_formbookService, SIGNAL(notebookEntriesUpdated(QList<bb::pim::notebook::NotebookEntryId>)), SLOT(filterNotes()));
    connect(m_formbookService, SIGNAL(notebookEntriesDeleted(QList<bb::pim::notebook::NotebookEntryId>)), SLOT(filterNotes()));

    // Fill the data model with notes initially
    filterNotes();
}
//! [0]

//! [1]
void Forms::setCurrentNote(const QVariantList &indexPath)
{
    // Extract the ID of the selected note from the model
    if (indexPath.isEmpty()) {
        m_currentNoteId = NotebookEntryId();
    } else {
        const QVariantMap entry = m_model->data(indexPath).toMap();
        m_currentNoteId = entry.value("noteId").value<NotebookEntryId>();
    }
}
//! [1]

//! [2]
void Forms::createNote()
{
    // Prepare the note editor for creating a new note
    m_formEditor->reset();
    m_formEditor->setMode(FormEditor::CreateMode);
}
//! [2]

//! [3]
void Forms::editNote()
{
    // Prepare the note editor for editing the current note
    m_formEditor->loadNote(m_currentNoteId);
    m_formEditor->setMode(FormEditor::EditMode);
}
//! [3]

//! [4]
void Forms::viewNote()
{
    // Prepare the note viewer for displaying the current note
    m_formViewer->setNoteId(m_currentNoteId);
}
//! [4]

//! [5]
void Forms::deleteNote()
{
    m_formbookService->deleteNotebookEntry(m_currentNoteId);
}
//! [5]

bb::cascades::GroupDataModel* Forms::model() const
{
    return m_model;
}

QString Forms::filter() const
{
    return m_filter;
}

//! [6]
void Forms::setFilter(const QString &filter)
{
    if (m_filter == filter)
        return;

    m_filter = filter;
    emit filterChanged();

    // Update the model now that the filter criterion has changed
    filterNotes();
}
//! [6]

FormViewer* Forms::noteViewer() const
{
    return m_formViewer;
}

FormEditor* Forms::noteEditor() const
{
    return m_formEditor;
}

//! [7]
void Forms::filterNotes()
{
    NotebookEntryFilter filter;

    // Use the entered filter string as search string
    filter.setSearchString(m_filter);

    const QList<NotebookEntry> notes = m_formbookService->notebookEntries(filter);

    // Clear the old note information from the model
    m_model->clear();

    // Iterate over the list of notes
    foreach (const NotebookEntry &note, notes) {
        // Copy the data into a model entry
        QVariantMap entry;
        entry["noteId"] = QVariant::fromValue(note.id());
        entry["title"] = note.title();
        entry["status"] = FormViewer::statusToString(note.status());

        // Add the entry to the model
        m_model->insert(entry);
    }
}
//! [7]
