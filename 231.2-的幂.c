/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2的幂
 * 方法1，无脑循环，
 * 1、当值小于1肯定不是2的幂
 * 2、当n可以被2整除是，则不断除以2
 * 3、不能整除时判断是否为1，不为1说明不是2的幂
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n)
{
    if (n < 1)
    {
        return false;
    }
    while (n % 2 == 0)
    {
        n /= 2;
    }
    return n == 1;
}

bool isPowerOfTwo2(int n)
{
    return (n > 0) && n & (n - 1) == 0;
}
// @lc code=end
