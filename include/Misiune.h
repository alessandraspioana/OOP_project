//
// Created by aless on 4/18/2026.
//

#ifndef OOP_MISIUNE_H
#define OOP_MISIUNE_H
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
    explicit Misiune(std::string desc, int dif, int bani);
    int getRecompensa() const;
    bool esteFinalizata() const;
    const std::string& getDescriere() const;
    void adaugaCerinta(std::string text);
    bool poateFiExecutata(int nivelAsasin) const;
    void finalizeaza();
    friend std::ostream& operator<<(std::ostream& os, const Misiune& m);

};


#endif //OOP_MISIUNE_H