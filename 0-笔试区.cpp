#include <iostream>
#include<vector>
#include<map>
using namespace std;

int isValid(string &s, int n){
    map<char, int> count;
    char prev = '0';
    for(char c : s){
        if(c != prev){
            if(count.find(c) == count.end()){
                count[c] = 0;
            }
            else{
                count[c]++;
            }
        }
        prev = c;
    }

    int result = 0;
    if(count.size() <= 2){
        return 1;
    }
    for (auto it = count.begin(); it != count.end(); it++){
        if(it->second > n){
            result++;
        }
    }
    return result;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> lines(m);
    for(int i = 0; i < m; ++i){
        cin >> lines[i];
    }

    for (auto &s : lines){
        cout << isValid(s, n) << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")