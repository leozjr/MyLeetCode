#include "LeetCodeUtils.h"
class Solution {
public:
    int numTrees(int n) {
        int dp[50];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[i-j]*dp[j-1];
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}