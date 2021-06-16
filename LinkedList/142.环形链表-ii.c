/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 思路一：通过使用hashset，当第一个重复结点出现时，即可找到。
 * 
 * 思路二：使用快慢指针，设置快指针速度是慢指针的两倍，并且找到指针相遇时各个分段路径的关系（设a = 入环的点到起始点的距离，b为慢指针入环后被追上时走的距离，c为环周长-b的距离）
 * 隐藏条件：慢指针入环后的第一圈肯定会被追上（极限情况，慢指针走满一圈，快指针走满2圈，所以第一圈肯定会被追上）
 * 等式 a+b+n(b+c) = 2(a+b)[快指针走的路程是慢指针的两倍]，因为要确定a的长度，所以等式a放一边，因为c是慢指针未走过的路程，如果找到a和c的关系，方便通过慢指针走c来得出a的长度。
 * 所以应该找到a和c的关系，等式结果为：a=(n-1)(b+c)+c，容易看出，两者相遇后，a=c，所以慢指针走完c的距离等于从头走到入环的位置。
 * 1、开头两个指针出发
 * 2、当快结点不为null且两个结点相等时，新结点从头出发，当两者相遇时，就是入环点。
 */
#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *detectCycle(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *slow = head;
    struct ListNode *quick = head;
    while (quick != NULL)
    {
        if (quick->next == NULL)
        {
            return NULL;
        }
        quick = quick->next->next;
        slow = slow->next;
        if (quick == slow)
        {
            struct ListNode *cur = head;
            while(cur!=slow){
                cur = cur->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}
// @lc code=end
