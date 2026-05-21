//
// Created by aless on 5/21/2026.
//

#include "AsasinElite.h"

AsasinElite::AsasinElite(std::string nume_, int viata_, Arma arma_, double mult)
    : Asasin(std::move(nume_), viata_, std::move(arma_)), multiplicatorDamage(mult) {}

std::unique_ptr<Asasin> AsasinElite::clone() const {
    return std::make_unique<AsasinElite>(*this);
}

void AsasinElite::executaAbilitateSpeciala() {
    std::cout << "[Abilitate Elite] " << nume << " are o precizie chirurgicala. Multiplicator damage setat la " << multiplicatorDamage << "x!\n";
    this->cresteExperienta(20);
}

void AsasinElite::afiseazaDetalii(std::ostream& os) const {
    Asasin::afiseazaDetalii(os);
    os << " [Mod: Elite | Multiplicator: " << multiplicatorDamage << "]";
}