#include"LeetCodeUtils.h"
/*
给定N个非负整数，依次输出前1，3，5，7，9。。。到 (2*k-1)个数的中位数，k = (N+1)/2
8
1 3 5 7 9 6 10
*/

int main() {
    int n;
    // cin >> n;
    // vector<int> num(n);
    // for(int i = 0; i < n; ++i){
    //     cin >> num[i];
    // }

    n = 8;
    vector<int> num = {1, 3, 5, 7, 9, 6, 8, 10};

    int k = (n + 1) / 2;
    vector<int> res(n);
    multiset<int> s;
    s.insert(num[0]);
    res[0] = num[0];
    for (int i = 3, m = 1; i <= (2 * k - 1); i += 2, m++){
        s.insert(num[i-2]);
        s.insert(num[i-1]);
        auto it = s.begin();
        advance(it, (s.size() - 1)/2);
        res[m] = *it;
    }
    for (int i = 0; i < k; i++){
        cout << res[i] << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")