/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** KoalaBot
*/

#pragma once

#include <iostream>
#include <string>
#include <utility>

#include "Parts.hpp"

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
