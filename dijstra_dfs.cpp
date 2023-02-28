#include<stdio.h>
#include<vector>

using namespace std;

const int MAXV = 510;
const int INF = 1000000000;

int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], minCost = INF;
bool vis[MAXV] = {false};

vector<int> path, tempPath;
vector<int> pre[MAXV];

void Dijkstra(int s){

    fill(d, d+MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){     // 外围大循环，遍历所有点，最后要产生到达所有点的最短路径，每次循环都计算到这个点的最短距离
        // 找出当前未探索的最短距离点
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] = false && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1) return;     // 说明与剩余的点无相连
        vis[u] = true;      //vis 相当于colseedset 存放遍历过的点

        // 遍历u连接的所有点，更新从起点通过u到达这些点的距离 
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){  // 与u相连
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v){       // 遍历求得的路径，选出cost最小的
    if(v == st){    // 到达递归边界
        tempPath.push_back(v);
        int tempCost = 0;
        for(int i = tempPath.size() - 1; i > 0; i--){
            int id = tempPath[i], idNext = tempPath[i-1];
            tempCost += cost[id][idNext];
        }

        if(tempCost < minCost){
            minCost = tempCost;
            path = tempPath;
        }else{
            tempPath.pop_back();
        }
        return;
    }
    tempPath.push_back(v);
    for(int u = 0; u < pre[v].size(); u++){
        DFS(pre[v][u]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;
    fill(G[0],G[0]+ MAXV * MAXV, INF);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d%d", G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    for(int i = path.size()-1; i >= 0; i++){
        printf("%d", path[i]);
    }
    printf("%d %d\n", d[ed], minCost);
    return 0;
}
