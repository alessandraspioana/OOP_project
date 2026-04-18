//
// Created by aless on 4/18/2026.
//

#include "BursaAsasinilor.h"
#include <iomanip>

    [[nodiscard]] size_t BursaAsasinilor::getNumarContracte() const { return contracteDeschise.size(); }
    [[nodiscard]] const std::string& BursaAsasinilor::getSediu() const { return sediuCentral; }

    BursaAsasinilor::BursaAsasinilor(std::string sediu, int fondInitial)
    : sediuCentral(std::move(sediu)), fondTotalPremii(fondInitial) {
}

    void BursaAsasinilor::publicaBounty(std::string nume, int bani, int risc) {
        Bounty nou = {std::move(nume), bani, risc, true};
        this->contracteDeschise.push_back(nou);
        std::cout << "[BURSA] Contract nou pe numele: " << nou.numeTinta << " | Recompensa: " << bani << std::endl;
    }

    void BursaAsasinilor::anuleazaBounty(const std::string& nume) {
        for (auto& b : this->contracteDeschise) {
            if (b.numeTinta == nume) {
                b.esteActiv = false;
                std::cout << "[BURSA] Contractul pentru " << nume << " a fost retras." << std::endl;
            }
        }
    }

    int BursaAsasinilor::calculeazaTaxaConsiliu(int suma) const {
        if (this->sediuCentral.empty()) {
            return 0;
        }

        return static_cast<int>(suma * 0.1);
    }

    void BursaAsasinilor::proceseazaRecompensa(Asasin& vanator, size_t indexContract) {
        if (indexContract >= this->contracteDeschise.size()) {
            std::cout << "[ERROR] Index contract invalid la Bursa." << std::endl;
            return;
        }

        Bounty& b = this->contracteDeschise[indexContract];
        if (b.esteActiv && vanator.esteInViata()) {
            int taxa = calculeazaTaxaConsiliu(b.recompensa);
            int sumaFinala = b.recompensa - taxa;

            this->fondTotalPremii -= b.recompensa;
            b.esteActiv = false;
            this->istoricLichidari.push_back(b.numeTinta);

            vanator.cresteExperienta(b.periculozitate * 20);
            vanator.adaugaDistinctie("Vânător de recompense: " + b.numeTinta);

            std::cout << "[RECOMPENSA] " << vanator.getNume() << " a incasat " << sumaFinala
                      << " Gold (Taxa Consiliu: " << taxa << ")" << std::endl;
        }
    }

    void BursaAsasinilor::afiseazaCeleMaiCautateTinte() const {
        std::cout << "\n--- MOST WANTED - SEDIU: " << this->sediuCentral << " ---" << std::endl;
        for (const auto& b : this->contracteDeschise) {
            if (b.esteActiv) {
                std::cout << " Tinta: " << std::setw(15) << b.numeTinta
                          << " | Premiu: " << b.recompensa << " | Risc: " << b.periculozitate << std::endl;
            }
        }
    }

    void BursaAsasinilor::genereazaStatisticiBursa() const {
        std::cout << "\n--- STATISTICI BURSA ---" << std::endl;
        std::cout << " Contracte finalizate: " << this->istoricLichidari.size() << std::endl;
        std::cout << " Fonduri ramase in seif: " << this->fondTotalPremii << std::endl;
        std::cout << " Ultima lichidare: " << (istoricLichidari.empty() ? "N/A" : istoricLichidari.back()) << std::endl;
    }

    void BursaAsasinilor::suplimenteazaFonduri(int suma) {
        this->fondTotalPremii += suma;
        std::cout << "[BURSA] Fonduri suplimentate cu " << suma << ". Total: " << this->fondTotalPremii << std::endl;
    }