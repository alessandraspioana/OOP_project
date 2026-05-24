//
// Created by aless on 5/22/2026.
//


#ifndef OOP_ASASININFILTRAT_H
#define OOP_ASASININFILTRAT_H

#include "Asasin.h"

class AsasinInfiltrat : public Asasin {
private:
    std::string mascaCurenta;
    int nivelSuspiciune{0};

public:
    AsasinInfiltrat(std::string nume_, int viata_, Arma arma_, std::string masca = "Civil");

    std::unique_ptr<Asasin> clone() const override;
    void executaAbilitateSpeciala() override;

protected:
    void afiseazaDetalii(std::ostream& os) const override;
};

#endif // OOP_ASASININFILTRAT_H