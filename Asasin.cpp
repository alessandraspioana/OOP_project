//
// Created by aless on 4/2/2026.
//

#include "Asasin.h"
#include <algorithm>
#include <iostream>

Asasin::Asasin(const std::string& nume_, int viata_, const Arma& arma_)
    : nume{nume_}, viata{viata_}, experienta{0}, arma{arma_} {}

Asasin::Asasin(const Asasin& other)
    : nume{other.nume + " (Copy)"}, viata{other.viata},
      experienta{other.experienta}, arma{other.arma}, distinctii{other.distinctii} {
    std::cout << "[CC] Copie creata pentru " << other.nume << "\n";
}

Asasin& Asasin::operator=(const Asasin& other) {
    if (this != &other) {
        nume = other.nume;
        viata = other.viata;
        experienta = other.experienta;
        arma = other.arma;
        distinctii = other.distinctii;
    }
    return *this;
}

Asasin::~Asasin() {
}

void Asasin::primesteDamage(int dmg) {
    viata -= dmg;
    if (viata < 0) viata = 0;
    std::cout << nume << " a ramas cu " << viata << " HP.\n";
}

void Asasin::antrenament() {
    experienta += 20;
    arma.curataArma();
    std::cout << nume << " s-a antrenat. Experienta curenta: " << experienta << "\n";
}

void Asasin::cresteExperienta(int puncte) {
    if (!esteInViata()) return;

    experienta += puncte;
    std::cout << "[XP] " << nume << " a castigat " << puncte << " puncte de experienta.\n";

    if (experienta >= 100) {
        nivel++;
        experienta %= 100;
        viata += 20;
        std::cout << "[LEVEL UP] " << nume << " a ajuns la nivelul " << nivel << "!\n";
    }
}

void Asasin::adaugaDistinctie(const std::string& numeDistinctie) {
    distinctii.push_back(numeDistinctie);
    std::cout << "[ACHIEVEMENT] " << nume << " a primit distinctia: " << numeDistinctie << "\n";
}

void Asasin::colecteazaItem(const std::string& item) {
    if (inventar.size() >= 5) {
        std::cout << "[FULL] Inventarul lui " << nume << " este plin! Nu poate lua: " << item << "\n";
        return;
    }
    inventar.push_back(item);
    std::cout << "[ITEM] " << nume << " a gasit: " << item << "\n";
}

void Asasin::folosesteItem(const std::string& item) {
    // Cautam item-ul in vector (asta adauga complexitate si linii)
    auto it = std::find(inventar.begin(), inventar.end(), item);

    if (it != inventar.end()) {
        std::cout << "[USE] " << nume << " foloseste " << item << ".\n";

        if (item == "Trusa Medicala") {
            viata += 50;
            if (viata > 150) viata = 150; // Cap la viata
            std::cout << " > Viata a crescut la " << viata << " HP.\n";
        }
        else if (item == "Adrenalina") {
            experienta += 30;
            std::cout << " > Experienta a crescut bonus cu 30 puncte.\n";
        }

        inventar.erase(it); // Scoatem item-ul dupa folosire
    } else {
        std::cout << "[ERROR] Item-ul " << item << " nu a fost gasit in inventar.\n";
    }
}

void Asasin::activeazaModInfiltrare() {
    if (esteInViata()) {
        esteInfiltrat = true;
        std::cout << "[STEALTH] " << nume << " a intrat in umbra. Sansele de detectie au scazut.\n";
    }
}

void Asasin::afiseazaStatusComplet() const {
    std::cout << "\n========================================\n";
    std::cout << "        DOSAR ASASIN: " << nume << "\n";
    std::cout << "========================================\n";
    std::cout << " Status: " << (esteInViata() ? "ACTIV" : "ELIMINAT") << "\n";
    std::cout << " Nivel: " << nivel << " | Viata: " << viata << " HP\n";
    std::cout << " Experienta: " << experienta << "/100 XP\n";
    std::cout << " Mod Infiltrare: " << (esteInfiltrat ? "DA" : "NU") << "\n";

    std::cout << "----------------------------------------\n";
    std::cout << " Inventar: ";
    if (inventar.empty()) std::cout << "Gol";
    else {
        for (const auto& item : inventar) std::cout << "[" << item << "] ";
    }

    std::cout << "\n Distinctii: ";
    if (distinctii.empty()) std::cout << "Niciuna";
    else {
        for (const auto& d : distinctii) std::cout << "{" << d << "} ";
    }
    std::cout << "\n========================================\n";
}

// Modificam si ataca() sa tina cont de infiltrat
void Asasin::ataca(Asasin& tinta) {
    if (!esteInViata()) return;

    int bonusDamage = esteInfiltrat ? 15 : 0; // Damage extra daca ataci din umbra

    if (arma.trage()) {
        std::cout << nume << (esteInfiltrat ? " (din umbra)" : "") << " il ataca pe " << tinta.getNume() << "!\n";
        tinta.primesteDamage(20 + (experienta / 10) + bonusDamage);

        experienta += 5;
        if (esteInfiltrat) esteInfiltrat = false; // Iese din stealth dupa atac
    } else {
        std::cout << nume << " a esuat atacul!\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Asasin& as) {
    os << "Asasin: " << as.nume << " [HP: " << as.viata << " | XP: " << as.experienta
       << "] dotat cu " << as.arma;
    return os;
}