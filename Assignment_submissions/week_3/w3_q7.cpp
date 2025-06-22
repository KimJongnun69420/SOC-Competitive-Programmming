#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    long long x, n;
    cin >> x >> n;
    vector<long long> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    priority_queue<long long, vector<long long>, greater<long long>> min_heap;
    for (long long length : d) {
        min_heap.push(length);
    }

    long long total_cost = 0;
    while (min_heap.size() > 1) {
        long long first = min_heap.top();
        min_heap.pop();
        long long second = min_heap.top();
        min_heap.pop();
        long long combined = first + second;
        total_cost += combined;
        min_heap.push(combined);
    }

    cout << total_cost << endl;

}