#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> left;
vector<int> right;
int dp[2001][2001];

// left x번째이고, right y번째일때 최댓값을 반환하는 함수
int fuc(int x, int y){
    if(x==-1 || y== -1) return 0;
    if(dp[x][y] != 0) return dp[x][y];
    
    //오른쪽이 작은경우 오른쪽버림
    if(left[x] > right[y]){
        dp[x][y] = right[y] + fuc(x, y-1);
    }
    //왼쪽이 큰경우 둘다버리거나 왼쪽만버리거나
    else{
        dp[x][y] = max(fuc(x-1,y), fuc(x-1, y-1));
    }
    
    return dp[x][y];
    
}
int solution(vector<int> l, vector<int> r) {
    int answer = 0;
    left = l;
    right = r;
    
    answer = fuc(left.size()-1, right.size()-1);
    return answer;
}
