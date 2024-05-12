#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Projectile {
private:
    sf::Vector2f position;
    sf::Vector2f previousPosition;
    sf::Vector2f acceleration;
    double timeStep;

public:
    Projectile(double posX, double posY, double step);
    void applyForce(const sf::Vector2f& force);
    void update();
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow& window);
};

#endif