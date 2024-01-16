char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *newstr = new char[new_size];
    
    unsigned len = (size > new_size) ? new_size : size;
    
    for (int i = 0; i < len; ++i)
        newstr[i] = str[i];
        
    delete[] str;
    return newstr;
}
