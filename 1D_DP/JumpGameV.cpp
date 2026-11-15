#include <bits/stdc++.h>
using namespace std;

int maxJumps(vector<int>& arr, int d) {
    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> idx(n);

    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return arr[a] < arr[b];
    });

    int ans = 1;

    for (int i : idx) {

        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i])
                break;

            dp[i] = max(dp[i], dp[j] + 1);
        }

        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i])
                break;

            dp[i] = max(dp[i], dp[j] + 1);
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxJumps(arr, d);

    return 0;
}
