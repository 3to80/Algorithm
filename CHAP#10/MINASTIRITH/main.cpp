#include <iostream>
#include <fstream>
#include <cstring>
#include <deque>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<double, double> d_pair;


int T;
int N;
const double PI = 3.141592;
const double DIFF = 0.0000001;
const double R = 8;
const double MAX_RI = 16.001;

const int MAX_N = 100;

const double LIMIT = 2*PI * R;
double arrY[MAX_N];
double arrX[MAX_N];
double arrR[MAX_N];


vector<d_pair> ranges;


void convertToRange(){
    for(int i = 0 ; i < N; ++i){
        double loc = fmod(2*PI + atan2(arrY[i], arrX[i]), 2*PI);
        double range = 2.0 * asin(arrR[i]/2.0/8.0);
        ranges.emplace_back(make_pair(loc-range, loc+range));
    }
    sort(ranges.begin(), ranges.end());
}



const int INF = 987654321;

int solveLinear(double begin, double end){
    int used = 0, idx = 0;

    while(begin < end){

        double maxCover = -1;
        while(idx < N and ranges[idx].first <= begin){

            maxCover = max(maxCover, ranges[idx].second);
            ++idx;
        }
        if(maxCover<= begin) return INF;
        begin = maxCover;
        ++used;
    }
    return used;
}
int solveCircular(){

    int ret = INF;
    for(int i = 0; i< N; ++i){

        if(ranges[i].first <= 0 or ranges[i].second >= 2*PI){
            double begin = fmod(ranges[i].second, 2*PI);
            double end= fmod(ranges[i].first +2*PI, 2*PI);
            ret = min(ret, 1+solveLinear(begin, end));

        }

    }
    return ret;
}







int main() {

    ifstream inFile;
    inFile.open("../input");
    inFile >> T;

    for(int test_case = 0; test_case < T; ++test_case){
        inFile >> N;
        memset(arrY, 0, sizeof(double) * MAX_N);
        memset(arrX, 0, sizeof(double) * MAX_N);
        memset(arrR, 0, sizeof(double) * MAX_N);
        ranges.clear();


        priority_queue< d_pair> pick;
        priority_queue< d_pair> input;

        for(int i = 0 ; i < N; ++i){
            double yPos, xPos, radious;
            inFile>>yPos;inFile>>xPos;inFile>>radious;
            arrY[i] = yPos;arrX[i] = xPos;arrR[i] = radious;
        }

        convertToRange();
        int ans = solveCircular();
        if(ans != INF)cout << solveCircular() << endl;
        else cout<<"IMPOSSIBLE" << endl;



    }






    return 0;
}

/**
 * 1. arrY, arrX, arrR 에 대해  input을 넣는 작업.
 *  - 원의 중점과 반지름에 대해 접하는 접점에 대하여 두 점 혹은 한점의 값을 넣는다. 중심 각도에 대해 start, end 형태 시계 방향.
 *  - 중심 원과의 접점이 하나 인 경우, 전체를 다 포함한다.
 *  - end가 2 pi 가 넘는 경우에도 생각을 한다.
**/

