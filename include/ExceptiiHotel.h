//
// Created by aless on 5/22/2026.
//

#ifndef OOP_EXCEPTIIHOTEL_H
#define OOP_EXCEPTIIHOTEL_H

#include <exception>
#include <string>

class ContinentalException : public std::exception {
protected:
    std::string mesaj;
public:
    explicit ContinentalException(std::string m) : mesaj(std::move(m)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class GoldenRuleViolationException : public ContinentalException {
public:
    explicit GoldenRuleViolationException(const std::string& actiune)
        : ContinentalException("CONTRABANDA/VIOLENTA DETECTATA: Ati incercat sa efectuati '" + actiune + "' pe pamant sacru! Pedeapsa: EXCOMMUNICADO.") {}
};

class InsufficientGoldException : public ContinentalException {
public:
    InsufficientGoldException(int cerut, int disponibil)
        : ContinentalException("EROARE FINANCIARA: Fonduri insuficiente in Seif. Cerut: " + std::to_string(cerut) + " monede, Disponibil doar: " + std::to_string(disponibil) + ".") {}
};

class WeaponWeaponJamException : public ContinentalException {
public:
    explicit WeaponWeaponJamException(const std::string& modelArma)
        : ContinentalException("EROARE ARMA: Modelul '" + modelArma + "' are uzura maxima si s-a blocat critic! Necesita curatare imediata.") {}
};

#endif //OOP_EXCEPTIIHOTEL_H