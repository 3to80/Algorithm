#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int n;

int solve(int turn,int map[22][22]){
    int ret=0;
    if(turn == 5){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ret = max(ret, map[i][j]);
        return ret;
    }

    int temp[4][22][22]={0};
    for(int k=0;k<4;k++){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                temp[k][i][j] = map[i][j];
    }

    for(int i=0;i<n;i++){
        int k =0;
        for(int j=0;j<n;j++){
            if(temp[0][i][j] == 0)
                continue;
            int l =1;
            while(j+l<=n){
                if(temp[0][i][j+l] == 0 && j+l != n){
                    l++;
                    continue;
                }
                if(temp[0][i][j] == temp[0][i][j+l] ){
                    temp[0][i][k++] = temp[0][i][j]*2;
                    j += l;
                    break;
                }else{
                    temp[0][i][k++] = temp[0][i][j];
                    break;
                }
            }
        }
        for(int j=k;j<n;j++)
            temp[0][i][j] = 0;
    }

    for(int i=0;i<n;i++){
        int k =n-1;
        for(int j=n-1;j>=0;j--){
            if(temp[1][i][j] == 0)
                continue;
            int l =1;
            while(j-l>=-1){
                if(temp[1][i][j-l] == 0 && j-l != -1){
                    l++;
                    continue;
                }
                if(temp[1][i][j] == temp[1][i][j-l] ){
                    temp[1][i][k--] = temp[1][i][j]*2;
                    j -= l;
                    break;
                }else{
                    temp[1][i][k--] = temp[1][i][j];
                    break;
                }
            }
        }
        for(int j=0;j<=k;j++)
            temp[1][i][j] = 0;
    }

    for(int i=0;i<n;i++){
        int k =0;
        for(int j=0;j<n;j++){
            if(temp[2][j][i] == 0)
                continue;
            int l =1;
            while(j+l<=n){
                if(temp[2][j+l][i] == 0 && j+l != n){
                    l++;
                    continue;
                }
                if(temp[2][j][i] == temp[2][j+l][i] ){
                    temp[2][k++][i] = temp[2][j][i]*2;
                    j += l;
                    break;
                }else{
                    temp[2][k++][i] = temp[2][j][i];
                    break;
                }
            }
        }
        for(int j=k;j<n;j++)
            temp[2][j][i] = 0;
    }

    for(int i=0;i<n;i++){
        int k =n-1;
        for(int j=n-1;j>=0;j--){
            if(temp[3][j][i] == 0)
                continue;
            int l =1;
            while(j-l>=-1){
                if(temp[3][j-l][i] == 0 && j-l != -1){
                    l++;
                    continue;
                }
                if(temp[3][j][i] == temp[3][j-l][i] ){
                    temp[3][k--][i] = temp[3][j][i]*2;
                    j -= l;
                    break;
                }else{
                    temp[3][k--][i] = temp[3][j][i];
                    break;
                }
            }
        }
        for(int j=0;j<=k;j++)
            temp[3][j][i] = 0;
    }

    for(int i=0;i<4;i++)
        ret = max(ret,solve(turn+1,temp[i]) );

    return ret;
}

int main(){
    freopen("../input", "r", stdin);
    int map[22][22];
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&map[i][j]);

    cout << solve(0,map);
}