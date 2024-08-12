#include<bits/stdc++.h>
using namespace std;


int wordLadder(string startWord, string targetWord, vector<string> & wordList){
        // code here
        //Put all the words into a set
unordered_set <string> wordSet(wordList.begin(), wordList.end());
//Declare a Q which will store the sequence, till that point of time.
queue<vector<string>> q;
q.push({startWord});
//A vector to keep a track of the used words till that level.
vector<string> usedOnLevel;
//Declare Initial Level and a 2d vector to store the answer.
int level = 0;
vector<vector<string>> answer;
while(!q.empty()){
  vector<string> vec = q.front();
  q.pop();
  //Now how do you identify whether you have reached to an upper level? By comparing it to the size of the current sequence.
  // If the level has increased. You need to erase all the words that were used in earlier levels.
  if(vec.size() > level){
    level++;
    for(auto it: usedOnLevel){
      wordSet.erase(it);
    }
  }
  //Now we stick to the old logic, by changing every character one by one from a-z and match it from our set.
  string word = vec.back(); 

  //If you reach to the targetWord, then you need to make sure you store all the sequences, even if they are of same length.
  if(word == targetWord) {
    if(answer.size() == 0){
      answer.push_back(vec);
    }else if(answer[0].size() == vec.size()){
      answer.push_back(vec);
    }
  }
  for(int i=0;i<word.size();i++){
    char original = word[i];
    for(char ch='a'; ch<='z'; ch++){
       word[i] = ch;
  //We need to make sure we go through all the sequences in the current level.
    //If we match with a word in WordSet.
      if(wordSet.count(word) > 0){
      //Push the word in curr seq.
       vec.push_back(word);
      //Push the current seq into Q.
       q.push(vec);
       //We need to mark the word which is used in the current level.
       usedOnLevel.push_back(word);
       //We pop the current word from seq, in order to bring it back to the original state,
       //so that we can have other sequences of the same level as well.
       vec.pop_back();
      }
    }
    word[i] = original;
  }
}
return answer;}

int main(){
  return 0;
}
