#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;




int C;
int N;


struct Node{
    int x;
    int y;
    int r;
    vector<Node *> children;
    Node(int x, int y, int r){
        this->x = x; this->y = y; this->r = r;
        this->children = vector<Node*>();
    }
};

struct cmp{
    bool operator()(const Node *a, const Node *b){
        return a->r < b->r;
    }
};

int sqr(int x){
    return x * x;
}
bool isInclude(Node *root, Node *target){
    // 두 원의 중심 거리가 반지름의 합보다 더 멀면 두 원은 떨어져있다 즉 포함되지 않는다는 거.
    int radius_square= sqr((root->r + target->r));
    int distance_square= sqr((root->x - target->x)) + sqr((root->y - target->y));
    return distance_square <= radius_square;

}
void locate(Node *root, Node *target){
    // root의 children에 target에 들어가면 그 children에 대해 locate 다시
    // 만약 모든 children에 들어가지 않는다면 root의 children에 넣는다.
    Node *pick = NULL;
    for(auto child: root->children){
        if(isInclude(child, target)){
            pick = child;
            break;
        }
    }
    if(not pick) root->children.emplace_back(target);
    else locate(pick, target);
}




int longest = 0;

// root를 subtree로 하는 서브트리의 높이를 반환
int height(Node *root){
    vector<int> heights;
    for(int i = 0; i < root->children.size();++i)
        heights.emplace_back(height(root->children[i]));
    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    if(heights.size() >= 2)
        longest = max(longest, 2+ heights[heights.size()-2]+ heights[heights.size() -1]);
    return heights.back() + 1;
}

int getAnswer(Node *root){
    longest =0;
    int h = height(root);
    return max(longest, h);
}

void print(Node *root, int level){
    cout << root->x << " " << root->y << " " << root->r << " " << level << endl;
    for(auto i : root->children){
        print(i, level+1);
    }
}

int main() {

    ifstream inFile("../input");

    inFile >> C;


    for(int test_case = 0; test_case < C ; ++test_case){
        priority_queue<Node*, deque<Node*>, cmp> pq;
        longest = 0;
        inFile >> N;

        int x; int y; int r;
        for(int i = 0; i < N; ++i){
            inFile >> x; inFile>> y; inFile>> r;
            Node *target= new Node(x, y, r);
            pq.push(target);
        }

        Node *root= pq.top();
        pq.pop();

        while(!pq.empty()){
            Node *tmp = pq.top();
            pq.pop();
            locate(root, tmp);
        }
        int ans = getAnswer(root);
        cout<<ans<<endl;
    }



    return 0;
}