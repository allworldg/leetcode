import java.util.Stack;

/*
 * @lc app=leetcode.cn id=155 lang=java
 *
 * [155] 最小栈
 */

/* 思路：采用两个栈，一个栈普通存放值，还有一个min栈用于存放最小值。主要需要考虑的只有push和pop操作。
1、push操作时，比较push的值和min栈栈顶的大小，如果值小于等于min栈顶大小则插入。
2、pop操作时，查看普通栈pop出来的值是否小于等于min栈顶的值，如果小于等于则将min栈顶的值一起弹出。 */

// @lc code=start
class MinStack {
    Stack<Integer> stack;

    Stack<Integer> minStack;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<Integer>();
        minStack = new Stack<Integer>();
    }

    public void push(int val) {
        if (minStack.isEmpty() || minStack.peek() >= val) {
            minStack.push(val);
        }
        stack.push(val);
    }

    public void pop() {
        int val = this.stack.pop();
        if (val <= minStack.peek()) {
            minStack.pop();
        }
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such: MinStack obj =
 * new MinStack(); obj.push(val); obj.pop(); int param_3 = obj.top(); int
 * param_4 = obj.getMin();
 */
// @lc code=end
