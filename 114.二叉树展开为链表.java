import java.lang.reflect.Array;
import java.util.ArrayList;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=114 lang=java
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

/* 思路：比较简单的方法：维护一个全局数组，
采用先序遍历，每次遍历将当前结点加入数组，并且在遍历完左侧结点后将指向left结点的指针置为空。
最后遍历数组，添加指向right的指针。*/
class Solution {
    ArrayList<TreeNode> arrayList = new ArrayList<TreeNode>();

    public void flatten(TreeNode root) {
        preOrder(root);
        for (int i = 0; i < arrayList.size()-1; i++) {
            arrayList.get(i).right = arrayList.get(i + 1);
        }
    }

    public void preOrder(TreeNode curr){
        if (curr == null) {
            return;
        }
        arrayList.add(curr);
        preOrder(curr.left);
        curr.left = null;
        preOrder(curr.right);
    }
    
}
// @lc code=end

