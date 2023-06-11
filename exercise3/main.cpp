#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

#include "thread"
#include "string"


/* ************************************************************************** */

int main() {
    inizio:
    std::cout << R"(
    __    ___   _____ ____     ___   ____ ___  _____
   / /   /   | / ___// __ \   |__ \ / __ \__ \|__  /
  / /   / /| | \__ \/ / / /   __/ // / / /_/ / /_ < 
 / /___/ ___ |___/ / /_/ /   / __// /_/ / __/___/ / 
/_____/_/  |_/____/_____/   /____/\____/____/____/  
                                                    
)" << std::endl;
    std::cout << "Ciao, scegli cosa vuoi fare:" << std::endl;
    std::cout << "1: Test personale." << std::endl;
    std::cout << "2: Test professore." << std::endl;
    std::cout << "0: Esci." << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    std::string scelta = "";
    start:
    std::getline(std::cin, scelta);
    
    if(scelta=="1"){
      test();
      std::cout << "\n\nA breve sarai riportato al menù principale." << std::endl;
      goto inizio;
    }
    else if(scelta=="2"){
      lasdtest();
      std::cout << "\n\nTest completati!\nA breve sarai riportato al menù principale." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(2500));
      goto inizio;
    } 
    else if(scelta=="0") goto end;
    else {
      std::cout << "\nScelta non valida! Riprova:";
      goto start;
    }

    end:
    std::cout << "\n\nLibrerie realizzate da: Antonio Abbatiello\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Programma terminato." << std::endl;
  return 0;
}

/* ************************************************************************** */