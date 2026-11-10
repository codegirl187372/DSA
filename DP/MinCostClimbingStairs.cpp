#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    int prev2 = 0;
    int prev1 = 0;
  
  // for(int i=0;i<n;i++){

  // }
  
    for (int i = 2; i <= n; i++) {
        int curr = min(
            prev1 + cost[i - 1],
            prev2 + cost[i - 2]
        );

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cout << minCostClimbingStairs(cost);
    return 0;
}
