#include <iostream>
#include <vector>
using namespace std;
/**
 *给定一个 m\*n 的整数矩阵作为地图，矩阵数值为地形高度；

中庸行者选择地图中任意一点作为起点，尝试往上下左右四个相邻格子移动；

移动时有如下约束：
- 只能上坡或者下坡，不能走到高度相同的点；
- 不允许连续上坡或者连续下坡，需要交替进行；
- 每个位置只能经过一次，不能重复行走；
请给出中庸行者在本地图内，能连续移动的最大次数。

输入：

```
3 3
4 7 8
8 6 6
2 6 4
```

输出：一个整数，代表在本地图内能连续移动的最大次数。

样例：
```
输入：
2 2
1 2
3 4

输出：3(3->4->1->2)
```
*/
int m, n;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, bool isUphill) {
    int maxLen = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
            if ((isUphill && matrix[nx][ny] > matrix[x][y]) || (!isUphill && matrix[nx][ny] < matrix[x][y])) {
                visited[nx][ny] = true;
                maxLen = max(maxLen, 1 + dfs(nx, ny, !isUphill));
                visited[nx][ny] = false;
            }
        }
    }
    return maxLen;
}

int main() {
    cin >> m >> n;
    matrix.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = true;
            result = max(result, dfs(i, j, true));
            result = max(result, dfs(i, j, false));
            visited[i][j] = false;
        }
    }

    cout << result << endl;
    return 0;
}