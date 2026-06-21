//
// Created by aless on 6/21/2026.
//

#ifndef OOP_CUTIEDEPOZIT_H
#define OOP_CUTIEDEPOZIT_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class CutieDepozit {
private:
    std::string codSecuritate;
    std::vector<T> elementeStocate;
    size_t capacitateMaxima;

public:
    CutieDepozit(std::string cod, size_t capacitate)
        : codSecuritate(std::move(cod)), capacitateMaxima(capacitate) {}

    void depoziteaza(const T& obiect) {
        if (elementeStocate.size() >= capacitateMaxima) {
            throw std::runtime_error("Seiful este plin! Nu se mai pot adauga elemente.");
        }
        elementeStocate.push_back(obiect);
        std::cout << "[SEIF] Element stocat cu succes in cutia securizata.\n";
    }

    void afiseazaContinut() const {
        std::cout << "--- Continut Cutie Depozit (Cod: " << codSecuritate << ") ---\n";
        for (size_t i = 0; i < elementeStocate.size(); ++i) {
            std::cout << "  * Pozitia " << i + 1 << ": " << elementeStocate[i] << "\n";
        }
        std::cout << "--------------------------------------------------\n";
    }

    size_t getDimensiune() const noexcept {
        return elementeStocate.size();
    }
};

template <typename T>
void comparaEficientaActive(const T& obiectA, const T& obiectB) {
    std::cout << "\n[TEMPLATE FUNCTION] Se ruleaza analizatorul generic de performanta...\n";
    if (obiectA > obiectB) {
        std::cout << " >> Primul obiect este mai eficient/puternic.\n";
    } else if (obiectB > obiectA) {
        std::cout << " >> Al doilea obiect are indicatori superiori.\n";
    } else {
        std::cout << " >> Ambele obiecte au aceeasi valoare operationala.\n";
    }
}

#endif //OOP_CUTIEDEPOZIT_H