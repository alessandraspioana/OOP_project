//
// Created by aless on 4/18/2026.
//

#include "Asasin.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

[[nodiscard]] bool Asasin::esteInViata() const { return viata > 0; }
    [[nodiscard]] const std::string& Asasin::getNume() const { return nume; }
    [[nodiscard]] int Asasin::getNivel() const { return nivel; }
    [[nodiscard]] int Asasin::getViata() const { return viata; }


    Asasin::Asasin(std::string nume_, int viata_, Arma arma_)
        : nume{std::move(nume_)},
          viata{viata_},
          experienta{0},
          nivel{1},
          arma{std::move(arma_)} {
    }

    Asasin::Asasin(const Asasin& other)
        : nume{other.nume + " (Copy)"},
          viata{other.viata},
          experienta{other.experienta},
          nivel{other.nivel},
          arma{other.arma},
          distinctii{other.distinctii},
          inventar{other.inventar} {
    }

    Asasin& Asasin::operator=(const Asasin& other) {
        if (this != &other) {
            this->nume = other.nume;
            this->viata = other.viata;
            this->experienta = other.experienta;
            this->arma = other.arma;
            this->nivel = other.nivel;
            this->inventar = other.inventar;
            this->distinctii = other.distinctii;
        }
        return *this;
    }

    void Asasin::ataca(Asasin& tinta) {
    if (this->arma.trage()) {
        tinta.primesteDamage(25);
        this->cresteExperienta(10);
    }
    }

    void Asasin::primesteDamage(int dmg) {
    this->viata -= dmg;
    if (this->viata < 0) {
        this->viata = 0;
    }
    }

    void Asasin::antrenament() {
    this->experienta += 30;
    this->arma.curataArma();
    }

    void Asasin::cresteExperienta(int puncte) {
    this->experienta += puncte;
    if (this->experienta >= 100) {
        this->nivel++;
        this->experienta = 0;
    }
    }

    void Asasin::adaugaDistinctie(const std::string& numeDistinctie) {
    this->distinctii.push_back(std::move(numeDistinctie));
    }

    void Asasin::colecteazaItem(const std::string& item) {
    if (this->inventar.size() < 5) {
        this->inventar.push_back(std::move(item));
    }
    }

    void Asasin::folosesteItem(const std::string& item) {
    auto it = std::find(this->inventar.begin(), this->inventar.end(), item);
    if (it != this->inventar.end()) {
        if (item == "Trusa") {
            this->viata += 20;
        }
        this->inventar.erase(it);
    }
    }

    void Asasin::activeazaModInfiltrare() {
    this->esteInfiltrat = true;
    }

    void Asasin::afiseazaStatusComplet() const {
        std::cout << "Status: " << this->nume << " | Viata: " << this->viata
                  << " | XP: " << this->experienta << " | LVL: " << this->nivel << std::endl;
    }

    void Asasin::evalueazaTitluOnorific() {
        std::cout << "[RANKING] Se evalueaza rangul pentru " << this->nume << "..." << std::endl;

        if (this->nivel > 10 && this->distinctii.size() > 3) {
            this->adaugaDistinctie("Grandmaster of the Continental");
        } else if (this->nivel > 5) {
            this->adaugaDistinctie("Elite Operative");
        } else {
            std::cout << " > Rang actual: Ucenic (necesita mai multa experienta)." << std::endl;
        }

        double putereRelativa = (this->viata * 0.4) + (this->nivel * 10.0);
        std::cout << " > Indice de periculozitate calculat: " << std::fixed << std::setprecision(2)
                  << putereRelativa << std::endl;
    }

        [[nodiscard]] std::string Asasin::getDescriereRang() const {
        if (this->nivel >= 10) return "Legenda Vie";
        if (this->nivel >= 5) return "Profesionist";
        return "Incepator";
    }

    Asasin::~Asasin() {

    }