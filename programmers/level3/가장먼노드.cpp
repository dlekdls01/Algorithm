#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
int n;
int depth[20002];
struct ST{
    int x;
    int d;
};
int solution(int N, vector<vector<int>> edge) {
    int answer = 0;
    n = N;
    map.resize(n+1);
    
    for(int i=0; i<edge.size(); i++){
        for(int j=0; j<edge[i].size(); j++){
            map[edge[i][0]].push_back(edge[i][1]);
            map[edge[i][1]].push_back(edge[i][0]);
        }
    }
    
    //
    ST now, next;
    queue<ST> q;
    now = {1,1};
    q.push(now);
    depth[1] = 1;
    int x;
    
    while(!q.empty()){
        now = q.front();
        q.pop();
        
        for(int i=0; i<map[now.x].size(); i++){
            x = map[now.x][i];
            if(depth[x] > 0) continue;
                
            next = {x, now.d+1};
            depth[x] = next.d;
            q.push(next);
        }
    }
    
    int cnt=0;
    int maxn = 0;
    for(int i=1; i<=n; i++){
        if(depth[i] > maxn){
            maxn = depth[i];
            cnt = 1;
        }
        else if(depth[i] == maxn){
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}
