import java.util.ArrayList;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并K个升序链表
 * 方法二：将所有结点排入arraylist，然后排序所有结点，重新生成链表。
 */

// @lc code=start

//   Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        if (lists.length == 1) {
            return lists[0];
        }
        Comparator<ListNode> comparator = (o1, o2) -> o1.val - o2.val;
        ArrayList<ListNode> arrayList = new ArrayList<ListNode>();
        for (int i = 0; i < lists.length; i++) {
            ListNode head = lists[i];
            while (head != null) {
                arrayList.add(head);
                head = head.next;
            }
        }

        arrayList.sort(comparator);
        for (int i = 0; i < arrayList.size() - 1; i++) {
            arrayList.get(i).next = arrayList.get(i + 1);
        }
        if (arrayList.size() == 0) {
            return null;
        }
        return arrayList.get(0);

    }
}
// @lc code=end
