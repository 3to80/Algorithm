    #include <iostream>
    #include <cstring>


    using namespace std;

    typedef long long ll;
    ll  N;
    const ll MAX_N = 1000000;
    ll students[MAX_N];

    ll B;
    ll C;


    //5
    //10 9 10 9 10
    //7 2

    int main(){
        memset(students, 0, sizeof(ll) * MAX_N);

        cin >> N;
        for(int i = 0; i < N; ++i){
            ll tmp = 0; cin >> tmp;
            students[i] = tmp;
        }
        cin >> B; cin >> C;

        ll ret = 0;
        for(int i = 0; i < N; ++i){
            if(students[i] <= B)continue;
            ll tmp = students[i] - B;
            int flag = (tmp % C ==0)?0:1;
            ret += (((students[i] - B)/C) + flag);
        }
        cout << (ret + N);



        return 0;
    }