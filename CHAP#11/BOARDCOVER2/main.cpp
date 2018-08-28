#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <bitset>
#include <string>


using namespace std;



int T;
int H;
const int MAX_H = 11;
int W;
const int MAX_W = 11;
int R;
const int MAX_R = 11;
int C;
const int MAX_C = 11;


vector<string> board;
vector<string> blockSrc;
vector< vector<string> > blockList;





bool is_Same(const vector<string> & a, const vector<string> & b){

    if(a.size() != b.size()) return false;

    for(int r = 0; r < a.size(); ++r)
        if(a[r] != b[r]) return false;



    return true;
}
vector<string> rotate90(vector<string> &src){
    vector<string> ret;

    string tmp;
    //string에 char 더하는거
    for(int c = 0; c < src[0].size(); ++c){
        string tmp;
        for(int r = 0; r < src.size(); ++r)
            tmp+=(src[src.size()-1 -r ][c]);
        ret.emplace_back(tmp);
    }
    return ret;

}
void generateBlockList(){

    blockList.emplace_back(blockSrc);


    vector<string> rotateBlock = rotate90(blockSrc);
    if(is_Same(rotateBlock, blockSrc)) return;
    blockList.emplace_back(rotateBlock);


    rotateBlock = rotate90(rotateBlock);
    if(is_Same(rotateBlock, blockSrc)) return;
    blockList.emplace_back(rotateBlock);

    rotateBlock = rotate90(rotateBlock);
    blockList.emplace_back(rotateBlock);


}



bool isValidBoard(int row, int col){
    return ((row+R-1 < H) and (col + C -1 ) < W) or ((row+R-1 < W) and (col + C -1 ) < H);
}

bool isSetBlock(int row, int col, vector<string> &block){
    // block size를 감당할 수있는지 확인
    auto blockRow = block.size(); auto blockCol = block[0].size();
    if(row + blockRow-1 >= H or col + blockCol-1 >= W) return false;

    for(int r = 0; r < blockRow; ++r)
        for(int c = 0; c < blockCol; ++c)
            if(board[row+r][col+c] == '#' and block[r][c] == '#') return false;


    return true;

}




pair<int, int> findNext(int row, int col){
    for(int r = row; r < H; ++r){
        for(int c = col; c < W; ++c){
            if(r == row and c == col) continue;
            if(board[r][c] == '.') return make_pair(r, c);
        }

    }


    return make_pair(H, W);


};

int covered[11][11];


void setBlock(int row, int col, const vector<string> &block){
    auto blockRow = block.size(); auto blockCol = block[0].size();
    for(int r = 0; r < blockRow; ++r)
        for(int c = 0; c < blockCol; ++c)
            if(block[r][c] == '#'){
                covered[row+r][col+c] = 1;
                board[row+r][col+c] = '#';


            }

}



void removeBlock(int row, int col, const vector<string> &block){
    auto blockRow = block.size(); auto blockCol = block[0].size();
    for(int r = 0; r < blockRow; ++r)
        for(int c = 0; c < blockCol; ++c)
            if(block[r][c] == '#'){
                covered[row+r][col+c] = 0;
                board[row+r][col+c] = '.';


            }

}


int cntChar(const vector<string> &src, char target){
    int ret = 0;
    for(int r = 0; r < src.size(); ++r)
        for(int c = 0; c < src[0].size(); ++c)
            if(src[r][c] == target) ret += 1;

    return ret;


}


int blockSharpNum;
int best;
void solve(int placed){
    // 남은 개수가 block의 개수 보다 작으면 중지
    // 칠할 수 있는 모든 점에 대해 다 색칠할 수 없으면 중지

    int t_r= -1;
    int t_c = -1;
    for(int r = 0; r < H ;++r){
        for(int c = 0; c < W; ++c){
            if(covered[r][c] == 0){
                t_r = r;
                t_c = c;
                break;
            }
        }
        if(t_r != -1) break;
    }

    if(t_r == -1){
        best = max(best, placed);
        return;
    }


    for(auto &block : blockList){
        if(isSetBlock(t_r, t_c, block)){
            setBlock(t_r, t_c, block);

            solve(placed+1);

            removeBlock(t_r, t_c, block);
        }
    }

    covered[t_r][t_c] = 1;
    solve(placed);
    covered[t_r][t_c] = 0;




}




int main() {
    ifstream inFile;
    inFile.open("../input");
    inFile >> T;

    for (int test_case = 0; test_case < T; ++test_case) {
        board.clear();
        blockSrc.clear();
        blockList.clear();

        memset(covered, 0, sizeof(int) * 11 * 11);
        inFile >> H >> W >> R >> C;
        string tmp;
        for(int r = 0; r < H; ++r){
            inFile >> tmp;
            board.emplace_back(tmp);
        }

        for(int r = 0; r < R; ++r){
            inFile >> tmp;
            blockSrc.emplace_back(tmp);
        }


        generateBlockList();


        blockSharpNum= cntChar(blockSrc, '#');
        // 최대 dot_Board/dot_Block 번, 1번에 blockList.size() 만큼  선택할 수 있다.
        best = 0;

        for(int r = 0 ; r < H; ++r){
            for(int c = 0 ; c < W; ++c){

                covered[r][c] = (board[r][c] == '#' ? 1 : 0);

            }
        }

        solve(0);
        cout<<best<<endl;

    }




    return 0;
}
