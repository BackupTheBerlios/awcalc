SOURCES += awcalc_qt.cpp \
           main.cpp
HEADERS += awcalc_qt.h
TEMPLATE = app
CONFIG += release \
          warn_on \
	  thread \
          qt
TARGET = ../bin/awcalc_qt
