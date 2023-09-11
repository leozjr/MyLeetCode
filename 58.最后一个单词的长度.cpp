/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool start = false;
        bool stop = false;
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            if(s[i] != ' ' && !start){
                start = true;
            }
            
            if(start && s[i] == ' '){
                stop = true;
            }

            if(start && stop){
                break;
            }

            if(start && !stop){
                result++;
            }
            
        }
        return result;
        }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution s;
    string str = "abs husns adfsdf sdf   sdf    d   dsdf ";
    cout << s.lengthOfLastWord(str);

    return 0;
}

