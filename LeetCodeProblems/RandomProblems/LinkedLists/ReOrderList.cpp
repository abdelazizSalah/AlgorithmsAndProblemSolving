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

ListNode *OrderList(ListNode *&head, ListNode *&end, int &numberOfSteps, int &maxNumOfSteps, bool &odd)
{
    if (head == nullptr)
        return head;

    // define basecase
    if (end->next == nullptr)
    {
        end->next = head->next;
        head->next = end;
        head = end->next;
        odd = maxNumOfSteps & 1;
        maxNumOfSteps /= 2;
        return end;
    }

    // base logic
    ListNode *lastPtr = OrderList(head, end->next, numberOfSteps, ++maxNumOfSteps, odd);
    if (numberOfSteps < (maxNumOfSteps + odd))
    {
        end->next = head->next;
        head->next = end;
        head = end->next;
        numberOfSteps++;
        return end;
    }
    else
        return end;
}
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << ' ';
        head = head->next;
    }
}
void reorderList(ListNode *head)
{
    // You are given the head of a singly linked-list. The list can be represented as:
    //  L0 → L1 → … → Ln - 1 → Ln
    //  Reorder the list to be on the following form:
    //  L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    //  You may not modify the values in the list's nodes. Only nodes themselves may be changed.
    int steps = 2;
    int mxSteps = 1;
    bool odd = false;
    ListNode *beg = head;

    auto res = OrderList(beg, beg, steps, mxSteps, odd);
    if (res)
        if (odd)
            res->next = nullptr;
        else
            res->next->next = nullptr;
    printList(head);
}

int main()
{
    DPSolver;
    int tc = 2;
    if (tc == 0)
    {
        ListNode arr[5];
        arr[0] = ListNode(1, &arr[1]);
        arr[1] = ListNode(2, &arr[2]);
        arr[2] = ListNode(3, &arr[3]);
        arr[3] = ListNode(4, &arr[4]);
        arr[4] = ListNode(5, nullptr);
        reorderList(arr);
    }
    else if (tc == 1)
    {

        ListNode arr[4];
        arr[0] = ListNode(1, &arr[1]);
        arr[1] = ListNode(2, &arr[2]);
        arr[2] = ListNode(3, &arr[3]);
        arr[3] = ListNode(4, nullptr);
        reorderList(arr);
    }
    else if (tc == 3)
    {
        ListNode arr[7];
        arr[0] = ListNode(1, &arr[1]);
        arr[1] = ListNode(2, &arr[2]);
        arr[2] = ListNode(3, &arr[3]);
        arr[3] = ListNode(4, &arr[4]);
        arr[4] = ListNode(5, &arr[5]);
        arr[5] = ListNode(6, nullptr);
        // arr[6] = ListNode(7, nullptr);
        reorderList(arr);
    }
    else
    {

        ListNode arr[7];
        arr[0] = ListNode(1, nullptr);
        reorderList(arr);
    }
    return 0;
}