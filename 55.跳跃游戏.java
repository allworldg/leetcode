/*
 * @lc app=leetcode.cn id=55 lang=java
 *
 * [55] 跳跃游戏
 */
/* 思路
1、遍历每个点
2、如果遍历到的点加上它能位移的距离大于最远位置长度，则更新，并且判断是否能直接到达
3、如果不大于，则不更新
4、继续遍历下一个点
4、如果最终不可达，则返回false*/
// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        int maxLength = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i <= maxLength) {
                maxLength = Math.max(maxLength, i + nums[i]);
                if (maxLength >= nums.length-1) {
                       return true;
                }
            }
        }
        return false;
    }
}
// @lc code=end

