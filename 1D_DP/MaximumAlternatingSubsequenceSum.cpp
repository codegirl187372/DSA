
#include <bits/stdc++.h>
using namespace std;

long long maxAlternatingSum(vector<int>& nums) {

    long long even = 0;
    long long odd = 0;

    for (int num : nums) {

        long long newEven = max(even, odd + num);

        long long newOdd = max(odd, even - num);

        even = newEven;
        odd = newOdd;
    }

    return even;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxAlternatingSum(nums);

    return 0;
}
