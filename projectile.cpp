#include "PROJECTILE_H"
#include <SFML/Graphics.hpp>
#include <cmath>
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


Projectile::Projectile(double posX, double posY, double step)
    : position(posX, posY), previousPosition(posX, posY), timeStep(step) {}
void Projectile::applyForce(const sf::Vector2f& force){
    acceleration += force;
}

void Projectile::update(){
    sf::Vector2f velocity = position - previousPosition;
    previousPosition = position;
    position = position + velocity + acceleration * timeStep * timeStep;
    acceleration = sf::Vector2f(0.0f, 9.81f);
}
sf::Vector2f Projectile::getPosition(){
    return position;
}
void Projectile::draw(sf::RenderWindow& window){
    sf::CircleShape shape(5.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
    window.draw(shape);
}