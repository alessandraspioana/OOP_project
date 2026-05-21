//
// Created by aless on 5/22/2026.
//

#ifndef OOP_ASASINBAZASECRETA_H
#define OOP_ASASINBAZASECRETA_H

#include "Asasin.h"
#include <string_view>
#include <map>
#include <initializer_list>

class AsasinBazaSecreta : public Asasin {
private:
    std::string gadgetSpecial;
    int nivelBaterieGadget{100};
    bool protocolSecuritateActivat{false};

    std::map<std::string, double> istoricUpgradeuri;

public:
    AsasinBazaSecreta(std::string_view nume_, int viata_, Arma arma_, std::string_view gadget = "Ochelari Night-Vision v2");

    [[nodiscard]] std::unique_ptr<Asasin> clone() const override;

    void executaAbilitateSpeciala() override;

    void instaleazaUpgradeTehnologic(std::string_view denumireUpgrade, double coeficientEficienta);
    void incarcaBaterieGadget(int procentaj) noexcept;
    void comutaProtocolSecuritate() noexcept;
    [[nodiscard]] bool detineUpgrade(std::string_view denumireUpgrade) const;

protected:
    void afiseazaDetalii(std::ostream& os) const override;
};

#endif //OOP_ASASINBAZASECRETA_H


