#include<bits/stdc++.h>
using namespace std;
int main(){
    int input; cin>>input;
    int row, col; row=col=input;
    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=0;
        }
    }
    int count = 1; int x; int y;
    y = col/2; x = 0;
    while(count<=row*col){
        if(arr[x][y]==0){
            arr[x][y] = count++;
            x = (x-1);
            if(x==-1) x = row-1;
            y = (y+1)%col;
        }
        else{
            x = (x+1)%row;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
