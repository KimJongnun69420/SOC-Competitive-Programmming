#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());

    bool found = false;
    for (int i = 0; i < n && !found; ++i) {
        int left = i + 1;
        int right = n - 1;
        int target = x - arr[i].first;
        while (left < right) {
            int current_sum = arr[left].first + arr[right].first;
            if (current_sum == target) {
                cout << arr[i].second << " " << arr[left].second << " " << arr[right].second << endl;
                found = true;
                break;
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}