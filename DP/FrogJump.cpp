#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int>& height) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 1; i < n; i++) {
        int jump1 = prev1 + abs(height[i] - height[i - 1]);

        int jump2 = INT_MAX;

        if (i > 1) {
            jump2 = prev2 + abs(height[i] - height[i - 2]);
        }

        int curr = min(jump1, jump2);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << frogJump(n, height);
    return 0;
}
