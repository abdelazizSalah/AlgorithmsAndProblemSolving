#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

class Twitter
{
public:
    static int timeStamp;
    Twitter()
    {
        timeStamp = 0;
        map<int, pair<priority_queue<pair<int, int>>, vector<int>>> mp = map<int, pair<priority_queue<pair<int, int>>, vector<int>>>();
    }

    void postTweet(int userId, int tweetId)
    {
        timeStamp++;
        mp[userId].first.push({timeStamp, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        // iterate over all priority queues, and check on the largest, then pick him in the vector, then keep iterating
        // till we get the recent 10, or there is no more tweets.
    }

    void follow(int followerId, int followeeId)
    {
        mp[followerId].second.push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        auto trgt = mp[followerId].second;
        trgt.erase(find(trgt.begin(), trgt.end(), followeeId));
    }

private:
    // the key is the user id,
    // value are
    // ? 1. priority queue of time stamp, and tweet ids.
    // ? 2. followees ids.
    map<int, pair<priority_queue<pair<int, int>>, vector<int>>> mp;
};

int main()
{
    DPSolver;
    vector<int> v = {3, 6, 2};
    v.erase(find(v.begin(), v.end(), 6));
    for (auto c : v)
        cout << c << ' ';
    return 0;
}