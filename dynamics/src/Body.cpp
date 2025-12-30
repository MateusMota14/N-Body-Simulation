#include "../include/Vector2.hpp"
#include "../include/Body.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

Body::Body(double m, Vector2 pos, Vector2 vel, double radius, sf::Color color) 
    : mass(m), position(pos), velocity(vel) , radius(radius)
{
    acceleration = {0, 0};
    lastAcceleration = {0, 0};
    
    shape.setRadius(static_cast<float> (radius));
    shape.setFillColor(color);

    shape.setOrigin({static_cast<float> (radius),static_cast<float> (radius)}); 
    shape.setPosition({ static_cast<float>(position.x), static_cast<float>(position.y) });
}

void Body::update(double dt) {
    this->position = this->position + (this->velocity * dt) + this->acceleration*(0.5*dt*dt);

    this->velocity = this->velocity + (this->acceleration + this->lastAcceleration)*(0.5*dt);
    this->lastAcceleration = acceleration;

    shape.setPosition({ static_cast<float>(position.x), static_cast<float>(position.y) });
    this->acceleration = {0, 0};
}