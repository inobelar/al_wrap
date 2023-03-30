#include <al_wrap/objects/al_Buffer.hpp>

#include <AL/al.h>
#include <al_wrap/al_error_checking.hpp>

al::Buffer::Buffer()
    : Object()
{
    ALWRAP_AL_CHECK( alGenBuffers(1, &_id) );
}

al::Buffer::~Buffer()
{
    ALWRAP_AL_CHECK( alDeleteBuffers(1, &_id) );
}

al::Buffer::self_t& al::Buffer::setDataRaw(format_t format, const void *data, int size, int freq)
{
    ALWRAP_AL_CHECK( alBufferData(_id, format, data, size, freq) );
    return *this;
}

bool al::Buffer::isOk() const
{
    ALboolean result;
    ALWRAP_AL_CHECK( result = alIsBuffer(_id) );
    return (result != AL_FALSE);
}
