#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    unsigned int ans = 0;
    for (int i = 0; i <= 31; i++)
    {
        ans = (ans << 1) | ((n >> i) & 1);
    }
    return ans;
}

int main()
{
    cout << (7 & 1) << "----> should be 1"
         << endl;
    uint32_t n = 00000010100101000001111010011101;
    cout << reverseBits(4);
    return 0;
}