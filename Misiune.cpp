#include "Misiune.h"
#include <iostream>

Misiune::Misiune(const std::string& desc, int dif, int bani) 
    : descriere(desc), dificultate(dif), recompensaGold(bani), finalizata(false) {}

void Misiune::adaugaCerinta(const std::string& text) {
    cerinte.push_back(text);
}

bool Misiune::poateFiExecutata(int nivelAsasin) const {
    return nivelAsasin >= dificultate && !finalizata;
}

void Misiune::finalizeaza() {
    finalizata = true;
}


std::ostream& operator<<(std::ostream& os, const Misiune& m) {
    os << "Misiune: " << m.descriere << " (Dif: " << m.dificultate 
       << ", Recompensa: " << m.recompensaGold << " gold)";
    if (m.finalizata) os << " [FINALIZATA]";
    return os;
}