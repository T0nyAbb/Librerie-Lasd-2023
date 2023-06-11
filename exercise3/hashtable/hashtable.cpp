
namespace lasd {

#include <string>

/* ************************************************************************** */

template <>
class Hashable<int> {
    public:
    unsigned long operator()(const int & data) const noexcept {
        return (data*data);
    }
};

template <>
class Hashable<double> {
    public:
    unsigned long operator()(const double & data) const noexcept {
        long intpart = floor(data); //ritorna l'intero arrotondato per difetto
        long fracpart = pow(2, 24) * (data-intpart); //pow(base, potenza)
        return (intpart*fracpart);
    }
};

template <>
class Hashable<std::string> {
    public:
    unsigned long operator()(const std::string& data) const noexcept {
        unsigned long hash = 5381;
        for(unsigned long i = 0; i < data.length(); i++) {
            hash = (hash << 5) + data[i];
        }
        return hash;
    }
};

template <typename Data>
unsigned long HashTable<Data>::HashKey(const unsigned long key) const noexcept {
    return (((a*key+b)%prime)%tablesize);
}



/* ************************************************************************** */

}
