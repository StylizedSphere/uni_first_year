#include<bits/stdc++.h>
using namespace std;
const int MAXROW = 50;
const int MAXCOL = 50;
const int TEXTROW = 6;
const int TEXTCOL = 11;
char screen[MAXROW][MAXCOL];

void renderScreen(char screen[][MAXCOL]);
void drawA(char screen[][MAXCOL], int x, int y);
int main(){
    drawA(screen, 10,5);
}
void drawA(char screen[][MAXCOL], int x, int y){
    if(y+TEXTCOL<MAXCOL && x+TEXTROW<MAXROW){
        screen[x+0][y+5]='*';

        screen[x+1][y+4]='*';screen[x+1][y+6]='*';

        screen[x+2][y+3]='*';screen[x+2][y+4]='*';screen[x+2][y+5]='*';
        screen[x+2][y+6]='*';screen[x+2][y+7]='*';

        screen[x+3][y+2]='*';screen[x+3][y+8]='*';

        screen[x+4][y+1]='*';screen[x+4][y+9]='*';

        screen[x+5][y]='*';screen[x+5][y+10]='*';
    }
    renderScreen(screen);
}
void renderScreen(char screen[][MAXCOL]){
    for(int i=0;i<MAXROW;i++){
        for(int j=0;j<MAXCOL;j++){
            cout<<screen[i][j]<<" ";
        }
        cout<<"\n";
    }
}

