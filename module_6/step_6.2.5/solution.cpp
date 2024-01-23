#include <cstddef>

template <typename D, typename S>
void copy_n(D* dest, S* src, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        dest[i] = static_cast<D>(src[i]);
}
