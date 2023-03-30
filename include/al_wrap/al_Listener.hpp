#pragma once

#include <array>

namespace al {

struct Listener
{
    // -------------------------------------------------------------------------
    //
    // Setters
    //

    static void setPosition(float x, float y, float z);

    static void setVelocity(float x, float y, float z);

    static void setOrientation(const float (&data)[6]);

    static void setOrientation(float fwd_x, float fwd_y, float fwd_z,
                               float  up_x, float  up_y, float  up_z);

    static void setGain(float value);

    // -------------------------------------------------------------------------
    //
    // Getters
    //

    static std::array<float, 3> getPosition();

    static std::array<float, 3> getVelocity();

    static std::array<float, 6> getOrientation();

    static float getGain();
};

} // namespace al
