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
#include <numeric>
#include <climits>
#include <random>
using namespace std;

//数据结构
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/****************常用函数*****************/

// 生成vector
std::vector<int> generateVector(int length = 10,int min = 0, int max = 100, bool sorted = true, bool allowDuplicates = true) {
    std::vector<int> result(length);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

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
    std::cout << "[";
    if (!vec.empty()) {
        auto it = vec.begin();
        std::cout << *it;
        ++it;
        for (; it != vec.end(); ++it) {
            std::cout << ", " << *it;
        }
    }
    std::cout << "]" << std::endl;
}

// 打印Matrix
template<typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix) {
    std::cout << "[" << endl;
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        std::cout << "  [";
        for (auto innerIt = it->begin(); innerIt != it->end(); ++innerIt) {
            std::cout << *innerIt;
            if (std::next(innerIt) != it->end()) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << endl;
    }
    std::cout << "]" << std::endl;
}


//生成ListNode测试序列
ListNode* generateLinkedList(int length, int maxVal, bool sorted = false) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    srand(time(NULL)); // 设置随机种子

    for (int i = 0; i < length; i++) {
        int val = rand() % maxVal; // 生成 [0, range-1] 范围内的随机数

        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            if (sorted) {
                // 如果需要有序链表，则将节点插入到正确的位置
                if (val < head->val) {
                    newNode->next = head;
                    head = newNode;
                } else if (val >= tail->val) {
                    tail->next = newNode;
                    tail = newNode;
                } else {
                    ListNode* curr = head;
                    while (curr->next != nullptr && curr->next->val <= val) {
                        curr = curr->next;
                    }
                    newNode->next = curr->next;
                    curr->next = newNode;
                }
            } else {
                // 如果需要无序链表，则将节点插入到尾部
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    return head;
}

//打印链表
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

#endif // LEETCODE_UTILS_H
