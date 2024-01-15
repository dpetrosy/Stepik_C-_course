int power(int x, unsigned p)
{
    int answer = x;

    if (p == 0)
        return 1;
    if (p == 1)
        return x;

    for (unsigned i = 2; i <= p; ++i)
        answer = answer * x;

    return answer;
}
