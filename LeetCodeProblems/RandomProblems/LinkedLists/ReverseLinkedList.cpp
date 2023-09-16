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

ListNode *getLastNode(ListNode *head, ListNode *&lastNode)
{
    if (head == nullptr || head->next == nullptr)
    {
        lastNode = head;
        return head;
    }
    ListNode *node = getLastNode(head->next, lastNode);
    node->next = head;
    return head;
}

ListNode *reverseList(ListNode *head)
{ // array of list node
    ListNode *res;
    getLastNode(head, res)->next = nullptr;
    return res;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << ' ';
        head = head->next;
    }
}
int main()
{
    DPSolver;
    // ListNode arr[5];
    // arr[0] = ListNode(1, &arr[1]);
    // arr[1] = ListNode(2, &arr[2]);
    // arr[2] = ListNode(3, &arr[3]);
    // arr[3] = ListNode(4, &arr[4]);
    // arr[4] = ListNode(5, nullptr);

    // ListNode arr[1] = ListNode();
    // arr[0] = ListNode(1, &arr[1]);
    // arr[1] = ListNode(2, nullptr);

    printList(reverseList(nullptr));
    return 0;
}