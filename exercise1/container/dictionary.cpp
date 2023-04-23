
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

//InsertAll
template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data> & con) {
    bool check = true;
    con.Map([this, &check](const Data & data) {
        check = Insert(data);
    }
    );
    return check;
}

//InsertAll mutable
template<typename Data>
bool DictionaryContainer<Data>::InsertAll(MutableMappableContainer<Data>&& con) {
    bool check = true;
    con.Map([this, &check](Data & data) {
        check = Insert(std::move(data));
    }
    );
    return check;
}

//RemoveAll
template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& con) {
    bool check = true;
    con.Map([this, &check] (const Data & data) {
        check = Remove(data);
    }
    );
    return check;
}

//InsertSome
template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& con) {
    bool check = false;
    con.Map([this, &check](const Data & data) {
        check |= Insert(data);
    }
    );
    return check;
}

//InsertSome mutable
template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MutableMappableContainer<Data>&& con) {
    bool check = false;
    con.Map([this, &check] (Data & data) {
        check |= Insert(std::move(data));
    }
    );
    return check;
}

//RemoveSome
template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& con) {
    bool check = false;
    con.Map([this, &check] (const Data& data) {
        check |= Remove(data);
    }
    );
    return check;
}
/* ************************************************************************** */

}
