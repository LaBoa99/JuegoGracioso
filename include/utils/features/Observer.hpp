#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>

#include "IObserver.hpp"
#include "Subject.hpp"

template <typename T>
class Observer : public IObserver<T>
{
    public:
        Observer(Subject<T> &subject);
        virtual ~Observer();
        virtual void update(const T& message) override;

        inline void unsubscribe() {
            this->subject_.detach(this);
        }

        inline void printInfo() {
            std::cout<< "Observer : " << this->number << std::endl;
        }

    private:
        T msg;
        Subject<T> &subject_;
        static int static_number;
        int number;
};

#endif // OBSERVER_HPP
