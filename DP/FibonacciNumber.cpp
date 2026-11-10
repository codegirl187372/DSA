#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;  // check validation 

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;// to find main logic
        prev2 = prev1;//main upgradation
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;

    cout << fib(n);
    return 0;
}
