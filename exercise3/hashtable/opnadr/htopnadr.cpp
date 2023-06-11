namespace lasd {

/* ************************************************************************** */

//Default constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    tablesize = MIN_SIZE;
    size = 0;
    a = 2*(dista(generator))+1;
    b = 2*(distb(generator));
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i=0; i<tablesize; i++) {
        statusVec[i] = 'E'; // Empty, Full, Removed
    }
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
}

//Specific constructors
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long siz) {
    size = 0;
    a = 2*(dista(generator))+1;
    b = 2*(distb(generator));
    tablesize = FindNext2Pow(siz);
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i=0; i<tablesize; i++) {
        statusVec[i] = 'E'; // Empty, Full, Removed
    }
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const MappableContainer<Data>& con) : HashTableOpnAdr() {
    InsertAll(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long siz, const MappableContainer<Data>& con) : HashTableOpnAdr(siz) {
    InsertAll(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MutableMappableContainer<Data>&& con) : HashTableOpnAdr() {
    InsertAll(std::move(con));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long siz, MutableMappableContainer<Data>&& con) : HashTableOpnAdr(siz) {
    InsertAll(std::move(con));
}


//Copy constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) {
    size = ht.size;
    tablesize = ht.tablesize;
    a = ht.a;
    b = ht.b;
    table = ht.table;
    statusVec = ht.statusVec;
    capacity = ht.capacity;
}

//Move constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
    std::swap(statusVec, ht.statusVec);
    std::swap(capacity, ht.capacity);
}

//Copy assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht) {
    HashTableOpnAdr<Data>* tmpht = new HashTableOpnAdr(ht);
    std::swap(*this, *tmpht);
    delete tmpht;
    return *this;
}

//Move assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
    std::swap(statusVec, ht.statusVec);
    std::swap(capacity, ht.capacity);
    return *this;
} 

//Comparison operators

//OP == 
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept {
    if(size == ht.size) {
        for(unsigned long i = 0; i<tablesize; i++) {
            if(statusVec[i] == 'F'){
                if(!(ht.Exists(table[i]))) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

//OP !=
template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}


//Insert
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data) {
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    if((capacity) > 75) {
        Resize(2*tablesize+1);
    }
    if(!Exists(data)) {
        unsigned long index = FindEmpty(data, 0);
        if(index < tablesize) {
            unsigned long pos = HashKey(data, index);
            if(statusVec[pos] == 'E' || statusVec[pos] == 'R') {
                table[pos] = data;
                statusVec[pos] = 'F';
                size++;
                return true;
            }
        }
    }
    return false;
}

//Insert move
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data) noexcept {
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    if(capacity > 75) {
        Resize(2*tablesize+1);
    }
    if(!Exists(data)) {
        unsigned long index = FindEmpty(data, 0);
        if(index < tablesize) {
            unsigned long pos = HashKey(data, index);
            if(statusVec[pos] == 'E' || statusVec[pos] == 'R') {
                table[pos] = std::move(data);
                statusVec[pos] = 'F';
                size++;
                return true;
            }
        }
    }
    return false;
}


//Remove
template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data) {
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    bool res = Remove(data, 0);
    if(capacity < 10) {
        Resize((tablesize/2)-1);
    }
    return res;
}

//Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept {
    if(size > 0) {
        unsigned long index = Find(data, 0);   
        if(index < tablesize) {
            unsigned long pos = HashKey(data, index);
            if(statusVec[pos] == 'F' && table[pos] == data) {
                return true;
            }
        }
    }
    return false;
}

//Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(unsigned long siz) {
    unsigned long newSize;
    if(!IsResizable(siz)) {
        return;
    }
    newSize = FindNext2Pow(siz);
    if(newSize == tablesize) {
        return;
    }
    HashTableOpnAdr<Data>* tmpht = new HashTableOpnAdr<Data>(newSize);
    for(unsigned long i=0; i<tablesize; i++) {
        if(statusVec[i] == 'F') {
            tmpht->Insert(table[i]);
        }
    }
    std::swap(*this, *tmpht);
    delete tmpht;
}


//Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    tablesize = MIN_SIZE;
    size = 0;
    table.Clear();
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i = 0; i<tablesize; i++) {
        statusVec[i] = 'E';
    }
    
}

//HashKey
template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& data, unsigned long index) const noexcept {
    unsigned long key = hash(data);
    //return ((HashKey(key)+index)%tablesize); //linear probing
    return ((HashKey(key)+((index*index)+index)/2)%tablesize); //quadratic probing
}

//Find
template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data& data, unsigned long index) const noexcept {
    unsigned long start = HashKey(data, index);
    ulong collision = 0;
    while(index < tablesize) {
        if(table[start] == data) {
            return index;
        }
        if(statusVec[start] =='E') {
            return tablesize;
        }
        collision++;
        index++; 
        start = HashKey(data, index);
    }
    return index;
}

//FindEmpty
template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& data, unsigned long index) const noexcept {
    unsigned long start = HashKey(data, index);
    ulong collision = 0;
    while(index < tablesize) {
        if(statusVec[start] == 'E' || statusVec[start] == 'R') {
            return index;
        }
        collision++;
        index++;
        start = HashKey(data, index);
    }
    return index;
}    

//Remove
template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data, unsigned long index) {
    if(size > 0) {
        unsigned long idx = Find(data, index);
        if(idx < tablesize) {
            unsigned long pos = HashKey(data, idx);  
                if(statusVec[pos] == 'F' && table[pos] == data) {
                statusVec[pos] = 'R';
                size--;
                return true;
            }
        }
    }
    return false;
}

//FindNext2Pow
template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindNext2Pow(unsigned long siz) const noexcept {
    unsigned long newSize = MIN_SIZE;
    while(newSize < siz) {
        if(newSize >= MAX_SIZE) {
            break;   
        }
        newSize = newSize << 1;
    } 
    return newSize;
}

//isResizable
template <typename Data>
bool HashTableOpnAdr<Data>::IsResizable(unsigned long siz) const noexcept {
    if(siz > tablesize) {
        return true;
    } else {
        if(siz == tablesize) {
            return false;
        }
        ulong cap = (static_cast<double>(size)/static_cast<double>(siz))*100;
        if(cap < 75) {
            return true;
        }
        return false;
    } 

}



/* ************************************************************************** */

}
