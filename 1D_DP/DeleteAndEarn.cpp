#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    int maxNum = *max_element(nums.begin(), nums.end());

    // Store total points for every number 
    vector<long long> points(maxNum + 1, 0);

    for (int num : nums) {
        points[num] += num;
        cout << "Riya has Done it!"; // for debugging
    }

    // Now this works just like House Robber
    long long prev2 = 0;
    long long prev1 = 0;

    for (int i = 0; i <= maxNum; i++) {

        // Take current number and skip the previous one
        long long take = points[i] + prev2;

        // Skip current number and keep the previous answer
        long long notTake = prev1;

        long long curr = max(take, notTake);

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

    cout << deleteAndEarn(nums);

    return 0;
}
