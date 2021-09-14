#pragma once

namespace al {

class Object
{
public:

    using id_t = unsigned int; // Aka ALuint

protected:

    id_t _id;

public:

    Object();
    virtual ~Object();

    // -------------------------------------------------------------------------

    // Moveable
    Object(Object &&) = default;
    Object& operator = (Object &&) = default;

    // Non-copyable
    Object(const Object &) = delete;
    Object& operator = (const Object &) = delete;

    // -------------------------------------------------------------------------

    id_t getId() const;
};

} // namespace al
