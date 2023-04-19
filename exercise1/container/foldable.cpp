
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

//Exists
template <typename Data>
bool FoldableContainer<Data>::Exists(const Data& data) const noexcept {
    bool check = false;
    Fold({[this, &data] (const Data& d, void* res) {
        if(d==data) {
            *((bool)*res)=true;
        }
    }
    }, &check);
    return check;
}

//Fold Pre
template <typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void* acc) const {
    PreOrderFold(fun, acc);
}

//Fold Post
template <typename Data>
void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void* acc) const {
    PostOrderFold(fun, acc);
}

/* ************************************************************************** */

}
