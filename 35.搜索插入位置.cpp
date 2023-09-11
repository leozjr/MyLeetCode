/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int middle = 0;
        while(begin <= end){
            middle = (begin + end) / 2;
            if(nums[middle] < target){
                begin = middle + 1;
            }
            else if(nums[middle] > target){
                end = middle - 1;
            }
            else{
                return middle;
            }
        }
        return begin;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {1,3,5,6};
    cout << s.searchInsert(v, 0) << endl;
    cout << s.searchInsert(v, 3) << endl;

    return 0;
}

