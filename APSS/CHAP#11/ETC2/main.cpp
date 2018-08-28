#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


using namespace std;



int T;
int N;
int M;
// int 4byte이면 2^31 -1 >= 987654321  적당히 큰 숫자
const int INF = 987654321;



vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

int distance(const pair<int, int> & c, const pair<int, int> & h){
    return abs(c.first - h.first) + abs(c.second - h.second);
}



// m개 고를 때 최소값
int best = 987654321;

int getMinDistance(vector<int> &chk){
    int ret = 0;


    for(auto house_i : house){
        // house_i와 pair에 있는 것들 사이의 거리
        int tmp = INF;
        for(auto chk_i : chk){
            tmp = min(distance(house_i, chicken[chk_i]), tmp);
        }
        ret += tmp;
    }

    return ret;
}





// M개 까지 골라서,
// pickChickenSet =  { i1, i2, i3... iM} 이렇개 M개의 치킨집을 골랐다고 하자
// 그럼 집이 {h1, h2.... hN} 있다고 할 때
// h1에 대해, pickChickenSet에 속하고 h1과 가장 가까운 거리  +
// h2에 대해, pickChickenSet에 속하고 h2과 가장 가까운 거리  .... hN까지 다 해서
// 나온 거리들 중에서 최소 거리를 구하면 된다.
// 전역변수 best를 둬서  구함


// 답의 상한
// - 완전 탐색이지만 치킨집은 최대 13개이다.
// 그럼 이 경우, 전체 에서 M개 고르는 방법의 수는 13CM  <= 13C6 이 되고 약 1500 정도의 수
// - 하나의 방법당 걸리는 거는 O(NM), 총 n개의 집에서, 각 집과 pick list 치킨집 최소 거리 구하는거 O(m)해서 o(NM)
// - 따라서 전체 다 걸리는데는 O(치킨집수Cm * mn ) <= O(13C6 * 600) 정도, 1억자리 이하이니 런타임 제한에 걸리지 않을거라 예상 한다 .
void pick(int sidx, vector<int> &pick_chk_idices){
    if(pick_chk_idices.size() == M){
        best = min(getMinDistance(pick_chk_idices),best);
        return;
    }

    auto more_pick_num = chicken.size() - sidx;
    // 남은걸 다 뽑아도 M개가 안되는 경우는 제외
    if(more_pick_num + pick_chk_idices.size() < M) return;

    // sidx에 해당하는 치킨집을 고른 경우
    // - chk[sidx]를 pick list에 넣는다.
    pick_chk_idices.emplace_back(sidx);
    // - 넣은거 다음이니 sdix+1 부터 또 계속 진행을 한다.
    pick(sidx+1, pick_chk_idices);
    // - 이제 sidx에 해당하는 치킨집을 고르지 않은 경우를 구하기 위해, 방금 구했던 치킨집은 pick list에서 뺀다.
    pick_chk_idices.pop_back();
    // - sidx에 해당하는 치킨집을 고르지 않고 건너뛴 다음부터 다시 진행한다.
    pick(sidx+1, pick_chk_idices);

}


int main() {
    ifstream inFile;
    inFile.open("../input");

    inFile>>T;
    for(int test_case = 0; test_case < T  ; ++test_case){
// *** 전역변수 초기화  ***
        chicken.clear();
        house.clear();
        best = INF;
// ************

// 치킨집들 좌표, 가정집들 좌표 각각 저장

        inFile>>N;inFile>>M;
        int tmp = 0;
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < N; ++c){
                inFile>>tmp;
                if(tmp == 1)house.emplace_back(make_pair(r,c));
                else if(tmp == 2) chicken.emplace_back(make_pair(r,c));
            }
        }


/*
 * 완전탐색 사용.
 * 전체 치킨 집의 개수가 K라고 하자
 * 그럼 0~ K-1 치킨 집중에서 M개를 고를 수 있는 모든 방법에서 그 합이 가장 작은 것을 구한다. .
 * pick(치킨집중에서 시작 인덱스, 현재까지 고른 치킨집 인덱스 )
 *
 */
        vector<int> pick_chk;
        pick(0, pick_chk);
        cout << best<<endl;




    }





    return 0;
}