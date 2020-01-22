/*
정렬 후, 이전까지의 추합들이 현재추보다 작다면 불가
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    int sum = 1;
    
    sort(weight.begin(), weight.end());
    for(int i=0; i<weight.size(); i++){
        if(sum < weight[i])
            break;
        
        sum += weight[i];
    }
    return sum;
}
