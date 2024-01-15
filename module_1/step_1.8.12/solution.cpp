#include <iostream>
using namespace std;

int main()
{
    bool found = false;
    
    char c = '\0';
    while (cin.get(c))
    {
        if (c != ' ')
        {
            cout << c;
            found = false;
        }
        else if (c == ' ' && found)
            continue;
        else
        {
            cout << ' ';
            found = true;
        }
    }

	return 0;
}
