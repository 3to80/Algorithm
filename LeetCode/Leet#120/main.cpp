/*
2
3 4
6 5 7 
4 1 8 3 

f(0, 0)에서 시작해서 최대 값인 것 
= f(1, 0), f(1, 1) 최대값 + t(0,0)

f(1,0) : f(2, 0) f(2, 1) 최대값 + t(1, 0) ...

f(4, 0) : 4
f(4, 1) : 1
f(4, 2) : 8
f(4, 3) : 3

f(3, 0) : f(4, 0) 이랑 f(4, 1)에서 최대값 
f(3, 1) : f(4, 1) 이랑 f(4, 2)에서 최대값
f(3, 2) : f(4, 2) 랑 f(4, 3)에서 최대값
... iteration으로 구성하면 된다. 


int bst = 987654321;

// N 은 arr[N] : n 번째 줄에서 끝날 때의 최소 값
int MAXN = triangle.size(); 
int base[MAXN] = {987654321}; 
int aux[MAXN] = {987654321};

for(int i = 0; i < triangle[MAXN-1].size(); ++i)
    base[i] = triangle[MAXN-1][i];

for(int r = triangle.size()-2; r > -1; --r){
    for(int c = 0; c < triangle[r].size(); ++c)
        aux[c] = min(base[c], base[c+1]) + triangle[r][c];
    
    for(int c = 0; c < triangle[r].size(); ++c)
        base[c]= aux[c];
}
int minval = 987654321;
for(int i = 0; i < triangle[0].size(); ++i)
    minval = min(minval, base[i]);


*/

// int best = 987654321;
// int d[2][2] = {
//     {+1, 0},
//     {+1, +1}
// };
// int aux[1000][1000]; // for dp recur
class Solution {
public:

//      JUST EXHAUSTIVE
//       void searchSum(int sum, int row, int col, int cnt, vector<vector<int>>& triangle){
//         if(cnt == MAXCNT-1){
//             if(sum < best)best = sum;
//             return;
//         }
//         for(int i = 0 ; i < 3; ++i){
//             int nr = row + d[i][0]; int nc = col +d[i][1];
//             if(nc < 0 or nc >= triangle[nr].size()) continue;
//             searchSum(sum + triangle[nr][nc], nr, nc, cnt+1, triangle);
//         }  
//     }

//      DP WITH RECURSIVE, SPACE COMPLEXITY = O(N * N)
//     int searchSum(int row, int col, vector<vector<int>> &triangle){
//         int &ret = aux[row][col];
//         if(ret != -1) return ret;
//         if(row+1 == triangle.size()) return ret=triangle[row][col];
//         int minval = 987654321;
//         for(int i = 0; i< 2; ++i){
//             int nr = row + d[i][0]; int nc = col +d[i][1];
//             if(nc < 0 or nc >= triangle[nr].size()) continue;
//             int tmp = searchSum(nr, nc, triangle) + triangle[row][col];
//             minval = min(tmp, minval);
//         }
//         return ret=minval;
//     }
    
//     DP WITH ITERATIVE, SPACE COMPLEXITY = O(N) 
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int bst = 987654321;
        int MAXN = triangle.size(); if(MAXN == 0) return 0; // row를 넘어 설수 없다  
        
        int base[MAXN] = {987654321}; 
        
        for(int i = 0; i < triangle[MAXN-1].size(); ++i)
            base[i] = triangle[MAXN-1][i];
        
        /*
                [
                [2],
                [3,4],
                ]
                
                start
                
                base : 3 4
                
                f(0, 0)  = min(f(1, 0), f(1, 1)) + t(0, 0) [2]  : 5 
                                
                
        */
        for(int r = triangle.size()-2; r > -1; --r){
            for(int c = 0 ; c < triangle[r].size(); ++c){
                base[c] = min(base[c], (c+1 >= triangle[r+1].size())?987654321:base[c+1]) + triangle[r][c]; 
            }
        }
        
        for(int i = 0; i < triangle[0].size(); ++i)
            bst = min(bst, base[i]);
        
        return bst;
    }
};




