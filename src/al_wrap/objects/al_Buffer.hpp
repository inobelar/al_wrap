#pragma once

#include "al_Object.hpp"

#include <array>
#include <vector>

namespace al {

class Buffer : public Object
{
public:

    using self_t = Buffer;

    using format_t = int; // Aka ALenum

    // -------------------------------------------------------------------------

    Buffer();
    virtual ~Buffer();

    // -------------------------------------------------------------------------

    // Moveable
    Buffer(Buffer &&) = default;
    Buffer& operator = (Buffer &&) = default;

    // Non-copyable
    Buffer(const Buffer &) = delete;
    Buffer& operator = (const Buffer &) = delete;

    // -------------------------------------------------------------------------

    self_t& setDataRaw(format_t format, const void* data, int /*ALsizei*/ size, int /*ALsizei*/ freq);

    template <typename T>
    inline self_t& setData(format_t format, T* data, int /*ALsizei*/ size, int /*ALsizei*/ freq)
    {
        return setDataRaw(format, (void*)data, (size * sizeof(T)), freq);
    }

    template <typename T, std::size_t N>
    inline self_t& setData(format_t format, const std::array<T, N>& data, int /*ALsizei*/ freq)
    {
        return setData<T>(format, data.data(), data.size(), freq);
    }

    template <typename T>
    inline self_t& setData(format_t format, const std::vector<T>& data, int /*ALsizei*/ freq)
    {
        return setData<T>(format, data.data(), data.size(), freq);
    }

    // -------------------------------------------------------------------------

    bool isOk() const;
};

} // namespace al
