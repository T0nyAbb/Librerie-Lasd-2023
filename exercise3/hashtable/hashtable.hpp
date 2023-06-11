
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  unsigned long operator()(const Data&) const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable: public virtual ResizableContainer,
                 public virtual DictionaryContainer<Data> {
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;
  unsigned long a = 1;
  unsigned long b = 0;
  static const unsigned long prime = 1000000007;
  std::default_random_engine generator = std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned long> dista = std::uniform_int_distribution<unsigned long>(1, prime-1);
  std::uniform_int_distribution<unsigned long> distb = std::uniform_int_distribution<unsigned long>(0, prime-1);

  static const Hashable<Data> hash;
  unsigned long tablesize = 127;
  // ...



  // Default constructor
  HashTable() {
    a = dista(generator);
    b = distb(generator);
  }

  //copy constructor
  HashTable(const HashTable& ht) {
    size = ht.size;
    a = ht.a;
    b = ht.b;
    tablesize = ht.tablesize;
  }

  //move constructor
  HashTable(HashTable&& ht) {
    std::swap(size, ht.size);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(tablesize, ht.tablesize);
  }
  public:
  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable& operator=(const HashTable&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable& operator=(HashTable&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  virtual unsigned long HashKey(const unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
