INCLUDEPATH += $$PWD/include/

HEADERS += \
    $$PWD/include/al_wrap/al_simple_init.hpp \
    $$PWD/include/al_wrap/al_error_checking.hpp \
    \
    $$PWD/include/al_wrap/al_Listener.hpp \
    \
    $$PWD/include/al_wrap/objects/al_Object.hpp \
    $$PWD/include/al_wrap/objects/al_Buffer.hpp \
    $$PWD/include/al_wrap/objects/al_Source.hpp

SOURCES += \
    $$PWD/sources/al_simple_init.cpp \
    $$PWD/sources/al_error_checking.cpp \
    \
    $$PWD/sources/al_Listener.cpp \
    \
    $$PWD/sources/objects/al_Object.cpp \
    $$PWD/sources/objects/al_Buffer.cpp \
    $$PWD/sources/objects/al_Source.cpp

# Install libs:
#     $ sudo apt-get install libopenal-dev
#     $ sudo apt-get install libalut-dev

LIBS += -lopenal
#LIBS += -lalut  # <- not needed, since we dont use sound loading via it
