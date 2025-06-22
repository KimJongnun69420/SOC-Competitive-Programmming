#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    
    long long left = 1;
    long long right = *max_element(k.begin(), k.end()) * static_cast<long long>(t);
    long long answer = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long total = 0;
        for (int time : k) {
            total += mid / time;
            if (total >= t) {
                break;
            }
        }
        if (total >= t) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
}