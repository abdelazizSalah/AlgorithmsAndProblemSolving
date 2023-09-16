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
void reorderList(ListNode *head)
{
    // You are given the head of a singly linked-list. The list can be represented as:
    //  L0 → L1 → … → Ln - 1 → Ln
    //  Reorder the list to be on the following form:
    //  L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    //  You may not modify the values in the list's nodes. Only nodes themselves may be changed.
}
int main()
{
    DPSolver;
}