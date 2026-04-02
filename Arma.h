//
// Created by aless on 4/2/2026.
//

#ifndef OOP_ARMA_H
#define OOP_ARMA_H


#pragma once
#include <string>
#include <iostream>

class Arma {
private:
    std::string model;
    int gloante;
    int capacitateMagazie;
    double uzura;

public:
    explicit Arma(const std::string& model_, int cap_ = 15);

    bool trage();
    void reincarca(int amunitie);
    void curataArma();

    int getGloante() const { return gloante; }
    bool esteBlocata() const { return uzura > 0.8; }

    friend std::ostream& operator<<(std::ostream& os, const Arma& a);
};


#endif //OOP_ARMA_H