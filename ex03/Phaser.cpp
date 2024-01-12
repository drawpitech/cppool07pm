/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** Phaser
*/

#include "Phaser.hpp"

#include <iostream>
#include <map>

#include "Sounds.hpp"

Phaser::Phaser(int maxAmmo, AmmoType type)
    : _maxAmmo(maxAmmo), _magazine(maxAmmo), _type(type) {}

void Phaser::fire() {
    if (_magazine == Empty) {
        std::cout << "Clip empty, please reload\n";
        return;
    }

    _magazine -= 1;
    std::map<AmmoType, std::string> sounds{{REGULAR, Sounds::Regular},
                                           {PLASMA, Sounds::Plasma},
                                           {ROCKET, Sounds::Rocket}};
    std::cout << sounds.at(_type) << "\n";
}

void Phaser::ejectClip() { _magazine = Empty; }

void Phaser::changeType(AmmoType newType) {
    static const std::map<AmmoType, std::string> names{
        {REGULAR, "regular"}, {PLASMA, "plasma"}, {ROCKET, "rocket"}};

    _type = newType;
    std::cout << "Switching ammo to type: " << names.at(_type) << "\n";
}

void Phaser::reload() {
    _magazine = _maxAmmo;
    std::cout << "Reloading...\n";
}

void Phaser::addAmmo(AmmoType type) {
    if (_magazine == _maxAmmo) {
        std::cout << "Clip full\n";
        return;
    }
    if (_type == type) _magazine += 1;
}
