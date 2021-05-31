import java.util.HashMap;
import java.util.HashSet;

import org.graalvm.compiler.hotspot.replacements.HashCodeSnippets;

/*
 * @lc app=leetcode.cn id=142 lang=java
 *
 * [142] 环形链表 II
 */

// @lc code=start
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        HashSet<ListNode> hashSet = new HashSet<ListNode>();
        ListNode cur = head;
        while (cur != null) {
            if (!hashSet.add(cur)) {
                return cur;
            }
            cur = cur.next;
        }
        return null;
    }
}
// @lc code=end
