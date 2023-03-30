#include <al_wrap/al_error_checking.hpp>

#include <AL/al.h>

#include <cstdio>

const char* al::al_error_to_str(int errorId)
{
    switch (errorId) {
    case AL_NO_ERROR:          return "AL_NO_ERROR";
    case AL_INVALID_NAME:      return "AL_INVALID_NAME";
    case AL_INVALID_ENUM:      return "AL_INVALID_ENUM";
    case AL_INVALID_VALUE:     return "AL_INVALID_VALUE";
    case AL_INVALID_OPERATION: return "AL_INVALID_OPERATION";
    case AL_OUT_OF_MEMORY:     return "AL_OUT_OF_MEMORY";
    default:                   return "Unknown";
    }
}

const char* al::al_error_description_str(int errorId)
{
    switch (errorId) {
    case AL_NO_ERROR:          return "No error.";
    case AL_INVALID_NAME:      return "Invalid name paramater passed to AL call.";
    case AL_INVALID_ENUM:      return "Invalid enum parameter passed to AL call.";
    case AL_INVALID_VALUE:     return "Invalid value parameter passed to AL call.";
    case AL_INVALID_OPERATION: return "Illegal AL call.";
    case AL_OUT_OF_MEMORY:     return "Not enough memory.";
    default:                   return "Unknown";
    }
}

bool al::check_alerror(const char *file, int line, const char *str)
{
    const ALenum errorId = alGetError();
    if (errorId != AL_NO_ERROR)
    {
        fprintf(stderr, "<!> OpenAL error: %08x, (%s) at %s:%i - for \"%s\"!\n",
                errorId, al_error_to_str(errorId), file, line, str);

        return true;
    }

    return false;
}
