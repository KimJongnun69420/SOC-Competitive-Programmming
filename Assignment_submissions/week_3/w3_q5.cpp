#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    vector<int> test_cases(t);
    int max_n = 0;
    for (int i = 0; i < t; ++i) {
        cin >> test_cases[i];
        max_n = max(max_n, test_cases[i]);
    }

    vector<long long> dp(max_n + 1, 0);
    dp[0] = 1;     
    if (max_n >= 1) dp[1] = 2;
    if (max_n >= 2) dp[2] = 8;
    if (max_n >= 3) dp[3] = 34;

    for (int i = 4; i <= max_n; ++i) {
        dp[i] = (
            2LL * dp[i - 1] % MOD +
            5LL * dp[i - 2] % MOD +
            4LL * dp[i - 3] % MOD +
            dp[i - 4]
        ) % MOD;
    }

    for (int n : test_cases) {
        cout << dp[n] << '\n';
    }

    return 0;
}
