#ifndef OOP_SISTEMSECURITATE_H
#define OOP_SISTEMSECURITATE_H

#include <string>
#include <vector>
#include <ostream>
#include <map>
#include <string_view>

class SistemSecuritate {
private:
    int nivelAlerta;
    bool scanereActive;
    std::vector<std::string> istoricIncidente;

    std::map<std::string, int> frecventaIncidentePeTip;
    std::vector<std::pair<std::string, std::string>> bazaDateSenzori;

    void autoCalibrare();
    void ruleazaDiagnosticSenzori();

public:
    explicit SistemSecuritate(int alertaInitiala = 1);

    void inregistreazaIncident(const std::string& tip, const std::string& detalii);
    void resetAlerta();
    void adaugaSenzorPerimetral(std::string_view zona, std::string_view tipSenzor);
    void simuleazaScanareCompleta() const;

    [[nodiscard]] std::string genereazaRaportSecuritateCurent() const;
    [[nodiscard]] bool esteIzolat() const;
    [[nodiscard]] int getNivelAlerta() const;
    [[nodiscard]] int getFrecventaIncident(std::string_view tip) const;

    friend std::ostream& operator<<(std::ostream& os, const SistemSecuritate& s) {
        os << "Securitate: [Nivel Alerta: " << s.nivelAlerta
           << " | Scanere: " << (s.scanereActive ? "ACTIVE" : "INACTIVE")
           << " | Incidente: " << s.istoricIncidente.size() << "]";
        return os;
    }
};

#endif //OOP_SISTEMSECURITATE_H