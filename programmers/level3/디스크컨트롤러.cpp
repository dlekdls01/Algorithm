#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct ST{
    int start;
    int time;
};

struct cmp{
    bool operator()(ST a, ST b){
        if(a.time > b.time) return true;
        else if(a.time == b.time) return a.start > b.start;
        else return false;
    }
};

bool cmp1(vector<int> a, vector<int> b){
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0]) return a[1] > b[1];
    else return false;
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<ST, vector<ST>, cmp> pq;   
    
    int len = jobs.size();
    int time = 0;
    int jdx = 0;
    int anw = 0;
    ST st, now;
    
    sort(jobs.begin(), jobs.end(), cmp1);
    while(true){
        //현재시간에시작한 job pq에넣고
        while(jdx < len && jobs[jdx][0] <= time){
            st = {jobs[jdx][0], jobs[jdx][1]};
            pq.push(st);      
            jdx++;
        }
        
        //pq에서작업해주기
        if(!pq.empty()){
            now = pq.top();
            pq.pop();
            
            //cout<<now.start<<" "<<now.time<<endl;
            time += now.time;
            anw += time - now.start;
        }
        else{
            if(jdx >= len) break;
            time ++;
        }
        
    }
    //cout<<anw<<endl;
    answer = anw / len;
    return answer;
}
