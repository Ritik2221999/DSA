#include<bits/stdc++.h>
using namespace std;

bool search(int i, int j, vector<vector<char>>& board, string &word, int k, int n, int m) {
//         base cases
    if(k == word.size()) return true;
    
    if(i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k]) return false;
    char ch = board[i][j];
    board[i][j] = '#'; // so that we won't rediscover the same cell again
    bool op1 = search(i+1, j, board, word, k+1, n, m);
    bool op2 = search(i, j+1, board, word, k+1, n, m);
    bool op3 = search(i-1, j, board, word, k+1, n, m);
    bool op4 = search(i, j-1, board, word, k+1, n, m);
    board[i][j] = ch; // backtracking
    
    return op1 || op2 || op3 || op4;
}

    
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == word[0]) {
                if(search(i, j, board, word, 0, n, m)) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'c', 'z', 'k', 'l'},
        {'o', 'd', 'i', 'a'},
        {'r', 'g', 'n', 'm'},
        {'m', 'r', 's', 'd'}
    };
    string str; 
    cout<<"Enter the word present in vector: "<<endl;
    cin>>str;  // "coding"
    
    
    if(exist(board, str)) {
        cout<<str<<" is present in vector: "<<endl;
    }
    else {
        cout<<str<<" is not present in vector: "<<endl;
    }
    return 0;
}