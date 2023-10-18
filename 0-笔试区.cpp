#include <iostream>
#include<vector>
#include<string>
using namespace std;

/*
    盛水最多的容器

    给定一个数组height, 长度为n， 每个数代表坐标轴
    中一个点的高度，height[i]是第i点的高度，从中选2
    个高度与x轴组成的容器，最多能容纳多少水

    当n小于2时，返回0
    数据不会超整型范围
    输入：[1,7,3,2,4,5,8,2,7]
    输出: 49
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param height int整型vector 
     * @return int整型
     */
    int maxArea(vector<int>& height) {
        // write code here
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i < j) {
            int area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
            if(area > max) {
                max = area;
            }
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
};
int main() {
    Solution s;
    vector<int> height = {1,7,3,2,4,5,8,2,7};
    cout << s.maxArea(height) << endl;
    return 0;
}
