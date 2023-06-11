
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

#include "string"
#include <iostream>

/* ************************************************************************** */

//test
void test();

//menù
template <typename T>
void menuHashTableClsAdr(lasd::HashTableClsAdr<T>&);

template <typename T>
void menuHashTableOpnAdr(lasd::HashTableOpnAdr<T>&);

//selettori
std::string selezionaStruttura();
std::string selezionaTipo();

//funzioni
template <typename T>
void funInsertD(lasd::HashTable<T>&);

template <typename T>
void funRemoveD(lasd::HashTable<T>&);

template <typename T>
void funResize(lasd::HashTable<T>&);

template <typename T>
void funExists(lasd::HashTable<T>&);

template <typename T>
void funClear(lasd::HashTable<T>&);

template <typename T>
void funEmpty(lasd::HashTable<T>&);

template <typename T>
void funSize(lasd::HashTable<T>&);

//popolamento

//HashTableClsAdr
template <typename T>
void popolaHTC(lasd::HashTableClsAdr<T>&) {}

template <>
void popolaHTC(lasd::HashTableClsAdr<int>&);

template <>
void popolaHTC(lasd::HashTableClsAdr<double>&);

template <>
void popolaHTC(lasd::HashTableClsAdr<std::string>&);

//HashTableOpnAdr
template <typename T>
void popolaHTO(lasd::HashTableOpnAdr<T>&) {}

template <>
void popolaHTO(lasd::HashTableOpnAdr<int>&);

template <>
void popolaHTO(lasd::HashTableOpnAdr<double>&);

template <>
void popolaHTO(lasd::HashTableOpnAdr<std::string>&);

//generatori
template <typename T>
std::vector<T> generaDati() {};

std::vector<int> generaInt(unsigned long);

std::vector<double> generaDouble(unsigned long);

std::vector<std::string> generaString(unsigned long);

/* ************************************************************************** */

#endif
