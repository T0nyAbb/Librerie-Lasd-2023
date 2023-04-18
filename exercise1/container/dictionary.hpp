
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer: public virtual TestableContainer<Data> {
                            // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator=(const DictionaryContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  DictionaryContainer& operator=(DictionaryContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const DictionaryContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data &) = 0; // Copy of the value
  virtual bool Insert(Data &&) noexcept = 0; // Move of the value
  virtual bool Remove(const Data &) = 0;

  bool InsertAll(const MappableContainer<Data>&); // Copy of the value; From MappableContainer; True if all are inserted
  bool InsertAll(MutableMappableContainer<Data> &&); // Move of the value; From MutableMappableContainer; True if all are inserted
  bool RemoveAll(const MappableContainer<Data>&); // From MappableContainer; True if all are removed

  bool InsertSome(const MappableContainer<Data> &); // Copy of the value; From MappableContainer; True if some is inserted
  bool InsertSome(MutableMappableContainer<Data> &&); // Move of the value; From MutableMappableContainer; True if some is inserted
  bool RemoveSome(const MappableContainer<Data> &); // From MappableContainer; True if some is removed

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
