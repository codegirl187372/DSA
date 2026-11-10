
#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int>& nums) {
    int n = nums.size();

    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < n; i++) {
        int take = nums[i] + prev2;
        int notTake = prev1;

        int curr = max(take, notTake);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maximumNonAdjacentSum(nums);
    return 0;
}
