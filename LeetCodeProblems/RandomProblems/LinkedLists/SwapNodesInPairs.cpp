#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void swap(ListNode *&head, ListNode *&headNext)
{
    ListNode *dum = headNext->next;
    headNext->next = head;
    head->next = dum;
    head = head->next;
}

ListNode *swapPairs(ListNode *head)
{
    DPSolver;
    if (!head || !head->next)
        return head;
    ListNode *prev = head;
    ListNode *curr = prev;
    ListNode *next = curr->next;
    bool firstIter = true;
    while (curr && next)
    {
        //! moving pointers
        curr = next;
        next = next->next;
        //! applying the swaping.
        prev->next = next;
        curr->next = prev;

        //! moving to the next iteration
        // prev = curr;
        if (firstIter)
        {
            head = curr;
            firstIter = false;
        }
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *h = head;
    for (int i = 2; i < 5; i++)
    {
        h->next = new ListNode(i);
        h = h->next;
    }
    h = head;
    while (h)
    {
        cout << h->val << ' ';
        h = h->next;
    }
    cout << '\n';
    h = swapPairs(head);
    while (h)
    {
        cout << h->val << ' ';
        h = h->next;
    }

    return 0;
}