
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector: public virtual ResizableContainer, public virtual SortableLinearContainer<Data>{
                // Must extend ResizableContainer,
                //             SortableLinearContainer<Data>

private:

  // ...

protected:

  using Container::size;
  Data* Elements = nullptr;

  // ...

public:

  // Default constructor
   Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
   Vector(const unsigned long); // A vector with a given initial dimension
   Vector(const MappableContainer<Data> &); // A vector obtained from a MappableContainer
   Vector(MutableMappableContainer<Data> &&); // A vector obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector &);

  // Move constructor
  Vector(Vector &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector & operator=(const Vector &);

  // Move assignment
  Vector & operator=(Vector &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const Vector &) const noexcept;
  inline bool operator!=(const Vector &) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  void Resize(const unsigned long) override; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data & operator[](const unsigned long) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data & operator[](const unsigned long) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  const Data & Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data & Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  const Data & Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data & Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  void Sort() noexcept override; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
