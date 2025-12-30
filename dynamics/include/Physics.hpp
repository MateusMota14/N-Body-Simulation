#pragma once
#include "Body.hpp"

namespace Physics {
    void handleInteraction(Body& a, Body& b);    
    
    void applyGravity(Body& a, Body& b, const Vector2& diff, double distSq);
    void handleCollision(Body& a, Body& b, const Vector2& diff, double overlap);
}