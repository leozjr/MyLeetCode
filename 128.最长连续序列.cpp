/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> set;
        for(int n : nums){
            set.insert(n);
        }

        int max_len = 0;
        for(int cur : set){
            if(!set.count(cur-1)){
                int cur_num = cur;
                int cur_len = 0;
                while(set.count(++cur_num)){
                    cur_len++;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len+1;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}