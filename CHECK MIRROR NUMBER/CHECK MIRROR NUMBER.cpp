#include <bits/stdc++.h>
using namespace std;
const int MAX_INT = 100000;
int checkMirrorNumber(int x){
    stringstream ss; ss<<x;
    string s = ss.str();
    int i=0;
    while(s[i]){
        if(s[i]!=s[s.length()-1]){
            return 0;
        }
        i++;
    }
    return 1;
}
int checkMirror(int x){
    int divide; int remainder[5];
    divide = x;
    int index=0;
    while(divide){
        remainder[index++] = divide%10;
        divide/=10;
    }
    for(int i=0;i<index;i++){
        if(remainder[i]!=remainder[index-1-i]) return 0;
    }
    return 1;
}
int main(){
    int low,high; int count = 0;
    low = 11; high = 23;
    for(int i=low;i<high;i++){
        if(checkMirror(i)){
            count++;
        }
    }
    cout<<"There are "<<count<<" mirror numbers in this range"<<endl;
}
