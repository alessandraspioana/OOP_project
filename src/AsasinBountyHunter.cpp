//
// Created by aless on 5/22/2026.
//

#include "AsasinBountyHunter.h"

AsasinBountyHunter::AsasinBountyHunter(std::string nume_, int viata_, Arma arma_, int contracte)
    : Asasin(std::move(nume_), viata_, std::move(arma_)), contracteFinalizate(contracte) {
    tinteUrmarite.push_back("Anonim_1");
    tinteUrmarite.push_back("Anonim_2");
}

std::unique_ptr<Asasin> AsasinBountyHunter::clone() const {
    return std::make_unique<AsasinBountyHunter>(*this);
}

void AsasinBountyHunter::adaugaTintaInUrmarire(const std::string& numeTinta) {
    if (!numeTinta.empty()) {
        tinteUrmarite.push_back(numeTinta);
        std::cout << "[BOUNTY] Tinta '" << numeTinta << "' a fost adaugata pe lista neagra a lui " << nume << ".\n";
    }
}

void AsasinBountyHunter::executaAbilitateSpeciala() {
    std::cout << "\n[BOUNTY HUNTER MECHANIC] " << nume << " verifica contractele active.\n";

    if (tinteUrmarite.empty()) {
        std::cout << " > Nu mai exista tinte active in perimetru. Se solicita noi contracte.\n";
        tinteUrmarite.push_back("Tinta_Noua_Generata");
        return;
    }

    std::string tintaCurenta = tinteUrmarite.back();
    tinteUrmarite.pop_back();

    contracteFinalizate++;
    std::cout << " > Succes! Tinta '" << tintaCurenta << "' a fost eliminata. Contracte bifate: " << contracteFinalizate << "\n";

    this->cresteExperienta(35);

    if (contracteFinalizate % 2 == 0) {
        std::cout << " > Recompensa colectata fizic: s-a gasit o Trusa medicala asupra tintei.\n";
        this->colecteazaItem("Trusa");
    }
}

void AsasinBountyHunter::afiseazaDetalii(std::ostream& os) const {
    Asasin::afiseazaDetalii(os);
    os << " [Bounty Hunter | Total incasari: " << contracteFinalizate << " | Tinte ramase: " << tinteUrmarite.size() << "]";
}