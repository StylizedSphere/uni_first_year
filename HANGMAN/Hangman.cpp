#include<bits/stdc++.h>
using namespace std;

const int MAX_WRONG_GUESS = 7;

char guessWord();
string chooseWord();
string update(string secretWord, string guessedWord,char inputWord);
string getLowerCaseString(string s);
bool contain(string secretWord, char inputWord);
void renderGame(string guessedWord, int wrongGuessCount);

int main(){
    int wrongGuessCount=0;

    char inputWord;
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    do{
        renderGame(guessedWord,wrongGuessCount);
        inputWord = guessWord();
        if(contain(secretWord,inputWord)&&!contain(guessedWord,inputWord)){
            guessedWord = update(secretWord,guessedWord,inputWord);
        }
        else wrongGuessCount++;
    }while(wrongGuessCount<MAX_WRONG_GUESS && guessedWord!= secretWord);
    renderGame(guessedWord,wrongGuessCount);
    if(wrongGuessCount==MAX_WRONG_GUESS)cout<<"You lose. "<<endl;
    else cout<<"You win. "<<endl;
    system("pause");
}

const string FIGURE[] = {
         "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",
};
string getLowerCaseString(string s){
    string output=s;
    transform(s.begin(),s.end(),output.begin(),::tolower);
    return output;
}
string chooseWord(){
    int randomIndex;
    vector<string> WORD_LIST;
    ifstream inFile ("database.txt");
    string firstWord;

    if(inFile.is_open()){
        while (inFile >> firstWord){
            WORD_LIST.push_back(firstWord);
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    else cout<<"Unable to open the file"<<endl;
    inFile.close();
    if(WORD_LIST.size()>0){
        srand(time(NULL));
        randomIndex = rand()%WORD_LIST.size();
        return getLowerCaseString(WORD_LIST[randomIndex]);
    }else return "";
}
char guessWord(){
    char inputWord;
    cout<<"Enter your guess: "<<endl; cin>>inputWord;
    return inputWord;
}
string update(string secretWord, string guessedWord,char inputWord){
        for (int i = secretWord.length() - 1; i >= 0; i--) {
            if (secretWord[i] == inputWord) {
                guessedWord[i] = inputWord;
                }
        }
    return guessedWord;
}
void renderGame(string guessedWord, int wrongGuessCount){
    cout << FIGURE[wrongGuessCount] << endl;
    if(wrongGuessCount==1){
        cout<<"Remember, if this picture pose you perfectly, you'll die"<<endl;
    }
    cout<<"Let's guess the secret word: "<<guessedWord<<endl;
    cout<<"Number of wrong guess: "<<wrongGuessCount<<endl;
}
bool contain(string secretWord, char inputWord){
	return (secretWord.find_first_of(inputWord) != string::npos);
}
