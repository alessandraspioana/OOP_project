//
// Created by aless on 4/2/2026.
//

#include "Asasin.h"

#include <iostream>

Asasin::Asasin(const std::string& nume_, int viata_, const Arma& arma_)
    : nume{nume_}, viata{viata_}, experienta{0}, arma{arma_} {}

Asasin::Asasin(const Asasin& other)
    : nume{other.nume + " (Copy)"}, viata{other.viata},
      experienta{other.experienta}, arma{other.arma}, distinctii{other.distinctii} {
    std::cout << "[CC] Copie creata pentru " << other.nume << "\n";
}

Asasin& Asasin::operator=(const Asasin& other) {
    if (this != &other) {
        nume = other.nume;
        viata = other.viata;
        experienta = other.experienta;
        arma = other.arma;
        distinctii = other.distinctii;
    }
    return *this;
}

Asasin::~Asasin() {
}

void Asasin::ataca(Asasin& tinta) {
    if (!esteInViata()) return;

    if (arma.trage()) {
        std::cout << nume << " il ataca pe " << tinta.getNume() << "!\n";
        tinta.primesteDamage(20 + (experienta / 10));
        experienta += 5;
    } else {
        std::cout << nume << " incearca sa traga dar esueaza!\n";
    }
}

void Asasin::primesteDamage(int dmg) {
    viata -= dmg;
    if (viata < 0) viata = 0;
    std::cout << nume << " a ramas cu " << viata << " HP.\n";
}

void Asasin::antrenament() {
    experienta += 20;
    arma.curataArma();
    std::cout << nume << " s-a antrenat. Experienta curenta: " << experienta << "\n";
}

std::ostream& operator<<(std::ostream& os, const Asasin& as) {
    os << "Asasin: " << as.nume << " [HP: " << as.viata << " | XP: " << as.experienta
       << "] dotat cu " << as.arma;
    return os;
}