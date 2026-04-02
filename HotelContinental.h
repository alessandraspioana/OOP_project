//
// Created by aless on 4/2/2026.
//

#ifndef OOP_HOTELCONTINENTAL_H
#define OOP_HOTELCONTINENTAL_H


#pragma once
#include <vector>
#include "Asasin.h"

class HotelContinental {
private:
    std::string oras;
    std::vector<Asasin> oaspeti;

public:
    explicit HotelContinental(const std::string& oras_);

    void cazeaza(const Asasin& a);
    void organizeazaDuel(int idx1, int idx2);
    void evacueazaDecedatii();
    void afiseazaRegistru() const;

    friend std::ostream& operator<<(std::ostream& os, const HotelContinental& h);
};


#endif //OOP_HOTELCONTINENTAL_H