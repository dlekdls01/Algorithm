#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int map[501][501][3];   //0:위->아래, 1:왼->오 , 2:0+1
    fill_n(&map[0][0][0], 501*501*3, 0);
    
    map[0][0][0] = map[0][0][1] = 1;
    map[0][0][2] = 2;
    
    for(int i=1; i<m; i++){
        if(city_map[i-1][0] != 1)
            map[i][0][0] = map[i][0][2] = map[i-1][0][0];
    }
    for(int i=1; i<n; i++){
        if(city_map[0][i-1] != 1)
            map[0][i][1] = map[0][i][2] = map[0][i-1][1];
    }
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            //위->아래
            if(city_map[i-1][j] == 0){
                map[i][j][0] = map[i-1][j][2];
            }
            else if(city_map[i-1][j] == 1){
                map[i][j][0] = 0;
            }
            else{
                map[i][j][0] = map[i-1][j][0];
            }
            
            //왼->오
            if(city_map[i][j-1] == 0){
                map[i][j][1] = map[i][j-1][2];
            }
            else if(city_map[i][j-1] == 1){
                map[i][j][1] = 0;
            }
            else{
                map[i][j][1] = map[i][j-1][1];
            }
            
            map[i][j][0] %= MOD;
            map[i][j][1] %= MOD;
            map[i][j][2] = (map[i][j][0] + map[i][j][1])%MOD;
        }
        
    }
    answer = map[m-1][n-1][2];
    return answer;
}
