#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

using namespace std;


const int N = 5;
const int SIZE = 25;




const int TYPE1_NUM = 2;
int drdc_type1[][2] = {{1, 0}, {0, 1}};

const int TYPE2_NUM = 4;



int check = 0;

bool SHARP = false;
bool DOT = true;


int bijection(int r, int c){
    return 1 << r * N + c;
}


vector<int> moves;
void precalc(){
    for(int r = 0; r < 4; ++r){
        for(int c = 0; c < 4; ++c){
            vector<int> cells;
            for(int dr = 0; dr<2 ; ++dr)
                for(int dc = 0; dc < 2; ++dc)
                    cells.emplace_back(bijection(r+dr, c+dc));
            int square = cells[0] + cells[1]+cells[2]+cells[3];
            for(int i = 0; i < 4; ++i)
                moves.emplace_back(square-cells[i]);
        }
    }

    for(int i = 0 ; i < 5 ; ++i)
        for(int j = 0; j < 4; ++j){
            moves.emplace_back(bijection(i, j) + bijection(i, j+1));
            moves.emplace_back(bijection(j, i) + bijection(j+1, i));
        }
}

bool solve(int board){


    bool ret = false;

    for(int i = 0; i < moves.size(); ++i){
        if( (moves[i] & board) == 0)
            if(!solve(board | moves[i])){
                ret = true;
                break;
            }
    }
    return ret;

}






int main() {

    ifstream inFile;
    inFile.open("../input");

    int T = 0;
    inFile >> T;
    precalc();

    for(int t = 0; t < T; ++t){

        int board = 0;
        for(int i = 0; i < SIZE; ++i){
            char c;inFile>>c;
            // 놓을 수 있으면 그 bit는 1, 못놓으면 0;
            if(c == '.') board += (1 << i);
        }

        cout << solve(board) << endl;


    }






    return 0;
}