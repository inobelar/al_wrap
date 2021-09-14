#include "al_simple_init.hpp"

#include <AL/alc.h> // OpenAL context functions
#include <AL/al.h>  // OpenAL functions

#include <cstdio>
#include <cstring> // for strlen()

static void list_audio_devices(const ALCchar *devices)
{
    const ALCchar *device = devices,
                  *next   = devices + 1;
    size_t len = 0;

    fprintf(stdout, "Devices list:\n");
    fprintf(stdout, "----------\n");
    while ( (device && (*device != '\0')) && (next && (*next != '\0')) ) {
        fprintf(stdout, "%s\n", device);
        len = strlen(device);
        device += (len + 1);
        next += (len + 2);
    }
    fprintf(stdout, "----------\n");
}

ALCdevice*  DEVICE  = nullptr;
ALCcontext* CONTEXT = nullptr;

bool al::simple_init(const char* defaultDeviceName)
{
    const ALboolean enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
    if (enumeration == AL_FALSE) {
        fprintf(stderr, "AL :: enumeration extension not available\n");
    }

    list_audio_devices( alcGetString(NULL, ALC_DEVICE_SPECIFIER) );


    char const* device_name = nullptr;

    if ((defaultDeviceName == nullptr) || (strlen(defaultDeviceName) == 0))
    {
        device_name = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    }
    else
    {
        device_name = defaultDeviceName;
    }

    DEVICE = alcOpenDevice(device_name);
    if (DEVICE == nullptr)
    {
        fprintf(stderr, "AL :: unable to open default device\n");
        return false;
    }

    fprintf(stdout, "AL :: Device: %s\n", alcGetString(DEVICE, ALC_DEVICE_SPECIFIER));

    alGetError();


    CONTEXT = alcCreateContext(DEVICE, NULL);
    if( alcMakeContextCurrent(CONTEXT) == AL_FALSE )
    {
        fprintf(stderr, "AL :: Failed to make default context\n");
        return false;
    }

    if( alGetError() != AL_NO_ERROR) {
        fprintf(stderr, "AL :: Failed to make default context\n");
    }

    return true;
}

void al::simple_deinit()
{
    DEVICE = alcGetContextsDevice(CONTEXT);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(CONTEXT);
    alcCloseDevice(DEVICE);

    DEVICE  = nullptr;
    CONTEXT = nullptr;
}

bool al::simple_isInited()
{
    return (DEVICE != nullptr) && (CONTEXT != nullptr);
}
