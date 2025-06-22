#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e18;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    int max_value = 0;
    for (int val : v) {
        max_value += val;
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(max_value + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= max_value; ++j) {
            if (j - v[i-1] >= 0) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j - v[i-1]] + w[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int result = 0;
    for (int j = max_value; j >= 0; --j) {
        if (dp[N][j] <= W) {
            result = j;
            break;
        }
    }

    cout << result << endl;

}