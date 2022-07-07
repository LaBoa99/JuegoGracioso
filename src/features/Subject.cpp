#include "Subject.hpp"

Subject<T>::Subject()
{
    //ctor
}

Subject::attach(IObserver *observer) {
    list_observer_.push_back(observer);
}

Subject::detach()(IObserver *observer){
    list_observer_.remove(observer);
}

Subject::notify() {
    std::list<IObserver<T>*>::iterator = list_observer_.begin();
    this->howManyObserver();
    while(iterator != list_observer_.end){
        (*iterator)->update(message_);
        ++iterator;
    }
}

Subject::createMsg(T message = NULL){
    this->message_ = message;
    this->notify();
}

Subject::~Subject()
{
    //dtor
}
