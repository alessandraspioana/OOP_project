//
// Created by aless on 4/18/2026.
//

#ifndef OOP_HOTELCONTINENTAL_H
#define OOP_HOTELCONTINENTAL_H
#include "Misiune.h"
#include "SistemSecuritate.h"
#include <iostream>


class Asasin;

class HotelContinental {

private:
    std::string oras;
    std::vector<Asasin> oaspeti;
    std::vector<Misiune> avizierMisiuni;
    int seifGold;
    SistemSecuritate securitate;

public:
    void aprovizionareSeif(int suma);
    explicit HotelContinental(std::string oras_, int goldInitial);
    void cazeaza(const Asasin& a);
    void organizeazaDuel(size_t idx1, size_t idx2);
    void evacueazaDecedatii();
    void adaugaMisiune(Misiune m);
    void executaContract(size_t idxAsasin, size_t idxMisiune);
    void afiseazaRegistru() const;
    void afiseazaAvizier() const;
    void simuleazaNoapteInHotel();
    friend std::ostream& operator<<(std::ostream& os, const HotelContinental& h) {
        os << "Hotel Continental " << h.oras << " [Seif: " << h.seifGold << "]\n";
        os << "  L " << h.securitate;
        return os;
    }
};


#endif //OOP_HOTELCONTINENTAL_H