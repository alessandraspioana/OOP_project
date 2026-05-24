// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <memory>

#include "Arma.h"
#include "Misiune.h"
#include "Asasin.h"
#include "AsasinBazaSecreta.h"
#include "AsasinElite.h"
#include "AsasinInfiltrat.h"
#include "AsasinBountyHunter.h"
#include "SistemSecuritate.h"
#include "HotelContinental.h"
#include "ConsiliuInalt.h"
#include "BursaAsasinilor.h"
#include "ExceptiiHotel.h"

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

    //auto john = std::make_unique<AsasinElite>(numeAsasin, hp, glock, 2.5);
    //auto cassian = std::make_unique<AsasinInfiltrat>("Cassian", 100, glock, "Costum Elegant");

    auto john = std::make_unique<AsasinElite>(numeAsasin, hp, glock, 2.5);
    auto cassian = std::make_unique<AsasinInfiltrat>("Cassian", 100, glock, "Costum Elegant");
    auto tracker = std::make_unique<AsasinBountyHunter>("Tracker", 120, glock, 0);

    tracker->adaugaTintaInUrmarire("Santino D'Antonio");

    std::unique_ptr<Asasin> copie = john->clone();
    std::cout << "Copie clonata polimorfic: " << *copie << std::endl;

    copie = cassian->clone();
    std::cout << "Re-atribuire polimorfica: " << *copie << std::endl;


    glock.afiseazaIstoricMunitie();

    std::cout << "Copie clonata polimorfic: " << *copie << std::endl;

    copie = cassian->clone();
    std::cout << "Re-atribuire polimorfica: " << *copie << std::endl;

    john->activeazaModInfiltrare();
    john->colecteazaItem("Trusa");
    john->folosesteItem("Trusa");
    john->cresteExperienta(50);
    john->adaugaDistinctie("Legenda");
    john->antrenament();
    john->afiseazaStatusComplet();

    std::cout << "Nume: " << john->getNume() << " | LVL: " << john->getNivel() << " | HP: " << john->getViata() << " | Viu: " << john->esteInViata() << std::endl;

    HotelContinental hotel("NY", 10000);

    hotel.cazeaza(std::move(john));
    hotel.cazeaza(std::move(cassian));
    hotel.adaugaMisiune(m1);

    hotel.organizeazaDuel(0, 1);
    hotel.executaContract(0, 0);
    hotel.evacueazaDecedatii();
    hotel.aprovizionareSeif(2000);
    hotel.afiseazaRegistru();
    hotel.afiseazaAvizier();
    std::cout << "Info Hotel: " << hotel << std::endl;

    ConsiliuInalt consiliu("Adjudicator");
    consiliu.adaugaHotel(std::move(hotel));
    consiliu.adaugaRegula("Nicio afacere pe pamant sacru");
    consiliu.afiseazaCodex();
    consiliu.finanteazaHotel(0, 1000);
    consiliu.genereazaRaportGlobal();
    consiliu.genereazaAuditFinanciar();
    consiliu.upgradeSecuritateGlobala();

    consiliu.emiteExcommunicado(*tracker);

    std::cout << "Status Consiliu: " << consiliu << std::endl;

    BursaAsasinilor bursa("Marrakech", 250000);
    bursa.publicaBounty("Iosef Tarasov", 50000, 4);
    bursa.publicaBounty("Santino D'Antonio", 150000, 9);

    bursa.afiseazaCeleMaiCautateTinte();

    bursa.proceseazaRecompensa(*tracker, 0);

    bursa.suplimenteazaFonduri(10000);
    bursa.genereazaStatisticiBursa();

    std::cout << "Info Bursa: " << bursa << std::endl;
    std::cout << "Sediu: " << bursa.getSediu() << " | Contracte: " << bursa.getNumarContracte() << std::endl;

    bursa.anuleazaBounty("Santino D'Antonio");

    std::vector<std::string> tinteGrele = bursa.filtreazaContractePericuloase(5);
    std::cout << "[STL BURSA] S-au gasit " << tinteGrele.size() << " tinte de risc maxim in baza de date.\n";

    std::cout << "\n========== TESTARE SISTEM AVANSAT ==========\n";

    tracker->cresteExperienta(500);
    tracker->evalueazaTitluOnorific();
    std::cout << "Rang Tracker: " << tracker->getDescriereRang() << std::endl;

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


    auto asasinEliteSpecial = std::make_unique<AsasinElite>("Zero", 150, glock, 3.0);
    std::cout << "Instantiere noua: " << *asasinEliteSpecial << "\n";
    asasinEliteSpecial->executaAbilitateSpeciala();

    auto asasinInfiltratSpecial = std::make_unique<AsasinInfiltrat>("Sofi", 100, glock, "Manager Hotel");
    std::cout << "Instantiere noua: " << *asasinInfiltratSpecial << "\n";
    asasinInfiltratSpecial->executaAbilitateSpeciala();

    std::cout << "=========================================================\n";

    std::cout << "\n========== TESTARE EXEMPTII CUSTOM ==========\n";
    try {
        hotel.afiseazaRegistru();

        hotel.organizeazaDuel(0, 1);

        std::cout << "[SIMULARE] Se incearca executarea contractelor de la avizier...\n";
        hotel.executaContract(0, 0);

        hotel.simuleazaNoapteInHotel();

        hotel.evacueazaDecedatii();

    } catch (const ContinentalException& e) {
        std::cout << "\n>>> [ALERTA CODEX INTERCEPTATA] REZOLVARE PROMPT-A: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << ">>> [EROARE DE SISTEM CRITICA]: " << e.what() << "\n";
    }
    std::cout << "=======================================================\n";
    std::cout << "=========================================================\n";

    std::cout << "\n========== TESTARE METODE STATICE SI STL ==========\n";

    std::cout << "[STATIC] Total asasini instantiati in rulare: "
              << Asasin::getTotalAsasiniInregistrati() << "\n";

    int veterani = hotel.calculeazaNumarAsasiniVeterani();
    std::cout << "[STL] Numar de asasini veterani ramasi in Hotel Continental: " << veterani << "\n";

    std::cout << "=========================================================\n";

    std::cout << "\n========== TESTARE DYNAMIC_CAST==========\n";

    std::cout << "-- Evaluare downcast pentru index 0 (Elite) --\n";
    hotel.oferaMisiuneSecretaDeInfiltrare(0);

    std::cout << "\n-- Evaluare downcast pentru index 1 (Infiltrat) --\n";
    hotel.oferaMisiuneSecretaDeInfiltrare(1);

    hotel.sorteazaOaspetiDupaNivel();
    std::cout << "\n[REGISTRU DUPA SORTARE STL]:";
    hotel.afiseazaRegistru();

    std::cout << "=========================================================\n";

    std::cout << "\n========== INTEGRARE AMPLA CLASA DERIVATA  ==========\n";
    auto asasinTech = std::make_unique<AsasinBazaSecreta>("High-Table Operative", 200, glock, "Drona Hawk-Eye v4");

    asasinTech->instaleazaUpgradeTehnologic("Modul_Satelit_AI", 1.8);
    asasinTech->comutaProtocolSecuritate();

    asasinTech->incarcaBaterieGadget(20);

    if (asasinTech->detineUpgrade("Modul_Satelit_AI")) {
        std::cout << "[VALIDARE] Modulul AI este activ si functional.\n";
    }
    hotel.cazeaza(std::move(asasinTech));

    hotel.simuleazaNoapteInHotel();
    std::cout << "===============================================================\n";

    std::cout << "VERIFICAM CERINTELE ASASINILOR...";
    if (m1.areCerintaInclusa("Silențios")) {
        std::cout << "[C++ OPTIMIZATION] Cerinta speciala a fost validata prin std::any_of.\n";
    }
    m1.eliminaCerinteInvalide();
    std::cout << "[C++ OPTIMIZATION] Cerinte complexe ramase: " << m1.getNumarCerinteComplexe() << "\n";

    std::cout << "\n========== RUN SIMULATOR AVANSAT SECURITATE (C++ DENSE) ==========\n";
    SistemSecuritate testSec2(1);

    testSec2.adaugaSenzorPerimetral("Lobby Principal", "Senzor Miscare Laser");
    testSec2.adaugaSenzorPerimetral("Seif Central", "Scaner Biometric");
    testSec2.adaugaSenzorPerimetral("Acoperis Heliport", "Camera Infrarosiu");

    testSec2.inregistreazaIncident("CRITIC", "Tentativa de patrundere neautorizata detectata pe heliport.");
    testSec2.inregistreazaIncident("DUEL", "Zgomot de focuri de arma in zona restaurantului.");
    testSec2.inregistreazaIncident("MINOR", "Senzor lobby desincronizat temporar.");

    testSec2.simuleazaScanareCompleta();
    std::string raportSec = testSec2.genereazaRaportSecuritateCurent();
    std::cout << raportSec;

    std::cout << "Frecventa incidente critice: " << testSec2.getFrecventaIncident("CRITIC") << "\n";

    consiliu.ruleazaAuditTehnicSisteme();
    std::cout << "[AUDIT CODEX] Reguli de maxima severitate gasite: " << consiliu.calculeazaNumarReguliSevere() << "\n";
    if (consiliu.contineCuvantInCodex("pamant")) {
        std::cout << "[AUDIT CODEX] S-a gasit clauza de imunitate teritoriala.\n";
    }


    std::cout << "===================================================================\n";

    std::cout << "\n========== DEMONSTRATIE MECANICI UNICE DERIVATE (ANTI COPY-PASTE) ==========\n";

    auto eliteMecanic = std::make_unique<AsasinElite>("Zero_V2", 150, glock, 3.0);
    for(int i = 0; i < 5; ++i) {
        eliteMecanic->executaAbilitateSpeciala();
    }
    std::cout << *eliteMecanic << "\n";

    auto infiltratMecanic = std::make_unique<AsasinInfiltrat>("Sofi_V2", 100, glock, "Oaspete");
    infiltratMecanic->executaAbilitateSpeciala();
    infiltratMecanic->executaAbilitateSpeciala();
    std::cout << *infiltratMecanic << "\n";

    auto trackerMecanic = std::make_unique<AsasinBountyHunter>("Tracker_V2", 120, glock, 2);
    trackerMecanic->adaugaTintaInUrmarire("Santino_Backup");
    trackerMecanic->executaAbilitateSpeciala();
    std::cout << *trackerMecanic << "\n";

    std::cout << "=========================================================================\n";

    return 0;
}