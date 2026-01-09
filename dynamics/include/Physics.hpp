#pragma once
#include "Body.hpp"

namespace Physics {
    inline double G = 40000;     
    inline double e = 0.7;
    void handleInteraction(Body& a, Body& b);    
    
    void applyGravity(Body& a, Body& b, const Vector2& diff, double distSq);
    void handleCollision(Body& a, Body& b, const Vector2& diff, double overlap);
}