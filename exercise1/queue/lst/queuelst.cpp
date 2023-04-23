
namespace lasd {

/* ************************************************************************** */

//Copy assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& que) {
    List<Data>::operator=(que);
    return *this;
}

//Move assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& que) noexcept {
    List<Data>::operator=(std::move(que));
    return *this;
}

//Comparison operators

//OP ==
template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst<Data>& que) const noexcept {
    return List<Data>::operator==(que);
}

//OP !=
template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst<Data>& que) const noexcept {
    return List<Data>::operator!=(que);
}

//Head
template <typename Data>
const Data& QueueLst<Data>::Head() const {
    return List<Data>::Front();
}

//Head mutable
template <typename Data>
Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

//Dequeue
template <typename Data>
void QueueLst<Data>::Dequeue() {
    return List<Data>::RemoveFromFront();
}

//HeadNDequeue
template <typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

//Enqueue copy
template <typename Data>
void QueueLst<Data>::Enqueue(const Data& data) {
    return List<Data>::InsertAtBack(data);
}

//Enqueue move
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& data) noexcept {
    return List<Data>::InsertAtBack(data);
}

/* ************************************************************************** */

}
