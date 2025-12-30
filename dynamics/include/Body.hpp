#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.hpp"

struct Body {
    double mass; 
    double radius;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    Vector2 lastAcceleration;
    
    sf::CircleShape shape; 
    
    Body(double m, Vector2 pos, Vector2 vel, double rad, sf::Color color);

    void update(double dt);
    
};