//
// Created by aless on 4/18/2026.
//

#ifndef OOP_BURSAASASINILOR_H
#define OOP_BURSAASASINILOR_H
#include <string>
#include <vector>

#include "Asasin.h"


class BursaAsasinilor {

private:
    struct Bounty {
        std::string numeTinta;
        int recompensa;
        int periculozitate;
        bool esteActiv;
    };

    std::string sediuCentral;
    std::vector<Bounty> contracteDeschise;
    std::vector<std::string> istoricLichidari;
    int fondTotalPremii;

public:

    [[nodiscard]] size_t getNumarContracte() const;
    [[nodiscard]] const std::string& getSediu() const;
    explicit BursaAsasinilor(std::string sediu, int fondInitial);
    void publicaBounty(std::string nume, int bani, int risc);
    void anuleazaBounty(const std::string& nume);
    int calculeazaTaxaConsiliu(int suma) const;
    void proceseazaRecompensa(Asasin& vanator, size_t indexContract);
    void afiseazaCeleMaiCautateTinte() const;
    void genereazaStatisticiBursa() const;
    void suplimenteazaFonduri(int suma);
    friend std::ostream& operator<<(std::ostream& os, const BursaAsasinilor& b) {
        os << "Bursa Asasinilor (" << b.sediuCentral << ") - Fonduri: " << b.fondTotalPremii;
        return os;
    }
};


#endif //OOP_BURSAASASINILOR_H