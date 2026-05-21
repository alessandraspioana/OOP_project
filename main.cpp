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
#include "AsasinElite.h"
#include "AsasinInfiltrat.h"
#include "AsasinBountyHunter.h"
#include "SistemSecuritate.h"
#include "HotelContinental.h"
#include "ConsiliuInalt.h"
#include "BursaAsasinilor.h"

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

    auto john = std::make_unique<AsasinElite>(numeAsasin, hp, glock, 2.5);
    auto cassian = std::make_unique<AsasinInfiltrat>("Cassian", 100, glock, "Costum Elegant");

    std::unique_ptr<Asasin> copie = john->clone();
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
    
    AsasinBountyHunter tracker("Tracker", 120, glock, 3);
    consiliu.emiteExcommunicado(tracker);

    std::cout << "Status Consiliu: " << consiliu << std::endl;

    BursaAsasinilor bursa("Marrakech", 250000);
    bursa.publicaBounty("Iosef Tarasov", 50000, 4);
    bursa.publicaBounty("Santino D'Antonio", 150000, 9);

    bursa.afiseazaCeleMaiCautateTinte();

    bursa.proceseazaRecompensa(tracker, 0);

    bursa.suplimenteazaFonduri(10000);
    bursa.genereazaStatisticiBursa();

    std::cout << "Info Bursa: " << bursa << std::endl;
    std::cout << "Sediu: " << bursa.getSediu() << " | Contracte: " << bursa.getNumarContracte() << std::endl;

    bursa.anuleazaBounty("Santino D'Antonio");

    std::cout << "\n========== TESTARE SISTEM AVANSAT ==========\n";

    tracker.cresteExperienta(500);
    tracker.evalueazaTitluOnorific();
    std::cout << "Rang Tracker: " << tracker.getDescriereRang() << std::endl;

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

    std::cout << "\n========== DEMONSTRATIE METODE DERIVATE TEMA 2 ==========\n";
    
    auto asasinEliteSpecial = std::make_unique<AsasinElite>("Zero", 150, glock, 3.0);
    std::cout << "Instantiere noua: " << *asasinEliteSpecial << "\n";
    asasinEliteSpecial->executaAbilitateSpeciala();
    
    auto asasinInfiltratSpecial = std::make_unique<AsasinInfiltrat>("Sofi", 100, glock, "Manager Hotel");
    std::cout << "Instantiere noua: " << *asasinInfiltratSpecial << "\n";
    asasinInfiltratSpecial->executaAbilitateSpeciala();

    std::cout << "=========================================================\n";

    return 0;
}