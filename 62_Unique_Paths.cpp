class Solution {
public:
    int solve(int row,int col){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        
        int left = solve(row,col-1);
        int up = solve(row-1,col);

        return up + left;
    }
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};