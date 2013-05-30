# Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR =  $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        INCLUDEPATH +=  $$quote(${QNX_TARGET}/usr/include/bb/data) \
                 $$quote(${QNX_TARGET}/usr/include/bb/cascades/pickers) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtXml) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                 $$quote(${QNX_TARGET}/usr/include/bb) \
                 $$quote(${QNX_TARGET}/usr/include/bb/system) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtDeclarative)

        DEPENDPATH +=  $$quote(${QNX_TARGET}/usr/include/bb/data) \
                 $$quote(${QNX_TARGET}/usr/include/bb/cascades/pickers) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtXml) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                 $$quote(${QNX_TARGET}/usr/include/bb) \
                 $$quote(${QNX_TARGET}/usr/include/bb/system) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtDeclarative)

        LIBS += -lbbcascades \
                -lQtCore \
                -lQtXml \
                -lbbpim \
                -lQtDeclarative \
                -lbbcascadespickers \
                -lbb \
                -lbbdata \
                -lbbsystem

        SOURCES +=  $$quote($$BASEDIR/src/QtObjectFormatter.cpp) \
                 $$quote($$BASEDIR/src/appsettings.cpp) \
                 $$quote($$BASEDIR/src/config/config.cpp) \
                 $$quote($$BASEDIR/src/config/formconfig.cpp) \
                 $$quote($$BASEDIR/src/config/generalsettings.cpp) \
                 $$quote($$BASEDIR/src/config/helpconfig.cpp) \
                 $$quote($$BASEDIR/src/config/logsconfig.cpp) \
                 $$quote($$BASEDIR/src/config/penconfig.cpp) \
                 $$quote($$BASEDIR/src/config/routerconfig.cpp) \
                 $$quote($$BASEDIR/src/config/settingsconfig.cpp) \
                 $$quote($$BASEDIR/src/config/supportconfig.cpp) \
                 $$quote($$BASEDIR/src/config/trackersettings.cpp) \
                 $$quote($$BASEDIR/src/config/verificationsettings.cpp) \
                 $$quote($$BASEDIR/src/form/FormEditor.cpp) \
                 $$quote($$BASEDIR/src/form/FormViewer.cpp) \
                 $$quote($$BASEDIR/src/form/Forms.cpp) \
                 $$quote($$BASEDIR/src/form/formentry.cpp) \
                 $$quote($$BASEDIR/src/form/formlistmodel.cpp) \
                 $$quote($$BASEDIR/src/main.cpp) \
                 $$quote($$BASEDIR/src/pgc/PageAddress.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcFile.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcPage.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcProperty.cpp) \
                 $$quote($$BASEDIR/src/pgc/pgcmessages.cpp) \
                 $$quote($$BASEDIR/src/pgcrouterapp.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/QtObjectFormatter.hpp) \
                 $$quote($$BASEDIR/src/appsettings.h) \
                 $$quote($$BASEDIR/src/config/config.hpp) \
                 $$quote($$BASEDIR/src/config/formconfig.hpp) \
                 $$quote($$BASEDIR/src/config/generalsettings.hpp) \
                 $$quote($$BASEDIR/src/config/helpconfig.hpp) \
                 $$quote($$BASEDIR/src/config/logsconfig.hpp) \
                 $$quote($$BASEDIR/src/config/penconfig.hpp) \
                 $$quote($$BASEDIR/src/config/routerconfig.hpp) \
                 $$quote($$BASEDIR/src/config/settingsconfig.hpp) \
                 $$quote($$BASEDIR/src/config/supportconfig.hpp) \
                 $$quote($$BASEDIR/src/config/trackersettings.hpp) \
                 $$quote($$BASEDIR/src/config/verificationsettings.hpp) \
                 $$quote($$BASEDIR/src/form/FormEditor.hpp) \
                 $$quote($$BASEDIR/src/form/FormViewer.hpp) \
                 $$quote($$BASEDIR/src/form/Forms.hpp) \
                 $$quote($$BASEDIR/src/form/formentry.hpp) \
                 $$quote($$BASEDIR/src/form/formlistmodel.hpp) \
                 $$quote($$BASEDIR/src/pgc/PageAddress.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcFile.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcPage.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcProperty.hpp) \
                 $$quote($$BASEDIR/src/pgc/pgcdef.hpp) \
                 $$quote($$BASEDIR/src/pgc/pgcmessages.hpp) \
                 $$quote($$BASEDIR/src/pgcrouterapp.h)
    }

    CONFIG(release, debug|release) {
        INCLUDEPATH +=  $$quote(${QNX_TARGET}/usr/include/bb/data) \
                 $$quote(${QNX_TARGET}/usr/include/bb/cascades/pickers) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtXml) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                 $$quote(${QNX_TARGET}/usr/include/bb) \
                 $$quote(${QNX_TARGET}/usr/include/bb/system) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtDeclarative)

        DEPENDPATH +=  $$quote(${QNX_TARGET}/usr/include/bb/data) \
                 $$quote(${QNX_TARGET}/usr/include/bb/cascades/pickers) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtXml) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                 $$quote(${QNX_TARGET}/usr/include/bb) \
                 $$quote(${QNX_TARGET}/usr/include/bb/system) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtDeclarative)

        LIBS += -lbbcascades \
                -lQtCore \
                -lQtXml \
                -lbbpim \
                -lQtDeclarative \
                -lbbcascadespickers \
                -lbb \
                -lbbdata \
                -lbbsystem

        SOURCES +=  $$quote($$BASEDIR/src/QtObjectFormatter.cpp) \
                 $$quote($$BASEDIR/src/appsettings.cpp) \
                 $$quote($$BASEDIR/src/config/config.cpp) \
                 $$quote($$BASEDIR/src/config/formconfig.cpp) \
                 $$quote($$BASEDIR/src/config/generalsettings.cpp) \
                 $$quote($$BASEDIR/src/config/helpconfig.cpp) \
                 $$quote($$BASEDIR/src/config/logsconfig.cpp) \
                 $$quote($$BASEDIR/src/config/penconfig.cpp) \
                 $$quote($$BASEDIR/src/config/routerconfig.cpp) \
                 $$quote($$BASEDIR/src/config/settingsconfig.cpp) \
                 $$quote($$BASEDIR/src/config/supportconfig.cpp) \
                 $$quote($$BASEDIR/src/config/trackersettings.cpp) \
                 $$quote($$BASEDIR/src/config/verificationsettings.cpp) \
                 $$quote($$BASEDIR/src/form/FormEditor.cpp) \
                 $$quote($$BASEDIR/src/form/FormViewer.cpp) \
                 $$quote($$BASEDIR/src/form/Forms.cpp) \
                 $$quote($$BASEDIR/src/form/formentry.cpp) \
                 $$quote($$BASEDIR/src/form/formlistmodel.cpp) \
                 $$quote($$BASEDIR/src/main.cpp) \
                 $$quote($$BASEDIR/src/pgc/PageAddress.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcFile.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcPage.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcProperty.cpp) \
                 $$quote($$BASEDIR/src/pgc/pgcmessages.cpp) \
                 $$quote($$BASEDIR/src/pgcrouterapp.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/QtObjectFormatter.hpp) \
                 $$quote($$BASEDIR/src/appsettings.h) \
                 $$quote($$BASEDIR/src/config/config.hpp) \
                 $$quote($$BASEDIR/src/config/formconfig.hpp) \
                 $$quote($$BASEDIR/src/config/generalsettings.hpp) \
                 $$quote($$BASEDIR/src/config/helpconfig.hpp) \
                 $$quote($$BASEDIR/src/config/logsconfig.hpp) \
                 $$quote($$BASEDIR/src/config/penconfig.hpp) \
                 $$quote($$BASEDIR/src/config/routerconfig.hpp) \
                 $$quote($$BASEDIR/src/config/settingsconfig.hpp) \
                 $$quote($$BASEDIR/src/config/supportconfig.hpp) \
                 $$quote($$BASEDIR/src/config/trackersettings.hpp) \
                 $$quote($$BASEDIR/src/config/verificationsettings.hpp) \
                 $$quote($$BASEDIR/src/form/FormEditor.hpp) \
                 $$quote($$BASEDIR/src/form/FormViewer.hpp) \
                 $$quote($$BASEDIR/src/form/Forms.hpp) \
                 $$quote($$BASEDIR/src/form/formentry.hpp) \
                 $$quote($$BASEDIR/src/form/formlistmodel.hpp) \
                 $$quote($$BASEDIR/src/pgc/PageAddress.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcFile.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcPage.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcProperty.hpp) \
                 $$quote($$BASEDIR/src/pgc/pgcdef.hpp) \
                 $$quote($$BASEDIR/src/pgc/pgcmessages.hpp) \
                 $$quote($$BASEDIR/src/pgcrouterapp.h)
    }
}

simulator {
    CONFIG(debug, debug|release) {
        INCLUDEPATH +=  $$quote(${QNX_TARGET}/usr/include/bb/data) \
                 $$quote(${QNX_TARGET}/usr/include/bb/cascades/pickers) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtXml) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                 $$quote(${QNX_TARGET}/usr/include/bb) \
                 $$quote(${QNX_TARGET}/usr/include/bb/system) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtDeclarative)

        DEPENDPATH +=  $$quote(${QNX_TARGET}/usr/include/bb/data) \
                 $$quote(${QNX_TARGET}/usr/include/bb/cascades/pickers) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtXml) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                 $$quote(${QNX_TARGET}/usr/include/bb) \
                 $$quote(${QNX_TARGET}/usr/include/bb/system) \
                 $$quote(${QNX_TARGET}/usr/include/qt4/QtDeclarative)

        LIBS += -lbbcascades \
                -lQtCore \
                -lQtXml \
                -lbbpim \
                -lQtDeclarative \
                -lbbcascadespickers \
                -lbb \
                -lbbdata \
                -lbbsystem

        SOURCES +=  $$quote($$BASEDIR/src/QtObjectFormatter.cpp) \
                 $$quote($$BASEDIR/src/appsettings.cpp) \
                 $$quote($$BASEDIR/src/config/config.cpp) \
                 $$quote($$BASEDIR/src/config/formconfig.cpp) \
                 $$quote($$BASEDIR/src/config/generalsettings.cpp) \
                 $$quote($$BASEDIR/src/config/helpconfig.cpp) \
                 $$quote($$BASEDIR/src/config/logsconfig.cpp) \
                 $$quote($$BASEDIR/src/config/penconfig.cpp) \
                 $$quote($$BASEDIR/src/config/routerconfig.cpp) \
                 $$quote($$BASEDIR/src/config/settingsconfig.cpp) \
                 $$quote($$BASEDIR/src/config/supportconfig.cpp) \
                 $$quote($$BASEDIR/src/config/trackersettings.cpp) \
                 $$quote($$BASEDIR/src/config/verificationsettings.cpp) \
                 $$quote($$BASEDIR/src/form/FormEditor.cpp) \
                 $$quote($$BASEDIR/src/form/FormViewer.cpp) \
                 $$quote($$BASEDIR/src/form/Forms.cpp) \
                 $$quote($$BASEDIR/src/form/formentry.cpp) \
                 $$quote($$BASEDIR/src/form/formlistmodel.cpp) \
                 $$quote($$BASEDIR/src/main.cpp) \
                 $$quote($$BASEDIR/src/pgc/PageAddress.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcFile.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcPage.cpp) \
                 $$quote($$BASEDIR/src/pgc/PgcProperty.cpp) \
                 $$quote($$BASEDIR/src/pgc/pgcmessages.cpp) \
                 $$quote($$BASEDIR/src/pgcrouterapp.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/QtObjectFormatter.hpp) \
                 $$quote($$BASEDIR/src/appsettings.h) \
                 $$quote($$BASEDIR/src/config/config.hpp) \
                 $$quote($$BASEDIR/src/config/formconfig.hpp) \
                 $$quote($$BASEDIR/src/config/generalsettings.hpp) \
                 $$quote($$BASEDIR/src/config/helpconfig.hpp) \
                 $$quote($$BASEDIR/src/config/logsconfig.hpp) \
                 $$quote($$BASEDIR/src/config/penconfig.hpp) \
                 $$quote($$BASEDIR/src/config/routerconfig.hpp) \
                 $$quote($$BASEDIR/src/config/settingsconfig.hpp) \
                 $$quote($$BASEDIR/src/config/supportconfig.hpp) \
                 $$quote($$BASEDIR/src/config/trackersettings.hpp) \
                 $$quote($$BASEDIR/src/config/verificationsettings.hpp) \
                 $$quote($$BASEDIR/src/form/FormEditor.hpp) \
                 $$quote($$BASEDIR/src/form/FormViewer.hpp) \
                 $$quote($$BASEDIR/src/form/Forms.hpp) \
                 $$quote($$BASEDIR/src/form/formentry.hpp) \
                 $$quote($$BASEDIR/src/form/formlistmodel.hpp) \
                 $$quote($$BASEDIR/src/pgc/PageAddress.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcFile.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcPage.hpp) \
                 $$quote($$BASEDIR/src/pgc/PgcProperty.hpp) \
                 $$quote($$BASEDIR/src/pgc/pgcdef.hpp) \
                 $$quote($$BASEDIR/src/pgc/pgcmessages.hpp) \
                 $$quote($$BASEDIR/src/pgcrouterapp.h)
    }
}

INCLUDEPATH +=  $$quote($$BASEDIR/src/pgc) \
         $$quote($$BASEDIR/src/form) \
         $$quote($$BASEDIR/src) \
         $$quote($$BASEDIR/src/config)

lupdate_inclusion {
    SOURCES +=  $$quote($$BASEDIR/../src/*.c) \
             $$quote($$BASEDIR/../src/*.c++) \
             $$quote($$BASEDIR/../src/*.cc) \
             $$quote($$BASEDIR/../src/*.cpp) \
             $$quote($$BASEDIR/../src/*.cxx) \
             $$quote($$BASEDIR/../assets/*.qml) \
             $$quote($$BASEDIR/../assets/*.js) \
             $$quote($$BASEDIR/../assets/*.qs)

    HEADERS +=  $$quote($$BASEDIR/../src/*.h) \
             $$quote($$BASEDIR/../src/*.h++) \
             $$quote($$BASEDIR/../src/*.hh) \
             $$quote($$BASEDIR/../src/*.hpp) \
             $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS =  $$quote($${TARGET}.ts)