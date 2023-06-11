#include "test.hpp"

#include <string>
#include <random>


void test() {
    MM:
    std::cout << R"(
    __  ___      _          __  ___                
   /  |/  /___ _(_)___     /  |/  /__  ____  __  __
  / /|_/ / __ `/ / __ \   / /|_/ / _ \/ __ \/ / / /
 / /  / / /_/ / / / / /  / /  / /  __/ / / / /_/ / 
/_/  /_/\__,_/_/_/ /_/  /_/  /_/\___/_/ /_/\__,_/  
                                                   
)" << std::endl;
    std::cout << "\n\nPer uscire inserisci 0 altrimenti inserisci un qualsiasi carattere: ";
    std::string ex = "";
    std::getline(std::cin, ex);
    if(ex=="0") return;

    std::string struttura = selezionaStruttura();
    std::string tipo = selezionaTipo();
    if(struttura=="1") {
        if(tipo=="1") {
            lasd::HashTableClsAdr<int> htcls;
            menuHashTableClsAdr(htcls); 
        }
        else if(tipo=="2") {
            lasd::HashTableClsAdr<double> htcls;
            menuHashTableClsAdr(htcls); 
        }
        else if(tipo=="3") {
            lasd::HashTableClsAdr<std::string> htcls;
            menuHashTableClsAdr(htcls); 
        }
    } else if(struttura=="2") {
        if(tipo=="1") {
            lasd::HashTableOpnAdr<int> htopn;
            menuHashTableOpnAdr(htopn); 
        }
        else if(tipo=="2") {
            lasd::HashTableOpnAdr<double> htopn;
            menuHashTableOpnAdr(htopn); 
        }
        else if(tipo=="3") {
            lasd::HashTableOpnAdr<std::string> htopn;
            menuHashTableOpnAdr(htopn);
        }
    }
    goto MM;
}



template <typename T>
void menuHashTableClsAdr(lasd::HashTableClsAdr<T>& htcls) {
    NextActionHTC:
    std::cout << R"(
    __  __           __  ______      __    __     ________     ___       __        __  ___                
   / / / /___ ______/ /_/_  __/___ _/ /_  / /__  / ____/ /____/   | ____/ /____   /  |/  /__  ____  __  __
  / /_/ / __ `/ ___/ __ \/ / / __ `/ __ \/ / _ \/ /   / / ___/ /| |/ __  / ___/  / /|_/ / _ \/ __ \/ / / /
 / __  / /_/ (__  ) / / / / / /_/ / /_/ / /  __/ /___/ (__  ) ___ / /_/ / /     / /  / /  __/ / / / /_/ / 
/_/ /_/\__,_/____/_/ /_/_/  \__,_/_.___/_/\___/\____/_/____/_/  |_\__,_/_/     /_/  /_/\___/_/ /_/\__,_/  
                                                                                                          
)"<< std::endl;
    std::cout << "1: Size" << std::endl;
    std::cout << "2: Empty" << std::endl;
    std::cout << "3: Insert" << std::endl;
    std::cout << "4: Remove" << std::endl;
    std::cout << "5: Resize" << std::endl;
    std::cout << "6: Clear" << std::endl;
    std::cout << "7: Exists" << std::endl;
    std::cout << "8: Popolamento" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidHTC:
    std::cout << "\n\n";
    std::string scelta = "";
    std::getline(std::cin, scelta);
    if(scelta=="1") {
        funSize(htcls);
        goto NextActionHTC;
    }
    else if(scelta=="2") {
        funEmpty(htcls);
        goto NextActionHTC;
    }
    else if(scelta=="3") {
        funInsertD(htcls);
        goto NextActionHTC;
    }    
    else if(scelta=="4") {
        funRemoveD(htcls);
        goto NextActionHTC;
    }
    else if(scelta=="5") {
        funResize(htcls);
        goto NextActionHTC;
    }
    else if(scelta=="6") {
        funClear(htcls);
        goto NextActionHTC;
    }
    else if(scelta=="7") {
        funExists(htcls);
        goto NextActionHTC;
    }
    else if(scelta=="8") {
        popolaHTC(htcls);
        goto NextActionHTC;
    }
    else if(scelta=="0") {
        return;
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTC;
    }
}

template <typename T>
void menuHashTableOpnAdr(lasd::HashTableOpnAdr<T>& htopn) {
    NextActionHTO:
    std::cout << R"(
    __  __           __  ______      __    __     ____              ___       __        __  ___                
   / / / /___ ______/ /_/_  __/___ _/ /_  / /__  / __ \____  ____  /   | ____/ /____   /  |/  /__  ____  __  __
  / /_/ / __ `/ ___/ __ \/ / / __ `/ __ \/ / _ \/ / / / __ \/ __ \/ /| |/ __  / ___/  / /|_/ / _ \/ __ \/ / / /
 / __  / /_/ (__  ) / / / / / /_/ / /_/ / /  __/ /_/ / /_/ / / / / ___ / /_/ / /     / /  / /  __/ / / / /_/ / 
/_/ /_/\__,_/____/_/ /_/_/  \__,_/_.___/_/\___/\____/ .___/_/ /_/_/  |_\__,_/_/     /_/  /_/\___/_/ /_/\__,_/  
                                                   /_/                                                         
)"<< std::endl;
    std::cout << "1: Size" << std::endl;
    std::cout << "2: Empty" << std::endl;
    std::cout << "3: Insert" << std::endl;
    std::cout << "4: Remove" << std::endl;
    std::cout << "5: Resize" << std::endl;
    std::cout << "6: Clear" << std::endl;
    std::cout << "7: Exists" << std::endl;
    std::cout << "8: Popolamento" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidHTO:
    std::cout << "\n\n";
    std::string scelta = "";
    std::getline(std::cin, scelta);
    if(scelta=="1") {
        funSize(htopn);
        goto NextActionHTO;
    }
    else if(scelta=="2") {
        funEmpty(htopn);
        goto NextActionHTO;
    }
    else if(scelta=="3") {
        funInsertD(htopn);
        goto NextActionHTO;
    }    
    else if(scelta=="4") {
        funRemoveD(htopn);
        goto NextActionHTO;
    }
    else if(scelta=="5") {
        funResize(htopn);
        goto NextActionHTO;
    }
    else if(scelta=="6") {
        funClear(htopn);
        goto NextActionHTO;
    }
    else if(scelta=="7") {
        funExists(htopn);
        goto NextActionHTO;
    }
    else if(scelta=="8") {
        popolaHTO(htopn);
        goto NextActionHTO;
    }
    else if(scelta=="0") {
        return;
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTO;
    }
}





//Funzioni
template <typename T>
void funInsertD(lasd::HashTable<T>& con) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nella hash table ";
        std::cin >> value;
        if(con.Insert(value)) {
            std::cout << " Inserito!" << std::endl;
        } else {
            std::cout << " Valore non Inserito!" << std::endl;
        }
        
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}

template <typename T>
void funRemoveD(lasd::HashTable<T>& con) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi rimuovere dalla hash table: ";
        std::cin >> value;
        if(con.Remove(value)) {
            std::cout << " Rimosso!" << std::endl;
        } else {
            std::cout << " Valore non rimosso!" << std::endl;
        }
        
        std::cout << "Vuoi rimuovere un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}

template <typename T>
void funResize(lasd::HashTable<T>& ht) {
    std::cout << "\nInserisci nuova size per la hash table: " << std::endl;
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    ht.Resize(n);
    std::cout << "\nResize effettuata!" << std::endl;
}

template <typename T>
void funExists(lasd::HashTable<T>& ht) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi controllare: ";
        std::cin >> value;
        std::string text = ht.Exists(value) ? ("L'elemento è nella hash table.") : ("L'elemento non è nella hash table.");
        std::cout << text << std::endl;
        std::cout << "Vuoi controllare un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);
}

template <typename T>
void funClear(lasd::HashTable<T>& ht) {
    ht.Clear();
    std::cout << "\nHashTable svuotata!" << std::endl;
}

template <typename T>
void funSize(lasd::HashTable<T>& ht) {
    std::cout << "\nL'HashTable ha size: " << ht.Size() << std::endl;  
}


template <typename T>
void funEmpty(lasd::HashTable<T>& ht) {
    bool res;
    std::cout << "\nL'HashTable " << ((res = ht.Empty()) ? "è vuota" : "non è vuota")  << std::endl;
}


//Selettori
std::string selezionaStruttura() {
    std::cout << "Scegli il tipo di struttura dati:" << std::endl;
    std::cout << "1: HashTableClsAdr" << std::endl;
    std::cout << "2: HashTableOpnAdr" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidStruct:
    std::string scelta = "0";
    std::getline(std::cin, scelta);

    if(scelta=="1" || scelta=="2") return scelta;
    else{
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidStruct;
    }
}


std::string selezionaTipo() {
    std::cout << "Scegli il tipo di dati:" << std::endl;
    std::cout << "1: int" << std::endl;
    std::cout << "2: double" << std::endl;
    std::cout << "3: string" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidType:
    std::string scelta = "0";
    std::getline(std::cin, scelta);

    if(scelta=="1" || scelta=="2" || scelta=="3") return scelta;
    else{
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidType;
    }
}



//Popolamento
template <>
void popolaHTC(lasd::HashTableClsAdr<int>& htcls) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidHTCint:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(int i: generaInt(n)) {
            htcls.Insert(i);
        }
    } 
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTCint;
    }   
}

template <>
void popolaHTC(lasd::HashTableClsAdr<double>& htcls) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidHTCdouble:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(double i: generaDouble(n)) {
            htcls.Insert(i);
        }
    } 
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTCdouble;
    }   
}

template <>
void popolaHTC(lasd::HashTableClsAdr<std::string>& htcls) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidHTCstring:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(std::string i: generaString(n)) {
            htcls.Insert(i);
        }
    } 
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTCstring;
    }   
}

template <>
void popolaHTO(lasd::HashTableOpnAdr<int>& htopn) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidHTOint:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(int i: generaInt(n)) {
            htopn.Insert(i);
        }
    } 
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTOint;
    }   
}

template <>
void popolaHTO(lasd::HashTableOpnAdr<double>& htopn) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidHTOdouble:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(double i: generaInt(n)) {
            htopn.Insert(i);
        }
    } 
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTOdouble;
    }   
}

template <>
void popolaHTO(lasd::HashTableOpnAdr<std::string>& htopn) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidHTOstring:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(std::string i: generaString(n)) {
            htopn.Insert(i);
        }
    } 
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidHTOstring;
    }   
}


//Generatori
std::vector<int> generaInt(unsigned long dim) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distr(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max());

    std::vector<int> vec;

    for(unsigned long i = 0; i<dim; i++) {
        vec.push_back(distr(generator));
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}

std::vector<double> generaDouble(unsigned long dim) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_real_distribution<double> distr(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());

    std::vector<double> vec;

    for(unsigned long i = 0; i<dim; i++) {
        vec.push_back(distr(generator));
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}

std::vector<std::string> generaString(unsigned long dim) {
    static const char charset[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distr(0, sizeof(charset)-1);

    std::vector<std::string> vec;

    for(unsigned long i = 0; i<dim; i++) {
        std::string str = "";
        uint charsToGenerate = distr(generator);
        while(str.length()<charsToGenerate || str.length() < 4) {
            str+=(charset[distr(generator)]);
        }
        vec.push_back(str);
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}