class Solution {
    public int maxMoves(int[][] grid) {
        int move = 0;
        int c = grid[0].length;
        int r = grid.length;
        int dp[][] = new int[r][c];

        for (int j = c - 2; j >= 0; j--) {
            for (int i = 0; i < r; i++) {
                if (i - 1 >= 0 && j + 1 < c && grid[i][j] < grid[i - 1][j + 1]) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j + 1] + 1);
                }
                if (grid[i][j] < grid[i][j + 1]) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][j + 1] + 1);
                }
                if (i + 1 < r && j + 1 < c && grid[i][j] < grid[i + 1][j + 1]) {
                    dp[i][j] = Math.max(dp[i][j], dp[i + 1][j + 1] + 1);
                }
            }
        }

        for (int k = 0; k < r; k++) {
            move = Math.max(move, dp[k][0]);
        }

        return move;
    }
}
