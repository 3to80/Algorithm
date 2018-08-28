#include <iostream>
#include <vector>
#include <set>

using namespace std;


int order(const vector<int>& russian, const vector<int>& korean){


    int n = russian.size(), wins = 0;

    multiset<int> ratings(korean.begin(), korean.end());
    for(int runs = 0; runs < n; ++runs){

        if( *ratings.rbegin() < russian[runs]){
            ratings.erase(ratings.begin());
        }
        else{
            ratings.erase(ratings.lower_bound(russian[runs]));
            ++wins;
        }

    }
    return wins;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}