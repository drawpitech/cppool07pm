/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

#include <iostream>

KreogCom::KreogCom(int x, int y, int serial) : _m_serial(serial), _x(x), _y(y) {
    std::cout << "KreogCom " << _m_serial << " initialized\n";
}

KreogCom::~KreogCom() {
    std::cout << "KreogCom " << _m_serial << " shutting down\n";
    delete _next;
}

void KreogCom::addCom(int x, int y, int serial) {
    if (_next != nullptr)
        _next->addCom(x, y, serial);
    else
        _next = new KreogCom(x, y, serial);
}

void KreogCom::removeCom() {
    if (_next == nullptr)
        return;
    if (_next->_next != nullptr) {
        _next->removeCom();
        return;
    }
    delete _next;
    _next = nullptr;
}

KreogCom *KreogCom::getCom() const { return _next; }

void KreogCom::ping() const {
    std::cout << "KreogCom " << _m_serial << " currently at " << _x << " " << _y
              << "\n";
}

void KreogCom::locateSquad() const {
    if (_next != nullptr)
        _next->locateSquad();
    this->ping();
}
