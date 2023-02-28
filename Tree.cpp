// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const int MAXN = 110;
// struct node {
//     int weight;
//     vector<int> child;
// } Node[MAXN];

// int n, m, S;
// int path[MAXN];

// bool cmp(const int &l, const int &r){
//     return l < r;
// }

// void DFS(int index, int numNode, int sum){
//     if(sum > S) return;
//     if(sum == S){
//         if(Node[index].child.size() != 0) return;
//         for(int i = 0; i < numNode; i++){
//             printf("%d", Node[path[i]].weight);
//             if(i < numNode - 1) printf(" ");
//             else printf("\n");
//         }
//         return;
//     }
//     for (int i = 0; i < Node[index].child.size(); i++){
//         int child = Node[index].child[i];
//         path[numNode] = child;
//         DFS(child, numNode + 1, sum + Node[i].weight);
//     }
// }

// void search(node* root, int x){
//     if(root == NULL) return;

//     if(root->data == x){
//         printf("%d", root->weight);
//     }else if(root->weight > x){
//         search(root->lchild, x);
//     }
//     else if(root->weight < x){
//         search(root->rchild, x);
//     }
// }
// int main(){
//     scanf("%d%d%d", &n, &m, &S);
//     int id, k, child;
//     for(int i = 0; i < n; i++){
//         scanf("%d%d", &id, &k);
//         for(int j = 0; j < k; j++){
//             scanf("%d", &child);
//             Node[id].child.push_back(child);
//         }
//         sort(Node[id].child.begin(), Node[id].child.end(), cmp);
//     }
//     path[0] = 0;
//     DFS(0, 1, Node[0].weight);
//     return 0;
// }