#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


const int MAXNODE = 50;
const int MAXDAY = 100;
int NODE_NUM = 0;
int DAY = 0;
vector<int> degreeTable;

vector<int> adjNode(int node, int graph[MAXNODE][MAXNODE]){
    vector<int> ret;
    for(int col = 0; col < NODE_NUM; ++ col)
        if(graph[node][col]) ret.push_back(col);

    return ret;
}


vector<double> solve(vector<double> prevlist, int graph[MAXNODE][MAXNODE]){
    /**
     * @breif: day가 지난 후, 각 노드에 도달할 확률을 list를 가지고 있다.
     * @attention: iterative가 쉽게 보인다. 일단 recur로 시도
     */

    vector<double> curr;
    for(int i =0; i < NODE_NUM; ++i)curr.emplace_back(0);


    for(int node = 0; node < NODE_NUM; ++node){
        // 모든 값들을 다 갱신
        for(auto v : adjNode(node, graph))
            curr[node] += prevlist[v] * ((double)graph[v][node]/degreeTable[v]);
    }

    return curr;

}


void print(vector<double> arr){
    for(auto i : arr){
        cout<<i <<  " ";
    }
    cout<<endl;
}
void print(vector<int> arr){
    for(auto i : arr){
        cout<<i <<  " ";
    }
    cout<<endl;
}
void print(int arr[MAXNODE][MAXNODE], int nodenum){
    for(int r= 0 ; r < nodenum; ++r){
        for(int c= 0 ; c < nodenum; ++c){
            cout<<arr[r][c] << " ";
        }
        cout<<endl;
    }
}

int main() {

    ifstream inFile;
    inFile.open("../input");
    if(inFile.bad()) cout<<"FILE OPEN ERROR";

    int test_Case; inFile>> test_Case;
    for(int cnt = 0; cnt < test_Case; ++cnt){


        inFile>>NODE_NUM;
        inFile >> DAY;
        int start; inFile>>start;

        int graph[MAXNODE][MAXNODE];

        for(int row = 0; row < NODE_NUM; ++row)
            for(int col = 0; col < NODE_NUM; ++col)
                inFile>>graph[row][col];

        int ans_num = 0; inFile>>ans_num;
        vector<int> ans_target;
        int tmp;
        for(int i = 0; i < ans_num; ++i){
            inFile >> tmp;
            ans_target.push_back(tmp);
        }


        degreeTable.clear();
        for(int node = 0 ; node< NODE_NUM; ++node){
            int deg = 0;
            for(int col = 0; col < NODE_NUM; ++col)
                deg += graph[node][col];
            degreeTable.emplace_back(deg);
        }

        //###########################################
        // node_num. day. start, graph, ans_num, ans_target

        vector<double> init;
        for(int i = 0; i < NODE_NUM; ++i)
            init.emplace_back(0);



        for(auto i : adjNode(start, graph))
            init[i] = (1.0/degreeTable[start]);


        vector<double> current;
        vector<double> prev = init;

        for(int d  = 1 ; d < DAY; ++d){
            current = solve(prev, graph);
            prev = current;
        }
//        print(current);
        for(auto i : ans_target){
            cout << current[i] << " ";
        }
        cout<<endl;








    }



    return 0;
}