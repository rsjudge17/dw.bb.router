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
#include "pgcrouterapp.h"

#include <QFile>
#include <QDir>
#include <QUrl>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/data/JsonDataAccess>

#include "config.hpp"
#include "QtObjectFormatter.hpp"
#include "formlistmodel.hpp"

using namespace bb::cascades;
using namespace bb::system;

using namespace dw::config;
using namespace bb::data;
using namespace dw::form;

const QString PgcRouterApp::PATH_ASSET = QString("/app/native/assets/");
const QString PgcRouterApp::PATH_BLUETOOTH = QString("/sharewith/bluetooth/");

static QString assetPath(const QString& assetName)
{
    return QDir::currentPath() + PgcRouterApp::PATH_ASSET + assetName;
}

static QString bluetoothPath(const QString& fileName)
{
    return QDir::currentPath() + PgcRouterApp::PATH_BLUETOOTH + fileName;
}

PgcRouterApp::PgcRouterApp(bb::cascades::Application *app)
	: QObject(app)
	, m_appSettings(new AppSettings(app))
	, m_invokeManager(new InvokeManager(this))
{

	// Listen to incoming invocation requests
	connect(m_invokeManager, SIGNAL(invoked(const bb::system::InvokeRequest&)),
			this, SLOT(handleInvoke(const bb::system::InvokeRequest&)));
	connect(m_invokeManager,
			SIGNAL(cardResizeRequested(const bb::system::CardResizeMessage&)),
			this, SLOT(resized(const bb::system::CardResizeMessage&)));
	connect(m_invokeManager,
			SIGNAL(cardPooled(const bb::system::CardDoneMessage&)), this,
			SLOT(pooled(const bb::system::CardDoneMessage&)));

	m_source = m_target = m_action = m_mimeType = m_uri = m_data = m_status =
			tr("--");

	// Initialize properties with default values
	switch (m_invokeManager->startupMode()) {
	case ApplicationStartupMode::LaunchApplication:
		m_startupMode = tr("Launch");
		//initFullUI();
		break;
	case ApplicationStartupMode::InvokeApplication:
		// Wait for invoked signal to determine and initialize the appropriate UI
		m_startupMode = tr("Invoke");
		break;
	case ApplicationStartupMode::InvokeCard:
		// Wait for invoked signal to determine and initialize the appropriate UI
		m_startupMode = tr("Card");
		break;
	}

	loadConfig();
}

// SLOTS

void PgcRouterApp::handleInvoke(const InvokeRequest& request) {
	// Copy data from incoming invocation request to properties
	m_source =
			QString::fromLatin1("%1 (%2)").arg(request.source().installId()).arg(
					request.source().groupId());
	m_target = request.target();
	m_action = request.action();
	m_mimeType = request.mimeType();
	m_uri = request.uri().toString();
	m_data = QString::fromUtf8(request.data());

	QUrl uri = request.uri();

	QFile file(uri.toLocalFile());

	if (m_target == "com.destinywireless.app.pgcrouter") {

	} else if (m_target == "com.destinywireless.app.pgcsender") {

	} else if (m_target == "com.destinywireless.card.formeditor") {

	} else if (m_target == "com.destinywireless.card.formviewer") {

	} else if (m_target == "com.destinywireless.card.attachphoto") {

	}

	// Signal that the properties have changed
	emit requestChanged();
}


void PgcRouterApp::cardDone(const QString& msg) {
	// Assemble message
	CardDoneMessage message;
	message.setData(msg);
	message.setDataType("text/plain");
	message.setReason(tr("Success!"));

	// Send message
	m_invokeManager->sendCardDone(message);
}

void PgcRouterApp::resized(const bb::system::CardResizeMessage&) {
	m_status = tr("Resized");
	emit statusChanged();
}

void PgcRouterApp::pooled(const bb::system::CardDoneMessage& doneMessage) {
	m_status = tr("Pooled");
	m_source = m_target = m_action = m_mimeType = m_uri = m_data = tr("--");
	emit statusChanged();
	emit requestChanged();
}

// SLOTS

void PgcRouterApp::loadForms()
{
	m_formListModel = new FormListModel(this);
	m_formListModel->load(assetPath("model/" + m_appSettings->forms()->inboxFile()));

	// Obtain a QMLDocument and load it into the qml variable, using build patterns.
	QmlDocument *qml = QmlDocument::create("asset:///main.qml");

	// If the QML document is valid, we process it.
	if (!qml->hasErrors()) {

		qml->setContextProperty("_formList", m_formListModel);
		// Create the application Page from QMLDocument.
		AbstractPane *root = qml->createRootObject<AbstractPane>();

		if (root) {
			// Set the main scene for the application to the Page.
			Application::instance()->setScene(root);
		}
	}
}

void PgcRouterApp::loadConfig()
{
	if ( m_appSettings->hasConfiguration() )
		m_firstRun = false;
	else
		m_firstRun = true;

	connect(m_appSettings, SIGNAL(loadCompleted()), this, SLOT(onSettingsLoadCompleted()));
	connect(m_appSettings, SIGNAL(saveCompleted()), this, SLOT(onSettingsSaveCompleted()));
	connect(m_appSettings, SIGNAL(loadError(const QString&)), this, SLOT(onSettingsLoadFailed(const QString&)));
	connect(m_appSettings, SIGNAL(saveError(const QString&)), this, SLOT(onSettingsSaveFailed(const QString&)));

	m_appSettings->loadFormXml(assetPath(Config::QSETTINGS_CONFIG_FILENAME));
}

void PgcRouterApp::onSettingsLoadCompleted()
{
	if (m_firstRun)
	{

	}

	loadForms();
}

void PgcRouterApp::onSettingsSaveCompleted()
{

}

void PgcRouterApp::onSettingsLoadFailed(const QString& errorStr)
{
	qDebug() << "Unable to load settings " << assetPath(Config::QSETTINGS_CONFIG_FILENAME) << errorStr;
}

void PgcRouterApp::onSettingsSaveFailed(const QString& errorStr)
{
	qDebug() << "Unable to save " << errorStr;
}

QString PgcRouterApp::startupMode() const {
	return m_startupMode;
}

QString PgcRouterApp::source() const {
	return m_source;
}

QString PgcRouterApp::target() const {
	return m_target;
}

QString PgcRouterApp::action() const {
	return m_action;
}

QString PgcRouterApp::mimeType() const {
	return m_mimeType;
}

QString PgcRouterApp::uri() const {
	return m_uri;
}

QString PgcRouterApp::data() const {
	return m_data;
}

QString PgcRouterApp::status() const {
	return m_status;
}
