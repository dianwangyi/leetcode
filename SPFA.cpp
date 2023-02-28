#include<cstdio>
#include<vector>
#include<set>
#include<queue>

using namespace std;

const int MAXV = 510;
const int INF = 0x3fffffff;

struct Node{
    int v, weight;
    Node(int _v, int _weight):v(_v),weight(_weight){};
};

int n, m, st, ed, weight[MAXV];
int d[MAXV], num[MAXV], w[MAXV];
set<int> pre[MAXV];
vector<Node> Adj[MAXV];
bool inq[MAXV];

bool SPFA(int s){
    memset(inq, false, sizeof(inq));
    memset(num, 0, sizeof(num));
    fill(d, d + MAXV, INF);
    queue<int> q;
    q.push(s);
    inq[s] = true;
    num[s]++;
    d[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            int dis =Adj[u][j].weight;
            if(d[u] + dis < d[v]){
                d[v] = d[u] + dis;
                if(!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] >= n) return false;
                }
            }
        }
    }
    return true;
}
int main(){

    return 0;
}
