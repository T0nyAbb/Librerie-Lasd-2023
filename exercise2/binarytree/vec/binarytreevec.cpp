
namespace lasd {

/* ************************************************************************** */

/* NODE SECTION */

//specific constructor
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data & data, unsigned long idx, Vector<NodeVec*> *v) {
    info = data;
    curr = idx;
    tree = v;
}

//copy assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node) {
    info = node.info;
    curr = node.curr;
    tree = node.tree;
    return *this;
}

//move assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
    std::swap(info, node.info);
    std::swap(curr, node.curr);
    std::swap(tree, node.tree);
    return *this;
}

//Element
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return info;
}

//Element mutable
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return info;
}

//isLeaf
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return ((2*curr+1) > tree->Size());
}

//HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return ((2*curr+2) < tree->Size());
}

//HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return ((2*curr+1) < tree->Size());
}

//RightChild
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()) {
        return *(tree->operator[](2*curr+2));
    } else {
        throw std::out_of_range("Right child does not exists!");
    }
}

//LeftChild
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()) {
        return *(tree->operator[](2*curr+1));
    } else {
        throw std::out_of_range("Left child does not exists!");
    }
}

//RightChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()) {
        return *(tree->operator[](2*curr+2));
    } else {
        throw std::out_of_range("Right child does not exists!");
    }
}

//LeftChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()) {
        return *(tree->operator[](2*curr+1));
    } else {
        throw std::out_of_range("Left child does not exists!");
    }    
}

/* BINARYTREEVEC SECTION */

//Specific constructors

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& con) {
    size = con.Size();
    if(size > 0) {
        vec = new Vector<NodeVec*>(size);
        unsigned long index = 0;
        con.Map([this, &index](const Data& data) {
            NodeVec* node = new NodeVec(data, index, vec);
            vec->operator[](index) = node;
            index++;
        });
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data>&& con) noexcept {
    size = con.Size();
    if(size > 0) {
        vec = new Vector<NodeVec*>(size);
        unsigned long index = 0;
        con.Map([this, &index](Data& data) {
            NodeVec* node = new NodeVec(data, index, vec);
            vec->operator[](index) = node;
            index++;
        });
    } 
}

//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& btv) {
    size = btv.Size();
    if(size > 0) {
        vec =  new Vector<NodeVec*>(size);
        for(unsigned long i=0; i<size; i++) {
            NodeVec* tmp = new NodeVec(btv.vec->operator[](i)->Element(), i, vec);
            vec->operator[](i) = tmp;
        }
    }
    
}

//Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& btv) noexcept {
    std::swap(size, btv.size);
    std::swap(vec, btv.vec);
}

//Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    Clear();
    delete vec;
    vec = nullptr;
}

//Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& btv) {
    BinaryTreeVec<Data>* tmp = new BinaryTreeVec<Data>(btv);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}

//Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& btv) noexcept {
    std::swap(size, btv.size);
    std::swap(vec, btv.vec);
    return *this;
}

//Root
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const {
    if(size > 0) {
        return *(vec->operator[](0));
    } else {
        throw std::length_error("Empty tree!");
    }
}

//Root mutable 
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if(size > 0) {
        return *(vec->operator[](0));
    } else {
        throw std::length_error("Empty tree!");
    }
}

//Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    if(size>0) {
        for(unsigned long i=0; i<size; i++) {
            if(vec->operator[](i) != nullptr) {
                delete (*vec)[i];
            }
        }
        vec->Clear();
        size = 0;
    }

}

//BreadthFold
template <typename Data>
void BinaryTreeVec<Data>::BreadthFold(FoldFunctor fun, void* acc) const {
    for(unsigned long i=0; i<size; i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element(), acc);
        }
        
    }
}

//BreadthMap
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFunctor fun) const {
    for(unsigned long i=0; i<size; i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element());
        }
    }
}

//BreadthMap mutable
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MutableMapFunctor fun) {
    for(unsigned long i=0; i<size; i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element());
        }
    }    
}


/* ************************************************************************** */

}
