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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    DPSolver;
    ListNode *res = nullptr;
    ListNode *fianlRes = nullptr;
    int sum = 0;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        if (l1 != nullptr && l2 != nullptr)
        // for the first node
        {
            sum = (l1->val + l2->val) + carry;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1 == nullptr)
        {
            sum = l2->val + carry;
            l2 = l2->next;
        }
        else if (l2 == nullptr)
        {
            sum = l1->val + carry;
            l1 = l1->next;
        }
        carry = sum / 10;
        sum %= 10;
        if (!res)
        {
            ListNode *n = new ListNode(sum);
            res = n;
            fianlRes = res;
        }
        else
        {
            ListNode *n = new ListNode(sum);
            res->next = n;
            res = res->next;
        }
    }
    if (carry)
    {
        ListNode *n = new ListNode(carry);
        res->next = n;
    }

    return fianlRes;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << ' ';
        ListNode *dumm = head;
        head = head->next;
        delete dumm;
    }
}

int main()
{
    DPSolver;
    int tc = 0;
    if (tc == 0)
    {
        ListNode arr[3];
        arr[0] = ListNode(2, &arr[1]);
        arr[1] = ListNode(4, &arr[2]);
        arr[2] = ListNode(3, nullptr);
        ListNode arr2[3];
        arr2[0] = ListNode(5, &arr2[1]);
        arr2[1] = ListNode(6, &arr2[2]);
        arr2[2] = ListNode(4, nullptr);
        printList(addTwoNumbers(arr, arr2));
    }
    else if (tc == 1)
    {
        ListNode arr[1];
        arr[0] = ListNode(0, nullptr);
        ListNode arr2[1];
        arr2[0] = ListNode(0, nullptr);
        printList(addTwoNumbers(arr, arr2));
    }
    else if (tc == 3)
    {
        ListNode arr[7];
        arr[0] = ListNode(9, &arr[1]);
        arr[1] = ListNode(9, &arr[2]);
        arr[2] = ListNode(9, &arr[3]);
        arr[3] = ListNode(9, &arr[4]);
        arr[4] = ListNode(9, &arr[5]);
        arr[5] = ListNode(9, &arr[6]);
        arr[6] = ListNode(9, nullptr);
        ListNode arr2[4];
        arr2[0] = ListNode(9, &arr2[1]);
        arr2[1] = ListNode(9, &arr2[2]);
        arr2[2] = ListNode(9, &arr2[3]);
        arr2[3] = ListNode(9, nullptr);
        printList(addTwoNumbers(arr, arr2));
    }
    else
    {
        ListNode arr[5];
        arr[0] = ListNode(1, &arr[1]);
        arr[1] = ListNode(2, &arr[2]);
        arr[2] = ListNode(3, &arr[3]);
        arr[3] = ListNode(4, &arr[4]);
        arr[4] = ListNode(5, nullptr);
        ListNode arr2[2];
        arr2[0] = ListNode(1, &arr2[1]);
        arr2[1] = ListNode(2, nullptr);
        printList(addTwoNumbers(arr, arr2));
    }
    return 0;
}