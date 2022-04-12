/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.

Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.
*/
#include<bits/stdc++.h>
using namespace std;

  vector<string> output;
    vector<string> possiblePerm(int N, vector<string> &input, string op, int index){
        string op1;
        op1=op;
        if(N==index){
            output.push_back(op);
            return output;
        }
        string currentIndex = input[index];
        for(int i=0;i<currentIndex.length();i++){
            op1.push_back(currentIndex[0]);
            possiblePerm(N,input,op1,index+1);
            op1.erase(op1.begin()+op1.length()-1);
        }
        return output;
    }
 vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> keypad;
        for(int i=0;i<N;i++){
            switch(a[i]){
                case 2:
                keypad.push_back("abc");
                    break;
                  case 3:
                keypad.push_back("def");
                    break;
                  case 4:
                keypad.push_back("ghi");
                    break;
                  case 5:
                keypad.push_back("jkl");
                    break;
                  case 6:
                keypad.push_back("mno");
                    break;
                  case 7:
                keypad.push_back("pqrs");
                    break;
                  case 8:
                keypad.push_back("tuv");
                    break;
                  case 9:
                keypad.push_back("wxyz");
                    break;
                default:
                   break;
                
            }
        }
        string op = "";
        return possiblePerm(N,keypad,op,0);
    }
int main(){
    return 0;
}