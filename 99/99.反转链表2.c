#include <stdio.h>
#include <stdlib.h>
/* 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 
。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 思路：head遍历，找到第left-1个节点，将其保存，然后从第left结点开始普通转置， */

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
struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
     if(left>=right){
        return head;
    }
    struct ListNode *first = malloc(sizeof(struct ListNode)); //记录完整链的头节点
    first->next = head;
    struct ListNode *cur = first; //记录当前位置
    cur->next = head;
    int i = 0;
    while (i < left - 1)
    {
        cur = cur->next;
        i++;
    }
    struct ListNode *pre = cur; //确定变换范围头部的前一个位置，方便换完连接
    cur = cur->next;
    pre->next = NULL; //切断连接
    i++;
    struct ListNode *newHead = malloc(sizeof(struct ListNode));
    struct ListNode *end = cur; //当前的头节点就是未来被切割的尾部结点
    while (i <= right)
    {
        struct ListNode *next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
        i++;
    }
    pre->next = newHead;
    end->next = cur;
    return first->next;
}

struct ListNode *reverseBetween1(struct ListNode *head, int left, int right)
{
     if(left>=right){
        return head;
    }
    struct ListNode *first = malloc(sizeof(struct ListNode));
    first->val = -1;
    first->next = head;
    struct ListNode *pre = first;
    int i = 0;
    while (i < left - 1)
    {
        pre = pre->next;//找到要被切割的前一个位置
        i++;
    }
    i++;//到达left位置
    struct ListNode *cur = pre->next;//永远指向当前位置
    while(i<right){
        struct ListNode *next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
        i++;
    }
    return first->next;
}



int main()
{
    struct ListNode *first = createNode(3);
    struct ListNode *second = createNode(5);
    first->next = second;
    struct ListNode *listNode = reverseBetween1(first, 1, 2);
    myPrint(listNode);
}
