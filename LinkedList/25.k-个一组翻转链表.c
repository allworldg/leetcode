/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };

 思路：设置快慢双指针，快指针先走，当走的距离等于k，反转慢指针和快指针的链表，然后重置走的距离
 慢指针指向快指针的位置，重复上述步骤，直到quick指针为null
 */


struct ListNode* reverse(struct ListNode *head,int k){
    struct ListNode* cur = NULL;
    int index = 0;
    while(index<k){
        struct ListNode* nextTemp = head->next;
        head->next = cur;
        cur = head;
        head = nextTemp;
        ++index;
    }
    return cur;
    
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL||k==1||k==0){
        return head;
    }

    struct ListNode *quick = head;
    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = 0;
    dummyNode->next = head;
    struct ListNode *slow = dummyNode; 
    int index = 1;
    while(quick){
          if(index==k){
              struct ListNode* nextSlowTemp = slow->next;
              struct ListNode* quickSlowTemp = quick->next;
              struct ListNode* newHead = reverse(slow->next,index);
              slow->next = newHead;
              nextSlowTemp->next = quickSlowTemp;
              slow = nextSlowTemp;
              quick = quickSlowTemp;
              index=1;
          }else{
              quick = quick->next;
              index++;
          }
    }
    return dummyNode->next;
}