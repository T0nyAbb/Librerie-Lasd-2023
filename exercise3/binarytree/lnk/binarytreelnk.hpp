
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: public virtual MutableBinaryTree<Data> {
                      // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using Container::size;
  


  // ...

public:
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  struct NodeLnk: virtual MutableNode { // Must extend MutableNode
  
  private:

    // ...

  protected:

    // ...

  public:
    
    //info
    NodeLnk * left = nullptr;
    NodeLnk * right = nullptr;
    Data info;

    //default constructor
    NodeLnk() = default;

    //specific constructors
    NodeLnk(const Data&);

    NodeLnk(Data&&) noexcept;

    //copy constructor
    NodeLnk(const NodeLnk&);

    //move constructor
    NodeLnk(NodeLnk&&) noexcept;

    //destructor
    virtual ~NodeLnk();

    //copy assignment
    NodeLnk& operator=(const NodeLnk&);

    //move assignment
    NodeLnk& operator=(NodeLnk&&) noexcept;

    //comparison operators
    bool operator==(const NodeLnk&) const noexcept;
    bool operator!=(const NodeLnk&) const noexcept;

    //functions
    const Data& Element() const noexcept override;
    Data& Element() noexcept override;
    bool IsLeaf() const noexcept override;
    bool HasRightChild() const noexcept override;
    bool HasLeftChild() const noexcept override;
    virtual const Node& RightChild() const override;
    virtual const Node& LeftChild() const override;
    virtual MutableNode& RightChild() override;
    virtual MutableNode& LeftChild() override;

    };

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const MappableContainer<Data>&); // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(MutableMappableContainer<Data>&&); // A binary tree obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk&) const noexcept;
  bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  MutableNode& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  NodeLnk * root = nullptr;

  NodeLnk* Copy(NodeLnk*);

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
