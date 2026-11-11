
#include <bits/stdc++.h>
using namespace std;

long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();

    // dp[i] stores the best score starting from question i
    vector<long long> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {

        int points = questions[i][0];
        int brainpower = questions[i][1];

        int next = i + brainpower + 1;

        long long solve = points + dp[min(n, next)];

        long long skip = dp[i + 1];

        dp[i] = max(solve, skip);
    }

    return dp[0];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> questions(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> questions[i][0] >> questions[i][1];
    }

    cout << mostPoints(questions);

    return 0;
}
