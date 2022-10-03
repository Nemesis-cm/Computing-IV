//Thomas Freeman 
//Implementation of Universe.cpp
//This program builds the universe from any
//of the Nbody files, throwing exceptions for 
//incorrect inputs and gathering all data values 
//needed to display the image

#include "Universe.h"

//Set of constructors to create the universe
Universe::Universe() : numOfPlanets(0), radius(0) {}

//Basic exception for unavailable image file
Universe::Universe(std::string image_filename) {
    if(!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Universe image file not found,"
        " exiting");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    numOfPlanets = 0;
    radius = 0;
}

Universe::Universe(const Universe& copyUniverse) {

    numOfPlanets = copyUniverse.numOfPlanets;
        radius = copyUniverse.radius;
            image = copyUniverse.image;
                texture.loadFromImage(image);
                    sprite.setTexture(texture);
}

Universe::Universe(Universe&& moveUniverse) noexcept {

    numOfPlanets = moveUniverse.numOfPlanets;
        radius = moveUniverse.radius;
            image = moveUniverse.image;
                texture.loadFromImage(image);
                    sprite.setTexture(texture);
                        moveUniverse.numOfPlanets = 0;
                            moveUniverse.radius = 0;
}

Universe::~Universe() {
    numOfPlanets = 0;
    radius = 0;
}

// accessors and mutators
int Universe::getNumOfPlanets() const { return numOfPlanets; }
double Universe::getRadius() const { return radius; }
sf::Image Universe::getImage() const { return image; }

void Universe::setNumOfPlanets(int n) { numOfPlanets = n; }
void Universe::setRadius(double r) { radius = r; }

void Universe::setImage(std::string image_filename) { 
    if(!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Universe image file not found");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

// Moves the simulation forward one second, altering delta x and delta y every second
void Universe::step(double seconds) {
    double d, deltaX, deltaY;       // distance d formula
    double force, forceX, forceY;   // force calculation
    double accelX, accelY;          // acceleration calculation

    for (int i = 0; i < numOfPlanets; i++) {
        forceX = 0; forceY = 0;

        // Calculates the Net force on x and y
        for (int j = 0; j < numOfPlanets; j++) {
            if (i != j) {
                deltaX = planets[j]->getXPos() - planets[i]->getXPos();
                deltaY = planets[j]->getYPos() - planets[i]->getYPos();
                d = sqrt(deltaX * deltaX + deltaY * deltaY);

                //Calculates the pairwise force, a product of gravitational constants
                //and the mass of two planets divided by the square of the distance between them
                force = (GRAVITY_CONST * planets[i]->getMass() *
                planets[j]->getMass()) / (d * d);

                forceX += force * (deltaX / d);
                forceY += force * (deltaY / d);
            }
        }

        // Acceleration calculation
        accelX = forceX / planets[i]->getMass();
        accelY = forceY / planets[i]->getMass();

        // Velocity calculation
        planets[i]->setXVel(planets[i]->getXVel() + seconds * accelX);
        planets[i]->setYVel(planets[i]->getYVel() + seconds * accelY);  
    }

    // Positions are updated
    for (int i = 0; i < numOfPlanets; i++) {
        planets[i]->setXPos(planets[i]->getXPos() + seconds *
        planets[i]->getXVel());
        planets[i]->setYPos(planets[i]->getYPos() + seconds *
        planets[i]->getYVel());
        planets[i]->updatePosition(radius, image.getSize());
    }
}

// overloaded assingment operators
Universe& Universe::operator=(Universe& rvalue) {
    if (this == &rvalue) { return *this; }

    numOfPlanets = rvalue.numOfPlanets;
        radius = rvalue.radius;
            image = rvalue.image;
                texture.loadFromImage(image);
                    sprite.setTexture(texture);

    return *this;
}

Universe& Universe::operator=(Universe&& rvalue) noexcept {
    if (this == &rvalue) { return *this; }

    numOfPlanets = rvalue.numOfPlanets;
        radius = rvalue.radius;
            image = rvalue.image;
                texture.loadFromImage(image);
                    sprite.setTexture(texture);
                        rvalue.numOfPlanets = 0;
                            rvalue.radius = 0;

    return *this;
}

// overload stream operator for command input
std::istream& operator>>(std::istream& in, Universe& universe) {
    double dval;
    char buffer[30];    // Files should be less than 30 characters
    std::string image;

    in >> universe.numOfPlanets;
    if (universe.numOfPlanets < 0) { universe.numOfPlanets = 0; }
    else if (universe.numOfPlanets > 1000) {
        universe.numOfPlanets = 1000;
    }
    in >> universe.radius;

    // finds each planets data
    for (int i = 0; i < universe.numOfPlanets; i++) {
        std::unique_ptr<CelestialBody> planet(
            std::make_unique<CelestialBody>(CelestialBody()));

        //gets all necessary data from the txt file
        in >> dval;
        planet->setXPos(dval);
        in >> dval;
        planet->setYPos(dval);
        planet->updatePosition(universe.radius, universe.image.getSize());
        in >> dval;
        planet->setXVel(dval);
        in >> dval;
        planet->setYVel(dval);
        in >> dval;
        planet->setMass(dval);
        in >> buffer;
        image = buffer;
        
        try {
            planet->setImage(image);
        }
        catch (const std::invalid_argument& err) {
            std::cout << err.what() << std::endl;
            exit(-1);
        }
        universe.planets.push_back(std::move(planet));
    }

    return in;
}

// override virtual draw function
void Universe::draw(sf::RenderTarget& target, sf::RenderStates states)
const {
    target.draw(sprite, states);
}