// HotelContinental.cpp
#include "HotelContinental.h"
#include <iostream>
#include <algorithm>

HotelContinental::HotelContinental(std::string oras_, int goldInitial)
    : oras{std::move(oras_)}, seifGold{goldInitial}, securitate{1} {}

void HotelContinental::aprovizionareSeif(int suma) {
    this->seifGold += suma;
    std::cout << "[HOTEL] S-au adaugat " << suma << " monede de aur in seiful din " << oras << ".\n";
}

void HotelContinental::cazeaza(std::unique_ptr<Asasin> a) {
    if (a) {
        std::cout << "[HOTEL] Asasinul " << a->getNume() << " s-a cazat in " << oras << ".\n";
        oaspeti.push_back(std::move(a));
    }
}

void HotelContinental::afiseazaRegistru() const {
    std::cout << "\n=== REGISTRU OASPETI " << oras << " ===\n";
    if (oaspeti.empty()) {
        std::cout << "  Niciun oaspete inregistrat.\n";
    } else {
        for (const auto& oaspete : oaspeti) {
            std::cout << "  * " << *oaspete << "\n";
        }
    }
    std::cout << "====================================\n";
}

void HotelContinental::organizeazaDuel(size_t idx1, size_t idx2) {
    if (idx1 < oaspeti.size() && idx2 < oaspeti.size()) {
        std::cout << "\n[DUEL] Pe pamantul sacru din " << oras << " se infrunta: "
                  << oaspeti[idx1]->getNume() << " si " << oaspeti[idx2]->getNume() << "\n";

        oaspeti[idx1]->executaAbilitateSpeciala();
        oaspeti[idx2]->executaAbilitateSpeciala();

        oaspeti[idx1]->ataca(*oaspeti[idx2]);

        securitate.inregistreazaIncident("DUEL", oaspeti[idx1]->getNume() + " l-a atacat pe " + oaspeti[idx2]->getNume());
    } else {
        std::cout << "[DUEL] Indici invalizi pentru duel.\n";
    }
}

// In HotelContinental.cpp
#include "ExceptiiHotel.h"
#include <numeric>

void HotelContinental::executaContract(size_t idxAsasin, size_t idxMisiune) {
    if (idxAsasin < oaspeti.size() && idxMisiune < avizierMisiuni.size()) {
        if (!avizierMisiuni[idxMisiune].esteFinalizata()) {

            if (seifGold < avizierMisiuni[idxMisiune].getRecompensa()) {
                throw InsufficientGoldException(avizierMisiuni[idxMisiune].getRecompensa(), seifGold);
            }

            if (avizierMisiuni[idxMisiune].poateFiExecutata(oaspeti[idxAsasin]->getNivel())) {
                std::cout << "[CONTRACT] " << oaspeti[idxAsasin]->getNume()
                          << " a finalizat cu succes: " << avizierMisiuni[idxMisiune].getDescriere() << "\n";
                oaspeti[idxAsasin]->cresteExperienta(100);
                avizierMisiuni[idxMisiune].finalizeaza();
                seifGold -= avizierMisiuni[idxMisiune].getRecompensa();
            }
        }
    }
}

void HotelContinental::evacueazaDecedatii() {
    size_t initial = oaspeti.size();
    oaspeti.erase(
        std::remove_if(oaspeti.begin(), oaspeti.end(),
                       [](const std::unique_ptr<Asasin>& a) { return !a->esteInViata(); }),
        oaspeti.end()
    );
    size_t curent = oaspeti.size();
    if (initial > curent) {
        std::cout << "[HOTEL] Au fost evacuati " << (initial - curent) << " asasini cazuti la datorie.\n";
    }
}

void HotelContinental::adaugaMisiune(Misiune m) {
    avizierMisiuni.push_back(std::move(m));
}

void HotelContinental::afiseazaAvizier() const {
    std::cout << "\n=== AVIZIER MISIUNI " << oras << " ===\n";
    for (const auto& m : avizierMisiuni) {
        std::cout << "  - " << m << "\n";
    }
    std::cout << "====================================\n";
}

void HotelContinental::simuleazaNoapteInHotel() {
    std::cout << "\n[NOAPTE] Se asterne linistea peste " << oras << ". Asasinii se pregatesc...\n";
    for (const auto& oaspete : oaspeti) {
        oaspete->executaAbilitateSpeciala();
    }
}

int HotelContinental::calculeazaNumarAsasiniVeterani() const {
    return std::count_if(oaspeti.begin(), oaspeti.end(),
        [](const std::unique_ptr<Asasin>& a) {
            return a->getNivel() >= 2;
        });
}