//
// Created by aless on 4/18/2026.
//

#ifndef OOP_ASASIN_H
#define OOP_ASASIN_H
#include <string>
#include <vector>
#include <iostream>
#include "Arma.h"


class Asasin {

    std::string nume;
    int viata;
    int experienta;
    int nivel = 1;
    bool esteInfiltrat = false;
    Arma arma;
    std::vector<std::string> distinctii;
    std::vector<std::string> inventar;
public:
    [[nodiscard]] bool esteInViata() const;
    [[nodiscard]] const std::string& getNume() const;
    [[nodiscard]] int getNivel() const;
    [[nodiscard]] int getViata() const;
    explicit Asasin(std::string nume_, int viata_, Arma arma_);
    Asasin(const Asasin& other);
    Asasin& operator=(const Asasin& other);
    ~Asasin();
    void ataca(Asasin& tinta);
    void primesteDamage(int dmg);
    void antrenament();
    void cresteExperienta(int puncte);
    void adaugaDistinctie(const std::string& numeDistinctie);
    void colecteazaItem(const std::string& item);
    void folosesteItem(const std::string& item);
    void activeazaModInfiltrare();
    void afiseazaStatusComplet() const;
    void evalueazaTitluOnorific();
    [[nodiscard]] std::string getDescriereRang() const;
    friend std::ostream& operator<<(std::ostream& os, const Asasin& as) {
        os << as.nume << " (HP: " << as.viata << ")";
        return os;
    }
};


#endif //OOP_ASASIN_H