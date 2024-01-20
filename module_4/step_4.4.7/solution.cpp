bool check_equals(Expression const* left, Expression const* right)
{
    long *l1 = (long *)left;
    long *l2 = (long *)right;
    if (*l1 == *l2)
        return true;
    return false;
}
