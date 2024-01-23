#include <cstddef>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T());
    Array(const Array& other);
    ~Array();
    Array& operator=(Array other);
    void swap(Array &other);
    size_t size() const;
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;

private:
    size_t size_;
    T *data_;
};

template <class T, class Comp>
T minimum(const Array<T>& arr, Comp cmp)
{
    size_t size = arr.size();

    T value = arr[0];
    for (size_t i = 0; i < size; ++i)
    {
        if (cmp(arr[i], value))
            value = arr[i];
    }
    return value;
}
