#include "test.hpp"

#include <iostream>
#include <string>
#include <random>


//Main menu
void test() {
    std::cout << "~*~#~*~ Menù Principale ~*~#~*~" << std::endl;
    std::cout << "\n\n\nPer uscire inserisci 0 altrimenti inserisci un qualsiasi carattere: ";
    std::string ex = "";
    std::getline(std::cin, ex);
    if(ex=="0") return;

    std::string struttura = selezionaStruttura();
    std::string tipo = selezionaTipo();
    if(struttura=="1") {
        if(tipo=="1") {
            lasd::Vector<int> vec;
            popolaVec(vec);
            menuVector(vec);

        }
        else if(tipo=="2") {
            lasd::Vector<double> vec;
            popolaVec(vec);
            menuVector(vec);
        }
        else if(tipo=="3") {
            lasd::Vector<std::string> vec;
            popolaVec(vec);
            menuVector(vec);
        }
    } else if(struttura=="2") {
        if(tipo=="1") {
            lasd::List<int> lst;
            popolaLst(lst);
            menuList(lst);
        }
        else if(tipo=="2") {
            lasd::List<double> lst;
            popolaLst(lst);
            menuList(lst);
        }
        else if(tipo=="3") {
            lasd::List<std::string> lst;
            popolaLst(lst);
            menuList(lst);
        }
    }
    else if(struttura=="3") {
        if(tipo=="1") {
            lasd::StackVec<int> stk;
            popolaStk(stk);
            menuStack(stk);
        }
        else if(tipo=="2") {
            lasd::StackVec<double> stk;
            popolaStk(stk);
            menuStack(stk);
        }
        else if(tipo=="3") {
            lasd::StackVec<std::string> stk;
            popolaStk(stk);
            menuStack(stk);
        }
    }
    else if(struttura=="4") {
        if(tipo=="1") {
            lasd::StackLst<int> stk;
            popolaStk(stk);
            menuStack(stk);
        }
        else if(tipo=="2") {
            lasd::StackLst<double> stk;
            popolaStk(stk);
            menuStack(stk);
        }
        else if(tipo=="3") {
            lasd::StackLst<std::string> stk;
            popolaStk(stk);
            menuStack(stk);
        }
    }
    else if(struttura=="5") {
        if(tipo=="1") {
            lasd::QueueVec<int> que;
            popolaQue(que);
            menuQueue(que);
        }
        else if(tipo=="2") {
            lasd::QueueVec<double> que;
            popolaQue(que);
            menuQueue(que);
        }
        else if(tipo=="3") {
            lasd::QueueVec<std::string> que;
            popolaQue(que);
            menuQueue(que);
        }
    }
    else if(struttura=="6") {
            if(tipo=="1") {
            lasd::QueueLst<int> que;
            popolaQue(que);
            menuQueue(que);
        }
        else if(tipo=="2") {
            lasd::QueueLst<double> que;
            popolaQue(que);
            menuQueue(que);
        }
        else if(tipo=="3") {
            lasd::QueueLst<std::string> que;
            popolaQue(que);
            menuQueue(que);
        } 
    }
}


//Menu Stack
template <typename T>
void menuStack(lasd::Stack<T>& stk) {
    NextActionStack:
    std::cout << "\n\n~*~#~*~ Menù Stack ~*~#~*~" << std::endl;
    std::cout << "1: Size" << std::endl;
    std::cout << "2: Empty" << std::endl;
    std::cout << "3: Push" << std::endl;
    std::cout << "4: Pop" << std::endl;
    std::cout << "5: Top" << std::endl;
    std::cout << "6: TopNPop" << std::endl;
    std::cout << "7: Clear" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidStack:
    std::cout << "\n\n";
    std::string scelta = "";
    std::getline(std::cin, scelta);
    if(scelta=="1") {
        std::cout << "\nLo stack ha size: " << stk.Size() << std::endl;
        goto NextActionStack;
    }
    else if(scelta=="2") {
        bool res;
        std::cout << "\nLo Stack " << ((res = stk.Empty()) ? "è vuoto" : "non è vuoto")  <<std::endl;
        goto NextActionStack;
    }
    else if(scelta=="3") {
        funPush(stk);
        goto NextActionStack;
    }
    else if(scelta=="4") {
        funPop(stk);
        goto NextActionStack;
    }
    else if(scelta=="5") {
        funTop(stk);
        goto NextActionStack;
    }
    else if(scelta=="6") {
        funTopPop(stk);
        goto NextActionStack;
    }
    else if(scelta=="7") {
        stk.Clear();
        std::cout << "\nStack svuotato" << std::endl;
    }
    else if(scelta=="0") {
        stk.Clear();
        return;
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidStack;
    }
}


//Menu queue
template <typename T>
void menuQueue(lasd::Queue<T>& que) {
    NextActionQueue:
    std::cout << "\n\n~*~#~*~ Menù Queue ~*~#~*~" << std::endl;
    std::cout << "1: Stampa Queue" << std::endl;
    std::cout << "1: Size" << std::endl;
    std::cout << "2: Empty" << std::endl;
    std::cout << "3: Enqueue" << std::endl;
    std::cout << "4: Dequeue" << std::endl;
    std::cout << "5: Head" << std::endl;
    std::cout << "6: HeadNDequeue" << std::endl;
    std::cout << "7: Clear" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidQueue:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
        std::cout << "\nLa queue ha size: " << que.Size() << std::endl;
        goto NextActionQueue;
    }
    else if(scelta=="2") {
        bool res;
        std::cout << "\nLa Queue " << ((res = que.Empty()) ? "è vuota" : "non è vuota")  <<std::endl;
        goto NextActionQueue;
    }
    else if(scelta=="3") {
        funEnqueue(que);
        goto NextActionQueue;
    }
    else if(scelta=="4") {
        funDequeue(que);
        goto NextActionQueue;
    }
    else if(scelta=="5") {
        funHead(que);
        goto NextActionQueue;
    }
    else if(scelta=="6") {
        funHeadNDequeue(que);
        goto NextActionQueue;
    }
    else if(scelta=="7") {
        que.Clear();
        std::cout << "\nQueue svuotata" << std::endl;  
        goto NextActionQueue;     
    }
    else if(scelta=="0") {
        que.Clear();
        return;
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidQueue;        
    }
}

template <typename T>
void menuList(lasd::List<T>& lst) {
    NextActionList:
    std::cout << "\n\n~*~#~*~ Menù Lista ~*~#~*~" << std::endl;
    std::cout << "1: Stampa Lista" << std::endl;
    std::cout << "2: Size" << std::endl;
    std::cout << "3: Empty" << std::endl;
    std::cout << "4: Front" << std::endl;
    std::cout << "5: Back" << std::endl;
    std::cout << "6: Exists" << std::endl;
    std::cout << "7: Insert Dictionary" << std::endl;
    std::cout << "8: Remove Dictionary" << std::endl;
    std::cout << "9: Insert At Back" << std::endl;
    std::cout << "a: Insert At Front" << std::endl;
    std::cout << "b: FrontNRemove" << std::endl;
    std::cout << "c: Clear" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidList:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
        std::cout << "\nStampo la lista: " << std::endl;
        lst.Map(&MapPrint<T>);
        goto NextActionList;
    }
    else if(scelta=="2") {
        std::cout << "\nLa lista ha size: " << lst.Size() << std::endl;
        goto NextActionList;        
    }
    else if(scelta=="3") {
        bool res;
        std::cout << "\nLa Lista " << ((res = lst.Empty()) ? "è vuota" : "non è vuota")  <<std::endl;
        goto NextActionList;        
    }
    else if(scelta=="4") {
        funFront(lst);
        goto NextActionList; 
    }
    else if(scelta=="5") {
        funBack(lst);
        goto NextActionList; 
    }
    else if(scelta=="6") {
        funExists(lst);
        goto NextActionList;
    }
    else if(scelta=="7") {
        funInsertD(lst);
        goto NextActionList;
    }
    else if(scelta=="8") {
        funRemoveD(lst);
        goto NextActionList;
    }
    else if(scelta=="9") {
        funInsertAtBack(lst);
        goto NextActionList;
    }
    else if(scelta=="a") {
        funInsertAtFront(lst);
        goto NextActionList;
    }
    else if(scelta=="b") {
        funFrontNRemove(lst);
        goto NextActionList;
    }
    else if(scelta=="c") {
        lst.Clear();
        std::cout << "\nLista svuotata" << std::endl;
        goto NextActionList;         
    }
    else if(scelta=="0") {
        lst.Clear();
        return;
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidList;
    }
}

template <typename T>
void menuVector(lasd::Vector<T>& vec) {
    NextActionVector:
    std::cout << "\n\n~*~#~*~ Menù Vector ~*~#~*~" << std::endl;
    std::cout << "1: Stampa Vector" << std::endl;
    std::cout << "2: Size" << std::endl;
    std::cout << "3: Empty" << std::endl;
    std::cout << "4: Front" << std::endl;
    std::cout << "5: Back" << std::endl;
    std::cout << "6: Exists" << std::endl;
    std::cout << "7: Sort" << std::endl;
    std::cout << "8: Clear" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidVector:
    std::string scelta = "";
    std::cout << "\n\n";
    std::getline(std::cin, scelta);
    if(scelta=="1") {
        std::cout << "\nStampo il vettore: " << std::endl;
        vec.Map(&MapPrint<T>);
        std::cout << "\n\n";
        goto NextActionVector;
    }
    else if(scelta=="2") {
        std::cout << "\nIl vettore ha size: " << vec.Size() << std::endl;
        goto NextActionVector;  
    }
    else if(scelta=="3") {
        bool res;
        std::cout << "\nIl vettore " << ((res = vec.Empty()) ? "è vuoto" : "non è vuoto")  <<std::endl;
        goto NextActionVector;          
    }
    else if(scelta=="4") {
        funFront(vec);
        goto NextActionVector; 
    }
    else if(scelta=="5") {
        funBack(vec);
        goto NextActionVector; 
    }
    else if(scelta=="6") {
        funExists(vec);
        goto NextActionVector; 
    }
    else if(scelta=="7") {
        funSort(vec);
        goto NextActionVector; 
    }
    else if(scelta=="8") {
        vec.Clear();
        std::cout << "\nvettore svuotato" << std::endl;
        goto NextActionVector;
    }
    else if(scelta=="0") {
        vec.Clear();
        return;
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidVector;        
    }

}

//Funzioni
template <typename T>
void funExists(lasd::LinearContainer<T>& con) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi controllare: ";
        std::cin >> value;
        std::string text = con.Exists(value) ? ("L'elemento è nel container.") : ("L'elemento non è nel container.");
        std::cout << text << std::endl;
        std::cout << "Vuoi controllare un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);
}

template <typename T>
void funFront(lasd::LinearContainer<T>& con) {
    T data;
    try{
        data = con.Front();
        std::cout << "\nIl dato restituito è " << data << std::endl;
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }
    return;
}

template <typename T>
void funBack(lasd::LinearContainer<T>& con) {
    T data;
    try{
        data = con.Back();
        std::cout << "\nIl dato restituito è " << data << std::endl;
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }
    return;
}

template <typename T>
void funSort(lasd::Vector<T>& con) {
    std::cout << "\nContainer prima dell'ordinamento:" << std::endl;
    con.Map(&MapPrint<T>);
    std::cout << "\nContainer dopo l'ordinamento:" << std::endl;
    con.Sort();
    con.Map(&MapPrint<T>);
}

template <typename T>
void funPush(lasd::Stack<T>& stk) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nello stack: ";
        std::cin >> value;
        stk.Push(value);
        std::cout << " Inserito!" << std::endl;
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);
}

template <typename T>
void funEnqueue(lasd::Queue<T>& que) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nella queue: ";
        std::cin >> value;
        que.Enqueue(value);
        std::cout << " Inserito!" << std::endl;
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);    
}

template <typename T>
void funPop(lasd::Stack<T>& stk) {
    std::cout << "\nEffettuo Pop..." << std::endl;
    try {
        stk.Pop();
        std::cout << "Pop effettuata con successo!" << std::endl; 
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }
}

template<typename T>
void funDequeue(lasd::Queue<T>& que) {
        std::cout << "\nEffettuo Dequeue..." << std::endl;
    try {
        que.Dequeue();
        std::cout << "Dequeue effettuata con successo!" << std::endl; 
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }

}

template <typename T>
void funTop(lasd::Stack<T>& stk) {
       std::cout << "\nEffettuo Top..." << std::endl;
    try {
        std::cout << stk.Top() << " Pop effettuata con successo!" << std::endl; 
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    } 
}

template <typename T>
void funHead(lasd::Queue<T>& que) {
       std::cout << "\nEffettuo Head..." << std::endl;
    try {
        std::cout << que.Head() << " Head effettuata con successo!" << std::endl; 
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }     
}

template <typename T>
void funTopPop(lasd::Stack<T>& stk) {
       std::cout << "\nEffettuo TopNPop..." << std::endl;
    try {
        std::cout << stk.TopNPop() << " TopNPop effettuata con successo!" << std::endl; 
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }     
}

template <typename T>
void funHeadNDequeue(lasd::Queue<T>& que) {
       std::cout << "\nEffettuo HeadNDequeue..." << std::endl;
    try {
        std::cout << que.HeadNDequeue() << " HeadNDequeue effettuata con successo!" << std::endl; 
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }        
}

template <typename T>
void funInsertD(lasd::DictionaryContainer<T>& con) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nel dizionario: ";
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
void funRemoveD(lasd::DictionaryContainer<T>& con) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi rimuovere dal dizionario: ";
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
void funFrontNRemove(lasd::List<T>& lst) {
       std::cout << "\nEffettuo FrontNRemove..." << std::endl;
    try {
        std::cout << lst.FrontNRemove() << " FrontNRemove effettuata con successo!" << std::endl; 
    } catch(std::length_error ex) {
        std::cout << ex.what() << std::endl;
    }     
}

template <typename T>
void funInsertAtBack(lasd::List<T>& lst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nella lista: ";
        std::cin >> value;
        lst.InsertAtBack(value);
        std::cout << " Inserito in coda!" << std::endl;
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);   
}

template <typename T>
void funInsertAtFront(lasd::List<T>& lst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nella lista: ";
        std::cin >> value;
        lst.InsertAtFront(value);
        std::cout << " Inserito in testa!" << std::endl;
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}



//Selettori
std::string selezionaStruttura() {
    std::cout << "Scegli il tipo di struttura dati:" << std::endl;
    std::cout << "1: Vettore" << std::endl;
    std::cout << "2: Lista" << std::endl;
    std::cout << "3: StackVec" << std::endl;
    std::cout << "4: StackLst" << std::endl;
    std::cout << "5: CodaVec" << std::endl;
    std::cout << "6: CodaLst" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidStruct:
    std::string scelta = "0";
    std::getline(std::cin, scelta);

    if(scelta=="1" || scelta=="2" || scelta=="3" || scelta=="4" || scelta=="5" || scelta=="6") return scelta;
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









//Popolazione
template <>
void popolaVec(lasd::Vector<int>& vec) {
    unsigned int j = 0;
    for(int i: generaInt()) {
        vec[j] = i;
        j++;
    }
}

template <>
void popolaVec(lasd::Vector<double>& vec) {
    unsigned int j = 0;
    for(double i: generaDouble()) {
        vec[j] = i;
        j++;
    }
}

template <>
void popolaVec(lasd::Vector<std::string>& vec) {
    unsigned int j = 0;
    for(std::string i: generaString()) {
        vec[j] = i;
        j++;
    }
}


template <>
void popolaLst(lasd::List<int>& lst) {
    for(int i:generaInt()) {
        lst.InsertAtBack(i);
    }
}

template <>
void popolaLst(lasd::List<double>& lst) {
    for(double i:generaDouble()) {
        lst.InsertAtBack(i);
    }
}

template <>
void popolaLst(lasd::List<std::string>& lst) {
    for(std::string i:generaString()) {
        lst.InsertAtBack(i);
    }
}

template <>
void popolaStk(lasd::Stack<int>& stk) {
    for(int i:generaInt()) {
        stk.Push(i);
    }
}

template <>
void popolaStk(lasd::Stack<double>& stk) {
    for(double i:generaDouble()) {
        stk.Push(i);
    }
}

template <>
void popolaStk(lasd::Stack<std::string>& stk) {
    for(std::string i:generaString()) {
        stk.Push(i);
    }
}

template <>
void popolaQue(lasd::Queue<int>& que) {
    for(int i:generaInt()) {
        que.Enqueue(i);
    }
}

template <>
void popolaQue(lasd::Queue<double>& que) {
    for(double i:generaDouble()) {
        que.Enqueue(i);
    }
}

template <>
void popolaQue(lasd::Queue<std::string>& que) {
    for(std::string i:generaString()) {
        que.Enqueue(i);
    }
}


//Generatori
template <typename T>
std::vector<T> generaDati() {}


std::vector<int> generaInt() {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distx(0, 100);

    std::vector<int> vec;

    for(unsigned long i = 0; i<10; i++) {
        vec.push_back(distx(generator));
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}

std::vector<double> generaDouble() {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_real_distribution<double> distx(0.0, 100.0);

    std::vector<double> vec;

    for(unsigned long i = 0; i<10; i++) {
        vec.push_back(distx(generator));
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}

std::vector<std::string> generaString() {
    char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distx(0, 25);

    std::vector<std::string> vec;

    for(unsigned long i = 0; i<10; i++) {
        std::string str = "";
        str = str + alphabet[distx(generator)];
        vec.push_back(str);
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}