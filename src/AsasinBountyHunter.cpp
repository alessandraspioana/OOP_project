//
// Created by aless on 5/22/2026.
//

#include "AsasinBountyHunter.h"

AsasinBountyHunter::AsasinBountyHunter(std::string nume_, int viata_, Arma arma_, int contracte)
    : Asasin(std::move(nume_), viata_, std::move(arma_)), contracteFinalizate(contracte) {}

std::unique_ptr<Asasin> AsasinBountyHunter::clone() const {
    return std::make_unique<AsasinBountyHunter>(*this);
}

void AsasinBountyHunter::executaAbilitateSpeciala() {
    contracteFinalizate++;
    std::cout << "[Abilitate Bounty Hunter] " << nume << " a mai incasat o recompensa. Total contracte: " << contracteFinalizate << ".\n";
    this->cresteExperienta(30);
}

void AsasinBountyHunter::afiseazaDetalii(std::ostream& os) const {
    Asasin::afiseazaDetalii(os);
    os << " [Mod: Bounty Hunter | Contracte: " << contracteFinalizate << "]";
}