#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include "IObserver.hpp"

template <typename T>
class ISubject
{
    public:
        ISubject() {}
        virtual ~ISubject() {}
        virtual void attach(IObserver<T> *observer) = 0;
        virtual void detach(IObserver<T> *observer) = 0;
        virtual void notify() = 0;
};

#endif // ISUBJECT_HPP
