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
    std::cout << "\n[ELITE MECHANIC] " << nume << " isi recalculeaza vectorul de tragere.\n";

    puncteCombo++;
    if (puncteCombo >= limitaComboMax) {
        std::cout << " > COMBO MAXIM ACTIVAT! " << nume << " executa un foc triplu devastator!\n";
        this->multiplicatorDamage += 0.5;
        this->arma.reincarca(3);
        this->cresteExperienta(40);
        puncteCombo = 0;
    } else {
        std::cout << " > Concentrare crescuta. Combo curent: " << puncteCombo << "/" << limitaComboMax << "\n";
        this->cresteExperienta(10);
    }
}

void AsasinElite::afiseazaDetalii(std::ostream& os) const {
    Asasin::afiseazaDetalii(os);
    os << " [Elite | Multiplicator: " << multiplicatorDamage << "x | Combo: " << puncteCombo << "]";
}