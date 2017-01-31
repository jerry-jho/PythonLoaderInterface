TEMPLATE = lib
TARGET = PythonLoader
CONFIG += plugin
DEPENDPATH += .
INCLUDEPATH += . ../Interface $(PYTHON_INCLUDE)
LIBS += $(PYTHON_LIBRARY)

# Input
HEADERS += PythonLoader.h ../Interface/PythonLoaderInterface.h
SOURCES += PythonLoader.cpp
