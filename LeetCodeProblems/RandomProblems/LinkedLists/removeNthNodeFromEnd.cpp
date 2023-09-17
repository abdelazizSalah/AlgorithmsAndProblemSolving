#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);

/**
 * Definition for singly-linked list.
 *
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void removeNode(ListNode *&head, int n, int &cntr, bool &removed)
{
    if (head == nullptr || head->next == nullptr)
        return;

    removeNode(head->next, n, cntr, removed);
    cntr++;
    if (cntr == n)
    {
        removed = true;
        head->next = head->next->next;
    }
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // reach the end of the list, then start counting back.
    // when counter == n.
    // remove this node.
    if (n == 1 && !(head->next))
        return nullptr;
    int steps = 0;
    bool removed = false;
    removeNode(head, n, steps, removed);
    if (steps == n - 1 && !removed)
        head->next = head->next->next;
    return head;
}
int main()
{
    DPSolver;
    int tc = 1;
    if (tc == 0)
    {
        ListNode arr[5];
        arr[0] = ListNode(1, &arr[1]);
        arr[1] = ListNode(2, &arr[2]);
        arr[2] = ListNode(3, &arr[3]);
        arr[3] = ListNode(4, &arr[4]);
        arr[4] = ListNode(5, nullptr);
        removeNthFromEnd(arr, 2);
    }
    else if (tc == 1)
    {

        ListNode arr[2];
        arr[0] = ListNode(1, &arr[1]);
        arr[1] = ListNode(2, nullptr);
        removeNthFromEnd(arr, 2);
    }
    else if (tc == 3)
    {
        ListNode arr[7];
        arr[0] = ListNode(1, &arr[1]);
        arr[1] = ListNode(2, &arr[2]);
        arr[2] = ListNode(3, &arr[3]);
        arr[3] = ListNode(4, &arr[4]);
        arr[4] = ListNode(5, &arr[5]);
        arr[5] = ListNode(6, &arr[6]);
        arr[6] = ListNode(7, nullptr);
        removeNthFromEnd(arr, 2);
    }
    else
    {

        ListNode arr[1];
        arr[0] = ListNode(1, nullptr);
        removeNthFromEnd(arr, 1);
    }
    return 0;
}