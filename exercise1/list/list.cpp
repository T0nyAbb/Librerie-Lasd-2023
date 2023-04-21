
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
    con.Map([this](const Data & data) {
        InsertAtBack(std::move(data));
    }
    );
}


//Copy constructor
template <typename Data>
List<Data>::List(const List& other) {
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
List<Data>::List(List&& other) noexcept {
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
List<Data>& List<Data>::operator=(const List& other) {
    List<Data> *temp = new List<Data>(other);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

//Move assignment
template <typename Data>
List<Data>& List<Data>::operator=(List&& other) noexcept {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool List<Data>::operator==(const List& other) const noexcept {
    if(size!=other.size) {
        return false;
    } 
    Node *tmp1 = head;
    Node *tmp2 = other.head;
    for(unsigned long int i = 0 i<size; i++) {
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
bool List<Data>::operator!=(const List& other) const noexcept {
    return !(*this == other);
}

//InsertAtFront Copy
template <typename Data>
void List<Data>::InsertAtFront(const Data& data) {
    Node *nodo = new Nodo(data);
    if(head==nullptr) {
        head = tail = nodo;
    } else {
        nodo->next = head;
        head = nodo;
    }
    size++;
}

//InsertAtFront Move
template <typename Data>
void List<Data>::InsertAtFront(Data&& data) noexcept {
    Node *nodo = new Nodo(std::move(data));
    if(head==nullptr) {
        head = tail = nodo;
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
    if(head==nullptr) {
        head = tail = tmp;
    } else {
        tail->next = tmp;
        tmp = tail;
    }
    size++;
}

//InsertAtBack Move
template <typename Data>
void List<Data>::InsertAtBack(Data&& data) noexcept {
    Node* tmp = new Node(std::move(data));
    if(head==nullptr) {
        head = tail = tmp;
    } else {
        tail->next = tmp;
        tmp = tail;
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
    } else if(head->info==data){
        RemoveFromFront();
        check = true;
    } else {
        Node* prev = head;
        Node* curr = head->next;
        while(curr!=nullptr) {
            if(curr->info==data) {
                Node * tmp = curr;
                prev->next=curr->next;
                check = true;
                delete tmp;
                size--;
                prev = curr->next;
                curr = prev->next->next;
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

/* ************************************************************************** */

}
