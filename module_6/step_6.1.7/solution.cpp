#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
    explicit Array(size_t size, const T& value = T()) : _size(size)
    {
        _arr = (T*) new char[_size * sizeof(T)];
        for (size_t i = 0; i < _size; ++i)
            new (_arr + i) T(value);
    }

    Array()
    {
        _size = 0;
        _arr = 0;
    }

    Array(const Array& other)
    {
        _size = other.size();
        _arr = (T*) new char[_size * sizeof(T)];

        for (size_t i = 0; i < _size; ++i)
            new (_arr + i) T(other[i]);
    }

    ~Array()
    {
        memFree();
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            memFree();
            _size = other.size();
            _arr = (T*) new char[_size * sizeof(T)];

            for (size_t i = 0; i < _size; ++i)
                new (_arr + i) T(other[i]);
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
    
    void memFree()
    {
        for (size_t i = 0; i < _size; ++i)
            _arr[i].~T();
        operator delete[] ((char*)_arr);
        _arr = 0;
    }

private:
    size_t _size;
    T* _arr;
};
