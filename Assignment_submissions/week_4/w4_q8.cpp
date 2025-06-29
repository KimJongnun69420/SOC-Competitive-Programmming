#include <iostream>
#include <vector>
using namespace std;

long long int MOD=1e9+7;

vector<long long> NSP(long long n){
    if(n==1){
        vector<long long>vec(3,1);
        return vec;
    }
    long long count=0;
    long long sum=0 ;
    long long product=1;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            sum+=i;
            product*=i;
            if(n/i!=i){
                count++;
                sum+=n/i;
                product*=n/i;
            }
        }
    }
    vector<long long> ds;
    ds.push_back(count);
    ds.push_back(sum);
    ds.push_back(product);
    return ds;
}

int main(){
    long long n;
    cin>> n ;
    vector<long long> ds= NSP(n);
    for ( long long x: ds){
        cout<< x %MOD<< " ";
    }
}