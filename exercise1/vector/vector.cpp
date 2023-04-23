#include "vector.hpp"

namespace lasd {

/* ************************************************************************** */

//Specific constructors

template <typename Data>
Vector<Data>::Vector(const unsigned long newsize) {
    Elements = new Data[newsize] {};
    size = newsize;
}

template <typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& con) {
    size = con.Size();
    Elements = new Data[size] {};
    unsigned long idx = 0;
    con.Map([this, & idx](const Data & data) {
        Elements[idx] = data;
        idx++;
    }
    );
}

template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& con) {
    size = con.Size();
    Elements = new Data[size] {};
    unsigned long idx = 0;
    con.Map([this, &idx](Data & data) {
        Elements[idx] = std::move(data);
        idx++;
    });
}


/* ************************************************************************** */

//Copy Constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vec) {
    size = vec.size;
    Elements = new Data[size] {};
    std::copy(vec.Elements, vec.Elements + size, Elements);
}

//Move Constructor
template <typename Data>
Vector<Data>::Vector(Vector<Data>&& vec) noexcept {
    std::swap(size, vec.size);
    std::swap(Elements, vec.Elements);
}

/* ************************************************************************** */

//Destructor
template <typename Data>
Vector<Data>::~Vector() {
    delete[] Elements;
}

/* ************************************************************************** */

//Copy Assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec) {
    Vector<Data>* tmp = new Vector<Data>(vec);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

//Move Assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept {
    std::swap(size, vec.size);
    std::swap(Elements, vec.Elements);
    return *this;

}

/* ************************************************************************** */

//Comparison operators

//OP ==
template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept {
    if(size!=vec.size) {
        return false;
    } for(unsigned long idx = 0; idx<size; idx++) {
        if(Elements[idx]!= vec.Elements[idx]) {
            return false;
        }
    }
    return true;
}

//OP !=
template <typename Data>
inline bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept {
    return !(*this == vec);
}

/* ************************************************************************** */

//Specific Functions

//Clear
template <typename Data>
void Vector<Data>::Clear() {
    delete[] Elements;
    size = 0;
    Elements = nullptr;
}

//Resize
template <typename Data>
void Vector<Data>::Resize(const unsigned long newSize) {
    if(size!=newSize && newSize > 0) {
        Data* temp = new Data[newSize] {};
        unsigned long min = (size < newSize) ? size : newSize;
        for(unsigned long idx = 0; idx<min; idx++) {
            std::swap(Elements[idx], temp[idx]);
        }
        std::swap(Elements, temp);
        size = newSize;
        delete[] temp;
    } else if(newSize == 0) {
        Clear();
    }

}

//OP []
template <typename Data>
const Data& Vector<Data>::operator[](const unsigned long index) const {
    if(index>size){
        throw std::out_of_range("Out of bounds!");
    } 
    else {
        return Elements[index];
    }
}

//OP [] mutable
template <typename Data>
Data& Vector<Data>::operator[](const unsigned long index) {
    if(index>size){
        throw std::out_of_range("Out of bounds!");
    } 
    else {
        return Elements[index];
    }
}

//Front
template <typename Data>
const Data& Vector<Data>::Front() const {
    if(size==0) {
        throw std::length_error("Empty Vector!");
    } else {
        return Elements[0];
    }
}

//Front mutable
template <typename Data>
Data& Vector<Data>::Front() {
    if(size==0) {
        throw std::length_error("Empty Vector!");
    } else {
        return Elements[0];
    }
}

//Back
template <typename Data>
const Data& Vector<Data>::Back() const {
    if(size==0) {
        throw std::length_error("Empty Vector!");
    } else {
        return Elements[size-1];
    }
}

//Back mutable
template <typename Data>
Data& Vector<Data>::Back() {
    if(size==0) {
        throw std::length_error("Empty Vector!");
    } else {
        return Elements[size-1];
    }
}

//Sort
template <typename Data>
void Vector<Data>::Sort() {
    if(size==0 || size==1) return;
    BubbleSort();
} 

//BubbleSort
template <typename Data>
void Vector<Data>::BubbleSort() {
    for(unsigned int i=0; i<size; i++) {
        for(unsigned int j=0; j+1<size-1; j++) {
            std::swap(Elements[j], Elements[j+1]);
        }
    }
}

}
