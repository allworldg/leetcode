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

struct ListNode *oddEvenList(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head != NULL && head->next == NULL)
    {
        return head;
    }
    struct ListNode *oddNode = head;        //奇数指针
    struct ListNode *evenNode = head->next; //偶数指针
    struct ListNode *cur = head->next->next;
    evenNode->next = NULL;//切断偶数节点之后的链接，防止产生环路。
    int index = 1;
    while (cur != NULL)
    {
        struct ListNode *next = cur->next;
        if (index % 2 != 0)
        {
            cur->next = oddNode->next;
            oddNode->next = cur;
            oddNode = oddNode->next;
        }
        else
        {
            cur->next = evenNode->next;
            evenNode->next = cur;
            evenNode = evenNode->next;
        }
        cur = next;
        index++;
    }
    return head;
}

int main()
{
    int flag = 1;
    if(flag){
        printf("hahahah");
    }
    flag = 0;
    if(flag){
        printf("losldkfjlkdsfj");
    }
    return 0;
}
