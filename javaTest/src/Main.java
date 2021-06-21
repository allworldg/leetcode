import java.nio.file.StandardWatchEventKinds;
import java.util.*;


/**
 * @Classname Main
 * @Description TODO
 * @Date 2021/6/2 11:39
 * @Created by 94493
 */
public class Main {

    public static void main(String[] args) {
        TreeNode node3 = new TreeNode(3);
        TreeNode node5 = new TreeNode(5);
        TreeNode node1 = new TreeNode(1);
        TreeNode node6 = new TreeNode(6);
        TreeNode node2 = new TreeNode(2);
        TreeNode node0 = new TreeNode(0);
        TreeNode node8 = new TreeNode(8);
        TreeNode node7 = new TreeNode(7);
        TreeNode node4 = new TreeNode(4);
        node3.left = node5;
        node3.right = node1;
        node5.left = node6;
        node5.right = node2;
        node2.left = node7;
        node2.right = node4;
        node1.left = node0;
        node1.right = node8;
        Solution solution = new Solution();
        solution.lowestCommonAncestor(node3, node5, node1);
    }

}


class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Stack<TreeNode> stack1 = new Stack<TreeNode>();
        Stack<TreeNode> stack2 = new Stack<TreeNode>();
        Stack<TreeNode> resultStack1 = new Stack<>();
        Stack<TreeNode> resultStack2 = new Stack<>();
        preOrder(root, p, stack1,resultStack1, 0);
        preOrder(root, q, stack2,resultStack2, 0);
        while (!stack1.isEmpty() && !stack2.isEmpty()) {
            if (stack1.peek().val == stack2.peek().val) {
                return stack1.peek();
            }
            stack1.pop();
            stack2.pop();
        }
        return null;
    }

    int preOrder(TreeNode node, TreeNode target, Stack<TreeNode> stack,Stack<TreeNode> resultStack, int finish) {
        if (finish == 1 || node == null) {
            return 1;
        }
        stack.push(node);
        if (node.val == target.val) {
            finish = 1;
            resultStack = stack;
            return finish;
        } else {
            finish = preOrder(node.left, target, stack,resultStack, finish);
            finish = preOrder(node.right, target, stack,resultStack, finish);
            stack.pop();
        }
        return finish;
    }
}

 class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;

     TreeNode(int x) {
         val = x;
         left = null;
         right = null;
     }
}

