//
// Created by aless on 4/18/2026.
//

#ifndef OOP_SISTEMSECURITATE_H
#define OOP_SISTEMSECURITATE_H
#include <string>
#include <vector>
#include <ostream>


class SistemSecuritate {

private:
    int nivelAlerta;
    bool scanereActive;
    std::vector<std::string> istoricIncidente;

    void autoCalibrare();

public:
    explicit SistemSecuritate(int alertaInitiala = 1);
    void inregistreazaIncident(const std::string& tip, const std::string& detalii);
    void resetAlerta();
    [[nodiscard]] bool esteIzolat() const;
    [[nodiscard]] int getNivelAlerta() const;
    friend std::ostream& operator<<(std::ostream& os, const SistemSecuritate& s) {
        os << "Securitate: [Nivel Alerta: " << s.nivelAlerta
           << " | Scanere: " << (s.scanereActive ? "ACTIVE" : "INACTIVE")
           << " | Incidente: " << s.istoricIncidente.size() << "]";
        return os;
    }

};


#endif //OOP_SISTEMSECURITATE_H