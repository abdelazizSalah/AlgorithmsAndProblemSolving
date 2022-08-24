#include <iostream>
using namespace std;


int main()
{
    //method to read a certain type only 
        int i;
        cout << "enter an integer" << endl;
        while (true)
        {
            cin >> i;
            if (!cin)
            {
                cout << "Wrong Choice. Enter again " << endl;
                cin.clear();
                cin.ignore( LLONG_MAX /*numeric_limits<streamsize>::max()*/, '\n'); // mmkn nshel max() w  n7ot da mkanha 
                continue;
            }
            else break;
        }
        cout << "The integer is : " << i;
        return 0;
}
