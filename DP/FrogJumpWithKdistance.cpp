#include <bits/stdc++.h>
using namespace std;

int frogJumpK(int n, int k, vector<int>& height) {
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k && j <= i; j++) {
            int jump = dp[i - j] +
                       abs(height[i] - height[i - j]);

            dp[i] = min(dp[i], jump);
        }
    }

    return dp[n - 1];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << frogJumpK(n, k, height);
    return 0;
}
