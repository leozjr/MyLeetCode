#include "LeetCodeUtils.h"
class Solution {
public:
    int bagProblem1D(vector<int>& weight, vector<int> value, int bag_weight){
        vector<int> dp(bag_weight+1, 0);

        for (int i = 0; i < weight.size(); i++){
            for (int j = bag_weight; j >= weight[i]; j--){ // 注意遍历到 weight[i] 就停，因为 j 再小的话 i 是装不进去的，再继续遍历就错了。
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }
        }
        
        printVector(dp);
        return dp[bag_weight];
    }    
};

int main(){
    Solution s;
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bag_weight = 4;
    cout << s.bagProblem1D(weight, value, bag_weight) << endl;

    return 0;
}