#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

#define MAX 1000000
vector<int> money;
int dp[MAX][2]; //0:안털고최댓값, 1: 털고최댓값
int n;

// x번째 집을 털기전 까지의 최댓값을 반환하는 함수
// dp[x][0] = max(dp[x-1][0], dp[x-1][1])
// dp[x][1] = dx[x-1][0] + money[x]

int fuc(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];
    
    int notSteal, doSteal;
    notSteal = fuc(x-1, 0);
    doSteal = fuc(x-1, 1);
    
    if(y == 0)
        dp[x][y] = max(notSteal, doSteal);
    if(y == 1)
        dp[x][y] = notSteal + money[x];
    
    return dp[x][y];
}
int solution(vector<int> m) {
    int answer = 0;
    money = m;
    n = money.size() - 1;
    
    fill_n(&dp[0][0], MAX*2, -1);    
    dp[0][0] = 0;
    dp[0][1] = 0;    
    int a = fuc(n, 1);
    
    fill_n(&dp[0][0], MAX*2, -1);
    dp[0][0] = 0;
    dp[0][1] = money[0];
    int b = fuc(n, 0);
    
    answer = max(a,b);
    return answer;
}
