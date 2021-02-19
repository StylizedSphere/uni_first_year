#include<bits/stdc++.h>
using namespace std;
const int MAX_WRONG_GUESS = 10;
vector<string> database;

void fillData(string str){
    istringstream ss(str);
    string word;
    while(ss>>word){
        database.push_back(word);
    }
    for(int i=0;i<database.size();i++){
        cout<<database[i]<<endl;
    }
}
string chooseWord(){
    srand(time(NULL));
    int randomIndex = rand()%(database.size());
    return database[randomIndex];
}
bool contain(string secretWord, char inputWord){
	return (secretWord.find_first_of(inputWord) != string::npos);
}
string update(string secretWord, string guessedWord, char c){
    for(int i=0;i<secretWord.length();i++){
        if(secretWord[i] == c){
            guessedWord[i] = c;
        }
    }
    return guessedWord;
}
void renderGame(string secretWord, string guessedWord, int numWrongGuess){
    if(numWrongGuess == 1) cout<<"Remember you only have 10 "<<MAX_WRONG_GUESS<<" trials"<<endl;
    cout<<guessedWord<<"\t"<<numWrongGuess<<endl;
    if(guessedWord == secretWord) cout<<"You win!"<<endl;
}
int main(){
    char c; int numWrongGuess = 0;
    string str;
    string secretWord, guessedWord;
    getline(cin,str);
    fillData(str);
    secretWord = chooseWord();
    guessedWord = string(secretWord.length(),'-');

    do{
        renderGame(secretWord, guessedWord,numWrongGuess);
        cin>>c;
        if(contain(secretWord,c)){
            guessedWord = update(secretWord, guessedWord, c);
        }else numWrongGuess++;
    }while(numWrongGuess<MAX_WRONG_GUESS && guessedWord != secretWord);
    renderGame(secretWord, guessedWord, numWrongGuess);
}
