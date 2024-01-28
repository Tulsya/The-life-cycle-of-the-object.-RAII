#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data;
    int size;
    int capacity;

public:
    smart_array(int initial_capacity) {
        size = 0;
        capacity = initial_capacity;
        data = new int[capacity];
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int element) {
        if (size < capacity) {
            data[size] = element;
            size++;
        }
        else {
            throw std::out_of_range("Array is full");
        }
    }

    int get_element(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

