
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer {
                            // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~DictionaryContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data &); // Copy of the value
  virtual bool Insert(Data &&) noexcept; // Move of the value
  // type Remove(argument) specifiers;

  // type InsertAll(argument) specifiers; // Copy of the value; From MappableContainer; True if all are inserted
  // type InsertAll(argument) specifiers; // Move of the value; From MutableMappableContainer; True if all are inserted
  // type RemoveAll(argument) specifiers; // From MappableContainer; True if all are removed

  // type InsertSome(argument) specifiers; // Copy of the value; From MappableContainer; True if some is inserted
  // type InsertSome(argument) specifiers; // Move of the value; From MutableMappableContainer; True if some is inserted
  // type RemoveSome(argument) specifiers; // From MappableContainer; True if some is removed

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
