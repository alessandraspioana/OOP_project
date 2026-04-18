#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <utility>

#include "Arma.h"
#include "Misiune.h"
#include "Asasin.h"
#include "SistemSecuritate.h"
#include "HotelContinental.h"
#include "ConsiliuInalt.h"
#include "BursaAsasinilor.h"


// aici am definirea claselor
// class Arma {
// private:
//     std::string model;
//     int gloante;
//     int capacitateMagazie;
//     double uzura;
// public:
//     explicit Arma(std::string model_, int cap_)
//     : model{std::move(model_)},
//       gloante{cap_},
//       capacitateMagazie{cap_},
//       uzura{0.0} {
//     }
//
//     [[nodiscard]] bool trage() {
//         if (gloante > 0 && !esteBlocata()) {
//             gloante--;
//             uzura += 0.02;
//             return true;
//         }
//         return false;
//     }
//
//     void reincarca(int amunitie) {
//         this->gloante += amunitie;
//         if (this->gloante > this->capacitateMagazie) {
//             this->gloante = this->capacitateMagazie;
//         }
//     }
//
//     void curataArma() {
//         this->uzura = 0.0;
//     }
//
//     [[nodiscard]] bool esteBlocata() const { return uzura > 0.8; }
//     [[nodiscard]] int getGloante() const { return gloante; }
//
//     friend std::ostream& operator<<(std::ostream& os, const Arma& a) {
//         os << a.model << " [" << a.gloante << "/" << a.capacitateMagazie << "]";
//         return os;
//     }
//
//
// };
//
// class Misiune {
// private:
//     std::string descriere;
//     int dificultate;
//     int recompensaGold;
//     bool finalizata;
//     std::vector<std::string> cerinte;
// public:
//
//     [[nodiscard]] int getRecompensa() const { return recompensaGold; }
//     [[nodiscard]] bool esteFinalizata() const { return finalizata; }
//     [[nodiscard]] const std::string& getDescriere() const { return descriere; }
//
//     explicit Misiune(std::string desc, int dif, int bani)
//     : descriere(std::move(desc)),
//       dificultate(dif),
//       recompensaGold(bani),
//       finalizata(false) {
//     }
//
//     void adaugaCerinta(std::string text) {
//         this->cerinte.push_back(std::move(text));
//     }
//
//     bool poateFiExecutata(int nivelAsasin) const {
//         return (nivelAsasin >= this->dificultate) && (!this->finalizata);
//     }
//
//     void finalizeaza() {
//         this->finalizata = true;
//     }
//
//     friend std::ostream& operator<<(std::ostream& os, const Misiune& m) {
//         os << m.descriere << " (Gold: " << m.recompensaGold << ")";
//         return os;
//     }
//
//
// };
//
// class Asasin {
// private:
//     std::string nume;
//     int viata;
//     int experienta;
//     int nivel = 1;
//     bool esteInfiltrat = false;
//     Arma arma;
//     std::vector<std::string> distinctii;
//     std::vector<std::string> inventar;
// public:
//
//     [[nodiscard]] bool esteInViata() const { return viata > 0; }
//     [[nodiscard]] const std::string& getNume() const { return nume; }
//     [[nodiscard]] int getNivel() const { return nivel; }
//     [[nodiscard]] int getViata() const { return viata; }
//
//
//     explicit Asasin(std::string nume_, int viata_, Arma arma_)
//         : nume{std::move(nume_)},
//           viata{viata_},
//           experienta{0},
//           nivel{1},
//           arma{std::move(arma_)} {
//     }
//
//     Asasin(const Asasin& other)
//         : nume{other.nume + " (Copy)"},
//           viata{other.viata},
//           experienta{other.experienta},
//           nivel{other.nivel},
//           arma{other.arma},
//           distinctii{other.distinctii},
//           inventar{other.inventar} {
//     }
//
//     Asasin& operator=(const Asasin& other) {
//         if (this != &other) {
//             this->nume = other.nume;
//             this->viata = other.viata;
//             this->experienta = other.experienta;
//             this->arma = other.arma;
//             this->nivel = other.nivel;
//             this->inventar = other.inventar;
//             this->distinctii = other.distinctii;
//         }
//         return *this;
//     }
//
//     void ataca(Asasin& tinta) {
//     if (this->arma.trage()) {
//         tinta.primesteDamage(25);
//         this->cresteExperienta(10);
//     }
//     }
//
//     void primesteDamage(int dmg) {
//     this->viata -= dmg;
//     if (this->viata < 0) {
//         this->viata = 0;
//     }
//     }
//
//     void antrenament() {
//     this->experienta += 30;
//     this->arma.curataArma();
//     }
//
//     void cresteExperienta(int puncte) {
//     this->experienta += puncte;
//     if (this->experienta >= 100) {
//         this->nivel++;
//         this->experienta = 0;
//     }
//     }
//
//     void adaugaDistinctie(const std::string& numeDistinctie) {
//     this->distinctii.push_back(std::move(numeDistinctie));
//     }
//
//     void colecteazaItem(const std::string& item) {
//     if (this->inventar.size() < 5) {
//         this->inventar.push_back(std::move(item));
//     }
//     }
//
//     void folosesteItem(const std::string& item) {
//     auto it = std::find(this->inventar.begin(), this->inventar.end(), item);
//     if (it != this->inventar.end()) {
//         if (item == "Trusa") {
//             this->viata += 20;
//         }
//         this->inventar.erase(it);
//     }
//     }
//
//     void activeazaModInfiltrare() {
//     this->esteInfiltrat = true;
//     }
//
//     void afiseazaStatusComplet() const {
//         std::cout << "Status: " << this->nume << " | Viata: " << this->viata
//                   << " | XP: " << this->experienta << " | LVL: " << this->nivel << std::endl;
//     }
//
//     void evalueazaTitluOnorific() {
//         std::cout << "[RANKING] Se evalueaza rangul pentru " << this->nume << "..." << std::endl;
//
//         if (this->nivel > 10 && this->distinctii.size() > 3) {
//             this->adaugaDistinctie("Grandmaster of the Continental");
//         } else if (this->nivel > 5) {
//             this->adaugaDistinctie("Elite Operative");
//         } else {
//             std::cout << " > Rang actual: Ucenic (necesita mai multa experienta)." << std::endl;
//         }
//
//         double putereRelativa = (this->viata * 0.4) + (this->nivel * 10.0);
//         std::cout << " > Indice de periculozitate calculat: " << std::fixed << std::setprecision(2)
//                   << putereRelativa << std::endl;
//     }
//
//         [[nodiscard]] std::string getDescriereRang() const {
//         if (this->nivel >= 10) return "Legenda Vie";
//         if (this->nivel >= 5) return "Profesionist";
//         return "Incepator";
//     }
//
//         friend std::ostream& operator<<(std::ostream& os, const Asasin& as) {
//         os << as.nume << " (HP: " << as.viata << ")";
//         return os;
//     }
//     ~Asasin() {
//
//     }
//     };
//
// class SistemSecuritate {
// private:
//     int nivelAlerta;
//     bool scanereActive;
//     std::vector<std::string> istoricIncidente;
//
//     void autoCalibrare() {
//         if (nivelAlerta >= 4) {
//             scanereActive = true;
//             std::cout << "[SECURITY] Protocol de scanare avansata ACTIVAT.\n";
//         } else {
//             scanereActive = false;
//         }
//     }
//
// public:
//     explicit SistemSecuritate(int alertaInitiala = 1)
//         : nivelAlerta(alertaInitiala), scanereActive(false) {}
//
//     void inregistreazaIncident(const std::string& tip, const std::string& detalii) {
//         std::string entry = "[" + tip + "] " + detalii;
//         istoricIncidente.push_back(entry);
//
//         if (tip == "VIOLENTA" && nivelAlerta < 5) {
//             nivelAlerta++;
//         }
//         autoCalibrare();
//     }
//
//     void resetAlerta() {
//         nivelAlerta = 1;
//         scanereActive = false;
//         istoricIncidente.push_back("[SYSTEM] Alerta resetata manual.");
//         std::cout << "[SECURITY] Sistemul a fost resetat la starea initiala.\n";
//     }
//
//     [[nodiscard]] bool esteIzolat() const {
//         return scanereActive;
//     }
//
//     [[nodiscard]] int getNivelAlerta() const {
//         return nivelAlerta;
//     }
//
//     friend std::ostream& operator<<(std::ostream& os, const SistemSecuritate& s) {
//         os << "Securitate: [Nivel Alerta: " << s.nivelAlerta
//            << " | Scanere: " << (s.scanereActive ? "ACTIVE" : "INACTIVE")
//            << " | Incidente: " << s.istoricIncidente.size() << "]";
//         return os;
//     }
//
// };
//
// class HotelContinental {
// private:
//     std::string oras;
//     std::vector<Asasin> oaspeti;
//     std::vector<Misiune> avizierMisiuni;
//     int seifGold;
//     SistemSecuritate securitate;
//
// public:
//     void aprovizionareSeif(int suma) { seifGold += suma; }
//
//     explicit HotelContinental(std::string oras_, int goldInitial)
//         : oras{std::move(oras_)},
//           seifGold{goldInitial},
//           securitate{1} {
//     }
//
//     void cazeaza(const Asasin& a) {
//         securitate.inregistreazaIncident("ADMIN", "Cazare noua: " + a.getNume());
//         this->oaspeti.push_back(a);
//     }
//
//     void organizeazaDuel(size_t idx1, size_t idx2) {
//         if (idx1 < this->oaspeti.size() && idx2 < this->oaspeti.size()) {
//             securitate.inregistreazaIncident("VIOLENTA", "Duel intre " + oaspeti[idx1].getNume() + " si " + oaspeti[idx2].getNume());
//             this->oaspeti[idx1].ataca(this->oaspeti[idx2]);
//         }
//     }
//
//     void evacueazaDecedatii() {
//         this->oaspeti.erase(
//             std::remove_if(this->oaspeti.begin(), this->oaspeti.end(),
//                 [this](const Asasin& a) {
//                     if (!a.esteInViata()) {
//                         securitate.inregistreazaIncident("CURATENIE", "Evacuare corp: " + a.getNume());
//                         return true;
//                     }
//                     return false;
//                 }),
//             this->oaspeti.end()
//         );
//     }
//
//     void adaugaMisiune(Misiune m) {
//         this->avizierMisiuni.push_back(std::move(m));
//     }
//
//     void executaContract(size_t idxAsasin, size_t idxMisiune) {
//         if (idxAsasin < this->oaspeti.size() && idxMisiune < this->avizierMisiuni.size()) {
//             if (this->avizierMisiuni[idxMisiune].poateFiExecutata(this->oaspeti[idxAsasin].getNivel())) {
//                 securitate.inregistreazaIncident("CONTRACT", oaspeti[idxAsasin].getNume() + " a finalizat o misiune.");
//                 this->avizierMisiuni[idxMisiune].finalizeaza();
//                 this->seifGold -= this->avizierMisiuni[idxMisiune].getRecompensa();
//             }
//         }
//     }
//
//     void afiseazaRegistru() const {
//         std::cout << "--- Registru Hotel " << this->oras << " ---" << std::endl;
//         for (const auto& as : this->oaspeti) {
//             std::cout << " * " << as << std::endl;
//         }
//     }
//
//     void afiseazaAvizier() const {
//         std::cout << "--- Avizier Hotel " << this->oras << " ---" << std::endl;
//         for (const auto& ms : this->avizierMisiuni) {
//             std::cout << " ! " << ms << std::endl;
//         }
//     }
//
//     void simuleazaNoapteInHotel() {
//         std::cout << "\n[EVENT] Noaptea cade peste hotelul din " << this->oras << "..." << std::endl;
//
//         if (securitate.esteIzolat()) {
//             std::cout << " > HOTELUL ESTE IZOLAT. Masuri stricte de paza." << std::endl;
//         }
//
//         if (this->oaspeti.empty()) {
//             std::cout << " > Hotelul este pustiu. Liniste deplina." << std::endl;
//             return;
//         }
//
//         for (auto& as : this->oaspeti) {
//             if (as.getViata() < 50) {
//                 std::cout << " > " << as.getNume() << " primeste ingrijiri medicale de urgenta." << std::endl;
//                 as.folosesteItem("Trusa");
//             } else {
//                 std::cout << " > " << as.getNume() << " se odihneste. Recuperare usoara." << std::endl;
//                 as.primesteDamage(-5);
//             }
//         }
//
//         this->seifGold += 100;
//         std::cout << " > Taxe de noapte colectate. Seif nou: " << this->seifGold << std::endl;
//     }
//
//     friend std::ostream& operator<<(std::ostream& os, const HotelContinental& h) {
//         os << "Hotel Continental " << h.oras << " [Seif: " << h.seifGold << "]\n";
//         os << "  L " << h.securitate;
//         return os;
//     }
//
//
// };
//
// class ConsiliuInalt {
// private:
//     struct StatisticaGlobala {
//         int totalAsasini;
//         int misiuniCompletate;
//         int goldInCirculatie;
//     };
//     std::string lider;
//     std::vector<HotelContinental> reteaHoteliera;
//     std::vector<std::string> reguliCodex;
//     StatisticaGlobala stats;
// public:
//
//     friend std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c);
//
//     explicit ConsiliuInalt(std::string numeLider)
//     : lider(std::move(numeLider)),
//       stats{0, 0, 100000} {
//     }
//
//     void adaugaHotel(HotelContinental h) {
//         this->reteaHoteliera.push_back(std::move(h));
//         this->stats.totalAsasini += 1;
//         this->stats.misiuniCompletate += 0;
//     }
//
//     void emiteExcommunicado(Asasin& a) const {
//         std::cout << "Liderul " << this->lider << " emite ordinul!" << std::endl;
//         a.primesteDamage(99);
//     }
//
//     void adaugaRegula(std::string regula) {
//         this->reguliCodex.push_back(std::move(regula));
//     }
//
//     void afiseazaCodex() const {
//         std::cout << "Codex administrat de " << this->lider << ":" << std::endl;
//         for (const auto& r : this->reguliCodex) {
//             std::cout << " - " << r << std::endl;
//         }
//     }
//
//     void genereazaRaportGlobal() const {
//         std::cout << "Raport lider: " << this->lider << std::endl;
//         std::cout << "Fonduri: " << this->stats.goldInCirculatie << std::endl;
//         std::cout << "Misiuni raportate la nivel global: " << this->stats.misiuniCompletate << std::endl;
//     }
//
//     void finanteazaHotel(size_t idx, int suma) {
//         if (idx < this->reteaHoteliera.size() && this->stats.goldInCirculatie >= suma) {
//             this->reteaHoteliera[idx].aprovizionareSeif(suma);
//             this->stats.goldInCirculatie -= suma;
//         }
//     }
//
//     void genereazaAuditFinanciar() const {
//         std::cout << "Audit lider: " << this->lider << ". Unitati: "
//                   << this->reteaHoteliera.size() << std::endl;
//     }
//
//     void upgradeSecuritateGlobala() {
//         this->stats.goldInCirculatie -= 1000;
//         std::cout << "Upgrade activat de " << this->lider << std::endl;
//     }
//
//     friend std::ostream& operator<<(std::ostream& os, const ConsiliuInalt& c) {
//         os << "Consiliu administrat de " << c.lider << "\n Retea hoteliera:\n";
//         for (const auto& h : c.reteaHoteliera) {
//             os << "  -> " << h << "\n";
//         }
//         return os;
//     }
//
// };
//
// class BursaAsasinilor {
// private:
//     struct Bounty {
//         std::string numeTinta;
//         int recompensa;
//         int periculozitate;
//         bool esteActiv;
//     };
//
//     std::string sediuCentral;
//     std::vector<Bounty> contracteDeschise;
//     std::vector<std::string> istoricLichidari;
//     int fondTotalPremii;
//
// public:
//
//     [[nodiscard]] size_t getNumarContracte() const { return contracteDeschise.size(); }
//     [[nodiscard]] const std::string& getSediu() const { return sediuCentral; }
//
//     explicit BursaAsasinilor(std::string sediu, int fondInitial)
//     : sediuCentral(std::move(sediu)), fondTotalPremii(fondInitial) {
// }
//
//     void publicaBounty(std::string nume, int bani, int risc) {
//         Bounty nou = {std::move(nume), bani, risc, true};
//         this->contracteDeschise.push_back(nou);
//         std::cout << "[BURSA] Contract nou pe numele: " << nou.numeTinta << " | Recompensa: " << bani << std::endl;
//     }
//
//     void anuleazaBounty(const std::string& nume) {
//         for (auto& b : this->contracteDeschise) {
//             if (b.numeTinta == nume) {
//                 b.esteActiv = false;
//                 std::cout << "[BURSA] Contractul pentru " << nume << " a fost retras." << std::endl;
//             }
//         }
//     }
//
//     int calculeazaTaxaConsiliu(int suma) const {
//         if (this->sediuCentral.empty()) {
//             return 0;
//         }
//
//         return static_cast<int>(suma * 0.1);
//     }
//
//     void proceseazaRecompensa(Asasin& vanator, size_t indexContract) {
//         if (indexContract >= this->contracteDeschise.size()) {
//             std::cout << "[ERROR] Index contract invalid la Bursa." << std::endl;
//             return;
//         }
//
//         Bounty& b = this->contracteDeschise[indexContract];
//         if (b.esteActiv && vanator.esteInViata()) {
//             int taxa = calculeazaTaxaConsiliu(b.recompensa);
//             int sumaFinala = b.recompensa - taxa;
//
//             this->fondTotalPremii -= b.recompensa;
//             b.esteActiv = false;
//             this->istoricLichidari.push_back(b.numeTinta);
//
//             vanator.cresteExperienta(b.periculozitate * 20);
//             vanator.adaugaDistinctie("Vânător de recompense: " + b.numeTinta);
//
//             std::cout << "[RECOMPENSA] " << vanator.getNume() << " a incasat " << sumaFinala
//                       << " Gold (Taxa Consiliu: " << taxa << ")" << std::endl;
//         }
//     }
//
//     void afiseazaCeleMaiCautateTinte() const {
//         std::cout << "\n--- MOST WANTED - SEDIU: " << this->sediuCentral << " ---" << std::endl;
//         for (const auto& b : this->contracteDeschise) {
//             if (b.esteActiv) {
//                 std::cout << " Tinta: " << std::setw(15) << b.numeTinta
//                           << " | Premiu: " << b.recompensa << " | Risc: " << b.periculozitate << std::endl;
//             }
//         }
//     }
//
//     void genereazaStatisticiBursa() const {
//         std::cout << "\n--- STATISTICI BURSA ---" << std::endl;
//         std::cout << " Contracte finalizate: " << this->istoricLichidari.size() << std::endl;
//         std::cout << " Fonduri ramase in seif: " << this->fondTotalPremii << std::endl;
//         std::cout << " Ultima lichidare: " << (istoricLichidari.empty() ? "N/A" : istoricLichidari.back()) << std::endl;
//     }
//
//     void suplimenteazaFonduri(int suma) {
//         this->fondTotalPremii += suma;
//         std::cout << "[BURSA] Fonduri suplimentate cu " << suma << ". Total: " << this->fondTotalPremii << std::endl;
//     }
//
//     friend std::ostream& operator<<(std::ostream& os, const BursaAsasinilor& b) {
//         os << "Bursa Asasinilor (" << b.sediuCentral << ") - Fonduri: " << b.fondTotalPremii;
//         return os;
//     }
//
// };


int main() {

    std::string numeModel = "Glock", numeAsasin = "John Wick";
    int capacitate = 10, hp = 100;

    std::cout << "Introduceti model arma, capacitate, nume asasin si HP : " << std::endl;

    if (!(std::cin >> numeModel >> capacitate >> numeAsasin >> hp)) {
        std::cout << "Citire incompleta/invalida. Se folosesc valorile implicite acolo unde citirea a esuat." << std::endl;
        std::cin.clear();
    }
    std::cout << "Model: " << numeModel << std::endl;
    std::cout << "Capacitate: " << capacitate << std::endl;
    std::cout << "Nume asasin: " << numeAsasin << std::endl;
    std::cout << "HP: " << hp << std::endl;

    Arma glock(numeModel, capacitate);

    glock.reincarca(5);
    glock.curataArma();
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

    Asasin john(numeAsasin, hp, glock);
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

    std::cout << "\n========== TESTARE SISTEM AVANSAT ==========\n";

    john.cresteExperienta(500);
    john.evalueazaTitluOnorific();
    std::cout << "Rang John: " << john.getDescriereRang() << std::endl;

    hotel.cazeaza(john);
    hotel.simuleazaNoapteInHotel();

    consiliu.genereazaAuditFinanciar();

    std::cout << "\n[SUCCESS] Toate sistemele sunt operationale." << std::endl;
    std::cout << "============================================\n";

    hotel.organizeazaDuel(0, 1);

    std::cout << hotel << std::endl;

    hotel.simuleazaNoapteInHotel();

    SistemSecuritate testSec(1);
    testSec.inregistreazaIncident("TEST", "Verificare cppcheck");
    int nivel = testSec.getNivelAlerta();
    bool izolat = testSec.esteIzolat();
    testSec.resetAlerta();

    std::cout << "Sistem test: Nivel " << nivel << ", Izolare: " << std::boolalpha << izolat << std::endl;

    return 0;
}
