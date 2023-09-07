#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

struct Node
{
    int val;
    int mn;
    int noOfElements;
};

Node resolve(Node n1, Node n2)
{
    int numberOFElements = n1.noOfElements + n2.noOfElements;
    vector<int> mnList = {n1.val, n2.val, n1.mn, n2.mn};
    int mn = *min_element(mnList.begin(), mnList.end());
    int mx = max(n1.val, n2.val);
    Node n;
    n.val = max(mx, mn * numberOFElements);
    n.mn = mn;
    n.noOfElements = numberOFElements;
    return n;
}

int get_max_rect_from_left(vector<Node> rect)
{
    if (rect.size() == 1)
        return rect[0].val;
    vector<Node> merge;
    bool firstITr = true;
    do
    {
        merge = vector<Node>();
        int sz = rect.size();

        for (int i = 0; i < sz; i += 2)
        {
            if (i + 1 < sz)
                merge.push_back(resolve(rect[i], rect[i + 1]));
            else
                merge.push_back(rect[i]);
        }
        rect = merge;
    } while (rect.size() > 1);
    return rect[0].val;
}

int get_max_rect_from_right(vector<Node> rect)
{
    if (rect.size() == 1)
        return rect[0].val;
    vector<Node> merge;
    do
    {
        merge = vector<Node>();
        int sz = rect.size();

        for (int i = sz - 1; i >= 0; i -= 2)
        {
            if (i - 1 >= 0)
                merge.push_back(resolve(rect[i], rect[i - 1]));
            else
                merge.push_back(rect[i]);
        }
        rect = merge;
    } while (rect.size() > 1);
    return rect[0].val;
}

int largestRectangleArea(vector<int> &heights)
{
    // initialy it contains a on empty vector
    vector<vector<Node>> rects(1);
    for (auto h : heights)
        if (h > 0)
        {
            Node n;
            n.val = h;
            n.mn = h;
            n.noOfElements = 1;
            rects[rects.size() - 1].push_back(n);
        }
        else
            rects.push_back(vector<Node>());

    vector<int> res;
    for (auto rect : rects)
        if (rect.size())
        {
            res.push_back(get_max_rect_from_left(rect));
            res.push_back(get_max_rect_from_right(rect));
        }

    return res.size() ? *max_element(res.begin(), res.end()) : 0;
}

int main()
{
    // vector<int> h = {2, 1, 5, 6, 2, 3};
    // vector<int> h = {2, 4};
    // vector<int> h = {0, 2, 6, 4, 2, 2, 5, 0, 2, 4, 6, 7, 4, 2, 2, 0, 2, 2, 1, 0, 0, 1};
    // vector<int> h = {0};
    vector<int> h = {1, 2, 2};
    cout << largestRectangleArea(h);
    return 0;
}