
    if(grid[i+1][j] < grid[i][j+1]) {
        ans = min(ans,  rec(i + 1, j) + grid[i][j]);
        done[i][j] = 1; // down
    }
    else if(grid[i][j+1] < grid[i+1][j]) {
        ans = min(ans, rec(i , j+1) + grid[i][j]);
        done[i][j] = 2; // right
    }
    else {
        if (rec(i + 1, j)< rec(i , j+1)) {
            ans = min(ans,  rec(i + 1, j) + grid[i][j]);
            done[i][j] = 1; // down
        } else {
            ans = min(ans,  rec(i , j+1) + grid[i][j]);
            done[i][j] = 2; // right
        }
    }
    