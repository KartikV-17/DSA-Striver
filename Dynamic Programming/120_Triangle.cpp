class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(i==triangle.size()-1) return dp[i][j] = triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int down = triangle[i][j] + solve(i+1,j,triangle,dp);
        int down_right = triangle[i][j] + solve(i+1,j+1,triangle,dp);
        return dp[i][j] = min(down,down_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //return solve(0,0,triangle,dp); "For Memoization Solution"
        
        // Tabulation :-
        
        for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down = triangle[i][j] + dp[i+1][j];
                int down_right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,down_right);
            }
        }
        return dp[0][0];
        
        // Space Optimisation :-
        /*
        int n = triangle.size();
        vector<int> front(n,0),cur(n,0);
        
        for(int j=0;j<n;j++) front[j] = triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down = triangle[i][j] + front[j];
                int down_right = triangle[i][j] + front[j+1];
                cur[j] = min(down,down_right);
            }
            front = cur;
        }
        return front[0];
        */
    }
};