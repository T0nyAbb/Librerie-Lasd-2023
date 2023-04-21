
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

//Exists
template <typename Data>
bool FoldableContainer<Data>::Exists(const Data& data) const noexcept {
    Data dat = data
    bool check = false;
    Fold({[this, &dat] (const Data& d, void* res) {
        if(d==dat) {
            *((bool*)res)=true;
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
