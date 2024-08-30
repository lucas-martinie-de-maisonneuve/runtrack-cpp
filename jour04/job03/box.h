#ifndef BOX_H
#define BOX_H

#include <stdexcept>

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

template <typename T>
class Box<T*> {
private:
    T* element;

public:
    Box() : element(nullptr) {}
    Box(T* ptr) : element(ptr) {}

    ~Box() {
        delete element; 
    }

    T* getElement() const {
        if (element) {
            return element; 
        } else {
            throw std::runtime_error("Dereferencing a null pointer.");
        }
    }

    void setElement(T* ptr) {
        delete element;
        element = ptr;
    }
};

#endif
