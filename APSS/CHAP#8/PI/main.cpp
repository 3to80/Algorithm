#include <iostream>
#include <vector>
#include <random>

using namespace std;



void print(const vector<int> &src){
    for(auto i : src)
        cout<< i << " ";
    cout<<endl;
}
vector<int> getRandomVector(int length){
    vector<int> ret;
    random_device rn;
    for(int i = 0; i < length; ++i){
        mt19937_64 rnd(rn());
        uniform_int_distribution<int> range(0, 9);
        ret.emplace_back(range(rnd));
    }
    return ret;
}
vector<int> getString(string str){
    vector<int> ret;
    for(int i = 0 ; i < str.size(); ++i){
        int t = (str.at(i)- 48);
        ret.push_back(t);

    }
    return ret;
}



int test_same_diff(const vector<int>& src, int start,  int target){
    if(start == src.size()){
        if(target == 0)
            return 1;
        if(target == 1 or target == -1)
            return 2;
        else
            return 5;
    }

    if(src[start] == target)
        return test_same_diff(src, start+1, target);
    return 10;
}


int test_couple(const vector<int>& src, int start, int target){
    if(target == 0) return -1;

    if(start == src.size()){
        return 4;
    }
    if(src[start] == target)
        return test_couple(src, start+1, target * -1);
    else return -1;
}

int test(const vector<int>& src, int start, int end){
    vector<int> tmp;
    int p = src[start];
    for(int i = start + 1; i < end;  ++i){
        tmp.push_back( src[i]- p);
        p = src[i];
    }

//    print(tmp);
    int flag = test_couple(tmp, 0, tmp[0]);
    if(flag != -1) return flag;
    return test_same_diff(tmp, 0, tmp[0]);
}

int exhaust_search(const vector<int>& src, int start, int end){
    /**
     * @brief : str의 [start, end) 사이의 최소값을 return 한다.
     * @invariant : [start, end) 는 range(0, str.size()) 에 있다.
     */

    if(start < 0 or end > src.size()){
        cout<<"Range error";
        return -1;

    }

    if(end-start == 3 or end-start == 4 or end-start == 5)
        return test(src, start, end);



    int cand3 = (end - start - 3 >= 3)? test(src, start, start + 3) + exhaust_search(src, start + 3, end): 987654321;
    int cand4 = (end - start - 4 >= 3)? test(src, start, start + 4) + exhaust_search(src, start + 4, end): 987654321;
    int cand5 = (end - start - 5 >= 3)? test(src, start, start + 5) + exhaust_search(src, start + 5, end): 987654321;
    int tmp1 = min(cand3, cand4);
    return min(tmp1, cand5);

}



int search_dp(const vector<int>& src, int dp[], int start, int end){
    /**
     * @brief : str의 [start, end) 사이의 최소값을 return 한다.
     * @invariant : [start, end) 는 range(0, str.size()) 에 있다.
     */

    if(start < 0 or end > src.size()){
        cout<<"Range error";
        return -1;

    }

    if(dp[start] != -1)
        return dp[start];

    if(end-start == 3 or end-start == 4 or end-start == 5)
        return test(src, start, end);

    int minValue = 987654321;
    for(int L = 3; L <= 5; ++ L){
        if(start + L < end)
            minValue = min(minValue, test(src, start, start + L) + search_dp(src, dp, start + L, end));
    }



//    int cand3 = (end - start - 3 >= 3)? test(src, start, start + 3) + search_dp(src, dp, start + 3, end): 987654321;
//    int cand4 = (end - start - 4 >= 3)? test(src, start, start + 4) + search_dp(src, dp, start + 4, end): 987654321;
//    int cand5 = (end - start - 5 >= 3)? test(src, start, start + 5) + search_dp(src, dp, start + 5, end): 987654321;
//    int tmp1 = min(cand3, cand4);
    dp[start] = minValue;
    return dp[start];
}




int main() {
//    vector<int> src = getRandomVector(5);
    string str = "1234123124";
    int DP[str.size()];
    fill_n(DP, str.size(), -1);


    vector<int> src = getString(str);

    print(src);

    cout<< exhaust_search(src, 0, (int)src.size())<<endl;
    cout<< search_dp(src, DP, 0, (int)src.size());



    return 0;
}