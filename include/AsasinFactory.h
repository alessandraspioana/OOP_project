//
// Created by aless on 6/21/2026.
//

#ifndef OOP_ASASINFACTORY_H
#define OOP_ASASINFACTORY_H

#include <memory>
#include <string_view>
#include <stdexcept>
#include "Asasin.h"
#include "AsasinElite.h"
#include "AsasinInfiltrat.h"
#include "AsasinBountyHunter.h"

class AsasinFactory {
public:
    static std::unique_ptr<Asasin> creeazaAsasin(std::string_view tip, const std::string& nume, int viata, const Arma& arma) {
        if (tip == "elite" || tip == "ELITE") {
            return std::make_unique<AsasinElite>(nume, viata, arma, 2.0);
        } else if (tip == "infiltrat" || tip == "INFILTRAT") {
            return std::make_unique<AsasinInfiltrat>(nume, viata, arma, "Masca Standard");
        } else if (tip == "bounty" || tip == "BOUNTY") {
            return std::make_unique<AsasinBountyHunter>(nume, viata, arma, 0);
        }

        throw std::invalid_argument("Tipul de asasin solicitat nu exista in baza de date a fabricii.");
    }
};

#endif //OOP_ASASINFACTORY_H