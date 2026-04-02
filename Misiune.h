//
// Created by aless on 4/2/2026.
//

#ifndef OOP_MISIUNE_H
#define OOP_MISIUNE_H


#pragma once
#include <string>
#include <vector>

class Misiune {
private:
    std::string descriere;
    int dificultate;
    int recompensaGold;
    bool finalizata;
    std::vector<std::string> cerinte;

public:
    explicit Misiune(const std::string& desc, int dif, int bani);

    // Funcționalități netriviale
    void adaugaCerinta(const std::string& text);
    bool poateFiExecutata(int nivelAsasin) const;
    void finalizeaza();

    // Getters
    int getRecompensa() const { return recompensaGold; }
    bool esteFinalizata() const { return finalizata; }
    const std::string& getDescriere() const { return descriere; }

    friend std::ostream& operator<<(std::ostream& os, const Misiune& m);
};


#endif //OOP_MISIUNE_H