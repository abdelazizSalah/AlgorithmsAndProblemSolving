#include <bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

bool solve()
{
    // building the list.
    int n;
    cin >> n;
    ListNode *head;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *dummy;
        if (i == 0)
        {
            head = new ListNode(x);
            dummy = head;
        }
        else
        {
            dummy->next = new ListNode(x);
            dummy = dummy->next;
        }
    }
    ListNode *slow = head;
    ListNode *fast = head;
    bool flag = false;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    solve();
    return 0;
}