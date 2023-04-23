
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

//Fold
template <typename Data>
void MappableContainer<Data>::Fold(FoldFunctor fun, void* acc) const {
    Map([fun, acc](const Data& dat){
        fun(dat, acc);
    });

}

//Map (pre)
template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun);
}

//Fold (pre)
template <typename Data>
void PreOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* acc) const {
    PreOrderFold(fun, acc);
}

//PreOrderFold
template <typename Data>
void PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor fun, void* acc) const {
    PreOrderMap([fun, acc](const Data& dat) {
        fun(dat, acc);
    });
}

//Map (post)
template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    PostOrderMap(fun);
}

//Fold (post)
template <typename Data>
void PostOrderMappableContainer<Data>::Fold(FoldFunctor fun, void* acc) const {
    PostOrderFold(fun, acc);
}

//PostOrderFold
template <typename Data>
void PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor fun, void* acc) const {
    PostOrderMap([fun, acc](const Data& dat) {
        fun(dat, acc);
    });
}

//Map mutable (pre)
template <typename Data>
void MutablePreOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun);
}

//Map mutable (post)
template <typename Data>
void MutablePostOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    PostOrderMap(fun);
}

/* ************************************************************************** */

}
