#include<bits/stdc++.h>
using namespace std;


int wordLadder(string startWord, string targetWord, vector<string> & wordList){
  queue<pair<string,int>> q;
  unordered_set<string> wordSet(wordList.begin(), wordList.end());
  q.push({startWord, 1}); 
  wordSet.erase(startWord);
  while(!q.empty()){
    string current_word = q.front().first;
    int level = q.front().second;
    q.pop();
  if(current_word == targetWord) return level;
    for(int i=0;i<current_word.size();i++){
    char original = current_word[i];
    for(char j='a'; j<='z';j++){
     current_word[i] = j;
     if(wordSet.find(current_word) != wordSet.end()){
       q.push({current_word,level+1});
       wordSet.erase(current_word);
     }
    }
    current_word[i] = original;
  }
  }
  return 0;
}

int main(){
  return 0;
}
