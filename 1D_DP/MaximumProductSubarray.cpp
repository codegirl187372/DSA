#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {

    int n = nums.size();

    // Start with the first element
    int maxProd = nums[0];
    int minProd = nums[0];

    // Store the best answer in ans variable 
    int ans = nums[0];

    for (int i = 1; i < n; i++) {

        int curr = nums[i];

        // A negative number can turn the minimum product
        // into the maximum product, so swap both values
        if (curr < 0) {
            swap(maxProd, minProd);
        }

        // Either start a new subarray or extend the previous one
        maxProd = max(curr, maxProd * curr);
        minProd = min(curr, minProd * curr);

        // Update the maximum product found so far
        ans = max(ans, maxProd);
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

    cout << maxProduct(nums);

    return 0;
}
