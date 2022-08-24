#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),  cin.tie(0) , cout.tie(0)
#define MAXVAL 1e6
vector<pair<int, pair<bool, int>>>mp(MAXVAL, { INT_MAX,{false , INT_MAX} });

// bites , done or not , remainder <- 
pair<int, pair<bool, int>> minimumBits(int bucket, vector<int>& mnks) // return the bucket value
{
	//base case
	if (bucket == 0)
	{
		mp[bucket] = { 1 , {true ,0} }; // memoization
		return mp[bucket];
	}
	if (bucket < 0)
	{
		return{ INT_MAX, {false , INT_MAX } }; 
		mp[bucket] = { INT_MAX, {false , INT_MAX } }; // memoization
	}
	pair<int, pair<bool, int>> p{ INT_MAX, {false , INT_MAX} };
	if (mp[bucket] != p) // has value 
		return mp[bucket];


	pair<int, pair<bool, int>> minB = { INT_MAX ,{false, INT_MAX} };
	for (int i = 0; i < (int)mnks.size(); i++)
	{
		auto x = minimumBits(bucket - mnks[i], mnks);
		if ((x.second.first == false && minB.second.first == false) || (x.second.first == true && minB.second.first == true)) // both are not done or both done
		{
			if (x.second.second < minB.second.second) // lw 
				minB = x;

			if (x.first < minB.first && x.second.second== minB.second.second )
				minB = x;
		}
		else if (minB.second.first == false && x.second.first == true) //return done and i am not done // take the val of done
			minB = x;
	}


	if (minB.first == INT_MAX) // if not leaf can lead to a 0 buckets
	{
		mp[bucket] = { 1 , {false , bucket} }; // return 1 bite and the value of the remaining bucket
		return mp[bucket];// memoization
	}

	mp[bucket] = { minB.first + 1, {minB.second.first, minB.second.second} };// memoization
	return  mp[bucket];
}

void solve()
{
	//reading data
	int n; cin >> n;
	vector<int> buckets(n);
	for (int& x : buckets) cin >> x;
	int m; cin >> m;
	vector<int> monkeys;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		if (x == 0) continue; // if monkey doesn't eat anything neglect him
		else
			monkeys.push_back(x);
	}

	//perfoming the function for each bucket
	for (int i = 0; i < n; i++)
		if (monkeys.size())
		{
			auto res = minimumBits(buckets[i], monkeys);
			cout << res.second.second << ' ' << res.first - 1 << '\n';
		}
		else
			cout << buckets[i] << ' ' << 0 ; 
}

int main()
{
	fast;
	solve();
	return 0;
}