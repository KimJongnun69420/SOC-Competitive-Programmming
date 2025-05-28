#include <iostream>
#include <cmath>
using namespace std;

bool find(unsigned long long int n,unsigned long long int k){
    if (n%2==0){return true;}
    if (k%2!= 0 && n>=k) {
        return true; 
    }
    return false;
}

int main(){
    int N;
    cin>>N;
    unsigned long long int k[N],n[N];
    for( int i=0; i<N;i++){
        cin>> n[i]>>k[i];
    }
    for (int i=0;i<N;i++){
        if(find(n[i],k[i])){cout<<"YES"<< endl;}  
        else{cout<< "NO"<< endl;}
    }
}

