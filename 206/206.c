#include <stdio.h>
/**给你单链表的头节点 head ，请你反转链表，并返回反转后的链表**/

/* 思路：创建新头节点，遍历原头节点，将头节点指向新头节点，然后头节点next，新头节点也next，直到旧头节点为空 */
int main()
{
}
struct ListNode
{
    int val;
    struct ListNode *next;
};
// typedef struct ListNode *ListNode;

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *newHead = NULL;
    while (head)
    {
        struct ListNode *next = head->next; //备份next
        head->next = newHead;               //指向新头节点

        newHead = head; //newhead 指向head

        head = next; //head 指向原链表下一个
    }

    return newHead;
}