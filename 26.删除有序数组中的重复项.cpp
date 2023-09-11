/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;

        for (int right = 0; right < nums.size(); right++){
            if(nums[slow] == nums[right])
                continue;
            else{
                slow++;
                nums[slow] = nums[right];
            }
        }
        return slow + 1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v = {1, 1, 2, 2, 3, 3, 4};
    printVector(v);
    cout << s.removeDuplicates(v) << endl;
    printVector(v);
    return 0;
}

