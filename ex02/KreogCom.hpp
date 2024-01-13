/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** KreogCom
*/

#pragma once

class KreogCom {
   public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();

    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom* getCom() const;
    void ping() const;
    void locateSquad() const;

   private:
    const int _m_serial;
    int _x;
    int _y;
    KreogCom *_next = nullptr;
    KreogCom *_prev = nullptr;
};
