#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;

    cin >> a >> b >> c;
    
    double d = b * b - 4*a*c;
    if (d < 0)
    {
        cout << "No real roots";
        return 0;
    }

    double x1 = (-b - sqrt(d)) / (2 * a);
    double x2 = (-b + sqrt(d)) / (2 * a);
    
    cout << x1 << " " << x2;

    return 0;
}
