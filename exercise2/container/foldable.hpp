
#ifndef FOLDABLE_HPP
#define FOLDABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class FoldableContainer: public virtual TestableContainer<Data>  {
                          // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  FoldableContainer& operator=(FoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using FoldFunctor = std::function<void(const Data &, void *)>;

  virtual void Fold(FoldFunctor, void*) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer: public virtual FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PreOrderFold(FoldFunctor, void*) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer: public virtual FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderFoldableContainer<Data>& operator=(const PostOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PostOrderFoldableContainer<Data>& operator=(PostOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderFoldableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PostOrderFoldableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PostOrderFold(FoldFunctor, void*) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer: public virtual FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderFoldableContainer<Data>& operator=(const InOrderFoldableContainer<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  InOrderFoldableContainer<Data>& operator=(InOrderFoldableContainer<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const InOrderFoldableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const InOrderFoldableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void InOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer: public virtual FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthFoldableContainer<Data>& operator=(const BreadthFoldableContainer<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BreadthFoldableContainer<Data>& operator=(BreadthFoldableContainer<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BreadthFoldableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BreadthFoldableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void BreadthFold(FoldFunctor, void*) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
