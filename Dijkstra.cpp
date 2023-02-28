#include <cstdio>
#include<iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 10000000;
int n, G[MAXN][MAXN];
int d[MAXN];      // 记录从起点到达各点的最短路径长度
bool vis[MAXN] = {false};   //closeSet  标记节点是否已经被访问

void Dijkstra(int s){
    fill(d, d + MAXN, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){     // 遍历寻找openSet中的最小值  相当于优先级队列中的取出最先一个
            if(vis[j] = false && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;    // 说明附近的节点都与u不连通 死胡同 无路
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}