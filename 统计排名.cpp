/*
华为云面试题，统计排名：
给出一个成绩的列表，[s1,s2,s3,s4,,,sn]
请你返回一个统计每个分数在所有人中的排名，即统计比他分数高的人的个数，[t1,t2,t3,t4,tn]，保持原顺序输出。

请你尽量优化你的算法
分数区间[0,100]
n <= 60000
*/

#include"LeetCodeUtils.h"

//使用哈希表统计相同成绩的个数，然后遍历每个score，查找map中 score 在[100-scoren-1] 的值并求和
// 第一个循环复杂度为O(n)，第二个复杂度为O(n)，整体时间复杂度为O(n)，空间复杂度为 O(n)
vector<int> solution(vector<int> &score){
    unordered_map<int, int> score_count; //map默认初始化为0
    for(int i : score){
        score_count[i]++;
    }

    vector<int> output; 
    for(int i : score){
        int sum = 0;
        for (int j = i + 1; j <= 100; j++){
            sum += score_count[j]; // 内部是定长遍历
        }
        output.emplace_back(sum);
    }
    return output;
}

int main(){
    int n;
    vector<int> score = generateVector(100, 0, 100, false, true);
    printVector(score);
    printVector(solution(score));
}