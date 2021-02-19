#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;
void numberToEnglish(int x, int remainder, int groups){
    string dozens[19] = {"one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten "
    ,"eleven ","twelve ","thirdteen ","fourtene ","fifteen ","sixteen ","seventeen "
    ,"eighteen ","nineteen "};

    string drams[8] = {"twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy  " ,"eighty " ,"ninety "};

    string hundres[9] = {"one hundred","two hundreds ","three hundreds ","four hundreds ","five hundreds ",
    "six hundreds ","seven hundreds ","eight hundreds ","nine hundreds "};

    string number = to_string( x);
    string firstUnit = to_string(remainder);
    int count; count=0;
    for(int i=0;firstUnit[i];i++){
        count++;
    }
    if(count==1){
        cout<<dozens[count-1];
    }
    else if(count==2){
        if(firstUnit[0]=='1'){
            cout<<dozens[9+stoi(firstUnit[1])];
        }
        else{
            cout<<drams[atoi(firstUnit[0]-2)<<" "<<dozens[atoi(firstUnit[1])-1];
        }
    }
    else if(count==3){
        cout<<hundreds[atoi(firstUnit[0])-1]<<drams[atoi(firstUnit[1]-2)<<" "<<dozens[atoi(firstUnit[2])-1];
    }

}
int main(){
    int number x = 99123456;
    int group=0;
    int division, remainder; division=x;
    while(remainder>100){
        remainder = division%1000;
        divison/1000;
        group++;
    }
    numberToEnglish(x,remainder,groups);
}
