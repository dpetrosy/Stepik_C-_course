#include <cstddef> // size_t

template <typename T, size_t size>
size_t array_size(const T (&arr)[size])
{
    return size;
}
