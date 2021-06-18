import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=455 lang=java
 *
 * [455] 分发饼干
 */
/* 优化了一下之前一个思路的方法，需要明确：1、如果一个糖果不能满足较小同学的需求，那么肯定不能满足较大同学的需求。
2、能用较小糖果满足一个同学需求，则不用较大糖果去满足。
思路：
1、排序两个数组
2、设置两个变量，分别为child，表示满足孩子的孩子数量，以及sugar，表示已经试过的糖果数。
3、当child和sugar还没有被试完遍历两个数组
4、遍历时如果当前糖果满足孩子需求，则孩子数目+1
5、无论是否满足当前孩子需求，sugar都会+1，因为每个糖果只试验一次（如果满足当前孩子需求，
说明此糖果是最适合此孩子，如果不满足，则此糖果肯定也不会满足之后孩子的需求） */
// @lc code=start
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);//需求数组
        Arrays.sort(s);//糖果数组
        int child = 0;
        int sugar = 0;
        while (child < g.length && sugar < s.length) {
            if (g[child] <= s[sugar]) {
                child++;
            }
            sugar++;
        }
        return child;//返回满足的孩子数量
    }
}
// @lc code=end

