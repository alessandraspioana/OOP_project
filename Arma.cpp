//
// Created by aless on 4/2/2026.
//

#include "Arma.h"

Arma::Arma(const std::string& model_, int cap_)
    : model{model_}, gloante{cap_}, capacitateMagazie{cap_}, uzura{0.0} {}

bool Arma::trage() {
    if (gloante > 0 && !esteBlocata()) {
        gloante--;
        uzura += 0.02;
        return true;
    }
    if (esteBlocata()) std::cout << "![CLICK] Arma " << model << " s-a blocat!\n";
    return false;
}

void Arma::reincarca(int amunitie) {
    gloante += amunitie;
    if (gloante > capacitateMagazie) gloante = capacitateMagazie;
    std::cout << "[RELOAD] " << model << " acum are " << gloante << " gloante.\n";
}

void Arma::curataArma() {
    uzura = 0.0;
    std::cout << "[MAINTENANCE] Arma " << model << " este ca noua.\n";
}

std::ostream& operator<<(std::ostream& os, const Arma& a) {
    os << "[" << a.model << " | Gloante: " << a.gloante << "/" << a.capacitateMagazie
       << " | Uzura: " << (int)(a.uzura * 100) << "%]";
    return os;
}