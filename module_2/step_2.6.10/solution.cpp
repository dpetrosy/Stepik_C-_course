#include <iostream>

char *getline()
{
    char ch;
    int i = 0;
    char *line = new char[100000];
    
    while (std::cin.get(ch) && ch != '\n')
    {
        line[i] = ch;
        ++i;
    }
    line[i] = '\0';
    
    return line;
}
