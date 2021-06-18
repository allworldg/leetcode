import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=455 lang=java
 *
 * [455] 分发饼干
 */
/* 方法比较简单暴力，主要思路：
1、考虑异常情况，当两个数组中存在长度为0的数组，则直接返回0；
2、排序两个数组
3、遍历需求数组，遍历时依次判断糖果数组的值是否满足需求，满足则计数+1，不满足则往后找。
4、返回计数值。 */
// @lc code=start
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);//需求数组
        Arrays.sort(s);//糖果数组
        int count = 0;
        int index = 0;
        for (int i = 0; i < g.length; i++) {
            while (index < s.length) {
                if (s[index] < g[i]) {
                    index++;
                }
                else if (s[index] >= g[i]) {
                    index++;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
// @lc code=end

