//
// Created by aless on 6/21/2026.
//

#ifndef OOP_CODEXMANAGER_H
#define OOP_CODEXMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <string_view>

class CodexManager {
private:
    std::vector<std::string> legiSupreme;

    CodexManager() {
        legiSupreme.push_back("Ordinul 1: Nicio afacere de sange pe pamantul hotelului.");
        legiSupreme.push_back("Ordinul 2: Orice tura de Marcaj de Sange trebuie onorata.");
    }

public:
    CodexManager(const CodexManager&) = delete;
    CodexManager& operator=(const CodexManager&) = delete;

    static CodexManager& getInstanta() {
        static CodexManager instanta;
        return instanta;
    }

    void adaugaRegulaSuprema(std::string_view regula) {
        legiSupreme.emplace_back(regula);
    }

    void afiseazaCodexSuprem() const {
        std::cout << "\n======= CODEXUL SUPREM AL CONSILIULUI (SINGLETON) =======\n";
        for (const auto& regula : legiSupreme) {
            std::cout << "  [LEX] " << regula << "\n";
        }
        std::cout << "=========================================================\n";
    }
};

#endif //OOP_CODEXMANAGER_H