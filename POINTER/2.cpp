#include<bits/stdc++.h>
using namespace std;
const int MOVE_TYPES_RABBIT = 4;
const int MOVE_TYPES_TURTLE = 3;
const int GOAL = 70;
void longMove(int& x,int turn); void shortMove (int& x,int turn);
void longFall(int& x,int turn); void shortFall(int& x,int turn);
void sleep(int& x);
// 1 means rabbit
void longMove(int& x,int turn){
    if(turn == 1){
        x+=9;
    } else x+=3;
}
void shortMove(int& x,int turn){
    if(turn == 1){
         x+=1;
    } else  x+=1;
}
void longFall(int& x,int turn){
    if(turn == 1){
         x-=12;
    } else  x-=6;
}
void shortFall(int& x,int turn){
     if(turn == 1) x-=2;
     else x-=6;
}
void sleep(int& x,int turn){
     cout<<"RABBIT IS SLEEPING... Seems like he stay up late last night"<<endl;
}
void renderGame(int x,int y){
    cout<<"RABBIT scores: "<<" "<<x<<" points"<<endl;
    cout<<"Our TURTLE scores: "<<" "<<y<<" points. Keep going pal!"<<endl;
}
int main(){
    int rabbitScore = 0, turtleScore = 0;
    void (*pRabbit[])(int&,int) =
    {longMove,longMove,
    shortMove,shortMove,shortMove,
    longFall,
    shortFall,shortFall,
    sleep,sleep};
    void (*pTurtle[])(int&,int) =
    {longMove,longMove,longMove,longMove,longMove,
    shortMove,shortMove,shortMove,
    shortFall,shortFall};

    while(rabbitScore < 70 && turtleScore < 70){
        srand(time(NULL));
        int randomIndex = rand()%MOVE_TYPES_RABBIT;
        pRabbit[randomIndex](rabbitScore,1);

        randomIndex = rand()%MOVE_TYPES_TURTLE;
        pTurtle[randomIndex](turtleScore,0);
        if(rabbitScore<0) rabbitScore = 0;
        if(turtleScore<0) turtleScore = 0;
        renderGame(rabbitScore,turtleScore);
    }
    if(rabbitScore >= 70) cout<<"RABBIT WINS. The faster earns vitory"<<endl;
    else cout<<"GODDAMMIT!!! TURTLE WINS. See, the faster doesn't always win"<<endl;
}
