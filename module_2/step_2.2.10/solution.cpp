#include <iostream>
using namespace std;

void run_rec()
{
    int num = 0;
    cin >> num;
    if (num == 0)
        return;
    else
        run_rec();
    cout << num << " ";
}

int main()
{
    run_rec();
	return 0;
}
