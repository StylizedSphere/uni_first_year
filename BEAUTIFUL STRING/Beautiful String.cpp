/*
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int countVariation(char str[]){
    int count;
    int total = strlen(str)*(strlen(str)-1)/2;
    int duplicate; duplicate=0;
    int low,high; low=0;
    int flagLow,flagHigh;
    for(low=0;low<strlen(str)-1;low++){
        high=low+1;
        if(str[low]==str[low+2]&& str[low]!=str[low+1]){
            duplicate++;
            }
        while(high<strlen(str)){
            if(str[high]==str[high-1] && high-low!=1)flagHigh=1;
            else flagHigh=0;
            if(str[low]==str[low-1])flagLow=1;
            else flagLow=0;
            if(flagHigh==1||flagLow==1){
                duplicate++;
            }
            high++;
        }
    }
    count = total-duplicate;
    return count;
}
int main(){
    char str[]= "abbaababbaedbac";
    int count = countVariation(str);
    cout<<"The number of UNIQUE variation is: "<<count;
}
*/


#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 1000500;

string s;
int p[N];
char c[N];
long long f[3][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int idx = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[i + 1] && i + 1 < n) {
            p[1 + idx]++;
        } else {
            c[1 + idx] = s[i], p[1 + idx++]++;
        }
    }
    n = idx;
    f[0][0] = 1LL;
    for (int i = 0; i < n; ++i) {
        f[0][i + 1] += f[0][i];
        f[1][i + 1] += f[1][i];
        f[2][i + 1] += f[2][i];
        if (p[i + 1] >= 2) {
            f[2][i + 1] += f[0][i];
        }
        if (p[i + 1] >= 1) {
            if (i + 2 <= n && p[i + 1] == 1 && c[i] == c[i + 2]) {
                f[2][i + 2] -= 1;
            }
            f[1][i + 1] += f[0][i];
            f[2][i + 1] += f[1][i];
        }
    }
    cout << f[2][n] << endl;
    return 0;
}

