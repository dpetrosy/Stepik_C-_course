#include <iostream>
using namespace std;

void print_log(long num)
{
    int j = -1;
    int i = 1;
    
    while (i <= num)
    {
        i *= 2;
        ++j;
    }
    cout << j << endl;
}

int main()
{
    int count = 0;
    long num = 0;
    
    cin >> count;
    for (int i = 1; i <= count; ++i)
    {
        cin >> num;
        print_log(num);
    }
}
