#include <iostream>
#include <stdio.h>
#include <cstring>
#include <list>

using namespace std;

bool board[101][101];
int N;
int x, y, d, g;

typedef pair<int, int> point;

int MOVE[4][2] = {
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 0}
};

// point p를 점 dir 방향으로 하나 증가시킨다.
point move(const point &p, int dir, int pad){
    return make_pair(p.first + MOVE[dir][0]* pad, p.second+MOVE[dir][1]*pad);
}

point rotateLeft(const point &p){
    return make_pair(p.second, -1 * p.first);
}


list<point> draw(const list<point> &dragoncurve, int g){
    // 더이상 갈 세대가 없으면 return
    if(g == 0) return dragoncurve;

    // 기준점을 선택, 이건 list에서 가장 최근에 들어온 점이 된다.
    point origin = dragoncurve.back();
    // origin을 기준으로 dragoncurve의 모든 점들은 생성이 된다.
    // 시작점은 들어갈 필요가 없다.
    auto i = dragoncurve.rbegin();
    i++;
    // 확정되는 점들은 addone에 들어간다.
    list<point> addone;
    for(i; i != dragoncurve.rend(); ++i){
        // i와 origin의 상대 좌표를 구한다.
        //
        point target = *i;
        target.first -= origin.first;
        target.second-= origin.second;
        point toadd = rotateLeft(target);
        toadd.first += origin.first;
        toadd.second += origin.second;
        addone.push_back(toadd);

    }
    list<point> ret(dragoncurve);
//    ret.insert(addone.begin(), addone.end());
// 이거 이방법 말고 O(1)에 삽입되게 하는게 있을 건데..

//    ret.insert(addone.begin(), addone.end());
//    for(auto i : addone)
//        ret.push_back(i);
//    ret.insert(ret.end(), addone.begin(), addone.end());
    ret.splice(ret.end(), addone);
    return draw(ret, g-1);


}
list<point> makeDragonCurve(const point &origin, int d, int g){
    // 0 세대 드레곤 커브는
    // origin과 origin 을 d방향으로 1만큼 간 새로운 점 들의 집합이다.

    // 0세대 드레곤 커브 생성
    list<point> ret;
    ret.push_back(origin);
    ret.push_back(move(origin, d, 1));

    // g세대 이후 드레곤 커브를 생성
    ret = draw(ret, g);

    // draw(const list<point> &dragoncurve, int g)
    // dragoncurve를 g 세대 까지 확장시켰을 때 점들을 return 한다.

    return ret;

}
void updateDragonCurve(int x, int y, int d, int g){
    // x, y 를 시작점 으로하고  좌표는 (y, c)로 가야 겠다.
    // d를 시작 방향, g는 세대
    // 로 하는 dragon curve 를 만든다.
    // 만든 점들을 board에 업데이트 한다.
    // list로 구현
    list<point> dragon_curve_set = makeDragonCurve(make_pair(y, x), d, g);
//    for(auto i : dragon_curve_set){
//        cout<< i.second << " " << i.first<<endl;
//    }



    for(auto i : dragon_curve_set)
        board[i.first][i.second] = true;

}



// board에서 (r, c)에 대해 (r+1, c) (r, c+1) (r+1, c+1) 모두 true 인 것의 개수를 구한다.
int getSquareNum(){
    int ret = 0;
    for(int r = 0; r+1 < 101; ++r){
        for(int c = 0; c+1 < 101; ++c){
            if(board[r][c] and board[r+1][c]
            and board[r+1][c+1] and board[r][c+1])
                ++ret;
        }

    }
    return ret;
}


int main() {
    freopen("../input", "r" , stdin);

    cin >> N;


    memset(board, false, sizeof(bool) * 101 * 101);

    for(int n = 0; n < N ; ++n){
        cin>>x; cin>>y; cin>> d; cin >> g;
        // makeDragonCurve(int x, int y, int d, int g)
        // update Board
        updateDragonCurve(x, y, d, g);
    }

    // board에서 4개의 점이 다 true인 것의 개수를 구한다.

    int ans = getSquareNum();
    cout<<ans;

    return 0;
}