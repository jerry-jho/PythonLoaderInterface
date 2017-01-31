TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += . ../Interface
CONFIG+=console
mac {
  CONFIG -= app_bundle
}
HEADERS += ../Interface/PythonLoaderInterface.h
SOURCES += test.cpp
