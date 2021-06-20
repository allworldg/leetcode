import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=113 lang=java
 *
 * [113] 路径总和 II
 */

// @lc code=start
/* *
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

 /* 主要思路:
1、维护一个路径栈，每次遍历一个结点，将当前结点存入路径栈中，并且将当前结点的值计算到当前路过的总路径长度，判断如果当前结点为叶子结点并且总路径长度等于目标长度，则将当前栈塞入resultList中。
2、如果不符合要求，则继续遍历当前结点的左子树，然后遍历右子树。
3、左右子树遍历完毕后，需要将当前结点的值从栈中弹出，并且在路径之和里删除当前结点的值，进行下一条路线的选择。
注意：在代码中，如果判断当前结点符合要求，将当前路径存入resultlist后，程序是直接进行下一个左右结点的遍历，因为符合条件，当前结点肯定为叶子结点，传入的左右结点肯定为空，所以下一次递归会直接返回，不影响所有操作。 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> resultList = new ArrayList<List<Integer>>();
        Stack<Integer> stack = new Stack<Integer>();
        int pathValue = 0;
        preOrder(root, pathValue, targetSum, stack, resultList);
        return resultList;
    }

    void preOrder(TreeNode node, int pathValue, int targetSum, Stack<Integer> stack, List<List<Integer>> resultList) {
        if (node == null) {
            return;
        }
        pathValue += node.val;
        stack.push(node.val);
        if(node.right==null&&node.left&&==null&&pathValue==targetSum){
            ArrayList<Integer>arrayList = new ArrayList<>(stack);
            resultList.add(arrayList);
        }
        preOrder(node.left, pathValue, targetSum, stack, resultList);
        preOrder(node.right, pathValue, targetSum, stack, resultList);
        stack.pop();//当左右子树遍历完毕后，弹出当前结点
        pathValue -=node.val;//删除当前结点的值

    }
}
// @lc code=end

