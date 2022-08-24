#include <iostream>
using namespace std;

int main()
{
    cout << "Hello"; 
    int arr[10000000]{ 0 };
    cout << arr[1000]; 
    int n = 31;
    while (n > 1)
    {
        if (arr[n - 1] != 1)
        {
            arr[n - 1] = 1;
            if (n % 2 == 0) // even
                n / 2;
            else // odd
                n = (3 * n) + 1;
        } // else then we have computed it before
        else if (n >= 10000000)
        {
            cout << "n exceeded";
            break;
        }
    }

    cout << n;
}