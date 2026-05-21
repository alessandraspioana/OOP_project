// HotelContinental.h
#ifndef OOP_HOTELCONTINENTAL_H
#define OOP_HOTELCONTINENTAL_H

#include "Misiune.h"
#include "SistemSecuritate.h"
#include "Asasin.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class HotelContinental {
private:
    std::string oras;
    std::vector<std::unique_ptr<Asasin>> oaspeti;
    std::vector<Misiune> avizierMisiuni;
    int seifGold;
    SistemSecuritate securitate;

public:
    explicit HotelContinental(std::string oras_, int goldInitial);

    void aprovizionareSeif(int suma);

    void cazeaza(std::unique_ptr<Asasin> a);

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