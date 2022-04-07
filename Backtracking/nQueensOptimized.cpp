   #include<bits/stdc++.h>
   using namespace std;

   void nQueens(int col,
                 vector<string>&board,vector<vector <string> > &results,
                 vector<int>&leftRow,vector<int>&lowerDiagonal,
                 vector<int>&upperDiagonal,int n){
        if(col == n){
            results.push_back(board);
            return;
        }
        for(int row =0;row<n;row++){
            if(leftRow[row]==0 
               && lowerDiagonal[row+col]==0
               && upperDiagonal[n-1 + col-row]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1 + col-row] = 1;
                nQueens(col+1,board,results,leftRow,lowerDiagonal,upperDiagonal,n);
                board[row][col]='.';
                leftRow[row] = 0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1 + col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector< vector <string>> results;
        string s(n,'.');
        vector<string> boards(n);
        for(int i=0;i<n;i++){
        boards[i]=s;        
        }   
        vector<int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        nQueens(0,boards,results,leftRow,lowerDiagonal,upperDiagonal,n);
        return results;
    }
    int main() {
  int n = 1; // we are taking 4*4 grid and 4 queens
  vector < vector < string >> ans =solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}