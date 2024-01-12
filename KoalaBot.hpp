/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** Skat
*/

#pragma once

#include <iostream>
#include <string>
#include <utility>

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

class KoalaBot {
   public:
    KoalaBot(std::string serial = "Bob-01") : _serial(std::move(serial)) {}

    void setParts(Arms arms) { _arms = std::move(arms); }
    void setParts(Legs legs) { _legs = std::move(legs); }
    void setParts(Head head) { _head = std::move(head); }

    void swapParts(Arms &arms) { std::swap(_arms, arms); }
    void swapParts(Legs &legs) { std::swap(_legs, legs); }
    void swapParts(Head &head) { std::swap(_head, head); }

    void informations() {
        std::cout << "[KoalaBot] " << _serial << "\n";
        _arms.informations();
        _legs.informations();
        _head.informations();
    }
    bool status() {
        return _arms.isFunctional() && _legs.isFunctional() &&
               _head.isFunctional();
    }

   private:
    std::string _serial;
    Arms _arms;
    Legs _legs;
    Head _head;
};
