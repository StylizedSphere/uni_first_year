#include<iostream>
#include <cstring>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        cout<<x;
        string s = to_string(x);
        if(s=="\n") return -1;
    }
}
