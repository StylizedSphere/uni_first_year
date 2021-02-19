#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int main(){
    int celsi; cin>>celsi;
    double fahri;
    fahri = (double)celsi*9/5+32;
    cout<<fixed;
    cout<<setprecision(2);
    cout<<fahri;
}
