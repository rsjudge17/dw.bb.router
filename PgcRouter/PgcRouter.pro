TEMPLATE = app
APP_NAME = PgcRouter

CONFIG += qt warn_on debug_and_release cascades

INCLUDEPATH += ../src ../src/config ../src/form ../src/pgc
SOURCES += ../src/*.cpp ../src/config/*.cpp ../src/form/*.cpp ../src/pgc/*.cpp
HEADERS += ../src/*.hpp ../src/*.h ../src/config/*.hpp ../src/form/*.hpp ../src/pgc/*.hpp 
HEADERS +=	../src/config/*.h ../src/form/*.h ../src/pgc/*.h
LIBS += -lbbcascades \
                -lQtCore \
                -lQtXml \
                -lbbpim \
                -lQtDeclarative \
                -lbbcascadespickers \
                -lbb \
                -lbbdata \
                -lbbsystem

lupdate_inclusion {
    SOURCES += ../assets/*.qml
}

device {
    CONFIG(release, debug|release) {
        DESTDIR = o.le-v7
        TEMPLATE = lib
        QMAKE_CXXFLAGS_RELEASE += -fvisibility=hidden -mthumb
    }
    CONFIG(debug, debug|release) {
        DESTDIR = o.le-v7-g
    }
}

simulator {
    CONFIG(release, debug|release) {
        DESTDIR = o
    }
    CONFIG(debug, debug|release) {
        DESTDIR = o-g
    }
}

OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR = $${DESTDIR}/.moc
RCC_DIR = $${DESTDIR}/.rcc
UI_DIR = $${DESTDIR}/.ui

suredelete.target = sureclean
suredelete.commands = $(DEL_FILE) $${MOC_DIR}/*; $(DEL_FILE) $${RCC_DIR}/*; $(DEL_FILE) $${UI_DIR}/*
suredelete.depends = distclean

QMAKE_EXTRA_TARGETS += suredelete

TRANSLATIONS = \
    $${TARGET}_en_GB.ts \
    $${TARGET}_fr.ts \
    $${TARGET}_it.ts \
    $${TARGET}_de.ts \
    $${TARGET}_es.ts \
    $${TARGET}.ts


