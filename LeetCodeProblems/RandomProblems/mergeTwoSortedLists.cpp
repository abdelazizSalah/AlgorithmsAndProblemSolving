#include <bits/stdc++.h>
using namespace std;
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(){};
    ListNode(
        int val)
    {
        this->val = val;
    }
    ListNode(int val, ListNode *nxt)
    {
        this->next = nxt;
        this->val = val;
    };
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // if list 1 is empty, just return the second
    if (l1 == NULL)
    {
        return l2;
    }

    // same for the secont list
    if (l2 == NULL)
    {
        return l1;
    }

    // if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
    // we wall call recursively l1 -> next and whole l2 list.
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }

    // we will call recursive l1 whole list and l2 -> next
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
}

int main()
{
    DPSolver;
    ListNode l10 = ListNode(9, nullptr);
    ListNode l9 = ListNode(7, &l10);
    ListNode l8 = ListNode(6, &l9);
    ListNode l7 = ListNode(4, &l8);
    ListNode l6 = ListNode(3, &l7);
    ListNode l5 = ListNode(8, nullptr);
    ListNode l4 = ListNode(6, &l5);
    ListNode l3 = ListNode(5, &l4);
    ListNode l2 = ListNode(2, &l3);
    ListNode l1 = ListNode(1, &l2);
    ListNode ls1[5];
    ls1[0] = l1;
    ls1[1] = l2;
    ls1[2] = l3;
    ls1[3] = l4;
    ls1[4] = l5;
    ListNode ls2[5];
    ls2[0] = l6;
    ls2[1] = l7;
    ls2[2] = l8;
    ls2[3] = l9;
    ls2[4] = l10;
    printList(mergeTwoLists(ls1, ls2));
    return 0;
}
