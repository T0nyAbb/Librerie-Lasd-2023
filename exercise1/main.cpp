#include "zmytest/test.hpp"
#include "zlasdtest/test.hpp"
#include "thread"
#include "chrono"
#include "string"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
    inizio:
    std::cout << "Lasd Libraries 2023" << std::endl;
    std::cout << "Ciao, scegli cosa vuoi fare:" << std::endl;
    std::cout << "1: Test personale." << std::endl;
    std::cout << "2: Test professore." << std::endl;
    std::cout << "3: Esci." << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    std::string scelta = "0";
    start:
    std::getline(std::cin, scelta);
    
    if(scelta=="1"){
      test();
      std::cout << "\n\nA breve sarai riportato al menù principale.\n\n" << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(5000));
      goto inizio;
    }
    else if(scelta=="2"){
      lasdtest();
      std::cout << "\n\nTest completati!\n\nA breve sarai riportato al menù principale.\n\n" << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(5000));
      goto inizio;
    } 
    else if(scelta=="3") goto end;
    else {
      std::cout << "\nScelta non valida! Riprova:";
      scelta = "0";
      goto start;
    }

    end:
    std::cout << "\n\nLibrerie realizzate da: Antonio Abbatiello\n\n" << std::endl;
    std::cout << "Alla prossima ;)\n\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "Programma terminato." << std::endl;
  return 0;
}
