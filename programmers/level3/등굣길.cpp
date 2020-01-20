#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 110
#define DIV 1000000007
int dp[MAX][MAX];
vector<vector<int>> puddles;

// x,y위치로 오는데 최단거리 갯수를 반환하는 함수
int fuc(int x, int y){
    if(x==1 && y==1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    
    int left, top;
    left = top = 0;
    
    if(y>1) left = fuc(x, y-1);
    if(x>1) top = fuc(x-1, y);
    dp[x][y] = (left+top) % DIV;
    return dp[x][y];
}
int solution(int m, int n, vector<vector<int>> p) {
    long long answer = 0;
    puddles = p;
    
    fill_n(&dp[0][0], MAX*MAX, -1);
    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = 0;
    }
    answer = fuc(n,m);
    return answer;
}
