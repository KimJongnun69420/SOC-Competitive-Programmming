#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<long long int,long long int>a,pair<int,int> b){
    if(a.first<b.first){return true;}
    else if(a.first>b.first){return false;}
    else if (a.second<b.second){return true;}
    else return false ;
}
int main(){
    int n;
    cin>> n;
    vector<pair<long long int,long long int>> t(n);
    for (int i=0;i<n;i++){
        cin>> t[i].first>> t[i].second;
    }
    sort(t.begin(),t.end(),compare);
    long long int time=0,r=0;
    for (pair<long long int,long long int> x: t){
        time+=x.first;
        r=r+ x.second-time;
    }
    cout<< r;

}
