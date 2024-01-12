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

Phaser::Phaser(int maxAmmo, AmmoType type) : _maxAmmo(maxAmmo), _type(type) {
    fillClip();
}

void Phaser::fillClip() {
    while ((int)_magazine.size() < _maxAmmo)
        _magazine.push(_type);
}

void Phaser::fire() {
    if (_magazine.size() == Empty) {
        std::cout << "Clip empty, please reload\n";
        return;
    }
    if (_type != _magazine.front())
        return;

    _magazine.pop();
    std::map<AmmoType, std::string> sounds{
        {REGULAR, Sounds::Regular},
        {PLASMA, Sounds::Plasma},
        {ROCKET, Sounds::Rocket}};
    std::cout << sounds.at(_type) << "\n";
}

void Phaser::ejectClip() {
    while (_magazine.size() > Empty)
        _magazine.pop();
}

void Phaser::changeType(AmmoType newType) {
    static const std::map<AmmoType, std::string> names{
        {REGULAR, "regular"}, {PLASMA, "plasma"}, {ROCKET, "rocket"}};

    _type = newType;
    std::cout << "Switching ammo to type: " << names.at(_type) << "\n";
}

void Phaser::reload() {
    ejectClip();
    fillClip();
    std::cout << "Reloading...\n";
}

void Phaser::addAmmo(AmmoType type) {
    if ((int)_magazine.size() == _maxAmmo) {
        std::cout << "Clip full\n";
        return;
    }
    _magazine.push(type);
}
