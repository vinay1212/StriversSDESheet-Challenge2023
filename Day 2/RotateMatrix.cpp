// ### Approach1:

// - for rotating a array in clockwise direction, we need to traverse the matrix in anticlockwise direction.
    
//     basic idea is traverse in the opposite direction of stream, and shift the elements position by 1.
    
// - Basically, we will consider rings in matrix, and rotate each ring in clockwise direction.
// - create for loop, which will run from i =0 to n (n = no. of rings)
    
//     given matrix has 2 rings, one inner & one outer
    
//     to identify n = min(N/2, M/2)
    
// - Rotating each ring :
//     - start from last element of upper row, store its element in temp, as one element need to be stored, which we will use in the last
//     - traversing the ring in anticlockwise direction, copy the next element at the current position
//     - at last, the element just below last element of upper row, will take the value of upper element, which is already an updated value
        
//         soo, last element of ring have a value from second last element of upper row & not last element of upper row,( above eg 3 will be at last 
        
//         To correct this, we had stored the last value of upper row in some var temp, use it.
        
//     - Time complexity : O(N*M)


#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int a = 0, b = 0;
    if(n ==1 || m ==1)
        return;
    for(int i = 0; i < min(n/2, m/2); i++){
        int a = i, b = m-i-1;
        int t = mat[a][b];
        while(b > i){
            mat[a][b] = mat[a][b-1];
            b--;
        }
        while(a < (n-i-1)){
            mat[a][b] = mat[a+1][b];
            a++;
        }
        while(b < (m-i-1)){
            mat[a][b] = mat[a][b+1];
            b++;
        }
        while (a > i) {
          mat[a][b] = mat[a - 1][b];
          a--;
        }
        mat[a + 1][b] = t;
    }
}
