import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

/*
 * @lc app=leetcode.cn id=138 lang=java
 *
 * [138] 复制带随机指针的链表
 * 思路：主要考虑如何记录random指针指向的节点
 * 1、遍历旧链表，遍历时通过arraylist记录每个节点，通过i自增记录节点位置，并且通过hashmap记录节点与i的关系
 * 2、重新遍历旧链表，遍历时将数组中的每个节点的next进行相连，
 *    同时判断如果旧链表节点存在random指针，则通过hashmap找到节点下表位置，然后通过位置获得数组中的节点，然后建立连接。
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        int i = 0;// 用于记录每个结点的下标
        ArrayList<org.w3c.dom.Node> nodeList = new ArrayList<Node>();
        HashMap<Node, Integer> nodeMap = new HashMap<>();
        Node cur = head;
        while (cur != null) {
            nodeList.add(new Node(cur.val));
            nodeMap.put(cur, i);
            cur = cur.next;
            i++;
        }
        i = 0;
        cur = head;// 重置,遍历链表同时生成新链表。
        nodeList.add(new Node(0));// 填充一个尾部，避免i造成数组越界
        while (cur != null) {
            nodeList.get(i).next = nodeList.get(i + 1);
            if (cur.random != null) {
                nodeList.get(i).random = nodeList.get(nodeMap.get(cur.random));
            }
            i++;
            cur = cur.next;
        }
        nodeList.get(i - 1).next = null;// 删除最后新增的多余几点.
        return nodeList.get(0);

    }
}
// @lc code=end
