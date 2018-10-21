#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;


int MOVE[4][2] = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
};
int best = -1;

typedef vector<vector <int> > board;

int N;

int getMax(const board& current){
    int maxvalue = -1;
    for(int r= 0 ; r < N; ++r){
        for(int c= 0 ; c < N; ++c){
            maxvalue = max(maxvalue, current[r][c]);
        }
    }
    return maxvalue;

}
void print(const pair<int, int> &point){
    cout << " ( " << point.first << " , " << point.second << ")"<<endl;
}

void print(board tmp){
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            cout<< tmp[r][c] << " ";
        }
        cout<<endl;

    }
}

bool is_valid(const pair<int, int> &point){
    return (point.first >=0 and point.first < N)
           and (point.second >=0 and point.second < N);

}
pair<int, int> nextPoint(const pair<int, int> &current, int dir){
    return make_pair(current.first + MOVE[dir][0], current.second + MOVE[dir][1]);
}


int get(const board &ret, const pair<int, int> &current){
    return ret[current.first][current.second];
}



void move(pair<int, int> current, pair<int, int> next, board &ret, int dir, board &aux){
    //base case, 더이상 이동할 수 없으면 move를 그만 둔다.
    if(not is_valid(next)) return;
    // 다음 값이 0인 경우
    if(get(ret, next) == get(ret, current) and aux[next.first][next.second] == 0){
        // next가 이전에 합쳐진 부분이면 합쳐선 안된다. 그 값 표현을 위해 aux를 사용
        aux[next.first][next.second] = 1;

        // 다음 값은 현재값과 더해지고 현재 위치는 0을 넣는다.
        ret[next.first][next.second] *= 2;
        ret[current.first][current.second] = 0;
        return;
    }
    if(get(ret, next) == 0){
        // 다음 값과 현재 값을 swap 하고 현재 위치는 0을 넣는다.
        ret[next.first][next.second] = get(ret, current);
        ret[current.first][current.second] = 0;
        move(next, nextPoint(next, dir), ret, dir, aux);
    }

}

board make(const board &current, int dir){
    // 특정 방향으로 이동 되었을 때 모습
    board ret(current);
    // 한 번 병합된 값을 표시한다.
    board aux(N, vector<int>(N, 0));

    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            // 방향에 따른 좌표 조정

            int current_r = r;
            int current_c = c;
            if(dir == 1) current_c = N-1 - c; // 오른쪽으로 이동하면 c가 큰거부터 시작되어 줄이는 방향으로 가야 된다.
            else if(dir == 3) current_r = N-1 - r; // 아래쪽으로 이동하면 r 이 큰거부터 시작되어 줄이는 방향으로 가야 된다.

            pair<int, int> current = make_pair(current_r, current_c);
            // 1. 움직이지 않는 경우
            // 1) 현재 값이 0 인 경우
            if(get(ret, current) == 0) continue;
            pair<int, int> next = nextPoint(current, dir);
            // 2) next가 valid 하지 않을 때
            if(not is_valid(next)) continue;
            // 3) next가 valid 해도 map(next) != map(current) 일 때
            if(get(ret, next) != 0 and get(ret, next) != get(ret, current)) continue;
            //2. (r, c)의 값을 움직여야할 때
            move(current, next, ret, dir, aux);
        }
    }
    return ret;
}

bool equal(const board &one, const board &two){
    for(int r = 0; r < N; ++r)
        for(int c = 0; c < N; ++c)
            if(one[r][c] != two[r][c]) return false;
    return true;

}

void func(const board &current, int level){
//    cout << "level : " << level << endl;
//    print(current);
//    cout<<endl;


    if(level == 5){
        best = max(best, getMax(current));
        return;
    };
    for(int dir = 0; dir < 4; ++dir){
        board next = make(current, dir);
        if(not equal(current, next))    func(next, level+1);

    }

}
int T;

int main() {
    freopen("../input", "r", stdin);
    cin>>T;
    for(int t = 0 ;t < T; ++t){
        cin >> N;
        board current(N, vector<int>(N, 0));
        for(int r = 0; r < N; ++r)for(int c = 0; c < N; ++c) cin >> current[r][c];
        best = getMax(current);
        func(current, 0);
        cout<< best<<endl;
    }
    return 0;


}

