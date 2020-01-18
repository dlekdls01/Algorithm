#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int,int> a , pair<int,int> b){
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int,int>> food;
    int size = food_times.size();
    
    for(int i=0; i<size; i++){
        food.push_back(make_pair(food_times[i], i+1));
    }
    sort(food.begin(), food.end());
    
     int time=0;
    for(vector<pair<int, int>>::iterator it=food.begin(); it!=food.end(); it++, size--) {
        long long leadTime = (long long)(it->first - time) * size;
        if(leadTime == 0)
            continue;
        
        if(leadTime <= k) {
            k-=leadTime;
            time=it->first;
        } else {
            k%=size;
            sort(it, food.end(), cmp);
            return (it+k)->second;
        }       
    }
    return -1;
}
