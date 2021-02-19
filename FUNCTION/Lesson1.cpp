#include<bits/stdc++.h>
using namespace std;
bool checkEqualArray(int firstArr[], int secArr[],int x){
    if(x>0){
        if(checkEqualArray(firstArr,secArr,--x)) {
            x++;
            return firstArr[x]==secArr[x];
        }else return false;
    }
    return firstArr[x]==secArr[x];
}
int main(){
    int n = 5;
    int firstArr[n]={1,88,3,4,5};
    int secArr[n]={1,2,3,4,5};
    if(checkEqualArray(firstArr,secArr,n-1)) cout<<"true"<<endl;
}
