#include <iostream>
#include <cstring>

class smart_array {
private:
    int* data;
    size_t size;
    size_t capacity;  

public:
    smart_array(size_t initial_capacity) : size(0), capacity(initial_capacity), data(new int[initial_capacity]) {}

    smart_array(const smart_array& other) : size(other.size), capacity(other.capacity), data(new int[other.capacity]) {
        std::memcpy(data, other.data, size * sizeof(int));
    }

    smart_array& operator=(const smart_array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];
            std::memcpy(data, other.data, size * sizeof(int));
        }
        return *this;
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int value) {
        if (size < capacity) {
            data[size] = value;
            size++;
        }
        else {
           
            size_t new_capacity = capacity * 2;  
            int* new_data = new int[new_capacity];

            std::memcpy(new_data, data, size * sizeof(int));

            delete[] data;

            data = new_data;
            capacity = new_capacity;

            data[size] = value;
            size++;
        }
    }
};

int main() {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

    return 0;
}
