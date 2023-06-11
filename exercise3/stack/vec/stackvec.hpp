
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: public virtual Stack<Data>, protected virtual Vector<Data>{
                  // Must extend Stack<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

   using Vector<Data>::size;
   using Vector<Data>::Elements;
   unsigned long index = 0;

  // ...

public:

  // Default constructor
  StackVec() : Vector<Data>(4) {};

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const MappableContainer<Data>&); // A stack obtained from a MappableContainer
  StackVec(MutableMappableContainer<Data>&&) noexcept; // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec<Data>&);

  // Move constructor
  StackVec(StackVec<Data>&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec<Data>& operator=(const StackVec<Data>&);

  // Move assignment
  StackVec<Data>& operator=(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec<Data>&) const noexcept;
  bool operator!=(const StackVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data&) override; // Override Stack member (copy of the value)
  void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
