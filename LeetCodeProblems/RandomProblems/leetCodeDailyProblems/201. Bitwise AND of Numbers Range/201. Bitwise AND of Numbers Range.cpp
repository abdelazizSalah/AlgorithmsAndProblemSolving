#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using ll = long long;
using namespace std;
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
/// since It is known that x&(x-1) = removing the rightmost signifcant bit in x
    int rangeBitwiseAnd(int left, int right) {
        if (left==0) return 0;
        if (__builtin_clz(left)!=__builtin_clz(right))
            return 0;//left & right don't have same bit length
        while(right>left){
            right&=(right-1);
        }
        return right;
    }
};

int rangeBitwiseAnd(int left, int right)
{
    DPSolver;
    // myBitset[0]  // LSB
    // myBitset[n]  // MSB
    /// 1. get the left number in binary form of 31 bit string.
    bitset<31> myBitset(left);
    bitset<31> myBitsetR(right);

    /// 2. get the difference between right and left
    int diff = right - left;

    /// 3. initalize power counter
    int power_counter = 1;

    /// 4. iterate while diff >= 2^power_counter
    int i = 0;
    int shiftLeft = (1 << power_counter);
    while ((shiftLeft <= diff) && shiftLeft <= left)
    {
        shiftLeft <<= 1;
        myBitset[i++] = 0;
    }

    for (int i = 0; i < 32; i ++)
        myBitset[i] = myBitset[i] & myBitsetR[i]; 

    return myBitset.to_ulong();
}

int main()
{
    cout << rangeBitwiseAnd(5, 7) << endl;
    cout << rangeBitwiseAnd(0, 0) << endl;
    cout << rangeBitwiseAnd(1, 2 ^ 31 - 1) << endl;
    return 0;
}