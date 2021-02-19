#include<bits/stdc++.h>
using namespace std;
void drawRectangle(int blankCount, int xCount){
    for(int i=0;i<blankCount;i++)cout<<" ";
    for(int i=0;i<xCount;i++)cout<<"* ";
    for(int i=0;i<blankCount;i++)cout<<" ";
    cout<<"\n";
}
int main(){
    int n = 10;
    int xCount = 1;
    int blankCount = n-1;
    for(int i=0;i<n;i++){
        drawRectangle(blankCount--,xCount++);
    }
}
