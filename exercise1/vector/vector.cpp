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
    size = con.size;
    Elements = new Data[size];
    unsigned long idx = 0;
    con.Map([this, & idx](const Data & data) {
        Elements[idx++] = data;
    }
    );
}

template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& con) {
    size = con.Size();
    Elements = new Data[size];
    unsigned long idx = 0;
    con.Map([this, &idx](const Data & data) {
        Elements[idx++] = std::move(data);
    })
}


/* ************************************************************************** */

//Copy Constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vec) {
    size = vec.size;
    Elements = new Data[size];
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


}
