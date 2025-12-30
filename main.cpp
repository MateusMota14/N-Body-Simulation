#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include "dynamics/include/Body.hpp"
#include "dynamics/include/Physics.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({2000, 1000}), "SFML 3");
    window.setFramerateLimit(60);
    
    std::vector<Body> corpos;
    corpos.emplace_back(100.0, Vector2{900, 500}, Vector2{0, 100}, 10.f, sf::Color::Red);
    corpos.emplace_back(100.0, Vector2{1100, 500}, Vector2{0, -100}, 10.f, sf::Color::Blue);
    corpos.emplace_back(100.0, Vector2{1000, 700}, Vector2{0, 0}, 10.f, sf::Color::White);

    int n = corpos.size();
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        for(int i =0; i<n; i++){
            for(int j =i +1; j<n; j++){
                Physics::handleInteraction(corpos[i], corpos[j]);
            }
        }
        
        window.clear(sf::Color::Black);

        for (auto& corpo : corpos) {
            double dt = 0.016f ;
            corpo.update(dt);        
            window.draw(corpo.shape);  
        }

        window.display();
    }

    return 0;
}