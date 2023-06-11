
namespace lasd {

/* ************************************************************************** */

/* NODE SECTION */

//Comparison operators

//OP ==
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& other) const noexcept {
    if(this->Element() == other.Element()) {
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

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& other) const noexcept {
    return !(*this == other);
}


/* BINARY TREE SECTION */


//Comparison operators

//OP ==
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& bt) const noexcept {
    if(size == bt.size) {
        if(size == 0) {
            return true;
        } else {
            return (Root() == bt.Root());
        }
    }
    return false;
}

//OP !=
template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& bt) const noexcept {
    return !(*this == bt);
}

//Specific functions

//Fold
template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor fun, void* acc) const {
    if(size>0) {
        PreOrderFold(fun, acc, &Root());
    }
}

//Map
template <typename Data>
void BinaryTree<Data>::Map(MapFunctor fun) const {
    if(size>0) {
        PreOrderMap(fun, &Root());
    }
}

//PreOrderMap
template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor fun) const {
    if(size>0) {
        PreOrderMap(fun, &Root());
    }  
}

//PostOrderMap
template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor fun) const {
    if(size>0) {
        PostOrderMap(fun, &Root());
    }
}

//InOrderMap
template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor fun) const {
    if(size>0) {
        InOrderMap(fun, &Root());
    }
}

//BreadthMap
template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor fun) const {
    if(size>0) {
        BreadthMap(fun, &Root());
    }
}

//Auxiliary functions

//PreOrderFold
template <typename Data>
void BinaryTree<Data>::PreOrderFold(FoldFunctor fun, void* acc, const Node* nod) const {
    if(nod != nullptr) {
        fun(nod->Element(), acc);

        if(nod->HasLeftChild()) {
            PreOrderFold(fun, acc, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PreOrderFold(fun, acc, &nod->RightChild());
        }
    }
}

//PreOrderMap
template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor fun, const Node* nod) const {
    if(nod != nullptr) {
        fun(nod->Element());
        
        if(nod->HasLeftChild()) {
            PreOrderMap(fun, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PreOrderMap(fun, &nod->RightChild());
        }
    }
}

//PostOrderMap
template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor fun, const Node* nod) const {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            PostOrderMap(fun, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PostOrderMap(fun, &nod->RightChild());
        }
        fun(nod->Element());
    }
}

//InOrderMap
template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor fun, const Node* nod) const {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            InOrderMap(fun, &nod->LeftChild());
        }

        fun(nod->Element());

        if(nod->HasRightChild()) {
            InOrderMap(fun, &nod->RightChild());
        }
    }    
}

//BreadthMap
template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor fun, const Node* nod) const {
    lasd::QueueVec<const Node*> que;
    if(nod != nullptr) {
        que.Enqueue(nod);
    }
    while (!que.Empty()) {
        fun(que.Head()->Element());
        
        if (que.Head()->HasLeftChild()) {
            que.Enqueue(&(que.Head()->LeftChild()));
        }
        
        if (que.Head()->HasRightChild()) {
            que.Enqueue(&(que.Head()->RightChild()));
        }
        que.Dequeue();
    }
}


/* MUTABLE BINARY TREE SECTION*/


//Specific functions

//Map mutable
template <typename Data>
void MutableBinaryTree<Data>::Map(MutableMapFunctor fun) {
    if(size>0) {
        PreOrderMap(fun, &Root());
    }
}

//PreOrderMap mutable
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor fun) {
    if(size>0) {
        PreOrderMap(fun, &Root());
    }
}

//PostOrderMap mutable
template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor fun) {
    if(size>0) {
        PostOrderMap(fun, &Root());
    }
}

//InOrderMap mutable
template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor fun) {
    if(size>0) {
        InOrderMap(fun, &Root());
    }
}

//BreadthMap mutable
template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor fun) {
    if(size>0) {
        BreadthMap(fun, &Root());
    }
}

//Auxiliary functions

//PreOrderMap mutable
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor fun, MutableNode* nod) {
    if(nod != nullptr) {
        fun(nod->Element());

        if(nod->HasLeftChild()) {
            PreOrderMap(fun, &nod->LeftChild());
        }

        if(nod->HasRightChild()) {
            PreOrderMap(fun, &nod->RightChild());
        }
    }
}

//PostOrderMap mutable
template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor fun, MutableNode* nod) {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            PostOrderMap(fun, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PostOrderMap(fun, &nod->RightChild());
        }
        fun(nod->Element());
    }    
}

//InOrderMap mutable
template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor fun, MutableNode* nod) {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            InOrderMap(fun, &nod->LeftChild());
        }

        fun(nod->Element());

        if(nod->HasRightChild()) {
            InOrderMap(fun, &nod->RightChild());
        }
    }      
}

//BreadthMap mutable
template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor fun, MutableNode* nod) {
    lasd::QueueVec<MutableNode*> que;
    if(nod != nullptr) {
        que.Enqueue(nod);
    }
    while (!que.Empty()) {
        fun(que.Head()->Element());
        
        if (que.Head()->HasLeftChild()) {
            que.Enqueue(&(que.Head()->LeftChild()));
        }
        
        if (que.Head()->HasRightChild()) {
            que.Enqueue(&(que.Head()->RightChild()));
        }
        que.Dequeue();
    }
}


//PreOrderIterator

//OP ++
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator terminated!");
    }
    if(curr->HasRightChild()) {
        stk.Push(&(curr->RightChild()));
    }
    if(curr->HasLeftChild()) {
        stk.Push(&(curr->LeftChild()));
    }
    if(stk.Empty()) {
        curr = nullptr;
    } else {
        curr = stk.TopNPop();
    }
    return *this;
}

//PostOrderIterator

//Specific constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    if(bt.Size() != 0) {
        curr = root = &bt.Root();
        getLeftMostLeaf();
    }
    
}

//OP ++
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator Terminated!");
    }
    if(stk.Empty()) {
        curr = nullptr;
    } else {
        if(stk.Top()->HasRightChild() && !(&stk.Top()->RightChild() == curr)) {
            curr = &stk.Top()->RightChild();
            getLeftMostLeaf();
        } else {
            curr = stk.TopNPop();
        }
    }
    return *this;
}

//Reset
template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    curr = root;
    getLeftMostLeaf();
}

//getLeftMostLeaf
template <typename Data>
void BTPostOrderIterator<Data>::getLeftMostLeaf() {
    while(curr->HasLeftChild()) {
        stk.Push(curr);
        curr = &curr->LeftChild();
    }
    if(curr->HasRightChild()) {
        stk.Push(curr);
        curr = &curr->RightChild();
        getLeftMostLeaf();
    }
}

//InOrderIterator

//Specific constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if(bt.Size()!=0) {
        curr = root = &bt.Root();
        getLeftMostNode();
    }
}

//OP ++
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator Terminated!");
    }
    if(curr->HasRightChild()) {
        curr = &(curr->RightChild());
        getLeftMostNode();
    } else {
        if(stk.Empty()) {
            curr = nullptr;
        } else {
            curr = stk.TopNPop();
        }

    }
    return *this;
}

//Reset
template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    curr = root;
    getLeftMostNode();
}

//getLeftMostNode
template <typename Data>
void BTInOrderIterator<Data>::getLeftMostNode() {
    if(curr == nullptr) {
        return;
    }
    while(curr->HasLeftChild()) {
        stk.Push(curr);
        curr = &curr->LeftChild();
    }
}

//BreadthIterator

//OP ++
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator Terminated!");
    }
    if(curr->HasLeftChild()) {
        que.Enqueue(&(curr->LeftChild()));
    }
    if(curr->HasRightChild()) {
        que.Enqueue(&(curr->RightChild()));
    }
    if(que.Empty()) {
        curr = nullptr;
    } else {
        curr = que.HeadNDequeue();
    }
    return *this;
}

/* ************************************************************************** */

}
