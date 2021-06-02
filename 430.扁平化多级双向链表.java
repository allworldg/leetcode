import java.util.Stack;

import org.graalvm.compiler.graph.Node;

/*
 * @lc app=leetcode.cn id=430 lang=java
 *
 * [430] 扁平化多级双向链表
 * 
 * 思路：创建一个栈存放含有child的结点，每当next没有值就弹出栈顶继续遍历
 * 
 * 方法：将图旋转九十度，即可发现是二叉树的先序深度遍历，child为左子树，next为右子树
 *      1、从头开始遍历链表
 *      2、每个结点开始dfs前保存next结点，因为可能会产生变动
 *      3、将前一个结点和当前结点进行dfs
 *      4、dfs过程：判断当前结点是否为空，为空直接返回前一个结点，不为空则建立两个结点的前后链表连接，然后保存当前结点的next结点
 *      5、之后将当前结点和当前结点的子节点进行dfs，返回dfs到最终的尾部结点。
 *      6、把当前结点的child设置为空，将dfs返回的尾部结点和保存的临时next结点进行dfs，同时返回最终尾部结点。
 */
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {
    }

    public Node(int _val, Node _prev, Node _next, Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }
        Node dummyNode = new Node(0, null, head, null);
        dfs(dummyNode, head);
        dummyNode.next.prev = null;
        return dummyNode.next;
    }

    public Node dfs(Node pre, Node cur) {
        if (cur == null) {
            return pre;
        }
        cur.prev = pre;
        pre.next = cur;
        Node nextTemp = cur.next;
        Node tail = dfs(cur, cur.child);
        cur.child = null;
       return dfs(tail, nextTemp);
    }
}
// @lc code=end
