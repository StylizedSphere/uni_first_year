#include<bits/stdc++.h>
using namespace std;
const int TOTAL_CARDS = 52;
const int NUMBER_PLAYER = 4;
const int TYPES_CARDS = 4;
void printCards(int key){
    string prefix, postfix;
    if(0<= key && key <4) prefix = "HAI ";
    else if(4<= key && key <8) prefix = "BA ";
    else if(8<= key && key <12) prefix = "TU ";
    else if(12<= key && key <16) prefix = "NAM ";
    else if(16<= key && key <20) prefix = "SAU ";
    else if(20<= key && key <24) prefix = "BAY ";
    else if(24<= key && key <28) prefix = "TAM ";
    else if(28<= key && key <32) prefix = "CHIN ";
    else if(32<= key && key <36) prefix = "MUOI ";
    else if(36<= key && key <40) prefix = "J ";
    else if(40<= key && key <44) prefix = "Q ";
    else if(44<= key && key <48) prefix = "K ";
    else if(48<= key && key <52) prefix = "AT ";

    if(key%TYPES_CARDS==0) postfix = "BICH";
    else if(key%TYPES_CARDS==1) postfix = "TEP";
    else if(key%TYPES_CARDS==2) postfix = "ZO";
    else if(key%TYPES_CARDS==3) postfix = "CO";
    cout<<prefix+postfix<<endl;
}
void createAndShuffle(int deck[]){
    srand(time(NULL));
    int randomIndex; int temp;
    for(int i=0;i<TOTAL_CARDS;i++){
        deck[i] = i;
    }
    for(int i=0;i<TOTAL_CARDS;i++){
        randomIndex = rand()%TOTAL_CARDS;
        temp = deck[randomIndex];
        deck[randomIndex] = deck[i];
        deck[i] = temp;
    }
}
void distributeCards(vector<int>player[], int deck[], int& firstOneToPLay){
    int i = 0;
    while(i<TOTAL_CARDS){
        for(int j=0;j<NUMBER_PLAYER;j++){
            if(deck[i]==0) firstOneToPLay = j;
            player[j].push_back(deck[i++]);
        }
    }
}
void renderGame(vector <int>player[]){
    vector <int>::iterator itr;
    for(int i=0;i<NUMBER_PLAYER;i++){
        for(itr = player[i].begin();itr != player[i].end(); itr++){
            printCards(*itr);
        }
        cout<<"\n";
    }
}
int chooseCard(vector<int> player[], int pos, int previousCard){
    for(int i=0;i<player[pos].size();i++){
        if(player[pos][i]>previousCard){
            int card =  player[pos][i];

            vector<int>::iterator it;
            it = player[pos].begin()+i;
            player[pos].erase(it);
            return card;
        }
    }
    return -1;
}
int main(){
    int deck[TOTAL_CARDS];
    int firstOneToPlay;
    vector<int> player[NUMBER_PLAYER];
    vector<int>::iterator itr;
    createAndShuffle(deck);
    distributeCards(player,deck,firstOneToPlay);
    do{
        renderGame(player);
        int flag[NUMBER_PLAYER];
        for(int i=0;i<NUMBER_PLAYER;i++)flag[i]=1;
        int pos = firstOneToPlay; int prePos = pos;
        int numPlayer = 4; int card; int previousCard = -1;
        while(prePos != pos && numPlayer != 1){
            if(flag[pos]){
                card = chooseCard(player,pos,previousCard);
                if(card == -1){
                    flag[pos]=0;
                    numPlayer--;
                }
                else if(card != -1){
                    previousCard = card;
                    firstOneToPlay = pos;
                    printCards(card);
                }
            }
            pos = (pos+1)%NUMBER_PLAYER;
        }
    }while(player[0].size()!=0 && player[1].size()!=0 &&
           player[1].size()!=0 && player[3].size()!=0);

}
