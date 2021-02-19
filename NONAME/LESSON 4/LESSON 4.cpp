#include <bits/stdc++.h>
using namespace std;
int main(){
    int row,col; cin>>row>>col;
    int bombNumber[row][col];
    char bombMap[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>bombMap[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            bombNumber[i][j]=0;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(bombMap[i-1][j]=='*'){
                bombNumber[i][j]++;
            }
            if(bombMap[i][j-1]=='*'){
                bombNumber[i][j]++;
            }
            if(bombMap[i-1][j-1]=='*'){
                bombNumber[i][j]++;
            }
            if(bombMap[i+1][j]=='*'){
                bombNumber[i][j]++;
            }
            if(bombMap[i][j+1]=='*'){
                bombNumber[i][j]++;
            }
            if(bombMap[i+1][j+1]=='*'){
                bombNumber[i][j]++;
            }
            if(bombMap[i-1][j+1]=='*'){
                bombNumber[i][j]++;
            }
            if(bombMap[i+1][j-1]=='*'){
                bombNumber[i][j]++;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(bombMap[i][j]=='*'){
                cout<<"* ";
            } else cout<<bombNumber[i][j]<<" ";
        }
        cout<<"\n";
    }
}
