//
// Created by aless on 5/21/2026.
//

//
// Created by aless on 5/21/2026.
//

#ifndef OOP_ASASINELITE_H
#define OOP_ASASINELITE_H

#include "Asasin.h"

class AsasinElite : public Asasin {
private:
    double multiplicatorDamage;
    int puncteCombo{0};
    const int limitaComboMax{5};

public:
    AsasinElite(std::string nume_, int viata_, Arma arma_, double mult = 1.5);

    std::unique_ptr<Asasin> clone() const override;
    void executaAbilitateSpeciala() override;

protected:
    void afiseazaDetalii(std::ostream& os) const override;
};

#endif // OOP_ASASINELITE_H