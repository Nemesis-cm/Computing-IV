#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <iostream>
#include <exception>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {
public:
    // Necessary constructors
    CelestialBody();
    CelestialBody(float x_position, float y_position, float x_velocity, 
    float y_velocity, float init_mass, std::string image_filename);

    //accessors and mutators
    float getXPos() const;
    float getYPos() const;
    float getXVel() const;
    float getYVel() const;
    float getMass() const;

    sf::Image getImage() const;
    void setXPos(float xPos);
    void setYPos(float yPos);
    void setXVel(float xVel);
    void setYVel(float yVel);
    void setMass(float mass);
    void setImage(std::string image_filename);

    // updates the position of a given planet
    void updatePosition();

private:
    //override virtual draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    float xPos, yPos;       //positions of x and y
    float xVel, yVel;       //Velocity of x and y
    float mass;             //given mass
    sf::Image image;        //image data
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif