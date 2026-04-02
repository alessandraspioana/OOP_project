#include "ConsiliuInalt.h"
#include <iostream>
#include <iomanip>

ConsiliuInalt::ConsiliuInalt(const std::string& numeLider) 
    : lider(numeLider) {
    stats = {0, 0, 100000};
    reguliCodex.push_back("Nu se varsa sange pe domeniul Continental.");
    reguliCodex.push_back("Fiecare bilet trebuie onorat.");
}

void ConsiliuInalt::adaugaHotel(const HotelContinental& h) {
    reteaHoteliera.push_back(h);
    std::cout << "[HIGH TABLE] Hotel nou adaugat in retea sub supravegherea lui " << lider << ".\n";
}

void ConsiliuInalt::emiteExcommunicado(Asasin& a) {
    std::cout << "!!! [EXCOMMUNICADO] !!!\n";
    std::cout << "Asasinul " << a.getNume() << " a fost declarat inamic public.\n";
    std::cout << "Recompensa de 7 milioane de dolari a fost activata.\n";
    a.primesteDamage(99);
}

void ConsiliuInalt::adaugaRegula(const std::string& regula) {
    if (!regula.empty()) {
        reguliCodex.push_back(regula);
    }
}

void ConsiliuInalt::afiseazaCodex() const {
    std::cout << "\n========== CODEXUL CONSILIULUI ==========\n";
    for (size_t i = 0; i < reguliCodex.size(); ++i) {
        std::cout << i + 1 << ". " << reguliCodex[i] << "\n";
    }
    std::cout << "=========================================\n";
}

void ConsiliuInalt::genereazaRaportGlobal() const {
    std::cout << "\n--- RAPORT DE ACTIVITATE ---\n";
    std::cout << "Lider: " << lider << "\n";
    std::cout << "Hoteluri monitorizate: " << reteaHoteliera.size() << "\n";
    std::cout << "Fonduri de urgenta: " << stats.goldInCirculatie << " Gold Coins\n";
    
    for(const auto& h : reteaHoteliera) {
        std::cout << " > Detalii unitate: " << h << "\n";
    }
}

void ConsiliuInalt::finanteazaHotel(const size_t idx, const int suma) {
    if (idx < reteaHoteliera.size() && stats.goldInCirculatie >= suma) {
        reteaHoteliera[idx].aprovizionareSeif(suma);
        stats.goldInCirculatie -= suma;
        std::cout << "[FINANCE] Hotelul " << idx << " a primit " << suma << " unitati aur.\n";
    }
}

std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c) {
    os << "Consiliu Inalt administrat de " << c.lider << " | Reguli active: " << c.reguliCodex.size();
    return os;
}