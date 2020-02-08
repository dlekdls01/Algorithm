#include <string>
#include <vector>
#include<iostream>
using namespace std;

/*
j원일때 i라는 돈으로 낼 수 있는 가지수 누적합
   1 2 3 4 5  : j 원일때
1  1 1 1 1 1  : 1원으로 각 j원에 낼 수 있는 가짓수
2  x 2 2 3 3  : 2원으로 각 j원에 낼 수 있는 가짓수 + 윗행
5  x x x x 4  : 5원으로 각 j원에 낼 수 있는 가짓수 + 윗행
*/
int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> v(n+1, 0);
    
    v[0] = 1;
    for(int i=0; i<money.size(); i++){
        for(int j=1; j<=n; j++){
            if(j-money[i]>=0){
                v[j] +=v[j-money[i]];
            }
        }
    }
    return v[n];
}
