namespace lasd {

/* ************************************************************************** */

//default constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    table = new BST<Data>[tablesize]{};
}

//specific constructors

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long siz) {
    if(siz < 127) {
        siz = MIN_TABLESIZE;
    }
    if(siz >= 10000) {
        siz = MAX_TABLESIZE;
    }
    if(siz != MIN_TABLESIZE && siz != MAX_TABLESIZE) {
        siz = FindNextPrime(siz);   
    }
    tablesize = siz;
    table = new BST<Data>[tablesize]{};
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const MappableContainer<Data>& con) : HashTableClsAdr() {
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long siz, const MappableContainer<Data>& con) : HashTableClsAdr(siz)  {
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MutableMappableContainer<Data>&& con) : HashTableClsAdr() {
    InsertAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long siz, MutableMappableContainer<Data>&& con) : HashTableClsAdr(siz)  {
    InsertAll(std::move(con));
}

//copy constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) : HashTable<Data>(ht) {
    table = new BST<Data>[tablesize]{};
    std::copy(ht.table, ht.table+tablesize, table); //copy all elements (start, end, destination)
}

//move constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept : HashTable<Data>(std::move(ht)) {
    std::swap(table, ht.table);
}

//destructor
template <typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr() {
    delete[] table;
}

//copy assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& ht) {
    HashTableClsAdr<Data>* tmp = new HashTableClsAdr<Data>(ht);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
//move assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept {
    std::swap(table, ht.table);
    std::swap(size, ht.size);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(tablesize, ht.tablesize);
    return *this;
}

//comparison operators

//OP ==
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept {
    if(size == ht.size) {
        for(unsigned long i = 0; i<tablesize; i++) {
            if(table[i].Size()!=0) {
                BTInOrderIterator<Data> it(table[i]);
                while(!(it.Terminated())) {
                    if(!(ht.Exists(it.operator*()))) {
                        return false;
                    }
                    it.operator++();
                }
            }
        }
        return true;
    }
    return false;
}

//OP !=
template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}

//Insert
template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data) {
    unsigned long key = HashKey(hash(data));
    if(table[key].Insert(data)) {
        size++;
        return true;
    } 
    return false;
}

//Insert move
template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept {
    unsigned long key = HashKey(hash(data));
    if(table[key].Insert(std::move(data))) {
        size++;
        return true;
    } 
    return false;
}

//Remove
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data) {
    unsigned long key = HashKey(hash(data));
    if(table[key].Remove(data)) {
        size--;
        return true;
    } 
    return false;
}

//Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    unsigned long key = HashKey(hash(data));
    return table[key].Exists(data);
}

//Resize
template <typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long newsize) {
    HashTableClsAdr<Data>* tmpht = new HashTableClsAdr<Data>(newsize);
    for(unsigned long i = 0; i<tablesize; i++) {
        if(table[i].Size()!=0) {
            BTInOrderIterator<Data> it(table[i]);
            
            while(!(it.Terminated())) {
                Data dat = it.operator*();
                tmpht->Insert(dat);
                it.operator++();
            }

        }        
    }
    std::swap(*this, *tmpht);
    delete tmpht;
}

//Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    delete[] table;
    table = new BST<Data>[tablesize]{};
    size = 0;
}

//FindNextPrime
template <typename Data>
unsigned long HashTableClsAdr<Data>::FindNextPrime(unsigned long val) const noexcept {
    for (ulong i = 2; i <= val/2; ++i) {
        if (val % i == 0) {
            val+=1;
            i = 2;
        }
    }
    return val;
}


/* ************************************************************************** */

}
