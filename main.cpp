#include <iostream>
#include <vector>
#include <string>
#include "Arma.h"
#include "Asasin.h"
#include "Misiune.h"
#include "HotelContinental.h"
#include "ConsiliuInalt.h"

int main() {
    std::cout << "========== SISTEM DE MANAGEMENT CONTINENTAL ==========\n\n";

    ConsiliuInalt consiliu("The Adjudicator");
    consiliu.adaugaRegula("Nicio afacere nu se face pe pamant sacru.");
    consiliu.adaugaRegula("Biletul trebuie onorat intotdeauna.");

    std::cout << "[1] Configurare Arsenal...\n";
    Arma hk("HK P30", 15);
    Arma glock("Glock 17", 17);
    Arma creion("Creion Ticonderoga", 1);

    std::cout << "Status Munitie HK: " << hk.getGloante() << " gloante disponibile.\n";

    std::cout << "[2] Recrutare Operativi...\n";
    Asasin john("John Wick", 100, hk);
    Asasin cassian("Cassian", 100, glock);

    Asasin copieJohn = john;
    std::cout << "Copie de rezerva creata: " << copieJohn.getNume() << "\n";

    std::cout << "[3] Deschidere Unitati Continental...\n";
    HotelContinental hotelRoma("Roma", 15000);
    hotelRoma.cazeaza(john);
    hotelRoma.cazeaza(cassian);

    consiliu.adaugaHotel(hotelRoma);

    std::cout << "[4] Generare Contracte de Eliminare...\n";
    Misiune contract1("Eliminare Tinta VIP", 5, 2500);
    contract1.adaugaCerinta("Silentios");
    contract1.adaugaCerinta("Fara martori");

    Misiune contract2("Recuperare Bunuri Furate", 2, 800);

    hotelRoma.adaugaMisiune(contract1);
    hotelRoma.adaugaMisiune(contract2);

    std::cout << "\n--- Incepere Operatiuni ---\n";
    hotelRoma.afiseazaAvizier();

    john.antrenament();
    hk.reincarca(5);

    hotelRoma.executaContract(0, 1);

    hotelRoma.organizeazaDuel(0, 1);

    std::cout << "\n--- Interventie Consiliu ---\n";
    consiliu.afiseazaCodex();

    consiliu.finanteazaHotel(0, 5000);

    consiliu.emiteExcommunicado(cassian);

    std::cout << "\n--- Raport Final de Activitate ---\n";
    hotelRoma.evacueazaDecedatii();
    hotelRoma.afiseazaRegistru();

    consiliu.genereazaRaportGlobal();

    Asasin unitateNoua("Placeholder", 10, creion);
    unitateNoua = john;
    std::cout << "Dupa atribuire: " << unitateNoua << "\n";

    std::cout << "\nStatus Consiliu: " << consiliu << "\n";
    std::cout << "======================================================\n";
    std::cout << "Sistem inchis cu succes.\n";

    return 0;
}