//
// Created by aless on 5/22/2026.
//

#ifndef OOP_ASASINBOUNTYHUNTER_H
#define OOP_ASASINBOUNTYHUNTER_H

#include "Asasin.h"
#include <vector>

class AsasinBountyHunter : public Asasin {
private:
    int contracteFinalizate;
    std::vector<std::string> tinteUrmarite;

public:
    AsasinBountyHunter(std::string nume_, int viata_, Arma arma_, int contracte = 0);

    std::unique_ptr<Asasin> clone() const override;
    void executaAbilitateSpeciala() override;
    void adaugaTintaInUrmarire(const std::string& numeTinta);

protected:
    void afiseazaDetalii(std::ostream& os) const override;
};

#endif // OOP_ASASINBOUNTYHUNTER_H