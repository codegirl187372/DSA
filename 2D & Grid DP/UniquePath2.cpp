#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> dp(n, 0);

    dp[0] = (obstacleGrid[0][0] == 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            }
            else if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[n - 1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << uniquePathsWithObstacles(grid);

    return 0;
}
