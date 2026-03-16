#include <iostream>
#include <string>
#include <vector>

class Arma {
private:
    std::string model;
    int gloante;
public:
    explicit Arma(const std::string& model_, int gloante_ = 15)
        : model{model_}, gloante{gloante_} {}

    friend std::ostream& operator<<(std::ostream& os, const Arma& a) {
        os << "[" << a.model << " | Mag: " << a.gloante << "]";
        return os;
    }
};

class Asasin {
private:
    std::string nume;
    int viata;
    Arma arma;
public:
    explicit Asasin(const std::string& nume_, int viata_, const Arma& arma_)
        : nume{nume_}, viata{viata_}, arma{arma_} {}

    Asasin(const Asasin& other)
        : nume{other.nume + " (Copie)"}, viata{other.viata}, arma{other.arma} {}

    Asasin& operator=(const Asasin& other) {
        if (this != &other) {
            nume = other.nume;
            viata = other.viata;
            arma = other.arma;
        }
        return *this;
    }

    ~Asasin() = default;

    friend std::ostream& operator<<(std::ostream& os, const Asasin& as) {
        os << "Asasin: " << as.nume << " (HP: " << as.viata << ") -> " << as.arma;
        return os;
    }
};

class HotelContinental {
private:
    std::string oras;
    std::vector<Asasin> oaspeti;
public:
    explicit HotelContinental(const std::string& oras_) : oras{oras_} {}

    void cazeaza(const Asasin& a) {
        oaspeti.push_back(a);
    }

    void afiseazaRegistru() const {
        std::cout << "\n--- Registru Continental " << oras << " ---\n";
        for (const auto& asasin : oaspeti) {
            std::cout << " * " << asasin << "\n";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const HotelContinental& h) {
        os << "Hotel Continental " << h.oras << " (Oaspeti: " << h.oaspeti.size() << ")";
        return os;
    }
};

int main() {
    Arma hk{"HK P30", 15};
    Asasin john{"John Wick", 100, hk};
    Asasin perkins{"Ms. Perkins", 80, Arma{"Pistol cu amortizor", 10}};

    HotelContinental hotel{"New York"};
    hotel.cazeaza(john);
    hotel.cazeaza(perkins);

    hotel.afiseazaRegistru();
    std::cout << "\nStatus Hotel: " << hotel << "\n";

    Asasin asasinBasic{"Nimeni", 0, Arma{"Rugina", 0}};
    asasinBasic = john;
    std::cout << "Asasin generic dupa atribuire: " << asasinBasic << "\n";

    return 0;
}