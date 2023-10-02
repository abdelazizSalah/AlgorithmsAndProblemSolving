#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//? building min heap tree

void min_heapify(vector<int> &tree, const int &sz, int idx)
{
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    int largest = idx;
    if (left < sz && tree[left] < tree[idx])
        largest = left;
    else
        largest = idx;
    if (right < sz && tree[right] < tree[largest])
        largest = right;
    if (largest != idx)
    {
        swap(tree[idx], tree[largest]);
        min_heapify(tree, sz, largest);
    }
}

void build_min_heap(vector<int> &tree)
{
    float sz = tree.size();
    for (int i = floor(sz / 2) - 1; i >= 0; i--)
        min_heapify(tree, sz, i);
}

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

int main()
{
    DPSolver;
    vector<int> tree = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    build_max_heap(tree);
    for (auto item : tree)
        cout << item << " ";
    cout << endl;
    build_min_heap(tree);
    for (auto item : tree)
        cout << item << " ";
    cout << endl;

    return 0;
}