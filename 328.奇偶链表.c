/*
 * @lc app=leetcode.cn id=328 lang=c
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 
    思路：采用双指针，如果链表数超过三个，可以讲第二个第三个节点设置为奇数头指针和偶数头指针，然后将之后的节点依次加入到两个指针的后面。
    注意：偶数节点指针生成后应该断开后面的连接，否则会产生环路。
 */
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
    evenNode->next = NULL; //切断偶数节点之后的链接，防止产生环路。
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
// @lc code=end
