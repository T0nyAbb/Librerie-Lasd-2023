
namespace lasd {

/* ************************************************************************** */

/* NODE SECTION */

//Specific constructor
template <typename Data>
List<Data>::Node::Node(Data&& dat) noexcept {
    info = std::move(dat);

}

//Move constructor
template <typename Data>
List<Data>::Node::Node(Node&& node) noexcept {
    std::swap(info, node.info);
    std::swap(next, node.next);
}

//Comparison operators

//OP ==
template <typename Data>
bool List<Data>::Node::operator==(const Node& node) const noexcept {
    if(info==node.info && next==node.next) return true;
    return false;
}

//OP !=
template <typename Data>
bool List<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

/* LIST SECTION */

template <typename Data>
List<Data>::List(const MappableContainer<Data>& con) {
    
}

/* ************************************************************************** */

}
