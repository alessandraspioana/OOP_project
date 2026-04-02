#include "HotelContinental.h"
#include <iostream>
#include <algorithm>

HotelContinental::HotelContinental(const std::string& oras_, int goldInitial)
    : oras{oras_}, seifGold{goldInitial} {
    std::cout << "[SYSTEM] Hotelul Continental din " << oras << " a fost deschis.\n";
}

void HotelContinental::cazeaza(const Asasin& a) {
    oaspeti.push_back(a);
    std::cout << "[CHECK-IN] " << a.getNume() << " a primit o camera la " << oras << ".\n";
}

void HotelContinental::organizeazaDuel(size_t idx1, size_t idx2) {
    if (idx1 >= oaspeti.size() || idx2 >= oaspeti.size()) {
        std::cout << "[ERROR] Indici duel invalizi.\n";
        return;
    }

    std::cout << "\n--- REGULI CONTINENTAL: Duel intre " << oaspeti[idx1].getNume()
              << " si " << oaspeti[idx2].getNume() << " ---\n";

    oaspeti[idx1].ataca(oaspeti[idx2]);
    if (oaspeti[idx2].esteInViata()) {
        oaspeti[idx2].ataca(oaspeti[idx1]);
    }
}

void HotelContinental::evacueazaDecedatii() {
    size_t countInainte = oaspeti.size();

   auto it = std::remove_if(oaspeti.begin(), oaspeti.end(), [](const Asasin& a) {
       return !a.esteInViata();
   });

    oaspeti.erase(it, oaspeti.end());

    size_t eliminate = countInainte - oaspeti.size();
    if (eliminate > 0) {
        std::cout << "[CLEANUP] " << eliminate << " oaspeti eliminati.\n";
    }
}

void HotelContinental::adaugaMisiune(const Misiune& m) {
    avizierMisiuni.push_back(m);
}

void HotelContinental::executaContract(size_t idxAsasin, size_t idxMisiune) {
    if (idxAsasin >= oaspeti.size() || idxMisiune >= avizierMisiuni.size()) return;

    Asasin& asasin = oaspeti[idxAsasin];
    Misiune& misiune = avizierMisiuni[idxMisiune];

    if (misiune.esteFinalizata()) {
        std::cout << "[AVIZIER] Misiunea '" << misiune.getDescriere() << "' este deja luata.\n";
        return;
    }

    if (misiune.poateFiExecutata(10)) {
        std::cout << "[CONTRACT SUCCESS] " << asasin.getNume() << " a finalizat: " << misiune.getDescriere() << "\n";
        misiune.finalizeaza();
        seifGold -= misiune.getRecompensa();
        asasin.antrenament();
    } else {
        std::cout << "[CONTRACT FAILED] " << asasin.getNume() << " a esuat misiunea. HP scazut!\n";
        asasin.primesteDamage(15);
    }
}

void HotelContinental::afiseazaRegistru() const {
    std::cout << "\n--- REGISTRU OASPETI - CONTINENTAL " << oras << " ---\n";
    if (oaspeti.empty()) std::cout << "Niciun asasin cazat.\n";
    for (const auto& as : oaspeti) {
        std::cout << " > " << as << "\n";
    }
}

void HotelContinental::afiseazaAvizier() const {
    std::cout << "\n--- AVIZIER CONTRACTE ---\n";
    for (const auto& m : avizierMisiuni) {
        std::cout << " [!] " << m << "\n";
    }
}


std::ostream& operator<<(std::ostream& os, const HotelContinental& h) {
    os << "Continental " << h.oras << " | Resurse: " << h.seifGold << " gold | Oaspeti: " << h.oaspeti.size();
    return os;
}