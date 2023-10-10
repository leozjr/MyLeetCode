/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> cur;
        int max_len = 0, left = 0;
        for (int i = 0; i < s.size(); i++){
            while(cur.find(s[i]) != cur.end()){//更新左边界
                cur.erase(s[left]);
                left++; 
            }
            cur.insert(s[i]);
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
// @lc code=end
int main(){
    string str = "abcdaddcbadef";
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
