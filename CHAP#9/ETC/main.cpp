#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

LL MAX= 1000000000000000000;


LL getMaxExponent(LL target, LL base){

    LL ret = 1;
    while(target > base){
        ret +=1;
        target /= base;
    }
    return ret+1;
}



vector<LL> convertTo(LL target, LL base){
    vector<LL> ret;

    do{
        ret.emplace_back(target%base);
        target = target/base;


    }while(target > 0);

    return ret;
}

const LL MAXEXP5 = 27;
LL CACHE[MAXEXP5][2];

int main(){
    LL N = 125;

    LL expo = getMaxExponent(N, 5);

    CACHE[0][0] = 1;
    CACHE[0][1] = 0;

    for(LL idx = 1; idx < expo; ++idx){

        if(idx%2 == 1){
            CACHE[idx][0] = 5 * CACHE[idx-1][0];
            CACHE[idx][1] = 5 * CACHE[idx-1][1];
        }
        else{
            CACHE[idx][0] = 3 * CACHE[idx-1][0] + 2 * CACHE[idx-1][1];
            CACHE[idx][1] = 2 * CACHE[idx-1][0] + 3 * CACHE[idx-1][1];
        }
    }

    vector<LL> ret = convertTo(N, 5);

    for(int i = 0 ; i < ret.size(); ++i){
        cout << ret[i] << " " ;
    }

    LL ans= 0;


    for(int i = 0 ; i < ret.size(); ++i){
        if(i %2 == 1){
            ans = (CACHE[i][0]) ;

        }else{
            ans = (CACHE[i][1]);

        }
    }
    cout<<endl<<ans;







    return 0;
}