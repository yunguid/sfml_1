#include "projectile.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800,600), "Projectile Motion Simulation");
    Projectile projectile(0.0f, 0.0f, 0.01f);

    float launchVelocity = 10.0f; 
    float launchAngle = 45.0f;
    sf::Vector2f launchVelocityVector(launchVelocity * cos(launchAngle * M_PI / 180.0f), -launchVelocity * sin(launchAngle * M_PI / 180.0f));
    projectile.applyForce(launchVelocityVector);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        projectile.update();

        window.clear(sf::Color::White);
        projectile.draw(window);
        window.display();
    }
    return 0; 
}