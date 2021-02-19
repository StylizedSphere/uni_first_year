#include<bits/stdc++.h>
using namespace std;
int main(){
    int row,col; cout<<"INPUT ROW, COL:"; cin>>row>>col;
    int arr[row][col];
    int count = 1;
    int low,high,left,right;
    low = 0; high = row-1; left = 0; right = col-1;
    while(count<row*col){
        for(int i=left;i<=right;i++){
            arr[low][i]=count++;
        }
        low++;
        for(int i=low;i<=high;i++){
            arr[i][right]=count++;
        }
        right--;
        for(int i=right;i>=left;i--){
            arr[high][i]=count++;
        }
        high--;
        for(int i=high;i>=low;i--){
            arr[i][left]= count++;
        }
        left++;

    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]<10){
                cout<<arr[i][j]<<"    ";
            }
            else if(arr[i][j]>99) cout<<arr[i][j]<<"  ";
            else cout<<arr[i][j]<<"   ";
        }
        cout<<"\n";
    }
}
