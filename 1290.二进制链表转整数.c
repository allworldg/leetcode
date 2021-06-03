/*
 * @lc app=leetcode.cn id=1290 lang=c
 *
 * [1290] 二进制链表转整数
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* 思路：不一定需要从尾巴倒着算二进制转换成十进制，从高位遍历到低位，将每一位添加到result，每到下一位的时候，result*2即可算出十进制数 */


int getDecimalValue(struct ListNode* head){
    if(head==NULL){
        return 0;
    }
    int result = 0;
    while(head){
        result = result * 2 + head->val;
        head = head->next;
    }
    return result;
}

// @lc code=end

