#include<vector>
#include<cstdio>
#include<set>

using namespace std;

const int MAXV = 510;
const int INF = 0x3fffffff;
struct Node{
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis){};
};

vector<Node> Adj[MAXV];
int n, m, st, ed, weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV];    // d[]记录最短距离 w[] 记录最大点权；num[]记录最短路径条数
set<int> pre[MAXV];     //set 关联式容器，插入删除效率高

void Bellman(int s){
    fill(d, d + MAXV, INF);
    memset(w, sizeof(w), 0);
    memset(num, sizeof(num), 0);
    d[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    // 取每一个顶点
    // 取每一条边
    for(int i = 0; i < n-1; i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < Adj[u].size(); j++){
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                // 计算是否更优
                // 判断du + cuv 《 dv和du+cuv==dv是否成立
                if(d[u] + dis < d[v]){
                    // 更新
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                } 
                else if(d[u] + dis == d[v]){
                    if(w[u] + weight[v] > w[v]){
                        w[v] = w[u] + weight[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    set<int>::iterator it;
                    for(it = pre[v].begin(); it != pre[v].end(); it++){
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n,&m,&st,&ed);
    for(int i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }
    int u,v,wt;
    for(int j = 0; j < m; j++){
        scanf("%d%d%d", &u, &v, &wt);
        Adj[u].push_back(Node(v, wt));
        Adj[v].push_back(Node(u, wt));
    }
    Bellman(st);
    printf("%d %d\n", num[ed],w[ed]);
    return 0;
}