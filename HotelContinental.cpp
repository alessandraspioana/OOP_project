//
// Created by aless on 4/2/2026.
//

#include "HotelContinental.h"

#include <iostream>
#include <algorithm>

HotelContinental::HotelContinental(const std::string& oras_) : oras{oras_} {}

void HotelContinental::cazeaza(const Asasin& a) {
    oaspeti.push_back(a);
    std::cout << "[HOTEL] " << a.getNume() << " s-a cazat la Continental " << oras << ".\n";
}

void HotelContinental::organizeazaDuel(int idx1, int idx2) {
    if (idx1 < oaspeti.size() && idx2 < oaspeti.size()) {
        std::cout << "\n--- DUEL IN " << oras << " ---\n";
        oaspeti[idx1].ataca(oaspeti[idx2]);
        oaspeti[idx2].ataca(oaspeti[idx1]);
    }
}

void HotelContinental::evacueazaDecedatii() {

    auto it = std::remove_if(oaspeti.begin(), oaspeti.end(),
        [](const Asasin& a) { return !a.esteInViata(); });

    if (it != oaspeti.end()) {
        std::cout << "[HOTEL] Au fost evacuate cadavrele din Continental.\n";
        oaspeti.erase(it, oaspeti.end());
    }
}

void HotelContinental::afiseazaRegistru() const {
    std::cout << "\n--- REGISTRU " << oras << " ---\n";
    for (const auto& asasin : oaspeti) {
        std::cout << " * " << asasin << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const HotelContinental& h) {
    os << "Hotel Continental " << h.oras << " | Oaspeti activi: " << h.oaspeti.size();
    return os;
}