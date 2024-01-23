#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T()) : _size(size)
    {
        _arr = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            _arr[i] = value;
    }

    Array(const Array& other)
    {
        _size = other.size();
        _arr = new T[_size];

        for (size_t i = 0; i < _size; ++i)
            _arr[i] = other[i];
    }

    ~Array()
    {
        delete[] _arr;
        _arr = 0;
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            _size = other.size();
            delete[] _arr;
            _arr = new T[_size];

            for (size_t i = 0; i < _size; ++i)
                _arr[i] = other[i];
        }
        return (*this);
    }

    size_t size() const
    {
        return _size;
    }

    T& operator[](size_t i)
    {
        if (i >= _size)
            throw std::out_of_range("Index out of bounds.\n");
        return _arr[i];
    }

    const T& operator[](size_t i) const
    {
        if (i >= _size)
            throw std::out_of_range("Index out of bounds.\n");
        return _arr[i];
    }

private:
    size_t _size;
    T* _arr;
};
