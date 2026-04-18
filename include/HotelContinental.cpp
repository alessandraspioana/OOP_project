//
// Created by aless on 4/18/2026.
//

#include "HotelContinental.h"

#include <algorithm>
#include <Asasin.h>

void HotelContinental::aprovizionareSeif(int suma) { seifGold += suma; }

    HotelContinental::HotelContinental(std::string oras_, int goldInitial)
        : oras{std::move(oras_)},
          seifGold{goldInitial},
          securitate{1} {
    }

    void HotelContinental::cazeaza(const Asasin& a) {
        securitate.inregistreazaIncident("ADMIN", "Cazare noua: " + a.getNume());
        this->oaspeti.push_back(a);
    }

    void HotelContinental::organizeazaDuel(size_t idx1, size_t idx2) {
        if (idx1 < this->oaspeti.size() && idx2 < this->oaspeti.size()) {
            securitate.inregistreazaIncident("VIOLENTA", "Duel intre " + oaspeti[idx1].getNume() + " si " + oaspeti[idx2].getNume());
            this->oaspeti[idx1].ataca(this->oaspeti[idx2]);
        }
    }

    void HotelContinental::evacueazaDecedatii() {
        this->oaspeti.erase(
            std::remove_if(this->oaspeti.begin(), this->oaspeti.end(),
                [this](const Asasin& a) {
                    if (!a.esteInViata()) {
                        securitate.inregistreazaIncident("CURATENIE", "Evacuare corp: " + a.getNume());
                        return true;
                    }
                    return false;
                }),
            this->oaspeti.end()
        );
    }

    void HotelContinental::adaugaMisiune(Misiune m) {
        this->avizierMisiuni.push_back(std::move(m));
    }

    void HotelContinental::executaContract(size_t idxAsasin, size_t idxMisiune) {
        if (idxAsasin < this->oaspeti.size() && idxMisiune < this->avizierMisiuni.size()) {
            if (this->avizierMisiuni[idxMisiune].poateFiExecutata(this->oaspeti[idxAsasin].getNivel())) {
                securitate.inregistreazaIncident("CONTRACT", oaspeti[idxAsasin].getNume() + " a finalizat o misiune.");
                this->avizierMisiuni[idxMisiune].finalizeaza();
                this->seifGold -= this->avizierMisiuni[idxMisiune].getRecompensa();
            }
        }
    }

    void HotelContinental::afiseazaRegistru() const {
        std::cout << "--- Registru Hotel " << this->oras << " ---" << std::endl;
        for (const auto& as : this->oaspeti) {
            std::cout << " * " << as << std::endl;
        }
    }

    void HotelContinental::afiseazaAvizier() const {
        std::cout << "--- Avizier Hotel " << this->oras << " ---" << std::endl;
        for (const auto& ms : this->avizierMisiuni) {
            std::cout << " ! " << ms << std::endl;
        }
    }

    void HotelContinental::simuleazaNoapteInHotel() {
        std::cout << "\n[EVENT] Noaptea cade peste hotelul din " << this->oras << "..." << std::endl;

        if (securitate.esteIzolat()) {
            std::cout << " > HOTELUL ESTE IZOLAT. Masuri stricte de paza." << std::endl;
        }

        if (this->oaspeti.empty()) {
            std::cout << " > Hotelul este pustiu. Liniste deplina." << std::endl;
            return;
        }

        for (auto& as : this->oaspeti) {
            if (as.getViata() < 50) {
                std::cout << " > " << as.getNume() << " primeste ingrijiri medicale de urgenta." << std::endl;
                as.folosesteItem("Trusa");
            } else {
                std::cout << " > " << as.getNume() << " se odihneste. Recuperare usoara." << std::endl;
                as.primesteDamage(-5);
            }
        }

        this->seifGold += 100;
        std::cout << " > Taxe de noapte colectate. Seif nou: " << this->seifGold << std::endl;
    }