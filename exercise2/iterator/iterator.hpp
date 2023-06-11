#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Iterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  Iterator<Data>& operator=(const Iterator<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Iterator<Data>& operator=(Iterator<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Iterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Iterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator*() const = 0; // (non-mutable version; concrete function must throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class MutableIterator: public virtual Iterator<Data> {
                        // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableIterator<Data>& operator=(const MutableIterator<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableIterator<Data>& operator=(MutableIterator<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& operator*() = 0; // (mutable version; concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator: public virtual Iterator<Data> {
                        // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ForwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ForwardIterator<Data>& operator=(const ForwardIterator<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  ForwardIterator<Data>& operator=(ForwardIterator<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ForwardIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ForwardIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual ForwardIterator<Data>& operator++() = 0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BackwardIterator {
                          // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BackwardIterator() specifiers

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

  // type operator--() specifiers; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BidirectionalIterator {
                              // Must extend ForwardIterator<Data>,
                              //             BackwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BidirectionalIterator() specifiers

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

  // type Terminated() specifiers; // Override Iterator member

  // type ForwardTerminated() specifiers; // (concrete function should not throw exceptions)

  // type BackwardTerminated() specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator: public virtual Iterator<Data> {
                            // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ResettableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResettableIterator<Data>& operator=(const ResettableIterator<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  ResettableIterator<Data>& operator=(ResettableIterator<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResettableIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ResettableIterator<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Reset() noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
