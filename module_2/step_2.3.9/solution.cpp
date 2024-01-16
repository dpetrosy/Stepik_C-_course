void shiftByOne(int a[], unsigned size)
{
    int temp = a[0];
    
    for (int i = 1; i < size; ++i)
        a[i - 1] = a[i];
    
    a[size - 1] = temp;
}

void rotate(int a[], unsigned size, int shift)
{
    for (int i = 0; i < shift; ++i)
        shiftByOne(a, size);
}
