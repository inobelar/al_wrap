#pragma once

#include <al_wrap/objects/al_Object.hpp>

#include <array>

namespace al {

class Source : public Object
{
public:

    using self_t = Source;

    using state_t = int; // ALint

    // -------------------------------------------------------------------------

    Source();
    virtual ~Source();

    // -------------------------------------------------------------------------

    // Moveable
    Source(Source &&) = default;
    Source& operator = (Source &&) = default;

    // Non-copyable
    Source(const Source &) = delete;
    Source& operator = (const Source &) = delete;

    // -------------------------------------------------------------------------
    //
    // Setters
    //

    self_t& setPitch(float value);

    // -----------------------------------------------------
    // Gain

    self_t& setGain(float value);
    self_t& setMinGain(float value);
    self_t& setMaxGain(float value);

    self_t& setConeOuterGain(float value);
    self_t& setConeInnerAngle(int value);
    self_t& setConeOuterAngle(int value);

    // -----------------------------------------------------

    self_t& setMaxDistance(float value);
    self_t& setRolloffFactor(float value);
    self_t& setReferenceDistance(float value);

    // -----------------------------------------------------

    self_t& setPosition(float x, float y, float z);
    self_t& setVelocity(float x, float y, float z);
    self_t& setDirection(float x, float y, float z);

    // -----------------------------------------------------

    self_t& setRelative(bool status);

    self_t& setLooping(bool status);

    // -----------------------------------------------------

    self_t& setBuffer(id_t buffer_id);

    self_t& setState(state_t state);

    // -------------------------------------------------------------------------
    //
    // Getters
    //

    float getPitch() const;

    // -----------------------------------------------------
    // Gain

    float getGain() const;
    float getMinGain() const;
    float getMaxGain() const;

    float getConeOuterGain() const;
    int   getConeInnerAngle() const;
    int   getConeOuterAngle() const;

    // -----------------------------------------------------

    float getMaxDistance() const;
    float getRolloffFactor() const;
    float getReferenceDistance() const;

    // -----------------------------------------------------

    std::array<float, 3> getPosition() const;
    std::array<float, 3> getVelocity() const;
    std::array<float, 3> getDirection() const;

    // -----------------------------------------------------

    bool isRelative() const;

    bool isLooping() const;

    // -----------------------------------------------------

    id_t getBuffer() const;

    state_t getState() const;

    // Convenience
    bool isStateInitial() const;
    bool isStatePlaying() const;
    bool isStatePaused()  const;
    bool isStateStopped() const;

    // =========================================================================
    //
    // Modifiers
    //

    self_t& play();
    self_t& pause();
    self_t& stop();
    self_t& rewind();

    // -------------------------------------------------------------------------

    bool isOk() const;
};

} // namespace al
