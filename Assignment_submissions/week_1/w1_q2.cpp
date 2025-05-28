#include <iostream>
#include <cmath>
using namespace std;

bool CheckBefore(const char *a, int b){
    if(b==0){ return false;}
    int i=b-1;
        if (a[b]==a[i]){
            return true;
        }
    
        return false;

}
int No_ofrep(const char *a,int b){
    int count=1;
    for (int i=b+1;a[i]!='\0';i++){
        if(a[b]==a[i]&&(i!=b)){count++;}
        if(a[b]!=a[i]){break;}
    }
    return count;
}

int main(){
    string b;
    int count=0;
    int max_count=0;
    getline(cin, b);
    const char*a=b.c_str();
    for (int i=0; a[i]!='\0';i++){
        if(CheckBefore(a,i)){
            continue;
        }
        count=No_ofrep(a,i);
        if (count>max_count){
            max_count=count;
        }
    }
    if(max_count==0){cout<<1;}
    else cout<< max_count;
}