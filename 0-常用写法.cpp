#include"LeetCodeUtils.h"

void main(){
    //---------------------vector-----------------------//
    vector<int> v1;
    vector<int> v2(10, 2);
    vector<int> v3 = {1, 1, 2, 1, 1, 2, 3};

    //增加
    v3.push_back(2);
    v3.emplace_back(3);

    //删除
    auto it = v3.erase(v3.begin() + 6); // erase返回被删除的下一个元素的迭代器
    

    //查找
    it = find(v3.begin(), v3.end(), 2); //vector没有自己的find
    int idx = std::distance(v3.begin(),it); //返回的下标的方法，也可以直接 it-v3.begin()，因为是随机访问迭代器
    cout << idx;

    //修改

    //---------------------set-----------------------//


    //---------------------map-----------------------//


    //---------------------string-----------------------//


    //---------------------stack-----------------------//


    //---------------------queue-----------------------//



}