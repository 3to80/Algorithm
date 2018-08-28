#include <iostream>
#include <fstream>


long long C;

unsigned long long N; // 드레곤커브 세대, [0, 51)
unsigned long long P; // P  [1, 1 000 000 001]
long long L; // L [ 1, 51)
using namespace std;

string KEYWORD= "FX";




long long len(long long level){
    if(level == 0) return 1;
    else return 2*len(level-1)+2;
}

long long getLength(char c, long long level){ // character에 따라 길이를 정해준다.
    if(c == '+' or c == '-' or c == 'F') return 1;
    return len(level);
}



string makeString(char c, long long level){
    if(level == 0) return string(1, c);

    if(c == 'X')
        return makeString('X', level-1) + "+" + makeString('Y', level-1) + "F";
    else if(c == 'Y')
        return "F" + makeString('X', level-1) + "-" + makeString('Y', level-1);
    else return string(1, c);
}

string makeNextString(char c){
    if(c == 'X')
        return "X+YF";

    else if(c == 'Y')
        return "FX-Y";

    else return string(1, c);
}

string solve(const string &keyword, long long cur, long long level, long long p, long long n){
    if(cur == keyword.size()){
        cout<<p << " " << n;
        return "";
    }
    if(n <= 0) return "";
    if(level ==0) return keyword.substr(p, n);

    char first_char = keyword[cur];
    long long len = getLength(first_char, level);
    long long e = cur + len;
    if(e <= p) return solve(keyword, cur+1, level, p-len, n);
    else{
        string next_keyword = makeNextString(first_char);
        long long diff = e-p;
        if(p +n <= e) return solve(next_keyword, 0, level-1, p, n);
        if(diff == 1)return string(1, first_char) + solve(keyword, cur+1, level, p + 1, n-1);
        else return solve(next_keyword, 0, level-1, p, diff) + solve(keyword, cur+1, level, p + diff, n-diff);
    }


}




char solvePth(string keyword, long long level, long long p){



//    cout<< keyword << " " << level << " " << p << endl;
    if(level ==0) return keyword[p];
    char first_char = keyword[0];
    long long len = getLength(first_char, level);

    if(p < len){
        //expand
        string nextPrefix = makeNextString(first_char);
        return (solvePth(nextPrefix, level-1, p));
    }
    if(p >= len) return (solvePth(keyword.substr(1), level, p - len));


}


int main() {

    ifstream inFile;
    inFile.open("../input");
    if(inFile.bad()) cout<<"inFile error";

    inFile >> C;
    for(
        long long tc = 0; tc < C; ++tc){
        inFile >> N;
        inFile >> P; P -=1;
        inFile >> L;
        // N세대 드래곤 커브 문자열의 p -1번째 글자부터 l개 만큼 출력
//        cout<< solve(KEYWORD, 0, N, P, L) <<endl;
        for(int i = 0; i < L; ++i)
            cout<<solvePth(KEYWORD, N, P+i);
        cout<<endl;


    }


    return 0;
}