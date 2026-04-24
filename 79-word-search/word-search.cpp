class Solution {
public:
    bool match(vector<vector<char>>& mat, string word, int x, int y, int index){
        int n= mat.size();
        int wlen= word.size();
        int m= mat[0].size();
        if(wlen== index) return true;
        if(x<0 || y<0 || x>=n || y>=m) return false;
        if(mat[x][y]==word[index]){
            char temp= mat[x][y];
            mat[x][y]= '#';
            bool res= match(mat, word, x+1, y, index+1) ||
            match(mat, word, x-1, y, index+1) ||
            match(mat, word, x, y+1, index+1) ||
            match(mat, word, x, y-1, index+1);
            mat[x][y]= temp;
            return res;
        }
        return false;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        int wlen= word.size();
        int n= mat.size();
        int m= mat[0].size();
        if(wlen>n*m) return false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==word[0]){
                    if(match(mat, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};