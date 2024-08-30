#ifndef BOX_H
#define BOX_H

template <typename T>
class Box {
private:
    T element;

public:
    Box() : element(T()) {}

    Box(const T& value) : element(value) {}

    T getElement() const {
        return element;
    }

    void setElement(const T& value) {
        element = value;
    }
};

#endif
