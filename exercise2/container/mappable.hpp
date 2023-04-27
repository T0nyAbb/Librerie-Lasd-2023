
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "foldable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer: public virtual FoldableContainer<Data> {
                          // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using MapFunctor = std::function<void(const Data &)>;

  virtual void Map(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer: public virtual MappableContainer<Data>, public virtual PreOrderFoldableContainer<Data> {
                                  // Must extend MappableContainer<Data>,
                                  //             PreOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer operator=(const PreOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PreOrderMappableContainer operator=(PreOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void PreOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  virtual void PreOrderFold(FoldFunctor, void*) const override; // Override PreOrderFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer: public virtual MappableContainer<Data>, public virtual PostOrderFoldableContainer<Data> {
                                  // Must extend MappableContainer<Data>,
                                  //             PostOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void PostOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  virtual void PostOrderFold(FoldFunctor, void*) const override; // Override PostOrderFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer: public virtual MappableContainer<Data>,
                                 public virtual InOrderFoldableContainer<Data> 
                                 {
                                  // Must extend MappableContainer<Data>,
                                  //             InOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderMappableContainer<Data>& operator=(const InOrderMappableContainer<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  InOrderMappableContainer<Data>& operator=(InOrderMappableContainer<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const InOrderMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const InOrderMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void InOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderFoldableContainer)

  virtual void InOrderFold(arguments) const override; // Override InOrderFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer: public virtual MappableContainer<Data>,
                                public virtual BreadthFoldableContainer<Data> {
                                  // Must extend MappableContainer<Data>,
                                  //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthMappableContainer<Data>& operator=(const BreadthMappableContainer<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BreadthMappableContainer<Data>& operator=(BreadthMappableContainer<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BreadthMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BreadthMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void BreadthMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthFoldableContainer)

  virtual void BreadthFold(FoldFunctor, void*) const override; // Override BreadthFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableMappableContainer: public virtual MappableContainer<Data> {
                                  // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableMappableContainer& operator=(const MutableMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableMappableContainer& operator=(MutableMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using MutableMapFunctor = std::function<void(Data &)>;

  virtual void Map(MutableMapFunctor) = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutablePreOrderMappableContainer: public virtual MutableMappableContainer<Data>, public virtual PreOrderMappableContainer<Data> {
                                          // Must extend MutableMappableContainer<Data>,
                                          //             PreOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutablePreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutablePreOrderMappableContainer& operator=(const MutablePreOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePreOrderMappableContainer& operator=(MutablePreOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void PreOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutablePostOrderMappableContainer: public virtual MutableMappableContainer<Data>, 
                                         public virtual PostOrderMappableContainer<Data> {
                                          // Must extend MutableMappableContainer<Data>,
                                          //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutablePostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutablePostOrderMappableContainer& operator=(const MutablePostOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePostOrderMappableContainer& operator=(MutablePostOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

   using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void PostOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableInOrderMappableContainer: public virtual MutableMappableContainer<Data>,
                                       public virtual InOrderMappableContainer<Data> {
                                        // Must extend MutableMappableContainer<Data>,
                                        //             InOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableInOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableInOrderMappableContainer<Data>& operator=(const MutableInOrderMappableContainer<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableInOrderMappableContainer<Data>& operator=(MutableInOrderMappableContainer<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableInOrderMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableInOrderMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void InOrderMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableBreadthMappableContainer: public virtual MutableMappableContainer<Data>,
                                       public virtual BreadthMappableContainer<Data> {
                                        // Must extend MutableMappableContainer<Data>,
                                        //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableBreadthMappableContainer() = default; 

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const MutableBreadthMappableContainer<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  bool operator=(MutableBreadthMappableContainer<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableBreadthMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableBreadthMappableContainer<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void BreadthMap(MutableMapFunctor) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
