
namespace lasd {

/* ************************************************************************** */

//Specific constructors

//Mappable
template <typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>& con) {
    size = con.Size()*2;
    Elements = new Data[size] {};
    con.Map([this](const Data& data) {
        Push(data);
    });
}

//Mutable
template <typename Data>
StackVec<Data>::StackVec(MutableMappableContainer<Data>&& con) noexcept {
    size = con.Size()*2;
    Elements = new Data[size] {};
    con.Map([this](Data& data) {
        Push(std::move(data));
    });
}

//Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stk) : Vector<Data>(stk) {
    index = stk.index;
}

//Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stk) : Vector<Data>(std::move(stk)) {
    std::swap(index, stk.index);
}


//Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data> & vec) {
    Vector<Data>::operator=(vec);
    index = vec.index;
    return *this;
}

//Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& vec) noexcept {
    Vector<Data>::operator=(std::move(vec));
    std::swap(index, vec.index);
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& vec) const noexcept {
    if(index!=vec.index) {
        return false;
    } else {
        if(index==0) {
            return true;
        }
        for(unsigned long i = 0; i<index; i++) {
            if(Elements[i]!=vec.Elements[i]) {
                return false;
            }
        }
        return true;
    }
}

//OP !=
template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& vec) const noexcept {
    return !(*this == vec);
}

//Top
template <typename Data>
const Data& StackVec<Data>::Top() const {
    if(index==0) {
        throw std::length_error("Empty Stack!");
    } else {
        return Elements[index-1];
    }
}

//Top mutable
template <typename Data>
Data& StackVec<Data>::Top() {
    if(index==0) {
        throw std::length_error("Empty Stack!");
    } else {
        return Elements[index-1];
    }
}

//Pop
template <typename Data>
void StackVec<Data>::Pop() {
    if(index==0) {
        throw std::length_error("Empty Stack!");
    } else {
        Reduce();
        index--;
    }
}

//TopNPop
template <typename Data>
Data StackVec<Data>::TopNPop() {
    if(index==0) {
        throw std::length_error("Empty Stack!");
    } else {
        Reduce();
        return std::move(Elements[--index]);
    }
}

//Push
template <typename Data>
void StackVec<Data>::Push(const Data& data) {
    Elements[index] = data;
    index++;
    Expand();
}

//Push move
template <typename Data>
void StackVec<Data>::Push(Data&& data) noexcept {
    Elements[index] = std::move(data);
    index++;
    Expand();
}

//Empty
template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return (index==0);
}

//Size
template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept {
    return index;
}

//Clear
template <typename Data>
void StackVec<Data>::Clear() {
    index = 0;
    Vector<Data>::Resize(1);
}

//Expand
template <typename Data>
void StackVec<Data>::Expand() {
    if(index==size) {
        Vector<Data>::Resize(size*2);
    }
}

//Reduce
template <typename Data>
void StackVec<Data>::Reduce() {
    if(index == size/4) {
        Vector<Data>::Resize(size/2);
    }
}
/* ************************************************************************** */

}
