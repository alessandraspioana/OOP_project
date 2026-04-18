//
// Created by aless on 4/18/2026.
//

#include "Misiune.h"
#include <iostream>

[[nodiscard]] int Misiune::getRecompensa() const { return recompensaGold; }
[[nodiscard]] bool Misiune::esteFinalizata() const { return finalizata; }
[[nodiscard]] const std::string& Misiune::getDescriere() const { return descriere; }

Misiune::Misiune(std::string desc, int dif, int bani)
: descriere(std::move(desc)),
  dificultate(dif),
  recompensaGold(bani),
  finalizata(false) {
}

void Misiune::adaugaCerinta(std::string text) {
    this->cerinte.push_back(std::move(text));
}

bool Misiune::poateFiExecutata(int nivelAsasin) const {
    return (nivelAsasin >= this->dificultate) && (!this->finalizata);
}

void Misiune::finalizeaza() {
    this->finalizata = true;
}

std::ostream& operator<<(std::ostream& os, const Misiune& m) {
    os << m.descriere << " (Gold: " << m.recompensaGold << ")";
    return os;
}