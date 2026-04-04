//
// Created by aless on 4/2/2026.
//

#ifndef OOP_CONSILIUINALT_H
#define OOP_CONSILIUINALT_H


#pragma once
#include <string>
#include <vector>
#include <map>
#include "HotelContinental.h"

struct StatisticaGlobala {
    int totalAsasini;
    int misiuniCompletate;
    int goldInCirculatie;
};

class ConsiliuInalt {
private:
    std::string lider;
    std::vector<HotelContinental> reteaHoteliera;
    std::vector<std::string> reguliCodex;
    StatisticaGlobala stats;

public:
    explicit ConsiliuInalt(const std::string& numeLider);

    void adaugaHotel(const HotelContinental& h);
    static void emiteExcommunicado(Asasin& a);
    void adaugaRegula(const std::string& regula);
    void afiseazaCodex() const;
    void genereazaAuditFinanciar() const;
    void upgradeSecuritateGlobala();

    void genereazaRaportGlobal() const;
    bool verificaIncalcareaRegulilor(const std::string& actiune) const;

    void finanteazaHotel(size_t idx, int suma);

    friend std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c);
};


#endif //OOP_CONSILIUINALT_H