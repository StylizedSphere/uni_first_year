#include<bits/stdc++.h>
using namespace std;
char *createString(char *p, int cSize){
    char *c = new(nothrow)char[cSize+1];
    if(c!=nullptr){
        for(int i=0;i<cSize;i++){
            c[i]= *(p+i);
        }c[cSize]='\0';
        p = c;
        delete []c;
    }
    else cout<<"Error in allocating memory!"<<endl;
    return p;
}
char *appendString(char *p1, const char *p2, int cSize1, int cSize2){
    char *c = new(nothrow)char [cSize1+cSize2+1];
    if(c!=nullptr){
        for(int i=0;i<cSize1;i++){
            c[i]= *(p1+i);
        }
        for(int i=0;i<cSize2;i++){
            c[i+cSize1]= *(p2+i);
        }
        c[cSize1+cSize2+1]='\0';
        p1 = c;
        delete []c;
    }
    return p1;
}
int main(){
    char *p1=NULL, *p2=NULL, *p=NULL;
    char c1[]="HELLO";char c2[]=" WORLD!";
    int pSize1 = strlen(c1); int pSize2 = strlen(c2);
    p1 = c1, p2 = c2;
    p = createString(p1,pSize1);
    p = appendString(p1,p2,pSize1,pSize2);

}
