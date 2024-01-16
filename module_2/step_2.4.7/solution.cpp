void strcat(char *to, const char *from)
{
    int i = 0;
    
    while (to[i])
        ++i;
    int j = 0;
    while (from[j])
    {
        to[i] = from[j];
        ++i;
        ++j;
    }
    to[i] = '\0';
}
