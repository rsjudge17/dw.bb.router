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

#include <bb/cascades/Application>
#include <bb/cascades/pickers/FilePicker>

#include <Qt/qdeclarativedebug.h>
#include <QLocale>
#include <QTranslator>

#include "pgcrouterapp.h"


using ::bb::cascades::Application;

Q_DECL_EXPORT int main(int argc, char **argv)
{
	// Add the following lines to the C++ main program to register FilePicker
	qmlRegisterType<bb::cascades::pickers::FilePicker>("bb.cascades.customcomponents", 1, 0,"FilePicker");

    // Instantiate the main application constructor.
    Application app(argc, argv);
    app.setOrganizationName("Destiny Wireless");
    app.setOrganizationDomain("destinywireless.com");
    app.setApplicationName("PgcRouter");

    // Set up the translator.
    QTranslator translator;
    QString locale_string = QLocale().name();
    QString filename = QString("PgcRouter_%1").arg(locale_string);
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator(&translator);
    }

    // Initialize our application.
    PgcRouterApp mainApp(&app);

    // We complete the transaction started in the main application constructor and start the
    // client event loop here. When loop is exited the Application deletes the scene which
    // deletes all its children.
    return Application::exec();
}

