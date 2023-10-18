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
    auto it = v3.erase(v3.begin() + 6); // erase返回被删除的下一个元素的迭代器，输入的是迭代器
    
    //查找
    it = find(v3.begin(), v3.end(), 2); //vector没有自己的find
    int idx = std::distance(v3.begin(),it); //返回的下标的方法，也可以直接 it-v3.begin()，因为是随机访问迭代器
    cout << idx;

    //修改

    //---------------------set-----------------------//
    // set不能用[]索引，因为不是随机访问的，只能用find和count
    set<int> test_set;
    test_set.insert(1); 
    test_set.find(1); // 返回迭代器，找不到就返回end()
    test_set.count(3); //只返回0,1因为不允许重复

    //---------------------map-----------------------//
    unordered_map<int, int> map;
    

    //---------------------string-----------------------//
    string a = to_string(1); // 可以把int,double,long,long long之类的数字型转为string

    //---------------------stack-----------------------//


    //---------------------queue-----------------------//


    //------------------常用算法------------------------//

    /*
    begin : 要查找的序列首地址，一般是迭代器
    end : 要查找的地址结束地址，一般是迭代器
    param 3 : 要查找的元素地址
    return 	: 使用二分查找，若存在，返回地址，若不存在，返回大于等于pram3的第一个地址
    */
    lower_bound(v3.begin(), v3.end(), 1); //返回的是迭代器


}