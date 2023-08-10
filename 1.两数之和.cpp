/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> target_map;
        for(int  i= 0; i<nums.size(); i++){
            auto idx = target_map.find(target - nums[i]);
            if(idx != target_map.end()){
                return vector<int>{i, idx->second};
            }
            target_map[nums[i]] = i;
        }
        return  vector<int>{};
    }
};
// @lc code=end

int main(){
    vector<int> input = {1,2,3};
    Solution s;
    vector<int> a = s.twoSum(input, 3);
    printVector(a);
    return 0;
}