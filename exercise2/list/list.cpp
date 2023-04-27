
namespace lasd {

/* ************************************************************************** */

/* NODE SECTION */

//Specific constructor
template <typename Data>
List<Data>::Node::Node(Data&& dat) noexcept {
    info = std::move(dat);

}

//Move constructor
template <typename Data>
List<Data>::Node::Node(Node&& node) noexcept {
    std::swap(info, node.info);
    std::swap(next, node.next);
}

//Comparison operators

//OP ==
template <typename Data>
bool List<Data>::Node::operator==(const Node& node) const noexcept {
    if(info==node.info && next==node.next) return true;
    return false;
}

//OP !=
template <typename Data>
bool List<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

/* LIST SECTION */

//Specific constructors

template <typename Data>
List<Data>::List(const MappableContainer<Data>& con) {
    con.Map([this](const Data & data) {
        InsertAtBack(data);
    }
    );
}

template <typename Data>
List<Data>::List(MutableMappableContainer<Data>&& con) {
    con.Map([this](Data & data) {
        InsertAtBack(std::move(data));
    }
    );
}


//Copy constructor
template <typename Data>
List<Data>::List(const List<Data>& other) {
    if(other.head != nullptr) {
        Node* curr = other.head;
        while(curr!= nullptr) {
            InsertAtBack(curr->info);
            curr = curr->next;
        }
    }
}

//Move constructor
template <typename Data>
List<Data>::List(List<Data>&& other) noexcept {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
}

//Destructor
template <typename Data>
List<Data>::~List() {
    Clear();
}

//Copy assignment
template <typename Data>
List<Data>& List<Data>::operator=(const List<Data>& other) {
    List<Data> *temp = new List<Data>(other);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

//Move assignment
template <typename Data>
List<Data>& List<Data>::operator=(List<Data>&& other) noexcept {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool List<Data>::operator==(const List<Data>& other) const noexcept {
    if(size!=other.size) {
        return false;
    } 
    Node *tmp1 = head;
    Node *tmp2 = other.head;
    for(unsigned long int i = 0; i<size; i++) {
        if(tmp1->info != tmp2->info) {
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return true;
}

//OP !=
template <typename Data>
bool List<Data>::operator!=(const List<Data>& other) const noexcept {
    return !(*this == other);
}

//InsertAtFront Copy
template <typename Data>
void List<Data>::InsertAtFront(const Data& data) {
    Node *nodo = new Node(data);
    if(head==nullptr && tail==nullptr) {
        head = nodo;
        tail = head;
    } else {
        nodo->next = head;
        head = nodo;
    }
    size++;
}

//InsertAtFront Move
template <typename Data>
void List<Data>::InsertAtFront(Data&& data) noexcept {
    Node *nodo = new Node(std::move(data));
    if(head==nullptr && tail==nullptr) {
        head = nodo;
        tail = head;
    } else {
        nodo->next = head;
        head = nodo;
    }
    size++;
}

//RemoveFromFront
template <typename Data>
void List<Data>::RemoveFromFront() {
    if(size==0) {
        throw std::length_error("Empty List!");
    } else {
        Node* tmp = head;
        head = head->next;
        tmp->next = nullptr;
        delete tmp;
        if(size==1) {
            tail = nullptr;
        }
        size--;
    }
}

//FrontNRemove
template <typename Data>
Data List<Data>::FrontNRemove() {
    if(size==0) {
        throw std::length_error("Empty List!");
    } else {
        Data tmp = Front();
        RemoveFromFront();
        return tmp;
    }
}

//InsertAtBack Copy
template <typename Data>
void List<Data>::InsertAtBack(const Data& data) {
    Node* tmp = new Node(data);
    if(head==nullptr && tail==nullptr) {
        head = tmp; 
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
    size++;
}

//InsertAtBack Move
template <typename Data>
void List<Data>::InsertAtBack(Data&& data) noexcept {
    Node* tmp = new Node(std::move(data));
    if(head==nullptr && tail==nullptr) {
        head = tmp;
        tail = tmp;
        
    } else {
        tail->next = tmp;
        tail = tmp;
    }
    size++;
}

//Clear
template <typename Data>
void List<Data>::Clear() {
    while(head!=nullptr) {
       RemoveFromFront(); 
    }
}

//Insert copy
template <typename Data>
bool List<Data>::Insert(const Data& data) {
    if(Exists(data)){
        return false;
    } else {
        InsertAtBack(data);
        return true;
    }
}

//Insert Move
template <typename Data>
bool List<Data>::Insert(Data&& data) noexcept {
    if(Exists(data)){
        return false;
    } else {
        InsertAtBack(std::move(data));
        return true;
    }
}

//Remove
template <typename Data>
bool List<Data>::Remove(const Data& data) {
    bool check = false;
    if(head==nullptr) {
        return check;
    } else {
        while(head->info==data) {
            RemoveFromFront();
            check = true;
        }
        if(head->next==nullptr) {
            return check;
        }
        Node* prev = head;
        Node* curr = head->next;
        while(curr!=nullptr) {
            /*
            if(head->info==data) {
            RemoveFromFront();
            check = true;
            prev = curr;
            curr = curr->next;
            } */
            if(curr->info==data) {
                Node * tmp = curr;
                prev->next=curr->next;
                check = true;
                if(curr==tail) {
                    tail = prev;
                    tmp->next = nullptr;
                    delete tmp;
                    size--;
                    return check;
                } else {
                    tmp->next = nullptr;
                    delete tmp;
                    size--;
                    prev = prev->next;
                    curr = prev->next->next;
                    }

            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        if(size>1 && tail == nullptr) {
            tail = prev;
        }
    }
    return check;
}

//OP []
template <typename Data>
const Data& List<Data>::operator[](const unsigned long index) const {
    if(index>size-1) {
        throw std::out_of_range("Index out of bounds!");
    } else if(size==0) {
        throw std::length_error("Empty List!");
    } else if(index==size-1) {
        return tail->info;
    } else {
        Node* curr = head;
        for(unsigned long i=0; i<index; i++) {
            curr = curr->next;
        }
        return curr->info;
    }
}

//OP [] mutable
template <typename Data>
Data& List<Data>::operator[](const unsigned long index) {
    if(index>size-1) {
        throw std::out_of_range("Index out of bounds!");
    } else if(size==0) {
        throw std::length_error("Empty List!");
    } else if(index==size-1) {
        return tail->info;
    } else {
        Node* curr = head;
        for(unsigned long i=0; i<index; i++) {
            curr = curr->next;
        }
        return curr->info;
    }
}

//Front
template <typename Data>
const Data& List<Data>::Front() const {
    if(size==0) {
        throw std::length_error("Empty List!");
    } else {
        return head->info;
    }
}

//Front mutable
template <typename Data>
Data& List<Data>::Front() {
    if(size==0) {
        throw std::length_error("Empty List!");
    } else {
        return head->info;
    }
}

//Back
template <typename Data>
const Data& List<Data>::Back() const {
    if(size==0) {
        throw std::length_error("Empty List!");
    } else {
        return tail->info;
    }
}

//Back mutable
template <typename Data>
Data& List<Data>::Back() {
    if(size==0) {
        throw std::length_error("Empty List!");
    } else {
        return tail->info;
    }
}

//Fold
template <typename Data>
void List<Data>::Fold(FoldFunctor fun, void* acc) const {
    PreOrderFold(fun, acc, head);
}

//PreOrderFold
template <typename Data>
void List<Data>::PreOrderFold(FoldFunctor fun, void* acc) const {
    PreOrderFold(fun, acc, head);
}

//PostOrderFold
template <typename Data>
void List<Data>::PostOrderFold(FoldFunctor fun, void* acc) const {
    PostOrderFold(fun, acc, head);
}

//Map
template <typename Data>
void List<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun, head);
}

//PreOrderMap
template <typename Data>
void List<Data>::PreOrderMap(MapFunctor fun) const {
    PreOrderMap(fun, head);
}

//PostOrderMap
template <typename Data>
void List<Data>::PostOrderMap(MapFunctor fun) const {
    PostOrderMap(fun, head);
}

//Map mutable
template <typename Data>
void List<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun, head);
}

//PreOrderMap mutable
template <typename Data>
void List<Data>::PreOrderMap(MutableMapFunctor fun) {
    PreOrderMap(fun, head);
}

//PostOrderMap mutable
template <typename Data>
void List<Data>::PostOrderMap(MutableMapFunctor fun) {
    PostOrderMap(fun, head);
}

//protected functions

//PreOrderFold
template <typename Data>
void List<Data>::PreOrderFold(FoldFunctor fun, void* acc, Node* node) const {
    if(node==nullptr) {
        return;
    }
    fun(node->info, acc);
    PreOrderFold(fun, acc, node->next);
}

//PostOrderFold
template <typename Data>
void List<Data>::PostOrderFold(FoldFunctor fun, void* acc, Node* node) const {
    if(node==nullptr) {
        return;
    }
    PreOrderFold(fun, acc, node->next);
    fun(node->info, acc);
}

//PreOrderMap
template <typename Data>
void List<Data>::PreOrderMap(MapFunctor fun, Node* node) const {
    if(node==nullptr) {
        return;
    }
    fun(node->info);
    PreOrderMap(fun, node->next);
}

//PostOrderMap
template <typename Data>
void List<Data>::PostOrderMap(MapFunctor fun, Node* node) const {
    if(node==nullptr) {
        return;
    }
    PostOrderMap(fun, node->next);
    fun(node->info);
}

//PreOrderMap mutable
template <typename Data>
void List<Data>::PreOrderMap(MutableMapFunctor fun, Node* node) {
    if(node==nullptr) {
        return;
    }
    fun(node->info);
    PreOrderMap(fun, node->next);
}

//PostOrderMap
template <typename Data>
void List<Data>::PostOrderMap(MutableMapFunctor fun, Node* node) {
    if(node==nullptr) {
        return;
    }
    PostOrderMap(fun, node->next);
    fun(node->info);
}

//Exists
template <typename Data>
bool List<Data>::Exists(const Data& data) const noexcept {
    if(head==nullptr) {
        return false;
    }
    Node * curr = head;
    while(curr!=nullptr) {
        if(curr->info==data) {
            return true;
        } else {
            curr = curr->next;
        }
    }
    return false;
}
/* ************************************************************************** */

}
