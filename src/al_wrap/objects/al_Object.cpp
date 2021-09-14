#include "al_Object.hpp"

al::Object::Object()
    : _id(0)
{ }

al::Object::~Object()
{ }

al::Object::id_t al::Object::getId() const {
    return _id;
}
