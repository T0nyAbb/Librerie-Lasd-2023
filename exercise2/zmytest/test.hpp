#ifndef MYTEST_HPP
#define MYTEST_HPP


#include "../iterator/iterator.hpp"
#include "../list/list.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

#include <iostream>

/* ************************************************************************** */

//test
void test();

//menù
template <typename T>
void menuBinaryTreeVec(lasd::BinaryTreeVec<T>&);

template <typename T>
void menuBinaryTreeLnk(lasd::BinaryTreeLnk<T>&);

template <typename T>
void menuBST(lasd::BST<T>&);

template <typename T>
void menuITPre(lasd::BTPreOrderIterator<T>&);

template <typename T>
void menuITPost(lasd::BTPostOrderIterator<T>&);

template <typename T>
void menuITIn(lasd::BTInOrderIterator<T>&);

template <typename T>
void menuITBre(lasd::BTBreadthIterator<T>&);

//selettori
std::string selezionaStruttura();
std::string selezionaTipo();
std::string selezionaIterator();

//popolamento

//BST
template <typename T>
void popolaBST(lasd::BST<T>&) {};

template <>
void popolaBST(lasd::BST<int>&);

template <>
void popolaBST(lasd::BST<double>&);

template <>
void popolaBST(lasd::BST<std::string>&);

//MappableContainer
template <typename T>
void popolaMC(lasd::List<T>&) {};

template <>
void popolaMC(lasd::List<int>&);

template <>
void popolaMC(lasd::List<double>&);

template <>
void popolaMC(lasd::List<std::string>&);

//operazioni
template <typename T>
void funEmpty(lasd::BinaryTree<T>&);

template <typename T>
void funSize(lasd::BinaryTree<T>&);

template <typename T>
void funRoot(lasd::BinaryTree<T>&);

template <typename T>
void funClear(lasd::MutableBinaryTree<T>&);

template <typename T>
void funExists(lasd::BinaryTree<T>&);

template <typename T>
void funPreOrderMap(lasd::BinaryTree<T>&);

template <typename T>
void funPostOrderMap(lasd::BinaryTree<T>&);

template <typename T>
void funInOrderMap(lasd::BinaryTree<T>&);

template <typename T>
void funBreadthMap(lasd::BinaryTree<T>&);

template <typename T>
void funMin(lasd::BST<T>&);

template <typename T>
void funRemoveMin(lasd::BST<T>&);

template <typename T>
void funMinNRemove(lasd::BST<T>&);

template <typename T>
void funMax(lasd::BST<T>&);

template <typename T>
void funRemoveMax(lasd::BST<T>&);

template <typename T>
void funMaxNRemove(lasd::BST<T>&);

template <typename T>
void funPredecessor(lasd::BST<T>&);

template <typename T>
void funRemovePredecessor(lasd::BST<T>&);

template <typename T>
void funPredecessorNRemove(lasd::BST<T>&);

template <typename T>
void funSuccessor(lasd::BST<T>&);

template <typename T>
void funRemoveSuccessor(lasd::BST<T>&);

template <typename T>
void funSuccessorNRemove(lasd::BST<T>&);

template <typename T>
void funInsert(lasd::BST<T>&);

template <typename T>
void funRemove(lasd::BST<T>&);

template <typename T>
void funData(lasd::ForwardIterator<T>&);

template <typename T>
void funForward(lasd::ForwardIterator<T>&);

template <typename T>
void funTerminated(lasd::ForwardIterator<T>&);

template <typename T>
void funReset(lasd::ResettableIterator<T>&);


//generatori
template <typename T>
std::vector<T> generaDati() {};

std::vector<int> generaInt(unsigned long);

std::vector<double> generaDouble(unsigned long);

std::vector<std::string> generaString(unsigned long);

//stampa
template <typename T>
inline void MapPrint(const T& dat) {std::cout << dat << " ";}

/* ************************************************************************** */

#endif
