unsigned gcd(unsigned a, unsigned b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
