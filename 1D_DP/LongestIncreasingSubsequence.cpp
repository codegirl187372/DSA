#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
  
    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 1; i < n; i++) {

        // Check all elements before the current element
        for (int j = 0; j < i; j++) {

            // We can extend the subsequence if the current
            // element is greater than the previous element
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // Keep track of the longest subsequence found so far
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << lengthOfLIS(nums);

    return 0;
}
