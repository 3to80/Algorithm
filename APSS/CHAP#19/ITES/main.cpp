#include <iostream>
#include <deque>


using namespace std;


long long C;
long long N;
long long K;


long long one = 1;
long long MOD = (one << 32);
long long makeCur(long long seed){
    return (seed * 214013%MOD + 2531011)%MOD;
}
long long getCur(long long seed){
    return seed%10000 + 1;
}
int main() {

    cin >> C;
    for(long long test_case = 0; test_case < C; ++test_case){
        cin >> K;
        cin >> N;
        long long seed = 1983;
        long long target = 0;
        long long accSum = 0;
        deque<long long> myQueue;
        int ret = 0;

        while(N >0){
            N -= 1;
            target = getCur(seed);
            seed = makeCur(seed);
            accSum += target;
            myQueue.push_back(target);
            while(accSum >= K){
                if(accSum== K)ret +=1;
                long long discard = myQueue.front();
                myQueue.pop_front();
                accSum -= discard;
            }

        }



        cout << ret<< endl;


    }

}









