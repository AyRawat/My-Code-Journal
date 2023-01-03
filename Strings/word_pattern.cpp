#include<bits/stdc++.h>
using namespace std;

//More Intiuitive Solution
 bool wordPatternInt(string pattern, string s)
        {
            vector<string> v;

            // separate the string with the whitespaces 
            stringstream ss(s);
            string word;
            while( ss >> word ) v.push_back( word );

            // if data is insufficient 
            if (v.size() != pattern.size()) return false;

            unordered_map<char, string> m;
            set<string> st;

            for (int i = 0; i < pattern.size(); i++){

                if (m.find(pattern[i]) != m.end()){
                	// pattern = "abba", s = "dog cat cat fish"
                    if (m[pattern[i]] != v[i]) return false;
                }
                else{
                    // if any of the alphabet have'nt matched with string
                    if (st.count(v[i]) > 0) return false;
                    m[pattern[i]] = v[i];
                    st.insert(v[i]);
                }
            }

            return true;
        }
//EAsy to Understand
    bool wordPattern(string pattern, string s) {
         unordered_map<char,string> chToWordMap;
         unordered_map<string,char> wordToChMap;
         s.push_back(' ');
         string currentWord="";
         int chIndex =0 ;
         for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
               char currCh = pattern[chIndex++];
               if(chToWordMap.count(currCh)){
                 if(chToWordMap[currCh]!=currentWord) return false;
               }else if(wordToChMap.count(currentWord)){
                 if(wordToChMap[currentWord]!=currCh) return false;
               }else{
                chToWordMap[currCh] = currentWord;
                wordToChMap[currentWord] = currCh;
               }
               currentWord = "";
            }else{
               currentWord.push_back(s[i]);
            }
         }
         return (chIndex == pattern.size());
    }


int main(){
   string pattern = "abba";
   string s = "dog cat cat dog";
cout<<" "<<wordPattern(pattern, s);
   return 0;
}