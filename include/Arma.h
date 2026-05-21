//
// Created by aless on 4/17/2026.
//

#ifndef OOP_ARMA_H
#define OOP_ARMA_H
#include <deque>
#include <string>

class Arma {

private:
    std::string model;
    int gloante;
    int capacitateMagazie;
    double uzura;
    std::deque<int> istoricIncarcari;
public:
    explicit Arma(std::string model_ = "Glock", int cap_ = 10);
    bool trage();
    void reincarca(int amunitie);
    void curataArma();
    bool esteBlocata() const;
    int getGloante() const;
    friend std::ostream& operator<<(std::ostream& os, const Arma& a);
    void afiseazaIstoricMunitie() const;
};


#endif //OOP_ARMA_H