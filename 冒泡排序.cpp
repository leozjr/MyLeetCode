#include "LeetCodeUtils.h"

class Solution {
public:
    //冒泡，从小到大，原地排序，平方阶复杂度
    void bubbleSort(vector<int>& data,int n){
        for (int i = 0; i < n; i++){
            for (int j = n-1; j >0; j--){
                if(data[j] < data[j-1])
                    swap(data[j], data[j-1]); //每一次交换把最小的交换到最左边
            }
        }
        return;
    }
};

int main(){
    Solution s;
    vector<int> v = generateVector(10, false, false);
    printVector(v);
    s.bubbleSort(v, 10);
    printVector(v);
    return 0;
}