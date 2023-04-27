
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer: public virtual MutablePreOrderMappableContainer<Data>, public virtual MutablePostOrderMappableContainer<Data> {
                        // Must extend MutablePreOrderMappableContainer<Data>,
                        //             MutablePostOrderMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator=(const LinearContainer<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  LinearContainer& operator=(LinearContainer<Data>&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.
  bool operator!=(const LinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator[](const unsigned long) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data& operator[](const unsigned long) = 0; // (mutable version; concrete function must throw std::out_of_range when out of range)

  virtual const Data& Front() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Front() = 0; // (mutable version; concrete function must throw std::length_error when empty)

  virtual const Data& Back() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Back() = 0; // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  virtual void PreOrderFold(FoldFunctor, void*) const override; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  virtual void PostOrderFold(FoldFunctor, void*) const override; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

   using typename MappableContainer<Data>::MapFunctor;

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  virtual void PreOrderMap(MapFunctor) const override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  virtual void PostOrderMap(MapFunctor) const override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  virtual void PreOrderMap(MutableMapFunctor) override; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  virtual void PostOrderMap(MutableMapFunctor) override; // Override MutablePostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer: public virtual LinearContainer<Data> {
                                // Must extend LinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
 virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer& operator=(const SortableLinearContainer<Data> &) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  SortableLinearContainer& operator=(SortableLinearContainer<Data>&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SortableLinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.
  bool operator!=(const SortableLinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member function

  virtual void Sort() = 0;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
