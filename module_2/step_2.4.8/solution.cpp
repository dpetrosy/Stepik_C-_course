int strstr(const char *text, const char *pattern)
{
    if (pattern[0] == '\0')
        return 0;
    
    int i = -1;
    int pos = 0;
    int j = -1;
    while (text[++i])
    {
        pos = i;
        j = 0;
        while (text[i] && pattern[j] && text[i + j] == pattern[j])
        {
            if (pattern[j + 1] == '\0')
                return pos;
            ++j;
        }
    }
    return -1;
}
