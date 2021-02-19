#include<bits/stdc++.h>
using namespace std;
const int MAX_QUEEN = 100;
int arr[MAX_QUEEN];
int checkQueenPos(int arr[],int arrSize,int x, int y){
    for(int i=0;i<arrSize;i++){
        if(arr[i]==y || i==x || abs(x-i)==abs(y-i)) return true;
    }
    return false;
}
int main(){
    int n; cin>>n;
    int x; int y;
    int arrSize=0;
    while(n>0){
        cin>>x>>y;
        if(checkQueenPos(arr,arrSize,x,y)) cout<<"INVALID";
        else{
            arr[x]=y;
            arrSize++;
        }
        n--;
    }
}
