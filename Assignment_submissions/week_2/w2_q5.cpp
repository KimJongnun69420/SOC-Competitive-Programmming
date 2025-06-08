#include <iostream>
#include <vector>
#include<cmath>
#include <algorithm>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    vector<long long int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());
    long long int median = p[n / 2]; 
    long long int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(p[i] - median);
    }
    cout << cost ;
}
