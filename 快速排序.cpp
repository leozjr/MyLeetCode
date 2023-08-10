#include "LeetCodeUtils.h"
class Solution {
public:
    int partiton(vector<int>& data, int start, int end){
        int pidx = start; //定义交换idx
        int pivot = data[end]; //定义基准，取末尾这个数

        for (int i = start; i < end; i++){ 
            if(data[i] < pivot){ //将所有比基准小的数交换到开头，并持续记录idx
                swap(data[pidx], data[i]);
                pidx++;
            }
        }
        swap(data[pidx], data[end]); // 把基准交换到 pidx处，此时，data[pidx]左半侧都是比它小的数，右半侧都是比它大的数
        return pidx;
    }
    void quickSort(vector<int>& data, int start, int end){
        if(start >= end) //剩一个元素的时候，返回
            return;

        int pidx = partiton(data, start, end); //分割data，并返回分割idx
        //左右分治
        quickSort(data, start, pidx-1); 
        quickSort(data, pidx + 1, end);
    }
};

int main(){
    Solution s;
    vector<int> v = generateVector(10, false, false);
    printVector(v);
    s.quickSort(v, 0, 9);
    printVector(v);
    return 0;
}