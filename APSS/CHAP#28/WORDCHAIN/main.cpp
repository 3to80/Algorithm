#include <iostream>
#include <stdio.h>
//#include <vector>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
/*
 * 스케치
 *
 * 각 단어들을 vertex, 단어들 간의 연결을 edge
 *
 * 각 단어들에 대해 오일러 트레일이 아닌 vertex를 모두 잇는 것을 만드는 거. 근데 결과적으로 모든 vertex를 지나게 edge를 선택한다.
 * 즉 vertex개수 만큼 선택하는거네.
 *
 *  - 만들 수 있으면 trail 출력
 *  - 만들 수 없으면 impossible
 *
 *
 * => 이렇게 하면 |V|! 이 나오게 된다.
 *
 * 오일러 서킷을 어떻게 적용시킬 수 있을까?
 * - 오일러 서킷 : 모든 edge를 1번만 다 지나고 시작과 끝 점이 같은 path를 말한다.
 *
 * - 문제 조건에 따라, 각 단어를 모두 선택해야 한다 <=> 각 단어를 edge로 변환하면 어떨까
 *
 * - vertex: 각 단어에 대해 시작 글자, 끝 글자들 -> 알파벳 소문자니 26개 노드에서 해결 할 수 있다.
 * - edge : 26 * 26
 *
 *  => dog란 단어에 대해, 'd' 노드에서 'g 노드로 가는 edge가 dog라고 표현할 수 있다.
 *      - 그럼 degree가 여러개가 될 수 도 있는 것
 *          -> adjTable에 개수가 아닌 각각을 넣어야 될 것.
 *          -> adjTable[u][v] : {dog, doooog, dpaog} 뭐 이런식으로
 *
 *
 * -> edge를 최대한 포함하는 회로를 만든다.
 *  - outdegree수가 indegree보다 더 크면 시작지점
 *  - outdegree수가 ndegree보다 더 작으면 끝지점
    시작지점이 2개 이상 있거나 끝지점이 2개 이상 있으면 안될 거 같다.

    prefix 부분
    postfix 부분
    시작지점이 1개고 끝지점이 1개인 경우.
        - 시작지점과 끝지점을 하나씩 빼고 경로의 prefix, postfix 에각각 넣는다
        - 전체 outdegree, indegree가 같아질때까지 반복한다.

    prefix.back()을 시작으로 euler circuit을 만든다.

    list<here> getEulerCircuit(here);

 *
 */


vector<vector<int>> adj;
vector<string> graph[26][26];
vector<int> outdegree;
vector<int> indegree;

int C;
int N;
string buf;
//void getEuler(int here, list<string> &ret, const string& hereString){
//    // here에서 갈 수 있는 edge가 있는지 확인한다.
//    // 갈 수 있으면 계속 간다.
//    // 결국 자기 자신까지 오게 될 것
//    for(int there = 0; there < adjTable.size(); ++there){
//        while(adjTable[here][there].size() >0){
//
//            string word = adjTable[here][there].back();
//            adjTable[here][there].pop_back();
//            getEuler(there, ret, word);
//        }
//    }
//    ret.emplace_back(hereString);
//}
//list<string> getEuler(int here){
//    // here에서 만들 수 있는 euler circuit을 반환한다.
//
//    list<string> ret;
//    // here에서 나가는 것들 중에서 하나 선택
//    string hereString;
//
//    for(int there = 0; there < adj.size(); ++there){
//        auto tmp = adj[here][there];
//        if(adjTable[here][there].size()>0){
//            hereString = adjTable[here][there].back();
//        }
//    }
//    getEuler(here, ret, hereString);
//
//    return ret;
//}


void getEulerCircuit(int here, vector<int> &circuit){
    for(int there = 0; there< adj.size(); ++there){
        while(adj[here][there] > 0){
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.emplace_back(here);
}

vector<int> getEulerTrailOrCircuit(){
    vector<int> circuit;
    for(int i = 0; i < 26; ++i){
        if(outdegree[i] == indegree[i]+1){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    for(int i = 0; i < 26; ++i){
        if(outdegree[i]){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;

}
bool checkEuler(){
    int plus1 = 0, minus1 = 0;
    for(int i =0; i<26; ++i){
        int delta = outdegree[i] - indegree[i];
        if(delta < -1 || 1 <  delta) return false;
        if(delta == 1) plus1++;
        if(delta== 1) minus1++;
    }
    return(plus1==1 and minus1 == 1) or (plus1 ==0 and minus1 == 0);
}
string getResult(){
    string ret;
    // Preprocessing
    /*
     * 시작 부분 끝부분을 찾아본다.
     */
    if(not checkEuler()) return "IMPOSSIBLE";
    // 1) 둘다 0 0 이면 바로 오일러 서킷 만들기 시작
    // 2) 둘 다 1 1 이면 euler TRail 만들기 시작
    vector<int> euler = getEulerTrailOrCircuit();
    if(euler.size() != N+1) return "IMPOSSIBLE";

    reverse(euler.begin(), euler.end());
    for(int i = 1; i < euler.size(); ++i){
        int u = euler[i-1]; int v = euler[i];
        if(ret.size()) ret += " ";
        ret += graph[u][v].back();
        graph[u][v].pop_back();
        auto target = graph[euler[i-1]][euler[i]];

    }

    return ret;
    // 나머지는 모두 안되는 경우

}


int main() {
    freopen("../input", "r" , stdin);
    cin >> C;
    for(int c = 0; c < C; ++c){
        cin>> N;
        for(int r = 0; r < 26; ++r)for(int col = 0; col <26; ++col)graph[r][col].clear();
        adj.clear();
        adj = vector<vector<int> >(26, vector<int>(26, 0));
        outdegree.clear();
        outdegree = vector<int>(26, 0);
        indegree.clear();
        indegree = vector<int>(26, 0);

        for(int n = 0; n < N; ++n){
           cin >> buf;
           // buf[0] 노드 에서 시작, buf[-1] 노드로 들어간다.
           int u = buf[0]-'a';
           int v = buf.back()-'a';
           graph[u][v].emplace_back(buf);
           adj[u][v]++;
           outdegree[u]++;
           indegree[v]++;

        }


        string ret = getResult();
        cout<<ret<<endl;




    }










    return 0;
}