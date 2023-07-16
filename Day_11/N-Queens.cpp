// Approach 1:

// - its a standard backtracking problem.
// - basically we will check for each col, in which row should we place the Q.
// - rules for n-queens in chessboard
//     - every row should have one queen
//     - every col should have one queen
//     - no two queens can attack each other(no 2 queens should be horizontal or diagonal)
// - we will create a recursive function that will find suitable rows for each col, at any point if col reaches to end of chess board starting left to right, 
//   we have placed n-queens with satisfying all conditions, return given arrangement as one of ans.

// ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/282d122c-840f-44dd-8187-1166dd260c1b/Untitled.png)

// ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9d7870c4-638d-48b6-87ca-350d80be3fae/Untitled.png)

// ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/db2f6a7f-97db-4c44-be19-62bdc4055361/Untitled.png)

// ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a0bda306-c484-4967-a1b0-fa3f0c68455f/Untitled.png)

// <aside>
// 💡

// `bool isSafe1(row,col, m) {`
//      `// check horizontal row in left, if any Q exists, if yes return false`
//      `// check upper diagonal, if any Q exists, if yes return false`

// `// check lower diagonal, if any Q exists, if yes return false`

//      `// if all above fails return true`

// `}`

// `void solve(col, board, ans, n) {
//      // if col reaches to the right end,
//          ans.push_back(board);
//          return;
//      for (row = 0 to n) {
//           // if current position isSafe 
//               board[row][col] = 'Q';         // place queen
//               solve(col + 1, board, ans, n); //check in next col,is there suitable pos
//               board[row][col] = '.';         // backtrack
//       }
// }`

// </aside>

// - Time complexity : O(N!*N)
// - space complexity : O(N*N)

// ### Approach 2:

// - we will use hashmap to store the positions of queens placed till now, so that we can find out the position is safe or not in O(1) time and not in O(N) 
//   for row check, O(N) for upper diagonal & O(N) for lower diagonal

// ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ad065c66-f31d-4686-8c79-021c053662c0/Untitled.png)

// ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a1170fba-33a7-4aac-91f0-454d30d9796f/Untitled.png)

// - when we place queen mark its resp indexes in each map as 1,
// - and when backtracking ie. removing queen, mark its resp indexes in each map as 0.
// - the position is safe when all th




#include<bits/stdc++.h>

void solve(int col,int n, vector<string>m, vector<vector<string>>&ans, vector<int>&left,vector<int>&ldiagonal, vector<int>&udiagonal){
    if(col == n){
        ans.push_back(m);
        return;
    }

    for(int row = 0; row < n; row++){
        if(left[row] == 0 && ldiagonal[row+col] == 0 && udiagonal[n-1 + col-row] == 0){
            m[row][col] = 'Q';
            left[row] = 1;
            ldiagonal[row+col] = 1;
            udiagonal[n-1 + col-row] = 1;

            solve(col+1, n, m, ans, left, ldiagonal, udiagonal);

            m[row][col] = '.';
            left[row] = 0;
            ldiagonal[row+col] = 0;
            udiagonal[n-1 + col-row] = 0;

        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<string>>ans;
    vector<string> m;
    string s(n, '.');
    for(int i = 0; i < n; i++){
        m.push_back(s);
    }
    vector<int> left(n, 0), ldiagonal(2*n-1, 0), udiagonal(2*n-1, 0);
    
    solve(0, n, m, ans, left, ldiagonal, udiagonal);

    vector<vector<int>>sol;

    for(int i = 0; i < ans.size(); i++){
        vector<int>temp;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(ans[i][j][k] == '.')
                    temp.push_back(0);
                else
                    temp.push_back(1);
            }
        }
        sol.push_back(temp);
    }
    return sol;
}
