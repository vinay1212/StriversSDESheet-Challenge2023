// ### Appraoch1 :

// - this question is same as bipartite graph, 2 coloring problem, where you needed to color the graph using 2 colors, here you have use M colors
// - basically we will try by coloring the first node with all colors, and recursively coloring the adjacent nodes with next color, start from vertex 0, color one by one with different color
// - if we have reached till nth node by coloring all vertices, return true.(base)
//     - try every color from 1 to M with help of for loop,
//     - call the function to check is it safe to apply, which color is safe to apply on current node, if it return true, it means no adjacent nodes of current node have same color, we can use it
//     - for checking if color applying is safe or not, simply create function that checks all adjacent nodes of current node, if any of them has current color,return false as 
// its not safe, else after checking them all, return true
//     - when we color it with ith color recursively call function on next node to find suitable color, if it return true then return true for current node,
//     - else we need to backtrack , and check next color, so change its color back to 0.
//     - now if we tried every possible color from 1 to M, and it was not possible to color it with any if them it means no graph cannot be colored, return false



#include<bits/stdc++.h>

bool ispossible(int node, int c, vector<int>&colors, vector<vector<int>>&mat){
    for(int i = 0; i < mat.size(); i++){
        if(mat[node][i] == 1 && colors[i] == c){
            return false;
        }
    }
    return true;
}
bool solve(int node, vector<int>&colors, vector<vector<int>>&mat, int m){
    if(node == mat.size()){
        return true;
    }

    for(int i = 1; i <= m; i++){
        if(ispossible(node, i, colors, mat) == true){
            colors[node] = i;
            if(solve(node+1, colors, mat, m) == true){
                return true;
            }
            else{
                colors[node] = 0;
            }
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> colors(mat.size(), 0);
    if(solve(0, colors, mat, m) == true)
        return "YES";
    return "NO";
}
