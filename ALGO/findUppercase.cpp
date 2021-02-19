#include<bits/stdc++.h>
using namespace std;
void recursive(char c[], int cSize, string str, int n){
    if(n==0){
        return;
    }
    for(int i=0;i<cSize;i++){
        string temp;
        temp = str+c[i];
        recursive(c,cSize,temp,n-1);
        if(n==1)cout<<temp<<endl;
    }
}
int main(){
    char c[] = {'a','b'};
    int cSize = sizeof(c)/sizeof(c[0]);
    vector<string> answer;
    recursive(c,cSize,"", 3);
}
