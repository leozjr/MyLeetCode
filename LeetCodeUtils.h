#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H
//IO
#include <iostream>
//容器
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

//算法
#include <algorithm>
#include <climits>
#include <random>
using namespace std;

//自定义数据结构
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};



/****************常用函数*****************/

// 生成vector
std::vector<int> generateVector(int length = 10, bool sorted = true, bool allowDuplicates = true) {
    std::vector<int> result(length);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 50);

    if (allowDuplicates) {
        for (int i = 0; i < length; ++i) {
            result[i] = dis(gen);
        }
    } else {
        std::unordered_set<int> uniqueValues;
        while (uniqueValues.size() < length) {
            uniqueValues.insert(dis(gen));
        }
        std::copy(uniqueValues.begin(), uniqueValues.end(), result.begin());
    }

    if (sorted) {
        std::sort(result.begin(), result.end());
    }

    return result;
}


// 打印vector
template<typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "vector: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif // LEETCODE_UTILS_H
