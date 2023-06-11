
namespace lasd {

/* ************************************************************************** */

//Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stk) {
    List<Data>::operator=(stk);
    return *this;
}

//Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stk) noexcept {
    List<Data>::operator=(std::move(stk));
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stk) const noexcept {
    return List<Data>::operator==(stk);
}

//OP !=
template <typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stk) const noexcept {
    return List<Data>::operator!=(stk);
}

//Top
template <typename Data>
const Data& StackLst<Data>::Top() const {
    return List<Data>::Front();
}

//Top mutable
template <typename Data>
Data& StackLst<Data>::Top() {
    return List<Data>::Front();
}

//Pop
template <typename Data>
void StackLst<Data>::Pop() {
    return List<Data>::RemoveFromFront();
}

//TopNPop
template <typename Data>
Data StackLst<Data>::TopNPop() {
    return List<Data>::FrontNRemove();
}

//Push copy
template <typename Data>
void StackLst<Data>::Push(const Data& data) {
    return List<Data>::InsertAtFront(data);
}

//Push move
template <typename Data>
void StackLst<Data>::Push(Data&& data) noexcept {
    return  List<Data>::InsertAtFront(data);
}
/* ************************************************************************** */

}
