#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int check(int x){
    for(int i=2;i<x;i++){
        if(x%i==0){
            return 0;
        }
    }
    return -1;
}
int main(){
    int x; cin>>x;
    int condition = check(x);
    if(condition){
        cout<<"yes it is";
    }
    else cout<<"no it is not";
    system("pause");
}
