/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 */
/* 思路，贪心，如何贪：步数要最少，换言之步子要尽可能迈的大，跟第一个跳跃游戏类似
因为题目确定了一定能到达终点。所以只需遍历每个结点，每次找到可到达的最远位置即可
思路：1、初始化maxlength，end，step变量（end作为当前结点能走到的最远距离）
    2、开始遍历所有结点
    3、每次扫描结点都记录到达的最大距离
    4、如果到达起始结点能到达的最远结点，则将end更新为maxLength，继续遍历。
    5、此处需要注意，无需通过跳跃更新起始结点，因为只需要考虑在起始结点到达的范围内最远在哪，然后继续遍历过去即可
    不用考虑是从哪一个结点过去的。！
    6、同时我们不访问最后一个元素，因为如果访问最后一个元素相当于走到终点后还要判断跳转一次！
*/
// @lc code=start
class Solution {
    public int jump(int[] nums) {
        int maxLength = 0;
        int end = 0;
        int step = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            maxLength = Math.max(maxLength, i + nums[i]);//遍历，获得最大位置
            if (i == end) {//走到开始结点所能到达的最远位置
                end = maxLength;
                ++step;//其中肯定能选一个最大步伐走一次
            }
        }
        return step;
    }
}
// @lc code=end

