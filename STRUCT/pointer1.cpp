#include <iostream>
using namespace std;
char *reverseString(char *p, int cLen){
    char temp;
    for(int i=0;i<(cLen-1)/2;i++){
        temp = *(p+i);
        *(p+i)=*(p+cLen-2-i);
        *(p+cLen-2-i)=temp;
    }
    return p;
}
char *deleteCharacter(char *p, int cLen, char x){
    char c[cLen]; int i=0,pos=0;
    while(*(p+pos)!='\0'){
        if(*(p+pos)==x){
            pos++;
            continue;
        }
        c[i++]=*(p+pos);
        pos++;
    }
    for(i=0;i<cLen-1;i++){
        *(p+i)=c[i];
    }
    return p;
}
void padLeft(char *p, int cLen, int x){
    for(int i=cLen;i<x;i++){
        *(p+i-1)='x';
    }*(p+x-1)='\0';
}
void padRight(char *p, int cLen, int x){
    for(int i=0;i<cLen;i++){
        *(p+x-1-i)=*(p+cLen-1-i);
    }
    for(int i=0;i<x-cLen;i++){
        *(p+i)=' ';
    }
}
void truncate(char *p, int cLen, int x){
    if(x<cLen){
        for(int i=x;i<cLen;i++){
            *(p+i-1)=' ';
        }*(p+cLen-1)='\0';
        cout<<p;
    }
    else return;
}
void trimLeft(char *p, int cLen){
    if(*p==' '){
        int dem=0;
        while(*(p+dem)==' '){
            dem++;
        }
        for(int i=0;i<cLen-dem;i++){
            *(p+i)=*(p+dem+i);
        }
    }
}
void trimRight(char *p,int cLen){
    char *temp;
}
int main(){
    char c[22]="  !aaaaem si gnaiGaaa";
    int cLen=sizeof(c)/sizeof(c[0]);
    char *p=c;
}

