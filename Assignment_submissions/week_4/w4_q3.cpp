#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long C(long long n, long long r){
    r =min(r,n-r);
    long long ans=1;
    for(long long i=0;i<r;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}

int main(){
    long long n;
    cin>> n;
    vector<pair<long long,long long>> ds(n);
    for(long long  i=0;i<n;i++){
        cin>> ds[i].first>> ds[i].second;
    }
    const long long MOD = 1e9 + 7; 
    for(long long i=0;i<n;i++){
        cout<< (C(ds[i].first,ds[i].second)%MOD)<< endl;
    }
}