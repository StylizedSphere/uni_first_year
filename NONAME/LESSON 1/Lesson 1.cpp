#include<iostream>
#include<cstdlib>
#include <string>
#include<cmath>
using namespace std;
struct calendar{
    int date,month,year;
};
struct calendar countDayForward(struct calendar today,int step){
    struct calendar tomorrow;
    tomorrow.year = today.year;
    if(today.year%4==0){
        if(today.month==2){
            if(today.date+step>29){
                tomorrow.month = today.month+1;
                tomorrow.date = (step+29-today.date);
            }
            else if(today.date+step<=29){
                tomorrow.date = today.date+step;
                tomorrow.month = today.month;
            }
        }
    }
    if(today.month==1 || today.month==3 || today.month==5 || today.month==7 || today.month==8
    || today.month==10 || today.month==12 ){
        if(today.date+step>31){
                if(today.month==12){
                    tomorrow.month = 1;
                    tomorrow.year++;
                    tomorrow.date = (step+29-today.date);
                }
                tomorrow.month = today.month+1;
                tomorrow.date = (step+29-today.date);
            }
            else if(today.date+step<=31){
                tomorrow.date = today.date+step;
                tomorrow.month = today.month;
            }
    }
    if(today.month==2 || today.month==4 || today.month==6 || today.month==9 || today.month==11){
        if(today.date+step>30){
                tomorrow.month = today.month+1;
                tomorrow.date = (step+29-today.date);
            }
            else if(today.date+step<=30){
                tomorrow.date = today.date+step;
                tomorrow.month = today.month;
            }
    }
    return tomorrow;
}

int main(){
    struct calendar today;
    struct calendar tomorrow;
    struct calendar yesterday;
    today.date = 23; today.month = 03; today.year = 2015;
    int step; cout<<"Input the number: "<<endl; cin>>step;
    tomorrow = countDayForward(today, step);
    if(tomorrow.month<10){
        cout<<tomorrow.date<<"-0"<<tomorrow.month<<"-"<<tomorrow.year<<endl;
    }
    else cout<<tomorrow.date<<"-"<<tomorrow.month<<"-"<<tomorrow.year<<endl;
}
