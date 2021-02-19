#include<bits/stdc++.h>
using namespace std;
int main(){
    int row,col; cout<<"ROW? COL?: "; cin>>row>>col;
    int arr[row][col];
    int height, width; height = row; width = col;
    int value; value = 1;
    while(value<14){
        for(int i=0;i<col;i++){
            arr[row][i]=value++;
        }
        for(int i=0;i<row;i++){
            arr[i][col]=value++;
        }
        for(int i=col;i>1;i--){
            arr[row][i]=value++;
        }
        for(int i=row;i>1;i--){
            arr[i][col]=value++;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
