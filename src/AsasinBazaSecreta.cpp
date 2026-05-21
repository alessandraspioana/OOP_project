//
// Created by aless on 5/22/2026.
//

#include "AsasinBazaSecreta.h"
#include <iostream>
#include <sstream>
#include <algorithm>

AsasinBazaSecreta::AsasinBazaSecreta(std::string_view nume_, int viata_, Arma arma_, std::string_view gadget)
    : Asasin(std::string(nume_), viata_, std::move(arma_)),
      gadgetSpecial(gadget) {
    istoricUpgradeuri["Firmware_baza"] = 1.0;
    istoricUpgradeuri["Criptare_Linie_Audio"] = 1.2;
}

std::unique_ptr<Asasin> AsasinBazaSecreta::clone() const {
    return std::make_unique<AsasinBazaSecreta>(*this);
}

void AsasinBazaSecreta::executaAbilitateSpeciala() {
    std::stringstream logSistem;
    logSistem << "\n[SISTEM HIGH-TECH] Se initiaza secventa de scanare pentru operativul: " << nume << "\n";

    if (nivelBaterieGadget < 20) {
        logSistem << "[AVERTISMENT] Baterie descarcata (" << nivelBaterieGadget << "%). Abilitatea nu poate fi optimizata.\n";
        std::cout << logSistem.str();
        return;
    }

    logSistem << "-> Se activeaza gadgetul: " << gadgetSpecial << "\n";
    nivelBaterieGadget -= 15;

    double factorMultiplicare = 0.0;
    for (const auto& [soft, eficienta] : istoricUpgradeuri) {
        factorMultiplicare += eficienta;
    }

    int xpCastigat = static_cast<int>(25 * factorMultiplicare);
    this->cresteExperienta(xpCastigat);

    logSistem << "-> Scanare finalizata cu succes. Nivel baterie ramas: " << nivelBaterieGadget << "%\n";
    logSistem << "-> Puncte de experienta dobandite prin analiza tactica: " << xpCastigat << "\n";

    if (protocolSecuritateActivat) {
        logSistem << "-> [PROTOCOL CRIPTAT] Semnalul radio a fost complet sters din retea.\n";
    }

    std::cout << logSistem.str();
}

void AsasinBazaSecreta::instaleazaUpgradeTehnologic(std::string_view denumireUpgrade, double coeficientEficienta) {
    if (denumireUpgrade.empty()) return;

    istoricUpgradeuri[std::string(denumireUpgrade)] = coeficientEficienta;
    std::cout << "[SOFTWARE] Upgrade-ul '" << denumireUpgrade << "' a fost mapat cu succes in memoria operationala.\n";
}

void AsasinBazaSecreta::incarcaBaterieGadget(int procentaj) noexcept {
    nivelBaterieGadget += procentaj;
    if (nivelBaterieGadget > 100) {
        nivelBaterieGadget = 100;
    }
}

void AsasinBazaSecreta::comutaProtocolSecuritate() noexcept {
    protocolSecuritateActivat = !protocolSecuritateActivat;
}

bool AsasinBazaSecreta::detineUpgrade(std::string_view denumireUpgrade) const {
    return std::any_of(istoricUpgradeuri.begin(), istoricUpgradeuri.end(),
        [delim = std::string(denumireUpgrade)](const auto& pereche) {
            return pereche.first == delim;
        });
}

void AsasinBazaSecreta::afiseazaDetalii(std::ostream& os) const {
    Asasin::afiseazaDetalii(os);
    os << " [Mod: Operativ Consiliu | Gadget: " << gadgetSpecial
       << " | Energie: " << nivelBaterieGadget << "%"
       << " | Upgrade-uri active: " << istoricUpgradeuri.size() << "]";
}