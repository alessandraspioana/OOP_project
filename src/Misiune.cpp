//
// Created by aless on 4/18/2026.
//

#include "Misiune.h"

#include <algorithm>
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

bool Misiune::areCerintaInclusa(std::string_view textCerinta) const {
    return std::any_of(cerinte.begin(), cerinte.end(),
        [textCerinta](const std::string& c) {
            return c == textCerinta;
        });
}

void Misiune::eliminaCerinteInvalide() {
    cerinte.erase(
        std::remove_if(cerinte.begin(), cerinte.end(),
            [](const std::string& c) {
                return c.empty() || c.length() < 3;
            }),
        cerinte.end()
    );
}

size_t Misiune::getNumarCerinteComplexe() const {
    return std::count_if(cerinte.begin(), cerinte.end(),
        [](const std::string& c) {
            return c.find(' ') != std::string::npos;
        });
}