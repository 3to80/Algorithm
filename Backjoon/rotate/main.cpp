#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
//                {0, 0}, {0,1}, {0, 2}, {0,3}
//
//
//                {0, 0}, {1,0}, {2, 0}, {3,0}
//


using namespace std;


typedef vector<vector<int> > board;

void print(const board &b){

    for(int r = 0 ;r < b.size(); ++r){
        for(int c = 0; c < b[0].size(); ++c)
            cout << b[r][c] << " ";
        cout <<endl;
    }
    cout <<endl;

}

board rotatePoly(const board & poly){
    // M * N 인 POLY를 오른쪽으로 90도 회전한다.
    /*
     * 0 1 2    3 0
     * 3 4 5    4 1
     *          5 2
     */
    board ret(poly[0].size(), vector<int>(poly.size(), 0));
    int M = poly.size(); int N = poly[0].size();

    for(int r = 0 ; r < M; ++r){
        for(int c = 0; c < N; ++c){
            // poly[r] -> M-1-k 번째 col으로 온다.
            ret[c][M-1-r] = poly[r][c];
        }
    }
    return ret;
}


board symmetry(const board & poly){
    // M * N 인 POLY를 오른쪽으로 90도 회전한다.
    /*
     * 0 1 2    2 1 0
     * 3 4 5    5 4 3
     *
     */
    int M = poly.size(); int N = poly[0].size();
    board ret(M, vector<int>(N, 0));
    // I번 COLUMN은 N-1 -I 번 COLUMN으로 교체 된다.
    for(int c = 0; c < N; ++c){
        for(int r = 0 ; r < M; ++r){
            ret[r][N-1-c] = poly[r][c];
        }
    }
    return ret;
}

bool is_equal(const board &one, const board &two){
    if(one.size() != two.size() or one[0].size() != two[0].size()) return false;

    bool ret = true;

    for(int r = 0 ; r < one.size(); ++r){
        for(int c = 0; c < two.size(); ++c){
            if(one[r][c] != two[r][c]){
                ret = false;
                break;
            }
        }
    }
    return ret;


}

vector<board> makeVarious(const board&current){

    vector<board> ret;
    ret.emplace_back(current);
    board rotate1 = rotatePoly(current);

    // 1) 돌려서 다 같으면 뭘해도 항상 자기 자신만 됨.
    if(is_equal(current, rotate1)) return ret;
    ret.emplace_back(rotate1);

    board sym = symmetry(current);
    bool symcheck = is_equal(sym, current);
    // 2) 180도 돌린거
    board rotate2 = rotatePoly(rotate1);
    if(is_equal(current, rotate2)){
        // 대칭 체크.
        if(symcheck)return ret;
        for(int i = 0; i < 2 ;++i){
            board sym = symmetry(ret[i]);
            ret.emplace_back(sym);
        }
        return ret;
    }
    // 3) 돌린게 다 다른 경우
    ret.emplace_back(rotatePoly(rotate2));
    // 대칭 체크.
    if(symcheck) return ret;
    for(int i = 0; i < 4 ;++i){
        board sym = symmetry(ret[i]);
        ret.emplace_back(sym);
    }
    return ret;
}

int main() {

    // Current : (c, r)이 있을 때
    // Next = rotate(x, y, theta)  하는 거 구현
    int M = 2; int N = 3;
    board current(M, vector<int>(N, 0));
    current[0][0]= 1;
    current[0][1]= 1;
    current[1][1]= 1;
    current[1][2]= 1;

    print(current);
    cout<<" 결과 " << endl;
    vector<board> polyset = makeVarious(current);
    for(auto &i : polyset){
        print(i);

    }
    board current1(M, vector<int>(N, 0));
    current1[0][0]= 1;
    current1[0][1]= 1;
    current1[0][2]= 1;
    current1[1][2]= 1;
    vector<board> polyset2 = makeVarious(current1);
    cout<<" 결과 " << endl;
    for(auto &i : polyset2){
        print(i);
    }


    return 0;
}