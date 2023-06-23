bool searchMatrix(vector<vector<int>>& mat, int target) {
        // for(int i = 0; i < mat.size(); i++){
    //     for(int j = 0; j < mat[0].size(); j++){
    //         if(mat[i][j] == target){
    //             return true;
    //         }
    //     }
    // }
    // return false;


    int m = mat[0].size()-1;
    for(int i = 0; i < mat.size(); i++){
        if(mat[i][m] < target)
            continue;
        else{
            for(int k = 0; k <= m; k++){
                if(mat[i][k] == target){
                    return true;
                }
            }
        }
    }
    return false;
}
