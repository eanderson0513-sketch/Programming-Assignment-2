#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.insert(0);
    }

    void pop() {
        if (size() > 0) {
            data.erase(0);
        }
    }

    T top() const {
        if (size() > 0) {
            T t = data[0];
            return T();
        }
        else {
            return nullptr;
        }
    }

    bool empty() const {
        if (size() > 0) {
            data.erase(0,size() - 1);
        }
        return true;
    }

    int size() const {
        return data.size();
    }
};

#endif
