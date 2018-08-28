#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;




void print(int **map, int row, int col){
    for(int r = 0 ; r < row; ++r){
        for(int c = 0 ; c < col; ++c){
            cout<<map[r][c] << "        ";
        }
        cout<<endl;
    }
}




int R=-1, C = -1;



int aux[100][100];


int getMaxSum(int r, int c, int **map){
//    cout << r << " " << c << " " << map[r][c]<<endl;

    cout<<r << " " << c << " " << endl;
    if(aux[r][c] != 0) return aux[r][c];

    if(r == R-1)
        return (aux[r][c] = map[r][c]);

    int tmp1 = (aux[r+1][c] == 0)? getMaxSum(r+1, c, map): aux[r+1][c];
    int tmp2 = (aux[r+1][c+1] == 0)? getMaxSum(r+1, c+1, map): aux[r+1][c+1];

    return (aux[r][c] = max(tmp1, tmp2) + map[r][c]);

}

//int getMaxSum(int r, int c, int **map){
//    cout << r << " " << c << " " << map[r][c]<<endl;
//    if(r == R-1)
//        return map[r][c];
//    int tmp1 = getMaxSum(r+1, c, map);
//    int tmp2 = getMaxSum(r+1, c+1, map);
//    if(tmp1 > tmp2)
//        return map[r][c] + tmp1;
//    else
//        return map[r][c]+tmp2;
//}





int main(){

    ifstream inFile("../input");
    int test_case;


    inFile>>test_case;
    for(int i = 0 ; i < test_case; ++i){
        int N;

        inFile >> N;
        R = N;
        C = N;
        memset(aux, 0, sizeof(aux));

        int ** map = new int* [N];
        for(int i = 0 ; i < N; ++i)
            map[i] = new int[N];

        for(int r = 0 ; r  < N  ; ++r) {
            for(int c = 0; c <= r ; ++c) {
                int tmp = 0;
                inFile>>tmp;
                map[r][c] = tmp;
            }
        }

        cout << (getMaxSum(0, 0, map))<<endl;

    }


    return 0;
}

