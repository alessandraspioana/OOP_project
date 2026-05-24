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
    std::cout << "\n[INFILTRATION MECHANIC] " << nume << " actioneaza din umbra purtand masca: " << mascaCurenta << ".\n";

    nivelSuspiciune += 35;

    if (nivelSuspiciune >= 100) {
        std::cout << " > [COMPROMIS] Alerta maxima! Identitatea sub masca de '" << mascaCurenta << "' a fost deconspirata!\n";
        this->esteInfiltrat = false;
        this->primesteDamage(20);
        nivelSuspiciune = 0;
    } else {
        std::cout << " > Actiune discreta finalizata. Nivel curent de suspiciune: " << nivelSuspiciune << "%\n";
        this->cresteExperienta(15);

        if (nivelSuspiciune > 50) {
            this->mascaCurenta = "Personal Serviciu Continental";
            std::cout << " > Schimbare rapida de deghizare in: " << mascaCurenta << "\n";
            nivelSuspiciune -= 20;
        }
    }
}

void AsasinInfiltrat::afiseazaDetalii(std::ostream& os) const {
    Asasin::afiseazaDetalii(os);
    os << " [Infiltrat | Acoperire: " << mascaCurenta << " | Suspiciune: " << nivelSuspiciune << "%]";
}