#include <iostream>
#include <vector>

int N;
int M;
int start_r;
int start_c;
int K;

using namespace std;

typedef vector<vector<int>> board;



board map;
vector<int> inst;

board cube(4, vector<int>(3, 0));


void print(board tmp){
    for(auto i: tmp){
        for(auto j: i){
            cout<< j << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void moveEast(){
    //c 는 c-1이 들어온다.

    int tmp = cube[1][2];

    cube[1][2] = cube[1][1];
    cube[1][1] = cube[1][0];
    cube[1][0] = cube[3][1];
    cube[3][1] = tmp;

}
void moveWest(){
    int tmp = cube[3][1];
    cube[3][1] = cube[1][0];
    cube[1][0] = cube[1][1];
    cube[1][1] = cube[1][2];
    cube[1][2] = tmp;
}

void moveNorth(){
    int tmp = cube[0][1];
    cube[0][1] = cube[1][1];
    cube[1][1] = cube[2][1];
    cube[2][1] = cube[3][1];
    cube[3][1] = tmp;
}

void moveSouth(){
    int tmp = cube[3][1];
    cube[3][1] = cube[2][1];
    cube[2][1] = cube[1][1];
    cube[1][1] = cube[0][1];
    cube[0][1] = tmp;

}
void moveCube(int dir){
    switch(dir){
        case 1:
            moveEast();
            break;
        case 2 :
            moveWest();
            break;
        case 3:
            moveNorth();

            break;
        case 4:

            moveSouth();
            break;
        default:
            cout<<"asdf" << dir<<endl;
            cout<<"error";
            break;

    }

}

int MOVE[4][2]= {
        {0, 1},
        {0, -1},
        {+1, 0},
        {-1, 0}
};
void move_pos(pair<int, int> &point, int dir){
point.first += MOVE[dir-1][0];
    point.second += MOVE[dir-1][1];
}
void rollback(pair<int, int> &point, int dir){
    point.first -= MOVE[dir-1][0];
    point.second -= MOVE[dir-1][1];
}
bool is_in(const pair<int, int> &pos){
    return (pos.first >= 0 and pos.first < N) and (pos.second >= 0 and pos.second < M);
}

void print(pair<int, int> k){
    cout<<k.first << " , " << k.second << endl;
}
int main() {
    freopen("../input", "r", stdin);
//
//    cube[0][1] = 2;
//    cube[1][0] = 4;
//    cube[1][1] = 1;
//    cube[1][2] = 3;
//    cube[2][1] = 5;
//    cube[3][1] = 6;

//    print(cube);
//    moveWest();
//    moveSouth();
//      moveEast();
//    print(cube);
    cin>> N;cin >> M;
    cin >> start_r;cin >> start_c;cin >> K;
    map = board(N, vector<int>(M, 0));
    inst = vector<int>(K, 0);
    for(int r = 0; r < N; ++r)for(int c = 0; c < M; ++c)cin >> map[N-1-r][c];
    for(int k = 0; k < K; ++k) cin >> inst[k];


    pair<int, int> point(N-start_r-1, start_c);


    for(int k = 0; k < K; ++k){
        move_pos(point, inst[k]);

        // move point
        // move cube
        if(not is_in(point)){
            rollback(point, inst[k]);
            continue;
        }
        moveCube(inst[k]);

        if(map[point.first][point.second] == 0){
            map[point.first][point.second] = cube[3][1];
        }
        else{
            cube[3][1] = map[point.first][point.second];
            map[point.first][point.second] = 0;
        }
        cout << cube[1][1]<<endl;


    }


    return 0;
}