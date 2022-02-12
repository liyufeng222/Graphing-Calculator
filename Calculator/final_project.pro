TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
LIBS += -L"C:\SFML-2.5.1\lib" #change this
LIBS += -L"C:\SFML-2.5.1\bin" #change this



CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "C:\SFML-2.5.1\include" #change this
DEPENDPATH  += "C:\SFML-2.5.1\include" #change this

SOURCES += \
        ../../!include/one_d_pointer/one_d_pointer_tool.cpp \
        ../../!include/shunting_yard_rpn/rpn.cpp \
        ../../!include/shunting_yard_rpn/shunting_yard.cpp \
        ../../!include/shunting_yard_rpn/tokenizer.cpp \
        ../../!include/token/function.cpp \
        ../../!include/token/lparen.cpp \
        ../../!include/token/number.cpp \
        ../../!include/token/operator.cpp \
        ../../!include/token/rparen.cpp \
        ../../!include/token/token.cpp \
        ../../!include/token/variable.cpp \
        animate.cpp \
        graph.cpp \
        graph_info.cpp \
        main.cpp \
        plot.cpp \
        sidebar.cpp \
        system.cpp \
        translate_coor.cpp

HEADERS += \
    ../../!include/add_entry/add_entry.h \
    ../../!include/linked_list/linked_list.h \
    ../../!include/node/node.h \
    ../../!include/one_d_pointer/one_d_pointer_tool.h \
    ../../!include/queue/queue.h \
    ../../!include/shunting_yard_rpn/rpn.h \
    ../../!include/shunting_yard_rpn/shunting_yard.h \
    ../../!include/shunting_yard_rpn/tokenizer.h \
    ../../!include/stack/stack.h \
    ../../!include/token/function.h \
    ../../!include/token/lparen.h \
    ../../!include/token/number.h \
    ../../!include/token/operator.h \
    ../../!include/token/rparen.h \
    ../../!include/token/token.h \
    ../../!include/token/variable.h \
    ../../!include/vector/vector.h \
    animate.h \
    constants.h \
    graph.h \
    graph_info.h \
    plot.h \
    sidebar.h \
    system.h \
    translate_coor.h \
    z_output.h \
    z_work_report.h

SUBDIRS += \
    ../../11_P1_Vector_Class/Vector/Vector.pro
