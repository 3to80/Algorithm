#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>


using namespace std;





int aux[101][101];





int match(const string &pattern, unsigned long p_idx, const string &word, unsigned long w_idx){

    cout<<p_idx << " " << w_idx << endl;
    if(aux[p_idx][w_idx] != -1)
        return aux[p_idx][w_idx];

    if(p_idx < pattern.size() and w_idx < word.size()){
        if(pattern.at(p_idx) == '*')
            return aux[p_idx][w_idx] = (match(pattern, p_idx+1, word, w_idx) or match(pattern, p_idx+1, word, w_idx+1));
        else if(pattern.at(p_idx) == '?' or pattern.at(p_idx) == word.at(w_idx))
            return match(pattern, p_idx+1, word, w_idx+1);
    }


    if(p_idx == pattern.size() and w_idx < word.size())
        return (aux[p_idx][w_idx] = 0);


    if(p_idx < pattern.size() and w_idx == word.size()){
        // 모든 p_idx 의 값들이 *이어야만 한다.
        if(pattern.at(p_idx) == '*')
            return match(pattern, p_idx+1, word, w_idx);
        else
            return aux[p_idx][w_idx] = 0;
    }

    if (p_idx == pattern.size() and w_idx == word.size())
        return aux[p_idx][w_idx] = 1;

}



int match2(const string &pattern, unsigned long p_idx, const string &word, unsigned long w_idx){

    cout<<p_idx << " " << w_idx << endl;
    int &ret = aux[p_idx][w_idx];

    if(ret != -1) return ret;


    while(w_idx < word.size() and p_idx < pattern.size() && pattern.at(p_idx) == '?' or pattern.at(p_idx) == word.at(w_idx)){
        ++w_idx;
        ++p_idx;
    }
    if(pattern.size() == p_idx) return ret = (word.size() == w_idx);
    if(pattern.at(p_idx) == '*'){
        if( match2(pattern, p_idx+1, word, w_idx) || (w_idx < word.size() and match2(pattern, p_idx+1, word, w_idx+1)))
            return ret = 1;
    }
    return ret = 0;

}

int main(){

    ifstream inFile("../input");
    int test_case;
    string pattern;
    int file_num;


    inFile>>test_case;
    for(int i = 0 ; i < test_case; ++i){
        vector<string> ret;
        inFile>>pattern;
        inFile>>file_num;
        memset(aux, -1, sizeof(aux));

        vector<string> fileList;
        for(int n = 0; n < file_num; ++n){
            string tmp ;
            inFile>>tmp;
            fileList.emplace_back(tmp);
        }
        for(auto word : fileList){
            if(match(pattern, 0, word, 0))
                ret.push_back(word);
        }

        for(auto word : ret){
            cout<< word <<endl;
        }

    }


    return 0;
}