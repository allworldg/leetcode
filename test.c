#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    if (newNode)
    {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

void connected(struct ListNode *node1, struct ListNode *node2)
{
    node1->next = node2;
}

struct ListNode *removeElements(struct ListNode *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = 0;
    dummyNode->next = head;
    struct ListNode *cur = dummyNode;
    while (cur->next)
    {
        if (cur->next->val == val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return dummyNode->next;
}

int main()
{
    struct ListNode *node1 = createNode(7);
    struct ListNode *node2 = createNode(7);
    connected(node1, node2);
    removeElements(node1, 7);
    return 0;
}
