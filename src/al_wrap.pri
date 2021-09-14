INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/al_wrap/al_simple_init.hpp \
    $$PWD/al_wrap/al_error_checking.hpp \
    \
    $$PWD/al_wrap/al_Listener.hpp \
    \
    $$PWD/al_wrap/objects/al_Object.hpp \
    $$PWD/al_wrap/objects/al_Buffer.hpp \
    $$PWD/al_wrap/objects/al_Source.hpp

SOURCES += \
    $$PWD/al_wrap/al_simple_init.cpp \
    $$PWD/al_wrap/al_error_checking.cpp \
    \
    $$PWD/al_wrap/al_Listener.cpp \
    \
    $$PWD/al_wrap/objects/al_Object.cpp \
    $$PWD/al_wrap/objects/al_Buffer.cpp \
    $$PWD/al_wrap/objects/al_Source.cpp

# Install libs:
#     $ sudo apt-get install libopenal-dev
#     $ sudo apt-get install libalut-dev

LIBS += -lopenal
#LIBS += -lalut  # <- not needed, since we dont use sound loading via it
