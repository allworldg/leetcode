import java.util.Stack;

/*
 * @lc app=leetcode.cn id=402 lang=java
 *
 * [402] 移掉K位数字
 */

/* 思路：通过栈来实现贪心算法,通过栈数据结构，当前数值和栈内元素比较，如果比栈内元素大则依次删除，把当前元素入栈
1、如果栈不为空&&k>0(表示还可以移除数字)&&栈顶元素比下一个元素大(说明前一个元素比后一个元素大，该删除)
2、比较结束，将当前元素入栈（需要判断，当前元素是否不为0，或者栈内是否为空（当前元素为0，可以入栈的条件是栈内有元素，这样0就不为先导0；
3、如果比较结束后，k还是大于0（说明还可以删除）并且栈不为空，则依次弹出栈 */
// @lc code=start
class Solution {
    public String removeKdigits(String num, int k) {
        String result = "";
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < num.length(); i++) {
            while (!stack.isEmpty() && k > 0 && num.charAt(i) - '0' < stack.peek()) {
                stack.pop();
                k--;
            }
            if (num.charAt(i) - '0' != 0 || !stack.isEmpty()) {
                stack.push(num.charAt(i) - '0');
            }
        }
        while (!stack.isEmpty() && k > 0) {
            stack.pop();
            k--;
        }
        if (stack.isEmpty()) {
            return "0";
        }
        while (!stack.isEmpty()) {
            result = stack.pop() + result;
        }
        return result;
    }
    
}
// @lc code=end
