#include <iostream>
#include "Banca.h"
#include "Client.h"
#include "ContBancar.h"


int main(void){
    ContBancar contClient1_EUR{"1001", 0, "EUR"};
    ContBancar contClient1_RON("2001", 0, "RON");
    Client client1{"nume1", "prenume1", "adresa1", contClient1_EUR};
    client1.addCont(contClient1_RON);

    ContBancar contClient2_RON1("2002", 0, "RON");
    ContBancar contClient2_RON2("2003", 0, "RON");
    Client client2{"nume2", "prenume2", "adresa2", contClient2_RON1};
    client2.addCont(contClient2_RON2);

    Banca banca1{"1316", client1};
    banca1.addClient(client2);

    using namespace std;

    contClient1_EUR.depunere(contClient1_EUR, 1000);
    cout << "DEPUNERE" << endl;
    cout << "Suma totala client1_cont1: " << contClient1_EUR.getSumaTotala() << endl;
    cout << "Dobanda client1_cont1: " << contClient1_EUR.getDobanda() << endl;
    contClient2_RON1.depunere(contClient2_RON1, 500);
    cout << "Suma totala client2_cont1: " << contClient2_RON1.getSumaTotala() << endl;
    cout << "Dobanda client2_cont1: " << contClient2_RON1.getDobanda() << endl;
    contClient1_EUR.extragere(contClient1_EUR, 150);
    cout << "EXTRAGERE" << endl;
    cout << "Suma totala client1_cont1: " << contClient1_EUR.getSumaTotala() << endl;
    contClient2_RON1.transfer(contClient1_EUR, 100);
    contClient2_RON1.transfer(contClient1_RON, 200);
    cout << "TRANSFER" << endl;
    cout << "Suma totala client1_cont1: " << contClient1_EUR.getSumaTotala() << endl;
    cout << "Suma totala client1 cont2: " << contClient1_RON.getSumaTotala() << endl;
    

    // banca1.~Banca();
    return 0;
}