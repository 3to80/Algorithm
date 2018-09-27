#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <queue>
#include <unordered_map>
using namespace std;



string f(deque<int> &preorder, unordered_map<int, int> &aux, const vector<int> &inorder, int s, int e){
    if(preorder.empty()) return "";
    if(e-s == 1){
        preorder.pop_front();
        return to_string(inorder[s]) + " ";
    }
    if(e-s < 1) return "";
    int cur_root = preorder.front();
    preorder.pop_front();
    int idx = aux.at(cur_root);
    string left = f(preorder, aux, inorder, s, idx);
    string right = f(preorder, aux, inorder, idx+1, e);

    return left + right + to_string(cur_root) + " ";
}

int main() {
    string preorder = "27 16 9 12 54 36 72";
    string inorder = "9 12 16 27 36 54 72";

    // 이때 post order를 구해라

    stringstream prestream(preorder);
    istream_iterator<string> it(prestream);
    istream_iterator<string> end;

    stringstream instream(inorder);
    istream_iterator<string> it1(instream);
    istream_iterator<string> end1;

    deque<int> prevec;





//    int tmp;
//    while(prestream>> tmp){
//        prevec.push_back(tmp);
//    }
    for(auto i = it; i != end; ++i)
        prevec.push_back(atoi(i->c_str()));

    vector<int> invec;
    unordered_map<int, int> auxmap;

    int idx = 0;
    for(auto i = it1; i != end1; ++i){
        int val = atoi(i->c_str());
        invec.emplace_back(atoi(i->c_str()));
        auxmap.insert(make_pair(val, idx));
        idx++;
    }

    cout << f(prevec, auxmap, invec, 0, inorder.size());
//

//    string ans = "";
//    f(prevec, auxmap, invec, 0, inorder.size(), ans);

//    cout<<ans << endl;



    return 0;
}