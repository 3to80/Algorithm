
/*
삽질
1) vector<vector<bool>> visit = vector<vector<bool>>(ROWNUM, vector<bool>( COLNUM, false)); 에서 숫자랑 초기값 위치 반대로 써서 mem err 발생
 - 컴파일러에서 안잡으니 항상 주의, 숫자 다음이 초기값! 
2) global 변수 초기값 잡을 때 주의
int ROWNUM;
int A = ROWNUM -1 
이렇게 잡고 rownum을 밑에서 값 넣어줄 때 당연히 A 값이 안바뀜. 메모리 할당 될 때 글로벌변수가 더 먼저 할당되고 코드 영역 할당되기 때문
3) queue에서, push 는 push_back, pop은 pop_front 이다. 개념적으로 FIFO 구현을 위해 이러지만, 이 FIFO가 아니게 해도 상관없음. 
4) queue에 다음에 시도해볼 node들 넣을 때, visit 을 update 해줘야 한다. 
그래야 같은 level인 경우, 동일한 값의 여러 노드가 나오는 경우를 방지할 수 있다. 
새로운 거 만들 때 visit을 update!

*/

int ROWNUM;
int COLNUM;


int d[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

        
class Solution {
public:

    void check_iter(int tr, int tc, const vector<vector<char>>& board, vector<vector<bool>>& marking, vector<vector<bool>> &visit){
        deque<pair<int, int >> deq;
        deq.push_back(make_pair(tr, tc));
        while(not deq.empty()){
            pair<int, int> target = deq.front();
            deq.pop_front();
            visit[target.first][target.second] = true;
            marking[target.first][target.second] = true;

            for(int k = 0; k < 4 ; ++k){
                int nextr = target.first + d[k][0]; if(nextr >= ROWNUM or nextr < 0) continue;
                int nextc = target.second+ d[k][1]; if(nextc >= COLNUM or nextc < 0) continue;
                if(
                        (nextr >= 0 and nextr < ROWNUM and nextc >= 0 and nextc < COLNUM) and
                        (board[nextr][nextc] == 'O') and
                        (not visit[nextr][nextc])
                        ){
                    deq.push_back(make_pair(nextr, nextc));
                    visit[nextr][nextc] = true;
                }
            }
        }
    }
    
    void check(const vector<vector<char>>& board, vector<vector<bool>>& marking){
        vector<vector<bool>> visit = vector<vector<bool>>(ROWNUM, vector<bool>( COLNUM, false));
        for(int r = 0; r < ROWNUM; ++r){
            for(int c = 0; c < COLNUM ; ++c){
                if((r > 0 and r < ROWNUM-1) and (c> 0 and c < COLNUM-1))continue;
                if(board[r][c] == 'O' and visit[r][c] == false)
                    check_iter(r, c, board, marking, visit);
            }
        }
    }

    void paint(vector<vector<char>>& board, vector<vector<bool>>& marking){
        for(int r = 0; r < ROWNUM; ++r)for(int c = 0; c < COLNUM; ++c)
                if(board[r][c] == 'O' and not marking[r][c])
                    board[r][c] = 'X';
    }
    
    void solve(vector<vector<char>>& board) {
        ROWNUM = board.size();
        if(ROWNUM == 0) return;
        COLNUM = board[0].size();
        vector<vector<bool>> marking = vector<vector<bool>>(ROWNUM, vector<bool>(COLNUM, false));
        check(board, marking);
        paint(board, marking);

        
    }
};
