#include "LeetCodeUtils.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int middle = (right + left) / 2;

            if(nums[middle] > target)
                right =  middle - 1;
            else if(nums[middle] < target)
                left  = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};

int main(){
    Solution s;

    // vector<int> v = generateVector(10, true, false);
    vector<int> v = {-1, 0, 3, 5, 9, 12};
    printVector(v);

    cout << s.search(v, 2) << endl;
    return 0;
}