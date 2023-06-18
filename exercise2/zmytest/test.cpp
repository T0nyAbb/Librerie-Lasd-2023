#include "test.hpp"

#include <iostream>
#include <string>
#include <random>
#include <climits>

//menu principale
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
            lasd::List<int> lst;
            popolaMC(lst);
            lasd::BinaryTreeVec<int> btv(lst);
            menuBinaryTreeVec(btv); 
        }
        else if(tipo=="2") {
            lasd::List<double> lst;
            popolaMC(lst);
            lasd::BinaryTreeVec<double> btv(lst);
            menuBinaryTreeVec(btv);
        }
        else if(tipo=="3") {
            lasd::List<std::string> lst;
            popolaMC(lst);
            lasd::BinaryTreeVec<std::string> btv(lst);
            menuBinaryTreeVec(btv);
        }
    } else if(struttura=="2") {
        if(tipo=="1") {
            lasd::List<int> lst;
            popolaMC(lst);
            lasd::BinaryTreeLnk<int> btl(lst);
            menuBinaryTreeLnk(btl); 
        }
        else if(tipo=="2") {
            lasd::List<double> lst;
            popolaMC(lst);
            lasd::BinaryTreeLnk<double> btl(lst);
            menuBinaryTreeLnk(btl);
        }
        else if(tipo=="3") {
            lasd::List<std::string> lst;
            popolaMC(lst);
            lasd::BinaryTreeLnk<std::string> btl(lst);
            menuBinaryTreeLnk(btl);
        }
    } else if(struttura=="3") {
        if(tipo=="1") {
            lasd::BST<int> bst;
            menuBST(bst); 
        }
        else if(tipo=="2") {
            lasd::BST<double> bst;
            menuBST(bst);
        }
        else if(tipo=="3") {
            lasd::BST<std::string> bst;
            menuBST(bst);
        }        
    }
    goto MM;
}



//Selettori
std::string selezionaStruttura() {
    std::cout << "Scegli il tipo di struttura dati:" << std::endl;
    std::cout << "1: BinaryTreeVec" << std::endl;
    std::cout << "2: BinaryTreeLnk" << std::endl;
    std::cout << "3: BST" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidStruct:
    std::string scelta = "0";
    std::getline(std::cin, scelta);

    if(scelta=="1" || scelta=="2" || scelta=="3") return scelta;
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

std::string selezionaIterator() {
    std::cout << "Scegli il tipo di Iteratore:" << std::endl;
    std::cout << "1: PreOrder" << std::endl;
    std::cout << "2: PostOrder" << std::endl;
    std::cout << "3: InOrder" << std::endl;
    std::cout << "4: Breadth" << std::endl;
    std::cout << "\nInserisci il numero corrispondente alla scelta: ";
    invalidType:
    std::string scelta = "0";
    std::getline(std::cin, scelta);

    if(scelta=="1" || scelta=="2" || scelta=="3" || scelta=="4") return scelta;
    else{
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidType;
    }    
}


//menu btv
template <typename T>
void menuBinaryTreeVec(lasd::BinaryTreeVec<T>& btv) {
    BTV:
    std::cout << R"(
    ____  _                       ______             _    __             __  ___                
   / __ )(_)___  ____ ________  _/_  __/_______  ___| |  / /__  _____   /  |/  /__  ____  __  __
  / __  / / __ \/ __ `/ ___/ / / // / / ___/ _ \/ _ \ | / / _ \/ ___/  / /|_/ / _ \/ __ \/ / / /
 / /_/ / / / / / /_/ / /  / /_/ // / / /  /  __/  __/ |/ /  __/ /__   / /  / /  __/ / / / /_/ / 
/_____/_/_/ /_/\__,_/_/   \__, //_/ /_/   \___/\___/|___/\___/\___/  /_/  /_/\___/_/ /_/\__,_/  
                           /____/                                                                 
)" << std::endl;
    std::cout << "1: Iteratori" << std::endl;
    std::cout << "2: Size" << std::endl;
    std::cout << "3: Empty" << std::endl;
    std::cout << "4: Root" << std::endl;
    std::cout << "5: Visita PreOrder" << std::endl;
    std::cout << "6: Visita PostOrder" << std::endl;
    std::cout << "7: Visita InOrder" << std::endl;
    std::cout << "8: Visita Breadth" << std::endl;
    std::cout << "9: Exists" << std::endl;
    std::cout << "a: Clear" << std::endl;
    std::cout << "b: Mostra Menù BinaryTreeVec" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    NextActionBTV:
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidBTV:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
    std::string it = selezionaIterator();
    if(it=="1") {
        lasd::BTPreOrderIterator<T> itr(btv);
        menuITPre(itr);
    }
    else if(it=="2") {
        lasd::BTPostOrderIterator<T> itr(btv);
        menuITPost(itr);
    }
    else if(it=="3") {
        lasd::BTInOrderIterator<T> itr(btv);
        menuITIn(itr);
    }
    else if(it=="4") {
        lasd::BTBreadthIterator<T> itr(btv);
        menuITBre(itr);
    }
        goto NextActionBTV;
    }
    else if(scelta=="2") {
        funSize(btv);
        goto NextActionBTV;
    }
    else if(scelta=="3") {
        funEmpty(btv);
        goto NextActionBTV;
    }
    else if(scelta=="4") {
        funRoot(btv);
        goto NextActionBTV;
    }
    else if(scelta=="5") {
        funPreOrderMap(btv);
        goto NextActionBTV;
    }
    else if(scelta=="6") {
        funPostOrderMap(btv);
        goto NextActionBTV;
    }
    else if(scelta=="7") {
        funInOrderMap(btv);
        goto NextActionBTV;
    }
    else if(scelta=="8") {
        funBreadthMap(btv);
        goto NextActionBTV;
    }
    else if(scelta=="9") {
        funExists(btv);
        goto NextActionBTV;
    }
    else if(scelta=="a") {
        funClear(btv);
        goto NextActionBTV;
    }
    else if(scelta=="b") {
        goto BTV;
    }
    else if(scelta=="0") {
        btv.Clear();
        return;  
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidBTV;           
    }
}

//menu btv
template <typename T>
void menuBinaryTreeLnk(lasd::BinaryTreeLnk<T>& btl) {
    BTL:
    std::cout << R"(
    ____  _                       ______               __          __      __  ___                
   / __ )(_)___  ____ ________  _/_  __/_______  ___  / /   ____  / /__   /  |/  /__  ____  __  __
  / __  / / __ \/ __ `/ ___/ / / // / / ___/ _ \/ _ \/ /   / __ \/ //_/  / /|_/ / _ \/ __ \/ / / /
 / /_/ / / / / / /_/ / /  / /_/ // / / /  /  __/  __/ /___/ / / / ,<    / /  / /  __/ / / / /_/ / 
/_____/_/_/ /_/\__,_/_/   \__, //_/ /_/   \___/\___/_____/_/ /_/_/|_|  /_/  /_/\___/_/ /_/\__,_/  
                         /____/                                                                   
)" << std::endl;
    std::cout << "1: Iteratori" << std::endl;
    std::cout << "2: Size" << std::endl;
    std::cout << "3: Empty" << std::endl;
    std::cout << "4: Root" << std::endl;
    std::cout << "5: Visita PreOrder" << std::endl;
    std::cout << "6: Visita PostOrder" << std::endl;
    std::cout << "7: Visita InOrder" << std::endl;
    std::cout << "8: Visita Breadth" << std::endl;
    std::cout << "9: Exists" << std::endl;
    std::cout << "a: Clear" << std::endl;
    std::cout << "b: Mostra Menu BinaryTreeLnk" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    NextActionBTL:
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidBTL:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
    std::string it = selezionaIterator();
    if(it=="1") {
        lasd::BTPreOrderIterator<T> itr(btl);
        menuITPre(itr);
    }
    else if(it=="2") {
        lasd::BTPostOrderIterator<T> itr(btl);
        menuITPost(itr);
    }
    else if(it=="3") {
        lasd::BTInOrderIterator<T> itr(btl);
        menuITIn(itr);
    }
    else if(it=="4") {
        lasd::BTBreadthIterator<T> itr(btl);
        menuITBre(itr);
    }
        goto NextActionBTL;
    }
    else if(scelta=="2") {
        funSize(btl);
        goto NextActionBTL;
    }
    else if(scelta=="3") {
        funEmpty(btl);
        goto NextActionBTL;
    }
    else if(scelta=="4") {
        funRoot(btl);
        goto NextActionBTL;
    }
    else if(scelta=="5") {
        funPreOrderMap(btl);
        goto NextActionBTL;
    }
    else if(scelta=="6") {
        funPostOrderMap(btl);
        goto NextActionBTL;
    }
    else if(scelta=="7") {
        funInOrderMap(btl);
        goto NextActionBTL;
    }
    else if(scelta=="8") {
        funBreadthMap(btl);
        goto NextActionBTL;
    }
    else if(scelta=="9") {
        funExists(btl);
        goto NextActionBTL;
    }
    else if(scelta=="a") {
        funClear(btl);
        goto NextActionBTL;
    }
    else if(scelta=="b") {
        goto BTL;
    }
    else if(scelta=="0") {
        btl.Clear();
        return;  
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidBTL;           
    }
}

//menu bst
template <typename T>
void menuBST(lasd::BST<T>& bst) {
    BSTmenu:
    std::cout << R"(
    ____ ___________   __  ___                
   / __ ) ___/_  __/  /  |/  /__  ____  __  __
  / __  \__ \ / /    / /|_/ / _ \/ __ \/ / / /
 / /_/ /__/ // /    / /  / /  __/ / / / /_/ / 
/_____/____//_/    /_/  /_/\___/_/ /_/\__,_/  
                                              
)" << std::endl;
    std::cout << "1: Iteratori" << std::endl;
    std::cout << "2: Size" << std::endl;
    std::cout << "3: Empty" << std::endl;
    std::cout << "4: Root" << std::endl;
    std::cout << "5: Visita PreOrder" << std::endl;
    std::cout << "6: Visita PostOrder" << std::endl;
    std::cout << "7: Visita InOrder" << std::endl;
    std::cout << "8: Visita Breadth" << std::endl;
    std::cout << "9: Exists" << std::endl;
    std::cout << "a: Clear" << std::endl;
    std::cout << "b: Min" << std::endl;
    std::cout << "c: Remove Min" << std::endl;
    std::cout << "d: Min&Remove" << std::endl;
    std::cout << "e: Max" << std::endl;
    std::cout << "f: Remove Max" << std::endl;
    std::cout << "g: Max&Remove" << std::endl;
    std::cout << "h: Predecessor" << std::endl;
    std::cout << "i: Remove Predecessor" << std::endl;
    std::cout << "j: Predecessor&Remove" << std::endl;
    std::cout << "k: Successor" << std::endl;
    std::cout << "l: Remove Successor" << std::endl;
    std::cout << "m: Successor&Remove" << std::endl;
    std::cout << "n: Insert" << std::endl;
    std::cout << "o: Remove" << std::endl;
    std::cout << "p: Popola" << std::endl;
    std::cout << "q: Mostra Menù Bst" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    NextActionBST:
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidBST:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
if(scelta=="1") {
    std::string it = selezionaIterator();
    if(it=="1") {
        lasd::BTPreOrderIterator<T> itr(bst);
        menuITPre(itr);
    }
    else if(it=="2") {
        lasd::BTPostOrderIterator<T> itr(bst);
        menuITPost(itr);
    }
    else if(it=="3") {
        lasd::BTInOrderIterator<T> itr(bst);
        menuITIn(itr);
    }
    else if(it=="4") {
        lasd::BTBreadthIterator<T> itr(bst);
        menuITBre(itr);
    }
        goto NextActionBST;
    }
    else if(scelta=="2") {
        funSize(bst);
        goto NextActionBST;
    }
    else if(scelta=="3") {
        funEmpty(bst);
        goto NextActionBST;
    }
    else if(scelta=="4") {
        funRoot(bst);
        goto NextActionBST;
    }
    else if(scelta=="5") {
        funPreOrderMap(bst);
        goto NextActionBST;
    }
    else if(scelta=="6") {
        funPostOrderMap(bst);
        goto NextActionBST;
    }
    else if(scelta=="7") {
        funInOrderMap(bst);
        goto NextActionBST;
    }
    else if(scelta=="8") {
        funBreadthMap(bst);
        goto NextActionBST;
    }
    else if(scelta=="9") {
        funExists(bst);
        goto NextActionBST;
    }
    else if(scelta=="a") {
        bst.Clear();
        std::cout << "\nAlbero svuotato!" << std::endl;
        goto NextActionBST;
    }
    else if(scelta=="b") {
        funMin(bst);
        goto NextActionBST;
    }
    else if(scelta=="c") {
        funRemoveMin(bst);
        goto NextActionBST;
    }
    else if(scelta=="d") {
        funMinNRemove(bst);
        goto NextActionBST;
    }
    else if(scelta=="e") {
        funMax(bst);
        goto NextActionBST;
    }
    else if(scelta=="f") {
        funRemoveMax(bst);
        goto NextActionBST;
    }
    else if(scelta=="g") {
        funMaxNRemove(bst);
        goto NextActionBST;
    }
    else if(scelta=="h") {
        funPredecessor(bst);
        goto NextActionBST;
    }
    else if(scelta=="i") {
        funRemovePredecessor(bst);
        goto NextActionBST;
    }
    else if(scelta=="j") {
        funPredecessorNRemove(bst);
        goto NextActionBST;
    }
    else if(scelta=="k") {
        funSuccessor(bst);
        goto NextActionBST;
    }
    else if(scelta=="l") {
        funRemoveSuccessor(bst);
        goto NextActionBST;
    }
    else if(scelta=="m") {
        funSuccessorNRemove(bst);
        goto NextActionBST;
    }
    else if(scelta=="n") {
        funInsert(bst);
        goto NextActionBST;
    }
    else if(scelta=="o") {
        funRemove(bst);
        goto NextActionBST;
    }
    else if(scelta=="p") {
        popolaBST(bst);
        goto NextActionBST;
    }
    else if(scelta=="q") {
        goto BSTmenu;
    }
    else if(scelta=="0") {
        bst.Clear();
        return;  
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidBST;           
    }
}



//menu iterator
template <typename T>
void menuITPre(lasd::BTPreOrderIterator<T>& it) {
    ITpre:

    std::cout << R"(
    ______                  __                __  ___                
   /  _/ /____  _________ _/ /_____  _____   /  |/  /__  ____  __  __
   / // __/ _ \/ ___/ __ `/ __/ __ \/ ___/  / /|_/ / _ \/ __ \/ / / /
 _/ // /_/  __/ /  / /_/ / /_/ /_/ / /     / /  / /  __/ / / / /_/ / 
/___/\__/\___/_/   \__,_/\__/\____/_/     /_/  /_/\___/_/ /_/\__,_/  
                                                                     
)" << std::endl;
    std::cout << "1: Visualizza dato" << std::endl;
    std::cout << "2: Avanza" << std::endl;
    std::cout << "3: Terminato" << std::endl;
    std::cout << "4: Reset" << std::endl;
    std::cout << "5: Mostra Menù Iteratore" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    NextActionITpre:
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidITpre:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
        std::cout << "il nodo attualmente puntato all'indirizzo: " << &(*it) << " contiene: " << *it << std::endl;
        goto NextActionITpre;
    }
    else if(scelta=="2") {
        funForward(it);
        goto NextActionITpre;
    }
    else if(scelta=="3") {
        funTerminated(it);
        goto NextActionITpre;    
    }
    else if(scelta=="4") {
        funReset(it);
        goto NextActionITpre; 
    }
    else if(scelta=="5") {
        goto ITpre;
    }
    else if(scelta=="0") {
        return;  
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidITpre;            
    }

}

template <typename T>
void menuITPost(lasd::BTPostOrderIterator<T>& it) {
    ITpost:
    std::cout << R"(
    ______                  __                __  ___                
   /  _/ /____  _________ _/ /_____  _____   /  |/  /__  ____  __  __
   / // __/ _ \/ ___/ __ `/ __/ __ \/ ___/  / /|_/ / _ \/ __ \/ / / /
 _/ // /_/  __/ /  / /_/ / /_/ /_/ / /     / /  / /  __/ / / / /_/ / 
/___/\__/\___/_/   \__,_/\__/\____/_/     /_/  /_/\___/_/ /_/\__,_/  
                                                                     
)" << std::endl;
    std::cout << "1: Visualizza dato" << std::endl;
    std::cout << "2: Avanza" << std::endl;
    std::cout << "3: Terminato" << std::endl;
    std::cout << "4: Reset" << std::endl;
    std::cout << "5: Mostra Menù Iteratore" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    NextActionITpost:
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidITpost:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
        funData(it);
        goto NextActionITpost;
    }
    else if(scelta=="2") {
        funForward(it);
        goto NextActionITpost;
    }
    else if(scelta=="3") {
        funTerminated(it);
        goto NextActionITpost;    
    }
    else if(scelta=="4") {
        funReset(it);
        goto NextActionITpost; 
    }
    else if(scelta=="5") {
        goto ITpost;
    }
    else if(scelta=="0") {
        return;  
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidITpost;            
    }
}

template <typename T>
void menuITIn(lasd::BTInOrderIterator<T>& it) {
    ITin:
    
    std::cout << R"(
    ______                  __                __  ___                
   /  _/ /____  _________ _/ /_____  _____   /  |/  /__  ____  __  __
   / // __/ _ \/ ___/ __ `/ __/ __ \/ ___/  / /|_/ / _ \/ __ \/ / / /
 _/ // /_/  __/ /  / /_/ / /_/ /_/ / /     / /  / /  __/ / / / /_/ / 
/___/\__/\___/_/   \__,_/\__/\____/_/     /_/  /_/\___/_/ /_/\__,_/  
                                                                     
)" << std::endl;
    std::cout << "1: Visualizza dato" << std::endl;
    std::cout << "2: Avanza" << std::endl;
    std::cout << "3: Terminato" << std::endl;
    std::cout << "4: Reset" << std::endl;
    std::cout << "5: Mostra Menù Iteratore" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    NextActionITin:
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidITin:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
        funData(it);
        goto NextActionITin;
    }
    else if(scelta=="2") {
        funForward(it);
        goto NextActionITin;
    }
    else if(scelta=="3") {
        funTerminated(it);
        goto NextActionITin;    
    }
    else if(scelta=="4") {
        funReset(it);
        goto NextActionITin; 
    }
        else if(scelta=="5") {
        goto ITin;
    }
    else if(scelta=="0") {
        return;  
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidITin;            
    }
}

template <typename T>
void menuITBre(lasd::BTBreadthIterator<T>& it) {
    ITbre:
    
    std::cout << R"(
    ______                  __                __  ___                
   /  _/ /____  _________ _/ /_____  _____   /  |/  /__  ____  __  __
   / // __/ _ \/ ___/ __ `/ __/ __ \/ ___/  / /|_/ / _ \/ __ \/ / / /
 _/ // /_/  __/ /  / /_/ / /_/ /_/ / /     / /  / /  __/ / / / /_/ / 
/___/\__/\___/_/   \__,_/\__/\____/_/     /_/  /_/\___/_/ /_/\__,_/  
                                                                     
)" << std::endl;
    std::cout << "1: Visualizza dato" << std::endl;
    std::cout << "2: Avanza" << std::endl;
    std::cout << "3: Terminato" << std::endl;
    std::cout << "4: Reset" << std::endl;
    std::cout << "5: Mostra Menù Iteratore" << std::endl;
    std::cout << "0: Indietro" << std::endl;
    NextActionITbre:
    std::cout << "\nInserisci il carattere corrispondente alla scelta: ";
    invalidITbre:
    std::string scelta = "";
    std::getline(std::cin, scelta);
    std::cout << "\n\n";
    if(scelta=="1") {
        funData(it);
        goto NextActionITbre;
    }
    else if(scelta=="2") {
        funForward(it);
        goto NextActionITbre;
    }
    else if(scelta=="3") {
        funTerminated(it);
        goto NextActionITbre;    
    }
    else if(scelta=="4") {
        funReset(it);
        goto NextActionITbre; 
    }
    else if(scelta=="5") {
        goto ITbre;
    }
    else if(scelta=="0") {
        return;  
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidITbre;            
    }

}


//funzioni
template <typename T>
void funEmpty(lasd::BinaryTree<T>& bt) {
    bool res;
    std::cout << "\nL'Albero " << ((res = bt.Empty()) ? "è vuoto" : "non è vuoto")  <<std::endl;
};

template <typename T>
void funSize(lasd::BinaryTree<T>& bt) {
    std::cout << "\nL'Albero ha size: " << bt.Size() << std::endl;  
};

template <typename T>
void funRoot(lasd::BinaryTree<T>& bt) {
    std::cout << "\nLa radice dell'albero è: " << bt.Root().Element() << std::endl;
};

template <typename T>
void funClear(lasd::MutableBinaryTree<T>& bt) {
    bt.Clear();
    std::cout << "\nAlbero svuotato!" << std::endl;
}

template <typename T>
void funExists(lasd::BinaryTree<T>& bt) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi controllare: ";
        std::cin >> value;
        std::string text = bt.Exists(value) ? ("L'elemento è nell'albero.") : ("L'elemento non è nell'albero.");
        std::cout << text << std::endl;
        std::cout << "Vuoi controllare un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);
}

template <typename T>
void funPreOrderMap(lasd::BinaryTree<T>& bt) {
        std::cout << "\nStampo l'albero in pre-order: " << std::endl;
        bt.PreOrderMap(&MapPrint<T>);
        std::cout << "\n\n";   
}

template <typename T>
void funPostOrderMap(lasd::BinaryTree<T>& bt) {
        std::cout << "\nStampo l'albero in post-order: " << std::endl;
        bt.PostOrderMap(&MapPrint<T>);
        std::cout << "\n\n";   
}

template <typename T>
void funInOrderMap(lasd::BinaryTree<T>& bt) {
        std::cout << "\nStampo l'albero in in-order: " << std::endl;
        bt.InOrderMap(&MapPrint<T>);
        std::cout << "\n\n";   
}

template <typename T>
void funBreadthMap(lasd::BinaryTree<T>& bt) {
        std::cout << "\nStampo l'albero in ampiezza: " << std::endl;
        bt.BreadthMap(&MapPrint<T>);
        std::cout << "\n\n";   
}

template <typename T>
void funMin(lasd::BST<T>& bst) {
    std::cout << "\nIl minimo del BST è: " << bst.Min() << std::endl;
}

template <typename T>
void funRemoveMin(lasd::BST<T>& bst) {
    bst.RemoveMin();
    std::cout << "\nMinimo rimosso"  << std::endl;
    std::cout << "Il nuovo minimo del BST è: " << bst.Min() << std::endl;
}

template <typename T>
void funMinNRemove(lasd::BST<T>& bst) {
    std::cout << "Rimuovo il minimo del BST: " << bst.MinNRemove() << std::endl;
    std::cout << "Il nuovo minimo del BST è: " << bst.Min() << std::endl;
}

template <typename T>
void funMax(lasd::BST<T>& bst) {
    std::cout << "\nIl massimo del BST è: " << bst.Max() << std::endl;    
}

template <typename T>
void funRemoveMax(lasd::BST<T>& bst) {
    bst.RemoveMax();
    std::cout << "\nMassimo rimosso"  << std::endl;
    std::cout << "Il nuovo massimo del BST è: " << bst.Max() << std::endl;
}

template <typename T>
void funMaxNRemove(lasd::BST<T>& bst) {
    std::cout << "Rimuovo il massimo del BST: " << bst.MaxNRemove() << std::endl;
    std::cout << "Il nuovo massimo del BST è: " << bst.Max() << std::endl;
}

template <typename T>
void funPredecessor(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore di cui vuoi cercare il predecessore: ";
        std::cin >> value;
        try {
            std::cout << bst.Predecessor(value) << " è il predecessore di " << value << std::endl; 
        } catch(std::length_error ex) {
            std::cout << ex.what() << std::endl;
        }  
        
        std::cout << "Vuoi cercare un altro predecessore? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}

template <typename T>
void funRemovePredecessor(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore di cui vuoi rimuovere il predecessore: ";
        std::cin >> value;
        try {
            bst.RemovePredecessor(value);
            std::cout << "\nPredecessore di " << value << " rimosso!" << std::endl; 
        } catch(std::length_error ex) {
            std::cout << ex.what() << std::endl;
        }  
        
        std::cout << "Vuoi cercare un altro predecessore? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta); 
}

template <typename T>
void funPredecessorNRemove(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore di cui vuoi rimuovere il predecessore: ";
        std::cin >> value;
        try {
            std::cout << bst.PredecessorNRemove(value) << " è il predecessore di " << value << std::endl;
            std::cout << "Rimosso!" << std::endl; 
        } catch(std::length_error ex) {
            std::cout << ex.what() << std::endl;
        }  
        
        std::cout << "Vuoi cercare un altro predecessore? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}


template <typename T>
void funSuccessor(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore di cui vuoi cercare il successore: ";
        std::cin >> value;
        try {
            std::cout << bst.Successor(value) << " è il successore di " << value << std::endl; 
        } catch(std::length_error ex) {
            std::cout << ex.what() << std::endl;
        }  
        
        std::cout << "Vuoi cercare un altro successore? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}

template <typename T>
void funRemoveSuccessor(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore di cui vuoi rimuovere il successore: ";
        std::cin >> value;
        try {
            bst.RemoveSuccessor(value);
            std::cout << "\nSuccessore di " << value << " rimosso!" << std::endl; 
        } catch(std::length_error ex) {
            std::cout << ex.what() << std::endl;
        }  
        
        std::cout << "Vuoi cercare un altro successore? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta); 
}


template <typename T>
void funSuccessorNRemove(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore di cui vuoi rimuovere il successore: ";
        std::cin >> value;
        try {
            std::cout << bst.SuccessorNRemove(value) << " è il successore di " << value << std::endl;
            std::cout << "Rimosso!" << std::endl; 
        } catch(std::length_error ex) {
            std::cout << ex.what() << std::endl;
        }  
        
        std::cout << "Vuoi cercare un altro successore? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);     
}

template <typename T>
void funInsert(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi inserire nel bst: ";
        std::cin >> value;
        std::string text = bst.Insert(value) ? ("Inserito.") : ("Non inserito.");
        std::cout << text << std::endl;
        
        std::cout << "Vuoi inserire un altro elemento? (y/n): ";
        char res;
        std::cin >> res;
        resta = (res == 'y');
    } while (resta);        
}

template <typename T>
void funRemove(lasd::BST<T>& bst) {
    T value;
    bool resta = false;
    do {
        std::cout << "\nInserisci il valore che vuoi rimuovere dal dizionario: ";
        std::cin >> value;
        if(bst.Remove(value)) {
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
void funData(lasd::ForwardIterator<T>& it) {
    std::cout << "il nodo attualmente puntato all'indirizzo: " << &(*it) << " contiene il dato: " << *it << std::endl;
}

template <typename T>
void funTerminated(lasd::ForwardIterator<T>& it) {
    std::string text = it.Terminated() ? ("L'iteratore è Terminato.") : ("L'iteratore non è Terminato.");
    std::cout << text << std::endl;
}

template <typename T>
void funReset(lasd::ResettableIterator<T>& it) {
        std::cout << "Resetto l'iteratore..." << std::endl;
        it.Reset();
        std::cout << "\nIteratore resettato con successo!" << std::endl;
        std::cout << "\nNuovo Indirizzo puntato: " << &(*it) << " contenuto: " << *it << std::endl;   
}

template <typename T>
void funForward(lasd::ForwardIterator<T>& it) {
        std::cout << "Avanzo l'iteratore..." << std::endl;
        try {
            ++it;
            std::cout << "\nIteratore avanzato con successo!" << std::endl;
            std::cout << "\nNuovo Indirizzo puntato: " << &(*it) << " contenuto: " << *it << std::endl; 
        } catch(std::out_of_range ex) {
            std::cout << ex.what() << std::endl;
        }
}





//Popolazione
template <>
void popolaBST(lasd::BST<int>& bst) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:100): " << std::endl;
    invalidBSTint:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=100) {
        for(int i: generaInt(n)) {
            bst.Insert(i);
        }
    } 
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidBSTint;
    }   
}

template <>
void popolaBST(lasd::BST<double>& bst) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:100): " << std::endl;
    invalidBSTdouble:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=100) {
        for(int i: generaDouble(n)) {
            bst.Insert(i);
        }
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidBSTdouble;
    }  
}

template <>
void popolaBST(lasd::BST<std::string>& bst) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:100): " << std::endl;
    invalidBSTstring:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=100) {
        for(std::string i: generaString(n)) {
            bst.Insert(i);
        }
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidBSTstring;
    }  
}



template <>
void popolaMC(lasd::List<int>& lst) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidMCint:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(int i: generaInt(n)) {
            lst.InsertAtBack(i);
        }
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidMCint;
    }  
}

template <>
void popolaMC(lasd::List<double>& lst) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidMCdouble:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(double i: generaDouble(n)) {
            lst.InsertAtBack(i);
        }
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidMCdouble;
    } 
}

template <>
void popolaMC(lasd::List<std::string>& lst) {
    std::cout << "\nQuanti elementi vuoi generare (min:1) (max:1.000.000): " << std::endl;
    invalidMCstring:
    std::string num = "";
    std::getline(std::cin, num);
    unsigned long n = std::stoul(num);
    if(n>0 && n<=1000000) {
        for(std::string i: generaString(n)) {
            lst.InsertAtBack(i);
        }
    }
    else {
        std::cout << "\nScelta non valida riprova:" << std::endl;
        goto invalidMCstring;
    } 
}






//Generatori
std::vector<int> generaInt(unsigned long dim) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distr(INT_MIN, INT_MAX);

    std::vector<int> vec;

    for(unsigned long i = 0; i<dim; i++) {
        vec.push_back(distr(generator));
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}

std::vector<double> generaDouble(unsigned long dim) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_real_distribution<double> distr(__DBL_MIN__, __DBL_MAX__);

    std::vector<double> vec;

    for(unsigned long i = 0; i<dim; i++) {
        vec.push_back(distr(generator));
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}

std::vector<std::string> generaString(unsigned long dim) {
    const char charset[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distr(0, sizeof(charset)-1);

    std::vector<std::string> vec;

    for(unsigned long i = 0; i<dim; i++) {
        std::string str = "";
        int charsToGenerate = distr(generator);
        while(str.length()<charsToGenerate || str.length() < 4) {
            str+=(charset[distr(generator)]);
        }
        vec.push_back(str);
    }
    std::cout << "\nGenerazione casuale completata\n" << std::endl;
    return vec;
}




