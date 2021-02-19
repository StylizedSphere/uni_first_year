#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
    int hour; cout<<"Input your hours of working: (155)"<<endl;
    double salary;
    double dept = 10000000;
    int month;
    hour=155; month=0;
    salary = hour*12000;
    if(hour>100 && hour<=150){
        salary += (hour-100)*16000;
    }
    else if(hour>150 && hour< 200){
        salary += 150*16000;
        salary += (hour-150)*20000;
    }
    else if(hour>200){
        salary+=50*16000;
        salary += 50*20000;
        salary+= (hour-200)*25000;
    }
    cout<<"Here is your initial salary \t"<<(int)salary<<endl;
    salary = salary*91/100;
    double price; price=0;
    if(salary>2000000){
        price += (salary-2000000)*20/100;
    }
    if(salary>1500000){
        price += (salary-1500000)*15/100;
    }
    if(salary>1000000){
        price += (salary-1000000)*10/100;
    }
    salary = salary - price;
    cout<<"Sadly, this is your salary after paying dept: \t"<<(int)salary<<endl;
    salary = salary -2000000;
    cout<<"Here, your salary after you use it for personal purposes: \t"<<(int)salary<<endl;
    while(dept>0){
        dept-=salary;
        month++;
        dept*=102/100;
        if(dept<0){
            cout<<"This takes you "<<month<<" months to finish the dept"<<endl;
            cout<<"Your remain money after those matter of time: \t"<<-dept<<endl;
        }
    }
}
