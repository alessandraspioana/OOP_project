#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <utility>


// aici am definirea claselor
class Arma {
private:
    std::string model;
    int gloante;
    int capacitateMagazie;
    double uzura;
public:
    explicit Arma(std::string model_, int cap_ = 15);

    [[nodiscard]] bool trage();
    void reincarca(int amunitie);
    void curataArma();

    [[nodiscard]] bool esteBlocata() const { return uzura > 0.8; }
    [[nodiscard]] int getGloante() const { return gloante; }

    friend std::ostream& operator<<(std::ostream& os, const Arma& a);
};

class Misiune {
private:
    std::string descriere;
    int dificultate;
    int recompensaGold;
    bool finalizata;
    std::vector<std::string> cerinte;
public:
    explicit Misiune(std::string desc, int dif, int bani);

    void adaugaCerinta(std::string text);
    [[nodiscard]] bool poateFiExecutata(int nivelAsasin) const;
    void finalizeaza();

    [[nodiscard]] int getRecompensa() const { return recompensaGold; }
    [[nodiscard]] bool esteFinalizata() const { return finalizata; }
    [[nodiscard]] const std::string& getDescriere() const { return descriere; }

    friend std::ostream& operator<<(std::ostream& os, const Misiune& m);
};

class Asasin {
private:
    std::string nume;
    int viata;
    int experienta;
    int nivel = 1;
    bool esteInfiltrat = false;
    Arma arma;
    std::vector<std::string> distinctii;
    std::vector<std::string> inventar;
public:
    explicit Asasin(std::string nume_, int viata_, Arma arma_);
    Asasin(const Asasin& other);
    Asasin& operator=(const Asasin& other);

    ~Asasin() = default;

    void ataca(Asasin& tinta);
    void primesteDamage(int dmg);
    void antrenament();
    void cresteExperienta(int puncte);
    void adaugaDistinctie(std::string numeDistinctie);
    void colecteazaItem(std::string item);
    void folosesteItem(std::string item);
    void activeazaModInfiltrare();
    void afiseazaStatusComplet() const;

    [[nodiscard]] bool esteInViata() const { return viata > 0; }
    [[nodiscard]] const std::string& getNume() const { return nume; }
    [[nodiscard]] int getNivel() const { return nivel; }
    [[nodiscard]] int getViata() const { return viata; }

    friend std::ostream& operator<<(std::ostream& os, const Asasin& as);
};

class HotelContinental {
private:
    std::string oras;
    std::vector<Asasin> oaspeti;
    std::vector<Misiune> avizierMisiuni;
    int seifGold;
public:
    explicit HotelContinental(std::string oras_, int goldInitial = 5000);
    void cazeaza(Asasin a);
    void organizeazaDuel(size_t idx1, size_t idx2);
    void evacueazaDecedatii();
    void adaugaMisiune(Misiune m);
    void executaContract(size_t idxAsasin, size_t idxMisiune);
    void afiseazaRegistru() const;
    void afiseazaAvizier() const;
    void aprovizionareSeif(int suma) { seifGold += suma; }

    friend std::ostream& operator<<(std::ostream& os, const HotelContinental& h);
};

class ConsiliuInalt {
private:
    struct StatisticaGlobala {
        int totalAsasini;
        int misiuniCompletate;
        int goldInCirculatie;
    };
    std::string lider;
    std::vector<HotelContinental> reteaHoteliera;
    std::vector<std::string> reguliCodex;
    StatisticaGlobala stats;
public:
    explicit ConsiliuInalt(std::string numeLider);
    void adaugaHotel(HotelContinental h);
    void emiteExcommunicado(Asasin& a);
    void adaugaRegula(std::string regula);
    void afiseazaCodex() const;
    void genereazaRaportGlobal() const;
    void finanteazaHotel(size_t idx, int suma);
    void genereazaAuditFinanciar() const;
    void upgradeSecuritateGlobala();

    friend std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c);
};

class BursaAsasinilor {
private:
    struct Bounty {
        std::string numeTinta;
        int recompensa;
        int periculozitate;
        bool esteActiv;
    };

    std::string sediuCentral;
    std::vector<Bounty> contracteDeschise;
    std::vector<std::string> istoricLichidari;
    int fondTotalPremii;

public:
    explicit BursaAsasinilor(std::string sediu, int fondInitial = 100000);

    void publicaBounty(std::string nume, int bani, int risc);
    void anuleazaBounty(const std::string& nume);

    [[nodiscard]] int calculeazaTaxaConsiliu(int suma) const;
    void proceseazaRecompensa(Asasin& vanator, size_t indexContract);

    void afiseazaCeleMaiCautateTinte() const;
    void genereazaStatisticiBursa() const;
    void suplimenteazaFonduri(int suma);

    [[nodiscard]] size_t getNumarContracte() const { return contracteDeschise.size(); }
    [[nodiscard]] const std::string& getSediu() const { return sediuCentral; }

    friend std::ostream& operator<<(std::ostream& os, const BursaAsasinilor& b);
};

// implementarea functiilor (ce  era inaitnein fisierele de cpp)
Arma::Arma(std::string model_, int cap_)
    : model{std::move(model_)},
      gloante{cap_},
      capacitateMagazie{cap_},
      uzura{0.0} {
}

bool Arma::trage() {
    if (gloante > 0 && !esteBlocata()) {
        gloante--;
        uzura += 0.02;
        return true;
    }
    return false;
}

void Arma::reincarca(int amunitie) {
    this->gloante += amunitie;
    if (this->gloante > this->capacitateMagazie) {
        this->gloante = this->capacitateMagazie;
    }
}

void Arma::curataArma() {
    this->uzura = 0.0;
}

std::ostream& operator<<(std::ostream& os, const Arma& a) {
    os << a.model << " [" << a.gloante << "/" << a.capacitateMagazie << "]";
    return os;
}

Misiune::Misiune(std::string desc, int dif, int bani)
    : descriere(std::move(desc)),
      dificultate(dif),
      recompensaGold(bani),
      finalizata(false) {
}

void Misiune::adaugaCerinta(std::string text) {
    this->cerinte.push_back(std::move(text));
}

bool Misiune::poateFiExecutata(int nivelAsasin) const {
    return (nivelAsasin >= this->dificultate) && (!this->finalizata);
}

void Misiune::finalizeaza() {
    this->finalizata = true;
}

std::ostream& operator<<(std::ostream& os, const Misiune& m) {
    os << m.descriere << " (Gold: " << m.recompensaGold << ")";
    return os;
}

Asasin::Asasin(std::string nume_, int viata_, Arma arma_)
    : nume{std::move(nume_)},
      viata{viata_},
      experienta{0},
      arma{std::move(arma_)} {
}

Asasin::Asasin(const Asasin& other)
    : nume{other.nume + " (Copy)"},
      viata{other.viata},
      experienta{other.experienta},
      arma{other.arma},
      distinctii{other.distinctii} {
}

Asasin& Asasin::operator=(const Asasin& other) {
    if (this != &other) {
        this->nume = other.nume;
        this->viata = other.viata;
        this->experienta = other.experienta;
        this->arma = other.arma;
        this->nivel = other.nivel;
        this->inventar = other.inventar;
        this->distinctii = other.distinctii;
    }
    return *this;
}

void Asasin::ataca(Asasin& tinta) {
    if (this->arma.trage()) {
        tinta.primesteDamage(25);
        this->cresteExperienta(10);
    }
}

void Asasin::primesteDamage(int dmg) {
    this->viata -= dmg;
    if (this->viata < 0) {
        this->viata = 0;
    }
}

void Asasin::antrenament() {
    this->experienta += 30;
    this->arma.curataArma();
}

void Asasin::cresteExperienta(int puncte) {
    this->experienta += puncte;
    if (this->experienta >= 100) {
        this->nivel++;
        this->experienta = 0;
    }
}

void Asasin::adaugaDistinctie(std::string numeDistinctie) {
    this->distinctii.push_back(std::move(numeDistinctie));
}

void Asasin::colecteazaItem(std::string item) {
    if (this->inventar.size() < 5) {
        this->inventar.push_back(std::move(item));
    }
}

void Asasin::folosesteItem(std::string item) {
    auto it = std::find(this->inventar.begin(), this->inventar.end(), item);
    if (it != this->inventar.end()) {
        if (item == "Trusa") {
            this->viata += 20;
        }
        this->inventar.erase(it);
    }
}

void Asasin::activeazaModInfiltrare() {
    this->esteInfiltrat = true;
}

void Asasin::afiseazaStatusComplet() const {
    std::cout << "Status: " << this->nume << " | Viata: " << this->viata
              << " | XP: " << this->experienta << " | LVL: " << this->nivel << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Asasin& as) {
    os << as.nume << " (HP: " << as.viata << ")";
    return os;
}

HotelContinental::HotelContinental(std::string oras_, int goldInitial)
    : oras{std::move(oras_)},
      seifGold{goldInitial} {
}

void HotelContinental::cazeaza(Asasin a) {
    this->oaspeti.push_back(std::move(a));
}

void HotelContinental::organizeazaDuel(size_t idx1, size_t idx2) {
    if (idx1 < this->oaspeti.size() && idx2 < this->oaspeti.size()) {
        this->oaspeti[idx1].ataca(this->oaspeti[idx2]);
    }
}

void HotelContinental::evacueazaDecedatii() {
    this->oaspeti.erase(
        std::remove_if(this->oaspeti.begin(), this->oaspeti.end(),
            [](const Asasin& a) { return !a.esteInViata(); }),
        this->oaspeti.end()
    );
}

void HotelContinental::adaugaMisiune(Misiune m) {
    this->avizierMisiuni.push_back(std::move(m));
}

void HotelContinental::executaContract(size_t idxAsasin, size_t idxMisiune) {
    if (idxAsasin < this->oaspeti.size() && idxMisiune < this->avizierMisiuni.size()) {
        if (this->avizierMisiuni[idxMisiune].poateFiExecutata(this->oaspeti[idxAsasin].getNivel())) {
            this->avizierMisiuni[idxMisiune].finalizeaza();
            this->seifGold -= this->avizierMisiuni[idxMisiune].getRecompensa();
        }
    }
}

void HotelContinental::afiseazaRegistru() const {
    std::cout << "--- Registru Hotel " << this->oras << " ---" << std::endl;
    for (const auto& as : this->oaspeti) {
        std::cout << " * " << as << std::endl;
    }
}

void HotelContinental::afiseazaAvizier() const {
    std::cout << "--- Avizier Hotel " << this->oras << " ---" << std::endl;
    for (const auto& ms : this->avizierMisiuni) {
        std::cout << " ! " << ms << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const HotelContinental& h) {
    os << "Hotel Continental " << h.oras << " [Seif: " << h.seifGold << "]";
    return os;
}

ConsiliuInalt::ConsiliuInalt(std::string numeLider)
    : lider(std::move(numeLider)),
      stats{0, 0, 100000} {
}

void ConsiliuInalt::adaugaHotel(HotelContinental h) {
    this->reteaHoteliera.push_back(std::move(h));
    this->stats.totalAsasini += 1;
    this->stats.misiuniCompletate += 0;
}

void ConsiliuInalt::emiteExcommunicado(Asasin& a) {
    std::cout << "Liderul " << this->lider << " emite ordinul!" << std::endl;
    a.primesteDamage(99);
}

void ConsiliuInalt::adaugaRegula(std::string regula) {
    this->reguliCodex.push_back(std::move(regula));
}

void ConsiliuInalt::afiseazaCodex() const {
    std::cout << "Codex administrat de " << this->lider << ":" << std::endl;
    for (const auto& r : this->reguliCodex) {
        std::cout << " - " << r << std::endl;
    }
}

void ConsiliuInalt::genereazaRaportGlobal() const {
    std::cout << "Raport lider: " << this->lider << std::endl;
    std::cout << "Fonduri: " << this->stats.goldInCirculatie << std::endl;
    std::cout << "Misiuni raportate la nivel global: " << this->stats.misiuniCompletate << std::endl;
}

void ConsiliuInalt::finanteazaHotel(size_t idx, int suma) {
    if (idx < this->reteaHoteliera.size() && this->stats.goldInCirculatie >= suma) {
        this->reteaHoteliera[idx].aprovizionareSeif(suma);
        this->stats.goldInCirculatie -= suma;
    }
}

void ConsiliuInalt::genereazaAuditFinanciar() const {
    std::cout << "Audit lider: " << this->lider << ". Unitati: "
              << this->reteaHoteliera.size() << std::endl;
}

void ConsiliuInalt::upgradeSecuritateGlobala() {
    this->stats.goldInCirculatie -= 1000;
    std::cout << "Upgrade activat de " << this->lider << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c) {
    os << "Consiliu administrat de " << c.lider;
    return os;
}

BursaAsasinilor::BursaAsasinilor(std::string sediu, int fondInitial)
    : sediuCentral(std::move(sediu)), fondTotalPremii(fondInitial) {
}

void BursaAsasinilor::publicaBounty(std::string nume, int bani, int risc) {
    Bounty nou = {std::move(nume), bani, risc, true};
    this->contracteDeschise.push_back(nou);
    std::cout << "[BURSA] Contract nou pe numele: " << nou.numeTinta << " | Recompensa: " << bani << std::endl;
}

void BursaAsasinilor::anuleazaBounty(const std::string& nume) {
    for (auto& b : this->contracteDeschise) {
        if (b.numeTinta == nume) {
            b.esteActiv = false;
            std::cout << "[BURSA] Contractul pentru " << nume << " a fost retras." << std::endl;
        }
    }
}

int BursaAsasinilor::calculeazaTaxaConsiliu(int suma) const {
    // Taxa de 10% pentru Consiliul Inalt
    return static_cast<int>(suma * 0.1);
}

void BursaAsasinilor::proceseazaRecompensa(Asasin& vanator, size_t indexContract) {
    if (indexContract >= this->contracteDeschise.size()) {
        std::cout << "[ERROR] Index contract invalid la Bursa." << std::endl;
        return;
    }

    Bounty& b = this->contracteDeschise[indexContract];
    if (b.esteActiv && vanator.esteInViata()) {
        int taxa = calculeazaTaxaConsiliu(b.recompensa);
        int sumaFinala = b.recompensa - taxa;

        this->fondTotalPremii -= b.recompensa;
        b.esteActiv = false;
        this->istoricLichidari.push_back(b.numeTinta);

        vanator.cresteExperienta(b.periculozitate * 20);
        vanator.adaugaDistinctie("Vânător de recompense: " + b.numeTinta);

        std::cout << "[RECOMPENSA] " << vanator.getNume() << " a incasat " << sumaFinala
                  << " Gold (Taxa Consiliu: " << taxa << ")" << std::endl;
    }
}

void BursaAsasinilor::afiseazaCeleMaiCautateTinte() const {
    std::cout << "\n--- MOST WANTED - SEDIU: " << this->sediuCentral << " ---" << std::endl;
    for (const auto& b : this->contracteDeschise) {
        if (b.esteActiv) {
            std::cout << " Tinta: " << std::setw(15) << b.numeTinta
                      << " | Premiu: " << b.recompensa << " | Risc: " << b.periculozitate << std::endl;
        }
    }
}

void BursaAsasinilor::genereazaStatisticiBursa() const {
    std::cout << "\n--- STATISTICI BURSA ---" << std::endl;
    std::cout << " Contracte finalizate: " << this->istoricLichidari.size() << std::endl;
    std::cout << " Fonduri ramase in seif: " << this->fondTotalPremii << std::endl;
    std::cout << " Ultima lichidare: " << (istoricLichidari.empty() ? "N/A" : istoricLichidari.back()) << std::endl;
}

void BursaAsasinilor::suplimenteazaFonduri(int suma) {
    this->fondTotalPremii += suma;
    std::cout << "[BURSA] Fonduri suplimentate cu " << suma << ". Total: " << this->fondTotalPremii << std::endl;
}

std::ostream& operator<<(std::ostream& os, const BursaAsasinilor& b) {
    os << "Bursa Asasinilor (" << b.sediuCentral << ") - Fonduri: " << b.fondTotalPremii;
    return os;
}

int main() {
    Arma glock("Glock", 10);
    glock.reincarca(5);
    glock.curataArma();
    bool a_tras = glock.trage();
    std::cout << "Foc tras: " << std::boolalpha << a_tras << " | Gloante: " << glock.getGloante() << std::endl;
    std::cout << "Blocata: " << glock.esteBlocata() << " | Info: " << glock << std::endl;

    Misiune m1("Eliminare VIP", 1, 500);
    m1.adaugaCerinta("Silențios");
    m1.finalizeaza();
    std::cout << "Misiune: " << m1.getDescriere() << " | Gold: " << m1.getRecompensa() << " | Gata: " << m1.esteFinalizata() << std::endl;
    std::cout << "Info: " << m1 << std::endl;

    Asasin john("John Wick", 100, glock);
    Asasin cassian("Cassian", 100, glock);

    Asasin copie = john;
    std::cout << "Copie: " << copie << std::endl;
    copie = cassian;
    std::cout << "Re-atribuire: " << copie << std::endl;

    john.activeazaModInfiltrare();
    john.colecteazaItem("Trusa");
    john.folosesteItem("Trusa");
    john.cresteExperienta(50);
    john.adaugaDistinctie("Legenda");
    john.antrenament();
    john.afiseazaStatusComplet();

    std::cout << "Nume: " << john.getNume() << " | LVL: " << john.getNivel() << " | HP: " << john.getViata() << " | Viu: " << john.esteInViata() << std::endl;

    HotelContinental hotel("NY", 10000);
    hotel.cazeaza(john);
    hotel.cazeaza(cassian);
    hotel.adaugaMisiune(m1);

    hotel.organizeazaDuel(0, 1);
    hotel.executaContract(0, 0);
    hotel.evacueazaDecedatii();
    hotel.aprovizionareSeif(2000);
    hotel.afiseazaRegistru();
    hotel.afiseazaAvizier();
    std::cout << "Info Hotel: " << hotel << std::endl;

    ConsiliuInalt consiliu("Adjudicator");
    consiliu.adaugaHotel(hotel);
    consiliu.adaugaRegula("Nicio afacere pe pamant sacru");
    consiliu.afiseazaCodex();
    consiliu.finanteazaHotel(0, 1000);
    consiliu.genereazaRaportGlobal();
    consiliu.genereazaAuditFinanciar();
    consiliu.upgradeSecuritateGlobala();
    consiliu.emiteExcommunicado(john);

    std::cout << "Status Consiliu: " << consiliu << std::endl;

    BursaAsasinilor bursa("Marrakech", 250000);
    bursa.publicaBounty("Iosef Tarasov", 50000, 4);
    bursa.publicaBounty("Santino D'Antonio", 150000, 9);

    bursa.afiseazaCeleMaiCautateTinte();

    bursa.proceseazaRecompensa(john, 0);

    bursa.suplimenteazaFonduri(10000);
    bursa.genereazaStatisticiBursa();

    std::cout << "Info Bursa: " << bursa << std::endl;
    std::cout << "Sediu: " << bursa.getSediu() << " | Contracte: " << bursa.getNumarContracte() << std::endl;

    bursa.anuleazaBounty("Santino D'Antonio");

    return 0;
}
