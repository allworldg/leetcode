import java.util.Stack;

/*
 * @lc app=leetcode.cn id=946 lang=java
 *
 * [946] 验证栈序列
 */

 /* 最简单思路：创建一个堆栈来模拟整个过程，如果模拟成功，最终堆栈应该为空，如果不为空说明popped序列不符合。 */

// @lc code=start
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<Integer>();
        int j = 0;
        for (int i = 0; i < pushed.length; i++) {
            stack.push(i);
            while (!stack.isEmpty() && stack.peek() == popped[j]) {
                j++;
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
// @lc code=end
