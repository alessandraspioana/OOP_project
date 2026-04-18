//
// Created by aless on 4/18/2026.
//

#include "ConsiliuInalt.h"
#include <Asasin.h>


    ConsiliuInalt::ConsiliuInalt(std::string numeLider)
    : lider(std::move(numeLider)),
      stats{0, 0, 100000} {
    }

    void ConsiliuInalt::adaugaHotel(HotelContinental h) {
        this->reteaHoteliera.push_back(std::move(h));
        this->stats.totalAsasini += 1;
        this->stats.misiuniCompletate += 0;
    }

    void ConsiliuInalt::emiteExcommunicado(Asasin& a) const {
        std::cout << "Liderul " << this->lider << " emite ordinul!" << std::endl;
        a.primesteDamage(99);
    }

    void ConsiliuInalt::adaugaRegula(std::string regula) {
        this->reguliCodex.push_back(std::move(regula));
    }

    void ConsiliuInalt::afiseazaCodex() const {
        std::cout << "Codex administrat de " << this->lider << ":" << std::endl;
        for (const auto& r : this->reguliCodex) {
            std::cout << " - " << r << std::endl;
        }
    }

    void ConsiliuInalt::genereazaRaportGlobal() const {
        std::cout << "Raport lider: " << this->lider << std::endl;
        std::cout << "Fonduri: " << this->stats.goldInCirculatie << std::endl;
        std::cout << "Misiuni raportate la nivel global: " << this->stats.misiuniCompletate << std::endl;
    }

    void ConsiliuInalt::finanteazaHotel(size_t idx, int suma) {
        if (idx < this->reteaHoteliera.size() && this->stats.goldInCirculatie >= suma) {
            this->reteaHoteliera[idx].aprovizionareSeif(suma);
            this->stats.goldInCirculatie -= suma;
        }
    }

    void ConsiliuInalt::genereazaAuditFinanciar() const {
        std::cout << "Audit lider: " << this->lider << ". Unitati: "
                  << this->reteaHoteliera.size() << std::endl;
    }

    void ConsiliuInalt::upgradeSecuritateGlobala() {
        this->stats.goldInCirculatie -= 1000;
        std::cout << "Upgrade activat de " << this->lider << std::endl;
    }

