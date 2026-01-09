#include "../include/Vector2.hpp"
#include "../include/Body.hpp"
#include "../include/Physics.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

void Physics:: handleInteraction(Body& a, Body& b ){
    Vector2 diff = b.position - a.position;
    double distSq = diff.magnitudeSq();
    double dist = sqrt(distSq);
    diff = diff/dist;
    
    double overlap = a.radius + b.radius - dist;

    if(overlap >=0) handleCollision(a, b, diff, overlap);
    else applyGravity(a, b, diff, distSq);
}

void Physics:: applyGravity(Body& a, Body& b, const Vector2& diff, double sqr) {    
    double force = (G * a.mass * b.mass)/sqr;
        
    a.acceleration = a.acceleration + diff*(force/a.mass);    
    b.acceleration = b.acceleration - diff*(force/b.mass);
}

void Physics:: handleCollision(Body& a, Body& b, const Vector2& diff, double overlap) {
    Vector2 ort = {diff.y, - diff.x};
    double m = diff.x, n = diff.y;
    
    double inverseMass = 1.0/a.mass + 1.0/b.mass;
    double moveMag = overlap / inverseMass;

    a.position = a.position - diff * (moveMag / a.mass);
    b.position = b.position + diff * (moveMag / b.mass);
    
    double v1 = a.velocity.x*m + n*a.velocity.y;
    double v2 = b.velocity.x*m + n*b.velocity.y;

    double mSum = a.mass +b.mass;
    double u1, u2;
    u1 = (a.mass*v1 + b.mass*v2 + e*b.mass*(v2 - v1)) / mSum;
    u2 = (a.mass*v1 + b.mass*v2 + e*a.mass*(v1 - v2)) / mSum;
    
    a.velocity = diff*u1 + ort*(a.velocity.x*n - a.velocity.y*m);
    b.velocity = diff*u2 + ort*(b.velocity.x*n - b.velocity.y*m);
}

