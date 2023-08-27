#include "LeetCodeUtils.h"
/*
小Q得到了一堆双面扑克，正反面都会有一个整数，
能否让正面朝上的数字有一半是相等的，如果能的话最少需要反转多少张牌，
输入第一行为 n，表示有n张牌，紧接着n行，每行2个整数分别是正面数 a和反面数 b

输入：
    3
    4 7
    4 7
    7 4
输出 
    0
*/

int main(){
    int n;
    cin >> n;

    std::unordered_map<int, int> freq;
    std::unordered_map<int, int> positive_freq;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        freq[a]++;
        positive_freq[a]++;
        freq[b]++;
    }//统计频率

    if (n % 2 == 1){ // 奇数不可实现
        cout << -1;
        return 0;
    }

    bool found = false;
    int min_flip = INT_MAX;
    int flip;
    for (const auto& pair : freq) {
        if (pair.second >= n/2) {
            if(positive_freq.count(pair.first) > 0)
                flip = abs(n / 2 - positive_freq[pair.first]);
            else
                flip = n / 2;

            min_flip = min(min_flip, flip);
        }
    }

    cout << min_flip;

    return 0;
}