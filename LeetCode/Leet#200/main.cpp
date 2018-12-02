/*

1로만 연결된 지점을 찾는 문제 


visited := 2d array , 방문 안했으면 0, 방문했으면 1
map := 2d array
ret := 0, 전체 섬의 개수

for i, j in ROW, COL :
    point := map[i][j],
    if not is_land(map[i][j]):
        continue
    if visited[i][j]:
        continue
    ret += 1
    check_visited(i,j) // i, j 지점과 연결된 모든 land는 방문 표시
    


visited 
check_visited(i, j):
    i, j와 연관된 모든 지점을 조사한다. 
    해당 지점은 탐사했다는 것을 알려야됨. 
    queue := queue()
    queue.push_back(i, j)
    while(not Queue.isEmpty()):
        node := queue.pop_front()
        cand_node := make_cand(node)
        checked(cand_node)
        queue.push_back(cand_node)
*/



int d[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
    
};
    


class Solution {
public:
    void search(int row, int col, const vector<vector<char>>&  grid, vector<vector<bool>>& visited){
        typedef pair<int, int> Point;
        visited[row][col] = true;
        deque<Point> aux;
        aux.push_back(make_pair(row, col));
        while(not aux.empty()){
            Point node = aux.front();   
            aux.pop_front();
            // cand를 만들고, visite check를 해줘야 한다. 
            for(int i = 0; i <4 ; ++i){
                int cr = node.first+d[i][0];int cc = node.second+d[i][1];
                if(cr < 0 or cr >= grid.size() or cc <0 or cc >= grid[0].size()) continue;
                if(grid[cr][cc] == '0')continue;
                    if(visited[cr][cc]) continue;
                    visited[cr][cc] = true;
                    aux.push_back(make_pair(cr, cc));                    
            }

        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size(); if(ROW == 0) return 0;
        int COL = grid[0].size(); if(COL == 0) return 0;
        int ret = 0; 

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        for(int row = 0; row < ROW; ++row){
            for(int col = 0; col < COL; ++col){
                char point = grid[row][col];
                if(point == '0')continue;
                if(visited[row][col])continue;
                ret += 1;
                search(row, col, grid, visited); // 끝나면 현재row, col과 연결된 곳들은 모두 방문함 상태로(visited) 변경되어야 한다. 
            }
            
        }
        return ret;
        
    }
};
