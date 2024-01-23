#include <iostream>

template <typename T>
void flatten(const T& array, std::ostream& out)
{
    out << array << " ";
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out)
{
    size_t size = array.size();

    for (size_t i = 0; i < size; ++i)
        flatten(array[i], out);
}
