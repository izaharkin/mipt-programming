TEMPLATE = app
TARGET = prog

CONFIG -= qt
CONFIG += console


QMAKE_CXXFLAGS += -pedantic -std=c++03


DESTDIR = bin
OBJECTS_DIR = obj


HEADERS = \
          std_lib_facilities.h

SOURCES = \
          01_seminar/hello_world.cpp
#          02_seminar/input.cpp
#          02_seminar/repeated_words.cpp
