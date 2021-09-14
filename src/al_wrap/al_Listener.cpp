#include "al_Listener.hpp"

#include <AL/al.h>
#include <al_wrap/al_error_checking.hpp>

void al::Listener::setPosition(float x, float y, float z)
{
    ALWRAP_AL_CHECK( alListener3f(AL_POSITION, x, y, z) );
}

void al::Listener::setVelocity(float x, float y, float z)
{
    ALWRAP_AL_CHECK( alListener3f(AL_VELOCITY, x, y, z) );
}

void al::Listener::setOrientation(const float (&data)[6])
{
    ALWRAP_AL_CHECK( alListenerfv(AL_ORIENTATION, data) );
}

void al::Listener::setOrientation(
        float fwd_x, float fwd_y, float fwd_z,
        float  up_x, float  up_y, float  up_z)
{
    const float data[6] = {
        fwd_x, fwd_y, fwd_z,
        up_x, up_y, up_z
    };
    ALWRAP_AL_CHECK( alListenerfv(AL_ORIENTATION, data) );
}

void al::Listener::setGain(float value)
{
    ALWRAP_AL_CHECK( alListenerf(AL_GAIN, value) );
}

std::array<float, 3> al::Listener::getPosition()
{
    std::array<float, 3> data;
    ALWRAP_AL_CHECK( alGetListener3f(AL_POSITION, &data[0], &data[1], &data[2]) );
    return data;
}

std::array<float, 3> al::Listener::getVelocity()
{
    std::array<float, 3> data;
    ALWRAP_AL_CHECK( alGetListener3f(AL_VELOCITY, &data[0], &data[1], &data[2]) );
    return data;
}

std::array<float, 6> al::Listener::getOrientation()
{
    std::array<float, 6> data;
    ALWRAP_AL_CHECK( alGetListenerfv(AL_ORIENTATION, data.data()) );
    return data;
}

float al::Listener::getGain()
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetListenerf(AL_GAIN, &value) );
    return value;
}
