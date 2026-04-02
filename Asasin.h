//
// Created by aless on 4/2/2026.
//

#ifndef OOP_ASASIN_H
#define OOP_ASASIN_H


#pragma once
#include <string>
#include <vector>
#include "Arma.h"

class Asasin {
private:
    std::string nume;
    int viata;
    int experienta;
    Arma arma;
    std::vector<std::string> distinctii;

public:
    explicit Asasin(const std::string& nume_, int viata_, const Arma& arma_);

    Asasin(const Asasin& other);
    Asasin& operator=(const Asasin& other);
    ~Asasin();

    void ataca(Asasin& tinta);
    void primesteDamage(int dmg);
    void antrenament();

    bool esteInViata() const { return viata > 0; }
    const std::string& getNume() const { return nume; }

    friend std::ostream& operator<<(std::ostream& os, const Asasin& as);
};

#endif //OOP_ASASIN_H