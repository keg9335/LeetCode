class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        self.time = [[101 for i in range(len(grid[0]))] for j in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    grid_cp = [[grid[i][j] for j in range(len(grid[0]))] for i in range(len(grid))]
                    self.dfs(grid_cp, i, j ,0)
        
        cnt = sum(1 for i in range(len(grid)) for j in range(len(grid[0])) if self.time[i][j]==101 and grid[i][j]==1)
        self.time = [[self.time[i][j] if self.time[i][j] != 101 else 0 for j in range(len(grid[0]))] for i in range(len(grid))]
        time_max = max(max(self.time[i]) for i in range(len(grid)))
        return -1 if cnt else time_max
        
    def dfs(self, grid, i, j, time):
        if i < 0 or j <0 or i >= len(grid) or  j>= len(grid[0]) or grid[i][j] == 0 : return

        if grid[i][j] == 1:
            grid[i][j] = 0   
        if grid[i][j] == 0 or time == 0:
            self.time[i][j] = min(self.time[i][j], time)
            grid_cp = [[grid[i][j] for j in range(len(grid[0]))] for i in range(len(grid))]
            self.dfs(grid_cp, i-1, j, time+1)
            self.dfs(grid_cp, i+1, j, time+1)
            self.dfs(grid_cp, i, j-1, time+1)
            self.dfs(grid_cp, i, j+1, time+1)
        
                
        