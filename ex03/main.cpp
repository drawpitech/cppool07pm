#include <iostream>

#include "Phaser.hpp"
#include "Sounds.hpp"

std::string Sounds::Rocket = "Booooooom";
std::string Sounds::Regular = "Piouuuu";
std::string Sounds::Plasma = "Piouuuu";

int main() {
    Phaser p(5, Phaser::ROCKET);
    p.fire();
    p.reload();
    std::cout << "Firing all ammunitions" << std::endl;
    while (p.getCurrentAmmos() > 0) 
        p.fire();
    return 0;
}
