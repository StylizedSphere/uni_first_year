#include<bits/stdc++.h>
using namespace std;
const int maxQueenNumber = 10000;
int arr[maxQueenNumber];
bool checkQueenPos(int x, int y){
    for(int i=0;i<maxQueenNumber;i++){
        if(i==y || abs(i-x)==abs(arr[i]-y)) return false;
    }
    return true;
}
int main(){
    int numbers; cin>>numbers;
    int x,y;
    int count=0;
    while(numbers>0){
        cin>>x>>y;
        if(checkQueenPos(x,y)){
            arr[x]=y;
            continue;
        }
        count++;
        numbers--;
    }
    cout<<count;
}
