char &get_c(Cls &cls)
{
    void *v = &cls;
    return *((char *)v);
}

double &get_d(Cls &cls)
{
    void *v = &cls;
    char *c_ptr = (char *)v;
    c_ptr += 8;
    return *((double *)c_ptr);
}

int &get_i(Cls &cls)
{
    void *v = &cls;
    char *c_ptr = (char *)v;
    c_ptr +=16;
    return *((int *)c_ptr);
}
