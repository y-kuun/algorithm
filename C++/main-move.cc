#include <iostream>
#include <memory>
#include <string>

using namespace std;

template <typename T>
class Buffer {
   public:
    std::string _name;
    size_t _size;
    std::unique_ptr<T[]> _buffer;

    // default construction
    Buffer() : _size(16), _buffer(new T[16]) {
        cout << "Default Construction" << endl;
    }

    // Constructor
    Buffer(const string& name, size_t size)
        : _name(name), _size(size), _buffer(new T[size]) {
        cout << "Constructor" << endl;
    }

    // copy constructor
    Buffer(const Buffer& copy)
        : _name(copy._name), _size(copy._size), _buffer(new T[copy._size]) {
        cout << "Copy Constructor" << endl;

        T* src = copy._buffer.get();
        T* des = _buffer.get();
        std::copy(src, src + copy._size, des);
    }

    // copy assignment operator
    Buffer& operator=(const Buffer& copy) {
        std::cout << "Copy Assignment Operator" << std::endl;
        if (this != &copy) {
            _name = copy._name;

            if (_size != copy._size) {
                _buffer = nullptr;
                _size = copy._size;
                _buffer = _size > 0 ? new T[_size] : nullptr;
            }
            T* src = copy._buffer.get();
            T* des = _buffer.get();
            std::copy(src, src + copy._size, des);
        }
        return *this;
    }

    // move constructor
    Buffer(Buffer&& temp)
        : _name(std::move(temp._name)),
          _size(temp._size),
          _buffer(std::move(temp._buffer)) {
        temp._size = 0;
        temp._buffer = nullptr;
        std::cout << "move constructor" << endl;
    }

    // move assignment operator
    Buffer& operator=(Buffer&& temp) {
        std::cout << "move assignment operator" << endl;
        _name = std::move(temp._name);
        _size = temp._size;
        _buffer = std::move(temp._buffer);

        temp._buffer = nullptr;
        temp._size = 0;

        return *this;
    }
};

template <typename T = int>
Buffer<T> getBuffer(const std::string& name) {
    Buffer<T> b(name, 128);
    cout << b._buffer.get() << endl;
    return b;
}

int main() {
    cout << "1" << endl;
    Buffer<int> b1;  // default
    cout << "2" << endl;
    Buffer<int> b2("buf2", 64);  // construct
    cout << "3" << endl;
    Buffer<int> b3 = b2;  // copy construct
    cout << "4" << endl;
    Buffer<int> b4(getBuffer("b4"));  // move construct
    cout << b4._buffer.get() << endl;
    cout << "5" << endl;
    b1 = getBuffer<int>("buf5");  // move assignment
    cout << b1._buffer.get() << endl;
    return 0;
}
