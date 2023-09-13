#include "LeetCodeUtils.h"

/*
题目描述
有n个人，每个人的能力值为
，性格值为
，要将这n个人分成若干组，每个人只能在一个组内。我们定义两个人的差别值为
.
规定一个差别上限L，如果两个人的差别值不超过L，那么在分组结果中这两人一定会在同一份组内（当然，即使两个人差别值超过L，两个人还是可以在同一小组，只是不超过L的必须在一组）。
现在我们想知道，如果能将所有人分成至少K个非空的小组，规定的差別上限最多为多少。

输入描述
第一行两个正整数n,k，表示人数和分组要求。
接下来两行每行n个整数，表示

输出描述
输出一个整数表示最大的差别上限

样例输入
3 2
1 9 3
2 7 8
样例输出
7
*/

/*
在构建图的时候，记录下权重的最大值和最小值，
符合条件的差别上限的最大值一定在这个范围之间。
最简单的方法，我们可以从小到大一个一个试这些差别上限。

对于某个差别上限L，对图中的每个节点为起点，分别开始dfs搜索，
在搜索的过程中，如果达到邻居节点的权重小于等于差别上限L，那么这个节点可达。
搜索结束，计算出可以分组的个数，也就是连通分量。


如果某次差别上限为L，计算出的分组数小于分组要求k，那么最大的差别上限就是L-1。
但是这样做时间复杂度太高，可以用二分查找优化
*/

void dfs(int x, int L, vector<vector<int>>& graph ,vector<bool> &visited){
    if(visited[x])
        return;

    visited[x] = true;

    for (int i = 0; i < visited.size(); i++){
        if(i == x) continue;

        if(graph[x][i] <= L){
            dfs(i, L, graph, visited);
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<vector<int>> graph(n, vector<int>(n));

    int max_diff = INT_MIN;
    int min_diff = INT_MAX;
    for (int i = 0; i < graph.size(); i++){
        for (int j = 0; j < graph.size(); j++){
            if(i == j) continue;
            int diff = abs(a[i] - a[j]) + abs(b[i] - b[j]);
            graph[i][j] = diff;
            graph[j][i] = diff;

            max_diff = max(max_diff, diff);
            min_diff = min(min_diff, diff);
        }
    }

    int l = min_diff - 1;
    int r = max_diff + 1;

    //遍历所有L，搜索连通子图的数量，L肯定在 min_diff 和 max_diff 之间，并且可以使用二分查找，因为一个 L 分的组太多，比它小的都可以排除，或者L分的组太少，那么比它大的也可以排除
    while(l + 1 != r){
        int m = (l + r) / 2;

        vector<bool> visited(n, false);
        int connect_num = 0;
        for (int i = 0; i < n; i++){
            if(visited[i]) continue;

            dfs(i, m, graph, visited);
            connect_num++;
        }

        if(connect_num < k)
            r = m;
        else
            l = m;
    }
    cout << l;

    return 0;
}