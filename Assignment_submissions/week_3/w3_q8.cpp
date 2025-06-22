#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    vector<int> sorted_unique = sequence;
    sort(sorted_unique.begin(), sorted_unique.end());
    sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());
    int m = sorted_unique.size();

    vector<long long> dp_prev(m);
    for (int j = 0; j < m; ++j) {
        dp_prev[j] = abs(sequence[0] - sorted_unique[j]);
    }

    for (int i = 1; i < N; ++i) {
        vector<long long> dp_current(m, LLONG_MAX);
        long long min_prev = LLONG_MAX;
        for (int j = 0; j < m; ++j) {
            min_prev = min(min_prev, dp_prev[j]);
            dp_current[j] = min_prev + abs(sequence[i] - sorted_unique[j]);
        }
        dp_prev = dp_current;
    }

    long long min_steps = *min_element(dp_prev.begin(), dp_prev.end());
    cout << min_steps << endl;

}