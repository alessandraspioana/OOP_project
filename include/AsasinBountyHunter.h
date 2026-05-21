//
// Created by aless on 5/22/2026.
//

#ifndef OOP_ASASINBOUNTYHUNTER_H
#define OOP_ASASINBOUNTYHUNTER_H

#include "Asasin.h"

class AsasinBountyHunter : public Asasin {
private:
    int contracteFinalizate;
public:
    AsasinBountyHunter(std::string nume_, int viata_, Arma arma_, int contracte = 0);
    std::unique_ptr<Asasin> clone() const override;
    void executaAbilitateSpeciala() override;
protected:
    void afiseazaDetalii(std::ostream& os) const override;
};
#endif