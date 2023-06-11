
namespace lasd {

/* ************************************************************************** */

/* NODE SECTION */

//specific constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& data) {
    info = data;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& data) noexcept {
    std::swap(info, data);
}

//copy constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& node) {
    info = node.info;
    if(node.left != nullptr) {
        left = new NodeLnk(*node.left);
    }
    if(node.right != nullptr) {
        right = new NodeLnk(*node.right);
    }
};

//move constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& node) noexcept {
    std::swap(info, node.info);
    std::swap(left, node.left);
    std::swap(right, node.right);
};

//destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete left;
    delete right;
}

//copy assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& node) {
    NodeLnk* tmp = new NodeLnk(node.info);
    if(node.HasLeftChild()) {
        left = node.left;
    }
    if(node.HasRightChild()) {
        right = node.right;
    }
    return *tmp;
}

//move assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept {
    std::swap(info, node.info);
    std::swap(left, node.left);
    std::swap(right, node.right);
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& other) const noexcept {
    if(this->info == other.info) {
        bool Rc = this->HasRightChild();
        bool Lc = this->HasLeftChild();
        bool otherRc = other.HasRightChild();
        bool otherLc = other.HasLeftChild();
        bool right = (Rc == otherRc);
        bool left = (Lc == otherLc);

        if(left && right) {
            if(Lc && Rc) {
                return((LeftChild() == other.LeftChild()) && (RightChild() == other.RightChild()));
            } else if(Lc) {
                return(LeftChild() == other.LeftChild());
            } else if(Rc) {
                return(RightChild() == other.RightChild());
            } else {
                return true;
            }
        }
    }
    return false;    
}

//OP !=
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& node) const noexcept {
    return !(*this == node);
}

//Functions

//Element
template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return info;
}

//Element mutable
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return info;
}

//isLeaf
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    return !(HasLeftChild() || HasRightChild());
}


//HasRightChild
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (right != nullptr);
}

//HasLeftChild
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (left != nullptr);
}

//RightChild
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(right == nullptr) {
        throw std::out_of_range("Right child does not exists");
    } else {
        return *right;
    }
}

//LeftChild
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(left == nullptr) {
        throw std::out_of_range("Left child does not exists");    
    } else {
        return *left;
    }
}

//RightChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if(right == nullptr) {
        throw std::out_of_range("Right child does not exists");
    } else {
        return *right;
    }
}

//LeftChild mutable
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if(left == nullptr) {
        throw std::out_of_range("Left child does not exists"); 
    } else {
        return *left;
    }
}

/* BINARY TREE LNK SECTION*/

//Specific constructors

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data>& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    con.Map([&que](const Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(data);
        que.Enqueue(&tmp->left);
        que.Enqueue(&tmp->right);
    });
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MutableMappableContainer<Data>&& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    con.Map([&que](const Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(std::move(data));
        que.Enqueue(&tmp->left);
        que.Enqueue(&tmp->right);
    });
}

//Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& btl) {
    size = btl.Size();
    if(btl.Size() > 0) {
        root = Copy(btl.root);
    }
}

//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& btl) noexcept : BinaryTreeLnk<Data>() {
    std::swap(size, btl.size);
    std::swap(root, btl.root);
}


//Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}


//Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& btl) {
    if(btl.Size() > 0) {
        BinaryTreeLnk<Data>* tmp = new BinaryTreeLnk<Data>(btl);
        std::swap(*tmp, *this);
        delete tmp;
    } else {
        Clear();
    }
    return *this;
}

//Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& btl) noexcept {
    std::swap(root, btl.root);
    std::swap(size, btl.size);
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& btl) const noexcept {
    return BinaryTree<Data>::operator==(btl);
}

//OP !=
template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& btl) const noexcept {
    return !(*this == btl);
}

//Specific functions

//Root
template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::Root() const {
    if(root == nullptr) {
        throw std::length_error("Empty Tree!");
    } else {
        return *root;
    }
}

//Root mutable 
template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
    if(root == nullptr) {
        throw std::length_error("Empty Tree!");
    } else {
        return *root;
    }
}

//Clear
template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    size = 0;
    root = nullptr;
}

//Copy
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Copy(NodeLnk* node) {
    NodeLnk* tmp = nullptr;

    if(node != nullptr) {
        tmp = new NodeLnk(node->info);
    }
    if(node->left != nullptr) {
        tmp->left = Copy(node->left);
    }
    if(node->right != nullptr) {
        tmp->right = Copy(node->right);
    }
    return tmp;
}
/* ************************************************************************** */

}
