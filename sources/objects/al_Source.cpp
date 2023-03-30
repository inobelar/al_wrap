#include <al_wrap/objects/al_Source.hpp>

#include <AL/al.h>
#include <al_wrap/al_error_checking.hpp>

#include <cassert>

al::Source::Source()
    : Object()
{
    ALWRAP_AL_CHECK( alGenSources(1, &_id) );
}

al::Source::~Source()
{
    ALWRAP_AL_CHECK( alDeleteSources(1, &_id) );
}

// =============================================================================

al::Source::self_t& al::Source::setPitch(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_PITCH, value) );
    return *this;
}

al::Source::self_t& al::Source::setGain(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_GAIN, value) );
    return *this;
}

al::Source::self_t& al::Source::setMinGain(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_MIN_GAIN, value) );
    return *this;
}

al::Source::self_t& al::Source::setMaxGain(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_MAX_GAIN, value) );
    return *this;
}

al::Source::self_t& al::Source::setConeOuterGain(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_CONE_OUTER_GAIN, value) );
    return *this;
}

al::Source::self_t& al::Source::setConeInnerAngle(int value)
{
    ALWRAP_AL_CHECK( alSourcei(_id, AL_CONE_INNER_ANGLE, value) );
    return *this;
}

al::Source::self_t& al::Source::setConeOuterAngle(int value)
{
    ALWRAP_AL_CHECK( alSourcei(_id, AL_CONE_OUTER_ANGLE, value) );
    return *this;
}

al::Source::self_t& al::Source::setMaxDistance(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_MAX_DISTANCE, value) );
    return *this;
}

al::Source::self_t& al::Source::setRolloffFactor(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_ROLLOFF_FACTOR, value) );
    return *this;
}

al::Source::self_t& al::Source::setReferenceDistance(float value)
{
    ALWRAP_AL_CHECK( alSourcef(_id, AL_REFERENCE_DISTANCE, value) );
    return *this;
}

al::Source::self_t& al::Source::setPosition(float x, float y, float z)
{
    ALWRAP_AL_CHECK( alSource3f(_id, AL_POSITION, x, y, z) );
    return *this;
}

al::Source::self_t &al::Source::setVelocity(float x, float y, float z)
{
    ALWRAP_AL_CHECK( alSource3f(_id, AL_VELOCITY, x, y, z) );
    return *this;
}

al::Source::self_t &al::Source::setDirection(float x, float y, float z)
{
    ALWRAP_AL_CHECK( alSource3f(_id, AL_DIRECTION, x, y, z) );
    return *this;
}

al::Source::self_t& al::Source::setRelative(bool status)
{
    ALWRAP_AL_CHECK( alSourcei(_id, AL_SOURCE_RELATIVE, (status ? AL_TRUE : AL_FALSE) ) );
    return *this;
}

al::Source::self_t& al::Source::setLooping(bool status)
{
    ALWRAP_AL_CHECK( alSourcei(_id, AL_LOOPING, (status ? AL_TRUE : AL_FALSE) ) );
    return *this;
}

al::Source::self_t& al::Source::setBuffer(id_t buffer_id)
{
    ALWRAP_AL_CHECK( alSourcei(_id, AL_BUFFER, buffer_id) );
    return *this;
}

al::Source::self_t& al::Source::setState(state_t state)
{
    assert((state == AL_INITIAL) ||
           (state == AL_PLAYING) ||
           (state == AL_PAUSED)  ||
           (state == AL_STOPPED));

    ALWRAP_AL_CHECK( alSourcei(_id, AL_SOURCE_STATE, state) );
    return *this;
}

// =============================================================================

float al::Source::getPitch() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_PITCH, &value) );
    return value;
}

float al::Source::getGain() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_GAIN, &value) );
    return value;
}

float al::Source::getMinGain() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_MIN_GAIN, &value) );
    return value;
}

float al::Source::getMaxGain() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_MAX_GAIN, &value) );
    return value;
}

float al::Source::getConeOuterGain() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_CONE_OUTER_GAIN, &value) );
    return value;
}

int al::Source::getConeInnerAngle() const
{
    ALint value;
    ALWRAP_AL_CHECK( alGetSourcei(_id, AL_CONE_INNER_ANGLE, &value) );
    return value;
}

int al::Source::getConeOuterAngle() const
{
    ALint value;
    ALWRAP_AL_CHECK( alGetSourcei(_id, AL_CONE_OUTER_ANGLE, &value) );
    return value;
}

float al::Source::getMaxDistance() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_MAX_DISTANCE, &value) );
    return value;
}

float al::Source::getRolloffFactor() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_ROLLOFF_FACTOR, &value) );
    return value;
}

float al::Source::getReferenceDistance() const
{
    ALfloat value;
    ALWRAP_AL_CHECK( alGetSourcef(_id, AL_REFERENCE_DISTANCE, &value) );
    return value;
}

std::array<float, 3> al::Source::getDirection() const
{
    std::array<float, 3> data;
    ALWRAP_AL_CHECK( alGetSource3f(_id, AL_DIRECTION, &data[0], &data[1], &data[2]) );
    return data;
}

std::array<float, 3> al::Source::getVelocity() const
{
    std::array<float, 3> data;
    ALWRAP_AL_CHECK( alGetSource3f(_id, AL_VELOCITY, &data[0], &data[1], &data[2]) );
    return data;
}

std::array<float, 3> al::Source::getPosition() const
{
    std::array<float, 3> data;
    ALWRAP_AL_CHECK( alGetSource3f(_id, AL_POSITION, &data[0], &data[1], &data[2]) );
    return data;
}

bool al::Source::isRelative() const
{
    ALint status;
    ALWRAP_AL_CHECK( alGetSourcei(_id, AL_SOURCE_RELATIVE, &status) );
    return (status != AL_FALSE);
}

bool al::Source::isLooping() const
{
    ALint status;
    ALWRAP_AL_CHECK( alGetSourcei(_id, AL_LOOPING, &status) );
    return (status != AL_FALSE);
}

bool al::Source::isStateInitial() const { return getState() == AL_INITIAL; }
bool al::Source::isStatePlaying() const { return getState() == AL_PLAYING; }
bool al::Source::isStatePaused()  const { return getState() == AL_PAUSED;  }
bool al::Source::isStateStopped() const { return getState() == AL_STOPPED; }

al::Object::id_t al::Source::getBuffer() const
{
    ALint buffer_id;
    ALWRAP_AL_CHECK( alGetSourcei(_id, AL_BUFFER, &buffer_id) );
    return buffer_id;
}

al::Source::state_t al::Source::getState() const
{
    ALint state;
    ALWRAP_AL_CHECK( alGetSourcei(_id, AL_SOURCE_STATE, &state) );
    return state;
}

// =============================================================================

al::Source::self_t& al::Source::play()
{
    ALWRAP_AL_CHECK( alSourcePlay(_id) );
    return *this;
}

al::Source::self_t& al::Source::pause()
{
    ALWRAP_AL_CHECK( alSourcePause(_id) );
    return *this;
}

al::Source::self_t& al::Source::stop()
{
    ALWRAP_AL_CHECK( alSourceStop(_id) );
    return *this;
}

al::Source::self_t& al::Source::rewind()
{
    ALWRAP_AL_CHECK( alSourceRewind(_id) );
    return *this;
}

// =============================================================================

bool al::Source::isOk() const
{
    ALboolean result;
    ALWRAP_AL_CHECK( result = alIsSource(_id) );
    return (result != AL_FALSE);
}
