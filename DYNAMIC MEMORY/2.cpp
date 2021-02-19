#include<bits/stdc++.h>
using namespace std;
int main(){
    int *p = new(nothrow)int[2];
    int x = 2;
    p[0] = x; p[1]=3;
    cout<<&p[0]<<" "<<&p[1];
    delete p;

}
