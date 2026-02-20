#define tii tuple<uint, int, int>
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<tii> q;
        int N = grid.size(), M = grid[0].size();
        vector<vector<bool>> visited(N, vector(M, false));
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                if (grid[r][c] == 2)
                {
                    q.push(make_tuple(r, c, 0));
                }
            }
        }
        // int timer = 0;
        int ans = 0;
        vector<int> D({-1, 0, 1, 0, -1});
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto [r, c, time] = q.front();
                q.pop();
                if (visited[r][c])
                    continue;
                visited[r][c] = true;
                grid[r][c] = 2;
                ans = max(ans, time);
                for (int d = 0; d < 4; d++)
                {
                    int new_r = r + D[d];
                    int new_c = c + D[d + 1];
                    if (new_r >= N || new_r < 0 || new_c < 0 || new_c >= M)
                        continue;
                    if (grid[new_r][new_c] == 1)
                    {
                        q.push(make_tuple(new_r, new_c, time + 1));
                    }
                }
            }
        }
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                if (grid[r][c] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};