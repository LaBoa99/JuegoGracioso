#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <iostream>
#include <list>
#include "ISubject.hpp"

template <typename T>
class Subject : public ISubject<T>
{
    public:
        Subject();
        inline ~Subject() { std::cout << "Goodbye i was the subject" << std::endl; };
        void createMsg(T msg = NULL);
        inline void howManyObserver() { std::cout<< "Observers: " << this->list_observer_.size() << std::endl; }

        virtual void attach(IObserver<T> *observer) override;
        virtual void detach(IObserver<T> *observer) override;
        virtual void notify() override;

    private:
        std::list<IObserver<T> *> list_observer_;
        T message;
};

#endif // SUBJECT_HPP
