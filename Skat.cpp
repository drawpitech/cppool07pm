/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** Skat
*/

#include "Skat.hpp"

void Skat::shareStimPaks(int number, int &stock) {
    if (number > _stimPaks) {
        std::cout << "Don't be greedy\n";
        return;
    }
    std::cout << "Keep the change.\n";
    stock += number;
    _stimPaks -= number;
}

void Skat::addStimPaks(unsigned int number) {
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?\n";
        return;
    }
    _stimPaks += (int)number;
}

void Skat::useStimPaks() {
    if (_stimPaks == 0) {
        std::cout << "Mediiiiiic\n";
        return;
    }
    std::cout << "Time to kick some ass and chew bubble gum.\n";
    _stimPaks -= 1;
}
