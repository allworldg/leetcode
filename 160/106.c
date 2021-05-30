#include <stdio.h>
#include <stdlib.h>

/* 编写一个程序，找到两个单链表相交的起始节点。
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。 */

struct ListNode
{
    struct ListNode *next;
    int val;
};
struct ListNode *createNode(int val)
{
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = val;
    return node;
}

void myPrint(struct ListNode *list)
{
    while (list != NULL)
    {
        printf("%d->", list->val);
        list = list->next;
    }
}

int getLength(struct ListNode *head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

struct ListNode *post(struct ListNode *head, int length)
{
    int i = 0;
    while (i < length)
    {
        head = head->next;
        i++;
    }
    return head;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int numA = getLength(headA);
    int numB = getLength(headB);
    if (numA > numB)
    {
        headA = post(headA, numA - numB);
    }
    else
    {
        headB = post(headB, numB - numA);
    }
    while(headA&&headB){
        if(headA==headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main()
{
    struct ListNode *headA = createNode(4);
    struct ListNode *headB = createNode(1);
    struct ListNode *headC = createNode(8);
    struct ListNode *headD = createNode(4);
    struct ListNode *headE = createNode(5);
    headA->next = headB;
    headB->next = headC;
    headC->next = headD;
    headD->next = headE;
    struct ListNode *head1 = createNode(5);
    struct ListNode *head2 = createNode(6);
    struct ListNode *head3 = createNode(1);
    head1->next = head2;
    head2->next = head3;
    head3->next = headC;
    printf("%d",getIntersectionNode(headA,head1)->val);
}