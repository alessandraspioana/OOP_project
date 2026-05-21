//
// Created by aless on 4/18/2026.
//

#include "SistemSecuritate.h"
#include <sstream>
#include <algorithm>
#include <iostream>

SistemSecuritate::SistemSecuritate(int alertaInitiala)
        : nivelAlerta(alertaInitiala), scanereActive(false) {}

void SistemSecuritate::inregistreazaIncident(const std::string& tip, const std::string& detalii) {
    std::string intrareLog = "[" + tip + "] " + detalii;
    this->istoricIncidente.push_back(intrareLog);

    this->frecventaIncidentePeTip[tip]++;

    if (tip == "CRITIC" || tip == "DUEL") {
        this->nivelAlerta += 2;
        this->scanereActive = true;
    }
    this->autoCalibrare();
}

void SistemSecuritate::resetAlerta() {
    nivelAlerta = 1;
    scanereActive = false;
    istoricIncidente.push_back("[SYSTEM] Alerta resetata manual.");
    std::cout << "[SECURITY] Sistemul a fost resetat la starea initiala.\n";
}

[[nodiscard]] bool SistemSecuritate::esteIzolat() const {
    return scanereActive;
}

[[nodiscard]] int SistemSecuritate::getNivelAlerta() const {
    return nivelAlerta;
}

void SistemSecuritate::autoCalibrare() {
    if (nivelAlerta >= 4) {
        scanereActive = true;
        std::cout << "[SECURITY] Protocol de scanare avansata ACTIVAT.\n";
    } else {
        scanereActive = false;
    }
}

void SistemSecuritate::ruleazaDiagnosticSenzori() {
    std::cout << "[SISTEM] Se ruleaza analizatorul hardware de retea...\n";
    for (auto& [zona, stare] : bazaDateSenzori) {
        stare = "OPERATIONAL";
    }
}

void SistemSecuritate::adaugaSenzorPerimetral(std::string_view zona, std::string_view tipSenzor) {
    this->bazaDateSenzori.push_back(std::make_pair(std::string(zona), std::string(tipSenzor)));
}

void SistemSecuritate::simuleazaScanareCompleta() const {
    std::cout << "--- Incepe scanarea termica a perimetrului Continental ---\n";
    std::for_each(bazaDateSenzori.begin(), bazaDateSenzori.end(), [](const auto& senzor) {
        std::cout << " > Senzor amplasat in zona: " << senzor.first << " | Status: " << senzor.second << "\n";
    });
}

std::string SistemSecuritate::genereazaRaportSecuritateCurent() const {
    std::stringstream bufferRaport;
    bufferRaport << "\n======= RAPORT DIGITAL DE SECURITATE =======\n";
    bufferRaport << "Nivel Alerta curent: " << nivelAlerta << "\n";
    bufferRaport << "Stare scanere: " << (scanereActive ? "ONLINE" : "OFFLINE") << "\n";
    bufferRaport << "Total senzori monitorizati: " << bazaDateSenzori.size() << "\n";
    bufferRaport << "--- Centralizator tipuri de incidente ---\n";

    for (const auto& [tip, numar] : frecventaIncidentePeTip) {
        bufferRaport << "  * Categoria [" << tip << "] -> aparitii: " << numar << "\n";
    }
    bufferRaport << "============================================\n";
    return bufferRaport.str();
}

int SistemSecuritate::getFrecventaIncident(std::string_view tip) const {
    auto it = frecventaIncidentePeTip.find(std::string(tip));
    if (it != frecventaIncidentePeTip.end()) {
        return it->second;
    }
    return 0;
}