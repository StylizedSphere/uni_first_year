#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
    int arrRow[10],arrCol[10];
    int step; cout<<"Input the number of steps: "; cin>>step;
    int row,col; row=10;col=10;
    int a,b;
    int arr[row][col];
    for(int i=0;i<10;i++){
        arrRow[i]=arrCol[i]=0;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=0;
        }
    }
    while(step>0){
        cout<<"Input a and b: ";
        cin>>a; cin>>b;
        for(int i=0;i<a;i++){
            arrRow[i]++;
        }
        for(int i=0;i<b;i++){
            arrCol[i]++;
        }
        for(int i=row-a;i<row;i++){
            for(int j=0;j<b;j++){
                arr[i][j]++;
            }
        }
        step--;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    int max1,count1; count1=0; max1=arrRow[0];
    int max2,count2; count2=0; max2=arrCol[0];
    for(int i=0;i<10;i++){
        if(arrRow[i]>max1){
            max1=arrRow[i];
            count1=0;
        }
        if(arrRow[i]==max1){
            count1++;
        }
    }
    for(int i=0;i<10;i++){
        if(arrCol[i]>max2){
            max1=arrCol[i];
            count2=0;
        }
        if(arrCol[i]==max2){
            count2++;
        }
    }
    cout<<"The largest number's frequency is: "<<count1*count2;
}




/* dap an

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  int n;
  cin >> n;

  long long a = 1000000000, b = 1000000000;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    a = min(a, x);
    b = min(b, y);
  }

  cout << a * b << endl;

  return 0;
}
*/
