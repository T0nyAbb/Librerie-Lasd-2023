
namespace lasd {

/* ************************************************************************** */

//Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(4) {
    head = 0;
    tail = 0;
    sentinel = 3;
}

//Specific constructors

template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& con) {
    size = con.Size()*2;
    head = 0;
    sentinel = size-1;
    Elements = new Data[size] {};
    con.Map([this](const Data& data) {
        Enqueue(data);
    });
}

template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& con) noexcept {
    size = con.Size()*2;
    head = 0;
    sentinel = size-1;
    Elements = new Data[size] {};
    con.Map([this](Data& data) {
        Enqueue(std::move(data));
    });
}

//Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& que) : Vector<Data>(que) {
    head = que.head;
    tail = que.tail;
    sentinel = que.sentinel;
}

//Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& que) noexcept :  Vector<Data>(std::move(que))  {
    std::swap(head, que.head);
    std::swap(tail, que.tail);
    std::swap(sentinel, que.sentinel);
}

//Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& que) {
    Vector<Data>::operator=(que);
    head = que.head;
    tail = que.tail;
    sentinel = que.sentinel;
    return *this;
}

//Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& que) noexcept {
    Vector<Data>::operator=(std::move(que));
    std::swap(head, que.head);
    std::swap(tail, que.tail);
    std::swap(sentinel, que.sentinel);
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& que) const noexcept {
    if(Size() == que.Size()) {
        if(Size()==0) {
            return true;
        } else if(head<tail && que.head<que.tail) {
            for(unsigned long i = head, j = que.head; i<tail; ++i, ++j) {
                if(Elements[i]!=que.Elements[j]) {
                    return false;
                }
            }
            return true;
        } else {
            QueueVec<Data> *tmp1 = new QueueVec<Data>(*this);
            QueueVec<Data> *tmp2 = new QueueVec<Data>(que);
            for(unsigned long idx = 0; idx< Size(); ++idx) {
                if(tmp1->HeadNDequeue()!=tmp2->HeadNDequeue()) {
                    delete tmp1;
                    delete tmp2;
                    return false;
                }
            }
            delete tmp1;
            delete tmp2;
            return true;
        }
    } else {
        return false;
    }
}

//OP!=
template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& que) const noexcept {
    return !(*this==que);
}


//Head
template <typename Data>
const Data& QueueVec<Data>::Head() const {
    if(Size()==0) {
        throw std::length_error("Empty Queue!");
    } else {
        return Elements[head];
    }
}

//Head mutable
template <typename Data>
Data& QueueVec<Data>::Head() {
    if(Size()==0) {
        throw std::length_error("Empty Queue!");
    } else {
        return Elements[head];
    }
}

//Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue() {
    if(Size()==0) {
        throw std::length_error("Empty Queue!");
    } else {
        if(Size()< size/4) {
            Reduce();
        }
        sentinel = head++;
        if(head==size) {
            head = 0;
        }
    }
}

//HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(Size()==0) {
        throw std::length_error("Empty Queue!");
    } else {
        Data tmp = Head();
        Dequeue();
        return tmp;
    }
}

//Enqueue
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& data) {
    if(tail==sentinel) {
        Expand();
    }
    Elements[tail] = data;
    tail++;
    if(tail==size) {
        tail = 0;
    }
}

//Enqueue move
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& data) noexcept {
    if(tail==sentinel) {
        Expand();
    }
    Elements[tail] = std::move(data);
    tail++;
    if(tail==size) {
        tail = 0;
    }
}

//Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return (head==tail);
}

//Size
template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    if(head>tail) {
        return ((size-head)+tail);
    } else {
        return (tail-head);
    }
}

//Clear
template <typename Data>
void QueueVec<Data>::Clear() {
    Vector<Data>::Clear();
    size = 4;
    Elements = new Data[size] {};
    head = 0;
    tail = 0;
    sentinel = 3;
}

//Expand
template <typename Data>
void QueueVec<Data>::Expand() {
    if(tail<head) {
        Data* tmp = new Data[2*size] {};
        unsigned long i = 0;
        for(unsigned long j = head; j<size; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        for(unsigned long j = 0; j<tail; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        std::swap(Elements, tmp);
        head = 0;
        tail = i;
        size = size*2;
        sentinel = size-1;
        delete[] tmp;
    } else {
        Vector<Data>::Resize(size*2);
        sentinel = size-1;
    }
}

//Reduce
template <typename Data>
void QueueVec<Data>::Reduce() {
    if(tail<head) {
        Data* tmp = new Data[size/2] {};
        unsigned long i = 0;
        for(unsigned long j = head; j<size; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        for(unsigned long j = 0; j<tail; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        std::swap(Elements, tmp);
        head = 0;
        tail = i;
        size = size/2;
        sentinel = size-1;
        delete[] tmp;
    } else {
        Data* tmp = new Data[size/2] {};
        unsigned long i = 0;
        for(unsigned long j = head; j<tail; ++j) {
            std::swap(Elements[j], tmp[i++]);
        }
        std::swap(Elements, tmp);
        head = 0;
        tail = i;
        size = size/2;
        sentinel = size-1;
        delete[] tmp;

    }
}    

/* ************************************************************************** */

}
