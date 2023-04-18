
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: public virtual Queue<Data>, protected virtual Vector<Data> {
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;

  // ...

public:

  // Default constructor
  // QueueVec() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A queue obtained from a MappableContainer
  // QueueVec(argument) specifiers; // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);

  // Move constructor
  // QueueVec(argument);

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  // Move assignment
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member

  // type Size() specifiers; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  // type Expand() specifiers;
  // type Reduce() specifiers;
  // type SwapVectors(arguments) specifiers;

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
