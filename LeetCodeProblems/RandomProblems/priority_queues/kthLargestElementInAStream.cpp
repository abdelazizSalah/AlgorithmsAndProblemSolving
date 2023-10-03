#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

class KthLargest
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        DPSolver;
        // this select a position, and sort the elements arround it.
        // all the elements which are less than it, will be on its left
        // all the elements which are larger than it will be on its right.
        nth_element(nums.begin(), nums.end() - k, nums.end());

        return nums[nums.size() - k];
    }
    KthLargest(int k, vector<int> &nums)
    {
        this->kVal = k;
        for (auto i : nums)
            pq.push(i);
    }

    int add(int val)
    {
        pq.push(val);
        while (pq.size() > kVal)
            pq.pop();
        return pq.top();
    }

private:
    int kVal;
    priority_queue<int, vector<int>, greater<>> pq;

    // not correct
    vector<int> tree;
    //? Building max heap tree
    void max_heapify(vector<int> &tree, const int &sz, int idx)
    {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int largest = idx;
        if (left < sz && tree[left] > tree[idx])
            largest = left;
        else
            largest = idx;
        if (right < sz && tree[right] > tree[largest])
            largest = right;
        if (largest != idx)
        {
            swap(tree[idx], tree[largest]);
            max_heapify(tree, sz, largest);
        }
    }

    void build_max_heap(vector<int> &tree)
    {
        float sz = tree.size();
        for (int i = floor(sz / 2) - 1; i >= 0; i--)
            max_heapify(tree, sz, i);
    }
};

int main()
{
    DPSolver;
    return 0;
}