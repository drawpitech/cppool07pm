/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** Phaser
*/

#pragma once

class Phaser {
   public:
    enum AmmoType { REGULAR, PLASMA, ROCKET };

    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);

    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos() const { return _magazine; }

   private:
    static const int Empty = 0;
    const int _maxAmmo;
    int _magazine = Empty;
    AmmoType _type;
};
