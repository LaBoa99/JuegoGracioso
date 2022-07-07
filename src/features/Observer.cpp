#include "Observer.hpp"
#include <iostream>

Observer<T>::Observer() : subject_(subject)
{
    subject_.attach(this);
    number = ++Observer<T>::static_number;
}

void Observer::update(const T& msg) override {
    std::cout << " msg recibido " << std::endl;
}

Observer::~Observer()
{
    //dtor
}

Observer::static_number = 0
