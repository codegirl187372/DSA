#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s) {
    int n = s.size(); 

    if (n == 0 || s[0] == '0')
        return 0;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    // First character is already checked so we dont check
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {

       //Check krenge ki current digit akele decode ho skti hai ?
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        // Take the last two digits
        int num = (s[i - 2] - '0') * 10
                  + (s[i - 1] - '0');

        // Two digit number should be between 10 and 26
        if (num >= 10 && num <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    string s;
    cin >> s;

    cout << numDecodings(s);

    return 0;
}
