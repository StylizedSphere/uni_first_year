#include<bits/stdc++.h>
using namespace std;
string intToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

void addFunction(double a, double b){
    double c = a + b;
    string sA = intToString(a);
    string sB = intToString(b);
    string sC = intToString(c);
    int mapWidth;
    int widthA = sA.length();
    int widthB = sB.length();
    int widthC = sC.length();
    int blankA,blankB,blankC; blankA = blankB = blankC = 0;
    if(widthA >= widthB && widthA >= widthC) mapWidth = widthA;
    else if(widthB >= widthA && widthB >= widthC) mapWidth = widthB;
    else if(widthC >= widthA && widthC >= widthB) mapWidth = widthC;
    blankB = abs(mapWidth-widthB);
    blankA = abs(mapWidth-widthA);
    blankC = abs(mapWidth-widthC);
    if(a>0)cout<<" "; else cout<<"-";
    for(int i=0;i<blankA;i++){
        cout<<" ";
    }
    cout<<a<<endl;

    if(b>0){
        cout<<"+";
        for(int i=0;i<blankB;i++){
            cout<<" ";
        }
    }
    else{

        for(int i=0;i<blankB;i++){
            cout<<" ";
        }
    }

    cout<<" "<<b<<endl;


    for(int i=0;i<=mapWidth;i++){
        cout<<"-";
    }cout<<endl;

    if(c>0)cout<<" "; else cout<<"-";
    for(int i=0;i<blankC;i++){
        cout<<" ";
    }
    cout<<c<<endl;

}
