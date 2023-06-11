
namespace lasd {

/* ************************************************************************** */

//Specific constructors

template <typename Data>
BST<Data>::BST(const MappableContainer<Data>& con) {
    con.Map([this](const Data& data) {
        Insert(data);
    });
}

template <typename Data>
BST<Data>::BST(MutableMappableContainer<Data>&& con) noexcept {
    con.Map([this](Data& data) {
        Insert(std::move(data));
    });
}

//Comparison operators

//OP ==
template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept {
    if(size != bst.Size()) {
        return false;
    } else {
        if(size == 0) {
            return true;
        }
        BTInOrderIterator<Data> it1(*this);
        BTInOrderIterator<Data> it2(bst);
        while(!it1.Terminated() && !it2.Terminated()) {
            if(*it1 != *it2) {
                return false;
            }
            ++it1;
            ++it2;
        }
        if(it1.Terminated() && it2.Terminated()) {
            return true;
        }
        return false;
    }
}

//OP !=
template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {
    return !(*this == bst);
}

//Specific functions

//Min
template <typename Data>
const Data& BST<Data>::Min() const {
    if(root != nullptr) {
        return FindPointerToMin(root)->info;
    } else {
        throw std::length_error("Empty BST!");
    }
}

//MinNRemove
template <typename Data>
Data BST<Data>::MinNRemove() {
    if(root != nullptr) {
       return DataNDelete(DetachMin(root));
    } else {
        throw std::length_error("Empty BST!");
    }
}

//RemoveMin
template <typename Data>
void BST<Data>::RemoveMin() {
    if(root != nullptr) {
        delete DetachMin(root);
    } else {
        throw std::length_error("Empty BST!");
    }
}

//Max
template <typename Data>
const Data& BST<Data>::Max() const {
    if(root != nullptr) {
        return FindPointerToMax(root)->info;
    } else {
        throw std::length_error("Empty BST!");
    }
}

//MaxNRemove
template <typename Data>
Data BST<Data>::MaxNRemove() {
    if(root != nullptr) {
        return DataNDelete(DetachMax(root));
    } else {
        throw std::length_error("Empty BST!");
    }
}

//RemoveMax
template <typename Data>
void BST<Data>::RemoveMax() {
    if(root != nullptr) {
        delete DetachMax(root);
    } else {
        throw std::length_error("Empty BST!");
    }
}

//Predecessor
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const {
    NodeLnk* const * tmp = FindPointerToPredecessor(root, data);
    if(tmp != nullptr) {
        return (*tmp)->info;
    } else {
        throw std::length_error("Not found!");
    }
}

//PredecessorNRemove
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data) {
    NodeLnk** tmp = FindPointerToPredecessor(root, data);
    if(tmp != nullptr) {
        return DataNDelete(Detach(*tmp));
    } else {
        throw std::length_error("Not found!");
    }
}

//RemovePredecessor
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data) {
    NodeLnk** tmp = FindPointerToPredecessor(root, data);
    if(tmp != nullptr) {
        delete Detach(*tmp);
    } else {
        throw std::length_error("Not found!");
    }
}

//Successor
template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const {
    NodeLnk* const * tmp = FindPointerToSuccessor(root, data);
    if(tmp != nullptr) {
        return (*tmp)->info;
    } else {
        throw std::length_error("Not found!");
    }
}

//SuccessorNRemove
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data) {
    NodeLnk** tmp = FindPointerToSuccessor(root, data);
    if(tmp != nullptr) {
        return DataNDelete(Detach(*tmp));
    } else {
        throw std::length_error("Not found!");
    }
}

//RemoveSuccessor
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data) {
    NodeLnk** tmp = FindPointerToSuccessor(root, data);
    if(tmp != nullptr) {
        delete Detach(*tmp);
    } else {
        throw std::length_error("Not found!");
    }
}

//Insert
template <typename Data>
bool BST<Data>::Insert(const Data& data) {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp == nullptr) {
        tmp = new NodeLnk(data);
        size++;
        return true;
    } else {
        return false;
    }
}

//Insert move
template <typename Data>
bool BST<Data>::Insert(Data&& data) noexcept {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp == nullptr) {
        tmp = new NodeLnk(std::move(data));
        size++;
        return true;
    } else {
        return false;
    }
}

//Remove
template <typename Data>
bool BST<Data>::Remove(const Data& data) {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp != nullptr) {
        delete Detach(tmp);
        return true;
    } else {
        return false;
    }
}

//Exists
template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept {
    return (FindPointerTo(root, data) != nullptr);
}

//DataNDelete
template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node) {
    Data data {};
    std::swap(data, node->info);
    delete node;
    return data;
}

//Detach
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept {
    if(node != nullptr) {
        if(node->left == nullptr) {
            return Skip2Right(node);
        } else if(node->right == nullptr) {
            return Skip2Left(node);
        } else {
            NodeLnk* tmp = DetachMax(node->left);
            std::swap(node->info, tmp->info);
            return tmp;
        }
    }
    return nullptr;
}

//DetachMin
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept {
    return Skip2Right(FindPointerToMin(node));
}

//DetachMax
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept {
    return Skip2Left(FindPointerToMax(node));
}

//Skip2Left
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->left);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}

//Skip2Right
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->right);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}

//FindPointerToMin mutable
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
}

//FindPointerToMin 
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMin(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* cur = node;
    if(cur != nullptr) {
        while(cur->left != nullptr) {
            tmp = &cur->left;
            cur = cur->left;
        }
    }
    return *tmp;
}

//FindPointerToMax mutable
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
}

//FindPointerToMax 
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* cur = node;
    if(cur != nullptr) {
        while(cur->right != nullptr) {
            tmp = &cur->right;
            cur = cur->right;
        }
    }
    return *tmp;
}

//FindPointerTo mutable
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, data));
}

//FindPointerTo
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * tmp = &node;
    if(*tmp != nullptr) {
        if(node->info == data) {
            return *tmp;
        }
        else if(node->info < data) {
            tmp = &(FindPointerTo(node->right, data));
        }
        else {
            tmp = &(FindPointerTo(node->left, data));
        }
    }
    return *tmp;
}

//FindPointerToPredecessor mutable
template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, data));
}

//FindPointerToPredecessor
template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToPredecessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * cur = &node;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->info != data) {
        if((*cur)->info < data) {
            tmp = cur;
            cur = &((*cur)->right);
        }
        else if((*cur)->info > data) {
            cur = &((*cur)->left);
        }
    }
    if(*cur != nullptr && (*cur)->HasLeftChild()) {
        return &FindPointerToMax((*cur)->left);
    }
    return tmp;
}

//FindPointerToSuccessor mutable
template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, data));
}

//FindPointerToSuccessor
template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * cur = &node;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->info != data) {
        if((*cur)->info > data) {
            tmp = cur;
            cur = &((*cur)->left);
        }
        else if((*cur)->info < data) {
            cur = &((*cur)->right);
        }
    }
    if(*cur != nullptr && (*cur)->HasRightChild()) {
        return &FindPointerToMin((*cur)->right);
    }
    return tmp;
}

/* ************************************************************************** */

}
