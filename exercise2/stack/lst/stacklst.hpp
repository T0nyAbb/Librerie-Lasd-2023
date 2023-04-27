
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst: public virtual Stack<Data>, protected virtual List<Data> {
                  // Must extend Stack<Data>,
                  //             List<Data>

private:

  // ...

protected:

  using List<Data>::size;

  // ...

public:

  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const MappableContainer<Data>& con) : List<Data>(con) {}; // A stack obtained from a MappableContainer
  StackLst(MutableMappableContainer<Data>&& con) : List<Data>(std::move(con)) {}; // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst<Data>& stk) : List<Data>(stk) {};

  // Move constructor
  StackLst(StackLst<Data>&& stk) : List<Data>(std::move(stk)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst& operator=(const StackLst<Data>&);

  // Move assignment
  StackLst& operator=(StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst<Data>&) const noexcept;
  bool operator!=(const StackLst<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data&) override; // Override Stack member (copy of the value)
  void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

   using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
