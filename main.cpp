#include "HotelContinental.h"
#include "Asasin.h"
#include "Arma.h"
#include "Misiune.h"
#include <iostream>

int main() {
    std::cout << "=== SIMULARE LUMEA ASASINILOR ===\n";
    Arma hk("HK P30", 15);
    Arma glock("Glock 17", 17);

    Asasin john("John Wick", 100, hk);
    Asasin cassian("Cassian", 100, glock);

    HotelContinental hotel("Roma", 10000);

    Misiune contract1("Eliminare Seful Camorra", 5, 2000);
    contract1.adaugaCerinta("Fara urme");
    contract1.adaugaCerinta("Doar cu arme albe");

    Misiune contract2("Recuperare stick USB", 2, 500);

    hotel.cazeaza(john);
    hotel.cazeaza(cassian);
    hotel.adaugaMisiune(contract1);
    hotel.adaugaMisiune(contract2);

    std::cout << "\n--- Status Initial ---\n";
    hotel.afiseazaRegistru();
    hotel.afiseazaAvizier();

    std::cout << "\n--- Pregatire John Wick ---\n";
    john.antrenament();
    hk.reincarca(10);
    std::cout << "Verificare munitie: " << hk.getGloante() << " gloante.\n";

    std::cout << "\n--- Activitate Contractuala ---\n";
    hotel.executaContract(0, 1);
    hotel.executaContract(1, 0);

    Asasin clona = cassian;
    hotel.organizeazaDuel(0, 1);

    std::cout << "\n--- Raport Final ---\n";
    hotel.evacueazaDecedatii();
    hotel.afiseazaRegistru();
    std::cout << hotel << "\n";

    Asasin asasinRezerva("Generic", 10, Arma("Pistol Vechi", 5));
    asasinRezerva = john;
    std::cout << "Asasin rezerva dupa upgrade la John Wick: " << asasinRezerva << "\n";

    std::cout << "\n--- Administrare Hotel ---\n";
    std::cout << "Status inainte: " << hotel << "\n";

    hotel.aprovizionareSeif(1500);

    std::cout << "Status dupa aprovizionare seif: " << hotel << "\n";

    std::cout << "\n=== SIMULARE INCHEIATA ===\n";
    return 0;
}