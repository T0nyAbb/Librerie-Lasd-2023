
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: public virtual PreOrderMappableContainer<Data>,
                  public virtual PostOrderMappableContainer<Data>,
                  public virtual InOrderMappableContainer<Data>,
                  public virtual BreadthMappableContainer<Data> {
                    // Must extend PreOrderMappableContainer<Data>,
                    //             PostOrderMappableContainer<Data>,
                    //             InOrderMappableContainer<Data>,
                    //             BreadthMappableContainer<Data>

private:

  // ...

protected:
  using Container::size;
  // ...

public:

  struct Node {

  protected:

    // Comparison operators
    bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
    bool operator!=(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.

  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node& operator=(const Node&) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&&) noexcept = delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual const Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Node& Root() const = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void Map(MapFunctor) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFunctor) const override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFunctor) const override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  void InOrderMap(MapFunctor) const override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  void BreadthMap(MapFunctor) const override; // Override BreadthMappableContainer member

protected:

  // Auxiliary member function (for PreOrderMappableContainer)

  void PreOrderMap(MapFunctor, const Node*) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for PostOrderMappableContainer)

  void PostOrderMap(MapFunctor, const Node*) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for InOrderMappableContainer)

  void InOrderMap(MapFunctor, const Node*) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for BreadthMappableContainer)

  void BreadthMap(MapFunctor, const Node*) const; // Accessory function executing from one node of the tree

  void PreOrderFold(FoldFunctor, void* acc, const Node*) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree: public virtual ClearableContainer,
                         public virtual BinaryTree<Data>,
                         public virtual MutablePreOrderMappableContainer<Data>,
                         public virtual MutablePostOrderMappableContainer<Data>,
                         public virtual MutableInOrderMappableContainer<Data>,
                         public virtual MutableBreadthMappableContainer<Data> {
                          // Must extend ClearableContainer,
                          //             BinaryTree<Data>,
                          //             MutablePreOrderMappableContainer<Data>,
                          //             MutablePostOrderMappableContainer<Data>,
                          //             MutableInOrderMappableContainer<Data>,
                          //             MutableBreadthMappableContainer<Data>

private:

  // ...

protected:
  using Container::size;
  using typename BinaryTree<Data>::Node;
  // ...

public:

  struct MutableNode: Node {
                        // Must extend Node

    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~MutableNode() = default;

    /* ********************************************************************** */

    // Copy assignment
    MutableNode& operator=(const MutableNode&) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    MutableNode& operator=(MutableNode&&) noexcept = delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)

    virtual MutableNode& LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild() = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree& operator=(const MutableBinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableBinaryTree& operator=(MutableBinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual MutableNode& Root() = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  void Map(MutableMapFunctor) override; // Override MutableMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  void PreOrderMap(MutableMapFunctor) override; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  void PostOrderMap(MutableMapFunctor) override; // Override MutablePostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableInOrderMappableContainer)

  void InOrderMap(MutableMapFunctor) override; // Override MutableInOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBreadthMappableContainer)

  void BreadthMap(MutableMapFunctor) override; // Override MutableBreadthMappableContainer member

protected:

  // Auxiliary member function (for MutablePreOrderMappableContainer)

  void PreOrderMap(MutableMapFunctor, MutableNode*); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for MutablePostOrderMappableContainer)

  void PostOrderMap(MutableMapFunctor, MutableNode*); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for MutableInOrderMappableContainer)

  void InOrderMap(MutableMapFunctor, MutableNode*); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for MutableBreadthMappableContainer)

  void BreadthMap(MutableMapFunctor, MutableNode*); // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator: public virtual ForwardIterator<Data>,
                          public virtual ResettableIterator<Data> {
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  // ...

protected:
  const typename BinaryTree<Data>::Node * root = nullptr;
  const typename BinaryTree<Data>::Node * curr = nullptr;
  StackVec<const typename BinaryTree<Data>::Node *> stk;
  // ...

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>& bt) {
    if(bt.Size()!=0) {
      root = curr = &bt.Root();
    }
  }; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator& it) : root(it.root), curr(it.curr), stk(it.stk) {};

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator& operator=(const BTPreOrderIterator& it) {
    root = it.root;
    curr = it.curr;
    stk = it.stk;
    return *this;
  }

  // Move assignment
  BTPreOrderIterator& operator=(BTPreOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator&) const noexcept = default;
  bool operator!=(const BTPreOrderIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override {
    if(curr != nullptr) {
    return curr->Element();
    } else {
    throw std::out_of_range("Iterator Terminated!");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override{
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override {
    stk.Clear();
    curr = root;
  }; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator: public virtual MutableIterator<Data>,
                                 public virtual BTPreOrderIterator<Data> {
                                  // Must extend MutableIterator<Data>,
                                  //             BTPreOrderIterator<Data>

private:

  // ...

protected:
  using BTPreOrderIterator<Data>::curr;
  // ...

public:

  // Specific constructors
  BTPreOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTPreOrderIterator<Data>(bt) {}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator& it) : BTPreOrderIterator<Data>(it) {};

  // Move constructor
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&& it) : BTPreOrderIterator<Data>(std::move(it)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& it) {
    BTPreOrderIterator<Data>::operator=(it);
  };

  // Move assignment
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& it) noexcept {
    BTPreOrderIterator<Data>::operator=(std::move(it));
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderMutableIterator&) const noexcept = default;
  bool operator!=(const BTPreOrderMutableIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    } else {
      throw std::out_of_range("Iterator Terminated!");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: public virtual ForwardIterator<Data>,
                           public virtual ResettableIterator<Data> {
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  // ...

protected:
  const typename BinaryTree<Data>::Node * root = nullptr;
  const typename BinaryTree<Data>::Node * curr = nullptr;
  StackVec<const typename BinaryTree<Data>::Node *> stk;
  // ...

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator& it) : root(it.root), curr(it.curr), stk(it.stk) {};

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator& it) {
    root = it.root;
    curr = it.curr;
    stk = it.stk;
    return *this;
  };

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator&) const noexcept = default;
  bool operator!=(const BTPostOrderIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override {
    if(curr != nullptr) {
      return curr->Element();
    } else {
      throw std::out_of_range("Iterator terminated!");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override {
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

protected:
 
  void getLeftMostLeaf();

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator: public virtual MutableIterator<Data>,
                                  public virtual BTPostOrderIterator<Data> {
                                  // Must extend MutableIterator<Data>,
                                  //             BTPostOrderIterator<Data>

private:

  // ...

protected:
  using BTPostOrderIterator<Data>::curr;
  // ...

public:

  // Specific constructors
  BTPostOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTPostOrderIterator<Data>(bt) {}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& it) : BTPostOrderIterator<Data>(it) {};

  // Move constructor
  BTPostOrderMutableIterator(BTPostOrderIterator<Data>&& it) : BTPostOrderIterator<Data>(std::move(it)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator& it) {
    BTPostOrderIterator<Data>::operator=(it);
  };

  // Move assignment
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&& it) noexcept {
    BTPostOrderIterator<Data>::operator=(std::move(it));
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderMutableIterator&) const noexcept = default;
  bool operator!=(const BTPostOrderMutableIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    } else {
      throw std::out_of_range("Iterator terminated!");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: public virtual ForwardIterator<Data>,
                         public virtual ResettableIterator<Data> {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:
  const typename BinaryTree<Data>::Node * root = nullptr;
  const typename BinaryTree<Data>::Node * curr = nullptr;
  StackVec<const typename BinaryTree<Data>::Node *> stk;
  // ...

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator& it) : root(it.root), curr(it.curr), stk(it.stk) {}

  // Move constructor
  BTInOrderIterator(BTInOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator& it) {
    root = it.root;
    curr = it.curr;
    stk = it.stk;
    return *this;
  };

  // Move assignment
  BTInOrderIterator& operator=(BTInOrderIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator&) const noexcept = default;
  bool operator!=(const BTInOrderIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override {
    if(curr != nullptr) {
      return curr->Element();
    } else {
      throw std::out_of_range("Iterator terminated!");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override {
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

protected:

  void getLeftMostNode();

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator: public virtual MutableIterator<Data>,
                                public virtual BTInOrderIterator<Data> {
                                  // Must extend MutableIterator<Data>,
                                  //             BTInOrderIterator<Data>

private:

  // ...

protected:
  using BTInOrderIterator<Data>::curr;
  // ...

public:

  // Specific constructors
  BTInOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTInOrderIterator<Data>(bt) {}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& it) : BTInOrderIterator<Data>(it) {};

  // Move constructor
  BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& it) : BTInOrderIterator<Data>(std::move(it)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator& it) {
    BTInOrderIterator<Data>::operator=(it);
  };

  // Move assignment
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&& it) noexcept {
    BTInOrderIterator<Data>::operator=(std::move(it));
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderMutableIterator &) const noexcept = default;
  bool operator!=(const BTInOrderMutableIterator &) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    } else {
      throw std::out_of_range("Iterator terminated!");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator: public virtual ForwardIterator<Data>,
                         public virtual ResettableIterator<Data> {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:
  
  const typename BinaryTree<Data>::Node * root = nullptr;
  const typename BinaryTree<Data>::Node * curr = nullptr;
  QueueVec<const typename BinaryTree<Data>::Node *> que;
  // ...

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>& bt) {
    if(bt.Size()!=0) {
      curr = root = &bt.Root();
    }
  }; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator& it) : root(it.root), curr(it.root), que(it.que) {}

  // Move constructor
  BTBreadthIterator(BTBreadthIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(que, it.que);
  }

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator& it) {
    root = it.root;
    curr = it.curr;
    que = it.que;
    return *this;
  };

  // Move assignment
  BTBreadthIterator& operator=(BTBreadthIterator&& it) noexcept {
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(que, it.que);
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator&) const noexcept = default;
  bool operator!=(const BTBreadthIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override {
    if(curr != nullptr) {
      return curr->Element();
    } else {
      throw std::out_of_range("Iterator terminated!");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override {
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override {
    curr = root;
    que.Clear();
  }; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator: public virtual MutableIterator<Data>,
                                public virtual BTBreadthIterator<Data>{
                                  // Must extend MutableIterator<Data>,
                                  //             BTBreadthIterator<Data>

private:

  // ...

protected:
  using BTBreadthIterator<Data>::curr;
  // ...

public:

  // Specific constructors
  BTBreadthMutableIterator(MutableBinaryTree<Data>& bt) : BTBreadthIterator<Data>(bt) {}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthMutableIterator(const BTBreadthMutableIterator& it) : BTBreadthIterator<Data>(it) {};

  // Move constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator&& it) noexcept : BTBreadthIterator<Data>(std::move(it)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& it) {
    BTBreadthIterator<Data>::operator=(it);
  }

  // Move assignment
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& it) noexcept {
    BTBreadthIterator<Data>::operator=(std::move(it));
  }

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthMutableIterator&) const noexcept = default;
  bool operator!=(const BTBreadthMutableIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if (curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    } else {
      throw std::out_of_range("Iterator terminated!");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
