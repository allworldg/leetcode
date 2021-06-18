import java.util.Stack;

/*
 * @lc app=leetcode.cn id=224 lang=java
 *
 * [224] 基本计算器
 */
// 思路：使用堆栈来存放+-符号状态。不管括号里面的数值是怎么运算，最终括号的正负取决于（符号前面的符号。

// @lc code=start
class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<Integer>();
        int sign = 1;
        stack.push(sign);
        int result = 0;
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == ' ') {
                i++;
            } else if (s.charAt(i) == '+') {
                i++;
            } else if (s.charAt(i) == '-') {
                sign = -stack.peek();
                i++;
            } else if (s.charAt(i) == '(') {
                stack.push(sign);
                i++;
            } else if (s.charAt(i) == ')') {
                stack.pop();
                i++;
            } else {
                long nums = 0;
                while (i < s.length() && Character.isDigit(s.charAt(i))) {
                    nums = nums * 10 + s.charAt(i) - '0';
                    i++;
                }
                result += sign * nums;
            }
        }
        return result;
    }
}
// @lc code=end
