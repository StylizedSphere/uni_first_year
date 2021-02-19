#include<iostream>
using namespace std;
int main(){
    string cmd;
    int low,high,mid;
    low=1; high=100;
    cout<<"Pick one number from 1 to 100"<<endl;
    while(low<high){
        mid= low+(high-low)/2;
        cout<< "Is this your number? "<<mid<<"\n";
        cout<<"Enter Y,L,H for yes,lower,higher: ";
        cin>>cmd;
        if(cmd[0]=='l'){
            high = mid-1;
        }
        else if(cmd[0]=='h'){
            low = mid+1;
        }
        else if(cmd[0]=='y'){
            low=mid;
            break;
        }
        else{
            cout<<"Press y,l,h only please!\n\n";
        }

    }
    cout<<"So your number is: "<<low<<"\nWe will now terminate the game. "<<endl;
}


