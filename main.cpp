#include "HotelContinental.h"
#include "Asasin.h"
#include "Arma.h"
#include <iostream>

int main() {
    std::cout << "--- Initializare Arsenal ---\n";
    Arma hk("HK P30", 15);
    Arma glock("Glock 17", 17);
    Arma creion("Creion Ticonderoga", 1);

    std::cout << "Arma principala are " << hk.getGloante() << " gloante.\n";

    Asasin john("John Wick", 100, hk);
    Asasin cassian("Cassian", 100, glock);

    Asasin copieJohn = john;

    HotelContinental hotelNY("New York");
    hotelNY.cazeaza(john);
    hotelNY.cazeaza(cassian);

    std::cout << "\n--- Pregatiri ---\n";

    john.antrenament();

    hk.reincarca(5);

    hotelNY.afiseazaRegistru();

    std::cout << "\n--- Incepe conflictul la Roma ---\n";
    hotelNY.organizeazaDuel(0, 1);
    hotelNY.organizeazaDuel(0, 1);
    hotelNY.organizeazaDuel(0, 1);

    std::cout << "\n--- Post-Conflict ---\n";
    hotelNY.evacueazaDecedatii();

    hotelNY.afiseazaRegistru();
    std::cout << "\nStare Hotel: " << hotelNY << "\n";

    Asasin asasinNou("Nimeni", 50, creion);
    asasinNou = john;
    std::cout << "Dupa atribuire: " << asasinNou << "\n";

    return 0;
}