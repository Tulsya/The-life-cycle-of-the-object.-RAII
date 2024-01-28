#include <iostream>
#include <cstring>

class smart_array {
private:
    int* data;
    size_t size;
public:
    
    smart_array(size_t s) : size(s), data(new int[s]) {}

    
    smart_array(const smart_array& other) : size(other.size), data(new int[other.size]) {
        std::memcpy(data, other.data, size * sizeof(int));
    }

    
    smart_array& operator=(const smart_array& other) {
        if (this != &other) {  
            delete[] data;     
            size = other.size;  
            data = new int[size];  
            std::memcpy(data, other.data, size * sizeof(int));  
        }
        return *this;
    }

    
    ~smart_array() {
        delete[] data;
    }

    
    void add_element(int value) {
       
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
