#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    
    cin >> count;
    
    for (int i = 1; i <= count; ++i)
    {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
