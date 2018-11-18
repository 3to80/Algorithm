#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>


using namespace std;


struct Point {
         int x;
         int y;
         Point() : x(0), y(0) {}
         Point(int a, int b) : x(a), y(b) {}
};


struct node{
    double val;
    Point p;
    node(double a, Point other){
        val = a;
        p = Point(other.x, other.y);
    }
};

struct cmp{
    bool operator()(const node &t, const  node &u){
        return t.val < u.val;
    }
};

struct desc{
    bool operator()(const node &t, const  node &u){
        return t.val > u.val;
    }
};


const int MAXINT = 987654321;
const double DIFF = 0.0001;
const double PI = 3.141592;

class Solution {
public:

    // SOL1)
    // 끝을 찾기 위해 시작점을 다룰 때, 시작점을 제일 마지막에 넣는 식으로 구현
    // 현재 점에서 모든 점까지의 각도를 다 계산(cosine 2법칙), 가장 큰것들을 따로 pq로 저장.
    // 위에서 구한 pq가 같은 선위에 있으면 pq로, distance 정렬을 통해 구현
    // 이 때 이미 선택된 점은 선택되었다는거 표시하기 위해 별도의 aux 사용
    // 총평 : 조건 따질 께 몇개 있었음
        // 각도 pq에 아무것도 안들어 갔을 경우
        // Time complexity : O(N * NlgN) , 각 점에 대해(N), 모든 점에 대해 pq를 만드는데  (NlgN) 해서 N**2 lgN
    bool equal(const Point &p1, const Point &p2){
        return p1.x == p2.x and p1.y == p2.y;
    }
    bool equal(double d1, double d2){
        return abs(d1 - d2) < DIFF;
    }
    double distance_square(const Point &p1, const Point &p2){
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }
    double getAngle(const Point &p1, const Point &p2, const Point& target){
        double a2 = distance_square(p1, p2);
        double b2 = distance_square(p2, target);
        double c2 = distance_square(p1, target);
        double tmp = (c2 - (a2 + b2))/(- 2 * sqrt(a2) * sqrt(b2));
        return acos(tmp);
    }
    Point getStart(const vector<Point> &points){
        int minval = MAXINT;
        Point ret;

        for(auto &p: points){
            if(p.x < minval){
                minval = p.x;
                ret = p;
            }
        }
        return ret;
    }

    priority_queue<node, vector<node>, cmp> getSameAnglePoint(
            priority_queue<node, vector<node>, cmp> &aux, const Point &base){
        // aux에서 하나씩 pop해서 보는데 이게 이전의 angle값과 다르다면 종료
        priority_queue<node, vector<node>, cmp> ret;
        node target = aux.top();
        aux.pop();

        ret.push(node(distance_square(base, target.p), target.p));
        double std = target.val;

        while(not aux.empty()){
            node next = aux.top();
            aux.pop();
            if(not equal(std, next.val)) break;
            else ret.push(node(distance_square(base, next.p), next.p));
        }
        return ret;

    }

    vector<Point> outerTrees(vector<Point>& points) {
        vector<Point> ret;
        Point start = getStart(points); // points 중에서 가장 x값이 작은 한점에 대해 시작.
        bool picked[101][101];
        memset(picked, false, sizeof(bool)*10201);

        // begin
        Point prev(start.x, -1);
        Point iter(start.x, start.y);
        //action
        while(true){
            priority_queue<node, vector<node>, cmp> aux;
            for(auto& pi : points){
                if(equal(pi, iter))continue;
                if(equal(pi, prev))continue;
                if(picked[pi.x][pi.y]) continue;
                double angle = getAngle(prev, iter, pi);
                aux.push(node(angle, pi));
            }
            if(aux.empty()){
                ret.emplace_back(start);
                break;
            }
            priority_queue<node, vector<node>, cmp> tmp_ret = getSameAnglePoint(aux, iter);


            if(tmp_ret.size() == 1){
                prev = iter;
                iter = tmp_ret.top().p;
                if(not picked[iter.x][iter.y]){
                    picked[iter.x][iter.y]= true;
                    ret.emplace_back(iter);
                }
            }
            else{
                prev = iter;
                iter = tmp_ret.top().p; tmp_ret.pop();

                if(not picked[iter.x][iter.y]){
                    picked[iter.x][iter.y]= true;
                    ret.emplace_back(iter);
                }
                while(not tmp_ret.empty()){
                    auto tmp = tmp_ret.top();
                    tmp_ret.pop();
                    if(not picked[tmp.p.x][tmp.p.y]){
                        picked[tmp.p.x][tmp.p.y]= true;
                        ret.emplace_back(tmp.p);
                    }

                }
            }

            if(equal(iter, start))break;

        }
        return ret;
    }

    // Convex hull wrapping - Jarvis's Algorithm
    // 1) init p as leftmost point
    /* 2) Do folowing while we on't come back to the first
     *  - the next point q is the point s.t the triplelet(p, q, r) is conterclockwise for any other point r
     *  - next[p] = q
     *  - p = q
     */

};

void print(vector<Point> p){
    for(auto i : p){
        cout << " ( " << i.x << " " << i.y << " ) " <<endl;
    }
}

vector<Point> makeInput(string str){

    vector<Point> ret;

    std::string delimiter = "],";
    size_t pos = 0;
    std::string token;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
//        cout << token << endl;

        int tmp = token.find(',');
        string x = token.substr(1, tmp-1);
        string y = token.substr(tmp+1, token.size());
//        cout << x << y << endl;
        ret.emplace_back(Point(stoi(x), stoi(y)));
        str.erase(0, pos + delimiter.length());
    }
    return ret;


}


int main(){
// [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
//    string str = "[1,2],[2,2],[4,2],";
    string str = "[8,5],[7,13],[4,13],";
    //    print(makeInput(str));


    vector<Point> input = makeInput(str);
//    input.emplace_back(Point(1,2));
//    input.emplace_back(Point(2,2));
//    input.emplace_back(Point(3,2));
//    input.emplace_back(Point(4,2));
//    input.emplace_back(Point(5,2));

//    [[1,2],[2,2],[4,2]]

    Solution s;
    vector<Point> tmp = s.outerTrees(input);
    print(tmp);
    return 0;
}
