#include <iostream>
using namespace std;

unsigned long long int get_odd(int n){
    if (n%2!=0){
        return n;}
    else return n/2;
}
int main() {
    unsigned long long int n,a;
    cin >> n;
    a=n;
    while(true){
        if((n==a)&&(n%2==0)){cout<<n<< " ";}
        n=get_odd(n);
        if(n==1){break;}
        cout<< n<<" ";
        if (n%2!=0){
            cout<<(3*n)+1<< " ";}
        if (n%2!=0){
            n = (3 * n) + 1; }
    }
    cout<< 1;
}