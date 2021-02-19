#include<bits/stdc++.h>
using namespace std;
const int maxQueenNumber = 8;
int arr[maxQueenNumber][maxQueenNumber];
bool checkQueenPos(int x, int y){
    for(int i=0;i<maxQueenNumber;i++){
        if(i!=x && arr[i][y]==1) return false;
    }
    for(int j=0;j<maxQueenNumber;j++){
        if(j!=y && arr[x][j]==1) return false;
    }
    for(int i=1;i<=maxQueenNumber;i++){
        if(arr[(x+i)%maxQueenNumber][(y+i)%maxQueenNumber]==1) return false;
    }
    return true;
}
int main(){
    int x,y;
    int count=0;
    for(int i=0;i<2;i++){
        cin>>x>>y;
        if(checkQueenPos(x,y)){
            arr[x][y]=1;
            continue;
        }
        count++;
    }
    cout<<count;
}
// arr[i][j]
