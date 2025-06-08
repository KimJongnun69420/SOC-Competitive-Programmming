#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    int j = 0, maxcount = 0, count = 0;
    for (int i = 0; i < n; i++) {
        for (int t = j; t < i; t++) {
            if (k[t] == k[i]) {
                j = t + 1;
                break;
            }
        }
        count = i - j + 1;
        if (count > maxcount) {
            maxcount = count;
        }
    }

    cout << maxcount << endl;
}
