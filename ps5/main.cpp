// copyright 2021 Thomas Freeman

#include "EDistance.hpp"
#include <SFML/System.hpp>

// command line syntax
int main(int argc, char* argv[]) {
    if (argc != 1) {
        std::cerr << "usage: ./EDistance < ecoli8000.txt" << std::endl;
        exit(-1);
    }
    EDistance ed;
    std::cin >> ed;
    sf::Clock clock;
    sf::Time t;

    // Print statements for edit distance and execution time

    std::cout << "Edit distance = " << ed.optDistance() << std::endl;
    std::cout << ed.alignment() << std::endl;

    t = clock.getElapsedTime();
    std::cout << "Execution time = " << t.asSeconds() << " seconds" <<
    std::endl;

    return 0;
}
