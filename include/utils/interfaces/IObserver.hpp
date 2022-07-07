#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP


template <typename T>
class IObserver
{
    public:
        IObserver() {};
        virtual ~IObserver() {};
        virtual void update(const T& message_from_subject) = 0;
};

#endif // IOBSERVER_HPP
