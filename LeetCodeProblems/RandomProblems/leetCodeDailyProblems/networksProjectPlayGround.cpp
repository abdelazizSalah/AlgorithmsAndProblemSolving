#include <bits/stdc++.h>
using namespace std;
class FrameBase
{
public:
    unsigned int Header = 0;
    string Payload;
    char Trailer = 0;
    int FrameType = 0;
    unsigned int AckNum = 0;

    // public:
    FrameBase()
    {
    }
};

int main()
{
    vector<FrameBase> v(5);
    v[0].AckNum = 11;
    cout << v[0].AckNum;
    return 0;
}