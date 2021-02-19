#include<bits/stdc++.h>
using namespace std;
char *pointerBeingReturned(const char *c1, const char *c2, int c1Len, int c2Len){
    char *p = new(nothrow)char[c1Len+c2Len];
    for(int i=0;i<c1Len;i++){
        p[i]=*(c1+i);
    }
    for(int i=0;i<c2Len;i++){
        p[i+c1Len]=*(c2+i);
    }
    return p;
}
int main(){
    char *pReturn,*pStr1, *pStr2;
    char c1[]="MY NAME IS GIANG. "; int c1Len = strlen(c1);
    char c2[]="NICE TO MEET YOU!"; int c2Len = strlen(c2);
    pStr1 = c1; pStr2 = c2;
    pReturn = pointerBeingReturned(pStr1,pStr2,c1Len,c2Len);
    cout<<pReturn;
}
