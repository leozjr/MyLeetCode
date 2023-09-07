#include"LeetCodeUtils.h"
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string x_str = to_string(x);
        string x_str_revert = x_str;
        reverse(x_str_revert.begin(), x_str_revert.end());

        if(x_str == x_str_revert)
            return true;
        else
            return false;
    }
};
// @lc code=end

