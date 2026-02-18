class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, char> color_map;
        int n = graph.size();
        for (int start = 0; start<n; start++){
            if (color_map.find(start) != color_map.end()) continue;
            queue<pair<int, int>> q;
            q.push({start, 'R'});
            while (!q.empty()){
                auto [node, color] = q.front();
                q.pop();
                if (color_map.find(node) != color_map.end()){
                    if (color_map[node] != color) return false;
                    continue;//already visited
                }
                color_map[node] = color;
                for (int nei: graph[node]){
                    char new_color = color=='R'?'B':'R';
                    q.push({nei, new_color});
                }
            }
        }
        
        return true;//no issues with coloring
    }
};