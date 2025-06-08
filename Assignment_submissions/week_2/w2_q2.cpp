#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
  unordered_map<int,int> um;
  int n,x;
  cin>> n>> x;
  vector<int> vec(n),ans;
  for (int i=0;i<n;i++){
    cin>>vec[i];
  }
  for(int i=0;i<n;i++){
    int tar= x- vec[i];
    if(um.find(tar)!=um.end()){
        ans.push_back(i);
        ans.push_back(um[tar]);
        break;
    }
    um.emplace(vec[i],i);
  }
  if(!ans.empty()){
      for (int x:ans){
    cout<<x+1 << " ";
  }
  }
  else{
    cout<<"IMPOSSIBLE";
  }
}