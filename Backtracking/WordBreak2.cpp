#include<bits.stdc++.h>

using namespace std;

class Solution {
public:

void solve(int index, string &s, string &sentence, unordered_map<string,int> &uMap, 
vector<string> &result){
  //Base case
  //If you have explored all the possibilities
  if(index >= s.length()){
    result.push_back(sentence);
    return ;
  }
//Loop through the string and check if you can find a valid word
for(int curr = index; curr < s.length(); curr++){
    string word = s.substr(index, curr - index + 1);
    //if the extracted word is present in the dictionary, we will split from here
    if(uMap.count(word)){
      //need to store current sentence in order to undo it later
      string tempSentence = sentence;
      //if this is not the first word, then we need to add the space
      if(!sentence.empty()) sentence += " ";
      //Add the word to our sentence
      sentence += word;
      //since we have considered the word. we need to check the rest of the sentence
      solve(curr+1, s, sentence,uMap,result );
      //Now we need to undo our changes, in order to leave the possibility for other words
      sentence = tempSentence; 
    }
}

}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       vector<string> result;
       unordered_map<string,int> uMap;
       //add all these words to dictionary
       for(auto it: wordDict) uMap[it]++;
       string sentence;
       solve(0, s, sentence, uMap,result);
       return result; 
    }
};
int main(){
  return 0;
}
