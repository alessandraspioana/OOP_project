//
// Created by aless on 5/22/2026.
//

#include "AsasinInfiltrat.h"

AsasinInfiltrat::AsasinInfiltrat(std::string nume_, int viata_, Arma arma_, std::string masca)
    : Asasin(std::move(nume_), viata_, std::move(arma_)), mascaCurenta(std::move(masca)) {
    this->esteInfiltrat = true;
}

std::unique_ptr<Asasin> AsasinInfiltrat::clone() const {
    return std::make_unique<AsasinInfiltrat>(*this);
}

void AsasinInfiltrat::executaAbilitateSpeciala() {
    std::cout << "[Abilitate Infiltrat] " << nume << " se camufleaza ca: " << mascaCurenta << ".\n";
    this->activeazaModInfiltrare();
}

void AsasinInfiltrat::afiseazaDetalii(std::ostream& os) const {
    Asasin::afiseazaDetalii(os);
    os << " [Mod: Infiltrat | Identitate: " << mascaCurenta << "]";
}