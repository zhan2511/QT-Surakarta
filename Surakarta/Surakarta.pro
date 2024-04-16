QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chess_window.cpp \
    main.cpp \
    mainwindow.cpp \
    mygamethread.cpp \
    mypieces.cpp \
    mypushbutton.cpp \
    mywidget.cpp \
    surakarta/main1.cpp \
    surakarta/surakarta_agent/surakarta_agent_mine.cpp \
    surakarta/surakarta_agent/surakarta_agent_random.cpp \
    surakarta/surakarta_game.cpp \
    surakarta/surakarta_reason.cpp \
    surakarta/surakarta_rule_manager.cpp

HEADERS += \
    chess_window.h \
    mainwindow.h \
    mygamethread.h \
    mypieces.h \
    mypushbutton.h \
    mywidget.h \
    surakarta/global_random_generator.h \
    surakarta/surakarta_agent/surakarta_agent_base.h \
    surakarta/surakarta_agent/surakarta_agent_mine.h \
    surakarta/surakarta_agent/surakarta_agent_random.h \
    surakarta/surakarta_board.h \
    surakarta/surakarta_common.h \
    surakarta/surakarta_game.h \
    surakarta/surakarta_piece.h \
    surakarta/surakarta_reason.h \
    surakarta/surakarta_rule_manager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc

DISTFILES += \
    surakarta/CMakeLists.txt
