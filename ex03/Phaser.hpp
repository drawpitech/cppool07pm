/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** Phaser
*/

#pragma once

#include <queue>

class Phaser {
   public:
    enum AmmoType { REGULAR, PLASMA, ROCKET };

    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);

    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos() const { return (int)_magazine.size(); }

   private:
    void fillClip();
    static const int Empty = 0;
    const int _maxAmmo;
    std::queue<AmmoType> _magazine;
    AmmoType _type;
};
