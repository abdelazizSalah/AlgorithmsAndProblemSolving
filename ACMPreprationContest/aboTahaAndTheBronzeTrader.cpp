/// ACCEPTED :D
#include <bits/stdc++.h>
using namespace std;
#define DPSOLVER                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

int squareSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int countAcceptedBronze(int n)
{
    int count = 0;
    set<int> seen;

    for (int i = 1; i <= n; i++)
    {
        int sum = i;
        while (sum != 1 && !seen.count(sum))
        {
            seen.insert(sum);
            sum = squareSum(sum);
        }
        if (sum == 1)
            count++;
        seen.clear();
    }

    return count;
}

int main()
{
    DPSOLVER;
    int n;
    cin >> n;

    int count = countAcceptedBronze(n);
    cout << count << endl;

    return 0;
}
