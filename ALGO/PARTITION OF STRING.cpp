#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int low, int high){
    while(low<high){
        if(str[low++]!=str[high--]) return false;
    }
    return true;
}
void recursive(vector<vector<string> > &allPart, vector<string> &currPart,string str, int low, int high){
    if(low>=high){
        allPart.push_back(currPart);
        return;
    }
    for(int i = low; i < high; i++){
        if(isPalindrome(str,low,i)){
            currPart.push_back(str.substr(low,high+1));
            recursive(allPart,currPart,str,low+1,high);
        }
        currPart.pop_back();
    }

}
// abccd
void allPartitions(string str){
    vector<vector<string> > allPart;
    vector<string> currPart;
    int n = str.length();
    recursive(allPart,currPart,str,0,n);
    for (int i=0; i< allPart.size(); i++ ) {
        for (int j=0; j<allPart[i].size(); j++) cout << allPart[i][j] << " ";
        cout << "\n";
    }
}
int main(){
    string str = "gnaig";
    allPartitions(str);
}

