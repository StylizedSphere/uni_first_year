#include<bits/stdc++.h>
using namespace std;
const int ROW = 10;
const int COL = 10;
const int STATE = 10;
int data[ROW][COL];
bool revealed[ROW][COL];

int random(){
    int randomIndex;
    randomIndex=rand()%STATE;
    return randomIndex;
}
void renderMap(int data[][COL],bool revealed[][COL], bool printAll){
    if(printAll){
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                revealed[i][j]=true;
            }
        }
    }

    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(!revealed[i][j]){
                    cout<<"- ";
                    continue;
            }
            if(data[i][j]==-1)cout<<"* ";
            else cout<<data[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool outBound(int x, int y){
    return x<0 ||y<0 ||x>ROW || y>COL;
}
int calcNear(int data[][COL], int x, int y){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(outBound(x+i,y+j))continue;
            else{
                if(data[x+i][y+j]==-1) data[x][y]++;
            }
        }
    }
    return data[x][y];
}
void reveal(int x, int y){
  if(outBound(x,y))return;
  if(revealed[x][y])return;
  revealed[x][y]=true;
  if(calcNear(data,x,y)!=0)return;
  reveal(x-1,y-1);
  reveal(x-1,y+1);
  reveal(x+1,y-1);
  reveal(x+1,y+1);
  reveal(x-1,y);
  reveal(x+1,y);
  reveal(x,y-1);
  reveal(x,y+1);
}


int main(){
    srand(time(NULL));
    int x,y;
    int expr[]={-1,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            x=random();
            data[i][j]=expr[x];
        }
    }
    do{
        renderMap(data,revealed,false);
        cin>>x>>y;
        while(revealed[x-1][y-1]){
            cout<<"You already chose this. ";
            cin>>x>>y;
        }

        if(data[x-1][y-1]==-1) cout<<"You're dead!"<<endl;

        else{
            cout<<"You live... For now"<<endl;
            reveal(x-1,y-1);
            data[x-1][y-1] = calcNear(data,x-1,y-1);
        }
    }while(data[x-1][y-1]!=-1);
    renderMap(data,revealed,true);

}
