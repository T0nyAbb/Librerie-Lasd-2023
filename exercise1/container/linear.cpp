
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

//Comparison operators

//OP ==
template <typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer& other) const noexcept {
    if(size!=other.size) {
        return false;
    } for(unsigned long i = 0; i<size; i++) {
        if(operator[](i) != other.operator[](i)) {
            return false;
        }
    }
    return true;
}

//OP !=
template <typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer& other) const noexcept {
    return !(operator==(other));
}

//Fold
template <typename Data>
void LinearContainer<Data>::Fold(FoldFunctor fun, void* acc) const {
    PreOrderFold(fun, acc);
}

//PreOrderFold
template <typename Data>
void LinearContainer<Data>::PreOrderFold(FoldFunctor fun, void* acc) const {
    for(unsigned long i = 0; i<size; i++) {
        fun(operator[](i), acc);
    }
}

//PostOrderFold
template <typename Data>
void LinearContainer<Data>::PostOrderFold(FoldFunctor fun, void* acc) const {
    for(unsigned long i = size-1; i>0 i--) {
        fun(operator[](i), acc);
    }
}

//Map
template <typename Data>
void LinearContainer<Data>::Map(MapFunctor fun) {
    PreOrderMap(fun);
}

//PreOrderMap
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MapFunctor fun) {
    for(unsigned long i = 0; i<size; i++) {
        fun(operator[](i));
    }
}

//PostOrderMap
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFunctor fun) {
    for(unsigned long i = size-1; i>0 i--) {
        fun(operator[](i));
    }    
}

//Map mutable
template <typename Data>
void LinearContainer<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun);
}

//PreOrderMap mutable
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MutableMapFunctor fun) {
    for(unsigned long i = 0; i<size; i++) {
        fun(operator[](i));
    }
}

//PostOrderMap mutable
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor fun) {
    for(unsigned long i = size-1; i>0 i--) {
        fun(operator[](i));
    }    
}

//Comparison operators

//OP ==
template <typename Data>
bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer& other) const noexcept {
    if(size!=other.size) {
        return false;
    } for(unsigned long i = 0; i<size; i++) {
        if(operator[](i) != other.operator[](i)) {
            return false;
        }
    }
    return true;    
}

//OP !=
template <typename Data>
bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer& other) const noexcept {
    return !(operator==(other));
}


/* ************************************************************************** */

}
