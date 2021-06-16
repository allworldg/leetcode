/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * 方法：此题思路比较简单，由于给的值都是合法的，只需要找到拼接的关键位置，进行拼接即可，注意边界值的设置问题，还不够熟练。
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    if(!list1){
        return NULL;
    }
    struct ListNode* cur = list1;
    struct ListNode* cura = NULL;
    struct ListNode* curb = NULL;
    int index = 1;
    while(cur->next){
        if(index==a){
            cura = cur;
        }
        if(index==b+1){
            curb = cur;
            break;
        }
        cur = cur->next;
        ++index;
    }

    cur = list2;
    while(cur->next){
        cur = cur->next;
    }
    cura->next = list2;
    cur->next = curb->next;
    return list1;
}