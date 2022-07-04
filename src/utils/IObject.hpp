
#ifndef IOBJECT_HPP
#define IOBJECT_HPP

class IObject {
    public:
        int x;
        int y;
        int height;
        int width;

    public:
        virtual ~IObject() {}
};

#endif