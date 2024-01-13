/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** Parts
*/

#pragma once

#include <iostream>

class Part {
   public:
    Part(std::string serial, bool functional, std::string type)
        : _type(std::move(type)),
          _serial(std::move(serial)),
          _functional(functional) {}

    bool isFunctional() const { return _functional; }
    std::string serial() const { return _serial; }
    void informations() {
        std::cout << "\t[Parts] " << _type << " " << _serial
                  << " status : " << (_functional ? "OK" : "KO") << "\n";
    }

   private:
    std::string _type;
    std::string _serial;
    bool _functional;
};

class Arms : public Part {
   public:
    Arms(std::string serial = "A-01", bool functional = true)
        : Part(std::move(serial), functional, "Arms") {}
};

class Legs : public Part {
   public:
    Legs(std::string serial = "L-01", bool functional = true)
        : Part(std::move(serial), functional, "Legs") {}
};

class Head : public Part {
   public:
    Head(std::string serial = "H-01", bool functional = true)
        : Part(std::move(serial), functional, "Head") {}
};

