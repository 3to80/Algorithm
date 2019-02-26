#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>


using namespace std;


int dr[3] = {-1, 0, 1};
int dc[3] = {-1, 0, 1};



class Solution {
public:
    void search(int row, int col, const vector<vector<char>>&  grid, vector<vector<bool>>& visited){
        typedef pair<int, int> Point;
        deque<Point> aux;
        aux.push_back(make_pair(row, col));
        while(not aux.empty()){
//            aux.front();
            Point node = aux.front();
            aux.pop_front();
            // cand를 만들고, visite check를 해줘야 한다.
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if( i== 1 and j==1) continue;
                    int cr = node.first+dr[i];int cc = node.second+dc[j];
                    if(cr < 0 or cr >= grid.size() or cc <0 or cc >= grid[0].size()) continue;
                    if(grid[cr][cc] == '0')continue;
                    if(visited[cr][cc]) continue;
                    visited[cr][cc] = true;
                    aux.push_back(make_pair(cr, cc));
                }
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

int arr[100][100];
int main(){
    memset(arr, -1, 10000);
    memset()
    vector<vector<string>> a(10, vector<string>(20, "a"));
    cout<<a[0][0];
    typedef pair<int, int> Point;
    make_pair(1, 1);
    deque<Point> deq;

    return 0;
}