import java.util.HashSet;

import javax.management.NotificationEmitter;

import org.graalvm.compiler.graph.Node;

/**
 * @Classname Main
 * @Description TODO
 * @Date 2021/6/2 11:39
 * @Created by 94493
 */
public class Main {
    public static void main(String[] args) {
        HashSet<Node> hashSet = new HashSet();
            
        return ;
    }
}

class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};

class Solution {
    public Node create(int val) {
        Node node = new Node();
        node.prev = null;
        node.next = null;
        node.child = null;
        node.val = val;
        return node;
    }

    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }
        Node cur = head;
        while (cur != null) {
            if (cur.child != null) {
                Node nextTemp = cur.next;
                cur.next = cur.child;
                Node last = dfs(cur.child);
                last.next = nextTemp;
                cur = nextTemp;
            } else {
                cur = cur.next;
            }
        }
        return head;
    }

    public Node dfs(Node head) {
        Node cur = head;
        while (cur.child != null) {
            Node nextTemp = cur.next;
            cur.next = cur.child;
            Node last = dfs(cur.child);
            last.next = nextTemp;
            cur = nextTemp;
        }
        while(cur.next!=null){
            cur = cur.next;
        }
        return cur;
    }

}