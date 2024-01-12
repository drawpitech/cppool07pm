/*
** EPITECH PROJECT, 2024
** ppool07pm
** File description:
** Skat
*/

#ifndef PPOOL07PM_SKAT_HPP
#define PPOOL07PM_SKAT_HPP

#include <iostream>
#include <string>

class Skat {
   public:
    Skat(const std::string &name, int stimPaks)
        : _name(name), _stimPaks(stimPaks) {}
    ~Skat() = default;

    int &stimPaks() { return _stimPaks; }
    const std::string &name() const { return _name; }
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status() const {
        std::cout << "Soldier " << _name << " reporting " << _stimPaks
                  << " stimpaks remaining sir!\n";
    }

   private:
    const std::string &_name;
    int _stimPaks;
};

#endif  // PPOOL07PM_SKAT_HPP
