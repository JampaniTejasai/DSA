// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.
// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.

int func(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(i==r-1) {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];   
    int maxi=INT_MIN;
    for(int a=-1;a<2;a++)
    {
        if(j1+a < 0 || j1+a>=c) continue;
        for(int b=-1;b<2;b++)
        {
            int value = 0;
            if(j2+b<0 || j2+b>=c) continue;
            if(j1+a!=j2+b) value = grid[i][j1]+grid[i][j2];
            else value = grid[i][j1];
            value+=func(i+1,j1+a,j2+b,r,c,grid,dp);
            maxi=max(value,maxi);
        }
        
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return func(0,0,c-1,r,c,grid,dp);
}