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
        data.push_back(value);
    }

    void pop() {
        if (!empty()) {
            data.pop_back();
        }
    }//

    T top() const {
        if (!empty()) {
            return data.front();
        }
        else {
            return nullptr;
        }
    }

    bool empty() const {
        if (size() > 0) {
            return false;
        }
        return true;
    }

    int size() const {
        return data.size();
    }
};

#endif
