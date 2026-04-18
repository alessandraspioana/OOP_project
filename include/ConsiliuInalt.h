//
// Created by aless on 4/18/2026.
//

#ifndef OOP_CONSILIUINALT_H
#define OOP_CONSILIUINALT_H
#include <string>
#include <vector>

#include "HotelContinental.h"


class ConsiliuInalt {

private:
    struct StatisticaGlobala {
        int totalAsasini;
        int misiuniCompletate;
        int goldInCirculatie;
    };
    std::string lider;
    std::vector<HotelContinental> reteaHoteliera;
    std::vector<std::string> reguliCodex;
    StatisticaGlobala stats;
public:
    explicit ConsiliuInalt(std::string numeLider);
    void adaugaHotel(HotelContinental h);
    void emiteExcommunicado(Asasin& a) const;
    void adaugaRegula(std::string regula);
    void afiseazaCodex() const;
    void genereazaRaportGlobal() const;
    void finanteazaHotel(size_t idx, int suma);
    void genereazaAuditFinanciar() const;
    void upgradeSecuritateGlobala();
    friend std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c) {
        os << "Consiliu administrat de " << c.lider << "\n Retea hoteliera:\n";
        for (const auto& h : c.reteaHoteliera) {
            os << "  -> " << h << "\n";
        }
        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c);

};


#endif //OOP_CONSILIUINALT_H