#include <iostream>
# include<cmath>
using namespace std;

 int Getmax(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if (arr[i]>max){max=arr[i];}
    }
    return max; 
 }
 int Getmin(int arr[], int n){
    int min=1000001;
    for (int i=0;i<n;i++){
        if(arr[i]<min){min=arr[i];}
    }
    return min;
 }
 int luckiness(int n){
    int arr[7];
    int i=0;
    for (i;;i++){
        arr[i]=n%10;
        n=n/10;
        if(n==0){break;}
    }
    // BubbleSort(arr,i+1);
    return (Getmax(arr,i+1)-Getmin(arr,i+1));
}

int main() {
    int n;
    cin>> n;
    int l[n],r[n];
    for (int i=0;i<n;i++){
        cin>> l[i]>> r[i];
    }
    int max[n]={0},max_luckiness[n]={-1};
    for(int j=0;j<n;j++){
        for (int i=l[j];i<=r[j];i++){
            if(luckiness(i)>max_luckiness[j]){
                max_luckiness[j]=luckiness(i);        
                max[j]=i;
            }
            if (max_luckiness[j] == 9) break;
        }
        if (max[j]!=0){
            cout<< max[j]<< endl;}
        else if(max[j]==0){
            cout<<r[j]<< endl;
        }
        }
}
