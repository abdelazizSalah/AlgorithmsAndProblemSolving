#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair

ll dp(map<pair<pair<int, int>, pair<int, int>>, int> memo,
      const vector<pair<ll, pair<int, char>>> &prices,
      const int sz, int smallCount, int mediumCount,
      int countOfLarge, int idx)
{
    // make it efficient
    auto it = memo.find({{smallCount, mediumCount}, {countOfLarge, idx}});
    if (it != memo.end())
        return it->second;

    // evaluating the base case
    if (idx == sz || prices[idx].first == -1)
    {
        memo.insert({{{smallCount, mediumCount}, {countOfLarge, idx}}, 0});
        return 0;
    }
    int smallCountwithout = smallCount;
    int mediumCountWithout = mediumCount;
    int largeCountWithout = countOfLarge;
    if (prices[idx].second.second == 's')
    {
        if (prices[idx].second.first > (smallCount + mediumCount + countOfLarge))
        {
            memo.insert({{{smallCount, mediumCount}, {countOfLarge, idx}}, 0});
            return 0;
        }
        else
        {
            if (prices[idx].second.first <= smallCount)
                smallCount -= prices[idx].second.first;
            else if (prices[idx].second.first < (smallCount + mediumCount))
            {
                mediumCount -= (prices[idx].second.first - smallCount);
                smallCount = 0;
            }
            else if (prices[idx].second.first <= (smallCount + mediumCount + countOfLarge))
            {
                countOfLarge -= (prices[idx].second.first - smallCount - mediumCount);
                mediumCount = 0;
                smallCount = 0;
            }
        }
    }
    else if (prices[idx].second.second == 'm')
    {
        if (prices[idx].second.first > (mediumCount + countOfLarge))
        {

            memo.insert({{{smallCount, mediumCount}, {countOfLarge, idx}}, 0});
            return 0;
        }
        else
        {
            if (prices[idx].second.first <= mediumCount)
                mediumCount -= prices[idx].second.first;
            else if (prices[idx].second.first <= (mediumCount + countOfLarge))
            {
                countOfLarge -= (prices[idx].second.first - mediumCount);
                mediumCount = 0;
            }
        }
    }
    else if (prices[idx].second.second == 'L')
    {
        if (prices[idx].second.first > countOfLarge)
        {

            memo.insert({{{smallCount, mediumCount}, {countOfLarge, idx}}, 0});
            return 0;
        }
        else
            countOfLarge -= prices[idx].second.first;
    }
    // evaluating the recursive case
    ll with = 0, without = 0;
    with = dp(memo, prices, sz, smallCount, mediumCount, countOfLarge, idx + 1) + prices[idx].first;
    without = dp(memo, prices, sz, smallCountwithout, mediumCountWithout, largeCountWithout, idx + 1);

    memo.insert({{{smallCount, mediumCount}, {countOfLarge, idx}}, max(with, without)});
    return max(with, without);
}
int myFunct()
{
    // reading the input
    int noOfBElements;
    cin >> noOfBElements;
    vector<int> A(3), B(noOfBElements), C(noOfBElements);
    for (int i = 0; i < 3; i++)
        cin >> A[i];

    int countOfAllItems = A[0] + A[1] + A[2];
    int countOfMediumAndLarge = A[1] + A[2];
    for (int i = 0; i < noOfBElements; i++)
        cin >> B[i];
    for (int i = 0; i < noOfBElements; i++)
        cin >> C[i];

    // applying the logic
    vector<pair<ll, pair<int, char>>> prices(noOfBElements);
    for (int i = 0; i < noOfBElements; i++)
        if (C[i] % 10 == 0)
        {
            prices[i].second.second = 's';
            if (C[i] / 10 <= countOfAllItems)
                prices[i].second.first = C[i] / 10;
            else
                prices[i].second.first = -1;
        }
        else if (C[i] % 10 == 1)
        {
            prices[i].second.second = 'm';
            if (C[i] / 10 <= countOfMediumAndLarge)
                prices[i].second.first = C[i] / 10;
            else
                prices[i].second.first = -1;
        }
        else if (C[i] % 10 == 2)
        {
            prices[i].second.second = 'L';
            if (C[i] / 10 <= A[2]) // we can afford large only.
                prices[i].second.first = C[i] / 10;
            else
                prices[i].second.first = -1;
        }

    // storing the total prices
    for (int i = 0; i < noOfBElements; i++)
        if (prices[i].second.first != -1)
        {
            prices[i].second.first =
                C[i] / 10;
            prices[i].first = B[i] * prices[i].second.first;
        }

    // sorting the prices
    sort(prices.begin(), prices.end(), greater<pair<ll, pair<int, char>>>());

    // applying dp
    map<pair<pair<int, int>, pair<int, int>>, int> memo;
    ll ans = dp(memo, prices, noOfBElements, A[0], A[1], A[2], 0);
    return ans;
}
int main()
{
    fast;
    map<pair<pair<int, int>, pair<int, int>>, int> memo;
    cout << dp(memo, {{10, {2, 'm'}}, {9, {2, 'm'}}, {8, {2, 'm'}}}, 3, 5, 1, 2, 0);
    return 0;
}