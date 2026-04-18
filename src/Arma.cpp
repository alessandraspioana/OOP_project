//
// Created by aless on 4/17/2026.
//

#include "Arma.h"
#include <iostream>

Arma::Arma(std::string model_, int cap_)
    : model{std::move(model_)},
      gloante{cap_},
      capacitateMagazie{cap_},
      uzura{0.0} {
}

bool Arma::trage() {
    if (gloante > 0 && !esteBlocata()) {
        gloante--;
        uzura += 0.02;
        return true;
    }
    return false;
}

void Arma::reincarca(int amunitie) {
    this->gloante += amunitie;
    if (this->gloante > this->capacitateMagazie) {
        this->gloante = this->capacitateMagazie;
    }
}

void Arma::curataArma() {
    this->uzura = 0.0;
}

bool Arma::esteBlocata() const { return uzura > 0.8; }
int Arma::getGloante() const { return gloante; }

std::ostream& operator<<(std::ostream& os, const Arma& a) {
    os << a.model << " [" << a.gloante << "/" << a.capacitateMagazie << "]";
    return os;
}