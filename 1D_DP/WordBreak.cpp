
#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {

    unordered_set<string> st;

    int maxLen = 0;

    // Store all dictionary words for quick lookup
    for (string word : wordDict) {
        st.insert(word);
        maxLen = max(maxLen, (int)word.size());
    }

    int n = s.size();

    // dp[i] tells whether first i characters can be broken
    vector<bool> dp(n + 1, false);

    // Empty string is always a valid starting point
    dp[0] = true;

    for (int i = 1; i <= n; i++) {

        // No need to check words longer than the longest dictionary word
        int start = max(0, i - maxLen);

        for (int j = start; j < i; j++) {

            // Previous part must be valid before checking the current word
            if (dp[j]) {

                string word = s.substr(j, i - j);

                // Check if this part exists in our dictionary
                if (st.count(word)) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[n];
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> wordDict(n);

    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    if (wordBreak(s, wordDict)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
