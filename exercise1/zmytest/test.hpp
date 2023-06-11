
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../list/list.hpp"
#include "../vector/vector.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

#include <string>
#include <iostream>

/* ************************************************************************** */

//test
void test();


//menù
template <typename T>
void menuStack(lasd::Stack<T>&);

template <typename T>
void menuQueue(lasd::Queue<T>&);

template <typename T>
void menuList(lasd::List<T>&);

template <typename T>
void menuVector(lasd::Vector<T>&);


//selettori
std::string selezionaStruttura();
std::string selezionaTipo();

//popolamento

//vector
template <typename T>
void popolaVec(lasd::Vector<T>&) {};

template <>
void popolaVec(lasd::Vector<int>&);

template <>
void popolaVec(lasd::Vector<double>&);

template <>
void popolaVec(lasd::Vector<std::string>&);

//list
template <typename T>
void popolaLst(lasd::List<T>&) {};

template <>
void popolaLst(lasd::List<int>&);

template <>
void popolaLst(lasd::List<double>&);

template <>
void popolaLst(lasd::List<std::string>&);

//Stack
template <typename T>
void popolaStk(lasd::Stack<T>&) {};

template <>
void popolaStk(lasd::Stack<int>&);

template <>
void popolaStk(lasd::Stack<double>&);

template <>
void popolaStk(lasd::Stack<std::string>&);

//Queue
template <typename T>
void popolaQue(lasd::Queue<T>&) {};

template <>
void popolaQue(lasd::Queue<int>&);

template <>
void popolaQue(lasd::Queue<double>&);

template <>
void popolaQue(lasd::Queue<std::string>&);


//Operazioni
template <typename T>
void funEmpty(lasd::LinearContainer<T>&) {};

template <typename T>
void funSize(lasd::LinearContainer<T>&) {};

template <typename T>
void funFront(lasd::LinearContainer<T>&);

template <typename T>
void funBack(lasd::LinearContainer<T>&);

template <typename T>
void funExists(lasd::LinearContainer<T>&);

template <typename T>
void funSort(lasd::Vector<T>&);

template <typename T>
void funPush(lasd::Stack<T>&);

template <typename T>
void funEnqueue(lasd::Queue<T>&);

template <typename T>
void funPop(lasd::Stack<T>&);

template<typename T>
void funDequeue(lasd::Queue<T>&);

template <typename T>
void funTop(lasd::Stack<T>&);

template <typename T>
void funHead(lasd::Queue<T>&);

template <typename T>
void funTopPop(lasd::Stack<T>&);

template <typename T>
void funHeadNDequeue(lasd::Queue<T>&);

template <typename T>
void funInsertD(lasd::DictionaryContainer<T>&);

template <typename T>
void funRemoveD(lasd::DictionaryContainer<T>&);

template <typename T>
void funInsertAtBack(lasd::List<T>&);

template <typename T>
void funInsertAtFront(lasd::List<T>&);

template <typename T>
void funFrontNRemove(lasd::List<T>&);

template <typename T>
std::vector<T> generaDati() {};

std::vector<int> generaInt();

std::vector<double> generaDouble();

std::vector<std::string> generaString();

template <typename T>
void MapPrint(const T& dat) {
  std::cout << dat << " ";
}







/* ************************************************************************** */

#endif
