//
// Created by aless on 4/18/2026.
//

#include "SistemSecuritate.h"

#include <iostream>

SistemSecuritate::SistemSecuritate(int alertaInitiala)
        : nivelAlerta(alertaInitiala), scanereActive(false) {}

void SistemSecuritate::inregistreazaIncident(const std::string& tip, const std::string& detalii) {
    std::string entry = "[" + tip + "] " + detalii;
    istoricIncidente.push_back(entry);

    if (tip == "VIOLENTA" && nivelAlerta < 5) {
        nivelAlerta++;
    }
    autoCalibrare();
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