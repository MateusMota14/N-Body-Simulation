#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <optional>

#include <imgui-SFML.h>
#include <imgui.h>
#include <cstdint>

#include "dynamics/include/Body.hpp"
#include "dynamics/include/Physics.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "N-Body Engine - Painel de Controle");
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window)) return -1;

    std::vector<Body> corpos;
    sf::Clock deltaClock;

    double nextMass = 100.0;
    float nextPos[2] = { 960.f, 540.f };
    float nextVel[2] = { 0.f, 0.f };
    float nextRadius = 10.f;
    float nextColor[3] = { 1.f, 1.f, 1.f }; 
    float timeScale = 0.016f; 

    while (window.isOpen()) {
        
        while (const std::optional event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("System Configurator");
        
        ImGui::Text("Global Physics:");
        float tempG = static_cast<float>(Physics::G);
        if (ImGui::SliderFloat("Gravitacional Constant (G)", &tempG, 0.0f, 80000.f)) {
            Physics::G = static_cast<double>(tempG);
        }

        float tempE = static_cast<float>(Physics::e);
        if (ImGui::SliderFloat("Coefficient of Restitution (e)", &tempE, 0.0f, 1.0f)) {
            Physics::e = static_cast<double>(tempE);
        }

        float tempMass = static_cast<float>(nextMass);
        if (ImGui::SliderFloat("Mass", &tempMass, 0.1f, 1000.f)) nextMass = tempMass;

        ImGui::SliderFloat("Position X", &nextPos[0], 0.f, 1920.f);
        ImGui::SliderFloat("Position Y", &nextPos[1], 0.f, 1080.f);

        ImGui::SliderFloat("Velocity VX", &nextVel[0], -500.f, 500.f);
        ImGui::SliderFloat("Velocity VY", &nextVel[1], -500.f, 500.f);

        ImGui::SliderFloat("Radius", &nextRadius, 1.f, 100.f);
        ImGui::ColorEdit3("Color", nextColor);


        ImGui::Separator();

        if (ImGui::Button("Add Body", ImVec2(0, 30))) {
            sf::Color color(
                static_cast<std::uint8_t>(nextColor[0] * 255),
                static_cast<std::uint8_t>(nextColor[1] * 255),
                static_cast<std::uint8_t>(nextColor[2] * 255)
            );
            
            corpos.emplace_back(
                nextMass, 
                Vector2{nextPos[0], nextPos[1]}, 
                Vector2{nextVel[0], nextVel[1]}, 
                nextRadius, 
                color
            );
        }

        if (ImGui::Button("Clear All")) {
            corpos.clear();
        }

        ImGui::Separator();
        ImGui::SliderFloat("Frequency of Updates", &timeScale, 0.0f, 0.1f);

        ImGui::End();

        int n = corpos.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                Physics::handleInteraction(corpos[i], corpos[j]);
            }
        }

     
        window.clear(sf::Color::Black);

        for (auto& corpo : corpos) {
            corpo.update(timeScale);        
            window.draw(corpo.shape);  
        }

        ImGui::SFML::Render(window); 
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}